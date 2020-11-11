#include<stdio.h>
int main()
{
	int s = 0;
	scanf("%d", &s);
	int hour = 0;
	int minute = 0;
	int second = 0;
	while (s >= 3600)
	{
		s -= 3600;
		hour++;
	}
	while (s >= 60)
	{
		s -= 60;
		minute++;
	}
	second = s;
	printf("%d %d %d\n", hour, minute, second);
	return 0;
}