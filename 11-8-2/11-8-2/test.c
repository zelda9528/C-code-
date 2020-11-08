#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	long a;
	float b, c, d;
	scanf("%ld %f %f %f\n", &a, &b, &c, &d);
	printf("The each subject score of  No. %ld is %.2f, %.2f, %.2f.\n", a, b, c, d);
	return 0;
}