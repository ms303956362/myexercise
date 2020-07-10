from socket import *
import sys

# if len(sys.argv) <= 1:
#     print('Usage: "python ProxyServer.py server_ip"\nserver_ip: It is the IP Address Of Proxy Server')
#     sys.exit(2)

# Create a server socket, bind it to a port and start listening
tcpSerSock = socket(AF_INET, SOCK_STREAM)
# Fill in start.
tcpSerSock.bind(('', 6789))
tcpSerSock.listen(3)
# Fill in end.

while 1:
    # Start receiving data from the client
    print('Ready to serve...')
    tcpCliSock, addr = tcpSerSock.accept()
    print('Received a connection from:', addr)
    message = tcpCliSock.recv(1024).decode() # Fill in start. # Fill in end.
    if message[:3] != 'GET':
        continue
    print(message)
    
    # Extract the filename from the given message
    url = message.split()[1]
    print(url)
    filename = url[1:].replace('/', '-')
    print(filename)
    fileExist = "false"
    filetouse = "/" + filename
    print(filetouse)

    try:
        # Check wether the file exist in the cache
        f = open(filetouse[1:], "r")
        outputdata = f.read()
        fileExist = "true"

        # ProxyServer finds a cache hit and generates a response message
        # Fill in start.
        tcpCliSock.send(outputdata.encode())
        # Fill in end.

        print('Read from cache')

    # Error handling for file not found in cache
    except IOError:
        if fileExist == "false":
            # Create a socket on the proxyserver
            c = socket(AF_INET, SOCK_STREAM) # Fill in start. # Fill in end.
            hostn = url[1:].partition("/")[0]
            print(hostn)

            try:
                # Connect to the socket to port 80
                # Fill in start.
                c.connect((hostn, 80))
                # Fill in end.

                # Create a temporary file on this socket and ask port 80 for the file requested by the client
                fileurl = url[1:].partition('/')[1] + url[1:].partition('/')[2]
                request = 'GET ' + fileurl + ' HTTP/1.0\r\nHost: '+ hostn +'\r\n\r\n'
                c.send(request.encode())

                # Read the response into buffer
                # Fill in start.
                outputdata = c.recv(4096)
                c.close()
                # Fill in end.

                # Create a new file in the cache for the requested file.
                # Also send the response in the buffer to client socket and the corresponding file in the cache
                tmpFile = open("./" + filename,"w")

                # Fill in start.
                tcpCliSock.send(outputdata)
                tmpFile.write(outputdata.decode())
                tmpFile.close()
                # Fill in end.

            except:
                tcpCliSock.send("HTTP/1.0 400 Bad Request\r\n".encode())
                print("Illegal request")

        else:
            # HTTP response message for file not found
            # Fill in start.
            tcpCliSock.send("HTTP/1.0 404 Not Found\r\n".encode())
            # Fill in end.

    # Close the client and the server sockets
    tcpCliSock.close()

# Fill in start.
tcpSerSock.close()
# Fill in end.
