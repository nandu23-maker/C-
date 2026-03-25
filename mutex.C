#include<windows.h>
#include <stdio.h>

int main()
{
    HANDLE hMutex;

    //create mutex
    hMutex = CreateMutex(NULL,FALSE,"MyMutex");

    //lock
    WaitForSingleObject(hMutex,INFINITE);

    printf("enterr\n");

    //unlock
    ReleaseMutex(hMutex);
    printf("PID: %lu Trying...\n", GetCurrentProcessId());
 
    CloseHandle(hMutex);
    
    return 0;
}
