#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

int Fib(int i)
{
	if (i == 1 || i == 2)
		return 1;
	else
		return Fib(i - 1) + Fib(i - 2);
}
int main()
{
	int *p = new int[20];
	for (int i = 1; i <= 20; i++)
	{
		*p = Fib(i);
		cout << *p;
		cout << endl;
	}
	return 0;
}