# C++提高编程

- 本阶段主要针对C++==泛型编程==和==STL==技术做详细讲解，探讨C++更深层次的使用



## 1 模板

### 1.1 模板的概念



模板就是建立**通用的模具**，大大**提高复用性**



例如生活中的模板



比如一寸照片模板、PPT模板



模板的特点：

- 模板不可以直接使用，它只是一个框架
- 模板的通用并不是万能的



### 1.2 函数模板



- C++中另一种编程思想称为==泛型编程==，主要利用的技术就是模板
- C++提供的两种模板机制：**函数模板**和**类模板**

#### 1.2.1 函数模板语法

函数模板作用：

建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型来代表



**语法：**

```c++
template<typename T>
函数声明或定义
```

**解释：**

template --- 声明创建模板

typename --- 表面其后面的符号是一种数据类型，可以用class代替

T --- 通用的数据类型，名称可以替换，通常为大写字母



**示例：**

```c++
#include<iostream>
using namespace std;


//函数模板

//交换两个整型的函数
void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//交换两个浮点型地函数
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//函数模板
template<typename T>//声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型

void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;

	//swapInt(a, b);
	//利用函数模板交换
	//两种方式使用函数模板
	//1、自动类型推导
	//mySwap(a, b);
	//2、显示指定类型
	mySwap<int>(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	//double c = 1.1;
	//double d = 2.2;

	//swapDouble(c, d);
	//cout << "c = " << c << endl;
	//cout << "d = " << d << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

**总结：**

- 函数模板利用关键字template
- 使用函数模板有两种方式：自动类型推导、显示指定类型
- 模板的目的是为了提高复用性，将类型参数化



#### 1.2.2 函数模板注意事项

注意事项：

- 自动类型推导，必须推导出一致的数据类型T，才可以使用
- 模板必须要确定出T的数据类型，才可以使用

**示例：**

```c++
#include<iostream>
using namespace std;

template<class T>//typename可以替换成class
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
//函数模板注意事项
//1、自动类型推导，必须推导出一致的数据类型T才可以使用
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';

	mySwap(a, b);//正确
	//mySwap(a, c);//错误；推导不出一致的类型T
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

//2、模板必须要确定出T的数据类型，才可以使用
template<class T>
void func()
{
	cout << "func调用" << endl;
}

void test02()
{
	func<int>();
}
int main() {

	//test01();
	test02();

	system("pause");

	return 0;
}
```

总结：

- 使用函数模板时必须确定出通用数据类型T，并且能够推导出一致的类型

#### 1.2.3 函数模板案例

案例描述：

- 利用函数模板封装一个排序的函数，可以对**不同数据类**型进行排序
- 排序规则从大到小，排序算法为选择排序
- 分别利用char数组和int数组进行测试

```c++
#include<iostream>
using namespace std;

//实现通用 对数组进行排序的函数
//规则 从大到小
//算法 选择
//测试 char 数组、int 数组

//交换函数模板
template<class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//排序算法
template<class T>
void mySort(T arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;//认定最大值的下标
		for (int j = i + 1; j < len; j++)
		{
			//认定的最大值比遍历出的数值要小，说明j下标元素才是真正的最大值
			if (arr[max] < arr[j])
			{
				max = j;//更新最大值
			}
		}
		if (max != i)
		{
			//交换max和i元素
			mySwap(arr[max], arr[i]);
		}
	}
}

//提供一个打印数组模板
template<class T>
void printArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}	
	cout << endl;

}

void test02()
{
	//测试int 数组
	int intArr[] = { 7,5,1,3,9,2,4,6,8 };

	int num = sizeof(intArr) / sizeof(int);

	mySort(intArr, num);

	printArray(intArr, num);

}

void test01()
{
	//测试char数组
	char charArr[] = "badcfe";
	int num = sizeof(charArr) / sizeof(char);
	mySort(charArr, num);
	printArray(charArr, num);
}


int main() {
	test01();
	test02();
	system("pause");

	return 0;

}
```



#### 1.2.4 普通函数与函数模板的区别



**普通函数与函数模板区别：**

- 普通函数调用时可以主动发生类型转换
- 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
- 如果利用指定类型函数的方式，可以发生隐式类型转换

**示例：**

```c++
#include<iostream>
using namespace std;

//普通函数与函数模板的区别

//1、普通函数调用可以发生隐式类型转换
//2、函数模板 用自动类型推导，不可以发生隐式类型转换
//3、函数模板 用显示指定类型，可以发生隐式类型转换

//普通函数
int myAdd01(int a, int b)
{
	return a + b;
}

//函数模板
template<class T>
T myAdd02(T a, T b)
{
	return a + b;
}

void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';//a - 97  c - 99
	cout << myAdd01(a, c) << endl;

	//自动类型推导
	//cout << myAdd02(a, b) << endl;

	//显示指定类型
	cout << myAdd02<int>(a, c) << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}c
```

#### 1.2.5 普通函数与函数模板的调用规则

调用规则如下：

1. 如果函数模板和普通函数都可以实现，优先调用普通函数
2. 可以通过空模板参数列表来强调函数模板
3. 函数模板也可以发生重载
4. 如果函数模板可以产生更好的匹配，优先调用函数模板

**示例：**

```c++
#include<iostream>
using namespace std;

//普通函数与函数模板调用规则
//1、如果函数模板和普通函数都可以调用，优先调用普通函数
//2、可以通过空模板参数列表 强制调用 函数模板
//3、函数模板可以发生函数重载
//4、如果函数模板可以产生更好的匹配，优先调用函数模板

void myPrint(int a, int b)
{
	cout << "调用普通函数" << endl;
}

template<class T>
void myPrint(T a,T b)
{
	cout << "调用的模板" << endl;
}

template<class T>
void myPrint(T a, T b,T c)
{
	cout << "重载的调用的模板" << endl;
}

void test01()
{
	int a = 10;
	int b = 20;

	//myPrint(a, b);

	//通过空模板参数列表，强制调用函数模板
	//myPrint<>(a, b);

	//myPrint(a, b, 100); 

	//如果函数模板产生更好的匹配，优先调用函数模板
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

总结：既然写了模板，就不要写普通函数

#### 1.2.6 模板的局限性

**局限性：**

- 模板的通用性并不是万能的



例如：



## 2 STL初识

### 2.1 STL的诞生



+  长久以来，软件界一直希望建立一种可重复利用的东西
+ C++的**面向对象**和**泛型编程**思想，目的就是**复用性的提升**
+ 大多情况下，数据结构和算法都未能有一套标准，导致被批从事大量重复工作
+ 为了建立数据结构和算法的一套标准，诞生了**STL**



### 2.2 STL基本概念



+ STL（Standard Template Library,标准模板库）
+ STL从广义上分为：容器（container）算法（algorithm）迭代器（iterator）
+ 容器和算法之间通过迭代器进行无缝连接
+ STL几乎所有的代码都采用了类模板或者模板函数



### 2.3 STL六大组件

STL大体分为六大组件，分别是：容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器



1. 容器：各种数据结构，如vector、list、deque、set、map等，用来存放数据
2. 算法：各种常用算法，如sort、find、copy、for_each等
3. 迭代器：扮演了容器与算法之间的胶合剂
4. 仿函数：行为类似函数，可作为算法的某种策略
5. 适配器：一种用来修饰容器或者仿函数或迭代器接口的东西
6. 空间配置器：负责空间的配置与管理



### 2.4 STL中容器、算法、迭代器



**容器：**置物之所也

STL**容器**就是将运用最**广泛的的一些数据结构**实现出来

常用的数据结构：数组、链表、树、栈、队列、集合、映射表等

这些容器分为**序列式容器**和**关联式容器**两种：

​	**序列式容器**：强调值的顺序，序列式容器中的每个元素均有固定的位置

​	**关联式容器**：二叉树结构，各元素之间没有严格的物理上的顺序关系



**算法：**问题之解法也

有限的步骤，解决逻辑或数学上的问题，这一门学科我们叫做算法（Algorithms）

算法分为：**质变算法**和**非质变算法**

​	**质变算法：**是指运算过程中会更改区间内的元素内容。如拷贝，替换，删除等等

​	**非质变算法：**是指运算过程中不会更改区间内的元素内容，如查找、计数、遍历、寻找极值等等



**迭代器：**容器和算法之间的粘合剂

提供一种方法，使之能够依序寻访某个容器所含的各个元素，而又无需暴露该容器的内部表示方式。

每个容器都有自己专属的迭代器

迭代器使用非常类似于指针，初学阶段我们可以先理解迭代器为指针



迭代器种类：

| 种类           | 功能                                                     | 支持运算                                |
| -------------- | -------------------------------------------------------- | --------------------------------------- |
| 输入迭代器     | 对数据的只读访问                                         | 只读，支持++、==、！=                   |
| 输出迭代器     | 对数据的只写访问                                         | 只写，支持++                            |
| 前向迭代器     | 读写操作，并能向前推进迭代器                             | 读写，支持++、==、！=                   |
| 双向迭代器     | 读写操作，并能向前和向后操作                             | 读写，支持++、--                        |
| 随机访问迭代器 | 读写操作，可以以跳跃的方式访问任意数据，功能最强的迭代器 | 读写，支持++、--、[n]、-n、<、<=、>、>= |

常用的容器中迭代器种类为**双向迭代器**和**随机访问迭代器**。

### 2.5容器算法迭代初识



了解STL中容器、算法、迭代器的概念后，我们利用代码感受STL的魅力

STL中最常用的容器为vector，可以理解为数组，下面我们将学习如何向这个容器中插入数据、并遍历这个容器



#### 2.5.1 vector存放内置数据类型



容器：vector

算法：for_each

迭代器：vector\<int\>::iterator

示例1：

```c++
#include<iostream>
#include<vector>
#include<algorithm>//标准算法头文件
using namespace std;

//vector容器存放内置数据类型
void myPrint(int val)
{
	cout << val << endl;
}

void test01()
{
	//创建了一个vector容器，数组
	vector<int> v;

	//向数据容器中插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//通过迭代器访问容器中的数据
	//vector<int>::iterator itBegin = v.begin();//起始迭代器 指向容器的第一个元素
	//vector<int>::iterator itEnd = v.end();//结束迭代器 指向容器中最后一个元素的下一个位置

	////第一种遍历方式
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	////第二种遍历方式
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << endl;
	//}

	//第三种遍历方式 利用STL提供遍历算法
	for_each(v.begin(), v.end(), myPrint);

}

int main() {

	test01();

	system("pause");

	return 0;
}
```



#### 2.5.2 Vector