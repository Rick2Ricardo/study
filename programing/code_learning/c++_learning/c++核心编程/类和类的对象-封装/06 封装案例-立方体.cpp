//#include<iostream>
//using namespace std;
//
////����������ư���
////1��������������
////2��������Ժ���Ϊ
////3����ȡ���������������
////4���ֱ�����ȫ�ֺ����ͳ�Ա����  �ж������������Ƿ����
//
//class cube
//{
//
//private:
//	int m_l; //��
//	int m_w; //��
//	int m_h; //��
//
//public:
//
//	//���ó�
//	void setl(int l)
//	{
//		m_l = l;
//	}
//	//��ȡ��
//	int getl()
//	{
//		return m_l;
//	}
//	//���ÿ�
//	void setw(int w)
//	{
//		m_w = w;
//	}
//	//��ȡ��
//	int getw()
//	{
//		return m_w;
//	}
//	//���ø�
//	void seth(int h)
//	{
//		m_h = h;
//	}
//	//��ȡ��
//	int geth()
//	{
//		return m_h;
//	}
//	//��ȡ���������
//	int calculates()
//	{
//		return 2 * m_l * m_w + 2 * m_w * m_h + 2 * m_l * m_h;
//	}
//	//��ȡ���������;
//	int calculatev()
//	{
//		return m_l * m_h * m_h;
//	}
//
//	//���ó�Ա�����ж������������Ƿ����
//	bool issamebyclass(cube &c)
//	{
//		//ֻ��Ҫ����һ��������ȥ�Ϳ���
//		if (m_l == c.getl() && m_h == c.geth() && m_w == c.getw())
//		{
//			return true;
//		}
//		else 
//		{
//			return false;
//		}
//
//		
//	}
//};
//
////����ȫ�ֺ����ж� �����������Ƿ����
//bool issame(cube &c1, cube &c2)
//{
//	if (c1.getl() == c2.getl() && c1.geth() == c2.geth() && c1.getw() == c2.getw())
//	{
//		return true;
//	}
//
//	return false;
//}
//
//int main() {
//
//	//�������������
//	cube c1;
//	c1.setl(10);
//	c1.setw(10);
//	c1.seth(10);
//
//	//600
//	cout << "c1�����Ϊ�� " << c1.calculates() << endl;
//	//1000
//	cout << "c1�����Ϊ�� " << c1.calculatev() << endl;
//
//	//�����ڶ���������
//	cube c2;
//	c2.setl(10);
//	c2.setw(10);
//	c2.seth(10);
//
//	bool ret = issame(c1, c2);
//	if (ret)
//	{
//		cout << "c1��c2����ȵ�" << endl;
//	}
//	else
//	{
//		cout << "c1��c2�ǲ���ȵ�" << endl;
//	}
//
//	//���ó�Ա�����ж�
//	ret = c1.issamebyclass(c2);
//
//	if (ret)
//	{
//		cout << "��Ա�����жϣ�c1��c2����ȵ�" << endl;
//	}
//	else
//	{
//		cout << "��Ա�����жϣ�c1��c2�ǲ���ȵ�" << endl;
//	}	\
//	system("pause");
//
//	return 0;
//}