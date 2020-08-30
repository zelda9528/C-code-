#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//打印菜单
void menu(void)
{
	printf("*************************\n");
	printf("**1.play*********0.exit**\n");
	printf("*************************\n");
}

//初始化棋盘
void InitBoard(char board[ROW][COL], int  row, int col)
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//显示棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i;
	int j;
	printf("     ");
	for (j = 0; j < col; j++)
	{
		printf("%2d  ", j + 1);
	}
	printf("\n\n");
	for (i = 0; i < row; i++)
	{
		printf("%3d  ", i + 1);
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n     ");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

//玩家落子
void PlayerMove(char board[ROW][COL], int row, int col, int arr[])
{
	int i;
	int j;

	printf("该玩家落子\n");
	printf("请输入位置：");
	printf("例如：1 1（该位置对应棋盘左上角第一格,输入完毕按enter键结束）\n");
	while (1)
	{
		scanf("%d %d", &i, &j);
		if ((i - 1) >= 0 && (i - 1) < row && (j - 1) >= 0 && (j - 1) < row)
		{
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				arr[0] = i - 1;
				arr[1] = j - 1;
				return arr;
			}
			else
			{
				printf("该位置已有棋子，请重新输入！！\n");
			}
		}
		else
		{
			printf("输入坐标不在棋盘范围内，请重新输入！！\n");
		}
	}
}
//电脑落子
void ComMove(char board[ROW][COL], int row, int col, int arr[])
{
	printf("该电脑落子：\n");
	int i;
	int j;
	while (1)
	{
		i = rand() % row;
		j = rand() % col;
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			arr[0] = i;
			arr[1] = j;
			return arr;
		}
	}
}

//判断输赢
char Winner(char board[ROW][COL], int row, int col, int arr[])
{
	int i;
	int j;
	int x = arr[0];
	int y = arr[1];
	int count[4] = { 1,1,1,1 };

	//向左检查
	for (i = x + 1; i < row; i++)
	{
		if (board[i][y] == board[x][y] && board[x][y] != ' ')
		{
			(count[0])++;
		}
		else
		{
			break;
		}
	}
	//向右检查
	for (i = x - 1; i >= 0; i--)
	{
		if (board[i][y] == board[x][y] && board[x][y] != ' ')
		{
			(count[0])++;
		}
		else
		{
			break;
		}
	}

	//向上检查
	for (j = y + 1; j < col; j++)
	{
		if (board[x][j] == board[x][y] && board[x][y] != ' ')
		{
			(count[1])++;
		}
		else
		{
			break;
		}
	}

	//向下检查
	for (j = y - 1; j >= 0; j--)
	{
		if (board[x][j] == board[x][y] && board[x][y] != ' ')
		{
			(count[1])++;
		}
		else
		{
			break;
		}
	}

	//向右上检查
	i = x + 1;
	j = y + 1;
	while (i < row && j < col)
	{
		if (board[i][j] == board[x][y] && board[x][y] != ' ')
		{
			(count[2])++;
			i++;
			j++;
		}
		else
		{
			break;
		}
	}
	//向左下检查
	i = x - 1;
	j = y - 1;
	while (i >= 0 && j >= 0)
	{
		if (board[i][j] == board[x][y] && board[x][y] != ' ')
		{
			(count[2])++;
			i--;
			j--;
		}
		else
		{
			break;
		}
	}

	//向左上检查
	i = x - 1;
	j = y + 1;
	while (i >= 0 && j < col)
	{
		if (board[i][j] == board[x][y] && board[x][y] != ' ')
		{
			(count[3])++;
			i--;
			j++;
		}
		else
		{
			break;
		}
	}

	//向右下检查
	i = x + 1;
	j = y - 1;
	while (i < row && j >= 0)
	{
		if (board[i][j] == board[x][y] && board[x][y] != ' ')
		{
			(count[3])++;
			i++;
			j--;
		}
		else
		{
			break;
		}
	}

	for (i = 0; i < 4; i++)
	{
		if (count[i] >= COUNT)
		{
			return board[x][y];
		}
	}

	//棋盘是否满？
	int ret = IsFull(board, ROW, COL);
	if (ret)
	{
		return 'E';
	}
	return 'C';
}

//判断棋盘是否落满子
int IsFull(char board[ROW][COL], int row, int col)
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < row; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}



//游戏主体
void game(void)
{
	char ret;

	//用于接收落子坐标
	int arr[2];

	//游戏界面部分
	//创建一个棋盘
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);

	//游戏功能部分
	while (1)
	{
		//玩家落子
		PlayerMove(board, ROW, COL, arr);
		DisplayBoard(board, ROW, COL);
		ret = Winner(board, ROW, COL, arr);
		if (ret != 'C')
		{
			break;
		}
		//电脑落子
		ComMove(board, ROW, COL, arr);
		printf("电脑落子位置是:(%d,%d)\n", arr[0] + 1, arr[1] + 1);
		DisplayBoard(board, ROW, COL, arr);
		ret = Winner(board, ROW, COL, arr);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("恭喜你，胜利！\n");
	}
	else if (ret == '#')
	{
		printf("很遗憾，失败了！\n");
	}
	else
	{
		printf("旗鼓相当，打成平局\n");
	}
}