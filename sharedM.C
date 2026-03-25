#include<windows.h>
#include <stdio.h>
#include<string.h>

int main()
{
   HANDLE hMapFile;
   char *pBuf;   //point to shared memory 

   

   //create a shared memory
   hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        1024,
        "my shared memory"
   );

   //Map memory
   pBuf=(char*)MapViewOfFile(
      hMapFile,
      FILE_MAP_ALL_ACCESS,
      0,0,1024
   );
  
 
   //write data
   strcpy(pBuf,"Hello from process 1!");
   printf("Data written\n");
   
   getchar();
  

   UnmapViewOfFile(pBuf);
   CloseHandle(hMapFile);
   
   
    
    return 0;
}
