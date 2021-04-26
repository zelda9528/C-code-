#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//抽象类的派生类必须重写虚函数才能实例化
//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//void Test()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//}

//class Person {
//public:
//	//虚函数：virtual + 函数
//	virtual void boyTicket()
//	{
//		cout << "全票" << endl;
//	}
//};
//
//class Student :public Person
//{
//	virtual void buyTicket()
//	{
//		cout << "半票" << endl;
//	}
//};
//
//
//void fun(&p)
//{
//	rp.buyTicket();
//}
//void test()
//{
//	Person p;
//	Student stu;
//	fun(p);
//	fun(stu);
//}

int main()
{
	Test();
	return 0;
}