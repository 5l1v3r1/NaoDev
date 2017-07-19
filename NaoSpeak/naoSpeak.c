#include <stdio.h> 
#include <string.h>    
#include <sys/socket.h>    
#include <arpa/inet.h> 

#define BUFFER 1024

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[1024];

    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("[-_-] Could not create socket");
    }
    puts("[^0^] Socket created");

    server.sin_addr.s_addr = inet_addr("<Insert_Nao_IP>");
    server.sin_family = AF_INET;
    server.sin_port = htons( 10001 );

    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("[-_-] Connection failed. Error");
        return 1;
    }

    puts("Connected!\n");

    while(1)
    {
        printf("[NAOSpeak] ");

        fgets(message,BUFFER,stdin);

        if( send(sock , message , strlen(message) , 0) < 0)
        {
            puts("[-_-] Could Not Send Message. ");
            return 1;
        }

    }

    close(sock);
    return 0;
}