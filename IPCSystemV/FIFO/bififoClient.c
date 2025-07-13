#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO1 "fifo1"  // client -> server
#define FIFO2 "fifo2"  // server -> client

int main() {
    char buffer[100];

    int write_fd = open(FIFO1, O_WRONLY);
    int read_fd = open(FIFO2, O_RDONLY);

    while (1) {
        printf("Client: Enter message: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline

        write(write_fd, buffer, strlen(buffer));

        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }

        // Read server response
        char response[100];
        ssize_t bytes = read(read_fd, response, sizeof(response) - 1);
        if (bytes > 0) {
            response[bytes] = '\0';
            printf("Client received: %s\n", response);
            if (strncmp(response, "exit", 4) == 0) {
                break;
            }
        }
    }

    close(read_fd);
    close(write_fd);
    return 0;
}
