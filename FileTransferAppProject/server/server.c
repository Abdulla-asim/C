// TCP Server
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 2000
#define BUFF_SIZ 1024

//char *extension[3] = {"txt", "mp3", "mp4"};

// Function prototypes
int create_tcp_ipv4_socket();
struct sockaddr_in* create_socket_addr(char* ip, int port);
int err_check(int return_val, const char *print);
const char* get_extension(int sock_fd, char *filename);
void close_server(int server_fd);
void close_client(int client_fd);

// MAIN
int main()
{
    // Socket Creation
    int server_fd  = create_tcp_ipv4_socket();
    struct sockaddr_in *server_addr = create_socket_addr("", PORT);


    // Socket Binding
    err_check(bind(server_fd, (struct sockaddr *) server_addr, sizeof(*server_addr)), "[x]Could not bind");
    puts("[+]Socket binding successful");


    // Listening for Connections
    err_check(listen(server_fd, 5), "[x]Could not start listening");
    puts("[+]Listening...");


    // Accepting Connection
    struct sockaddr_in client_addr;
    int addr_size = sizeof(client_addr);
    int client_fd = err_check(accept(server_fd, (struct sockaddr *) &client_addr, &addr_size), "[x]Could not accept connection");
    puts("[+]Connection Accepted");
    
    // EXIT server?
    char client_reply[5] = "";
    recv(client_fd, client_reply, 5, 0);
    if (!strcmp(client_reply, "EXIT")) 
    {
        close_client(client_fd);    
        close_server(server_fd);
        return 0;
    }

    // Buffer and variables.
    char buffer[BUFF_SIZ] = "";
    char filename[20] = "";
    int bytes = 0;
    
    FILE *fp = NULL;

    // Get Filename and it's extension
    recv(client_fd, filename, 20, 0);
    const char *extension = get_extension(client_fd, filename);
    if (extension == NULL) 
    {
        close_client(client_fd);
        close_server(server_fd);
        return 1;
    }
    
    // Opening appropriate files for receiving data
    if(!strcmp("txt", extension))
    {
        fp = fopen(filename, "w"); // Opens (Text)file in write mode
        if (fp == NULL)
        {
            perror("[x]Error opening file:");
            exit(EXIT_FAILURE);
        }
        printf("[+]File opened with name %s\n", filename);

        while (1)
        {
            bytes = err_check(recv(client_fd, buffer, BUFF_SIZ, 0), "[x]Error receiving data:");
            if (bytes == 0) 
            {
                puts("[+]File received");
                break;
            }
            fputs(buffer, fp);
        }
    }
    else if(!strcmp("mp3", extension) || !strcmp("mp4", extension))
    {
        fp = fopen(filename, "wb"); // Opens (binary)file in write mode
        if (fp == NULL)
        {
            perror("[x]Error opening file:");
            exit(EXIT_FAILURE);
        }
        printf("[+]File opened with name %s\n", filename);

        while (1)
        {
            bytes = err_check(recv(client_fd, buffer, BUFF_SIZ, 0), "[x]Error receiving data:");
            if (bytes == 0)
            {
                puts("[+]File received");
                break;
            }
            fwrite(buffer, 1, BUFF_SIZ, fp);
        }
    }

    // CLose file
    fclose(fp);

    close_client(client_fd);
    close_server(server_fd);

    return 0;
}

// Create a TCP IPv4 Socket and return it's file descriptor
int create_tcp_ipv4_socket()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0)
    {
        perror("[+]Socket Connection Failed");
        exit(EXIT_FAILURE);
    }
    else
        puts("[+]Socket Created");

    return fd;
}

// Create a socket address and returns a pointer to the address (Input empty string in case of server)
struct sockaddr_in* create_socket_addr(char* ip, int port)
{
    struct sockaddr_in *address = malloc(sizeof(struct sockaddr_in)); // Pre Defined struct
    address->sin_family = AF_INET;
    address->sin_port = htons(port);

    if(ip == "") // Empty string In case of server
    {
        address->sin_addr.s_addr = INADDR_ANY;
    }
    else if(!inet_pton(AF_INET, ip, &address->sin_addr.s_addr)) // In case of Client
    {
        perror("[-]Invalid IP-Address"); // If invalid address
        exit(EXIT_FAILURE);
    }

    return address;
}

const char* get_extension(int sock_fd, char *filename)
{
    const char *extension = strrchr(filename, '.');
    if (!strcmp(extension, filename) || !extension) // if equal or if empty
    {
        puts("Invalid file name.");
        return NULL;
    }

    return extension+1;
}

int err_check(int return_val, const char *print)
{
    if (return_val == -1)
    {
        perror(print);
        exit(EXIT_FAILURE);
    }
    return return_val;
}


void close_client(int client_fd)
{
    // Closing client connection socket
    err_check(close(client_fd), "[x]Error closing socket:");
    puts("[+]Client Socket Closed");
}

void close_server(int server_fd)
{
    // Shutting down server
    err_check(shutdown(server_fd, SHUT_RDWR), "[x]Error shutting down socket:");
    puts("[+]Server Closed");
}

// These addresses might come in handy.
// broadcast 10.7.51.255
// inet 10.7.48.64
// local host 127.0.0.1