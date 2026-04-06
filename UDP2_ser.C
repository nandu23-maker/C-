#include <stdio.h>
#include<string.h>
#include<winsock2.h>

int main()
{
   WSADATA wsa;
   SOCKET s;
   struct sockaddr_in server,client;
   char msg[100];
   int len=sizeof(client);

   WSAStartup(MAKEWORD(2,2),&wsa);

   s = socket(AF_INET,SOCK_DGRAM,0);

   server.sin_family=AF_INET;
   server.sin_port=htons(1234);
   server.sin_addr.s_addr=INADDR_ANY;

   bind(s,(struct sockaddr*)&server,sizeof(server));

   while(1){
        int n= recvfrom(s,msg,sizeof(msg),0,(struct sockaddr*)&client,&len);
        msg[n]='\0';
         printf("client: %s",msg);

         printf("you: ");
         fgets(msg,sizeof(msg),stdin);
         sendto(s,msg,strlen(msg),0,(struct sockaddr*)&client,len);
      }

   closesocket(s);
   WSACleanup();
   
    
    return 0;
}
