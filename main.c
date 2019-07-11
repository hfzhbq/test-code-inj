#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <memory.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORT 9090
#define Buflen 1024
#define SERVER_ADDR "127.0.0.1"
int main(int argc,char *argv[])
{
    struct sockaddr_in server_addr;
    int n,count=0;
    int sockfd;
    char sendline[Buflen];
    sockfd= socket(AF_INET,SOCK_STREAM,0);
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, SERVER_ADDR, &server_addr.sin_addr) <= 0) {
        printf("inet_pton error");
        return 1;
    }

    connect(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr));

    memset(sendline,'a',sizeof(Buflen));

    while ( (n=send(sockfd,sendline,Buflen, NULL))>0 )
    {
      count++;
      printf("already write %d bytes -- %d\n",n,count);
    }

    if(n<0)
       perror("write error");
    close(sockfd);
}