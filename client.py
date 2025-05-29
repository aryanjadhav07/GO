import socket

s = socket.socket()
s.connect(('Localhost', 9999))
print("Connected to the server successfully.")

s.send(b"Hello Server, I am client.")
print("server : ", s.recv(1024).decode())

exp = input("Enter the expression : ")
s.send(exp.encode())
print("Result : ", s.recv(1024).decode())

file_name = input("Enter the file name to download : ")
s.send(file_name.encode())

with open(file_name, 'wb') as f:
    while True: 
        data = s.recv(1024)
        if not data : break
        f.write(data)

print("File downloaded successfully.")
s.close()
