#----数据协议相关配置----
REQUEST_LOGIN='0001'  #登录请求
REQUEST_CHAT='0002'  #聊天请求
RESPONSE_LOGIN_RESULT='1001' #登录结果响应
RESPONSE_CHAT='1002' #聊天结果响应
DELIMITER='|' #自定义协议数据分隔符
#我们在config.py中定义了数据协议的相关配置，包括请求和响应的标识符、分隔符等。这些配置将用于我们的客户端和服务器之间的通信。

#----服务器相关配置----
SERVER_IP='127.0.0.1' #服务器IP地址
SERVER_PORT=8090 #服务器端口号