#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hMapFile;
    char *pBuf;

    // Create shared memory
    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        1024,
        "MySharedMemory"
    );
};
