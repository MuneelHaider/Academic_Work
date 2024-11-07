import socket

def create_socket():
    # create the socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # setup an address
    server_address = ('localhost', 8080)
    sock.connect(server_address)
    
    return sock

def main():
    print("\n\t>>>>>>>>>> XYZ University Chat Client <<<<<<<<<<\n\n")

    # Create socket and connect to the server
    sock = create_socket()

    while True:
        # Get user input and send it to the server
        message = input("You (Client): ")

        # Send the message to the server
        sock.send(message.encode('utf-8'))

        # If the client sends "exit", terminate the chat
        if message == "exit":
            print("You disconnected from the chat.")
            break

        # receive response from server
        response = sock.recv(256).decode('utf-8')
        print(response)

    # Close the socket after communication
    sock.close()

if __name__ == "__main__":
    main()
