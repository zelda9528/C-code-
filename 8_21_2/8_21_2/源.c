#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
void menu()
{
	printf("******************************\n");
	printf("******      1. play     ******\n");
	printf("******      0. exit     ******\n");
	printf("******************************\n");
}

//RAND_MAX = 32767 - rand函数返回的是一个0-32767之间的随机数
 
void game()
{
	//1. 生成随机数 1-100 之间的随机数
	//C语言中有一个生成随机数的函数 - rand
	//time函数
	int guess = 0;
	int ret = rand()%100+1;

	//2. 猜数字
	while (1)
	{
		printf("请猜数字:>");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//时刻发生变化的数字 - 电脑上的时间一直在变化 -
	do
	{
		//1. 打印一个菜单
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//游戏的逻辑
			game();//猜数字游戏的代码
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择!\n");
			break;
		}
	} while (input);
	return 0;
}