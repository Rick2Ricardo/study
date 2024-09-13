import socket

with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as s:
    s.bind(("0.0.0.0",1234))
    s.listen()
    c , adder = s.accept()
    with c:
        print(adder,"connected.")

        while True:
            data =c.recv(1024)
            if not data:
                break
            c.sendall()