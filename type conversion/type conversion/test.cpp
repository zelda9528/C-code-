#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;


class A{
public:
	virtual void fun()	//虚函数
	{}
};
class B:public A{
	void fun()	//重写父类虚函数
	{}
};

int main()
{
	int a=1;
	double f=1.2;
	int *p = &a;


	//1.static_cast:支持所有的隐式类型转换，
	//特殊：仅持支父类指针或者引用到子类指针或者引用的强制类型转换
	//     不支持其他的强制类型转换。

	//强制类型转换
	a = (int)p;

	//不支持：a = static_cast<int>(pa);

	a = static_cast<int>(f);

	A* pa = new A;
	B* pb = (B*)pa;
	B* pb1 = static_cast<B*>(pb);



	//2. reinterpret_cast：支持强制类型转换
	a = reinterpret_cast<int>(pa);

	//3.const_cast:去除变量的const属性
	volatile const int m = 10;
	cout << "m:" << m << endl;

	//不能用普通指针取const数据的地址：int *pm = &m;
	int *pm = const_cast<int*>(&m);
	
	*pm = 100;
	cout << "m:" << m << endl;

	//4.dynamic_cast:只能用于多态场景下，父类的引用/指针向子类转换
	A* paa = new A;
	B* pbb = dynamic_cast<B*>(pa);

	return 0;
}