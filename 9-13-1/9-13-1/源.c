#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i = 0;
	int num = 10;//00000000000000000000000000001010
	//奇数位：0000000000000011
	//偶数位：0000000000000000
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (num >> i) & 1);
	}
	return 0;
}