#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class A
{
public:
	int a;
	A(int x = 1 )
	{
		a = x;
		cout << "A()" << endl;
	}
};
class date {
public:
	//无参构造函数
	date()
	{
		cout << "date()" << endl;
	}
	//带参构造函数---也可以作为默认构造函数
	date(int y=1, int m=1, int d=1)
	{
		year = y;
		month = m;
		day = d;
		cout << "date(int ,int ,int)" << endl;
	}
	//拷贝构造函数--形参必须为本类对象的引用
	//如果不显式定义拷贝构造函数，编译器会自动生成
	date(const date&  a)
	{
		year = a.year;
		month = a.month;
		day = a.day;
		cout << "copy" << endl;
	}
private:
	int year;
	int month;
	int day;

	A a;

};

void test()
{

	date b(2021,2,3);	//调用有参构造函数
	date copy(b);
}

int main()
{
	test();
	return 0;
}