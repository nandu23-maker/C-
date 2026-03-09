#include <stdio.h>
#include <winsock2.h>

int main()
{
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;
    char msg[100];

    WSAStartup(MAKEWORD(2,2), &wsa);

    s = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8888);

    connect(s, (struct sockaddr*)&server, sizeof(server));

    printf("Enter message: ");
    gets(msg);

    send(s, msg, sizeof(msg), 0);

    closesocket(s);
    WSACleanup();

    return 0;
}
