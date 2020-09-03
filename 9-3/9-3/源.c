#define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
void action1(int x, int y)
{
	printf("x+y=%d\n", x + y);
}
void action2(int x, int y)
{
	printf("x*y=%d\n", x*y);
}
int main()
{
	void action1(int x, int y), action2(int x, int y);
	char ch;
	int a = 15, b = 23;
	ch = getchar();
	switch (ch)
	{
	case 'A':
	case 'a':action1(a, b); break;
	case 'B':
	case 'b':action2(a, b); break;
	default:putchar('\a');
	}
	return 0;
}
