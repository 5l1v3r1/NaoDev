# -*- coding: UTF-8 -*-
import socket
import sys
import subprocess

NAO_IP = "<Insert_Nao_IP>"

server_address = (NAO_IP, 10001)
ps1 = '[NAO@%s:%s] ' % server_address

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

print >>sys.stderr, 'Starting server @ %s on port %s \n' % server_address
sock.bind(server_address)

sock.listen(1)

while True:
    print >>sys.stderr, ps1, 'Waiting for connection...\n'
    connection, client_address = sock.accept()

    try:
        print >>sys.stderr, ps1, 'Connected to', client_address

        while True:
            data = connection.recv(1024)
            print >>sys.stderr, client_address, '"%s"\n' % data

            if data:
                print >>sys.stderr, ps1, 'Speak Request from ', client_address
                subprocess.call(["qicli", "call", "ALTextToSpeech.say", "[\"%s\"]" % data ])
                
            else:
                print >>sys.stderr, ps1, 'Connection Terminated with:', client_address, "\n"
                break

    finally:
        connection.close()