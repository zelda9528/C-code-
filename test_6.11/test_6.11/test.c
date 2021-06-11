#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main()
{
	int i;
	char buffer[256];
	printf("Enter a number: ");
	fgets(buffer, 256, stdin);
	i = atoi(buffer);
	printf("The value entered is %d. Its double is %d.\n", i, i * 2);

	char a[] = "-100";
	char b[] = "456";
	int c;

	c = atoi(a) + atoi(b);
	printf("c = %d\n", c);

	return 0;
}

//int main()
//{
//	char a, b, c;
//	printf(" the size of the result of a+b :%d ", sizeof(a + b));
//	return 0;
//}

//union {
//	int a;
//	char b;
//}u;
//
//int main()
//{
//	u.a = 1;
//	if (u.b == 1)
//	{
//		printf("xiaoduan ");
//	}
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	char* b = &a;
//	if (*b == 1)
//		printf("小端\n");
//	else
//		printf("大端\n");
//	return 0;
//}


/*
int main()
{
	////一维数组
	//int a[] = { 1,2,3,4 };
	//printf("%d\n", sizeof(a));//16
	//printf("%d\n", sizeof(a + 0));//4
	//printf("%d\n", sizeof(*a));//4
	//printf("%d\n", sizeof(a + 1));//4
	//printf("%d\n", sizeof(a[1]));//4
	//printf("%d\n", sizeof(&a));//4
	//printf("%d\n", sizeof(*&a));//16
	//printf("%d\n", sizeof(&a + 1));//4
	//printf("%d\n", sizeof(&a[0]));//4
	//printf("%d\n", sizeof(&a[0] + 1));//4

	////字符数组
	//char arr[] = { 'a','b','c','d','e','f' };
	//printf("%d\n", sizeof(arr));//6
	//printf("%d\n", sizeof(arr + 0));//4
	//printf("%d\n", sizeof(*arr));//1
	//printf("%d\n", sizeof(arr[1]));//1
	//printf("%d\n", sizeof(&arr));//4
	//printf("%d\n", sizeof(&arr + 1));//4
	//printf("%d\n", sizeof(&arr[0] + 1));//4
	//
	//printf("%d\n", strlen(arr));//
	//printf("%d\n", strlen(arr + 0));//
	////printf("%d\n", strlen(*arr));//error
	////printf("%d\n", strlen(arr[1]));//5
	////printf("%d\n", strlen(&arr));//6
	////printf("%d\n", strlen(&arr + 1));//5
	//printf("%d\n", strlen(&arr[0] + 1));//

	//char arr[] = "abcdef";
	//printf("%d\n", sizeof(arr));//7
	//printf("%d\n", sizeof(arr + 0));//4
	//printf("%d\n", sizeof(*arr));//1
	//printf("%d\n", sizeof(arr[1]));//1
	//printf("%d\n", sizeof(&arr));//4
	//printf("%d\n", sizeof(&arr + 1));//4
	//printf("%d\n", sizeof(&arr[0] + 1));//4

	//printf("%d\n", strlen(arr));//6
	//printf("%d\n", strlen(arr + 0));//6
	////printf("%d\n", strlen(*arr));
	////printf("%d\n", strlen(arr[1]));
	////printf("%d\n", strlen(&arr));
	////printf("%d\n", strlen(&arr + 1));
	//printf("%d\n", strlen(&arr[0] + 1));//5

	//char *p = "abcdef";
	//printf("%d\n", sizeof(p));//4
	//printf("%d\n", sizeof(p + 1));//4
	//printf("%d\n", sizeof(*p));//1
	//printf("%d\n", sizeof(p[0]));//1
	//printf("%d\n", sizeof(&p));//4
	//printf("%d\n", sizeof(&p + 1));//4
	//printf("%d\n", sizeof(&p[0] + 1));//4
	//printf("%d\n", strlen(p));//6
	//printf("%d\n", strlen(p + 1));//5
	////printf("%d\n", strlen(*p));
	////printf("%d\n", strlen(p[0]));
	////printf("%d\n", strlen(&p));
	////printf("%d\n", strlen(&p + 1));
	//printf("%d\n", strlen(&p[0] + 1));//5


	////二维数组
	//int a[3][4] = { 0 };
	//printf("%d\n", sizeof(a));//48
	////printf("%d\n", sizeof(a[0][0]));
	//printf("%d\n", sizeof(a[0]));//16
	//printf("%d\n", sizeof(a[0] + 1));//4
	////printf("%d\n", sizeof(*(a[0] + 1)));
	//printf("%d\n", sizeof(a + 1));//4
	//printf("%d\n", sizeof(*(a + 1)));//16
	//printf("%d\n", sizeof(&a[0] + 1));//4
	//printf("%d\n", sizeof(*(&a[0] + 1)));//16
	//printf("%d\n", sizeof(*a));//16
	//printf("%d\n", sizeof(a[3]));//16
	return 0;
}*/
