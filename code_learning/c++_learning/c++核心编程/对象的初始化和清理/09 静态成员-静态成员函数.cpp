//#include<iostream>
//using namespace std;
//
////��̬��Ա����
////���ж�����ͬһ������
////��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
//
//class person
//{
//public:
//	static void func()
//	{
//		m_a = 100;//��̬��Ա�������Է��� ��̬��Ա����
//		//m_b = 200;//��̬��Ա���� �����Է��� �Ǿ�̬��Ա�������޷����ֵ������ĸ������m_b����
//		cout << "static void func ����" << endl;
//	}
//
//	static int m_a;//��̬��Ա����
//	int m_b;//�Ǿ�̬��Ա����
//
//	//��̬��Ա���� Ҳ���з���Ȩ�޵�
//private:
//	static void func2()
//	{
//		cout << "static void func2 ����" << endl;
//	}
//};
//
//int person::m_a = 0;
//
////�����ֵķ��ʷ�ʽ
//void test01()
//{
//	//1��ͨ���������
//	person p;
//	p.func();
//	//2��ͨ����������
//	person::func();
//
//	//person::func2();������ʲ���˽�о�̬��Ա����
//}
//int main()
//{
//	test01();
//	system("pause");
//
//	return 0;
//}