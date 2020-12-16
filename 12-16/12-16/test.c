#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int main()
{
	double a, b;
	char ch;
	while (scanf("%lf %c %lf", &a, &ch, &b) != EOF)
	{
		switch (ch)
		{
		case '+':
			printf("%.4lf+%.4lf=%.4lf\n", a, b, a+b);
			break;
		case'-':
			printf("%.4lf-%.4lf=%.4lf\n", a, b, a-b);
			break;
		case'*':
			printf("%.4lf*%.4lf=%.4lf\n", a, b, a*b);
			break;
		case'/':
			if (b == 0.0)
			{
				printf("Wrong!Division by zero!\n");
			}
			else
			{
				printf("%.4lf/%.4lf=%.4lf", a, b, a / b);
			}
			break;
		default:
			printf("Invalid operation!\n");
		}

	}
	return 0;
}