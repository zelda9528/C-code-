#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>




//输入年份和月份计算天数
//int main()
//{
//	int year, month;
//	while (scanf("%d %d", &year, &month) != EOF)
//	{
//		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
//		{
//			printf("31\n");
//		}
//		else if (month == 4 || month == 6 || month == 9 || month == 11)
//		{
//			printf("30\n");
//		}
//		else
//		{
//			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//			{
//				printf("29\n");
//			}
//			else
//			{
//				printf("28\n");
//			}
//		}
//	}
//	return 0;
//}



//三角形判断
//int main()
//{
//	int a, b, c;
//	while (scanf("%d %d %d", &a, &b, &c) != EOF)
//	{
//		if (a + b > c&&a + c > b&&b + c > a)
//		{
//			if (a == b && b == c)
//				printf("Equilateral triangle!\n");
//			else if (a == b || a == c || b == c)
//				printf("Isosceles triangle!\n");
//			else
//				printf("Ordinary triangle!\n");
//		}
//		else
//			printf("Not a triangle!\n");
//
//	}
//
//	return 0;
//}


//大小写转换
//int main()
//{
//	char c;
//	while (scanf("%c", &c) != EOF)
//	{
//		getchar();
//		if (c >= 'a'&&c <= 'z')
//			printf("%c\n", c - 32);
//		if (c >= 'A'&&c <= 'Z')
//			printf("%c\n", c + 32);
//	}
//
//	return 0;
//}



//多组输入判断大小
//#include<stdio.h>
//int main()
//{
//	int a, b;
//	while (scanf("%d %d", &a, &b) != eof)
//	{
//		if (a > b)
//			printf("%d>%d\n", a, b);
//		else if (a < b)
//			printf("%d<%d\n", a, b);
//		else
//			printf("%d=%d\n", a, b);
//	}
//}



//分段函数
//#include<stdio.h>
//int main()
//{
//	int t = 0;
//	while (scanf("%d", &t) != EOF)
//	{
//		if (t > 0)
//			printf("1\n");
//		if (t == 0)
//			printf("0.5\n");
//		if (t < 0)
//			printf("0\n");
//	}
//
//	return 0;
//}