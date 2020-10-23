#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>




int main()
{
	char arr1[] = "2671100876.tech";
	char tmp[30] = { 0 };
	strcpy(tmp, arr1);
	char arr2[] = "@.";
	char* p = NULL;
	for (p = strtok(tmp, arr2); p != NULL; p = strtok(NULL, arr2))
	{
		printf("%s\n", p);
	}

	//char* p = strtok(tmp, arr2);
	//printf("%s\n", p);

	//p = strtok(NULL, arr2);
	//printf("%s\n", p);

	//p = strtok(NULL, arr2);
	//printf("%s\n", p);
	return 0;
}