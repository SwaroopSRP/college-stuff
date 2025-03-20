import socket

# Server code to handle multiple clients sequentially (no threads)
def server_program():
    host = '127.0.0.1'  # Server's IP
    port = 57  # Port for the server

    # Create a socket object using IPv4 and TCP
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))  # Bind to the specified address and port
    server_socket.listen(5)  # Allow multiple pending connections

    print(f"Server listening on {host}:{port}")

    while True:
        conn, address = server_socket.accept()  # Accept a client connection
        print(f"Connection from: {address}")

        # Receive file name from client
        file_name = conn.recv(1024).decode()
        print(f"Client requested file: {file_name}")

        # Try to open and read the file
        try:
            with open(file_name, 'r') as file:
                file_data = file.read()
                conn.send(file_data.encode())  # Send file content to client
        except FileNotFoundError:
            conn.send(b"File not found")

        # Close the connection after serving the client
        conn.close()
        print(f"Connection with {address} closed")

if __name__ == "__main__":
    server_program()
