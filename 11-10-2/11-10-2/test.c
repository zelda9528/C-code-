#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int num = 0;//从数组中删掉数据的个数
void Dupl(int * arr,int n)
{
	int i,j,k;
	for (i = 0; i < n-num; i++)//标记数组中的一个值
	{
		for (j = i+1; j < n  ; j++)//判断标记值是否有重复
		{
			if (arr[i] == arr[j])
			{
				for (k = j; k < n - num - 1; k++)//出现重复，数组向左平移
				{
					arr[k] = arr[k + 1];
				}
				j--;
				num++;
				arr[k] = 0;
			}

		}

	}

}
int main()
{
	int arr[1000] = { 0 };
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}
	Dupl(arr,n);
	for (int i = 0; i < n-num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
