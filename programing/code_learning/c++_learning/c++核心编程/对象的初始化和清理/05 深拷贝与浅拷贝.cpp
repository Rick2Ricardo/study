//#include<iostream>
//using namespace std;
//
////�����ǳ����
////ǳ������ϵͳ�����ǵĸ�ֵ����
////��������������ڶ�������һ���ڴ�
////����������ڴ棬�������������ͷ�
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person��Ĭ�Ϲ��캯������" << endl;
//	}
//
//	Person(int age , int height)
//	{
//		m_Age = age;
//		cout << "Person���вι��캯������" << endl;
//		m_Height=new int(height);			//�ڶ�����������
//	}
//
//	//�Լ�ʵ�ֿ������������ǳ��������������
//	Person(const Person& p)
//	{
//		cout << "Person �������캯������" << endl;
//		m_Age = p.m_Age;
//		//m_Height = p.m_Height;������Ĭ��ʵ�־������д���
//		//�������
//
//		m_Height = new int(*p.m_Height);
//
//	}
//	~Person()
//	{
//		//�������ڶ������ٵ��������ͷŲ���
//		if (m_Height != NULL)
//		{
//			delete m_Height;
//			m_Height = NULL;
//		}
//		cout << "Person��������������" << endl;
//	}
//	int m_Age;		//����
//	int* m_Height;	//���
//	//ǳ�����Ὣ�����ĵ�ֱַ�Ӵ����µ���
//	//�ڽ�������������ʱ����ظ��ͷ�
//};
//
//void test01()
//{
//	Person p1(18,160);
//
//	cout << "p1������Ϊ��" << p1.m_Age << "���Ϊ�� " << *p1.m_Height << endl;
//
//	Person p2(p1);
//	//������ñ������ṩ�Ŀ������캯��������ǳ��������
//
//	cout << "p2������Ϊ��" << p2.m_Age << "���Ϊ�� " << *p2.m_Height << endl;
//
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//}