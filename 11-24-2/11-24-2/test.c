#define _CRT_SECURE_NO_WARNINGS 1

#define offsetof(StructType, MemberName) (size_t)&(((StructType *)0)->MemberName)

#include<stdio.h>
int main()
{
	struct S
	{
		double a;
		int b;
		char c;
		int d;
	};
	printf("%d\n",offsetof(struct S,d));
	return 0;
}