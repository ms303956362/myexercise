from socket import *

server = ('127.0.0.1', 6789)
with socket(AF_INET, SOCK_STREAM) as clientSocket:
    clientSocket.connect(server)
    httpHeader = 'GET /index.html HTTP/1.1\r\nHost: 127.0.0.1\r\n\r\n'
    clientSocket.send(httpHeader.encode())
    response = ""
    while True:
        msg = clientSocket.recv(1024)
        if msg:
            response += msg.decode()
        else:
            break
    print(response)
