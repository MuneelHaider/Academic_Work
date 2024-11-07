import socket
import os

def main():
    print("\n\t>>>>>>>>>> XYZ University Chat Server <<<<<<<<<<\n\n")

    # create the server socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # define the server address
    server_address = ('', 8080)

    # bind the socket to the specified IP and port
    server_socket.bind(server_address)
    server_socket.listen(5)

    while True:
        # accept incoming connections
        client_socket, client_address = server_socket.accept()

        # create a new process to handle the client
        pid = os.fork()
        if pid == -1:
            print("Error! Unable to fork process.")
        elif pid == 0:
            # child process handles the client
            handle_client(client_socket)
            os._exit(0)
        else:
            # parent process continues accepting clients
            client_socket.close()

def handle_client(client_socket):
    while True:
        # receive message from the client
        buf = client_socket.recv(256).decode('utf-8')

        # if client sends "exit", close the connection
        if buf == "exit":
            print("Client disconnected.")
            break

        print("Client:", buf)

        # send a response back to the client
        response = input("You (Server): ")
        message = "Server: " + response
        client_socket.send(message.encode('utf-8'))

    client_socket.close()

if __name__ == "__main__":
    main()
