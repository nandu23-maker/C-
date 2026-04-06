#include <stdio.h>
#include<string.h>
#include<winsock2.h>

int main()
{
   WSADATA wsa;
   SOCKET s;
   struct sockaddr_in server;
   char msg[100];

   WSAStartup(MAKEWORD(2,2),&wsa);
   s = socket(AF_INET,SOCK_DGRAM,0);

   server.sin_family=AF_INET;
   server.sin_port=htons(1234);
   server.sin_addr.s_addr=inet_addr("127.0.0.1");

   while(1){
          printf("you: ");
          fgets(msg,sizeof(msg),stdin);
          sendto(s,msg,strlen(msg),0,(struct sockaddr*)&server ,sizeof(server));
          
          int n=recvfrom(s,msg,sizeof(msg),0,NULL,NULL);
          msg[n]='\0';
          printf("client: %s",msg);
       }

   closesocket(s);
   WSACleanup();
    
    return 0;
}
