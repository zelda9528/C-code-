#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


void rank(int*score,int n)
{
	int i, j, tmp;
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (score[i] < score[j])
			{
				tmp = score[i];
				score[i] = score[j];
				score[j] = tmp;
			}
		}

	}
}

int main()
{
	int n = 0;
	int score[40] = { 0 };

	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d ", &score[i]);
	}

	rank(score,n);

	for (int j = 0; j < 5; j++)
	{
		printf("%d ", score[j]);
	}

	return 0;
}