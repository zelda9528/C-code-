#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main()
{
	float a, b, c, s, p;
	printf("请输入边长:\n");
	scanf("%f %f %f", &a, &b, &c);
	printf("a=%f b=%f c=%f\n", a, b, c);
	if (a + b > c&&a + c > b&&b + c > a)
	{
		p = (a + b + c) / 2;
		printf("能构成三角形，面积是:%f\n", sqrt(p*(p - a)*(p - b)*(p - c)));
	}
	else
	{
		printf("不能构成三角形\n");
	}
	return 0;
}