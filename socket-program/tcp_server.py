import socket
import threading

# 预定义合法用户名和密码
valid_users = {
    "ssy": "50351552",
    "user2": "password2"
}

def handle_client(client_socket, addr):
    print(f"客户端 {addr} 已连接")
    
    try:
        # 接收用户名和密码
        client_socket.send("请输入用户名: ".encode('utf-8'))
        username = client_socket.recv(1024).decode('utf-8').strip()
        client_socket.send("请输入密码: ".encode('utf-8'))
        password = client_socket.recv(1024).decode('utf-8').strip()

        # 验证用户
        if valid_users.get(username) == password:
            client_socket.send("登录成功! 请输入文本或文件路径: ".encode('utf-8'))
            print(f"{username} 登录成功")

            # 接收文本或文件内容
            data = client_socket.recv(4096).decode('utf-8').strip()

            # Echo 回显数据
            client_socket.send(f"服务器回显: {data}".encode('utf-8'))
        else:
            client_socket.send("登录失败!".encode('utf-8'))
            print(f"{username} 登录失败")
    
    finally:
        print(f"客户端 {addr} 连接已关闭")
        client_socket.close()

def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('0.0.0.0', 9999))
    server_socket.listen(5)
    print("TCP 服务器正在运行，等待连接...")

    try:
        while True:
            client_socket, addr = server_socket.accept()
            client_handler = threading.Thread(target=handle_client, args=(client_socket, addr))
            client_handler.start()
    except KeyboardInterrupt:
        print("服务器已关闭")
        server_socket.close()

if __name__ == "__main__":
    start_server()
