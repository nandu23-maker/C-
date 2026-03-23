#include<windows.h>   //windows API function
#include <stdio.h>

DWORD WINAPI myThread (LPVOID arg)  //function executed my each thread
{
     printf("Thread running\n");
     return 0;
}
int main()
{
    CreateThread(NULL,0,myThread,NULL,0,NULL);
  
    Sleep(2000);
   
    
    return 0;
}
