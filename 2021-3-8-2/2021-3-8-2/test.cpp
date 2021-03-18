#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


template<typename T>
void Swap(T&left, T&right)
{
	T tmp = left;
	left = right;
	right = tmp;
}

int main()
{
	char a = 'a';
	char b = 'b';
	int i = 1, j = 2;
	double m = 1.0, n = 2.0;
	Swap(a, b);
	Swap(i, j);
	Swap(m, n);
	return 0;
}