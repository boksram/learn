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
	printf("****1����ʼ��Ϸ  0���˳���Ϸ****\n");
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
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("���������������\n");
			break;
		}
	} while (i);
}
int main()
{
	test();
	return 0;
}