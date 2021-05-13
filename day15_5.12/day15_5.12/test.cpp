#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;
class A {
public:
	static int findNumber0f1(int num)
	{
		int count = 0;
		int flag = 1;
		while (flag)
		{
			if (num&flag)
				count++;
			flag = flag << 1;
		}
		return count;
	}

};


int main()
{
	cout<<A::findNumber0f1(5);
	return 0;
}


//class A {
//public:
//
//	~A()
//	{
//		cout << "da" << endl;
//	}
//};
//
//class B :public A {
//public:
//	~B()
//	{
//		cout << "db" << endl;
//	}
//};
//
//void test()
//{
//	A *a = new B;
//	delete a;
//}

//static int a = 1;
//void func1() {
//	a = 2;
//}
//void func2() {
//	int a = 3;
//}
//void func3() {
//	static int a = 4;
//}
//void test()
//{
//	cout << a << endl;	//1
//	func1();
//	cout << a << endl;	//2
//	func2();
//	cout << a << endl;	//3
//	func3();
//	cout << a << endl;	//4
//
//}


//class A {
//public:
//	void func()
//	{
//		cout << "A" << endl;
//	}
//};
//
//class B :public A {
//public:
//	virtual void func()
//	{
//		cout << "B" << endl;
//	}
//};


//
//int main() 
//{
//	test();
//	return 0;
//}