#include <stdio.h>
#include <winsock2.h>

int main()
{
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;
    char msg[100] = "Hello Server";

    WSAStartup(MAKEWORD(2,2), &wsa);

    s = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8888);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    sendto(s,msg,sizeof(msg),0,(struct sockaddr*)&server,sizeof(server));

    closesocket(s);
    WSACleanup();
}
