#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<direct.h>
#include"shuru.h"
#include"caidan.h"
#define Ticket_Name_DAT ".\\Ticket\\Tick_Date_Name.dat"
#define Ticket_Dir ".\\Ticket\\"
#define STUDIO_DAT ".\\PerformHotel.dat"
#define SCHDULEDAT ".\\Schdule.dat"
#define Seat_Dir ".\\Seat\\"
#define SALE_DAT ".\\Sale\\"
using namespace std;
extern int Search_Studio(string Studio_ID);
extern int Schdule_Serch(string Schdule_ID);
extern int Search_Seat_Name(string Studio_ID);
extern int Search_Seat_ID(string Studio_ID, string Seat_Line, string Seat_Column);
extern HWND hWnd;
extern HANDLE hOut;
int Studio_Line, Studio_Column;
struct Schdule_Data
{
	string Schdule_ID;
	string Play_ID;
	string Perform_ID;
	string Play_Date;
	string Play_Time;
	string Play_Ticket;
}Schdule_Public;

struct Ticket_Data
{
	string Ticket_ID;
	string Schdule_ID;
	int Seat_ID;
	float Price;
	char Sta;
}Ticket_Public;

int Get_Schdule(string Schdule_ID)
{
	if (!Schdule_Serch(Schdule_ID))
	{
		MessageBox(NULL, L"管理员未添加此演出计划", L"提示", NULL);
		return 0;
	}
	else
	{
		FILE *fp;
		char Str_Tmp[100];
		if (!(fp = fopen(SCHDULEDAT, "r")))
		{
			MessageBox(hWnd, L"打开演出计划文件失败", L"提示", NULL);
			fclose(fp);
			return 0;
		}
		else
		{
			while (1)
			{
				fscanf(fp, "Schdule_ID=%s\n", Str_Tmp);
				Schdule_Public.Schdule_ID = Str_Tmp;
				fscanf(fp, "Play_ID=%s\n", Str_Tmp);
				Schdule_Public.Play_ID = Str_Tmp;
				fscanf(fp, "Perform_ID=%s\n", Str_Tmp);
				Schdule_Public.Perform_ID = Str_Tmp;
				fscanf(fp, "Play_Date=%s\n", Str_Tmp);
				Schdule_Public.Play_Date = Str_Tmp;
				fscanf(fp, "Play_Time=%s\n", Str_Tmp);
				Schdule_Public.Play_Time = Str_Tmp;
				fscanf(fp, "Play_Ticket=%s\n", Str_Tmp);
				Schdule_Public.Play_Ticket = Str_Tmp;
				if (Schdule_Public.Schdule_ID == Schdule_ID)
				{
					fclose(fp);
					return 1;
				}
			}
		}
	}

}

int Init_Ticket(string Studio_ID,float Price)
{
	if (!Search_Seat_Name(Studio_ID))
	{
		MessageBox(hWnd, L"演出厅座位尚未初始化，请联系系统管理员", L"提示", NULL);
		return 0;
	}
	else
	{
		string Seat_Dat_Name = Seat_Dir + Studio_ID + ".dat";
		string Ticket_Dat_Name = Ticket_Dir + Schdule_Public.Schdule_ID + ".dat";
		FILE *fp;
		if (!(fp = fopen(Seat_Dat_Name.c_str(),"r")))
		{
			MessageBox(hWnd, L"打开座位文件失败", L"", NULL);
			return 0;
		}
		else
		{
			ofstream Out_Init_Ticket(Ticket_Dat_Name);
			char Str_Tmp[100];
			Ticket_Public.Schdule_ID = Schdule_Public.Schdule_ID;
			Ticket_Public.Price = Price;
			for (int i = 1; !feof(fp); ++i)
			{
				fscanf(fp, "Seat_ID=%d\n", &Ticket_Public.Seat_ID);
				if (feof(fp))
				{
					fclose(fp);
					Out_Init_Ticket.close();
					return 1;
				}
				fgets(Str_Tmp, 100, fp);
				if (feof(fp))
				{
					fclose(fp);
					Out_Init_Ticket.close();
					return 1;
				}
				fgets(Str_Tmp, 100, fp);
				fscanf(fp, "Seat_Sta=%c\n", &Ticket_Public.Sta);
				Out_Init_Ticket << "Ticket_ID=" << i << endl;
				Out_Init_Ticket << "Schdule_ID=" << Ticket_Public.Schdule_ID << endl;
				Out_Init_Ticket << "Seat_ID=" << Ticket_Public.Seat_ID << endl;
				Out_Init_Ticket << "Price=" << Ticket_Public.Price << endl;
				Out_Init_Ticket << "Sta=" << Ticket_Public.Sta << endl;
			}
			fclose(fp);
			Out_Init_Ticket.close();
			return 1;
		}
	}
}

int Creat_Ticket()
{
	ifstream Get_Ticket_Name(Ticket_Name_DAT);
	if (!Get_Ticket_Name.is_open())
	{
		_mkdir(".\\Ticket");
		ofstream Creat_File(Ticket_Name_DAT);
		Creat_File.close();
	}
	Get_Ticket_Name.close();
	string Str, Price;
	shuru C_Ticket;
	C_Ticket.tishi("********************************添加演出门票\
*******************************\n\n\t\t\t请输入演出计划ID:");
	Str = C_Ticket.shuzi();
	if (Get_Schdule(Str))
	{
		C_Ticket.tishi("********************************添加演出门票\
*******************************\n\n\t\t\t请输入票价:");
		Price = C_Ticket.shuziandxiaoshu();
		Init_Ticket(Schdule_Public.Perform_ID, atof(Price.c_str()));
	}
	else
	{
		return 0;
	}
	return 0;
}

int Get_Studio_Line_And_Colum(string Studio_ID)
{
	FILE *fp;
	char Str_Tmp[100];
	string Str_strTmp;
	if (fp = fopen(STUDIO_DAT, "r"))
	{
		while (!feof(fp))
		{
			Str_strTmp = "";
			fscanf(fp, "ID=%s\n", Str_Tmp);
			Str_strTmp += Str_Tmp;
			fgets(Str_Tmp, 100, fp);
			fscanf(fp, "SeatLine=%d\n", &Studio_Line);
			fscanf(fp, "SeatColumn=%d\n", &Studio_Column);
			if (Str_strTmp == Studio_ID)
			{
				return 1;
			}
		}
		return 0;
	}
}

int Show_Ticket_DAT(string Schdule_ID)
{
	if (!Get_Schdule(Schdule_ID))return 0;
	if (!Get_Studio_Line_And_Colum(Schdule_Public.Perform_ID))return 0;
	string Ticket_Name_Tmp = Ticket_Dir+Schdule_ID + ".dat";
	const int Seat_Num = Studio_Line*Studio_Column;
	FILE *fp;
	if (!(fp = fopen(Ticket_Name_Tmp.c_str(),"r")))
	{
		MessageBox(hWnd, L"打开票务信息失败!", L"提示", NULL);
		return 0;
	}
	else
	{
		Ticket_Data *Ticket_Pointer = new Ticket_Data[Seat_Num];
		char Str_Tmp[100];
		for (int i = 0; i < Seat_Num; ++i)
		{
			fscanf(fp, "Ticket_ID=%s\n", Str_Tmp);
			Ticket_Pointer[i].Ticket_ID = Str_Tmp;
			fscanf(fp, "Schdule_ID=%s\n", Str_Tmp);
			Ticket_Pointer[i].Schdule_ID = Str_Tmp;
			fscanf(fp, "Seat_ID=%d\n", &Ticket_Pointer[i].Seat_ID);
			fscanf(fp, "Price=%f\n", &Ticket_Pointer[i].Price);
			fscanf(fp, "Sta=%c\n", &Ticket_Pointer[i].Sta);
		}
		cout << "   ";
		for (int m = 0; m < Studio_Column; ++m)
		{
			cout << m + 1;
			if ((m + 1) > 9)
			{
				cout << " ";
			}
			else
			{
				cout << "  ";
			}
		}
		for (int i = 0; i < Seat_Num; ++i)
		{
			
			if ((i % Studio_Column) == 0)
			{
				cout <<endl<< ((i / Studio_Column)+1);
				if (((i / Studio_Column) + 1) > 9)cout << " ";
				else cout << "  ";
			}
			if (Ticket_Pointer[i].Sta == 'Y')
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
				cout << "#  ";
				SetConsoleTextAttribute(hOut, FOREGROUND_RED |
					FOREGROUND_BLUE |
					FOREGROUND_GREEN);
			}
			else if (Ticket_Pointer[i].Sta == 'S')
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << "#  ";
				SetConsoleTextAttribute(hOut, FOREGROUND_RED |
					FOREGROUND_BLUE |
					FOREGROUND_GREEN);
			}
			else 
			{
				cout << "   ";
			}
		}
		cout << endl;
		system("pause");
		delete[]Ticket_Pointer;
		fclose(fp);

	}
}
//函数返回值为座位ID↓
int Sale_Ticket(string Schdule_ID)
{
	if (!Get_Schdule(Schdule_ID))return 0;
	if (!Get_Studio_Line_And_Colum(Schdule_Public.Perform_ID))return 0;
	string Ticket_Name_Tmp = Ticket_Dir + Schdule_ID + ".dat";
	const int Seat_Num = Studio_Line*Studio_Column;
	FILE *fp;
	if (!(fp = fopen(Ticket_Name_Tmp.c_str(), "r")))
	{
		MessageBox(hWnd, L"打开票务信息失败!", L"提示", NULL);
		fclose(fp);
		return 0;
	}
	else
	{
		Ticket_Data *Ticket_Pointer = new Ticket_Data[Seat_Num];
		char Str_Tmp[100];
		for (int i = 0; i < Seat_Num; ++i)
		{
			fscanf(fp, "Ticket_ID=%s\n", Str_Tmp);
			Ticket_Pointer[i].Ticket_ID = Str_Tmp;
			fscanf(fp, "Schdule_ID=%s\n", Str_Tmp);
			Ticket_Pointer[i].Schdule_ID = Str_Tmp;
			fscanf(fp, "Seat_ID=%d\n", &Ticket_Pointer[i].Seat_ID);
			fscanf(fp, "Price=%f\n", &Ticket_Pointer[i].Price);
			fscanf(fp, "Sta=%c\n", &Ticket_Pointer[i].Sta);
		}
		string Line_Tmp, Column_Tmp;
		while (1)
		{
			cout << "请输入出售的票行标:";
			cin >> Line_Tmp;
			if (atoi(Line_Tmp.c_str()) > Studio_Line)
			{
				MessageBox(hWnd, L"行数过长", L"提示", NULL);
			}
			else if (atoi(Line_Tmp.c_str()) <= 0)
			{
				MessageBox(hWnd, L"行数过短", L"提示", NULL);
			}
			else
			{

			}
			{
				break;
			}
		}
		while (1)
		{
			cout << "请输入出售的票列标:";
			cin >> Column_Tmp;
			if (atoi(Column_Tmp.c_str()) > Studio_Column)
			{
				MessageBox(hWnd, L"列数过长", L"提示", NULL);
			}
			else if (atoi(Column_Tmp.c_str()) <= 0)
			{
				MessageBox(hWnd, L"列数过短", L"提示", NULL);
			}
			else
			{
				break;
			}
		}
		int Seat_ID_Tmp = Search_Seat_ID(Schdule_Public.Perform_ID, Line_Tmp, Column_Tmp);
		if (Seat_ID_Tmp == 0)
		{
			MessageBox(NULL, L"发生未知错误", L"提示", NULL);
			delete[]Ticket_Pointer;
			fclose(fp);
			return 0;
		}
		for (int i = 0; i < Seat_Num; ++i)
		{
			if (Seat_ID_Tmp == Ticket_Pointer[i].Seat_ID)
			{
				if (Ticket_Pointer[i].Sta == 'Y')
				{
					Ticket_Pointer[i].Sta = 'S';
					fclose(fp);
					ofstream Out_Ticket_Dat(Ticket_Name_Tmp);
					for (int m = 0; m < Seat_Num; ++m)
					{
						Out_Ticket_Dat << "Ticket_ID=" << Ticket_Pointer[m].Ticket_ID << endl;
						Out_Ticket_Dat << "Schdule_ID=" << Ticket_Pointer[m].Schdule_ID << endl;
						Out_Ticket_Dat << "Seat_ID=" << Ticket_Pointer[m].Seat_ID << endl;
						Out_Ticket_Dat << "Price=" << Ticket_Pointer[m].Price << endl;
						Out_Ticket_Dat << "Sta=" << Ticket_Pointer[m].Sta << endl;
					}
					Out_Ticket_Dat.close();
					delete[]Ticket_Pointer;
					MessageBox(hWnd, L"修改成功", L"提示", NULL);
					return Seat_ID_Tmp;
				}
				else if (Ticket_Pointer[i].Sta == 'S')
				{
					delete[]Ticket_Pointer;
					fclose(fp);
					MessageBox(hWnd, L"此票已经出售", L"提示", NULL);
					return 0;
				}
				else
				{
					delete[]Ticket_Pointer;
					fclose(fp);
					MessageBox(hWnd, L"此坐标未设置座位或此票处于无法出售状态", L"提示", NULL);
					return 0;
				}
			}
		}
		delete[]Ticket_Pointer;
		fclose(fp);

	}
}

int Return_Ticket(string Schdule_ID)
{
	if (!Get_Schdule(Schdule_ID))return 0;
	if (!Get_Studio_Line_And_Colum(Schdule_Public.Perform_ID))return 0;
	string Ticket_Name_Tmp = Ticket_Dir + Schdule_ID + ".dat";
	const int Seat_Num = Studio_Line*Studio_Column;
	FILE *fp;
	if (!(fp = fopen(Ticket_Name_Tmp.c_str(), "r")))
	{
		MessageBox(hWnd, L"打开票务信息失败!", L"提示", NULL);
		fclose(fp);
		return 0;
	}
	else
	{
		Ticket_Data *Ticket_Pointer = new Ticket_Data[Seat_Num];
		char Str_Tmp[100];
		for (int i = 0; i < Seat_Num; ++i)
		{
			fscanf(fp, "Ticket_ID=%s\n", Str_Tmp);
			Ticket_Pointer[i].Ticket_ID = Str_Tmp;
			fscanf(fp, "Schdule_ID=%s\n", Str_Tmp);
			Ticket_Pointer[i].Schdule_ID = Str_Tmp;
			fscanf(fp, "Seat_ID=%d\n", &Ticket_Pointer[i].Seat_ID);
			fscanf(fp, "Price=%f\n", &Ticket_Pointer[i].Price);
			fscanf(fp, "Sta=%c\n", &Ticket_Pointer[i].Sta);
		}
		string Line_Tmp, Column_Tmp;
		while (1)
		{
			cout << "请输入出售的票行标:";
			cin >> Line_Tmp;
			if (atoi(Line_Tmp.c_str()) > Studio_Line)
			{
				MessageBox(hWnd, L"行数过长", L"提示", NULL);
			}
			else if (atoi(Line_Tmp.c_str()) <= 0)
			{
				MessageBox(hWnd, L"行数过短", L"提示", NULL);
			}
			else
			{

			}
			{
				break;
			}
		}
		while (1)
		{
			cout << "请输入出售的票列标:";
			cin >> Column_Tmp;
			if (atoi(Column_Tmp.c_str()) > Studio_Column)
			{
				MessageBox(hWnd, L"列数过长", L"提示", NULL);
			}
			else if (atoi(Column_Tmp.c_str()) <= 0)
			{
				MessageBox(hWnd, L"列数过短", L"提示", NULL);
			}
			else
			{
				break;
			}
		}
		int Seat_ID_Tmp = Search_Seat_ID(Schdule_Public.Perform_ID, Line_Tmp, Column_Tmp);
		if (Seat_ID_Tmp == 0)
		{
			MessageBox(NULL, L"发生未知错误", L"提示", NULL);
			delete[]Ticket_Pointer;
			fclose(fp);
			return 0;
		}
		for (int i = 0; i < Seat_Num; ++i)
		{
			if (Seat_ID_Tmp == Ticket_Pointer[i].Seat_ID)
			{
				if (Ticket_Pointer[i].Sta == 'S')
				{
					Ticket_Pointer[i].Sta = 'Y';
					fclose(fp);
					ofstream Out_Ticket_Dat(Ticket_Name_Tmp);
					for (int m = 0; m < Seat_Num; ++m)
					{
						Out_Ticket_Dat << "Ticket_ID=" << Ticket_Pointer[m].Ticket_ID << endl;
						Out_Ticket_Dat << "Schdule_ID=" << Ticket_Pointer[m].Schdule_ID << endl;
						Out_Ticket_Dat << "Seat_ID=" << Ticket_Pointer[m].Seat_ID << endl;
						Out_Ticket_Dat << "Price=" << Ticket_Pointer[m].Price << endl;
						Out_Ticket_Dat << "Sta=" << Ticket_Pointer[m].Sta << endl;
					}
					Out_Ticket_Dat.close();
					delete[]Ticket_Pointer;
					MessageBox(hWnd, L"修改成功", L"提示", NULL);
					return Seat_ID_Tmp;
				}
				else if (Ticket_Pointer[i].Sta == 'Y')
				{
					delete[]Ticket_Pointer;
					fclose(fp);
					MessageBox(hWnd, L"此票尚未出售", L"提示", NULL);
					return 0;
				}
				else
				{
					delete[]Ticket_Pointer;
					fclose(fp);
					MessageBox(hWnd, L"此票处于无法修改状态", L"提示", NULL);
					return 0;
				}
			}
		}
		delete[]Ticket_Pointer;
		fclose(fp);

	}
}

int Ticket_Menu()
{
	xuanzecaidan Ticket_Menu_Tmp;
	Ticket_Menu_Tmp.tianjiacaidan("*******************************************票务管理************************\n", 1);
	Ticket_Menu_Tmp.tianjiacaidan("出售票");
	Ticket_Menu_Tmp.tianjiacaidan("退票");
	Ticket_Menu_Tmp.tianjiacaidan("返回上级");
	string ceshi;
	while (1)
	{
		switch (Ticket_Menu_Tmp.jiantoucaidan())
		{
		case 1:
			cout << "需要出售票的演出计划ID:";
			cin >> ceshi;
			Show_Ticket_DAT(ceshi);
			Sale_Ticket(ceshi);
			break;
		case 2:
			cout << "需要退票的演出计划ID:";
			cin >> ceshi;
			Show_Ticket_DAT(ceshi);
			Return_Ticket(ceshi);
			break;
		default:
			return 0;
		}
	}
}