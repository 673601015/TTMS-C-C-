#include<iostream>
#include<fstream>
#include<Windows.h>
#include<string>
#include"caidan.h"
#include"shuru.h"
using namespace std;
extern int Login();
extern int Schedule_Menu();
extern int Seat_Menu();
extern HWND hWnd = GetConsoleWindow();
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
extern int Admin_Menu();
extern int JL_Menu();
extern int SPY_Menu();
int main()
{
	switch (Login())
	{
	case 1:
		Admin_Menu();
		break;
	case 2:
		JL_Menu();
		break;
	case 3:
		SPY_Menu();
		break;
	default:
		break;
	}
	system("pause");
	return 0;
}