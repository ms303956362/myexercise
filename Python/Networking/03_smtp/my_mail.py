from base64 import b64encode
from socket import *
import ssl

AUTHCODE = '123'
NAME = '123'
SENDER = '123@163.com'
RECVER = '123@163.com'

class SMTPControler:
    def __init__(self, socket) -> None:
        self.clientSocket = socket

    def request(self, command, succCode='250'):
        if command is not None:
            self.clientSocket.send(command.encode())
            print('C:', command)
        if succCode is not None:
            recv = self.clientSocket.recv(1024).decode()
            print('S:', recv)
            if recv[:3] != succCode:
                print('S:', succCode, 'reply not received from server.')

if __name__ == "__main__":
    msg = '<h1>Big Ocean Horse</h1><img src="http://redbust.com/stuff/katie-banks-in-the-doorway/katie-banks-boobs-white-shirt-doorway-naked-tits-01.jpg">\r\n'
    endmsg = "\r\n.\r\n"
    # Choose a mail server (e.g. Google mail server) and call it mailserver
    mailserver = ('smtp.163.com', 465)
    
    # Create socket called clientSocket and establish a TCP connection with mailserver
    #Fill in start
    context = ssl.create_default_context()
    with socket(AF_INET, SOCK_STREAM) as sock:
        with context.wrap_socket(sock, server_hostname='smtp.163.com') as clientSocket:
            clientSocket.connect(mailserver)
            smtp = SMTPControler(clientSocket)
            smtp.request(None, '220')
            #Fill in end

            # Send HELO command and print server response.
            smtp.request('HELO 163.com\r\n')

            # Send AUTH command and print server response and login.
            smtp.request('AUTH login\r\n', '334')
            username = b64encode(SENDER.encode()).decode()
            username += '\r\n'
            smtp.request(username, '334')
            authcode = b64encode(AUTHCODE.encode()).decode()
            authcode += '\r\n'
            smtp.request(authcode, '235')

            # Send MAIL FROM command and print server response.
            # Fill in start
            smtp.request('MAIL FROM <{}>\r\n'.format(SENDER))
            # Fill in end

            # Send RCPT TO command and print server response.
            # Fill in start
            smtp.request('RCPT TO <{}>\r\n'.format(RECVER))
            # Fill in end

            # Send DATA command and print server response.
            # Fill in start
            smtp.request('DATA\r\n', '354')
            # Fill in end

            # Send message data.
            # Fill in start
            header = ('From: {0}<{1}>\r\n' + \
                    'To: <{2}>\r\n' + \
                    'Subject: Hello\r\n' + \
                    'Content-Type: text/html\r\n\r\n').format(NAME, SENDER, RECVER)
            smtp.request(header + msg, None)
            # Fill in end

            # Message ends with a single period.
            # Fill in start
            smtp.request(endmsg)
            # Fill in end

            # Send QUIT command and get server response.
            # Fill in start
            smtp.request('QUIT\r\n', '221')
            # Fill in end
