#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include "game.h"
void menu()
{
	printf("################################\n");
	printf("####1、开始游戏  0、退出游戏####\n");
	printf("################################\n");
}
void game()
{
	char board[ROW][COL] = {0};
	int ret = 0;
	initboard(board,ROW,COL);
	displayboard(board,ROW,COL);
	while (1)
	{
		playermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
		printf("玩家赢了\n");
	else if (ret == '#')
		printf("电脑赢了\n");
	else if (ret == 'Q')
		printf("平局了\n");
}
void test()
{
	int i = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("选择错误，重新选择");
			break;
		}
	} while (i);
}
int main()
{
	test();
	return 0;
}
