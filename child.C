#include <windows.h>
#include <stdio.h>

int main() {
         HANDLE hmap;
         char *ptr;

         hmap=OpenFileMapping(
                     FILE_MAP_ALL_ACCESS,
                     FALSE,
                     "mysharedmemory"
                    );

         ptr=(char*)MapViewOfFile(
                             hmap,
                             FILE_MAP_ALL_ACCESS,
                             0,0,100
                            );
         
         printf("child read: %s\n",ptr);

    
    return 0;
}
