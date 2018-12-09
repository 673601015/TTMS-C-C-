#include<iostream>
#include<fstream>
#include<direct.h>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include"caidan.h"
#include"shuru.h"
#define STUDIO_DAT ".\\PerformHotel.dat"
#define Seat_Name_Dat ".\\Seat\\Seat_Name.dat"
#define Seat_Dir_Tmp ".\\SeatTmp\\"
#define Seat_Dir ".\\Seat\\"
extern HWND hWnd;
extern HANDLE hOut;
char fun(char a)
{
	if (a >= 'a'&&a <= 'z')return (a + ('A' - 'a'));
	else return a;
}
//检测演出厅存在性↓
int Search_Studio(string Studio_ID)
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
			fgets(Str_Tmp, 100, fp);
			fgets(Str_Tmp, 100, fp);
			if (Str_strTmp == Studio_ID)
			{
				return 1;
			}
		}
		return 0;
	}
}
//检测演出厅名字存在性↓
int Search_Seat_Name(string Studio_ID)
{
	Studio_ID = Studio_ID + ".dat";
	string Studio_ID_Get;
	ifstream GetStudioID(Seat_Name_Dat);
	while (!GetStudioID.eof())
	{
		getline(GetStudioID, Studio_ID_Get);
		if (Studio_ID_Get == Studio_ID)
		{
			return 1;
		}
	}
	return 0;
}
//初始化座位↓
int Init_Seat(string Studio_ID)
{
//	string Studio_ID_Tmp;
	FILE *fp;
	char Str_Tmp[100];
	string Str_strTmp;
	int SeatLine, SeatColumn;
	if (fp = fopen(STUDIO_DAT, "r"))
	{
		while (!feof(fp))
		{
			Str_strTmp = "";
			fscanf(fp, "ID=%s\n", Str_Tmp);
			Str_strTmp += Str_Tmp;
			if (Str_strTmp == Studio_ID)
			{
//				Studio_ID_Tmp = Str_strTmp;
				fgets(Str_Tmp, 100, fp);
				fscanf(fp, "SeatLine=%d\n", &SeatLine);
				fscanf(fp, "SeatColumn=%d\n", &SeatColumn);
				break;
			}
			fgets(Str_Tmp, 100, fp);
			fgets(Str_Tmp, 100, fp);
			fgets(Str_Tmp, 100, fp);
		}
	}
	fclose(fp);
	Studio_ID = Seat_Dir+Studio_ID + ".dat";
	ofstream Out_Seat(Studio_ID);
	for (int i = 1,m=1; i <= SeatLine; ++i)
	{
		for (int j = 1; j <= SeatColumn; ++j)
		{
			Out_Seat << "Seat_ID=" << m << endl;
			Out_Seat << "Seat_Line=" << i << endl;
			Out_Seat << "Seat_Column=" << j << endl;
			Out_Seat << "Seat_Sta=Y" << endl;
			++m;
		}
	}
	Out_Seat.close();
	return 1;
}
//清理座位数据文件↓
int Clean_Seat_Dat()
{
	system("cls");
	_mkdir(".\\SeatTmp");
	string Seat_Name,Seat_Name_Tmp;
	ifstream Get_Seat_Name(Seat_Name_Dat);
	while (!Get_Seat_Name.eof())
	{
		getline(Get_Seat_Name, Seat_Name);
		Seat_Name_Tmp = Seat_Dir_Tmp + Seat_Name;
		Seat_Name = ".\\Seat\\" + Seat_Name;
		rename(Seat_Name.c_str(), Seat_Name_Tmp.c_str());
	}
	Get_Seat_Name.close();
	rename(Seat_Name_Dat,".\\SeatTmp\\Seat_Name.dat" );
	system("rd /s/q .\\Seat");
	rename("SeatTmp", "Seat");
	system("pause");
	return 0;
}
//显示修改演出厅座位信息↓
int Studio_Seat_Change(string Studio_ID)
{
	
	if (!Search_Studio(Studio_ID))
	{
		MessageBox(hWnd, L"没有此演出厅", L"提示", NULL);
		return 0;
	}
	else
	{
		if (!Search_Seat_Name(Studio_ID))
		{
			Init_Seat(Studio_ID);
			string ID_DATNAME_TMP =Studio_ID + ".dat";
			ofstream Out_IDNAME(Seat_Name_Dat, ios::app);
			Out_IDNAME << ID_DATNAME_TMP<<endl;
			Out_IDNAME.close();
		}
		
		int SeatLine, SeatColumn;
		string Str_strTmp;
		char Str_Tmp[100];
		FILE *fp;
		if (fp = fopen(STUDIO_DAT, "r"))
		{
			while (!feof(fp))
			{
				Str_strTmp = "";
				fscanf(fp, "ID=%s\n", Str_Tmp);
				Str_strTmp += Str_Tmp;
				if (Str_strTmp == Studio_ID)
				{
					//				Studio_ID_Tmp = Str_strTmp;
					fgets(Str_Tmp, 100, fp);
					fscanf(fp, "SeatLine=%d\n", &SeatLine);
					fscanf(fp, "SeatColumn=%d\n", &SeatColumn);
					break;
				}
				fgets(Str_Tmp, 100, fp);
				fgets(Str_Tmp, 100, fp);
				fgets(Str_Tmp, 100, fp);
			}
		}
		fclose(fp);

		int **Seat_ID = new int*[SeatLine*SeatColumn];
		for (int i = 0; i < SeatLine; ++i)
		{
			Seat_ID[i] = new int[SeatColumn];
		}
		char **Seat_Sta = new char*[SeatLine];
		for (int i = 0; i < SeatLine; ++i)
		{
			Seat_Sta[i] = new char[SeatColumn];
		}
		char Sta_Tmp[100];
		int ID_Tmp;
		string Seat_ID_Dat_Tmp;
		Seat_ID_Dat_Tmp = Seat_Dir + Studio_ID + ".dat";
		fp = fopen(Seat_ID_Dat_Tmp.c_str(), "r");
		for (int i=0;i<SeatLine;++i)
		{
			for (int ii = 0; ii < SeatColumn; ++ii)
			{
				fscanf(fp, "Seat_ID=%d\n", &Seat_ID[i][ii]);
				fgets(Sta_Tmp, 100, fp);
				fgets(Sta_Tmp, 100, fp);
				fscanf(fp, "Seat_Sta=%c\n", &Seat_Sta[i][ii]);
			}
		}
		fclose(fp);
		shuru Seat_Input;
		int Line_Tmp, Column_Tmp;
		string Sta_Tmp_Input;
		char ch;
		system("cls");
		cout << "   ";
		for (int i = 1; i <= SeatColumn; ++i)
		{
			cout << i;
			if (i > 9)
			{
				cout << " ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
		for (int i = 0; i < SeatLine; ++i)
		{
			cout << i + 1;
			if ((i + 1) > 9)
			{
				cout << " ";
			}
			else
			{
				cout << "  ";
			}
			for (int j = 0; j < SeatColumn; ++j)
			{
				if (Seat_Sta[i][j] == 'Y')
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
					cout << "#  ";
					SetConsoleTextAttribute(hOut, FOREGROUND_RED|
					                              FOREGROUND_BLUE|
					                              FOREGROUND_GREEN );
				}
				else if (Seat_Sta[i][j] == 'N')
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED |
						FOREGROUND_BLUE);
					cout << "X  ";
					SetConsoleTextAttribute(hOut, FOREGROUND_RED |
						FOREGROUND_BLUE |
						FOREGROUND_GREEN);
				}
				else if (Seat_Sta[i][j] == 'S')
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "#  ";
					SetConsoleTextAttribute(hOut, FOREGROUND_RED |
						FOREGROUND_BLUE |
						FOREGROUND_GREEN);
				}
			}
			cout << endl;
		}
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
		cout << "#  ";
		SetConsoleTextAttribute(hOut, FOREGROUND_RED |
			FOREGROUND_BLUE |
			FOREGROUND_GREEN);
		cout << "座位正常出售" << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_RED |
			FOREGROUND_BLUE);
		cout << "X  ";
		SetConsoleTextAttribute(hOut, FOREGROUND_RED |
			FOREGROUND_BLUE |
			FOREGROUND_GREEN);
		cout << "座位无法使用" << endl;
		cout << "************************************选择功能************************************" << endl
			<< "\t\t\t\t1.修改座位信息" << endl
			<< "\t\t\t\t0.返回上级" << endl;
		while ((ch = _getch())!='0')
		{
			ofstream Out_Seat_Change(Seat_ID_Dat_Tmp);
/*			for (int i = 0; i < SeatLine; ++i)
			{
				for (int j = 0; j < SeatColumn; ++j)
				{
					Out_Seat_Change << "Seat_ID=" << Seat_ID[i][j] << endl;
					Out_Seat_Change << "Seat_Sta=" << Seat_Sta[i][j] << endl;
				}
			}
			Out_Seat_Change.close();
			*/
			switch (ch)
			{
			case '1':
				while (1)
				{
					Seat_Input.tishi("**********************************修改座位信息**********************************\n\n\t\t\t\t请输入[行数]:");
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
					if ((Line_Tmp = atoi(Seat_Input.shuzi().c_str())) > SeatLine)
					{
						MessageBox(hWnd, L"输入的行数太长", L"提示", NULL);
						continue;
					}
					Seat_Input.tishi("**********************************修改座位信息*********************************\n\n\t\t\t\t请输入[列数]:");
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
					if ((Column_Tmp = atoi(Seat_Input.shuzi().c_str())) > SeatColumn)
					{
						MessageBox(hWnd, L"输入的列数太长", L"提示", NULL);
						continue;
					}
					SetConsoleTextAttribute(hOut, FOREGROUND_RED |
						FOREGROUND_BLUE |
						FOREGROUND_GREEN);
					break;
				}
				while (1)
				{
					Seat_Input.tishi("**********************************修改座位信息\
*********************************\n\n修改提示： Y正常 N无法使用 \n\t\t\t\t座位状态修改为:");
					Sta_Tmp_Input = Seat_Input.zimu();
					if (Sta_Tmp_Input.size() > 1)
					{
						continue;
					}
					else
					{
						break;
					}
				}
				Line_Tmp--;
				Column_Tmp--;
				if (fun(Sta_Tmp_Input[0]) == 'Y' || fun(Sta_Tmp_Input[0]) == 'N')
				{
					Seat_Sta[Line_Tmp][Column_Tmp] = Sta_Tmp_Input[0];
				}
				for (int i = 0; i < SeatLine; ++i)
				{
					for (int j = 0; j < SeatColumn; ++j)
					{
						Out_Seat_Change << "Seat_ID=" << Seat_ID[i][j] << endl;
						Out_Seat_Change << "Seat_Line=" << (i + 1) << endl;
						Out_Seat_Change << "Seat_Column=" << (j + 1) << endl;
						Out_Seat_Change << "Seat_Sta=" << Seat_Sta[i][j] << endl;
					}
				}
				Out_Seat_Change.close();
				break;
			case '0':
				for (int i = 0; i < SeatLine; ++i)
				{
					for (int j = 0; j < SeatColumn; ++j)
					{
						Out_Seat_Change << "Seat_ID=" << Seat_ID[i][j] << endl;
						Out_Seat_Change << "Seat_Line=" << (i + 1) << endl;
						Out_Seat_Change << "Seat_Column=" << (j + 1) << endl;
						Out_Seat_Change << "Seat_Sta=" << Seat_Sta[i][j] << endl;
					}
				}
				for (int i = 0; i < SeatLine; ++i)
				{
					delete[] Seat_ID[i];
				}
				for (int i = 0; i < SeatLine; ++i)
				{
					delete[]Seat_Sta[i];
				}
				Out_Seat_Change.close();
				return 1;
			}
			system("cls");
			cout << "   ";
			for (int i = 1; i <= SeatColumn; ++i)
			{
				cout << i;
				if (i > 9)
				{
					cout << " ";
				}
				else
				{
					cout << "  ";
				}
			}
			cout << endl;
			for (int i = 0; i < SeatLine; ++i)
			{
				cout << i + 1;
				if ((i + 1) > 9)
				{
					cout << " ";
				}
				else
				{
					cout << "  ";
				}
				for (int j = 0; j < SeatColumn; ++j)
				{
					if (Seat_Sta[i][j] == 'Y')
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						cout << "#  ";
						SetConsoleTextAttribute(hOut, FOREGROUND_RED |
							FOREGROUND_BLUE |
							FOREGROUND_GREEN);
					}
					else if (Seat_Sta[i][j] == 'N')
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED |
							FOREGROUND_BLUE);
						cout << "X  ";
						SetConsoleTextAttribute(hOut, FOREGROUND_RED |
							FOREGROUND_BLUE |
							FOREGROUND_GREEN);
					}
					else if (Seat_Sta[i][j] == 'S')
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << "#  ";
						SetConsoleTextAttribute(hOut, FOREGROUND_RED |
							FOREGROUND_BLUE |
							FOREGROUND_GREEN);
					}
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
			cout << "#  ";
			SetConsoleTextAttribute(hOut, FOREGROUND_RED |
				FOREGROUND_BLUE |
				FOREGROUND_GREEN);
			cout << "座位正常出售" << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_RED |
				FOREGROUND_BLUE);
			cout << "X  ";
			SetConsoleTextAttribute(hOut, FOREGROUND_RED |
				FOREGROUND_BLUE |
				FOREGROUND_GREEN);
			cout << "座位无法使用"<<endl;
			cout << "************************************选择功能************************************" << endl
				<< "\t\t\t\t1.修改座位信息" << endl
				<< "\t\t\t\t0.返回上级" << endl;
		}
	}
	return 1;
}
//删除演出厅座位信息↓
int Del_Studio_Seat(string Studio_ID)
{
	if (Search_Seat_Name(Studio_ID))
	{
		Studio_ID =Studio_ID + ".dat";
		string Name_Str;
		ifstream Get_Name_Dat(Seat_Name_Dat);
		ofstream Out_Name_Dat("SeatNameTmp.dat");
		while (!Get_Name_Dat.eof())
		{
			getline(Get_Name_Dat, Name_Str);
			if (Name_Str == Studio_ID)
			{
				continue;
			}
			else if(Name_Str.size()>3)
			{
				Out_Name_Dat << Name_Str << endl;
			}
		}
		Get_Name_Dat.close();
		Out_Name_Dat.close();
		remove(Seat_Name_Dat);
		rename("SeatNameTmp.dat", Seat_Name_Dat);
	}

	return 1;
}
//根据演出厅行列找座位ID
int Search_Seat_ID(string Studio_ID,string Seat_Line, string Seat_Column)
{
	if (!Search_Seat_Name(Studio_ID))
	{
		MessageBox(hWnd, L"演出厅座位尚未初始化,请联系管理员", L"提示", NULL);
		return 0;
	}
	else
	{
		FILE *fp;
		string Seat_Dat_Name_Tmp = Seat_Dir + Studio_ID + ".dat";
		if (!(fp = fopen(Seat_Dat_Name_Tmp.c_str(), "r")))
		{
			MessageBox(hWnd, L"打开座位数据失败", L"提示", NULL);
			fclose(fp);
			return 0;
		}
		else
		{
			int Seat_ID;
			string Line_Tmp, Column_Tmp;
			char Str_Tmp[100];
			while (1)
			{
				fscanf(fp, "Seat_ID=%d\n", &Seat_ID);
				fscanf(fp, "Seat_Line=%s\n", Str_Tmp);
				Line_Tmp = Str_Tmp;
				fscanf(fp, "Seat_Column=%s\n", Str_Tmp);
				Column_Tmp = Str_Tmp;
				if (Line_Tmp == Seat_Line&&Column_Tmp == Seat_Column)
				{
					fclose(fp);
					return Seat_ID;
				}
				fscanf(fp, "Seat_Sta=%s\n", Str_Tmp);
			}
			fclose(fp);
		}
	}
}
int Seat_Menu()
{
	ifstream GetSeatName(Seat_Name_Dat);
	if (!GetSeatName)
	{
		_mkdir("Seat");
		ofstream MkSeatName(Seat_Name_Dat);
		MkSeatName.close();
	}
	GetSeatName.close();
	xuanzecaidan Seat_menu;
	Seat_menu.tianjiacaidan("******************************座位管理************************************\n", 1);
	Seat_menu.tianjiacaidan("清理座位数据文件");
	Seat_menu.tianjiacaidan("查看和修改演出厅座位信息");
	Seat_menu.tianjiacaidan("删除演出厅");
	Seat_menu.tianjiacaidan("返回上一级");
	string Studio_ID_Tmp;
	shuru Studio_ID_Input_Tmp;

	while (1)
	{
		switch (Seat_menu.jiantoucaidan())
		{
		case 1:
			Clean_Seat_Dat();
			break;
		case 2:
			Studio_ID_Input_Tmp.tishi("请输入需要修改的演出厅ID:");
			Studio_ID_Tmp = Studio_ID_Input_Tmp.zimuandshuzi();
			Studio_Seat_Change(Studio_ID_Tmp);
			break;
		case 3:
			Studio_ID_Input_Tmp.tishi("请输入需要修改的演出厅ID:");
			Studio_ID_Tmp = Studio_ID_Input_Tmp.zimuandshuzi();
			Del_Studio_Seat(Studio_ID_Tmp);
			Clean_Seat_Dat();
			break;
		default:
			return 0;
		}
	}
}