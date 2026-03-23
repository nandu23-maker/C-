#include <winsock2.h>
#include <stdio.h>

#pragma comment(lib,"ws2_32.lib")

int main()
{
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;

    WSAStartup(MAKEWORD(2,2), &wsa);

    s = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8888);

    connect(s, (struct sockaddr*)&server, sizeof(server));

    printf("Connected to server\n");

    return 0;
}
