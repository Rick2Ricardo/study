//#include<iostream>
//using namespace std;
//
////空指针调用成员函数
//
//class Person
//{
//public:
//
//	void showClassName()
//	{
//		cout << "this is Person class" << endl;
//	}
//
//	void showPersonAge()
//	{
//		//默认m_Age=this->m_Age 这里this是一个空指针
//		//报错的原因是因为传入的指针是为NULL
//		if (this == NULL)//防止空指针 防止代码出错
//		{
//			return;
//		}
//
//		cout << "age = " << m_Age << endl;
//
//	}
//
//	int m_Age;
//};
//
//void test01()
//{
//	Person* p = NULL;
//
//	//p->showClassName();
//
//	p->showPersonAge();
//}
//
//int main() {
//
//	test01();
//	system("pause");
//
//	return 0;
//}