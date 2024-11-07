#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;

int main() {
    char buf[256];
    char message[256] = "Server: ";
    
    cout << "\n\t>>>>>>>>>> XYZ University Chat Server <<<<<<<<<<\n\n";
    
    // create the server socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to the specified IP and port
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    listen(server_socket, 5);

    while (1) {
        // accept incoming connections
        int client_socket;
        client_socket = accept(server_socket, NULL, NULL);

        // create a new process to handle the client
        pid_t new_pid;
        new_pid = fork();
        if (new_pid == -1) {
            // error occurred while forking
            cout << "Error! Unable to fork process.\n";
        } else if (new_pid == 0) {
            // child process handles the client
            while (true) {
                // clear buffer and receive message from client
                memset(buf, 0, sizeof(buf));
                recv(client_socket, buf, sizeof(buf), 0);

                // if client sends "exit", close the connection
                if (strcmp(buf, "exit") == 0) {
                    cout << "Client disconnected.\n";
                    break;
                }

                cout << "Client: " << buf << endl;

                // Send a response back to the client
                cout << "You (Server): ";
                string response;
                getline(cin, response);
                strcpy(message + 8, response.c_str()); // append the response after "Server: "
                send(client_socket, message, sizeof(message), 0);
            }

            // Close the client socket after communication
            close(client_socket);
            exit(0);
        } else {
            // parent process continues accepting clients
            close(client_socket);
        }
    }

    close(server_socket);

    return 0;
}
