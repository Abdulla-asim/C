#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
//#pragma comment(lib, "ws2_32.lib")

#define SIZE 1024
#define PORT 8080

void write_file(int sockfd);

int main ()
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        perror("[-] Failed to initialize Winsock");
        return 1;
    }

    /**/
    char *ip = "127.0.0.1";
    int port = 8080;
    int e;

    int sockfd, new_sock;
    struct sockaddr_in server_addr, new_addr;
    int addr_size;
    char buffer[SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("[-]Error in socket");
        exit(1);
    }

    printf("[+]Server socket created. \n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port); //  use httons(port)
    server_addr.sin_addr.s_addr = INADDR_ANY; //inet_addr(ip); // use inaddr_any

    if (bind(sockfd,(struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("[-]Error in Binding");
        exit(1);
    }
    printf("[+]Binding Successfull.\n");

    if(listen(sockfd, 10) == 0)
        printf("[+]Listening...\n");
    else 
    {
        perror("[-]Error in Binding");
        exit(1);
    }

    addr_size = sizeof(new_addr);

    while (1) { //
        new_sock = accept(sockfd,(struct sockaddr*)&new_addr, &addr_size);
        if (new_sock < 0) { perror("[-]Error in Accepting"); exit(1); } //
    

        write_file(new_sock);
        printf("[+]Data written in the text file ");

        closesocket(new_sock); //

    }

    closesocket(sockfd);

    return 0;
}

void write_file(int sockfd)
{
    int n; 
    FILE *fp;
    char *filename = "file2.txt";
    char buffer[SIZE];

    fp = fopen(filename, "w");
    if(fp==NULL)
    {
        perror("[-]Error in creating file.");
        exit(1);
    }
    while(1)
    {
        n = recv(sockfd, buffer, SIZE, 0);
        if(n<=0)
        {
            break;
            return;
        }
        fprintf(fp, "%s", buffer);
        memset(buffer, 0, SIZE);
    }
    return;
    
}
