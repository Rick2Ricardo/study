import socket

def tcp_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('127.0.0.1', 9999))

    try:
        # 接收服务器请求输入用户名和密码
        username_prompt = client_socket.recv(1024).decode('utf-8')
        username = input(username_prompt)
        client_socket.send(username.encode('utf-8'))

        password_prompt = client_socket.recv(1024).decode('utf-8')
        password = input(password_prompt)
        client_socket.send(password.encode('utf-8'))

        # 接收登录结果
        result = client_socket.recv(1024).decode('utf-8')
        print(result)

        if "成功" in result:
            # 发送文本或文件内容
            text_input = input("请输入要发送的文本或文件路径: ")
            client_socket.send(text_input.encode('utf-8'))

            # 接收回显结果
            response = client_socket.recv(4096).decode('utf-8')
            print(response)

    finally:
        client_socket.close()

if __name__ == "__main__":
    tcp_client()
