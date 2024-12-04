import socket
import getpass
from hashlib import sha256
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives import padding
from cryptography.hazmat.backends import default_backend
import random
import os


def diffieHell(base, prime, private_key):
    return pow(base, private_key, prime)


def createSKey(public_key, private_key, prime):
    shareKey = pow(public_key, private_key, prime)
    return sha256(str(shareKey).encode()).digest()


def padMessage(message):
    padder = padding.PKCS7(algorithms.AES.block_size).padder()
    return padder.update(message.encode()) + padder.finalize()


def unpadMessage(message):
    unpadder = padding.PKCS7(algorithms.AES.block_size).unpadder()
    return unpadder.update(message) + unpadder.finalize()


def aesEncry(message, key):
    iv = os.urandom(16)  # Initialization vector
    cipher = Cipher(algorithms.AES(key), modes.CBC(iv), backend=default_backend())
    encryptor = cipher.encryptor()
    ciphertext = encryptor.update(padMessage(message)) + encryptor.finalize()
    return iv + ciphertext


def aesDecry(ciphertext, key):
    iv = ciphertext[:16]  # Extract IV
    cipher = Cipher(algorithms.AES(key), modes.CBC(iv), backend=default_backend())
    decryptor = cipher.decryptor()
    padded_message = decryptor.update(ciphertext[16:]) + decryptor.finalize()
    return unpadMessage(padded_message).decode()


def create_socket():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = ('localhost', 8080)
    sock.connect(server_address)
    return sock


def register(sock, base, prime):
    email = input("Enter email: ")
    username = input("Enter username: ")
    password = getpass.getpass("Enter password: ")

    priKey = random.randint(2, prime - 2)
    pubKey = diffieHell(base, prime, priKey)

    sock.send(f"REGISTER {pubKey}".encode())
    sPubKey = int(sock.recv(1024).decode())
    shareKey = createSKey(sPubKey, priKey, prime)

    user_data = f"{email},{username},{password}"
    encrypted_data = aesEncry(user_data, shareKey)
    sock.send(encrypted_data)

    response = sock.recv(1024).decode()
    print(response)


def login(sock, base, prime):
    username = input("Enter username: ")
    password = getpass.getpass("Enter password: ")

    priKey = random.randint(2, prime - 2)
    pubKey = diffieHell(base, prime, priKey)

    sock.send(f"LOGIN {pubKey}".encode())
    sPubKey = int(sock.recv(1024).decode())
    shareKey = createSKey(sPubKey, priKey, prime)

    user_data = f"{username},{password}"
    encrypted_data = aesEncry(user_data, shareKey)
    sock.send(encrypted_data)

    response = sock.recv(1024).decode()
    print(response)

    return response == "Login successful", shareKey, username


def chat(sock, shared_key, username):
    dKey = sha256(shared_key + username.encode()).digest()

    while True:
        message = input("Client: ")
        encryMessage = aesEncry(message, dKey)
        sock.send(encryMessage)

        if message.lower() == "exit":
            print("You disconnected from the chat.")
            break

        response = aesDecry(sock.recv(256), dKey)
        print("Server:", response)

    sock.close()


def main():
    print("-------------------------- FAST NUCES Chat Client ------------------------------")
    sock = create_socket()

    base = 2
    prime = int("FFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7EDEE386BFB5A899FA5AE9F24117C4B1FE649286651ECE65381FFFFFFFFFFFFFFFF", 16)

    choice = input("Do you want to register as a new user or login? (register/login): ").strip().lower()

    if choice == "register":
        register(sock, base, prime)
    elif choice == "login":
        good, shareKey, username = login(sock, base, prime)
        if good:
            print("Login successful. You can proceed with the chat.")
            private_key = random.randint(2, prime - 2)
            public_key = diffieHell(base, prime, private_key)

            sock.send(f"CHAT {public_key}".encode())
            server_public_key = int(sock.recv(1024).decode())
            shareKey = createSKey(server_public_key, private_key, prime)
            chat(sock, shareKey, username)
        else:
            print("Login failed.")
    else:
        print("Error.")


if __name__ == "__main__":
    main()
