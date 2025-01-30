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

    while True:
        client_message = input("(Client) Enter message: ")
        if client_message == "":
            continue
        client_socket.sendall(client_message.encode())
        
        if client_message.lower() == "/exit":
            print("Client executed disconnection!")
            break

        server_message = client_socket.recv(1024).decode()
        if server_message == "/exit":
            print("Server executed disconnection!")
            break

        print(f"Server: {server_message}")

    client_socket().close()

    # Close the connection after the communication is done
    client_socket.close()
    print("Connection closed.")

if __name__ == "__main__":
    start_client()
