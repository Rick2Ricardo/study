//#include<iostream>
//using namespace std;
//
////立方体类设计案例
////1、创建立方体类
////2、设计属性和行为
////3、获取立方体的面积和体积
////4、分别利用全局函数和成员函数  判断两个立方体是否相等
//
//class cube
//{
//
//private:
//	int m_l; //长
//	int m_w; //宽
//	int m_h; //高
//
//public:
//
//	//设置长
//	void setl(int l)
//	{
//		m_l = l;
//	}
//	//获取长
//	int getl()
//	{
//		return m_l;
//	}
//	//设置宽
//	void setw(int w)
//	{
//		m_w = w;
//	}
//	//获取宽
//	int getw()
//	{
//		return m_w;
//	}
//	//设置高
//	void seth(int h)
//	{
//		m_h = h;
//	}
//	//获取高
//	int geth()
//	{
//		return m_h;
//	}
//	//获取立方体面积
//	int calculates()
//	{
//		return 2 * m_l * m_w + 2 * m_w * m_h + 2 * m_l * m_h;
//	}
//	//获取立方体体积;
//	int calculatev()
//	{
//		return m_l * m_h * m_h;
//	}
//
//	//利用成员函数判断两个立法体是否相等
//	bool issamebyclass(cube &c)
//	{
//		//只需要传递一个参数进去就可以
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
////利用全局函数判断 两个立方体是否相等
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
//	//创建立方体对象
//	cube c1;
//	c1.setl(10);
//	c1.setw(10);
//	c1.seth(10);
//
//	//600
//	cout << "c1的面积为： " << c1.calculates() << endl;
//	//1000
//	cout << "c1的体积为： " << c1.calculatev() << endl;
//
//	//创建第二个立方体
//	cube c2;
//	c2.setl(10);
//	c2.setw(10);
//	c2.seth(10);
//
//	bool ret = issame(c1, c2);
//	if (ret)
//	{
//		cout << "c1和c2是相等的" << endl;
//	}
//	else
//	{
//		cout << "c1和c2是不相等的" << endl;
//	}
//
//	//利用成员函数判断
//	ret = c1.issamebyclass(c2);
//
//	if (ret)
//	{
//		cout << "成员函数判断：c1和c2是相等的" << endl;
//	}
//	else
//	{
//		cout << "成员函数判断：c1和c2是不相等的" << endl;
//	}	\
//	system("pause");
//
//	return 0;
//}