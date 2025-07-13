#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO1 "fifo1"  // client -> server
#define FIFO2 "fifo2"  // server -> client

int main() {
    char buffer[100];

    // Create FIFOs if they do not exist
    mkfifo(FIFO1, 0666);
    mkfifo(FIFO2, 0666);

    printf("Server: Waiting for messages from client...\n");

    int read_fd = open(FIFO1, O_RDONLY);
    int write_fd = open(FIFO2, O_WRONLY);

    while (1) {
        ssize_t bytes = read(read_fd, buffer, sizeof(buffer) - 1);
        if (bytes > 0) {
            buffer[bytes] = '\0';
            printf("Server received: %s\n", buffer);

            if (strncmp(buffer, "exit", 4) == 0) {
                break;
            }

            // Respond to client
            printf("Server: Enter message: ");
            char response[100];
            fgets(response, sizeof(response), stdin);
            response[strcspn(response, "\n")] = '\0'; // Remove newline

            write(write_fd, response, strlen(response));

            if (strncmp(response, "exit", 4) == 0) {
                break;
            }
        }
    }

    close(read_fd);
    close(write_fd);
    unlink(FIFO1);
    unlink(FIFO2);
    return 0;
}
