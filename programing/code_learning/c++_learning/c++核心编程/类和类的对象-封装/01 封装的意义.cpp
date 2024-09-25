#include<iostream>
using namespace std;

const double PI = 3.14;
//设计一个圆类，求圆的周长
//圆求周长的公式： 2 * PI * 半径

//class 代表设计一个类，类后面紧跟着的就是类名称
class Circle
{
	//访问权限
	//公共权限
public:

	//属性,用变量
	int m_r;

	//行为 用函数
	//获取圆的周长
	double calculateZC()
	{
		return 2 * PI * m_r;
	}
	int  readit()
	{
		return m_p;
	}
private:
	int m_p = 10;
};


class myStu
{
public:
	string name;
	string Num;

	void AddInfo(string name,string Num)
	{
		this->name = name;
		this->Num = Num;
	}
	
	void ShowInfo()
	{
		cout << "学生的姓名是：" << this->name << endl;
		cout << "学生的学号是：" << this->Num << endl;
	}
};
int main() {

	////通过圆类，创建具体的圆（对象）
	////实例化 （通过一个类 创建一个对象的过程）
	Circle c1;
	Circle c2;
	////给圆对象 的属性进行赋值
	c1.m_r = 10;
	c2.m_r = 30;
	cout << "该圆的周长为：" << c1.calculateZC() << endl;
	cout << c2.m_r << endl;
	int m_p = c1.readit();
	//cout << "圆的周长为： " << c1.calculateZC() << endl;
	/*myStu st1;
	string Name;
	string Num;
	cout << "请输入你的学生姓名：" << endl;
	cin >> Name;
	cout << "请输入你的学生学号：" << endl;
	cin >> Num;

	st1.AddInfo(Name, Num);
	st1.ShowInfo();*/
	system("pause");

	return 0;
}