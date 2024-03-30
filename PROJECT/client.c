#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>
//#include <netdb.h>
//#pragma comment(lib, "ws2_32.lib")

#define SIZE 1024
#define PORT 8080

void send_file(FILE *fp, int sockfd)
{
    char data[SIZE] = {0};

    while(fgets(data, SIZE, fp)!=NULL)
    {
        if(send(sockfd, data, sizeof(data), 0)== -1)
        {
            perror("[-] Error in sendung data");
            exit(1);
        }
        memset(data, 0, SIZE);
    }
}

 /*
int main()
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        perror("[-] Failed to initialize Winsock");
        return 1;
    }

    char *ip = "127.0.0.1";
    int port = 8080;
    int e;

    int sockfd;
    struct sockaddr_in server_addr;
    FILE *fp;
    char *filename = "file.txt";
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd<0)
    {
        perror("[-]Error in socket");
        exit(1);
    }
     printf("[+]Server socket created. \n");

     server_addr.sin_family = AF_INET;
     server_addr.sin_port = port;
     server_addr.sin_addr.s_addr = inet_addr(ip);

     e = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
     if(e == -1)
     {
         perror("[-]Error in Connecting");
         exit(1);
     }
     printf("[+]Connected to server.\n");
     fp = fopen(filename, "r");
     if(fp == NULL)
     {
         perror("[-]Error in reading file.");
         exit(1);
     }
     send_file(fp,sockfd);
     printf("[+] File data send successfully. \n");
     close(sockfd);
     printf("[+]Disconnected from the server. \n");
     return 0;

}
 */

//  /*
int main() {
    // Get a list of available IP addresses using getaddrinfo
    struct addrinfo hints, *res, *p;
    char ipstr[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo("localhost", NULL, &hints, &res) != 0) {
        perror("[-]Error in getaddrinfo");
        return 1;
    }

    // Loop through all the results and connect to the first one we can
    int sockfd;
    for (p = res; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("[-] Error in socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("[-] Error in connecting");
            closesocket(sockfd);
            continue;
        }

        break; // If we get here, we connected successfully
    }

    if (p == NULL) {
        fprintf(stderr, "[-] Failed to connect\n");
        return 2;
    }

    inet_ntop(p->ai_family, get_in_addr((struct sockaddr*)p->ai_addr), ipstr, sizeof ipstr);
    printf("[+] Connected to %s\n", ipstr);

    freeaddrinfo(res); // All done with this structure

    FILE *fp;
    char *filename = "file.txt";
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("[-]Error in reading file.");
        exit(1);
    }

    // Send file to the server
    send_file(fp, sockfd);
    printf("[+] File data sent successfully.\n");

    // Close the socket
    closesocket(sockfd);

    return 0;
}
//   */