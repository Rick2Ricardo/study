import socket
import tkinter as tk
from tkinter import messagebox

def send_message():
    username = username_entry.get().strip()
    password = password_entry.get().strip()
    message = message_entry.get().strip()

    if not username or not password or not message:
        messagebox.showwarning("Input Error", "Username, password, and message cannot be empty.")
        return

    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        client_socket.connect(('127.0.0.1', 9999))
        print("Connected to server")

        # 发送用户名和密码
        client_socket.sendall(username.encode('utf-8'))
        client_socket.sendall(password.encode('utf-8'))

        # 接收登录结果
        result = client_socket.recv(1024).decode('utf-8')
        print(f"Received login result: {result}")
        if "登录成功" in result:
            # 发送消息内容
            client_socket.sendall(message.encode('utf-8'))

            # 接收回显结果
            response = client_socket.recv(4096).decode('utf-8')
            messagebox.showinfo("Server Response", response)
        else:
            messagebox.showwarning("Login Result", result)
    
    except socket.error as e:
        messagebox.showerror("Connection Error", f"Socket error: {e}")
    except Exception as e:
        messagebox.showerror("Error", str(e))
    finally:
        client_socket.close()

# 创建图形化界面
root = tk.Tk()
root.title("TCP Client")

tk.Label(root, text="Username:").pack(pady=5)
username_entry = tk.Entry(root)
username_entry.pack(pady=5)

tk.Label(root, text="Password:").pack(pady=5)
password_entry = tk.Entry(root, show="*")
password_entry.pack(pady=5)

tk.Label(root, text="Message to Send:").pack(pady=5)
message_entry = tk.Entry(root, width=50)
message_entry.pack(pady=5)

tk.Button(root, text="Send Message", command=send_message).pack(pady=10)

root.mainloop()
