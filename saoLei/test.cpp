#include"head1.h"

int main()
{
	srand((unsigned int)time(NULL));
	char mine[COLS][ROWS] = { 0 };//����׵���Ϣ
	char show[COLS][ROWS] = { 0 };//�����ʾ���û���������
	
	menu(mine, show);
	return 0;
}