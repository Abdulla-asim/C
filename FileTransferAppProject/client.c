// TCP CLient
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sendfile.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 2000
#define BUFF_SIZ 1024

// Enum for checking file extension/type
typedef enum {txt = 1, mp3, mp4, EXIT}file_type;
char *string[5] = {"txt", "mp3", "mp4", "EXIT"};

// Function Prototypes
int create_tcp_ipv4_socket();
struct sockaddr_in* create_socket_addr(char* ip, int port);
int err_check(int return_val, const char *print);

// MAIN
int main(int argc, char** argv)
{
    // Input Check
    if (argc != 2)
    {
        printf("USAGE: %s 'IP-Address'\n", argv[0]);
        return 1;
    }
    char* input_addr = argv[1];


    // Socket Creation
    int client_fd = create_tcp_ipv4_socket(); //  Create Socket and store the file descriptor in 'fd'
    // Associate the port number and the server address to the client socket
    struct sockaddr_in *server_addr = create_socket_addr(input_addr, PORT);


    // Connecting
    // Connects the client socket to the server address
    err_check(connect(client_fd, (const struct sockaddr *) server_addr, sizeof(*server_addr)), "[x]Could not connect.");
    puts("[+]Connection Successful"); 


    file_type choice;
    do{
        puts("\nCHOOSE THE TYPE OF FILE TO SEND");
        printf("\n1. Text File\n2. Audio File\n3. Video File\n4. EXIT\n\nYour Choice : ");
        scanf("%d", (int*)&choice);
        getchar(); // Clear the input buffer to remove '\n'
        send(client_fd, string[choice - 1], 4, 0); // Sends msg to the server to close.

        if (choice == -1)  // exits the client application if -1 was entered
        {
            printf("\nExited the client application...%d\n", choice);
            return 1;
        }
    } while (choice < 1 || choice > 4); // user can only choose nums between 1 and 3


    char filename[20] = ""; // Initializes the char array with NUL characters '\0'
    printf("Enter the filename you want to send (filename.extension): ");
    scanf(" %s", filename); // Reads max 19 chars to handle buffer overflow
    getchar(); // Clear the input buffer

    send(client_fd, filename, 20, 0); // Send the filename to server

    FILE *fp; // File pointer
    char buffer[BUFF_SIZ] = ""; // Initializes the char array to NUL characters '\0' 

    // Choices to send text file, mp3 or video files.
    switch (choice)
    {
        case txt:
            // Open file for reading binary data
            fp = fopen(filename, "r");
            if (fp == NULL) // Check if file opened or not
            {
                perror("Error opening file:");
                exit(EXIT_FAILURE);
            }

            // Read the file into the buffer and send to server
            while (fgets(buffer, BUFF_SIZ, fp) != NULL)
            {
                send(client_fd, buffer, BUFF_SIZ, 0);
            }
            puts("[+]File sent");
            break;

        case mp3:
        case mp4:
            // Open file for reading binary data
            fp = fopen(filename, "rb");
            if (fp == NULL) // Check if file opened or not
            {
                perror("Error opening file:");
                exit(EXIT_FAILURE);
            }

            // Read the file into the buffer and send to server
            while (fread(buffer, 1, BUFF_SIZ, fp) > 0)
            {
                send(client_fd, buffer, BUFF_SIZ, 0);
            }
            puts("[+]File sent");
            break;
        
        default:

            puts("Extension not found.");
            break;
    }

    // Close File
    fclose(fp);

    // Close Socket
    err_check(close(client_fd), "[X]Error closing socket");
    puts("[+]Client Socket Closed");


    return 0;
}
// END MAIN

// Create a TCP IPv4 Socket and return its socket descriptor (file descriptor)
int create_tcp_ipv4_socket()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0); // AF_INET signifies 'ipv4' and sock_stream with flag 0 signifies TCP 
    if (fd < 0)
    {
        perror("[x]Socket Connection Failed");
        exit(EXIT_FAILURE);
    }
    puts("[+]Socket Created..");

    return fd;
}

// Create a socket address and returns a pointer to the address (Input empty string in case of server)
struct sockaddr_in* create_socket_addr(char* ip, int port)
{
    struct sockaddr_in *address = malloc(sizeof(struct sockaddr_in)); // sockaddr_in is a Pre Defined struct
    address->sin_family = AF_INET; // Setting the address family "IPv4"
    address->sin_port = htons(port); // Setting the port

    if (ip == "") // Empty string In case of server
    {
        address->sin_addr.s_addr = INADDR_ANY; // Tell the server to accept any IP adress and connect
    }
    else if (!inet_pton(AF_INET, ip, &address->sin_addr.s_addr)) // In case of Client (converts the ip into network byte order and stores it in s_addr)
    {
        perror("[x]Invalid IP-Address"); // If invalid address
        exit(EXIT_FAILURE);
    }

    return address;
}

// Checks for errors and returns the original function's return value
int err_check(int return_val, const char *print)
{
    if (return_val == -1)
    {
        perror(print);
        exit(EXIT_FAILURE);
    }
    return return_val;
}