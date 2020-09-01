#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int arr[5] = { 0 };
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (j = 0; j < 5; j++)
	{
		printf("%d ", arr[j]);
	}
	return 0;
}