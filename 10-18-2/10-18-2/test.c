#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

void Reverse(char*left, char*right)
{
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void Swap(char arr[],int k)
{
	int len = strlen(arr);
	Reverse(&arr[0], &arr[0] + k-1);
	Reverse(&arr[k], &arr[len - 1]);
	Reverse(&arr[0], &arr[len - 1]);
}
int main()
{
	int k = 0;
	scanf("%d", &k);
	char arr[] = "abcdef";
	printf("%s\n", arr);
	Swap(arr, k);
	printf("%s\n", arr);
	return 0;

}
