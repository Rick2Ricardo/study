import socket
import os

# 定义服务器监听端口号和最大连接请求数
SERVPORT = 3333
BACKLOG = 10
BUFFERSIZE = 1024

def main():
    # 创建TCP套接字
    try:
        sockfd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    except socket.error as e:
        print(f"socket 创建出错！: {e}")
        return

    # 配置本地地址信息
    my_addr = ('', SERVPORT)
    
    # 绑定地址
    try:
        sockfd.bind(my_addr)
    except socket.error as e:
        print(f"bind 出错！: {e}")
        sockfd.close()
        return

    # 监听
    try:
        sockfd.listen(BACKLOG)
    except socket.error as e:
        print(f"listen 出错！: {e}")
        sockfd.close()
        return

    print(f"服务器正在监听端口 {SERVPORT}...")

    while True:
        # 接受客户端连接
        try:
            client_fd, remote_addr = sockfd.accept()
        except socket.error as e:
            print(f"accept 出错！: {e}")
            continue
        
        print(f"接收到来自 {remote_addr[0]} 的连接")

        pid = os.fork()
        if pid == 0:  # 子进程
            try:
                # 发送消息给客户端
                client_fd.send(b"Hello, you are connected!\n")
            except socket.error as e:
                print(f"send 出错！: {e}")
            finally:
                client_fd.close()
                os._exit(0)  # 子进程结束
        else:
            # 父进程关闭客户端连接
            client_fd.close()

if __name__ == "__main__":
    main()
