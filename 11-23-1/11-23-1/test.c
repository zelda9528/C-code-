#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stddef.h>

struct S
{
	char c;//1
	int i;//4
};

int main()
{
	//struct S s = {0};
	//printf("%d\n", sizeof(s));
	printf("%d\n", offsetof(struct S, c));
	printf("%d\n", offsetof(struct S, i));

	return 0;
}