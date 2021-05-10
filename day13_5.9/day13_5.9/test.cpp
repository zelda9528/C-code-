#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class A {
public:
	virtual void fun()
	{
		cout << "A" << endl;
	}
};

class B :public A {
public:
	virtual void fun()
	{
		cout << "B" << endl;
	}
};

class C :public A {
public:
	virtual void fun()
	{
		cout << "C" << endl;
	}
};

void fun(A a)
{
	a.fun();
}

int main()
{
	A a, *aa, *ab, *ac;
	B b;
	C c;
	a.fun();
	b.fun();
	c.fun();
	aa = &a;
	ab = &b;
	ac = &c;
	aa->fun();
	ab->fun();
	ac->fun();
	fun(a);
	fun(b);
	fun(c);


	return 0;
}



//int main()
//{
//	int i=0, a=1, b=2, c=3;
//	i = ++i || ++b || ++c;
//	printf("%d%d%d%d", i, a, b, c);
//	return 0;
//}

/*class B
{
public:
	B()
	{
		cout << 1<<" ";
	}

	~B()
	{
		cout << 2 << " ";
	}

	B(int i) :data(i)
	{
		cout << 3 << " ";
	}
private:
	int data;
};

B play(B b)
{
	return b;
}

int main()
{
	B tmp = play(5);
	return 0;
}*/


//void func(const string& str)
//{
//	int count = 0;
//	int i = 0;
//	for (const char&ch : str)
//	{
//		if (ch == ' ')
//			count += 1;
//	}
//	cout << count+1 << endl;
//
//	for (i = 0; i < str.size(); i++)
//	{
//		if (str[i] == ' ')
//		{
//			cout << endl;
//		}
//		else if (str[i] == '\0')
//		{
//			cout << endl;
//		}
//		else
//			cout << str[i];
//	}
//	cout << endl;
//}
//int main()
//{
//	string str;
//	getline(cin, str);
//	func(str);
//	return 0;
//}