//#include<iostream>
//using namespace std;
//
////深拷贝与浅拷贝
////浅拷贝是系统给我们的赋值操作
////深拷贝是我们重新在堆区申请一块内存
////堆区申请的内存，在析构函数中释放
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person的默认构造函数调用" << endl;
//	}
//
//	Person(int age , int height)
//	{
//		m_Age = age;
//		cout << "Person的有参构造函数调用" << endl;
//		m_Height=new int(height);			//在堆区开辟数据
//	}
//
//	//自己实现拷贝函数，解决浅拷贝带来的问题
//	Person(const Person& p)
//	{
//		cout << "Person 拷贝构造函数调用" << endl;
//		m_Age = p.m_Age;
//		//m_Height = p.m_Height;编译器默认实现就是这行代码
//		//深拷贝操作
//
//		m_Height = new int(*p.m_Height);
//
//	}
//	~Person()
//	{
//		//将我们在堆区开辟的数据做释放操作
//		if (m_Height != NULL)
//		{
//			delete m_Height;
//			m_Height = NULL;
//		}
//		cout << "Person的析构函数调用" << endl;
//	}
//	int m_Age;		//年龄
//	int* m_Height;	//身高
//	//浅拷贝会将堆区的地址直接传给新的类
//	//在进行析构函数的时候会重复释放
//};
//
//void test01()
//{
//	Person p1(18,160);
//
//	cout << "p1的年龄为：" << p1.m_Age << "身高为： " << *p1.m_Height << endl;
//
//	Person p2(p1);
//	//如果利用编译器提供的拷贝构造函数，会做浅拷贝操作
//
//	cout << "p2的年龄为：" << p2.m_Age << "身高为： " << *p2.m_Height << endl;
//
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//}