#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Exchange(int *a, int *b) 
{
	int t = *a;
	*a = *b;
	*b = t;
}
int main() 
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a < b) Exchange(&a, &b); 
	if (a < c) Exchange(&a, &c); 
	if (b < c) Exchange(&b, &c); 
	printf("%d %d %d\n", a, b, c);
	return 0;
}
