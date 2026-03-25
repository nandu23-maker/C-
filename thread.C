#include<windows.h>   //windows API function
#include <stdio.h>

DWORD WINAPI MyThread(LPVOID param) 
{
       printf("Thread running\n");
       return 0;
}
   
int main()
{
    HANDLE hThread;

    hThread = CreateThread(
              NULL,                     //security
              0,                        //stack size
              MyThread,                 //function
              NULL,                     //parameter
              0,                        //run immediately
              NULL                      //thread id
    ); 
    
    WaitForSingleObject(hThread, INFINITE);

    printf("finished\n");

    CloseHandle(hThread);

    return 0;
}i
