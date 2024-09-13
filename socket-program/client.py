import socket
import sys

# 定义服务器端口和每次最大数据传输量
SERVPORT = 3333
MAXDATASIZE = 100

def main():
    if len(sys.argv) < 2:
        print("Please enter the server's hostname!")
        sys.exit(1)

    server_hostname = sys.argv[1]

    try:
        # 获取主机IP地址
        host = socket.gethostbyname(server_hostname)
    except socket.gaierror:
        print("gethostbyname 出错！")
        sys.exit(1)

    try:
        # 创建TCP套接字
        sockfd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    except socket.error as e:
        print(f"socket 创建出错！: {e}")
        sys.exit(1)

    # 配置服务器地址
    serv_addr = (host, SERVPORT)

    try:
        # 连接服务器
        sockfd.connect(serv_addr)
    except socket.error as e:
        print(f"connect 出错！: {e}")
        sys.exit(1)

    try:
        # 接收数据
        data = sockfd.recv(MAXDATASIZE)
        if not data:
            print("Connection closed by the server.")
            sys.exit(1)
        print(f"Received: {data.decode('utf-8')}")
    except socket.error as e:
        print(f"recv 出错！: {e}")
        sys.exit(1)
    finally:
        # 关闭连接
        sockfd.close()

if __name__ == "__main__":
    main()
