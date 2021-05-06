#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int  count = 0;
		int max = 0;
		while (n != 0)
		{
			if (n % 2 == 1)
			{
				count++;
			}
			else
			{
				count = 0;
			}
			n /= 2;
			if (count > max)
				max = count;
		}
		cout << max << endl;
	}
	return 0;
}


//class A {
//public:
//	virtual void func(int val = 1)
//	{
//		cout << "A->" << val << endl;
//	}
//
//	virtual void test()
//	{
//		func();
//	}
//};
//
//class B :public  A{
//public:
//	void func(int val = 0)
//	{
//		cout << "B->" << val << endl;
//	}
//
//};
//int main()
//{
//	B* p = new B;
//	p->test();
//	return 0;
//}




//class A
//{
//public:
//  A() :m_iVal(0) { test(); }
//  virtual void func() { std::cout << m_iVal << " "; }
//  void test() { func(); }
//public:
//  int m_iVal;
//};
//
//class B : public A
//{
//public:
//	B() { test(); }
//	virtual void func()
//	{
//		++m_iVal;
//		std::cout << m_iVal << " ";
//	}
//};
//
//int main(int argc, char* argv[])
//
//{
//	A*p = new B;
//	p->test();
//	return 0;
//
//}
//class A {
//public:
//	void foo()
//	{
//		printf("1");
//	}
//	virtual void fun()
//	{
//		printf("2");
//	}
//};
//
//class B :public A {
//public:
//	void foo()
//	{
//		printf("3");
//	}
//	void fun()
//	{
//		printf("4");
//	}
//};
//int main()
//{
//	A a;
//	B b;
//	A*p = &a;
//	p->foo();
//	p->fun();
//	p = &b;
//	p->foo();
//	p->fun();
//	A* ptr = (A*)&b;
//	ptr->foo();
//	ptr->fun();
//	return 0;
//}

//struct A {
//	int a;
//	short b;
//	int c;
//	char d;
//};
//
//struct B {
//	int m;
//	short n;
//	char o;
//	int p;
//};
//int main()
//{
//	cout << sizeof(A) << " " << sizeof(B) << endl;
//}

//int fo(int n)
//{
//	if (n < 2) {
//		return n;
//	}
//	else
//		return 2 * fo(n - 1) + fo(n - 2);
//}
//
//int main()
//{
//	cout << fo(5) << endl;
//	return 0;
//}