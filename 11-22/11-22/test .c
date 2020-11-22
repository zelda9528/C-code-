#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int main()
{
	//000000000000000000000000010
	//001001010100000000000000111
	//111111111111111111111111101

	unsigned char i = 7;
	//7 4 1 254 251 ....5 2 255 252 3 0 
	int j = 0;
	for (; i>0; i -= 3)
	{
		++j;
	}
	printf("%d\n", j);
	return 0;
}