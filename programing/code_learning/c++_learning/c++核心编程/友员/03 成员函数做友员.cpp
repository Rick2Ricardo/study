#include<iostream>
#include<string>
using namespace std;

class Building;
class GoodGay
{
public:
	GoodGay();

	void visit();//让visit函数可以访问Building中的私有成员
	void visit2();//让visit2函数不可以访问Building中的私有成员

	Building* building;
};

class Building
{
	//告诉编译器 GoodGay类下的visit成员函数作为本类的好朋友有
	friend void GoodGay::visit();
public:
	Building();
public:

	string m_SittingRoom;//客厅

private:
	
	string m_BedRoom;//卧室
};

//类外实现成员函数
Building::Building()//Building的构造函数
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";

}

GoodGay::GoodGay()//GoodGay的构造函数
{
	building = new Building;
}

void GoodGay::visit()//让visit函数可以访问Building中的私有成员
{
	cout << "visit 函数正在访问：" << building->m_SittingRoom << endl;
	cout << "visit 函数正在访问：" << building->m_BedRoom << endl;
}
void GoodGay::visit2()//让visit2函数不可以访问Building中的私有成员
{
	cout << "visit2 函数正在访问：" << building->m_SittingRoom << endl;
	//cout << "visit 函数正在访问：" << building->m_BedRoom << endl;

}

void test01()
{
	GoodGay gg;
	gg.visit();
	gg.visit2();

}


int main()
{

	test01();

	system("pause");

	return 0;
}