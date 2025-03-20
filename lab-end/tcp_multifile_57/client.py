import socket

def client_program():
    host = '127.0.0.1'  # Server address
    port = 57  # Server port

    # Create a socket object using IPv4 and TCP
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((host, port))  # Connect to the server

    # Get file name from user input
    file_name = input("Enter file name to request: ")
    client_socket.send(file_name.encode())  # Send file name to server

    # Receive file content from server
    file_data = client_socket.recv(4096).decode()

    print("\nReceived from server:")
    print(file_data)  # Display the received file content or error message

    # Close the client socket
    client_socket.close()

if __name__ == "__main__":
    client_program()
