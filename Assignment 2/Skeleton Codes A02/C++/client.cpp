#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
using namespace std;

int sock;

void create_socket()
{
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

    cout << "\n\t>>>>>>>>>> XYZ University Chat Client <<<<<<<<<<\n\n";
    
    // Create socket and connect to the server
    create_socket();

    while (true) {
        // Get user input and send it to the server
        cout << "You (Client): ";
        string message;
        getline(cin, message);

        // Send the message to the server
        strcpy(buf, message.c_str());
        send(sock, buf, sizeof(buf), 0);

        // If the client sends "exit", terminate the chat
        if (message == "exit") {
            cout << "You disconnected from the chat.\n";
            break;
        }

        // Clear buffer and receive response from server
        memset(buf, 0, sizeof(buf));
        recv(sock, buf, sizeof(buf), 0);
        cout << buf << endl;
    }

    // Close the socket after communication
    close(sock);

    return 0;
}
