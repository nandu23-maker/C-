#include<windows.h>
#include <stdio.h>
#include<string.h>

int main()
{
    HANDLE hMapFile,hMutex;
    char *pBuf;

    //Create Mutex
    hMutex=CreateMutex(NULL,FALSE,"MyMutex"); 

    //Create Shared Memory
    hMapFile = CreateFileMapping(
               INVALID_HANDLE_VALUE,    //memory in RAM
               NULL,
               PAGE_READWRITE,
               0,
               1024,
               "My Shared Memory"
    );
 
    //map memory
    pBuf = (char*)MapViewOfFile(
           hMapFile,             //handle
           FILE_MAP_ALL_ACCESS,
           0,0,1024            //size memory
    );
    
    //lock
    WaitForSingleObject(hMutex,INFINITE);

    //Write data
    strcpy(pBuf,"hello with mutex");
    printf("Written:%s\n",pBuf);

    //unlock
    ReleaseMutex(hMutex);
    
    getchar();  //wait so reader can read

   //cleanup
   UnmapViewOfFile(pBuf);
   CloseHandle(hMapFile);
   CloseHandle(hMutex);
               
    
    return 0;
}
