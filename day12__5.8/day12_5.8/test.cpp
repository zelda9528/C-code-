#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cmath>
using namespace std;

//1.二进制位插入
//int main()
//{
//	int m, n, i, j;
//	while (cin >> n >> m >> j >> i)
//	{
//		n |= (m << j);
//		cout << n << endl;
//	}
//	return 0;
//}

//2.查找组成一个偶数最接近的两个素数
bool IsPrimeNumber(int num)
{
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int factor1 = n / 2;
		int factor2 = n - factor1;
		while (factor1 >= 1 && factor1 <= n)
		{
			if (factor1 >= 1 && factor1 <= n && (!IsPrimeNumber(factor1) || !IsPrimeNumber(factor2)))
			{
				--factor1;
				++factor2;
			}
			else
				break;
		}
		cout << factor1 << endl << factor2 << endl;
	}
	return 0;
}