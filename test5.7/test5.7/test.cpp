#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class A {
public:
	A() {}
	virtual void fun1() {}
	virtual void fun2() {}
	void fun3() {}
	int _a;
 };

class B :public A {
public:
	void fun1(){}
	int _b;
};
int main()
{
	A a;
	B b;
	cout << sizeof(a) << endl;
	return 0;
}




//class A{};
//
//class B :public A {};
//
//
//class Person {
//public:
//	virtual A* RedPapper()
//	{
//		cout << "100块" << endl;
//		return new A;
//	}
//};
//
//class Student :public Person {
//public:
//	//协变：返回值为具有继承关系的指针或引用
//	B* RedPapper()
//	{
//		cout << "1毛" << endl;
//		return new B;
//	}
//};
//
//void test()
//{
//	Person p;
//	Person* rp=&p;
//	rp->RedPapper();
//
//	rp = (Person*)new Student;
//	rp->RedPapper();
//}
//
//int main()
//{
//	test();
//	return 0;
//}



//class Person {
//public:
//	virtual void BuyTicket()
//	{
//		cout << "全票" << endl;
//	}
//	virtual Person* RedPapper()
//	{
//		cout << "100块" << endl;
//			return new Person;
//	}
//};
//
//class Student :public Person {
//public:
//	//重写：函数名，参数列表、返回值与父类虚函数完全相同
//	void BuyTicket()
//	{
//		cout << "半票" << endl;
//	}
//	//协变：返回值为具有继承关系的指针或引用
//	Student* RedPapper()
//	{
//		cout << "1毛" << endl;
//		return new Student;
//	}
//};
//
//
//void test()
//{
//	Person p;
//	Person* p1 = &p;
//	Person& p2 = p;
//	//p.BuyTicket();	//用对象来调用虚函数时，不会产生多态
//
//	p1->BuyTicket();	
//	p2.BuyTicket();
//	p1->RedPapper();
//	p2.RedPapper();
//
//	Student s;
//	p1 = &s;
//	Person& p3 = s;
//	p1->BuyTicket();
//	p3.BuyTicket();
//
//	p1->RedPapper();
//	p3.RedPapper();
//
//}
//
//int main()
//{
//	test();
//	return 0;
//}
