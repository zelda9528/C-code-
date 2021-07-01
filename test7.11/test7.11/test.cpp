#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstdio>
using namespace std;

void test1()
{
	cout << sizeof(int) << endl;//4
	cout << sizeof(long) << endl;//4
	cout << sizeof(long long) << endl;//8
	cout << sizeof(short) << endl;//2
	cout << sizeof(float) << endl;//4
	cout << sizeof(double) << endl;//8
	cout << sizeof(char) << endl;//1
	cout << sizeof(bool) << endl;//1


	for (int i = 32; i <= 127; i++)
	{
		printf("%c ", i);
	}
}

void test2()
{
	int score;
	cout << "你考试考了多少分？（1~100）\n";

	cin >> score;

	if (score >= 90 && score <= 100)
		cout << "优\n";
	if (score >= 80 && score <= 90)
		cout << "良\n";
	if (score >= 60 && score <= 80)
		cout << "优\n";
	if (score >= 0 && score <= 60)
		cout << "良\n";
	else
		cout << "错误\n";
}

bool IsPrimeNumber(int num)
{
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num%i == 0)
			return false;
	}
	return true;
}

void test3()
{
	for (int i = 2; i <= 100; i++)
	{
		if (IsPrimeNumber(i))
			cout << i << endl;
		else 
			continue;
	}
}

void test4()
{
	int i = 2;
	while (i <=100)
	{
		if (IsPrimeNumber(i))
		{
			cout << i << endl;
			i++;
		}
		else
		{
			i++;
			continue;
		}
	}
}

void test5()
{
	int i = 2;
	do
	{
		if (IsPrimeNumber(i))
		{
			cout << i << endl;
			i++;
		}
		else
		{
			i++;
			continue;
		}
	} while (i <= 100);
}
void test6()
{
	printf("现在下雨吗？\n");
	char n;
	cin >> n;
	switch (n)
	{
	case 'Y':
		cout << "现在正在下雨.\n"; break;
	case 'N':
		cout << "现在没有下雨.\n"; break;
	default:
		test6();
	}
}

int main()
{

	//test2();
	//test3();
	//test4();
	//test5();
	test6();
	return 0;
}