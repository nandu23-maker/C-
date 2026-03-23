#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hRead, hWrite;
    SECURITY_ATTRIBUTES sa = { sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };

    // Create an anonymous pipe
    if (!CreatePipe(&hRead, &hWrite, &sa, 0)) {
        printf("Pipe creation failed!\n");
        return 1;
    }

    //prepare child process info
    printf("Pipe created successfully!\n");
     

    PROCESS_INFORMATION pi;
    STARTUPINFO si;
    ZeroMemory(&pi, sizeof(pi));
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    // Redirect child's stdout to pipe write handle
    si.hStdOutput = hWrite;
    si.hStdError = hWrite;        // optional: also redirect stderr
    si.dwFlags |= STARTF_USESTDHANDLES;

    // create child process
    char cmd[]="child.exe";  
    if (!CreateProcess(
            NULL,
            cmd, // child program to run
            NULL,
            NULL,
            TRUE,       // allow handle inheritance
            0,
            NULL,
            NULL,
            &si,
            &pi)) 
    {
        printf("Failed to create child process!\n");
        return 1;
    }

    

     //parent write data
    char message[] = "Hello from Parent!";
    DWORD written;
    if (!WriteFile(hWrite, message, sizeof(message), &written, NULL)) {
        printf("Failed to write to pipe!\n");
      
    }
      CloseHandle(hWrite);  // close AFTER writing

     // child reads data
     char buffer[100];
    DWORD readBytes;
    if (ReadFile(hRead, buffer, sizeof(buffer) - 1, &readBytes, NULL)) {
        buffer[readBytes] = '\0';
        printf("child received: %s\n", buffer);
    }

    CloseHandle(hRead);
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;

}
