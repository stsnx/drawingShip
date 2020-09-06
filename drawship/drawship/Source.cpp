#include<windows.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
void gotoxy(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void ship(int x, int y)
{
	gotoxy(x, y);
	std::cout << "<-0->";
}
int main()
{
	char ch = ' ';
	int x = 38, y = 20;
	ship(x, y);
	do {

		if (_kbhit())
		{
			ch = _getch();
			
			/*&&(x<81&&x>0)&&(y>0&&y<24)*/
			if (ch == 'a')  x--;
			if (ch == 'd' ) x++;
			if (ch == 'w')  y--;
			if (ch == 's') y++;
			if (x < 0) x = 0;
			if (x >= 80) x = 79;
			if (y < 0) y = 0;
			if (y >= 30) y = 29; 
			system("cls"); ship(x, y);
			fflush(stdin);
		}
		Sleep(50);


	} while (ch != 'x');
	return 0;
}