#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
int main()
{
	char arr1[] = "welcome to my world";
	char arr2[] = "*******************";
	int left = 0;
	int right = sizeof(arr2) - 1;
	while (left <= right)
	{
		Sleep(1000);
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		left++;
		right--;
		printf("%s\n", arr2);
	}

	return 0;
}