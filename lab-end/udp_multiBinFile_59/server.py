import socket
import os

# Server configuration
HOST = "127.0.0.1"  # Localhost
PORT = 59  # Server port
BUFFER_SIZE = 1024  # Size of data chunks

# Create UDP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.bind((HOST, PORT))

print(f"Server is listening on {HOST}:{PORT}...")

while True:
    try:
        # Receive file request from client
        data, client_address = server_socket.recvfrom(BUFFER_SIZE)
        file_name = data.decode().strip()
        print(f"Client {client_address} requested file: {file_name}")

        if os.path.exists(file_name):
            # Send confirmation to the client
            server_socket.sendto(b"FILE_FOUND", client_address)

            # Open file and send in chunks
            with open(file_name, "rb") as file:
                while (chunk := file.read(BUFFER_SIZE)):
                    server_socket.sendto(chunk, client_address)

            # Send end-of-file signal
            server_socket.sendto(b"EOF", client_address)
            print(f"File '{file_name}' sent successfully.")

        else:
            server_socket.sendto(b"ERROR: File not found", client_address)

    except Exception as e:
        print(f"Error: {e}")

# Close socket (unreachable in this case, but good practice)
server_socket.close()
