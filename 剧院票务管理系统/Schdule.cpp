#include<iostream>
#include"caidan.h"
#include<string>
#include<stdio.h>
#include<fstream>
#include"shuru.h"
#define SCHDULEDAT ".\\Schdule.dat"

#define GESHI_SIZE 14
using namespace std;
extern HWND hWnd;
struct Schdule_inf
{
	string Schdule_ID;
	string Play_ID;
	string Perform_ID;
	string Play_Date;
	string Play_Time;
	string Play_Ticket;
};
//检测演出计划ID存在性↓
int Schdule_Serch(string Schdule_ID)
{
	FILE *fp;
	string Schdule_ID_Tmp;
	char strtmp[100];
	if ((fp = fopen(SCHDULEDAT, "r")))
	{
		while (!feof(fp))
		{
			Schdule_ID_Tmp = "";
			fscanf(fp, "Schdule_ID=%s", strtmp);
			Schdule_ID_Tmp += strtmp;
			if (Schdule_ID_Tmp == Schdule_ID)
			{
				fclose(fp);
				return 1;
			}
			fgets(strtmp, 100, fp);
		}

	}
	fclose(fp);
	return 0;
}
//查看当前演出计划↓
int Schdule_Show()
{
	ifstream Init_Schdule(SCHDULEDAT);
	if (!Init_Schdule.is_open())
	{
		ofstream Creat_Schdule(SCHDULEDAT);
		Creat_Schdule.close();
	}
	Init_Schdule.close();
	int GETSCHDULE_MAX_SIZE = 5;
	FILE *fp;
	int Schdule_MAX_Size =0;
	char strtmp[100];
	if (fp = fopen(SCHDULEDAT, "r"))
	{
		while (1)
		{
			if (feof(fp))
			{
				break;
			}
			fscanf(fp, "Schdule_ID=%s\n", strtmp);
			if (feof(fp))
			{
				break;
			}
			//			cout << strtmp << "\t\t";
			fscanf(fp, "Play_ID=%s\n", strtmp);
			if (feof(fp))
			{
				break;
			}
			//			cout << strtmp << "\t   ";
			fscanf(fp, "Perform_ID=%s\n", strtmp);
			//			cout << strtmp << "\t       ";
			fscanf(fp, "Play_Date=%s\n", strtmp);
			//			cout << strtmp << "\t";
			fscanf(fp, "Play_Time=%s\n", strtmp);
			//			cout << strtmp << "\t     ";
			fscanf(fp, "Play_Ticket=%s\n", strtmp);
			//			cout << strtmp << endl;
			Schdule_MAX_Size++;
		}
	}
	fclose(fp);
	int flag = 1;
	char ch=' ';
	do
	{
		switch (ch)
		{
		case (int)'w':
			if(GETSCHDULE_MAX_SIZE< Schdule_MAX_Size)
			GETSCHDULE_MAX_SIZE++;
			break;
		case (int)'s':
			
			if (GETSCHDULE_MAX_SIZE>2)
			{
				GETSCHDULE_MAX_SIZE--;
			}
			break;
		case 72:
			if (flag > GETSCHDULE_MAX_SIZE)
			{
				flag -= GETSCHDULE_MAX_SIZE;
			}
			break;
		case 80:
			if (flag <= (Schdule_MAX_Size - GETSCHDULE_MAX_SIZE))
			{
				flag += GETSCHDULE_MAX_SIZE;
			}
			break;
		case 75:
			if (flag > GETSCHDULE_MAX_SIZE)
			{
				flag -= GETSCHDULE_MAX_SIZE;
			}
			break;
		case 77:
			if (flag <= (Schdule_MAX_Size - GETSCHDULE_MAX_SIZE))
			{
				flag += GETSCHDULE_MAX_SIZE;
			}
			break;
		default:
			break;
		}
		FILE *fp;
		system("cls");
		cout << "演出计划ID    剧目ID        演出厅ID      放映日期      放映时间      票数\n";
		if (fp = fopen(SCHDULEDAT, "r"))
		{
			for (int i = 1; i < flag; ++i)
			{
				if (i <= (Schdule_MAX_Size))
				{
					fgets(strtmp, 100, fp);
					fgets(strtmp, 100, fp);
					fgets(strtmp, 100, fp);
					fgets(strtmp, 100, fp);
					fgets(strtmp, 100, fp);
					fgets(strtmp, 100, fp);
				}
				else
				{
					break;
				}

			}

			for (int i = 0; i < GETSCHDULE_MAX_SIZE; ++i)
			{
				if (feof(fp))
				{
					break;
				}
				fscanf(fp, "Schdule_ID=%s\n", strtmp);
				if (feof(fp))
				{
					Schdule_MAX_Size = 0;
					break;
				}
				cout << strtmp;
				for (int m = 0; m < (GESHI_SIZE-strlen(strtmp)); ++m)
				{
					cout << " ";
				}
				fscanf(fp, "Play_ID=%s\n", strtmp);
				cout << strtmp;
				for (int m = 0; m < (GESHI_SIZE-strlen(strtmp)); ++m)
				{
					cout << " ";
				}
				fscanf(fp, "Perform_ID=%s\n", strtmp);
				cout << strtmp;
				for (int m = 0; m < (GESHI_SIZE-strlen(strtmp)); ++m)
				{
					cout << " ";
				}
				fscanf(fp, "Play_Date=%s\n", strtmp);
				cout << strtmp;
				for (int m = 0; m < (GESHI_SIZE-strlen(strtmp)); ++m)
				{
					cout << " ";
				}
				fscanf(fp, "Play_Time=%s\n", strtmp);
				cout << strtmp;
				for (int m = 0; m < (GESHI_SIZE-strlen(strtmp)); ++m)
				{
					cout << " ";
				}
				fscanf(fp, "Play_Ticket=%s\n", strtmp);
				cout << strtmp<<endl;			
			}
			
		}
		fclose(fp);
		cout << "\n共有演出计划" << Schdule_MAX_Size << "个  当前第" << ((flag - 1) / GETSCHDULE_MAX_SIZE) + 1
			<< "/"; 
		if (Schdule_MAX_Size == GETSCHDULE_MAX_SIZE)
		{
			cout << (Schdule_MAX_Size / GETSCHDULE_MAX_SIZE) << "页\n按ESC退出  ↑/←向前翻页  ↓/→向下翻页"
				<< "\nw增加每页显示数 s减少每页显示数 默认为5 最低为2 当前每页显示量:" << GETSCHDULE_MAX_SIZE;
		}
		else
		{
			cout << (Schdule_MAX_Size / GETSCHDULE_MAX_SIZE)+1 << "页\n按ESC退出  ↑/←向前翻页  ↓/→向下翻页"
				<< "\nw增加每页显示数 s减少每页显示数 默认为5 最低为2 当前每页显示量:" << GETSCHDULE_MAX_SIZE;
		}
		
	} while ((ch = _getch()) != 27);
	return 0;

}
int Init_Schdule_Add()
{
	ifstream Init_Schdule_Dat(SCHDULEDAT);
	if (Init_Schdule_Dat.is_open())
	{
		string Str;
		for (int i = 0; i < 3; ++i)
		{
			getline(Init_Schdule_Dat, Str);
			if (Init_Schdule_Dat.eof())
			{
				Init_Schdule_Dat.close();
				remove(SCHDULEDAT);
				return 0;
			}
		}
	}
	Init_Schdule_Dat.close();
	return 0;
}
//添加演出计划↓
int Schdule_Add()
{
	Init_Schdule_Add();
	system("cls");
	Schdule_inf SCHDULE_add;
	string Str_Tmp, Str_Tmp1;
	char ch;
	cout << "请输入剧目ID:";
	while ((ch = _getch())!= 13|| SCHDULE_add.Play_ID=="")
	{
		if (ch == 27)return 0;
		if (ch >= '0'&& ch <= '9')
		{
			SCHDULE_add.Play_ID += ch;
		}
		else if (ch == 8&& SCHDULE_add.Play_ID.size()>0)
		{
			SCHDULE_add.Play_ID = SCHDULE_add.Play_ID.substr(0, SCHDULE_add.Play_ID.size() - 1);
		}
		system("cls");
		cout << "请输入剧目ID:";
		cout << SCHDULE_add.Play_ID;
	}
	system("cls");
	cout << "请输入演出厅ID:";
	while ((ch = _getch()) != 13 || SCHDULE_add.Perform_ID=="")
	{

		if (ch >= '0'&& ch <= '9')
		{
			SCHDULE_add.Perform_ID += ch;
		}
		else if (ch == 8 && SCHDULE_add.Perform_ID.size()>0)
		{
			SCHDULE_add.Perform_ID = SCHDULE_add.Perform_ID.substr(0, SCHDULE_add.Perform_ID.size() - 1);
		}
		system("cls");
		cout << "请输入演出厅ID:";
		cout << SCHDULE_add.Perform_ID;
	}
	SCHDULE_add.Perform_ID = "Perform_ID=" + SCHDULE_add.Perform_ID;
	system("cls");
	cout << "请输入放映年份:";
	while ((ch = _getch()) != 13 || Str_Tmp == "")
	{
		Str_Tmp1= Str_Tmp + ch;
		if (ch >= '0'&& ch <= '9' && (atoi(Str_Tmp1.c_str()) > 0))
		{
			Str_Tmp += ch;
		}
		else if (ch == 8 && Str_Tmp.size()>0)
		{
			Str_Tmp = Str_Tmp.substr(0, Str_Tmp.size() - 1);
		}
		system("cls");
		cout << "请输入放映年份:";
		cout << Str_Tmp;
	}
	SCHDULE_add.Play_Date = "Play_Date=" + Str_Tmp;
	Str_Tmp = "";
	system("cls");
	cout << "请输入放映月份:";
	while (((ch = _getch()) != 13) || Str_Tmp=="")
	{
		Str_Tmp1= Str_Tmp + ch;
		if (ch >= '0'&& ch <= '9'&&(atoi(Str_Tmp1.c_str())<=12) && (atoi(Str_Tmp1.c_str()) > 0))
		{
			Str_Tmp += ch;
		}
		else if (ch == 8 && Str_Tmp.size()>0)
		{
			Str_Tmp = Str_Tmp.substr(0, Str_Tmp.size() - 1);
		}
		system("cls");
		cout << "请输入放映月份:";
		cout << Str_Tmp;
	}
	SCHDULE_add.Play_Date += "-" + Str_Tmp;
	Str_Tmp = "";
	system("cls");
	cout << "请输入放映日:";
	while ((ch = _getch()) != 13 || Str_Tmp == "")
	{
		Str_Tmp1 = Str_Tmp + ch;
		if (ch >= '0'&& ch <= '9'&&(atoi(Str_Tmp1.c_str()) <= 30)&& (atoi(Str_Tmp1.c_str()) > 0))
		{
			Str_Tmp += ch;
		}
		else if (ch == 8 && Str_Tmp.size()>0)
		{
			Str_Tmp = Str_Tmp.substr(0, Str_Tmp.size() - 1);
		}
		system("cls");
		cout << "请输入放映日:";
		cout << Str_Tmp;
	}
	SCHDULE_add.Play_Date += "-" + Str_Tmp;
	system("cls");
	Str_Tmp = "";
	cout << "请输入放映时间（时位）:";
	while ((ch = _getch()) != 13 || Str_Tmp == "")
	{
		Str_Tmp1 = Str_Tmp + ch;
		if (ch >= '0'&& ch <= '9' && (atoi(Str_Tmp1.c_str()) <= 23) && (atoi(Str_Tmp1.c_str()) >= 0))
		{
			Str_Tmp += ch;
		}
		else if (ch == 8 && Str_Tmp.size()>0)
		{
			Str_Tmp = Str_Tmp.substr(0, Str_Tmp.size() - 1);
		}
		system("cls");
		cout << "请输入放映时间（时位）:";
		cout << Str_Tmp;
	}
	SCHDULE_add.Play_Time = "Play_Time=" + Str_Tmp;
	system("cls");
	Str_Tmp = "";
	cout << "请输入放映时间（分位）:";
	while ((ch = _getch()) != 13 || Str_Tmp == "")
	{
		Str_Tmp1 = Str_Tmp + ch;
		if (ch >= '0'&& ch <= '9' && (atoi(Str_Tmp1.c_str()) <= 59) && (atoi(Str_Tmp1.c_str()) >= 0))
		{
			Str_Tmp += ch;
		}
		else if (ch == 8 && Str_Tmp.size()>0)
		{
			Str_Tmp = Str_Tmp.substr(0, Str_Tmp.size() - 1);
		}
		system("cls");
		cout << "请输入放映时间（分位）:";
		cout << Str_Tmp;
	}
	SCHDULE_add.Play_Time += "-" + Str_Tmp;
	system("cls");
	cout << "请输入票数:";	
	cin >> SCHDULE_add.Play_Ticket;
	ifstream GetSchdule(SCHDULEDAT);
	string Schdule_ID_Tmp, Perform_ID_Tmp, Play_Date_Tmp, Play_Time_Tmp;
	if (!GetSchdule.is_open())
	{
		SCHDULE_add.Schdule_ID += '1';
	}
	else
	{
		while (!GetSchdule.eof())
		{
			getline(GetSchdule, Schdule_ID_Tmp);
			if (Schdule_ID_Tmp.substr(0, 10) == "Schdule_ID")
			{
				Schdule_ID_Tmp = Schdule_ID_Tmp.substr(11, Schdule_ID_Tmp.size());
				getline(GetSchdule, Perform_ID_Tmp);
				getline(GetSchdule, Perform_ID_Tmp);
				getline(GetSchdule, Play_Date_Tmp);
				getline(GetSchdule, Play_Time_Tmp);
				if (SCHDULE_add.Perform_ID == Perform_ID_Tmp&&
					SCHDULE_add.Play_Date == Play_Date_Tmp&&
					SCHDULE_add.Play_Time == Play_Time_Tmp)
				{
					MessageBox(hWnd, L"当前时间演出厅已有安排!", L"提示", NULL);
					return 0;
				}
				if (SCHDULE_add.Schdule_ID == "")
				{
					int flag = 1;
					for (int i = 1;; ++i)
					{
						char Get_ID_other[100];
						int Get_ID;
						FILE *fp_id = fopen(SCHDULEDAT, "r");
						flag = 1;

						while (!feof(fp_id))
						{
							fscanf(fp_id, "Schdule_ID=%d", &Get_ID);
							fgets(Get_ID_other, 100, fp_id);
							if (Get_ID == i)
							{
								flag = 0;
								break;
							}
						}
						if (flag)
						{
							char a;
							for (int m = i; m != 0; m /= 10)
							{
								a = i + 48;
								SCHDULE_add.Schdule_ID += a;
							}
							break;
						}
					}
				}
			}
		}
	}
	GetSchdule.close();
	ofstream OutSchdule(SCHDULEDAT, ios::app);
	OutSchdule <<"Schdule_ID="<<SCHDULE_add.Schdule_ID << endl;
	OutSchdule << "Play_ID=" << SCHDULE_add.Play_ID << endl;
	OutSchdule << SCHDULE_add.Perform_ID << endl;
	OutSchdule << SCHDULE_add.Play_Date << endl;
	OutSchdule << SCHDULE_add.Play_Time << endl;
	OutSchdule << "Play_Ticket=" << SCHDULE_add.Play_Ticket << endl;
	system("pause");
	return 1;
}
//删除演出计划↓
int Schdule_Del()
{
	string Del_Tmp;
	shuru Schdule_Del_Shuru;
	system("cls");
	cout << "请输入需要删除计划的ID:";
	Schdule_Del_Shuru.tishi("*********************************删除演出计划********************************\n\
\t\t请输入演出计划ID:");
	Del_Tmp = Schdule_Del_Shuru.shuzi();
	if (Schdule_Serch(Del_Tmp))
	{

		Del_Tmp = "Schdule_ID=" + Del_Tmp;
		string File_Tmp;
		ofstream OutSchdule("SchduleTmp.dat");
		ifstream InSchdule(SCHDULEDAT);
		if (!InSchdule.is_open())
		{
			OutSchdule.close();
			InSchdule.close();
			return 0;
		}
		while (!InSchdule.eof())
		{
			getline(InSchdule, File_Tmp);
			if (File_Tmp == Del_Tmp)
			{
				getline(InSchdule, File_Tmp);
				getline(InSchdule, File_Tmp);
				getline(InSchdule, File_Tmp);
				getline(InSchdule, File_Tmp);
				getline(InSchdule, File_Tmp);
			}
			else
			{
				if(File_Tmp.size()>3)
				OutSchdule << File_Tmp << endl;
			}

		}
		OutSchdule.close();
		InSchdule.close();
		remove(SCHDULEDAT);
		rename("SchduleTmp.dat", SCHDULEDAT);
	}
	else
	{
		MessageBox(hWnd, L"没有此ID", L"提示", NULL);
	}
	return 0;
/*	string Del_Tmp;
	xuanzecaidan Schdule_Del_Menu;
	
	Schdule_Del_Menu.tianjiacaidan("**************************请选择需要删除的剧目*******************",1);
	Schdule_Del_Menu.tianjiacaidan("**************************当前所有剧目ID如下所示*****************", 1);
	ifstream GetSchdule(SCHDULEDAT);
	while (!GetSchdule.eof())
	{
		getline(GetSchdule, Del_Tmp);
		if (Del_Tmp.substr(0, 10) == "Schdule_ID")
		{
			Del_Tmp = Del_Tmp.substr(11, Del_Tmp.size());
			Schdule_Del_Menu.tianjiacaidan(Del_Tmp);
		}
	}
	GetSchdule.close();
	while (1)
	{
		int a = Schdule_Del_Menu.jiantoucaidan();
		a--;
		ifstream GetSchdule(SCHDULEDAT);
		for (int i = 0; i < a;++i)
		{
			for (int m = 0; m < 6; ++m)
			{
				getline(GetSchdule, Del_Tmp);
				if (GetSchdule.eof())
				{
					MessageBox(hWnd, L"读取文件发生错误", L"Error", NULL);
					return 0;
				}
			}
		}
		getline(GetSchdule, Del_Tmp);
		Del_Tmp = Del_Tmp.substr(11, Del_Tmp.size());
		xuanzecaidan Schdule_Del_YESORNO;
		string YESORNO_Tmp = "\t\t你确定要删除ID为" + Del_Tmp + "的剧目吗?";
		Schdule_Del_YESORNO.tianjiacaidan(YESORNO_Tmp, 1);
		Schdule_Del_YESORNO.tianjiacaidan("确认删除");
		Schdule_Del_YESORNO.tianjiacaidan("取消");
		switch (Schdule_Del_YESORNO.jiantoucaidan())
		{
		case 1:
			MessageBox(hWnd, L"删除成功", L"提示", NULL);
			break;
		default:
			break;
		}
	}*/
}

int Schedule_Menu()
{
	xuanzecaidan Schedule_Xuan;
	Schedule_Xuan.tianjiacaidan("******************************演出计划安排************************************\n", 1);
	Schedule_Xuan.tianjiacaidan("查看演出计划");
	Schedule_Xuan.tianjiacaidan("添加演出计划");
	Schedule_Xuan.tianjiacaidan("删除演出计划");
	Schedule_Xuan.tianjiacaidan("返回上一级");
	while (1)
	{
		switch (Schedule_Xuan.jiantoucaidan())
		{
		case 1:
			Schdule_Show();
			break;
		case 2:
			Schdule_Add();
			break;
		case 3:
			Schdule_Del();
			break;
		default:
			return 0;
		}
	}
	system("pause");
	return 0;
}