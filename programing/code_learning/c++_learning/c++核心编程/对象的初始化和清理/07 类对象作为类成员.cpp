#include<iostream>
#include<string.h>
using namespace std;

//类对象作为类成员

//手机类
class Phone
{
public:

	Phone(string pName)
	{
		cout << "phone的构造函数调用" << endl;
		m_PName = pName;
	}
	~Phone()
	{
		cout << "Phone的析构函数调用" << endl;
	}
	//手机品牌名称
	string m_PName;
};

//人类
class Person
{
public:
	//Phone m_Phone = pName  隐式转化法
	Person(string name, string pName) :m_Name(name), m_Phone(pName)
	{
		cout << "Person的构造函数调用" << endl;
	}
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
	//姓名
	string m_Name;
	//手机
	Phone m_Phone;
};


void test01()
{
	//当其他类对象作为本类成员
	//构造时候先构造类对象，再构造自身
	//析构的顺序与构造的时候相反
	Person p("张三", "苹果MAX");

	cout << p.m_Name << "拿着： " << p.m_Phone.m_PName << endl;
}
int main()
{
	test01();
	system("pause");

	return 0;
}