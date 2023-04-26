#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define easy 10
void initboard(char board[ROWS][COLS], int rows, int cols, char cet);
void displayboard(char board[ROWS][COLS], int row, int col);
void setmine(char board[ROWS][COLS], int row, int col);
void findmine(char mine[ROWS][COLS], char board[ROWS][COLS], int row, int col);