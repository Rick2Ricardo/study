#include<iostream>
#include<string.h>
using namespace std;

//�������Ϊ���Ա

//�ֻ���
class Phone
{
public:

	Phone(string pName)
	{
		cout << "phone�Ĺ��캯������" << endl;
		m_PName = pName;
	}
	~Phone()
	{
		cout << "Phone��������������" << endl;
	}
	//�ֻ�Ʒ������
	string m_PName;
};

//����
class Person
{
public:
	//Phone m_Phone = pName  ��ʽת����
	Person(string name, string pName) :m_Name(name), m_Phone(pName)
	{
		cout << "Person�Ĺ��캯������" << endl;
	}
	~Person()
	{
		cout << "Person��������������" << endl;
	}
	//����
	string m_Name;
	//�ֻ�
	Phone m_Phone;
};


void test01()
{
	//�������������Ϊ�����Ա
	//����ʱ���ȹ���������ٹ�������
	//������˳���빹���ʱ���෴
	Person p("����", "ƻ��MAX");

	cout << p.m_Name << "���ţ� " << p.m_Phone.m_PName << endl;
}
int main()
{
	test01();
	system("pause");

	return 0;
}