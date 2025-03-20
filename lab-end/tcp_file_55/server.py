import socket

# Server code
def server_program():
    # Define server address and port
    host = '127.0.0.1'  # Localhost IP
    port = 55  # Port number to listen on

    # Create a socket object using IPv4 and TCP (stream socket)
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    # Bind socket to address and port
    server_socket.bind((host, port))
    server_socket.listen(1)  # Listen for incoming connections (1 client at a time)
    
    print(f"Server listening on {host}:{port}")

    # Accept a new connection
    conn, address = server_socket.accept()
    print(f"Connection from: {address}")

    # Receive file name requested by the client
    file_name = conn.recv(1024).decode()  # Buffer size of 1024 bytes
    print(f"Client requested file: {file_name}")

    # Try to open and read the requested file
    try:
        with open(file_name, 'r') as file:
            file_data = file.read()  # Read file content
            conn.sendall(file_data.encode())  # Send file content to client
    except FileNotFoundError:
        conn.send(b"File not found")  # Send error message if file not found

    # Close the connection
    conn.close()

if __name__ == "__main__":
    server_program()
