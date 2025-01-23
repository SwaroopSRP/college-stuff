import socket

def start_client():
    """
    Function to connect to the server, send a message,
    receive a response, and then close the connection.
    """
    # Create a socket object for IPv4 and TCP protocol
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Define the server address and port to connect to
    server_address = ('localhost', 53)

    # Connect to the server
    client_socket.connect(server_address)
    print("Connected to the server.")

    # Send a message to the server
    client_message = "Hello fraands, connect me pls"
    client_socket.send(client_message.encode())

    # Receive a message from the server
    server_message = client_socket.recv(1024).decode()
    print(f"Message from server: {server_message}")

    # Close the connection after the communication is done
    client_socket.close()
    print("Connection closed.")

if __name__ == "__main__":
    start_client()
