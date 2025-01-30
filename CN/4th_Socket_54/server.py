import socket

def start_server():
    """
    Function to start the server, listen for incoming connections,
    and handle communication with a client.
    """
    # Create a socket object for IPv4 and TCP protocol
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Define the server address and port
    server_address = ('localhost', 53)

    # Bind the socket to the server address and port
    server_socket.bind(server_address)

    # Start listening for incoming connections (maximum 1 client)
    server_socket.listen(1)
    print("Server is listening/waiting on port 53...")

    # Wait for a connection from the client
    connection, client_address = server_socket.accept()
    print(f"Successfully connected with {client_address}!")

    # # Receive the message from the client
    # client_message = connection.recv(1024).decode()
    # print(f"Message from client: {client_message}")

    # # Send a response back to the client
    # server_message = "Hello bro ur connected already!"
    # connection.send(server_message.encode())

    # # Close the connection after the communication is done
    # connection.close()
    # print("Connection closed.")

    while True:
        client_message = connection.recv(1024).decode()
        if client_message.lower() == "/exit":
            print("Client executed disconnection!")
            break

        server_message = input("(Server) Enter message: ")
        if client_message == "":
            continue
        connection.sendall(server_message.encode())

        if server_message.lower() == "/exit":
            print("Server executed disconnection!")
            break

    connection.close()
    server_socket().close()

if __name__ == "__main__":
    start_server()
