#include<windows.h>
#include <stdio.h>

int main()
{
    HANDLE hMapFile,hMutex;
    char *pBuf;

    //open Mutex
    hMutex = OpenMutex(
             MUTEX_ALL_ACCESS,
             FALSE,
             "MyMutex"
    );
  
    //open shared memory
    hMapFile = OpenFileMapping(
               FILE_MAP_ALL_ACCESS,
               FALSE,
               "My Shared Memory"
   );

   //map memory
   pBuf = (char*)MapViewOfFile(
          hMapFile,
          FILE_MAP_ALL_ACCESS,
          0,0,1024
   );

   //lock
   WaitForSingleObject(hMutex,INFINITE);

   //Read data
   printf("Reader:%s\n",pBuf);
 
   //unlock
   ReleaseMutex(hMutex);
  
   //cleanup
   UnmapViewOfFile(pBuf);
   CloseHandle(hMapFile);
   CloseHandle(hMutex);
   
    
    return 0;
}
