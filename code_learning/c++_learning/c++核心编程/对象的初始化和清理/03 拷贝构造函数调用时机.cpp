//#include<iostream>
//using namespace std;
//
//
//
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person默认构造函数调用" << endl;
//	}
//	Person(int age)
//	{
//		cout << "Person有参构造函数调用" << endl;
//		m_Age = age;
//	}
//	Person(const Person& p)
//	{
//		cout << "Person拷贝构造函数调用" << endl;
//		m_Age = p.m_Age;
//	}
//	~Person()
//	{
//		cout << "Person析构函数调用" << endl;
//	}
//	int m_Age;
//};
//
////拷贝构造函数调用时机
//
////1、使用一个已经创建完毕的对象来初始化一个新对象
//void test01()
//{
//	Person p1(20);
//	Person p2(p1);
//
//	cout << "p2的年龄为：" << p2.m_Age << endl;
//}
////2、值传递的方式给函数参数传值
//
//void doWork(Person p)//值传递的本质就是拷贝一个副本出来
//{
//
//}
//void test02()
//{
//	Person p;
//	doWork(p);
//}
//
////3、值方式返回局部变量
////vs2022进行了优化，减少了拷贝构造函数的使用
//
//Person doWork2()
//{
//	Person p1;
//	cout << (int*)&p1 << endl;
//	return p1;
//}
//
//void test03()
//{
//	Person p = doWork2();
//	cout << (int*)&p << endl;
//
//}
//int main() {
//
//	//test01();
//	//test02();
//	test03();
//	system("pause");
//
//	return 0;
//}