#include "game.h"

#define _CRT_SECURE_NO_WARNINGS 1

void initboard(char board[ROWS][COLS], int rows, int cols, char cet)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = cet;
		}
	}
}

void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row;i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void setmine(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = easy;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	int count = 0;
	count = mine[x - 1][y + 1]
		+ mine[x][y + 1]
		+ mine[x + 1][y + 1]
		+ mine[x - 1][y]
		+ mine[x + 1][y]
		+ mine[x - 1][y - 1]
		+ mine[x][y - 1]
		+ mine[x + 1][y - 1]
		- 8 * '0';
		return count;
}

void findmine(char mine[ROWS][COLS], char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	int win = 0;
	while (win<row*col-easy)
	{
		printf("请输入坐标\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col&&board[x][y]=='*')
		{
			if (mine[x][y] == '1')
			{
				printf("你被炸死了\n");
				displayboard(mine, row, col);
				break;
			}
			else
			{
				count = get_mine_count(mine, x, y);
				board[x][y] = count+'0';
				displayboard(board, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("输入值非法，重新输入:\n");
		}
	}
	if (win == row * col - easy)
	{
		printf("恭喜你排雷成功\n");
	}
}
