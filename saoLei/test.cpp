#include"head1.h"

int main()
{
	srand((unsigned int)time(NULL));
	char mine[COLS][ROWS] = { 0 };//存放雷的信息
	char show[COLS][ROWS] = { 0 };//存放显示给用户看的棋盘
	
	menu(mine, show);
	return 0;
}