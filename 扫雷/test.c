#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char board[ROWS][COLS] = { 0 };
	initboard(mine, ROWS, COLS, '0');
	initboard(board, ROWS, COLS, '*');
	setmine(mine, ROW, COL);\
	//displayboard(mine, ROW, COL);
	displayboard(board, ROW, COL);
	findmine(mine, board, ROW, COL);
}
void menu()
{
	printf("********************************\n");
	printf("****1、开始游戏  0、退出游戏****\n");
	printf("********************************\n");
}
void test()
{
	int i = 0;
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
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，重新输入\n");
			break;
		}
	} while (i);
}
int main()
{
	test();
	return 0;
}