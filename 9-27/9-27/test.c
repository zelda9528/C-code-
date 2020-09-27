#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define PI 3.1415926
int main()
{
	double r, pertimrter, area;
	scanf("%lf", &r);
	pertimrter = 2 * PI*r;
	area = PI * r*r;
	printf("pertimrter=%lf\tarea=%lf\t", pertimrter, area);
}

