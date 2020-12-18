#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int i, j, k;
//	while (scanf("%d", &k) != EOF)
//	{
//		for (i = 1; i <= k; i++)
//		{
//			for (int n = 0; n <k-i; n++)
//			{
//				printf(" ");
//			}
//			for (j = 1; j <= i; j++)
//			{
//				printf("* ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

int main()
{
	int i, j, k, n;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 1; i <= n + 1; i++)
		{
			for(j=1;j<=n+1-i;j++)
			{
				printf(" ");
			}
			for (k = 1; k <=i; k++)
			{
				printf("* ");
			}
			printf("\n");
		}
		for (i = 1; i <= n ; i++)
		{
			for (j = 1; j <=  i; j++)
			{
				printf(" ");
			}
			for (k = i; k <= n  ; k++)
			{
				printf("* ");
			}
			printf("\n");
		}
	}
	return 0;
}