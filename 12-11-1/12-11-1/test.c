#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int remove(int *nums, int numssize, int val)
{
	int* newnums = (int *)malloc(sizeof(int)*numssize);
	int idx = 0;
	for (int i = 0; i < numssize; i++)
	{
		while (nums[i]!=val)
		{
			newnums[idx++] = nums[i];
		}
	}
	memcpy(nums, newnums, sizeof(int)*idx);
	free(newnums);
	return idx;
}
int main()
{
	int arr[4] = { 3,2,2,3 };
	int a=remove(arr, 4, 3);
	printf("%d ", a);
}