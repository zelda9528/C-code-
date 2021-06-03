#define _CRT_SECURE_NO_WARNINGS 1
// write your code here cpp

#include<iostream>
#include<cstdio>
using namespace std;

bool isLeapYear(int y)
{
	return ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0);
}

//月份
int DAYS[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

//求解 y  m  d  这一年过了多少天
int nDays(int y, int m, int d)
{
	int n = d;

	for (int i = 0; i < m - 1; i++)
	{
		n += DAYS[i];
	}
	if (m > 2 && isLeapYear(y))
	{
		n += 1;
	}
	return n;
}

//给定 y m d  计算从基准日期到待计算日期过了多少天%7
int diff(int y, int m, int d)
{
	return (y - 1) + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400 + nDays(y, m, d);
}

//传入 y  m  d 计算周几
int week(int y, int m, int d)
{
	int w = diff(y, m, d)%7;
	if (w == 0)
		w = 7;
	return w;
}

//已知当月1日是星期w，计算第n个星期e是几号
int m1(int w, int n, int e)
{
	return 1 + (n - 1) * 7 + (7 - w + e) % 7;
}

//已知6月1日是星期w，计算5月的最后一个星期1
int m2(int w)
{
	int d = (w == 1 ? 7 : w - 1);
	return 32 - d;
}

int main()
{
	int y;
	while (cin >> y)
	{
		/*
		和中国的节日不同，美国的节假日通常是选择某个月的第几个星期几这种形式，因此每一年的放假日期都不相同。具体规则如下：
		* 1月1日：元旦
		* 1月的第三个星期一：马丁·路德·金纪念日
		* 2月的第三个星期一：总统节
		* 5月的最后一个星期一：阵亡将士纪念日
		* 7月4日：美国国庆
		* 9月的第一个星期一：劳动节
		* 11月的第四个星期四：感恩节
		* 12月25日：圣诞节
		现在给出一个年份，请你帮忙生成当年节日的日期。
		*/
		printf("%d-01-01\n", y);
		int w;
		w = week(y, 1, 1);
		printf("%d-01-%02d\n", y, m1(w, 3, 1));
		w = week(y, 2, 1);
		printf("%d-02-%02d\n", y, m1(w, 3, 1));

		w = week(y, 6, 1);
		printf("%d-05-%d\n", y, m2(w));


		printf("%d-07-04\n", y);

		w = week(y, 9, 1);
		printf("%d-09-%02d\n", y, m1(w, 1, 1));

		w = week(y, 11, 1);
		printf("%d-11-%02d\n", y, m1(w, 4, 4));

		printf("%d-12-25\n\n", y);
	}
	return 0;
}

