#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hMutex;

    hMutex = CreateMutex(NULL, FALSE, "MyMutex");

    printf("Trying to enter....\n");

    WaitForSingleObject(hMutex, INFINITE);

    printf("wait\n");

    Sleep(5000);

    printf("leaving\n");

    ReleaseMutex(hMutex);

    CloseHandle(hMutex);
    return 0;
}
