#include <stdio.h>
#include <winsock2.h>

int main()
{
    WSADATA wsa;
    SOCKET s, client;
    struct sockaddr_in server;
    char msg[100];

    WSAStartup(MAKEWORD(2,2), &wsa);

    s = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8888);

    bind(s, (struct sockaddr*)&server, sizeof(server));

    listen(s,1);

    printf("Waiting for client...\n");

    client = accept(s, NULL, NULL);

    recv(client, msg, sizeof(msg), 0);

    printf("Message from client: %s\n", msg);

    closesocket(s);
    WSACleanup();

    return 0;
}
