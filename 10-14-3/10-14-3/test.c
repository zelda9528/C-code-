#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//void LeftHanded(char* arr,int time)
//{
//	int i, j, tmp;
//	int len = strlen(arr);
//	time %= len;
//	for ( i = 0; i < time; i++)
//	{
//		tmp = arr[0];
//		for (j = 0; j < len - 1; j++)
//		{
//			arr[j] = arr[j + 1];
//		}
//		arr[j] = tmp;
//		i++;
//	}
//
//
//
//}
//int main()
//{
//	char arr[4] = {'a','b','c','d'};
//	
//	int time = 2;
//	LeftHanded(arr, time);
//
//	for (int j = 0; j < 4; j++)
//	{
//		printf("%c", arr[j]);
//	}
//	return 0;
//}


void leftRound(char * src, int time)
{
	int i, j, tmp;
	int len = strlen(src);
	time %= len; //长度为5的情况下，旋转6、11、16...次相当于1次，7、12、17...次相当于2次，以此类推。
	for (i = 0; i < time; i++) //执行k次的单次平移
	{
		tmp = src[0];
		for (j = 0; j < len - 1; j++) //单次平移
		{
			src[j] = src[j + 1];
		}
		src[j] = tmp;
	}
}
int main()
{
	char src[] = { 'a','b','c','d' };
	int time = 2;
	leftRound(src, time);
	for (int j = 0; j < 4; j++)
			{
				printf("%c", src[j]);
			}
	return 0;
}