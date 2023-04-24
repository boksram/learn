#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include "game.h"
void menu()
{
	printf("################################\n");
	printf("####1����ʼ��Ϸ  0���˳���Ϸ####\n");
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
		printf("���Ӯ��\n");
	else if (ret == '#')
		printf("����Ӯ��\n");
	else if (ret == 'Q')
		printf("ƽ����\n");
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
			printf("�˳���Ϸ");
			break;
		default:
			printf("ѡ���������ѡ��");
			break;
		}
	} while (i);
}
int main()
{
	test();
	return 0;
}
