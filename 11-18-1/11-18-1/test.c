#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <math.h>
int main()
{
	double weight, high;
	scanf("%lf%lf", &weight, &high);
	high /= 100;
	double High = pow(high, 2);
	double bmi = (double)(weight) / High;
	printf("%.2lf", bmi);
	return 0;
}