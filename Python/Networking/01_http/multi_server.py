import time
from threading import Thread
from socket import *


class ConnectionThread(Thread):
    def __init__(self, connectionSocket, cnt):
        super().__init__()
        self.cnt = cnt
        self.connectionSocket = connectionSocket
    
    def run(self):
        try:
            message =  self.connectionSocket.recv(1024).decode() #Fill in start #Fill in end
            if len(message) < 1:
                raise IOError
            filename = message.split()[1]
            print(filename)
            with open(filename[1:]) as f:
                outputdata = f.read() #Fill in start #Fill in end

            #Send one HTTP header line into socket
            #Fill in start
            response = 'HTTP/1.1 200 OK\r\n' \
                    'Connection: close\r\n' \
                    'Content-Length: ' + str(len(outputdata)) + '\r\n' \
                    'Content-type: text\html\r\n\r\n'
            self.connectionSocket.send(response.encode())
            #Fill in end

            #Send the content of the requested file to the client
            # for i in range(0, len(outputdata)):
            self.connectionSocket.send(outputdata.encode())
            self.connectionSocket.send("\r\n".encode())
            self.connectionSocket.close()
            for i in range(5):
                print('Thread', self.cnt, ':', i + 1)
                time.sleep(1)

        except IOError:

            #Send response message for file not found

            #Fill in start
            print('IO Error')
            response = 'HTTP/1.1 404 Not Found\r\n' \
                    'Connection: close\r\n\r\n'
            self.connectionSocket.send(response.encode())
            self.connectionSocket.close()
            #Fill in end

if __name__ == "__main__":
    serverSocket = socket(AF_INET, SOCK_STREAM)
    #Prepare a sever socket
    #Fill in start
    serverSocket.bind(('', 6789))
    serverSocket.listen(3)
    #Fill in end

    cnt = 0
    while True:
        #Establish the connection
        print('Ready to serve...')
        connectionSocket, _ = serverSocket.accept() 
        ConnectionThread(connectionSocket, cnt).start()
        cnt += 1
