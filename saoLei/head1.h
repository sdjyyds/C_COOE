#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>
#include<stdbool.h>
#define LEI 10
#define COL 9
#define ROW 9
#define COLS COL+2
#define ROWS ROW+2


//初始化
void InitBoarad(char a[ROWS][COLS], int row, int col, char u);

//放雷
void setLei(char mine[ROWS][COLS], int row, int col);

//统计雷的个数（统计周围一圈雷的个数）
int getLeiCount(char mine[ROWS][COLS], int x, int y);

//排雷
void findLei(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, char a);

//展示
void displayBoard(char a[ROWS][COLS], int row, int col);
bool judge(int x, int y, int row, int col);
void menu(char mine[ROWS][COLS], char show[ROWS][COLS]);
bool paiLei(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int& count, int row, int col, char q);