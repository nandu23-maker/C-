#include<windows.h>
#include <stdio.h>
#include<string.h>

int main()
{
    HANDLE hfile,hmap;
    char *ptr;
   
    //create file
    hfile=CreateFile(
                     "data.txt",
                     GENERIC_WRITE|GENERIC_READ,
                     0,
                     NULL,
                     OPEN_ALWAYS,
                     FILE_ATTRIBUTE_NORMAL,
                     NULL
                     ); 
   
    //create shared memory
    hmap=CreateFileMapping(
                            hfile,
                            NULL,
                            PAGE_READWRITE,
                            0,
                            1024,
                            "Mymap"
                          );
   //map memory
   ptr=(char*)MapViewOfFile(
                            hmap,
                            FILE_MAP_ALL_ACCESS,
                            0,0,1024
                           );
   //write data
   strcpy(ptr,"hello world......");
   printf("Data written\n");

   getchar();

   UnmapViewOfFile(ptr);
   CloseHandle(hmap);
   CloseHandle(hfile);
    
    return 0;
}
