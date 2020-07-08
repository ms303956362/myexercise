# UDPPingerServer.py
# We will need the following module to generate randomized lost packets import random
import time
from socket import *

# Create a UDP socket
# Notice the use of SOCK_DGRAM for UDP packets
serverSocket = socket(AF_INET, SOCK_DGRAM) # Assign IP address and port number to socket
serverSocket.bind(('', 12000))
serverSocket.settimeout(0.1)

t_send = time.time()
t_start = t_send
print('Ready to receive')

while True:
    try:
        # Receive the client packet along with the address it is coming from
        message, address = serverSocket.recvfrom(1024)
        t_send = float(message.decode().split(' ')[-1])
        print('OK')
    except:
        if t_start == t_send:
            continue
        if time.time() - t_send >= 1:
            print('Application Closed')
            break
        else:
            print('Packet loss')

serverSocket.close()