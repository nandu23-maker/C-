#include<windows.h>
#include <stdio.h>

int main()
{
    HANDLE hsem;
    LONG prev;
  
    hsem=CreateSemaphore(NULL,2,2,"Mysem");
  
    //wait
    WaitForSingleObject(hsem,INFINITE);
    printf("Entering....");

    Sleep(2000);
 
     //signal
     ReleaseSemaphore(hsem,1,&prev);
     printf("previous value %d\n",prev);

    CloseHandle(hsem);
   
    
    return 0;
}
