#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;

		for (int i = 2; i < sqrt(n); i++)
		{
			if (n%i == 0)
			{
				while (n%i == 0)
				{
					n /= i;
				}
				count++;
			}
		}
		if (n != 1)
		{
			count++;
		}
		cout << count;
	}
	return 0;
}

//#include<stdio.h>
//
//int main()
//{
//	char ch;
//	while ((ch=getchar()) != EOF)
//	{
//		if (ch >= 'A'&&ch <= 'Z')
//		{
//
//			ch>'E'? ch-=5 :ch+=21 ;
//		}
//		putchar(ch);
//	}
//	return 0;
//}