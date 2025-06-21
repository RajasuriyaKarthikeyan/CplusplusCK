#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

#define PORT 8080

int main(){
    int sock = 0;
    struct sockaddr_in server_address;
    const char *hello = "Hello from client";
    

    //Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0){
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    //Convert IPv4 or IPv6 address from text to binary
    if(inet_pton(AF_INET, "127.0.0.1" , &server_address.sin_addr) <= 0){
        std::cerr << "Invalid address / Address not supported" << std::endl;
        return -1;
    }

    //Connect to server
    if( connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0){
        std::cerr << "Connection failed" << std::endl;
        return -1;
    }

    //Send data
    send(sock, hello, strlen(hello), 0);
    std::cout << "Message sent to server" << std::endl;

    //close the socket
    close(sock);
    return 0;

}