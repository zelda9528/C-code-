#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
	for (int i = 1; i < 40; i++)
	{
		for (int j = 1; j < 200; j++)
		{
			if (5 * i + 2 * 10 * j + j == 200)
			{
				cout << 11*j+i << endl;
			}
		}
	}

	return 0;
}