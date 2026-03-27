#include<windows.h>
#include <stdio.h>

int main()
{
    HANDLE hmap;
    char *ptr;

    //open a shared memory
    hmap=OpenFileMapping(
                         FILE_MAP_ALL_ACCESS,
                         FALSE,
                         "Mymap"
                        );
 
    //Map memory
    ptr=(char*)MapViewOfFile(
                             hmap,
                             FILE_MAP_ALL_ACCESS,
                             0,0,1024
                            );
 
    //read data
    printf("Received: %s\n",ptr);

    UnmapViewOfFile(ptr);
    CloseHandle(hmap);
    
    return 0;
}
