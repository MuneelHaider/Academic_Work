#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

int sock;

void create_socket() {
    // create the socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // setup an address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    connect(sock, (struct sockaddr *) &server_address, sizeof(server_address));
}

int main() {
    char buf[256];

    printf("\n\t>>>>>>>>>> XYZ University Chat Client <<<<<<<<<<\n\n");

    // Create socket and connect to the server
    create_socket();

    while (1) {
        // Get user input and send it to the server
        printf("You (Client): ");
        char message[256];
        fgets(message, sizeof(message), stdin);

        // Remove newline character from the message
        message[strcspn(message, "\n")] = 0;

        // Send the message to the server
        strcpy(buf, message);
        send(sock, buf, sizeof(buf), 0);

        // If the client sends "exit", terminate the chat
        if (strcmp(message, "exit") == 0) {
            printf("You disconnected from the chat.\n");
            break;
        }

        // Clear buffer and receive response from server
        memset(buf, 0, sizeof(buf));
        recv(sock, buf, sizeof(buf), 0);
        printf("%s\n", buf);
    }

    // Close the socket after communication
    close(sock);

    return 0;
}
