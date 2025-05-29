import socket, os

s = socket.socket()
s.bind(('', 9999))
s.listen(1)
print("Server is waiting for client connectin.....")
c, _= s.accept()

print ("Client connected successfully.")

print("Client : ", c.recv(1024).decode())
c.send(b"Hello Client, I am server and how can I help you? ")

exp = c.recv(1024).decode()
c.send(str(eval(exp)).encode())

file_name = c.recv(1024).decode()
if os.path.exists(file_name):
    with open(file_name, 'rb') as f: 
        data = f.read()
        c.sendall(data)
        print("File " + file_name + " sent successfully.")
        c.shutdown(socket.SHUT_WR)

else:
    c.send(b"File not found.")
    c.shutdown(socket.SHUT_WR)
    print("File not found")
    c.close()
    print ("Connection closed.")