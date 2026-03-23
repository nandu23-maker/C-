#include <windows.h>

#include <stdio.h>

int main()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    DWORD status;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    char cmd[] = "handler.exe";

    if (!CreateProcess(
            NULL,
            cmd,
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &si,
            &pi))
    {
        printf("Failed to start process!\n");
        return 1;
    }

    printf("Process started (PID: %lu)\n", pi.dwProcessId);

    // Monitor
    while (1)
    {
        GetExitCodeProcess(pi.hProcess, &status);

        if (status == STILL_ACTIVE)
        {
            printf("Process RUNNING...\n");
        }
        else
        {
            printf("Process FINISHED!\n");
            break;
        }

        Sleep(1000);
    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
