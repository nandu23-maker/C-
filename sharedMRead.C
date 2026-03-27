#include<windows.h>
#include <stdio.h>

int main()
{
   HANDLE hMapFile;
   char *pBuf;
  
  //open a shared memory
  hMapFile = OpenFileMapping(
        FILE_MAP_ALL_ACCESS,
        FALSE,                //no inheritance
        "mysharedmemory"
  );
  
  //Map memory
  pBuf=(char*)MapViewOfFile(
      hMapFile,
      FILE_MAP_ALL_ACCESS,
      0,0,1024
  );
 
  //Read data
  printf("Received: %s\n",pBuf);

  UnmapViewOfFile(pBuf);
  CloseHandle(hMapFile);
    
    return 0;
}

