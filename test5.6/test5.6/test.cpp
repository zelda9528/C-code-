#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

class A{
public:
  virtual void f()
  {
	cout << "A::f()" << endl;
  }
};

class B : public A{

	virtual void f()
	{
		cout << "B::f()" << endl;
	}
public:
	B() {}

};

int main()
{
	A* pa = (A*)new B;
	pa->f();
	return 0;
}