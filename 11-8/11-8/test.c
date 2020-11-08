#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	printf("practice makes perfect!");
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 1234;
//	printf("%#o ", a);
//	printf("%#X", a);
//	return 0;
//}

//16进制数字转10进制输出 
//#include<stdio.h>
//int main()
//{
//	printf("%15d", 0XABCDEF);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	//printf("Hello world!\n")
//	printf("%d", printf("Hello world!\n"));
//		return 0;
//}

int main()
{
	char a = '0';
	scanf("%c", &a);
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 5 - i; j > 0; j--)
		{
			printf(" ");
		}
		for (int m=1 ; m <= i; m++)
		{
			printf("%c ", a);
		}
		printf("\n");
	}
	return 0;
}