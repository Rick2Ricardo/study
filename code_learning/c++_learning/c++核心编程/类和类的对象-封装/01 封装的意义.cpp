#include<iostream>
using namespace std;

const double PI = 3.14;
//���һ��Բ�࣬��Բ���ܳ�
//Բ���ܳ��Ĺ�ʽ�� 2 * PI * �뾶

//class �������һ���࣬���������ŵľ���������
class Circle
{
	//����Ȩ��
	//����Ȩ��
public:

	//����,�ñ���
	int m_r;

	//��Ϊ �ú���
	//��ȡԲ���ܳ�
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
		cout << "ѧ���������ǣ�" << this->name << endl;
		cout << "ѧ����ѧ���ǣ�" << this->Num << endl;
	}
};
int main() {

	////ͨ��Բ�࣬���������Բ������
	////ʵ���� ��ͨ��һ���� ����һ������Ĺ��̣�
	Circle c1;
	Circle c2;
	////��Բ���� �����Խ��и�ֵ
	c1.m_r = 10;
	c2.m_r = 30;
	cout << "��Բ���ܳ�Ϊ��" << c1.calculateZC() << endl;
	cout << c2.m_r << endl;
	int m_p = c1.readit();
	//cout << "Բ���ܳ�Ϊ�� " << c1.calculateZC() << endl;
	/*myStu st1;
	string Name;
	string Num;
	cout << "���������ѧ��������" << endl;
	cin >> Name;
	cout << "���������ѧ��ѧ�ţ�" << endl;
	cin >> Num;

	st1.AddInfo(Name, Num);
	st1.ShowInfo();*/
	system("pause");

	return 0;
}