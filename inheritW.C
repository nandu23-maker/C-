#include<windows.h>
#include <stdio.h>
#include<string.h>

int main()
{
    HANDLE hmap;
    char *ptr;

    SECURITY_ATTRIBUTES sa={sizeof(sa),NULL,TRUE};

    //create shared memory
    hmap=CreateFileMapping(
               INVALID_HANDLE_VALUE,
               &sa,
               PAGE_READWRITE,
               0,
               100,
               "mysharedmemory"
            );

     ptr=(char*)MapViewOfFile(
                  hmap,
                  FILE_MAP_ALL_ACCESS,
                  0,0,100);

     strcpy(ptr,"Hello from parent");

     STARTUPINFO si;   //setting for new process
     ZeroMemory(&si,sizeof(si));
     si.cb=sizeof(si);

     PROCESS_INFORMATION pi;         //info about create process

     //create child process
     CreateProcess(
                  "child.exe",
                   NULL,
                   NULL,
                   NULL,
                   TRUE,     //inheritance
                   0,
                   NULL,
                   NULL,
                   &si,
                   &pi
                 );

    WaitForSingleObject(pi.hProcess,INFINITE);
 
    return 0;
}



































