#include<windows.h>
#include <stdio.h>

int main()
{
   HANDLE hsem;

   hsem=CreateSemaphore(NULL,2,2,"Mysem");
   printf("Trying to enter......\n");

   //wait
   WaitForSingleObject(hsem,INFINITE);
   printf("enter\n");

   Sleep(2000);
  
   //signal
   ReleaseSemaphore(hsem,1,NULL);
   printf("left\n");
   
 
   CloseHandle(hsem);
    
    return 0;
}
