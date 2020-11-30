#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

int main()
{
	float a, b, c;
	scanf("%f %f %f", &a, &b, &c);
	float area, len;
	if (a > 0 && b > 0 && c > 0)
	{
		len = a + b + c;
		float p = (a + b + c) / 2;
		area = sqrt(p*(p - a)*(p - b)*(p - c));
	}
	printf("circumference=%.2f area=%.2f", len, area);
	return 0;
}