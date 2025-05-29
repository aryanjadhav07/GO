import socket

s = socket.socket()
s.connect(('localhost', 8888))

s.send(b"Hello from Client")
print("Server:", s.recv(1024).decode())

expr = input("Enter expression (e.g., 2+3*4): ")
s.send(expr.encode())
print("Result:", s.recv(1024).decode())

# Ask user for file name to request
file_name = input("Enter file name to download from server: ")
s.send(file_name.encode())

# Save with same name
with open('received' + file_name, 'wb') as f:
    while True:
        data = s.recv(1024)
        if not data: break
        f.write(data)
print("File received.")
s.close()
