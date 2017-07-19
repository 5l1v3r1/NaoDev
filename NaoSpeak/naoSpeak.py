import socket
import sys
import argparse

NAO_IP = '<Insert_Nao_IP>'

parser = argparse.ArgumentParser()
parser.add_argument("-s", type=str, default="You need to type a string if you want me to say it",
                    help="Example: naoclient.py -s hello, naoclient.py -s \"Hello Everyone\" ")
args = parser.parse_args()

server_address = (NAO_IP, 10001)

sock = socket.create_connection(server_address)

try:
    message = args.s
    print >>sys.stderr, 'Sending: "%s"' % message 
    sock.sendall(message)

finally:
    print >>sys.stderr, 'Closing Socket'
    sock.close()
