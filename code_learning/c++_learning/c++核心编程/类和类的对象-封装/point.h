#pragma once
#include<iostream>
using namespace std;

//����
class Point
{
private:
	int m_X;
	int m_Y;

public:
	//����x
	void setX(int x);

	//��ȡx
	int getX();

	//����y
	void setY(int y);

	//��ȡy
	int getY();

};