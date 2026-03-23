#include <stdio.h>
#include <winsock2.h>

int main()
{
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server, client;
    int len;
    char msg[100];

    WSAStartup(MAKEWORD(2,2), &wsa);

    s = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8888);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(s,(struct sockaddr*)&server,sizeof(server));

    len = sizeof(client);

    recvfrom(s,msg,sizeof(msg),0,(struct sockaddr*)&client,&len);

    printf("Message: %s",msg);

    closesocket(s);
    WSACleanup();
}
