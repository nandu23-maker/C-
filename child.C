#include <windows.h>
#include <stdio.h>

int main() {
    char buffer[100];
    DWORD readBytes;
    HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);

    if (ReadFile(hStdIn, buffer, sizeof(buffer) - 1, &readBytes, NULL)) {
        buffer[readBytes] = '\0';
        printf("Child received: %s\n", buffer);
    }

    return 0;
}
