import time
from socket import *
import random

serverHost = '127.0.0.1'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_DGRAM)

for i in range(1, 11):
    sendMsg = 'Packet ' + str(i) + ' ' + str(time.time())
    try:
        clientSocket.sendto(sendMsg.encode(), (serverHost, serverPort))
        print(sendMsg)
    except:
        print('Server closed')
        break
    time.sleep(random.uniform(0.02, 0.12))
clientSocket.close()
