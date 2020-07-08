#import socket module
from socket import *
import sys # In order to terminate the program

serverSocket = socket(AF_INET, SOCK_STREAM)
#Prepare a sever socket
#Fill in start
serverSocket.bind(('', 6789))
serverSocket.listen(1)
#Fill in end

while True:
    #Establish the connection
    print('Ready to serve...')
    connectionSocket, addr = serverSocket.accept() #Fill in start #Fill in end
    try:
        message =  connectionSocket.recv(1024).decode() #Fill in start #Fill in end
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
        connectionSocket.send(response.encode())
        #Fill in end

        #Send the content of the requested file to the client
        # for i in range(0, len(outputdata)):
        connectionSocket.send(outputdata.encode())
        connectionSocket.send("\r\n".encode())
        connectionSocket.close()

    except IOError:

        #Send response message for file not found

        #Fill in start
        print('IO Error')
        response = 'HTTP/1.1 404 Not Found\r\n' \
                   'Connection: close\r\n\r\n'
        connectionSocket.send(response.encode())
        connectionSocket.close()
        #Fill in end

#Close client socket

#Fill in start

#Fill in end

serverSocket.close()

sys.exit()#Terminate the program after sending the corresponding data