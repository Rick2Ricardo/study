//#include<iostream>
//using namespace std;
//
//int *func()
//{
//	//利用new关键字 可以将数据开辟到堆区
//	//指针 本质也是局部变量，放在栈上，执政保存的数据是放在堆区
//	int * p = new int(10);
//	return p;
//}
//
//int main() {
//	//在堆区开辟数据
//	int* p = func();
//	//相当于func将p 即 new int在堆区上的地址，传给了main函数中的p
//	cout << *p << endl;
//	cout << *p << endl;
//	//cout << *p << endl;
//	cout << *p << endl;
//
//	system("pause");
//
//	return 0;
//}