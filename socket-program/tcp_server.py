import socket
import threading

# 示例用户名和密码字典
user_credentials = {
    "root": "50351552",
    "ssy": "50351552"
}

def handle_client(client_socket):
    try:
        # 处理用户名和密码
        username = client_socket.recv(1024).decode('utf-8')
        password = client_socket.recv(1024).decode('utf-8')

        # 验证用户名和密码
        if username in user_credentials and user_credentials[username] == password:
            client_socket.send("登录成功".encode('utf-8'))
            
            # 接收并处理数据
            data = client_socket.recv(4096).decode('utf-8')
            response = f"收到的数据：{data}"
            client_socket.send(response.encode('utf-8'))
        else:
            client_socket.send("登录失败".encode('utf-8'))
    finally:
        client_socket.close()

def tcp_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('127.0.0.1', 9999))
    server_socket.listen(5)
    print("Server listening on port 9999")

    while True:
        client_socket, addr = server_socket.accept()
        print(f"Accepted connection from {addr}")
        client_thread = threading.Thread(target=handle_client, args=(client_socket,))
        client_thread.start()

if __name__ == "__main__":
    tcp_server()
