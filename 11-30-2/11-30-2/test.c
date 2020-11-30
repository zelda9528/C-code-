#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main()
{
	double r = 0;
	double V;
	scanf("%lf", &r);
	double p = 3.1415926;
	double R = pow(r, 3);
	double H = (double)4 / 3;
	V = H* p *R;
	printf("%.3lf", V);
	return 0;
}