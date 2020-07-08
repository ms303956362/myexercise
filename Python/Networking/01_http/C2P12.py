from socket import *
port = 6324
sk = socket(AF_INET, SOCK_STREAM)
sk.bind(('', port))
sk.listen(1)
print('Server is ready to receive')
i = 0
while i < 10:
    con, _ = sk.accept()
    text = con.recv(1024).decode()
    print(text)
    i += 1
    con.close()
