#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cmath>
using namespace std;
int sroot(int a)
{
	return int(sqrt(a));
}

long sroot(long a)
{
	return long(sqrt(a));
}
double sroot(double a)
{
	return double(sqrt(a));
}
int main()
{
	int a = 4;
	long b = 12345;
	double c = 0.01;
	cout<< sroot(a)  << endl;
	cout << sroot(b) << endl;
	cout << sroot(c) << endl;
	return 0;
}