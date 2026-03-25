#include<windows.h>
#include <stdio.h>

int main()
{
   HANDLE hsem;

   hsem=OpenSemaphore(SEMAPHORE_ALL_ACCESS,FALSE,"Mysem");

   printf("Waiting");

   //wait
   WaitForSingleObject(hsem,INFINITE);
   
   Sleep(3000);

   //Signal
   ReleaseSemaphore(hsem,1,NULL);
   
   CloseHandle(hsem);
    
    return 0;
}
