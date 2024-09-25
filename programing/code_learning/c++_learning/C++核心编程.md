

## 1 内存分区模型

> C++程序在执行时，将内存大方向划分为4个区域
>
> 1. 代码区：存放函数体的二进制代码，由操作系统进行管理的
> 2. 全局区：存放全局变量和静态变量以及常量
> 3. 栈区：由编译器自动分配释放，存放函数的参数值，局部变量等
> 4. 堆区：由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收

### 内存四区的意义：

> 不同区域存放的数据，赋予不同的生命周期，给我们更大的灵活编程
>



### 1.1 程序执行前

在程序编译后，生成了==exe==可执行程序，未执行该程序前分为两个区域

#### 代码区：

> 存放CPU执行的机械指令
>
> 代码区是共享的，共享的目的是对于频繁被执行的程序，只需要在内存中只有一份代码即可
>
> 代码区是只读的，使其只读的原因是防止程序意外地修改了它的指令
>

#### 全局区：

> 全局变量和静态变量存放在此
>
> 全局区还包含了常量区，字符串常量和其他常量也存放在此
>
> 该区域的数据在程序结束后由操作系统释放
>

**代码：**

```c++
#include<iostream>
using namespace std;

//全局变量
int g_a = 10;
int g_b = 10;

//const修饰的全局变量，全局常量
const int c_g_a = 10;
const int c_g_b = 10;
int main() {

	//全局区

	//全局变量、静态变量、常量区


	//创建一个普通的局部变量
	int a = 10;
	int b = 10;

	cout << "局部变量a的地址为： " << (int)&a << endl;
	cout << "局部变量b的地址为： " << (int)&b << endl;

	cout << "全局变量g_a的地址为： " << (int)&g_a << endl;
	cout << "全局变量g_b的地址为： " << (int)&g_b << endl;

	//静态变量 在普通变量前面加static，属于静态变量
	static int s_a = 10;
	static int s_b = 10;
	cout << "静态变量s_a的地址为： " << (int)&s_a << endl;
	cout << "静态变量s_b的地址为： " << (int)&s_b << endl;

	//常量
	//字符串常量
	cout << "字符串常量的地址为： " << (int)&"hello world" << endl;

	//const修饰的变量
	//const修饰的全局变量 const修饰的局部变量
	cout << "全局常量 c_g_a的地址为： " << (int)&c_g_a << endl;
	cout << "全局常量 c_g_b的地址为： " << (int)&c_g_b << endl;

	const int c_l_a = 10;//c - const   g - global   l - local
	const int c_l_b = 10;

	cout << "局部常量 c_l_a的地址为： " << (int)&c_l_a << endl;
	cout << "局部常量 c_l_b的地址为： " << (int)&c_l_b << endl;
	system("pause");

	return 0;
}
```

> #### 总结
>
> 1. c++在程序运行前分为全局区和代码区
> 2. 代码区特点是共享和只读
> 3. 全局区中存放全局变量和字符串常量
> 4. 常量区中存放==const==修饰的全局常量和字符串常量



### 1.2 程序运行后

#### 栈区：

> 由编译器自动分配释放，存放函数的参数值，局部变量等
>
> **注意事项：**不要放回局部变量的地址，栈区开辟的数据由编译器自动释放

```c++
#include<iostream>
using namespace std;

//栈区数据注意事项   ----  不要返回局部变量地址
//栈区数据由编译器管理开辟和释放


int * func(int b)//形参数据也会放在栈区
{
	b = 100;
	int a = 10;//局部变量  存放在栈区，栈区的数据在执行完后自动释放
	return &a;//返回局部变量的地址
}

int main()
{
	//接受func函数的返回值
	int* p = func(1);

	cout << *p << endl;//第一次可以打印正确的数据是因为编译器做了保留
	cout << *p << endl;//第二次这个数据就不保留了

	system("pause");

	return 0;

}
```

#### 堆区：

> 由程序员分配释放，若程序员不释放，程序结束时由操作系统回收
>
> 在C++中主要利用==new==在堆区开辟内存
>

```c++
#include<iostream>
using namespace std;

int *func()
{
	//利用new关键字 可以将数据开辟到堆区
	//指针 本质也是局部变量，放在栈上，执政保存的数据是放在堆区
	int * p = new int(10);
	return p;
}

int main() {
	//在堆区开辟数据
	int* p = func();
	//相当于func将p 即 new int在堆区上的地址，传给了main函数中的p
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;

	system("pause");

	return 0;
}
```

> #### 总结：
>
> 堆区数据由程序员管理开辟和释放
>
> 堆区数据利用new关键字进行开辟内存
>

### 1.3 new操作符

> C++中利用==new==操作符在堆区开辟数据与
>
> 堆区开辟的数据，由程序员手动开辟，手动释放，利用操作符==delete==
>
> 语法：`new 数据类型`
>
> 利用==new==创建的数据，会返回该数据对应的类型的指针
>

#### 示例一：基本语法

```c++
#include<iostream>
using namespace std;

//1、new的基本语法
int* func()
{
	//在堆区创建整型数据
	//new返回的是 该类型数据的指针
	int* p = new int(10);
	//创建一个数字10
	return p;
}

void test01()
{
	int* p = func();

	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	//堆区的数据由管理员管理开辟，由程序员管理释放
	//如果想释放堆区的数据，利用关键字delete
	delete p;
	//cout << *p << endl;
	//内存已经被释放，在此访问就是非法操作，会报错

}
//2、在堆区利用new开辟数组
void test02()
{
	//创建10整型数据的数组，在堆区
	int* arr = new int[10];
	//10代表数组有10个元素

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;//给十个元素赋值100—109
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	//释放堆区数组
	//释放数组的时候，要加[]才可以
	delete[]arr;
}
int main() {
	//test01();
	test02();

	system("pause");

	return 0;

}
```



## 2 引用

### 2.1 引用的基本使用

**作用：**给变量起别名

**语法：**`数据类型 &别名 = 原名`

**代码：**

```c++
#include<iostream>
using namespace std;

int main() {

	//引用基本语法
	//数据类型 &别名 = 原名

	int a = 10;
	int& b = a;

	cout << "a= " << a << endl;
	cout << "b= " << b << endl;

	b = 100;

	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	system("pause");
	return 0;
}
```



### 2.2 应用的注意事项

> 引用必须初始化
>
> 引用在初始化后，不可以改变

**代码：**

```c++
#include<iostream>
using namespace std;

int main() {

	int a = 10;
	//1、引用必须初始化
	//int& b;//错误，必须要初始化
	int& b = a;

	//2、引用在初始化后，不可改变
	int c = 20;

	b = c;//赋值操作，而不是更改引用

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	system("pause");

	return 0;
}
```



### 2.3 引用做函数参数

> **作用：**函数传参时，可以利用引用的技术让形参修饰实参
>
> **优点：**可以简化指针修改实参



**代码：**

```c++
#include<iostream>
using namespace std;

//交换函数

//1、值传递
void mySwap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	//cout << "swap01 a = " << a << endl;
	//cout << "swap01 b = " << b << endl;
}

//2、地址传递
void mySwap02(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//3、引用传递
void mySwap03(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main() {

	int a = 10;
	int b = 20;
	
	//mySwap01(a, b);//值传递，形参不会修饰实参
	//mySwap02(&a, &b);//地址传递，形参会修饰实参

	mySwap03(a, b);//引用传递，形参会修饰实参
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	

	system("pause");

	return 0;
}
```

> #### 总结：
>
> 通过引用参数产生的效果同按地址传递是一样的，引用的语法更清楚简单。



### 2.4 引用做函数的返回值







## 4 类和对象

> c++面向对象的三大特性为：封装、继承、多态
>
> c++认为万事万物都皆为对象，对像上有其属性和行为
>
> **例如：**
>
> 人可以作为对象，属性有姓名、年龄、身高、体重……，行为有走、跑、跳、吃饭、唱歌……
>
> 车也可以作为对象，属性有轮胎、方向盘、车灯……，行为有载人、放音乐、放空调……
>
> 具有相同性质的对象，我们可以抽象称为类，人属于人类，车属于车类
>



### 4.1 封装

#### 4.1.1 封装的意义

> 封装是C++面向对象三大特征之一
>
> 封装的意义：
>
> - 将属性和行为作为一个整体，来表现生活中的事物
> - 将属性和行为加以权限控制封装意义
>

##### **封装意义一：**

> 在设计类的时候，属性和行为在一起，表现事物
>
> **语法：**`class 类名{   访问权限： 属性  /  行为   }；`



**示例1：**设计一个圆类，求圆周长

**示例代码：**

```c++
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
};

int main() {

	//通过圆类，创建具体的圆（对象）
	//实例化 （通过一个类 创建一个对象的过程）
	Circle c1;
	//给圆对象 的属性进行赋值
	c1.m_r = 10;

	cout << "圆的周长为： " << c1.calculateZC() << endl;
	system("pause");

	return 0;
}
```



**示例2：**设计一个学生类，属性有姓名学号，可以给姓名和学号赋值，可以显示学生的姓名和学号

**我的代码：**

```c++
#include<iostream>
using namespace std;

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
	myStu st1;
	string Name;
	string Num;
	
	cout << "请输入你的学生姓名：" << endl;
	cin >> Name;
	cout << "请输入你的学生学号：" << endl;
	cin >> Num;

	st1.AddInfo(Name, Num);
	st1.ShowInfo();
	
	system("pause");

	return 0;
}
```

**老师的示例代码：**

```c++
#include<iostream>
#include<string.h>
using namespace std;

//设计一个学生类，属性有姓名学号，可以给姓名和学号赋值，可以显示学生的姓名和学号

//设计学生类
class Student
{
public://公共权限

	//类中的属性和行为 我们统一成为 成员
	//属性  成员属性 成员变量
	//行为  成员函数 成员方法


	//属性
	string m_Name;//姓名
	int m_Id;//学号

	//行为
	//显示姓名和学号
	void showStudent()
	{
		cout << "姓名： " << m_Name << " " << "学号： " << m_Id << endl;
	}

	//给姓名赋值
	void setName(string name)
	{
		m_Name = name;
	}

	//给学号赋值
	void setId(int id)
	{
		m_Id = id;
	}
};

int main() {

	//创建一个具体的学生 实例化对象
	Student s1;
	//给s1对象 进行属性赋值操作
	s1.setId(1);
	s1.setName("张三");
	//显示学生信息

	s1.showStudent();

	Student s2;
	s2.m_Name = "李四";
	s2.m_Id = 2;
	s2.showStudent();

	system("pause");

	return 0;
}
```

##### 封装的意义二：

> 类在设计时，可以把属性和行为放在不同权限下，加以控制、
>
> 访问的权限有三种
>
> 1. public 		公共权限
> 2. protected  保护权限
> 3. private        私有权限
>

**示例：**

```c++
#include<iostream>
using namespace std;

//访问权限
//三种
//公共权限 public			成员 类内可以访问 类外可以访问
//保护权限 protected		成员 类内可以访问 类外不可以访问  儿子也可以访问父亲的保护内容
//私有权限 private			成员 类内可以访问 类外不可以访问  儿子不可以访问父亲的私有内容
class Person
{
public:
	//公共权限
	string m_Name;	//姓名

protected:
	//保护权限
	string m_Car;  //汽车

private:
	//私有权限
	int m_Password;//银行卡密码

public:
	void func()
	{
		m_Name = "张三";
		m_Car = "拖拉机";
		m_Password = 123456;
	}
	//类内都可以访问
};

int main() {

	//实例化具体对象
	Person p1;

	p1.m_Name = "李四";
	//p1.m_Car = "奔驰";//保护权限的内容，在类外访问不到
	//p1.m_Password = 123;//私有权限的内容，在类外访问不到

	p1.func();

	system("pause");

	return 0;
}
```

#### 4.1.2 struct和class的区别

> 在C++中 struct和class唯一的**区别**就在于**默认的访问权限不同**
>
> 区别：
>
> - struct 默认权限为公共
> - class   默认权限为私有
>

**示例：**

```c++
#include<iostream>
using namespace std;

class C1
{
	int m_A;//默认权限 是私有
};

struct C2
{
	int m_A;//默认权限 是公共
};

int main() {

	//struct 和 class 区别
	//struct 默认权限是 公共 public
	//class  默认权限是 私有 private
	C1 c1;
	//C1.m_A=100;//在class里默认权限 私有 因此类外不可以访问

	C2 c2;
	c2.m_A = 100;//在struct默认权限  公共 因此可以访问

	system("pause");

	return 0;
}
```

#### 4.1.3 成员属性设为私有

> **优点1：**将所有成员属性设置为私有，可以自己控制读写权限
>
> **优点2：**对于读写权限，我们可以检测数据的有效性

**示例：**

```c++
#include<iostream>
using namespace std;
#include<string>
//成员属性设置为私有
//1、可以自己控制读写
//2、对于写可以检测数据的有效性

//设计人类
class Person
{
public:

	//设置姓名
	void setName(string name)
	{
		m_Name = name;
	}
	//获取姓名
	string getName()
	{
		return m_Name;
	}

	//获取年龄  可读可写 如果想修改（年龄的范围必须是0—150之间）
	int getAge()
	{
		//m_Age = 0;//初始化为0岁
		return m_Age;
	}

	//设置年龄
	void setAge(int age)
	{
		if (age < 0 || age>150)
		{
			m_Age = 0;
			cout << "你这个老妖精！" << endl;
			return;
		}
		m_Age = age;
	}

	//设置情人 只写
	void setLover(string lover)
	{
		m_Lover = lover;
	}
private:
	//姓名   可读可写
	string m_Name;
	//年龄   只读
	int m_Age;
	//情人   只写
	string m_Lover;
};

int main() {

	Person p;
	p.setName("张三") ;

	cout << "姓名为： " << p.getName() << endl;

	//p.m_Age = 18;
	//p.setAge(18);
	p.setAge(1000);
	cout << "年龄为： " << p.getAge() << endl;

	//设置情人为苍井
	p.setLover("苍井");

	//cout << "情人为： " << p.setLover << endl;//是不可以访问的
	
	system("pause");

	return 0;
}
```



**练习案例1：设计立方体**

设计立方体(Cube)

求出立方体的面积和体积

分别用全局函数和成员函数判断两个立方体是否相等。

```c++
#include<iostream>
using namespace std;

//立方体类设计案例
//1、创建立方体类
//2、设计属性和行为
//3、获取立方体的面积和体积
//4、分别利用全局函数和成员函数  判断两个立方体是否相等

class Cube
{

private:
	int m_L; //长
	int m_W; //宽
	int m_H; //高

public:

	//设置长
	void setL(int l)
	{
		m_L = l;
	}
	//获取长
	int getL()
	{
		return m_L;
	}
	//设置宽
	void setW(int w)
	{
		m_W = w;
	}
	//获取宽
	int getW()
	{
		return m_W;
	}
	//设置高
	void setH(int h)
	{
		m_H = h;
	}
	//获取高
	int getH()
	{
		return m_H;
	}
	//获取立方体面积
	int calculateS()
	{
		return 2 * m_L * m_W + 2 * m_W * m_H + 2 * m_L * m_H;
	}
	//获取立方体体积;
	int calculateV()
	{
		return m_L * m_H * m_H;
	}

	//利用成员函数判断两个立法体是否相等
	bool isSameByClass(Cube &c)
	{
		//只需要传递一个参数进去就可以
		if (m_L == c.getL() && m_H == c.getH() && m_W == c.getW())
		{
			return true;
		}
		else 
		{
			return false;
		}

		
	}
};

//利用全局函数判断 两个立方体是否相等
bool isSame(Cube &c1, Cube &c2)
{
	if (c1.getL() == c2.getL() && c1.getH() == c2.getH() && c1.getW() == c2.getW())
	{
		return true;
	}

	return false;
}

int main() {

	//创建立方体对象
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);

	//600
	cout << "c1的面积为： " << c1.calculateS() << endl;
	//1000
	cout << "c1的体积为： " << c1.calculateV() << endl;

	//创建第二个立方体
	Cube c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(10);

	bool ret = isSame(c1, c2);
	if (ret)
	{
		cout << "c1和c2是相等的" << endl;
	}
	else
	{
		cout << "c1和c2是不相等的" << endl;
	}

	//利用成员函数判断
	ret = c1.isSameByClass(c2);

	if (ret)
	{
		cout << "成员函数判断：c1和c2是相等的" << endl;
	}
	else
	{
		cout << "成员函数判断：c1和c2是不相等的" << endl;
	}	\
	system("pause");

	return 0;
}
```



**练习案例2：点和圆的关系**

设计一个圆形类（Circle），和一个点类（Point），计算点和圆的关系。

圆的头文件

```c++
Circle.h
#pragma once
#include<iostream>
using namespace std;
#include"point.h"

class Circle
{
private:
	int m_R;//半径

	//在类中可以让另一个类 作为本类中的成员
	Point m_Center;//圆心
public:
	//设置半径
	void setR(int r);

	//获取半径
	int getR();

	//设置圆心
	void setCenter(Point center);

	//获取圆心
	Point getCenter();

};
```

点的头文件

```c++
point.h
#pragma once
#include<iostream>
using namespace std;

//点类
class Point
{
private:
	int m_X;
	int m_Y;

public:
	//设置x
	void setX(int x);

	//获取x
	int getX();

	//设置y
	void setY(int y);

	//获取y
	int getY();

};
```

圆的源文件

```c++
Circle.cpp
#include"Circle.h"
#include"point.h"

//设置半径
void Circle::setR(int r)
{
	m_R = r;
}
//获取半径
int Circle::getR()
{
	return m_R;
}
//设置圆心
void Circle::setCenter(Point center)
{
	m_Center = center;
}
//获取圆心
Point Circle::getCenter()
{
	return m_Center;
}
```

点的源文件

```c++
point.cpp
#include"point.h"
//设置x
void Point::setX(int x)
{
	m_X = x;
}
//获取x
int Point::getX()
{
	return m_X;
}
//设置y
void Point::setY(int y)
{
	m_Y = y;
}
//获取y
int Point::getY()
{
	return m_Y;
}
```

主函数

```c++
main.cpp
#include<iostream>
using namespace std;
#include"point.h"
#include"Circle.h"

//判断点和圆的关系
void isInCircle(Circle &c,Point &p)
{
	//计算两点之间距离的平方
	int distance = 
	(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + 
	(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	//计算半径的平方
	int rDistance = c.getR() * c.getR();

	//判断关系
	if (distance == rDistance)
	{
		cout << "点在圆上" << endl;
	}
	else if(distance > rDistance)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}

int main() {
	
	//创建圆
	Circle c;
	c.setR(10);
	Point center;
	center.setX(10);
	center.setY(0);
	c.setCenter(center);

	//创建点
	Point p;
	p.setX(10);
	p.setY(10);

	//判断关系

	isInCircle(c, p);

	system("pause");

	return 0;
}
```



### 4.2 对象的初始化和清理

> 生活中我们买的电子产品都基本有出厂设置，在某一天我们不用的时候也会删除一些自己信息数据保证安全
>
> C++中的面向对象来源于生活，每个对象都会有初始设置以及对象销毁前的清理数据设置



#### 4.2.1 构造函数和析构函数

> 对象的**初始化和清理**也是两个非常重要的安全问题
>
> 一个对象或者变量没有初始状态，对其使用的后果是未知的
>
> 同样的使用完一个对象或者变量，没有及时清理，也会造成一定的安全问题
>



> c++利用了**构造函数**和**析构函数**解决上述问题，这两个函数会被编译器自动调用，完成对象初始化和清理工作。
>
> 对象的初始化的清理工作是编译器强制我们要做的事情，因此如果**我们不提供构造和析构，编译器会提供编译器**
>
> **提供的构造函数和析构函数是空实现**



> 构造函数：主要作用在于**创建对象**时为对象的成员属性赋值，构造函数由编译器自动调用，无须手动调用。
> 析构函数：主要作用在于对象**销毁前**系统自动调用，执行一些清理工作。



> **构造函数语法：**`类名(){}`
>
> 1. 构造函数，没有返回值也不写void
> 2. 函数名称与类名相同
> 3. 构造函数可以有参数，因此可以发生重载
> 4. 程序在调用对象时会自动调用构造，无须手动调用，而且只会调用一次



> **析构函数语法：**`~类名(){}`
>
> 1. 析构函数，没有返回值也不写void
> 2. 函数名称与类名相同，在名称前加上符号 ~
> 3. 析构函数不可以有参数，因此不可以发生重载
> 4. 程序在对象销毁前会自动调用析构，无须手动调用，而且只会调用一次

代码：

```c++
#include<iostream>
using namespace std;

//对象的初始化和清理
//1、构造函数 进行初始化操作

//2、析构函数 进行清理的操作

class Person
{
public://1、构造函数
	//没有返回值 不用写void
	//函数名 与类名相同
	//构造函数可以有参数，可以发生重载
	//创建对象的时候，构造函数会自动调用，而且只调用一次
	Person()
	{
		cout << "Person 构造函数的调用" << endl;
	}
	//2、析构函数 进行清理的操作
	//没有返回值 不写 void
	//函数名和类名相同 在名称前加~
	//析构函数不可以有参数的，不可以发生重载
	//对象在销毁前 会自动调用析构函数，而且只会调用一次
	~Person()
	{
		cout << "Person的析构函数调用 " << endl;
	}
};


//构造和析构都是必须有的实现，如果我们自己不提供，编译器会提供一个空实现的构造和析构函数
void test01()
{
	Person p; //在栈上的数据，test01执行完后，释放这个函数
}

int main()
{
	test01();
	//Person p;
	system("pause");
	return 0;
}
```



#### 4.2.2 构造函数的分类及调用

> ##### 两种分类：
>
> 按参数分：有参构造和无参构造
> 按类型分：普通构造和拷贝构造
>
> ##### 三种调用方式：
>
> 括号法
> 显示法
> 隐式转换法

**代码：**

```c++
#include<iostream>
using namespace std;

//1、构造函数的分类及调用
//分类
//		按照参数分类	无参构造（默认构造） 和 有参构造
//		按照类型分类	普通构造	拷贝构造
class Person
{
public:
	//构造函数
	Person()
	{
		cout << "Person的无参构造函数调用" << endl;
	}
	Person(int a)
	{
		age = a;
		cout << "Person的有参构造函数调用" << endl;
	}
	//拷贝构造函数
	Person(const Person &p)
	{
		//将传入的人身上所有属性，拷贝到我身上；
		age = p.age;
		cout << "Person的拷贝构造函数调用" << endl;
	}
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
	int age;
};
void test01()
{
	 //1、口号法
	//Person p;//默认构造函数调用
	//Person p2(10);//有参构造函数
	//Person p3(p2);//拷贝构造函数

	//注意事项1
	// 调用默认构造函数时候，不要加（）
	//因为下面这行代码，编译器会认为是一个函数的声明，不会认为在创建对象
	//Person p1();

	//cout << "p2的年龄为：" << p2.age << endl;
	//cout << "p3的年龄为：" << p3.age << endl;
	
	//2、显示法
	//Person p1;
	//Person p2 = Person(10);//有参构造
	//Person p3 = Person(p2);//拷贝构造

	//Person(10);//匿名对象  特点：当前行执行结束后，系统会立即回收掉匿名对象
	//cout << "aaaa" << endl;

	//注意事项2
	//不要利用拷贝构造函数 初始化匿名对象 编译器会认为 Person (p3) == Person p3;
	//Person(p3);//编译器会认为是创建对象的声明

	//3、隐式转换法
	Person p4 = 10;//相当于 写了 Person p4 = Person(10);		有参构造
	Person p5 = p4;//拷贝构造
}
//调用

int main()
{
	test01();

	system("pause");
}
```



#### 4.2.3拷贝构造函数

> C++中拷贝构造函数调用的时机通常有三种情况
>
> - 使用一个已经创建完毕的对象来初始化一个新对象
> - 值传递的方式给函数参数传值
> - 以值方式返回局部对象
>

**示例：**

```c++
#include<iostream>
using namespace std;



class Person
{
public:
	Person()
	{
		cout << "Person默认构造函数调用" << endl;
	}
	Person(int age)
	{
		cout << "Person有参构造函数调用" << endl;
		m_Age = age;
	}
	Person(const Person& p)
	{
		cout << "Person拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
	}
	~Person()
	{
		cout << "Person析构函数调用" << endl;
	}
	int m_Age;
};

//拷贝构造函数调用时机

//1、使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
	Person p1(20);
	Person p2(p1);

	cout << "p2的年龄为：" << p2.m_Age << endl;
}
//2、值传递的方式给函数参数传值

void doWork(Person p)//值传递的本质就是拷贝一个副本出来
{

}
void test02()
{
	Person p;
	doWork(p);
}

//3、值方式返回局部变量
//vs2022进行了优化，减少了拷贝构造函数的使用

Person doWork2()
{
	Person p1;
	cout << (int*)&p1 << endl;
	return p1;
}

void test03()
{
	Person p = doWork2();
	cout << (int*)&p << endl;

}
int main() {

	//test01();
	//test02();
	test03();
	system("pause");

	return 0;
}
```



#### 4.2.4构造函数调用规则

> 默认情况下，c++编译器至少给一个类添加3个函数
>
> 1. 默认构造函数（无参，函数体为空）
> 2. 默认析构函数（无参，函数体为空）
> 3. 默认拷贝构造函数，对属性进行值拷贝
>
> 构造函数调用规则如下：
>
> - 如果用户定义有参构造函数，c++不再提供默认无参构造函数，但是会提供默认拷贝构造
> - 如果用户定义拷贝构造函数，c++不会再提供其他构造函数
>

**示例：**

```c++
#include<iostream>
using namespace std;

//构造函数的调用规则
//1、创建一个类，C++编译器会给每个类都添加至少3个函数
//默认构造 （空实现）
//析构寒素 （空实现）
//拷贝构造 （值拷贝）


//2、如果我们写了有参构造函数，编译器就不再提供默认构造，依然提供拷贝构造函数
//如果我们写了拷贝构造函数，编译就不再提供其他构造函数
class Person
{
public:
	//Person()
	//{
	//	cout << "Person的默认构造函数调用" << endl;
	//}

	Person(int age)
	{
		cout << "Person的有参构造函数调用" << endl;
		m_Age = age;
	}
	//Person(const Person& p)
	//{
	//	cout << "Person的拷贝构造函数调用" << endl;
	//	m_Age = p.m_Age;
	//}
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}

	int m_Age;
};

//void test01()
//{
//	Person p;
//	p.m_Age = 18;
//
//	Person p2(p);
//
//	cout << "p2的年龄为：" << p2.m_Age << endl;
//}

void test02()
{
	Person p(20);

	Person p2(p);

	cout << "p2的年龄为：" << p2.m_Age << endl;
}
int main() {
	
	//test01();
	test02();
	system("pause");

	return 0;
}
```



#### 4.2.5 深拷贝和浅拷贝

> 深浅拷贝是面试经典问题，也是常见的一个坑
>
> 
>
> **浅拷贝：**简单的赋值拷贝操作
> **深拷贝：**在堆区重新申请空间，行拷贝操作

**示例：**

```c++
#include<iostream>
using namespace std;

//深拷贝与浅拷贝
//浅拷贝是系统给我们的赋值操作
//深拷贝是我们重新在堆区申请一块内存
//堆区申请的内存，在析构函数中释放
class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}

	Person(int age , int height)
	{
		m_Age = age;
		cout << "Person的有参构造函数调用" << endl;
		m_Height=new int(height);			//在堆区开辟数据
	}

	//自己实现拷贝函数，解决浅拷贝带来的问题
	Person(const Person& p)
	{
		cout << "Person 拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
		//m_Height = p.m_Height;编译器默认实现就是这行代码
		//深拷贝操作

		m_Height = new int(*p.m_Height);

	}
	~Person()
	{
		//将我们在堆区开辟的数据做释放操作
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "Person的析构函数调用" << endl;
	}
	int m_Age;		//年龄
	int* m_Height;	//身高
	//浅拷贝会将堆区的地址直接传给新的类
	//在进行析构函数的时候会重复释放
};

void test01()
{
	Person p1(18,160);

	cout << "p1的年龄为：" << p1.m_Age << "身高为： " << *p1.m_Height << endl;

	Person p2(p1);
	//如果利用编译器提供的拷贝构造函数，会做浅拷贝操作

	cout << "p2的年龄为：" << p2.m_Age << "身高为： " << *p2.m_Height << endl;

}

int main() {

	test01();

	system("pause");
}
```

> #### 总结
>
> 如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题

#### 4.2.6 初始化列表

> **作用：**
> c++提供了初始化列表语法，用来初始化属性
>
> **语法：**`构造函数（）：属性1（值1），属性2（值2），属性3（值3）`

**代码：**

```c++
#include<iostream>
using namespace std;

//初始化列表
class Person
{
public:

	//传统初始化操作
	//Person(int a, int b, int c)
	//{
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}

	//初始化列表初始化属性
	Person(int a ,int b ,int c) :m_A(a), m_B(b), m_C(c)
	{

	}
	int m_A;
	int m_B;
	int m_C;
};
void test01()
{
	//Person p(10, 20, 30);
	Person p(30,20,10);
	cout << "m_A = " << p.m_A << endl;
	cout << "m_B = " << p.m_B << endl;
	cout << "m_C = " << p.m_C << endl;
}
int main()
{
	
	test01();
	system("pause");

	return 0;
}
```



#### 4.2.7 类对象作为类成员

> C++类中的成员可以是另一个类的对象，我们陈该对象为对象成员
>
> 例如
>
> ```c++
> class A()
> class B
> {
>     A a;
> }
> ```
>
> B类中有对象A作为成员，A为对象成员
>
> 那么当创建B对象时，A与B的构造和析构顺序是谁先谁后？
>



**示例：**

```c++
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
```



#### 4.2.8 静态成员

> 静态成员就是在成员变量和成员函数前加上关键字static，称为静态成员
>
> 静态成员分为：
>
> - 静态成员变量
>   - 所有对象共享一份数据
>   - 在编译阶段分配内存
>   - 类内声明，类外初始化
> - 静态成员函数
>   - 所有对象共享同一个函数
>   - 静态成员函数只能访问静态成员变量
>





**示例1：**静态成员变量

```c++
#include<iostream>
using namespace std;

//静态成员变量
class Person
{
public:

	//1、所有对象都共享同一份数据
	//2、编译阶段就分配内存
	//3、类内声明，类外初始化操作
	static int m_A;

	//静态成员变量也是有访问权限的
private:
	static int m_B;
};

int Person::m_A = 100;
int Person::m_B = 200;

void test01()
{
	Person p;
	cout << p.m_A << endl;

	Person p2;
	p.m_A = 200;
	cout << p.m_A << endl;
}

void test02()
{
	//静态成员变量 不属于某个对象上 所有对象都共享同一份数据

	//1、通过对象进行访问
	//Person p;
	//cout << p.m_A << endl;

	//2、通过类名进行访问
	cout << Person::m_A << endl;
	//cout << Person::m_B << endl;类外访问不到私有静态成员变量
}
int main()
{

	//test01();
	test02();

	system("pause");

	return 0;
}
```

**示例2：**静态成员函数

```c++
#include<iostream>
using namespace std;

//静态成员函数
//所有对象共享同一个函数
//静态成员函数只能访问静态成员变量

class Person
{
public:
	static void func()
	{
		m_A = 100;//静态成员函数可以访问 静态成员变量
		//m_B = 200;//静态成员函数 不可以访问 非静态成员变量，无法区分到底是哪个对象的m_B属性
		cout << "static void func 调用" << endl;
	}

	static int m_A;//静态成员变量
	int m_B;//非静态成员变量

	//静态成员函数 也是有访问权限的
private:
	static void func2()
	{
		cout << "static void func2 调用" << endl;
	}
};

int Person::m_A = 0;
//有两种的访问方式
void test01()
{
	//1、通过对象访问
	Person p;
	p.func();
	//2、通过类名访问
	Person::func();

	//Person::func2();类外访问不到私有静态成员函数
}
int main()
{
	test01();
	system("pause");

	return 0;
}
```



### 4.3 C++对象模型和this指针



#### 4.3.1 成员变量和成员函数分开存储

> 在C++中，类内的成员变量和成员函数分开存储
>
> 只有非静态成员变量才属于类的对象上
>

```c++
#include<iostream>
using namespace std;

//成员变量和成员函数分开存储

class Person
{
	int m_A;//非静态成员变量  属于类对象上

	static int m_B;//静态成员变量  不属于类对象上

	void func(){}//非静态成员函数  不属于类对象上

	static void func2(){}//静态成员函数  不属于类对象上
};

int Person::m_B = 0;

void test01()
{
	Person p;
	//空对像占用内存空间为：1
	//C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
	//每个空对像也应该有一个独一无二的内存地址
	cout << "size of p = " << sizeof(p) << endl;
}

void test02()
{
	Person p;
	cout << "size of p = " << sizeof(p) << endl;
}
int main() {

	//test01();

	test01();

	system("pause");

	return 0;
}
```



#### 4.3.2 this指针的概念

> 通过4.3.1我们知道在C++中成员变量和成员函数是分开存储的
>
> 每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会公用一块代码
>
> 那么问题是：这一块代码是如何区分哪个对象调用自己的呢？
>



> C++通过提供特殊的对象指针，this指针，解决上述问题，**this指针指向被调用的成员函数所属的对象**
>



> this指针是隐含每一个非静态成员函数内的一种指针
>
> this指针不需要定义，直接使用即可



> this指针的用途
>
> - 当形参和成员变量同名时，可用this指针来区分
> - 在类的非静态成员函数中返回对象本身，可使用`return *this`
>

**示例：**

```c++
#include<iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{

		//this指针指向 被调用成员函数 所属的对象
		this->age = age;
	}


	Person& PersonAddAge(Person &p)//Person PersonAddAge(Person &p) 用值的方式返回会创建新的对象，引用的方式不会
	{
		this->age += p.age;
		//this是一个指向p2的指针，而*this指向的就是p2这个对象本体
		return *this;
	}
	int age;
};

//1、解决名称冲突
void test01()
{
	Person p1(18);
	cout << "p1的年龄为： " << p1.age << endl;
}

//2、返回对象本身用*this
void test02()
{
	Person p1(10);

	Person p2(10);

	//链式编程思想
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);

	cout << "p2的年龄为：" << p2.age << endl;
}

int main() {
	//test01();

	test02();

	system("pause");

	return 0;
}
```



#### 4.3.3 空指针访问成员函数

> c++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针
>
> 
>
> 如果用到this指针，需要加以判断保证代码的健壮性
>

**示例：**

```c++
#include<iostream>
using namespace std;

//空指针调用成员函数

class Person
{
public:

	void showClassName()
	{
		cout << "this is Person class" << endl;
	}

	void showPersonAge()
	{
		//默认m_Age=this->m_Age 这里this是一个空指针
		//报错的原因是因为传入的指针是为NULL
		if (this == NULL)//防止空指针 防止代码出错
		{
			return;
		}

		cout << "age = " << m_Age << endl;

	}

	int m_Age;
};

void test01()
{
	Person* p = NULL;

	//p->showClassName();

	p->showPersonAge();
}

int main() {

	test01();
	system("pause");

	return 0;
}
```



#### 4.3.4 const修饰成员函数

> **常函数：**
>
> - 成员函数后加const后我们陈这个函数为常函数
> - 常含数内不可以修改成员属性
> - 成员属性声明是加关键字mutable后，在常函数中可以修改
>
> 
>
> **常对象：**
>
> - 声明对象前加const称该对象为常对象
> - 常对象只能调用常函数
>

```c++
#include<iostream>
using namespace std;

//常函数
class Person
{
public:

	//this指针的本质 是指针常量 指针的指向是不可以修改的
	//const Person* const this;
	//在成员函数后加const 修饰的是this指向 让指针指向的值也不可以修改
	void showPerson() const
	{
		this->m_B = 100;
		//this->m_A = 100;
		//this = NULL;//this 指针不可以修改修饰指针的指向的
	}

	void func()
	{
		m_A = 100;
	}

	int m_A;
	mutable int m_B;//特殊变量，即使在常函数中，也可以修改这个值 加关键字mutable
};


void test01()
{
	Person p;
	p.showPerson();
}

//常对象

void test02()
{
	const Person p;//在对象前加const，变为常对象
	//p.m_A = 100;
	p.m_B = 100;//m_B是特殊值，在常对象下也可以修改

	//常对象只能调用常函数
	p.showPerson();
	//p.func();//常对象 不可以调用普通成员函数 因为普通成员函数可以修改属性
}

int main()
{


	system("pause");

	return 0;
}
```

### 4.4 友员



> 生活中你的家有客厅（==Public==），有你的卧室（==Private==）
>
> 客厅所有的客人都可以进去，但是你的卧室是私有的，也就是说只有你能进去
>
> 但是呢，你也可以允许的好闺蜜好基友进去。
>
> 在程序里，有些私有属性 也想让类外特殊的一些函数或者进行访问，就需要用到友员的技术
>
> 友员的目的就是让一个函数或者类 访问另一个类中私有成员
>



> 友员的关键字为` friend`
>



> 友员的三种实现
>
> - 全局函数做友员
> - 类做友员
> - 成员函数做友员
>

#### 4.4.1 全局函数做友员

```c++
#include<iostream>
#include<string>
using namespace std;

//建筑类
class Building
{
	//goodGay全局函数是Building好朋友，可以访问Building中私有成员
	friend void goodGay(Building* building);
public:
	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
public:
	string m_SittingRoom;//客厅

private:
	string m_BedRoom;
};

//全局函数
void goodGay(Building* building)
{
	cout << "好基友的全局函数 正在访问： " << building->m_SittingRoom << endl;
	cout << "好基友的全局函数 正在访问： " << building->m_BedRoom << endl;
}

void test01()
{
	Building building;
	goodGay(&building);
}

int main()
{

	test01();
	system("pause");

	return 0;
}
```



#### 4.4.2 类做友员

```c++
#include<iostream>
using namespace std;

//类做友员

class Building;

class GoodGay
{
public:

	GoodGay();

	void visit();//参观函数 访问Building中的属性

	Building* building;
};

class Building
{
	//GodGay类是本类的好朋友，可以访问本类中私有的成员
	friend class GoodGay;
public:
	Building();
public:

	string m_SittingRoom;//客厅

private:
	string m_BedRoom;//卧室
};

//类外写成员函数
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
	//创建建筑物对象
	building = new Building;
}

void GoodGay::visit()
{
	cout << "好基友正在访问：" << building->m_SittingRoom << endl;
	cout << "好基友正在访问：" << building->m_BedRoom << endl;
}
void test01()
{
	GoodGay gg;
	gg.visit();
}
int main() {

	test01();

	system("pause");

	return 0;
}
```



#### 4.4.3 成员函数做友员

```c++
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
```



### 4.5 运算符重载

> 运算符重载概念：对已有的运算符进行重新定义，赋予其另一种功能，以适应不同的数据类型
>



#### 4.5.1 加号运算符重载

> 作用：实现两个自定义数据类型相加的运算
>



```c++
#include<iostream>
using namespace std;

//加号运算符重载

class Person
{
public:
	
	//1、成员函数重载+号
	Person operator+(Person& p)
	{
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}

	int m_A;
	int m_B;
};

//2、全局函数重载+号
//Person operator+(Person& p1, Person& p2)
//{
//	Person temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}

//函数重载的版本
Person operator+(Person& p1, int num)
{
	Person temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}

void test01()
{
	Person p1;
	p1.m_A = 10;
	p1.m_B = 10;
	Person p2;
	p2.m_A = 10;
	p2.m_B = 10;

	//成员函数重载本质调用
	//Person p3 = p1.operator+(p2);

	//全局函数重载本质调用
	//Person p3 = operater+(p1, p2);
	Person p3 = p1 + p2;

	//运算符重载 也可以发生函数重载
	Person p4 = p1 + 100;

	cout << "p4.m_A = " << p4.m_A << endl;
	cout << "p4.m_B = " << p4.m_B << endl;
}




int main()
{
	test01();

	system("pause");

	return 0;
}
```



> 总结1：对于内置的数据类型的表达式的运算符是不可能改变的
>
> 总结2：不要滥用运算符重载
>



#### 4.5.2 左移运算符重载

作用:可以输出自定义数据类型



```c++
#include<iostream>
using namespace std;

//左移运算符重载
class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);
public:
	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}
	//利用成员函数重载左移运算符 p.operator<<(cout) 简化版本 p << cout
	// 不会利用成员函数来重载<<运算符，因为无法实现cout在左侧
	//void operator<<(Person&p)
	//{

	//}
private:
	int m_A;
	int m_B;
};

//只能利用全局函数重载左移运算符
ostream & operator<<(ostream& cout,Person &p)//本质operator<<(cout,p) 简化 cout<<p;
{
	cout << "m_A = " << p.m_A << "m_B = " << p.m_B;
	return cout;
}

void test01()
{
	Person p(10,10);

	cout << p << "Hello world" << endl;
}

int main() {

	test01();
	system("pause");

	return 0;
}
```



> 总结：重载左移运算符配合友员可以实现输出自定义数据类型
>



#### 4.5.3 递增运算符重载



> 作用：通过重载递增运算符，实现自己的整型数据
>



```c++
#include<iostream>
using namespace std;

//重载递增运算符

//自定义整型
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}

	//重载前置++运算符   返回引用为了一直对一个数据进行递增操作
	MyInteger& operator++()
	{
		//先进行++运算
		m_Num++;

		//再将自身返回值
		return *this;
	}

	MyInteger& operator--()
	{
		//先进行--运算
		m_Num--;

		//再将自身返回值
		return *this;
	}

	//重载后置++运算符
	//void operator++(int) int代表占位参数，可以用于区分前置和后置
	MyInteger operator++(int )
	{
		//先 记录当时的结果
		MyInteger temp = *this;
		//后 递增
		m_Num++;
		//最后将记录结果返回
		return temp;
	}

	MyInteger operator--(int)
	{
		//先 记录当时的结果
		MyInteger temp = *this;
		//后 递增
		m_Num--;
		//最后将记录结果返回
		return temp;
	}

private:
	int m_Num;
};

//重载<<运算符
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.m_Num;
	return cout;
}

void test01()
{
	MyInteger myint;

	cout << ++(++myint) << endl;
	cout << myint << endl;
}

void test02()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}

int main() {

	//test01();

	test02();

	int a = 0;

	//cout << ++(++a) << endl;
	//cout << a << endl;

	system("pause");

	return 0;
}
```



#### 4.5.4 赋值运算符

> c++编译器至少给一个类添加4个函数
>
> 1. 默认构造函数（无参，函数体为空）
> 2. 默认析构函数（无参，函数体为空）
> 3. 默认拷贝构造函数，对属性进行值拷贝
> 4. 赋值运算符operator=，对属性进行拷贝
>
> 
>
> 如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
>



**示例：**

```c++
#include<iostream>
using namespace std;

//赋值运算符重载
class Person
{
public:

	Person(int age)
	{
		m_Age = new int(age);
	}

	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		//堆区内存重复释放，程序崩溃
		//利用深拷贝，解决浅拷贝带来的问题
	}

	//重载赋值运算符
	Person& operator=(Person& p)
	{
		//编译器是提供浅拷贝
		//m_Age = p.m_Age;

		//应该先判断是否有属性在堆区，先释放干净，然后再深拷贝
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}

		//深拷贝
		m_Age = new int(*p.m_Age);

		//返回对象的本身
		return *this;
	}
	int* m_Age;
};

void test01()
{
	Person p1(18);

	Person p2(20);

	Person p3(30);
	p3 = p2 = p1;//赋值操作

	cout << "p1的年龄为：" << *p1.m_Age << endl;

	cout << "p2的年龄为：" << *p2.m_Age << endl;

	cout << "p3的年龄为：" << *p3.m_Age << endl;


}

int main() {

	test01();

	//int a = 10;
	//int b = 20;
	//int c = 30;
	//c = b = a;
	//cout << " a = " << a << endl;
	//cout << " b = " << b << endl;
	//cout << " c = " << c << endl;
	
	system("pause");

	return 0;
}
```



#### 4.5.5 关系运算符重载

> **作用：**重载关系运算符，可以让两个自定义对象进行比较

**示例：**

```c++
#include<iostream>
#include<string>
using namespace std;

//重载关系运算符

class Person
{
public:
	Person(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}

	//重载 == 号
	bool operator==(Person& p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		return false;
	}	
	bool operator!=(Person& p)
	{
		if (this->m_Name != p.m_Name && this->m_Age == p.m_Age)
		{
			return false;
		}
		return true;
	}

	string m_Name;
	string m_Age;

};

void test01()
{
	Person p1("Tom", 18);

	Person p2("Jerry", 18);

	if (p1 == p2)
	{
		cout << "p1和p2是相等的!" << endl;
	}
	else
	{
		cout << "p1和p2是不相等的！" << endl;
	}

	if (p1 != p2)
	{
		cout << "p1和p2是相等的!" << endl;
	}
	else
	{
		cout << "p1和p2是不相等的！" << endl;
	}
}

int main() {
	
	test01();

	system("pause");

	return 0;
}
```



#### 4.5.6 函数调用运算符重载

> 函数调用运算符（）也可以重载
> 由于重载后使用的方式非常像函数的调用，
> 因此成为仿函数仿函数没有固定写法，非常灵活



**示例：**

```c++
#include<iostream>
#include<string>
using namespace std;

class MyPrint
{
public:

	//重载函数调用运算符
	void operator()(string test)
	{
		cout << test << endl;
	}
};

void MyPrint02(string test)
{
	cout << test << endl;
}

void test01()
{
	MyPrint myPrint;

	myPrint("Hello world!");//由于使用起来非常类似于函数调用，因此称为仿函数

	MyPrint02("Hello world!");
}

//仿函数非常灵活，没有固定的写法
//加法类

class MyAdd
{
public:
	int operator()(int num1,int num2)
	{
		return num1 + num2;
	}
};

void test02()
{
	MyAdd myadd;
	int ret = myadd(100, 100);
	cout << "ret = " << ret << endl;

	//匿名函数对象
	cout << MyAdd()(100, 100) << endl;
}
int main() {

	//test01();

	test02();

	system("pause");

	return 0;
}
```





### 4.6 继承

> 继承是面向对象三大特性之一
>
> 有些类与类之间存在特殊关系，例如下图中：
>
> 
>
> 我们发现，定义这些类时，下级别的成员除了拥有上一级的共性，还有自己的特性
>
> 这个时候我们就可以考虑利用继承的技术，减少重复代码
>



#### 4.6.1 继承的基本语法

> 例如我们看到很多网站中，都有公共的头部，公共的底部，甚至公共的列表，只有中心内容不同
>
> 接下来我们分别利用普通写法和继承的写法来实现网页中的内容，看一下继承存在的意义以及好处
>

**普通实现：**

```c++
#include<iostream>
using namespace std;

//普通实现页面

//Java页面
//class Java
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登录、注册（公共的头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图（公共的底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Java、Python、C++、（公共分类列表）" << endl;
//	}
//	void content()
//	{
//		cout << "Java学科视频" << endl;
//	}
//};
//
////Python页面
//class Python
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登录、注册（公共的头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图（公共的底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Java、Python、C++、（公共分类列表）" << endl;
//	}
//	void content()
//	{
//		cout << "Python学科视频" << endl;
//	}
//};
//
////C++
//class Cpp
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登录、注册（公共的头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图（公共的底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Java、Python、C++、（公共分类列表）" << endl;
//	}
//	void content()
//	{
//		cout << "C++学科视频" << endl;
//	}
//};


//继承实现页面

//继承的好处：减少重复代码
//语法：class 子类：继承方式 父类
//子类 也称为 派生类
//父类 也称为 基类

//公共页面
class BasePage
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册（公共的头部）" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图（公共的底部）" << endl;
	}
	void left()
	{
		cout << "Java、Python、C++、（公共分类列表）" << endl;
	}
};

//Java页面
class Java :public BasePage
{
public:
	void content()
	{
		cout << "Java学科视频" << endl;
	}
};

//Python页面
class Python :public BasePage
{
public:
	void content()
	{
		cout << "Python学科视频" << endl;
	}
};

//C++页面
class Cpp :public BasePage
{
public:
	void content()
	{
		cout << "C++学科视频" << endl;
	}
};

void test01()
{
	cout << "Java下载视频页面如下：" << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();

	cout << "-------------------------------" << endl;
	cout << "Python下载视频页面如下：" << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();

	cout << "-------------------------------" << endl;
	cout << "C++下载视频页面如下：" << endl;
	Cpp cpp;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.content();

}

int main() {

	test01();

	system("pause");

	return 0;
}
```



> #### 总结：
>
> 继承的好处：可以减少重复的代码
>
> class A : public B;
>
> A类称为子类 或 派生类
>
> B类称为父类 或 基类
>
> 
>
> **派生类中的成员，包含两大部分：**
>
> 一类是从基类中的成员，一类是自己增加的成员
>
> 从基类继承过来的表现其共性，而新增的成员体现了其个性 
>



#### 4.6.2 继承方式



> 继承的语法：`class A : public B;`
>
> 
>
> 继承方式一共有三种：
>
> - 公共继承
> - 保护继承
> - 私有继承
>

```c++
#include<iostream>
using namespace std;

//继承方式

//公共继承
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1 :public Base1
{
public:
	void func()
	{
		m_A = 10;//父类中的公共权限成员 到子类中依然是公共权限
		m_B = 10;//父类中的保护权限成员 到子类中依然是保护权限
		//m_C = 10;//父类中的私有权限成员 子类中访问不到
	}
};

//保护继承
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son2 :protected Base2
{
public:
	void func()
	{
		m_A = 100;//子类中公共成员 到子类中变为保护权限
		m_B = 100;//子类中保护成员 到子类中变为保护权限
		//m_C = 100;//父类中的私有成员 子类访问不到
	}
};

void test01()
{
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100;//到Son1中 m_B是保护权限 类外访问不到
}

void test02()
{
	Son2 s1;
	//s1.m_A = 1000;//在Son2中 m_A变为保护权限，因此类外访问不到
	//s1.m_B = 1000;//在Son2中 m_B为保护权限 不可以访问
}

class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son3:private Base3
{
public:
	void func()
	{ 
		m_A = 100;//父类中公共成员 到子类中变为 私有成员
		m_B = 100;//父类中保护成员 到子类中变为 私有成员
		//m_C = 100;//父类中的私有成员，子类访问不到
	}
};

class GrandSon3 :public Son3
{
public:
	void func()
	{
		
		//m_A = 1000;//到了Son3中 m_A变为私有 即使是儿子 也访问不到
		//m_B = 1000;//到了Son3中 m_B变为私有 即使是儿子 也访问不到
	}
};
void test03()
{
	Son3 s1;
	//s1.m_A = 1000;//到了Son3中 变为 私有成员 类外访问不到
	//s1.m_B = 1000;//到了Son3中 变为 私有成员 类外访问不到
}

int main()
{
	system("pause");

	return 0;
}
```



#### 4.6.3 继承中的对象模型



> **问题：**从父类继承过来的成员，哪些属于子类对象中？



**示例：**

```c++
#include<iostream>
using namespace std;

//继承中的对象模型

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son :public Base
{
public:

	int m_D;
};

//利用开发人员命令提示工具查看对象模型
//跳转盘符  F:
//跳转文件路径 cd 具体路径下
//查看命名
//c1 /d1 resportSingleClassLayout类名 文件名

void test01()
{
	//16
	//父类中所有非静态成员属性都会被子类传承下去
	//父类中私有成员属性 是被编译器隐藏了 因此是访问不到 但是确实被继承下去了
	cout << "size of Son = " << sizeof(Son) << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

> vs 2022 的开发人员命令提示符
>
> 
>
> 结论：父类中私有成员也是被子类继承下去了，只是由编译器给隐藏后访问不到
>



#### 4.6.4 继承中构造和析构顺序



> 子类继承父类，当创建子类对象，也会调用父类的构造函数
>
> 
>
> 问题：父类和子类的构造和析构顺序是谁先谁后？
>



**示例：**

```c++
#include<iostream>
using namespace std;

//继承中的构造和析构顺序
class Base
{
public:
	Base()
	{
		cout << "Base构造函数！" << endl;
	}
	~Base()
	{
		cout << "Base析构函数！" << endl;
	}
};


class Son:public Base
{
public:
	Son()
	{
		cout << "Son构造函数！" << endl;
	}
	~Son()
	{
		cout << "Son析构函数！" << endl;
	}
};

void test01()
{
	//Base b;

	//继承中的构造和析构顺序如下：
	//先构造父类，再构造子类，析构的顺序与构造的顺序相反
	Son s;
}
int main() {

	test01();

	system("pause");

	return 0;
}
```

> **总结：**先构造父类，再构造子类，析构的顺序与构造的顺序相反。





#### 4.6.5 继承同名成员处理方式

**示例：**

```c++
#include<iostream>
using namespace std;

//继承中同名成员处理
class Base
{
public:
	Base()
	{
		m_A = 100;
	}

	void func()
	{
		cout << "Base - func()调用" << endl;
	}
	void func(int a)
	{
		cout << "Base - func(int a)调用" << endl;
	}
	int m_A;
};

class Son :public Base
{
public:
	Son()
	{
		m_A = 200;
	}
	void func()
	{
		cout << "Son - func()调用" << endl;
	}
 
	int m_A;
};

//同名的成员属性处理
void test01()
{
	Son s;
	cout << "Son 下 m_A = " << s.m_A << endl;
	//如果通过子类对象 访问到父类中的同名成员 需要加一个作用域
	cout << "Base 下 m_A = " << s.Base::m_A << endl;
}

//同名的成员函数处理
void test02()
{
	Son s;

	s.func();//直接调用 调用的是子类中的同名成员

	//如何调用到父类中同名成员函数
	s.Base::func();

	//如果子类中出现和父类同名的成员函数 ，子类的同名成员会隐藏掉父类中所有同名成员函数
	// 如果像访问父类中被隐藏的同名成员函数，需要加作用域
	s.Base::func(100);
}

int main() {

	//test01();

	test02();

	system("pause");

	return 0;
}
```

> #### 总结：
>
> 1. 子类对象可以直接访问到子类中同名成员
> 2. 子类对象加作用域可以访问到父类同名成员
> 3. 当子类与父类拥有同名的成员函数，子类会隐藏父类中的同名函数，加作用域可以访问到父类中同名函数
>



#### 4.6.6 继承同名静态成员处理方式

> 问题：继承中同名的静态成员再子类对象上如何访问
>
> 静态成员和非静态成员出现同名，处理方式一致
>
> 
>
> - 访问子类同名成员 直接访问即可
> - 访问父类同名成员 需要加作用域
>



**示例：**

```c++
#include<iostream>
using namespace std;

//继承中的同名静态成员处理方式

class Base
{
public:

	static int m_A;

	static void func()
	{
		cout << "Base - static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Son - static void func()" << endl;
	}
};

int Base::m_A = 100;

class Son :public Base
{
public:

	static int m_A;

	static void func()
	{
		cout << "Son - static void func()" << endl;
	}	

};


int Son::m_A = 200;

//同名静态成员属性
void test01()
{
	//1、通过对象访问
	cout << "通过对象访问：" << endl;
	Son s;
	cout << "Son 下 m_A = " << s.m_A << endl;
	cout << "Base 下 m_A = " << s.Base::m_A << endl;
	
	//2、通过类名访问
	cout << "通过类名访问：" << endl;
	cout << "Son 下 m_A = " << Son::m_A << endl;
	//第一个::代表通过类名方式访问 第二个::代表访问父类作用域下
	cout << "Base 下 m_A = " << Son::Base::m_A << endl;

}
//同名静态函数
void test02()
{
	//1、通过对象访问
	cout << "通过对象访问" << endl;
	Son s;
	s.func();
	s.Base::func();

	//2、通过类名访问
	cout << "通过类名访问" << endl;
	Son::func();
	Son::Base::func();

	//子类出现和父类同名静态成员函数，也会隐藏父类所有同名成员函数
	//如果想访问父类中被隐藏同名成员，需要加作用域
	Son::Base::func(100);
}

int main() {

	//test01();
	test02();

	system("pause");

	return 0;
}
```

> **总结：**同名静态成员处理方式和非静态处理方式一样，只不过有两种访问方式（通过对象 和 通过类名）



#### 4.6.7 多继承语法

> C++允许**一个类继承多个类**
>
> 语法：`class 子类 ：继承方式 父类1，继承方式 父类2.。。。`
>
> 多继承可能会引发父类中有同名成员出现，需要加作用域区分
>

**C++开发中不建议用多继承**

**示例：**

```c++
#include<iostream>
using namespace std;

//多继承语法

class Base1
{
public:
	Base1()
	{
		m_A = 100;
	}

	int m_A;
};
class Base2
{
public:
	Base2()
	{
		m_A = 200;
	}

	int m_A;
};

//子类   需要继承Base1和Base2
//语法： class子类 ：继承方式 父类1，继承方式 父类2.。。。。
class Son :public Base1, public Base2
{
public:
	Son()
	{
		m_C = 300;
		m_D = 400;
	}


	int m_C;
	int m_D;
};

void test01()
{
	Son s;

	cout << "sizeof Son = " << sizeof(s) << endl;
	//当父类中出现同名成员，需要加作用域区分
	cout << "Base1::m_A = " << s.Base1::m_A << endl;
	cout << "Base2::m_A = " << s.Base2::m_A << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

> 总结：多继承中如果父类中出现了同名情况，子类使用时候要加作用域
>



#### 4.6.8 菱形继承

> **菱形继承概念：**
>
> 两个派生类继承同一个基类
> 又有某个类同时继承着两个派生类
> 这种继承被称为菱形继承，或者钻石继承
>
> **典型的菱形继承案例：**
>
> 菱形继承问题：
>
> 1. 羊继承了动物的数据，驼同样继承了动物的数据，当草泥马使用数据时，就会产生二义性
> 2. 草泥马继承自动物的数据继承了两份，其实我们应该清楚，这份数据我们只需要一份就可以
>

```c++
#include<iostream>
using namespace std;

//动物类

class Animal
{
public:
	int m_Age;
};
//利用虚继承 解决菱形继承的问题
//继承之前 加上关键字virtual 变为虚继承
// Animal 类称为虚基类
//羊类
class Sheep:virtual public Animal{};

//驼类
class Tuo:virtual public Animal{};

//羊驼类
class SheepTuo:public Sheep,public Tuo{};

void test01()
{
	SheepTuo st;

	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 28;
	//当菱形继承是，两个父类拥有相同数据，需要加以作用域区分
	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
	cout << "st.m_Age = " << st.m_Age << endl;
	//这份数据我们知道 只要有一份就可以 菱形继承导致数据有两份 资源浪费
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

> 总结：
>
> - 菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费以及毫无意义
> - 利用虚继承可以解决菱形继承问题
>

### 4.7 多态

#### 4.7.1 多态的基本概念

> **多态是C++面向对象三大特性之一**
>
> 多态分为两类
>
> - 静态多态：函数重载 和运算符重载属于静态多态，复用函数名
> - 动态多态：派生类和虚函数实现运行时多态
>
> 静态多态和动态多态区别：
>
> - 静态多态的函数地址早绑定 - 编译阶段确定函数地址
> - 动态多态的函数地址晚绑定 - 运行阶段确定函数地址
>
> 下面通过案例进行讲解多态
>



```c++
#include<iostream>
using namespace std;

//多态

//动物类

class Animal
{
public:
	//虚函数 
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
	
};

//狗类
class Dog :public Animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};

//猫类
class Cat :public Animal
{
public:
	//重写 函数返回值 函数名 参数列表 完全相同
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};

//执行说话的函数
//地址早绑定 在编译阶段确定函数地址
//如果想执行让猫说话，那么这个函数地址就不能提前绑定 需要在运行阶段进行绑定，地址晚绑定

//动态多态满足条件
//1、有继承关系
//2、子类重写的虚函数

//动态多态使用
//父类的指针或者引用 指向子类对象

void doSpeak(Animal& animal)//Animal & animal = cat ;
{
	animal.speak();
}

void test01()
{

	Cat cat;
	doSpeak(cat);
	
	Dog dog;
	doSpeak(dog);
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

> #### 总结：
>
> 多态满足条件
>
> - 有继承关系
> - 子类重写父类中的虚函数
>
> 多态使用条件
>
> - 父类指针或引用指向子类对象
>
> 重写：函数返回值类型 函数名 参数列表 完全一致称为重写
>



#### 4.7.2 多态案例一 - 计算器类

> 案例描述：
>
> 分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类
>
> 多态的优点：
>
> - 代码组织结构清晰
> - 可读性强
> - 利于前期和后期的扩展以及维护
>

**示例：**

```c++
#include<iostream>
#include<string>
using namespace std;

//分别利用普通写法和多态技术实现计算器

//普通写法
class Calculator
{
public:

	int getResult(string oper)
	{
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		else if (oper == "*")
		{
			return m_Num1 * m_Num2;
		}
		//如果想要扩展新的功能，需要修改源码
		//在真实的开发中 提倡开闭原则
		//开闭原则：对扩展进行开放 对修改进行关闭
	}


	int m_Num1;
	int m_Num2;

};

//利用多态实现计算器
//多态好处：
//1、组织结构清晰
//2、可读性强
//3、对于前期和后期的扩展以及维护性高
//实现计算器抽象类

class AbstractCalculator
{
public:

	virtual int getResult()
	{
		return 0;
	}

	int m_Num1;
	int m_Num2;
};

//加法计算器类
class AddCalculator :public AbstractCalculator
{
public:

	virtual int getResult()
	{
		return m_Num1 + m_Num2;
	}
};

//减法运算
class SubCalculator :public AbstractCalculator
{
public:

	virtual int getResult()
	{
		return m_Num1 - m_Num2;
	}
};

//乘法运算
class MulCalculator :public AbstractCalculator
{
public:

	virtual int getResult()
	{
		return m_Num1 * m_Num2;
	}
};

void test02()
{
	//多态使用调价
	//父类指针或者引用指向子类对象

	//加法运算
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;

	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
	//用完后记得销毁
	delete abc;

	//减法运算
	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
	//乘法运算
	abc = new MulCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;

	delete abc;

	abc = nullptr;

}

void test01()
{
	//创建一个计算器的对象
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;

	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;

	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;

	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
}

int main() {

	//test01();
	test02();

	system("pause");

	return 0;
}
```

总结：C++开发提倡利用多态设计程序架构，因为多态优点很多。



#### 4.7.3 纯虚函数和抽象类

> 在多态类，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
>
> 因此可以将虚函数改为**纯虚函数**
>
> 纯虚函数语法 ：` virtual  返回值 函数名   （参数列表） = 0；`
>
> 当类中有了纯虚数，这个类也称为抽象类
>
> **抽象类的特点：**
>
> - 无法实例化对象
> - 子类必须重写抽象类中的纯虚函数，否则也属于抽象类
>



**示例：**

```c++
#include<iostream>
using namespace std;

//纯虚函数和抽象类
class Base
{
public:

	//纯虚函数
	//只要有一个纯虚函数，这个类称为抽象类
	//抽象类特点
	//1、无法示例化对象
	//2、抽象类的子类 必须要重写父类中的纯虚函数，否则也属于抽象类
	virtual void func() = 0;

};

class Son :public Base
{
public:
	virtual void func()
	{
		cout << "func函数调用" << endl;
	};

};

void test01()
{
	//Base b;//抽象类是无法实例化对象
	//new Base;//抽象类是无法实例化对象

	//Son s;//子类必须重写父类中的纯虚函数，否则无法实例化对象

	Base* base = new Son;
	base->func();
}

int main() {

	test01();

	system("pause");

	return 0;
}
```



#### 4.7.4 多态案例-制作饮品

> **案例描述：**
>
> 制作饮品的大致流程为：煮水 -  冲泡 -  倒入杯中 -  加入辅料
>
> 利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶
>



```c++
#include<iostream>
using namespace std;

//多态案例2 制作饮品
class AbstractDrinking
{
public:
	
	//煮水
	virtual void Boil() = 0;

	//冲泡
	virtual void Brew() = 0;

	//倒入杯中
	virtual void PourInCup() = 0;

	//加入辅料
	virtual void PutSomething() = 0;

	//制作饮品
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}

};

//制作咖啡
class Coffe :public AbstractDrinking
{
	//煮水
	virtual void Boil()
	{
		cout << "煮农夫山泉" << endl;
	}

	//冲泡
	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}

	//倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;
	}

	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入糖和牛奶" << endl;
	}
};

//制作茶叶
class Tea :public AbstractDrinking
{
public:

	//煮水
	virtual void Boil()
	{
		cout << "煮矿泉水" << endl;
	}

	//冲泡
	virtual void Brew()
	{
		cout << "冲泡茶叶" << endl;
	}

	//倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;
	}

	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入柠檬" << endl;
	}
};

void doWork(AbstractDrinking*abs)
{
	abs->makeDrink();
	delete abs;//释放
}

void test01()
{
	//制作咖啡
	doWork(new Coffe);

	cout << "-------------" << endl;
	//制作茶叶
	doWork(new Tea);
}

int main() {

	test01();

	system("pause");

	return 0;
}
```



#### 4.7.5 虚析构和纯虚析构

> 多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
>
> 解决方式：将父类中的析构函数改为虚析构或者纯虚析构
>
> 虚析构和纯虚析构共性：
>
> - 可以解决父类指针释放子类对象
> - 都需要具体的函数实现
>
> 虚析构和纯虚析构区别：
>
> - 如果是纯虚析构，该类属于抽象类，无法实例化对象
>
> 虚析构语法：
>
> `virtual  ~类名（）{};`
>
> 纯虚析构语法：
>
> `virtual  ~类名（）=  0;`
>
> 类名:: ~类名
>

```c++
#include<iostream>
#include<string>
using namespace std;

//虚析构和纯虚析构

class Animal
{
public:

	Animal()
	{
		cout << "Animal构造函数调用" << endl;
	}

	////利用虚析构可以解决 父类指针释放子类对象时不干净的问题
	//virtual ~Animal()
	//{
	//	cout << "Animal虚析构函数调用" << endl;
	//}
	
	//纯虚析构   需要声明 也需要实现
	//有了纯虚析构 之后 ，这个类也属于抽象类 无法实例化对象
	virtual ~Animal() = 0;
	
	//纯虚函数
	virtual void speak() = 0;
};

Animal::~Animal()
{
	cout<< "Animal纯虚析构函数调用" << endl;
}
class Cat :public Animal
{
public:

	Cat(string name)
	{
		cout << "Cat构造函数调用" << endl;
		m_Name = new string(name);
	}
	virtual void speak()
	{
		cout << *m_Name << "小猫在说话" << endl;
	}

	~Cat()
	{
		if (m_Name != NULL)
		{
			cout << "Cat析构函数调用" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
	string *m_Name;
};

void test01()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	//父类指针在析构时候 不会调用子类中析构函数 导致子类如果有堆区属性 出现内存泄漏
	delete animal;
}

int main() {

	test01();


	system("pause");

	return 0;
}
```



#### 4.7.6 多态案例三-电脑组装

> **案例描述：**
>
> 电脑主要组成部件为CPU（用于计算），显卡（用于显示），内存条（用于存储）
>
> 将每个零件封装出抽象类，并且提供不同厂商生产不同零部件，例如Intel厂商和Lenovo厂商
>
> 创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
>
> 测试时组装三台不同的电脑进行工作
>

**示例：**

```c++
#include<iostream>
using namespace std;

//抽象不同零件
//抽象CPU类

class CPU
{
public:
	//抽象的计算机函数
	virtual void calculate() = 0;

};

//抽象显卡类
class VideoCard
{
public:
	//抽象的显示函数
	virtual void display() = 0;

};

//抽象内存条类
class Memory
{
public:
	//抽象的存储函数
	virtual void storage() = 0;

};

//电脑类
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}

	//提供工作的函数
	void work()
	{
		//认识那个零件工作起来，调用接口
		m_cpu->calculate();

		m_vc->display();

		m_mem->storage();
	}

	//提供一个析构函数 释放3个电脑零件
	~Computer()
	{
		//释放CPU零件
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		//释放内存条零件
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
		//释放显卡零件
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
	}

private:

	CPU* m_cpu;//CPU零件指针
	VideoCard* m_vc; //显卡零件指针
	Memory* m_mem;//内存条零件指针

};

//具体的厂商
//Intel厂商
class IntelCPU :public CPU
{
public:
	//抽象的计算机函数
	virtual void calculate()
	{
		cout << "Intel的CPU开始计算了！" << endl;
	}
};


class IntelVideoCard :public VideoCard
{
public:

	virtual void display()
	{
		cout << "Intel的显卡开始显示了！" << endl;
	}
};

class IntelMemory :public Memory
{
public:

	virtual void storage()
	{
		cout << "Intel的内存条开始存储了！" << endl;
	}
};

//Lenovo厂商
class LenovoCPU :public CPU
{
public:
	//抽象的计算机函数
	virtual void calculate()
	{
		cout << "Lenovo的CPU开始计算了！" << endl;
	}
};


class LenovoVideoCard :public VideoCard
{
public:

	virtual void display()
	{
		cout << "Lenovo的显卡开始显示了！" << endl;
	}
};

class LenovoMemory :public Memory
{
public:

	virtual void storage()
	{
		cout << "Lenovo的内存条开始存储了！" << endl;
	}
};

void test01()
{
	//第一台电脑零件
	CPU* interlCPU = new IntelCPU;
	VideoCard* intelCard = new IntelVideoCard;
	Memory* intelMem = new IntelMemory;

	cout << "第一台电脑开始工作：" << endl;
	//创建第一台电脑
	Computer* computer1 = new Computer(interlCPU, intelCard, intelMem);
	computer1->work();
	delete computer1;

	cout << "----------------------------" << endl;
	cout << "第二台电脑开始工作:" << endl;
	//第二台电脑的组装
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;

	cout << "----------------------------" << endl;
	cout << "第三台电脑开始工作:" << endl;
	//第二台电脑的组装
	Computer* computer3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);
	computer3->work();
	delete computer3;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

