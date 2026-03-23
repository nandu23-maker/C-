#include<stdio.h>
#include<winsock2.h>

int main()
{
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server,client;

    WSAStartup(MAKEWORD(2,2) &wsa);

    s=socket(AF_INET,SOCK_DGRAM,0);

    server.sin_family=AF_INET;
    server.sin_port=htons(8888);
    server.sin_addr.s_addr=INADDR_ANY;

    bind(s,(struct sockaddr*)&server,sizeof(server));

    printf("Waiting for message...\n");

    len=sizeof(client);
    recv

        
