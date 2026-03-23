#include <stdio.h>
#include <windows.h>

int main()
{
    while (1)
    {
        printf("Child process running...\n");
        Sleep(1000); // 1 sec delay
    }

    return 0;
}
