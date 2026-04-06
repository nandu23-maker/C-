#include<windows.h>
#include <stdio.h>
#include<string.h>

int main()
{
    HANDLE hfile,hmap;
    char *ptr;

    SECURITY_ATTRIBUTES sa={sizeof(sa),NULL,TRUE};

    hfile=CreateFile(
                      "data.txt",
                       GENERIC_READ | GENERIC_WRITE,
                       0,
                       &sa,
                       OPEN_ALWAYS,
                       FILE_ATTRIBUTE_NORMAL,
                       NULL
                    );

    hmap=CreateFileMapping(
                       hfile,
                       &sa,
                       PAGE_READWRITE,
                       0,
                       100,
                       "Myfile"
                    );

    ptr=(char*)MapViewOfFile(hmap,FILE_MAP_ALL_ACCESS,0,0,100);

    strcpy(ptr,"hello.....");

    STARTUPINFO si;
    ZeroMemory(&si,sizeof(si));
    si.cb=sizeof(si);

    PROCESS_INFORMATION pi;
   
    CreateProcess(
                 "child1.exe",
                  NULL,
                  NULL,
                  NULL,
                  TRUE,
                  0,
                  NULL,
                  NULL,
                  &si,
                  &pi
               );

   WaitForSingleObject(pi.hProcess,INFINITE);
                  
     
    
    return 0;
}
