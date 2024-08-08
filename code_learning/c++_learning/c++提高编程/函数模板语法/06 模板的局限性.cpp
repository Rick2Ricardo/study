#include<iostream>
using namespace std;

//模板局限性
//模板并不是万能的，有些特定数据类型，需要用具体化方式做特殊实现

//对比两个数据是否相等函数
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test01()
{
	int a = 10;
	int b = 20;

	bool ret = myCompare(a, b);

	if (ret)
	{
		cout << "a == b" << endl;
	}
	else
	{
		cout << "a != b" << endl;
	}
}

int main() {

	test01();

	system("pause");

	return 0;
}