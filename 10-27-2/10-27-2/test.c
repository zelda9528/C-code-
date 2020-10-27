#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define ROW 3  
#define COL 3

int Find(int a[ROW][COL], int x)
{
	int i = 0;      //初始化i和j
	int j = COL - 1;
	while (j >= 0 && i < COL)
	{
		if (a[i][j] < x) //比我大就向下
		{
			i++;
		}
		else if (a[i][j] > x) //比我小就向左
		{
			j--;
		}
		else
		{
			return 1;
		}
	}
	return 0;

}
int  main()
{
	int a[3][3] = { 1,2,3,4,5,6,7,8,9 };
	printf("请输入要查找的数：");
	int x = 0;
	scanf("%d", &x);
	if (Find(a, x))
	{
		printf("找到了\n");
	}
	else
	{
		printf("没找到\n");
	}
	return 0;
}

