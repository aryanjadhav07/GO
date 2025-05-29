import socket, os

s = socket.socket()
s.bind(('', 8888))
s.listen(1)
print("Server is waiting for client connection...")
c, _ = s.accept()

print("Client:", c.recv(1024).decode())
c.send(b"Hello from Server")

# Calculator
expr = c.recv(1024).decode()
c.send(str(eval(expr)).encode())

# Receive requested file name
file_name = c.recv(1024).decode()
if os.path.exists(file_name):
    with open(file_name, 'rb') as f:
        data = f.read()
        c.sendall(data)
    c.shutdown(socket.SHUT_WR)
    print(f"Sent file: {file_name}")
else:
    c.send(b"File not found")
    c.shutdown(socket.SHUT_WR)
    print("File not found.")
    
c.close()
