import time
from socket import *

serverHost = '127.0.0.1'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_DGRAM)
clientSocket.settimeout(1)

min_rtt = 1000
max_rtt = 0
avg_rtt = 0
total = 10
cnt_loss = 0

for i in range(1, total + 1):
    sendMsg = 'Ping ' + str(i) + ' ' + str(time.time())
    clientSocket.sendto(sendMsg.encode(), (serverHost, serverPort))
    try:
        recvMsg, _ = clientSocket.recvfrom(1024)
        t_recv = time.time()
        t_send = float(recvMsg.decode().split()[-1])
        rtt = (t_recv - t_send) * 1000
        max_rtt = max(max_rtt, rtt)
        min_rtt = min(min_rtt, rtt)
        avg_rtt += rtt
        print('Data Packet', i, 'RTT:', rtt, 'ms')
    except :
        cnt_loss += 1
        print('Data Packet', i, 'Request timed out')

clientSocket.close()
print('Max RTT:', max_rtt, 'ms Min RTT:', min_rtt, 'ms Average RTT:', avg_rtt / (total - cnt_loss), 'ms')
print('Packet loss rate:', cnt_loss / total * 100, '%')
