#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>

int main()
{
	float a, b, c;
	scanf("%f %f %f", &a, &b, &c);
	float sum = a + b + c;
	float avg = (a + b + c) / 3;
	printf("%.2f ", sum);
	printf("%.2f\n", avg);
}
