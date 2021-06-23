#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

void Print1ToMaxOfNDigitsRecursively(char *number, int length, int idex);
void PrintNumber(char* number);


void Print1ToMaxOfNDigits(int n)
{
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	number[n] = '\0';

	for (int i = 0; i < 10; i++)
	{
		number[0] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, n, 0);
	}
	delete[] number;
}

void Print1ToMaxOfNDigitsRecursively(char *number, int length, int index)
{
	if (index == length - 1)
	{
		PrintNumber(number);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		number[index + 1] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}

void PrintNumber(char* number) 
{
	bool isBeginning0 = true;
	int nLength = strlen(number);
	for (int i = 0; i < nLength; i++)
	{
		if (isBeginning0&&number[i] != '0')
			isBeginning0 = false;
		if (!isBeginning0)
			printf("%c", number[i]);
	}
	printf(" ");
}

int main()
{
	Print1ToMaxOfNDigits(4);
	return 0;
}