import socket

# Client configuration
SERVER_IP = "127.0.0.1"  # Localhost (change if running on different machines)
SERVER_PORT = 59  # Server port
BUFFER_SIZE = 1024  # Size of data chunks

# Create UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Request a specific file from the server
file_name = input("Enter the name of the binary file to download: ").strip()
client_socket.sendto(file_name.encode(), (SERVER_IP, SERVER_PORT))

# Receive server response
response, _ = client_socket.recvfrom(BUFFER_SIZE)

if response == b"FILE_FOUND":
    with open(f"received_{file_name}", "wb") as file:
        while True:
            data, _ = client_socket.recvfrom(BUFFER_SIZE)
            if data == b"EOF":
                break  # End of file transmission
            file.write(data)

    print(f"File '{file_name}' received successfully.")
else:
    print(response.decode())  # Display error message

# Close socket
client_socket.close()
