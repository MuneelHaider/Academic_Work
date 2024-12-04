import socket
import threading
import hashlib
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives import padding
from cryptography.hazmat.backends import default_backend
import random
import os


def diffieHell(base, prime, priKey):
    return pow(base, priKey, prime)


def createSKey(pubKey, priKey, prime):
    shareKey = pow(pubKey, priKey, prime)
    return hashlib.sha256(str(shareKey).encode()).digest()


def padMessage(message):
    padder = padding.PKCS7(algorithms.AES.block_size).padder()
    return padder.update(message.encode()) + padder.finalize()


def unPadMessage(message):
    unpadder = padding.PKCS7(algorithms.AES.block_size).unpadder()
    return unpadder.update(message) + unpadder.finalize()


def aesEncry(message, key):
    iv = os.urandom(16)  # Random Initialization Vector
    cipher = Cipher(algorithms.AES(key), modes.CBC(iv), backend=default_backend())
    encryptor = cipher.encryptor()
    ciphertext = encryptor.update(padMessage(message)) + encryptor.finalize()
    return iv + ciphertext


def aesDecry(ciphertext, key):
    iv = ciphertext[:16]  # Extract IV
    cipher = Cipher(algorithms.AES(key), modes.CBC(iv), backend=default_backend())
    decryptor = cipher.decryptor()
    padded_message = decryptor.update(ciphertext[16:]) + decryptor.finalize()
    return unPadMessage(padded_message).decode()


def check_username_exists(username):
    try:
        with open("creds.txt", "r") as f:
            for line in f:
                stored_username = line.strip().split(",")[0]
                if stored_username == username:
                    return True
    except FileNotFoundError:
        pass
    return False


def clientHandle(sock, addr):
    print(f"Connected to {addr}")
    base = 2
    prime = int("FFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7EDEE386BFB5A899FA5AE9F24117C4B1FE649286651ECE65381FFFFFFFFFFFFFFFF", 16)

    try:
        while True:
            comm = sock.recv(1024).decode().split()
            if not comm:
                break

            if comm[0] == "REGISTER":
                priKey = random.randint(2, prime - 2)
                pubKey = diffieHell(base, prime, priKey)
                sock.send(str(pubKey).encode())
                sShareKey = createSKey(int(comm[1]), priKey, prime)

                encrypted_data = sock.recv(1024)
                user_data = aesDecry(encrypted_data, sShareKey)
                email, username, password = user_data.split(",")

                if check_username_exists(username):
                    sock.send("Registration failed: Username already exists.".encode())
                    continue

                salt = os.urandom(16)
                hashPass = hashlib.sha256(salt + password.encode()).hexdigest()

                with open("creds.txt", "a") as f:
                    f.write(f"{username},{email},{hashPass},{salt.hex()}\n")

                sock.send("Successfully Registered.".encode())

            elif comm[0] == "LOGIN":
                priKey = random.randint(2, prime - 2)
                pubKey = diffieHell(base, prime, priKey)
                sock.send(str(pubKey).encode())
                sShareKey = createSKey(int(comm[1]), priKey, prime)

                encrypted_data = sock.recv(1024)
                user_data = aesDecry(encrypted_data, sShareKey)
                username, password = user_data.split(",")

                print(f"Attempting login for username: {username}")

                with open("creds.txt", "r") as f:
                    users = [line.strip().split(",") for line in f.readlines()]

                for user in users:
                    sUsername, email, sHashPass, salt = user

                    if sUsername == username:
                        hashPass = hashlib.sha256(bytes.fromhex(salt) + password.encode()).hexdigest()

                        print(f"Stored hash: {sHashPass}")
                        print(f"Calculated hash: {hashPass}")

                        if hashPass == sHashPass:
                            sock.send("Login successful".encode())
                            break
                else:
                    sock.send("Login failed".encode())

            elif comm[0] == "CHAT":
                priKey = random.randint(2, prime - 2)
                pubKey = diffieHell(base, prime, priKey)
                sock.send(str(pubKey).encode())
                shareKey = createSKey(int(comm[1]), priKey, prime)

                dKey = hashlib.sha256(shareKey + username.encode()).digest()

                while True:
                    encryMessage = sock.recv(256)
                    if not encryMessage:
                        break

                    message = aesDecry(encryMessage, dKey)

                    if message.lower() == "exit":
                        print("Client disconnected.")
                        break

                    print("Client:", message)
                    response = input("You (Server): ")
                    sock.send(aesEncry(response, dKey))

    except Exception as e:
        print(f"Error: {e}")

    finally:
        print(f"Connection to {addr} closed.")
        sock.close()


def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = ('', 8080)
    server_socket.bind(server_address)
    server_socket.listen(5)
    print("Server listening on port 8080...")

    while True:
        client_socket, client_address = server_socket.accept()
        client_thread = threading.Thread(target=clientHandle, args=(client_socket, client_address))
        client_thread.start()


if __name__ == "__main__":
    main()
