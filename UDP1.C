#include <stdio.h>
#include<winsock2.h>

int main()
{
   WSADATA wsa;
   SOCKET s;
   struct sockaddr_in server,client;
   char msg[50];
   int len=sizeof(client);

   WSAStartup(MAKEWORD(2,2),&wsa);

   s = socket(AF_INET,SOCK_DGRAM,0);
   
   server.sin_family=AF_INET;
   server.sin_port=htons(1234);
   server.sin_addr.s_addr=INADDR_ANY;

   bind(s,(struct sockaddr*)&server,sizeof(server));

   printf("waiting..\n");

   recvfrom(s,msg,sizeof(msg),0,(struct sockaddr*)&client,&len);

   printf("message: %s",msg);
  
   closesocket(s);
   WSACleanup();
   
    
    return 0;
}
