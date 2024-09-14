from server.config import *

class ResponseProtocol(object):
  """服务器响协议的格式字符串处理"""

  @staticmethod
  def response_login_result(result,nickname,username):
    """
    拼接等陆响应，数据格式为：“响应协议编号|登陆结果|登陆用户昵称|登陆用户名
    生成用户登陆的结果字符串
    ：param result:值为0表示登陆失败，值为1表示登陆成功
    ：param nickname:登陆用户的昵称。如果登陆失败，则该值为空
    ：param username:登陆用户的账号。如果登陆失败，则该值为空
    ：return:供返回给用户的登陆结果协议字符串
    """
    return DELIMITER.join([RESPONSE_LOGIN_RESULT,result,nickname,username])
  
  @staticmethod
  def response_chat(nickname,message):
    """
    拼接聊天响应，数据格式为：“响应协议编号|发送消息的用户昵称|消息正文”
    生成返回给用户的消息字符串
    :param nickname:发送消息的用户昵称
    :param message:消息正文
    :return:返回给用户的消息字符串
    """
    return DELIMITER.join([RESPONSE_CHAT,nickname,message])