#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class A {
public:
	A(int a) :_a(1)
	{
		cout << "A()" << endl;
	}
private:
	int _a;
};

int main()
{
	A obj1(1);
	A obj2 = obj1;
	A obj3 = 20;	//用整数20初始化类的对象，发生单参构造函数的隐式类型转换 
					//编译器会先用整数20初始化一个临时的无名对象，然后用该临时对象给obj3进行赋值	
	return 0;
}

