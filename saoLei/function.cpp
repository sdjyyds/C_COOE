#include"head1.h"
bool st[COLS][ROWS] = { 0 };
void InitBoarad(char a[ROWS][COLS], int row, int col, char u)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			a[i][j] = u;
}

void setLei(char mine[ROWS][COLS],int row, int col)
{
	int count = LEI;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			--count;
		}
	}
	displayBoard(mine, row, col);
}

int getLeiCount(char mine[ROWS][COLS],int x, int y)
{
	int k = (int)(mine[x - 1][y] + mine[x][y - 1] + mine[x - 1][y - 1] + mine[x - 1][y + 1] + mine[x][y + 1] + mine[x + 1][y - 1]
		+ mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0');
	return k;
}

void findLei(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col, char a)
{
	int count = 0;
	while (count + LEI < row * col)
	{
		int x = 0, y = 0;
		printf("���������׵����꣺x,y:\n");
		scanf("%d,%d", &x,&y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			bool s = paiLei(mine, show, x, y, count, row, col, a);
			if (s)
			{
				displayBoard(mine, row, col);
				displayBoard(show, row, col);
			}
			else break;
		}
		else printf("�������겻�Ϸ���\n");
	}
	if (count + LEI == row * col)
	{
		printf("���׳ɹ���\n");
		displayBoard(mine, row, col);
	}
}
bool judge(int x, int y,int row,int col)
{
	return (x >= 1 && x <= row && y >= 1 && y <= col);
	
}
bool paiLei(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int &count,int row,int col,char q)
{
	//printf("-1-1");
	if (x >= 1 && x <= row && y >= 1 && y <= col)
	{
		if (mine[x][y] == '1')
		{
			printf("�㱻ը���ˣ�\n");
			displayBoard(mine, row, col);
			return false;
		}
		else if (show[x][y] == q)
		{
			int u = getLeiCount(mine, x, y);
			st[x][y] = true;
			show[x][y] = u + '0';
			if(!u)
			{
				for (int a = -1; a < 2; a++)
					for (int b = -1; b < 2; b++)
						if (judge(x + a, y + b, row, col) && (!st[x+a][y+b]))
							paiLei(mine, show, x + a, y + b, count, row, col, q);
			}
			
			++count;
		}
		else printf("���������Ѿ�ѡ���ˣ�\n");
	}
	else
	{
		printf("�������겻�Ϸ���\n");
	}
	return true;
}
void displayBoard(char a[ROWS][COLS], int row, int col)
{
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
			printf("%c", a[i][j]);
		printf("\n");
	}
	printf("\n");
}

void menu(char mine[ROWS][COLS],char show[ROWS][COLS])
{
	int x = 0;
	do
	{
		int startf = 0;
		printf("***************1.��ʼ��Ϸ************************\n");
		printf("    ***********0.�˳���Ϸ**************\n");
		printf("�����룺");
		scanf("%d", &startf);
		if (startf)
		{
			char u = '*';
			InitBoarad(mine, ROWS, COLS, '0');
			InitBoarad(show, ROWS, COLS, u);
			displayBoard(show, ROW, COL);
			setLei(mine, ROW, COL);
			findLei(mine,show,ROW, COL, u);
			printf("�������Ƿ������1������0���˳�");
			scanf("%d", &x);
		}
		else
		{
			printf("��Ϸ������");
			break;
		}
	} while (x);
}