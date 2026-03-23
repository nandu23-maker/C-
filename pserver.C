#include <winsock2.h>
#include <windows.h>
#include <stdio.h>



int main()
{
    WSADATA wsa;
    SOCKET s, client;
    struct sockaddr_in server, client_addr;
    int c;

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    WSAStartup(MAKEWORD(2,2), &wsa);

    s = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    bind(s, (struct sockaddr*)&server, sizeof(server));
    listen(s, 5);

    printf("Server waiting...\n");

    c = sizeof(client_addr);

    while(1)
    {
        client = accept(s, (struct sockaddr*)&client_addr, &c);

        printf("Client connected!\n");

        // Initialize
        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        ZeroMemory(&pi, sizeof(pi));

        char cmd[] = "handler.exe";

        // Create new process
        CreateProcess(
            NULL,
            cmd,
            NULL, NULL, FALSE,
            0,
            NULL, NULL,
            &si,
            &pi
        );

        printf("Process created!\n");
    }

    return 0;
}
