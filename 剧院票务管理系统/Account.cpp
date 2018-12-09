#include<iostream>
#include<string>
#include<time.h>
#include<Windows.h>
#include<fstream>
#include<direct.h>
#include<conio.h>
#include"caidan.h"
#include"shuru.h"
#include<stdio.h>
#define JLAccountDAT ".\\Account\\AccountJL.dat"
#define SPYAccountDAT ".\\Account\\AccountSPY.dat"
#define AdminAccountDAT ".\\Account\\AccountAdmin.dat"
using namespace std;
extern HWND hWnd;
string SPY_ID;
string SPY_MM;
string JL_ID;
string JL_MM;
//extern int Initadmin();
//string JiaAccountAdminZ(string str1);
//string JieAccountAdminZ(string str1);
//string JiaAccountAdminM(string str1);
//string JieAccountAdminM(string str1);
//管理员账号加密解密
string JiaAccountAdminZ(string str1)
{
	srand((unsigned)time(NULL));
	string str2 = "";
	for (int i = 0; i<str1.size(); i++)
	{
		if (i == 3)
		{
			str2 += str1[i] - 10;
			int rndptmp = rand() % 45052 + 51404;
			srand((unsigned)rndptmp);
			char strtmp = rand() % 70 + 40;
			str2 += strtmp;
			rndptmp = rand() % 1 + 100000;
			srand((unsigned)rndptmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			rndptmp = rand() % 1000000 + 1000000;
			srand((unsigned)rndptmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
		}
		else if (i < 4)
		{
			str2 += str1[i] - 10;

		}
		else if (i == 8)
		{
			str2 += str1[i] + 5;
			int rndptmp = rand() % 1254 + 10543;
			srand((unsigned)rndptmp);
			char strtmp = rand() % 70 + 40;
			str2 += strtmp;
			rndptmp = rand() % 1054 + 17273;
			srand((unsigned)rndptmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			rndptmp = rand() % 277475 + 24280;
			srand((unsigned)rndptmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
		}
		else if (i < 9)
		{
			str2 += str1[i] + 5;
		}

		else if (i == (str1.size() - 1))
		{
			str2 += str1[i] + 18;
			int rndptmp = rand() % 72752 + 442520;
			srand((unsigned)rndptmp);
			char strtmp = rand() % 70 + 40;
			str2 += strtmp;
			rndptmp = rand() % 24541 + 9727;
			srand((unsigned)rndptmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			rndptmp = rand() % 172727 + 24783;
			srand((unsigned)rndptmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			return str2;
		}
		else
		{
			str2 += str1[i] + 18;
		}
	}
	return str2;
}

string JieAccountAdminZ(string str1)
{
	string str2 = "";
	for (int i = 0; i < str1.size(); i++)
	{
		if (i < 4)
		{
			str2 += (str1[i] + 10);
		}
		else if (i < 7)continue;
		else if (i < 12)
		{
			str2 += (str1[i] - 5);
		}
		else if (i < 15)
		{
			continue;
		}
		else if (i < (str1.size() - 3))
		{
			str2 += (str1[i] - 18);
		}
	}
	return str2;
}

string JiaAccountAdminM(string str1)
{
	string str2 = "";
	char strtmp;
	srand((unsigned)time(NULL));
	strtmp = rand() % 70 + 40;
	str2 += strtmp;
	int randtmp;
	randtmp = rand() % 16511 + 13203;
	srand((unsigned)randtmp);
	strtmp = rand() % 70 + 40;
	str2 += strtmp;
	for (int i = 0; i < str1.size(); i++)
	{
		if (i < 3)
		{
			str1[i] += 13;
			str2 += str1[i];
		}
		else if (i == 3)
		{
			randtmp = rand() % 137870 + 37203;
			srand((unsigned)randtmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			randtmp = rand() % 50727 + 77273;
			srand((unsigned)randtmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			randtmp = rand() % 31560 + 40231;
			srand((unsigned)randtmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			str1[i] -= 10;
			str2 += str1[i];
		}
		else if (i < 7)
		{
			str1[i] -= 10;
			str2 += str1[i];
		}
		else if (i == 7)
		{
			randtmp = rand() % 31245 + 3542;
			srand((unsigned)randtmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			randtmp = rand() % 132523 + 12332;
			srand((unsigned)randtmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			randtmp = rand() % 34536 + 4345;
			srand((unsigned)randtmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			str1[i] += 16;
			str2 += str1[i];
		}
		else
		{
			str1[i] += 16;
			str2 += str1[i];
		}
	}
	randtmp = rand() % 34531 + 1320;
	srand((unsigned)randtmp);
	strtmp = rand() % 70 + 40;
	str2 += strtmp;
	randtmp = rand() % 16517 + 132456;
	srand((unsigned)randtmp);
	strtmp = rand() % 70 + 40;
	str2 += strtmp;
	randtmp = rand() % 5780 + 678;
	srand((unsigned)randtmp);
	strtmp = rand() % 70 + 40;
	str2 += strtmp;
	return str2;
}

string JieAccountAdminM(string str1)
{
	string str2 = "";
	for (int i = 2; i < (str1.size() - 3); i++)
	{
		if (i < 5)
		{
			str1[i] -= 13;
			str2 += str1[i];
		}
		else if (i < 8)continue;
		else if (i < 12)
		{
			str1[i] += 10;
			str2 += str1[i];
		}
		else if (i < 15)continue;
		else
		{
			str1[i] -= 16;
			str2 += str1[i];
		}
	}
	return str2;
}
//经理账号加密解密
string JiaAccountJLZ(string str1)
{
	srand((unsigned)time(NULL));
	string str2 = "";
	for (int i = 0; i<str1.size(); i++)
	{
		if (i == 3)
		{
			str2 += str1[i] - 11;
			int rndptmp = rand() % 45052 + 51404;
			srand((unsigned)rndptmp);
			char strtmp = rand() % 70 + 40;
			str2 += strtmp;
			rndptmp = rand() % 1 + 100000;
			srand((unsigned)rndptmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			rndptmp = rand() % 1000000 + 1000000;
			srand((unsigned)rndptmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
		}
		else if (i < 4)
		{
			str2 += str1[i] - 11;

		}
		else if (i == 8)
		{
			str2 += str1[i] + 5;
			int rndptmp = rand() % 1254 + 10543;
			srand((unsigned)rndptmp);
			char strtmp = rand() % 70 + 40;
			str2 += strtmp;
			rndptmp = rand() % 1054 + 17273;
			srand((unsigned)rndptmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			rndptmp = rand() % 277475 + 24280;
			srand((unsigned)rndptmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
		}
		else if (i < 9)
		{
			str2 += str1[i] + 5;
		}

		else if (i == (str1.size() - 1))
		{
			str2 += str1[i] + 18;
			int rndptmp = rand() % 72752 + 442520;
			srand((unsigned)rndptmp);
			char strtmp = rand() % 70 + 40;
			str2 += strtmp;
			rndptmp = rand() % 24541 + 9727;
			srand((unsigned)rndptmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			rndptmp = rand() % 172727 + 24783;
			srand((unsigned)rndptmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			return str2;
		}
		else
		{
			str2 += str1[i] + 18;
		}
	}
	return str2;
}

string JieAccountJLZ(string str1)
{
	string str2 = "";
	for (int i = 0; i < str1.size(); i++)
	{
		if (i < 4)
		{
			str2 += (str1[i] + 11);
		}
		else if (i < 7)continue;
		else if (i < 12)
		{
			str2 += (str1[i] - 5);
		}
		else if (i < 15)
		{
			continue;
		}
		else if (i < (str1.size() - 3))
		{
			str2 += (str1[i] - 18);
		}
	}
	return str2;
}

string JiaAccountJLM(string str1)
{
	string str2 = "";
	char strtmp;
	srand((unsigned)time(NULL));
	strtmp = rand() % 70 + 40;
	str2 += strtmp;
	int randtmp;
	randtmp = rand() % 16511 + 13203;
	srand((unsigned)randtmp);
	strtmp = rand() % 70 + 40;
	str2 += strtmp;
	for (int i = 0; i < str1.size(); i++)
	{
		if (i < 3)
		{
			str1[i] += 23;
			str2 += str1[i];
		}
		else if (i == 3)
		{
			randtmp = rand() % 137870 + 37203;
			srand((unsigned)randtmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			randtmp = rand() % 50727 + 77273;
			srand((unsigned)randtmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			randtmp = rand() % 31560 + 40231;
			srand((unsigned)randtmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			str1[i] -= 22;
			str2 += str1[i];
		}
		else if (i < 7)
		{
			str1[i] -= 22;
			str2 += str1[i];
		}
		else if (i == 7)
		{
			randtmp = rand() % 31245 + 3542;
			srand((unsigned)randtmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			randtmp = rand() % 132523 + 12332;
			srand((unsigned)randtmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			randtmp = rand() % 34536 + 4345;
			srand((unsigned)randtmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			str1[i] += 8;
			str2 += str1[i];
		}
		else
		{
			str1[i] += 8;
			str2 += str1[i];
		}
	}
	randtmp = rand() % 34531 + 1320;
	srand((unsigned)randtmp);
	strtmp = rand() % 70 + 40;
	str2 += strtmp;
	randtmp = rand() % 16517 + 132456;
	srand((unsigned)randtmp);
	strtmp = rand() % 70 + 40;
	str2 += strtmp;
	randtmp = rand() % 5780 + 678;
	srand((unsigned)randtmp);
	strtmp = rand() % 70 + 40;
	str2 += strtmp;
	return str2;
}

string JieAccountJLM(string str1)
{
	string str2 = "";
	for (int i = 2; i < (str1.size() - 3); i++)
	{
		if (i < 5)
		{
			str1[i] -= 23;
			str2 += str1[i];
		}
		else if (i < 8)continue;
		else if (i < 12)
		{
			str1[i] += 22;
			str2 += str1[i];
		}
		else if (i < 15)continue;
		else
		{
			str1[i] -= 8;
			str2 += str1[i];
		}
	}
	return str2;
}
//售票员账号加密解密
string JiaAccountSPYZ(string str1)
{
	srand((unsigned)time(NULL));
	string str2 = "";
	for (int i = 0; i<str1.size(); i++)
	{
		if (i == 3)
		{
			str2 += str1[i] - 6;
			int rndptmp = rand() % 45052 + 51404;
			srand((unsigned)rndptmp);
			char strtmp = rand() % 70 + 40;
			str2 += strtmp;
			rndptmp = rand() % 1 + 100000;
			srand((unsigned)rndptmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			rndptmp = rand() % 1000000 + 1000000;
			srand((unsigned)rndptmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
		}
		else if (i < 4)
		{
			str2 += str1[i] - 6;

		}
		else if (i == 8)
		{
			str2 += str1[i] + 5;
			int rndptmp = rand() % 1254 + 10543;
			srand((unsigned)rndptmp);
			char strtmp = rand() % 70 + 40;
			str2 += strtmp;
			rndptmp = rand() % 1054 + 17273;
			srand((unsigned)rndptmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			rndptmp = rand() % 277475 + 24280;
			srand((unsigned)rndptmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
		}
		else if (i < 9)
		{
			str2 += str1[i] + 5;
		}

		else if (i == (str1.size() - 1))
		{
			str2 += str1[i] + 18;
			int rndptmp = rand() % 72752 + 442520;
			srand((unsigned)rndptmp);
			char strtmp = rand() % 70 + 40;
			str2 += strtmp;
			rndptmp = rand() % 24541 + 9727;
			srand((unsigned)rndptmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			rndptmp = rand() % 172727 + 24783;
			srand((unsigned)rndptmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			return str2;
		}
		else
		{
			str2 += str1[i] + 18;
		}
	}
	return str2;
}

string JieAccountSPYZ(string str1)
{
	string str2 = "";
	for (int i = 0; i < str1.size(); i++)
	{
		if (i < 4)
		{
			str2 += (str1[i] + 6);
		}
		else if (i < 7)continue;
		else if (i < 12)
		{
			str2 += (str1[i] - 5);
		}
		else if (i < 15)
		{
			continue;
		}
		else if (i < (str1.size() - 3))
		{
			str2 += (str1[i] - 18);
		}
	}
	return str2;
}

string JiaAccountSPYM(string str1)
{
	string str2 = "";
	char strtmp;
	srand((unsigned)time(NULL));
	strtmp = rand() % 70 + 40;
	str2 += strtmp;
	int randtmp;
	randtmp = rand() % 16511 + 13203;
	srand((unsigned)randtmp);
	strtmp = rand() % 70 + 40;
	str2 += strtmp;
	for (int i = 0; i < str1.size(); i++)
	{
		if (i < 3)
		{
			str1[i] += 23;
			str2 += str1[i];
		}
		else if (i == 3)
		{
			randtmp = rand() % 137870 + 37203;
			srand((unsigned)randtmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			randtmp = rand() % 50727 + 77273;
			srand((unsigned)randtmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			randtmp = rand() % 31560 + 40231;
			srand((unsigned)randtmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			str1[i] -= 10;
			str2 += str1[i];
		}
		else if (i < 7)
		{
			str1[i] -= 10;
			str2 += str1[i];
		}
		else if (i == 7)
		{
			randtmp = rand() % 31245 + 3542;
			srand((unsigned)randtmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			randtmp = rand() % 132523 + 12332;
			srand((unsigned)randtmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			randtmp = rand() % 34536 + 4345;
			srand((unsigned)randtmp);
			strtmp = rand() % 70 + 40;
			str2 += strtmp;
			str1[i] += 11;
			str2 += str1[i];
		}
		else
		{
			str1[i] += 11;
			str2 += str1[i];
		}
	}
	randtmp = rand() % 34531 + 1320;
	srand((unsigned)randtmp);
	strtmp = rand() % 70 + 40;
	str2 += strtmp;
	randtmp = rand() % 16517 + 132456;
	srand((unsigned)randtmp);
	strtmp = rand() % 70 + 40;
	str2 += strtmp;
	randtmp = rand() % 5780 + 678;
	srand((unsigned)randtmp);
	strtmp = rand() % 70 + 40;
	str2 += strtmp;
	return str2;
}

string JieAccountSPYM(string str1)
{
	string str2 = "";
	for (int i = 2; i < (str1.size() - 3); i++)
	{
		if (i < 5)
		{
			str1[i] -= 23;
			str2 += str1[i];
		}
		else if (i < 8)continue;
		else if (i < 12)
		{
			str1[i] += 10;
			str2 += str1[i];
		}
		else if (i < 15)continue;
		else
		{
			str1[i] -= 11;
			str2 += str1[i];
		}
	}
	return str2;
}
/***************************************管理员账户操作*******************************************************/

//初始化注册系统管理员用户↓
int Initadmin()   
{
//	MessageBox(hWnd, L"本账号拥有系统账户添加修改权限，请仔细填写", L"提示", MB_OK);
	string strtmp1, strtmp2, strtmp11, strtmp22;
	char strtmpin;
	shuru Init_Admin;

	while (1)
	{
		/*system("cls");
		cout << "******************提示:本账号拥有系统账户添加修改权限，请仔细填写************\n\n";
		cout << "******************提示:账号密码长度必须大于8位,小于15位************\n\n";
		cout << "\t\t\t账号:";
		while ((strtmpin = _getch()) != 13)
		{
			system("cls");
			cout << "******************提示:本账号拥有系统账户添加修改权限，请仔细填写************\n\n";
			cout << "******************提示:账号密码长度必须大于8位,小于15位************\n\n";
			cout << "\t\t\t账号:";
			if (strtmpin == 8)
			{
				if (strtmp1.size() > 0)
				{
					strtmp1 = strtmp1.substr(0, strtmp1.size() - 1);
				}
			}
			else if ((strtmpin >= '0'&&strtmpin <= '9')\
				|| (strtmpin >= 'a'&&strtmpin <= 'z')\
				|| (strtmpin >= 'A'&&strtmpin <= 'Z'))
			{
				if (strtmp1.size() <= 14)
				{
					strtmp1 += strtmpin;
				}
			}
			cout << strtmp1;
		}*/
		Init_Admin.tishi("******************提示:本账号拥有系统账户添加修改权限，请仔细填写************\n\n\
******************提示:账号密码长度必须大于8位,小于15位************\n\n\
\t\t\t账号:");
		strtmp1 = Init_Admin.zimuandshuzi();
		if (strtmp1.size() < 9)
		{
			MessageBox(hWnd, L"账号长度过短", L"Error", NULL);
			system("cls");
			continue;
		}
		else if (strtmp1.size() > 15)
		{
			MessageBox(hWnd, L"账号长度过长", L"Error", NULL);
			system("cls");
			continue;
		}
		else
		{
			Init_Admin.tishi("******************提示:本账号拥有系统账户添加修改权限，请仔细填写************\n\n\
******************提示:账号密码长度必须大于8位,小于15位************\n\n\
\t\t\t请再次输入账号:");
			strtmp11 = Init_Admin.zimuandshuzi();
			if (strtmp1 == strtmp11)
			{
				break;
			}
			else
			{
				MessageBox(hWnd, L"两次输入不一致，请重试", L"Error", NULL);
				continue;
			}
		}
	}

	while (1)
	{
		/*system("cls");
		cout << "******************提示:本账号拥有系统账户添加修改权限，请仔细填写************\n\n";
		cout << "******************提示:账号密码长度必须大于8位,小于15位************\n\n";
		cout << "\t\t\t账号:";
		cout << strtmp1;
		cout << "\n\t\t\t密码:";
		while ((strtmpin = _getch()) != 13)
		{
			system("cls");
			cout << "******************提示:本账号拥有系统账户添加修改权限，请仔细填写************\n\n";
			cout << "******************提示:账号密码长度必须大于8位,小于15位************\n\n";
			cout << "\t\t\t账号:";
			cout << strtmp1;
			cout << "\n\t\t\t密码:";
			if (strtmpin == 8)
			{
				if (strtmp2.size() > 0)
				{
					strtmp2 = strtmp2.substr(0, strtmp2.size() - 1);
				}
			}
			else if ((strtmpin >= '0'&&strtmpin <= '9')\
				|| (strtmpin >= 'a'&&strtmpin <= 'z')\
				|| (strtmpin >= 'A'&&strtmpin <= 'Z'))
			{
				if (strtmp2.size() <= 18)
				{
					strtmp2 += strtmpin;
				}
			}
			cout << strtmp2;
		}*/
		Init_Admin.tishi("******************提示:本账号拥有系统账户添加修改权限，请仔细填写************\n\n\
******************提示:账号密码长度必须大于8位,小于15位************\n\n\
\t\t\t密码:");
		strtmp2 = Init_Admin.zimuandshuzi();
		if (strtmp2.size() <9)
		{
			MessageBox(hWnd, L"密码长度过短", L"Error", NULL);
			system("cls");
			continue;
		}
		else if (strtmp2.size() > 15)
		{
			MessageBox(hWnd, L"密码长度过长", L"Error", NULL);
			continue;
		}
		else
		{
			Init_Admin.tishi("******************提示:本账号拥有系统账户添加修改权限，请仔细填写************\n\n\
******************提示:账号密码长度必须大于8位,小于15位************\n\n\
\t\t\t再次输入密码:");
			strtmp22 = Init_Admin.zimuandshuzi();
			if (strtmp2 == strtmp22)
			{
				_mkdir("Account");
				ofstream zhuce(AdminAccountDAT);
				while (1)
				{
					strtmp1 = strtmp11;
					strtmp2 = strtmp22;
					strtmp1 = JiaAccountAdminZ(strtmp1);
					strtmp2 = JiaAccountAdminM(strtmp2);
					if (strtmp11 == JieAccountAdminZ(strtmp1) && strtmp22 == JieAccountAdminM(strtmp2))break;
				}
				zhuce << strtmp1 << endl;
				zhuce << strtmp2;
				zhuce.close();
				break;
			}
			else
			{
				MessageBox(hWnd, L"两次输入不一致，请重试", L"Error", NULL);
				continue;
			}
		}
	}
	MessageBox(hWnd, L"注册成功", L"提示", NULL);
	return 0;
}

//管理员用户登录↓
int AdminLogin()
{
	
	string zhanghao, mima;
	char strtmpin;
	system("cls");
	cout << "\t   ";
	for (int i = 0; i < 20; i++)cout << '*';
	cout << "管理员身份验证";
	for (int i = 0; i < 20; i++)cout << '*';
	cout << endl;
	cout << "\t\t\t管理员账号:";
	while ((strtmpin = _getch()) != 13)
	{
		system("cls");
		cout << "\t      ";
		for (int i = 0; i < 20; i++)cout << '*';
		cout << "管理员账号登录";
		for (int i = 0; i < 20; i++)cout << '*';
		cout << endl;
		cout << "\t\t\t管理员账号:";
		if (strtmpin == 8)
		{
			if (zhanghao.size() > 0)
			{
				zhanghao = zhanghao.substr(0, zhanghao.size() - 1);
			}
		}
		else if ((strtmpin >= '0'&&strtmpin <= '9')\
			|| (strtmpin >= 'a'&&strtmpin <= 'z')\
			|| (strtmpin >= 'A'&&strtmpin <= 'Z'))
		{
			if (zhanghao.size() <= 18)
			{
				zhanghao += strtmpin;
			}
		}
		cout << zhanghao;
	}
	system("cls");
	cout << "\t   ";
	for (int i = 0; i < 20; i++)cout << '*';
	cout << "管理员身份验证";
	for (int i = 0; i < 20; i++)cout << '*';
	cout << endl;
	cout << "\t\t\t管理员账号:";
	cout << zhanghao;
	cout << "\n\t\t\t管理员密码:";
	while ((strtmpin = _getch()) != 13)
	{
		system("cls");
		cout << "\t      ";
		for (int i = 0; i < 20; i++)cout << '*';
		cout << "管理员身份验证";
		for (int i = 0; i < 20; i++)cout << '*';
		cout << endl;
		cout << "\t\t\t管理员账号:";
		cout << zhanghao;
		cout << "\n\t\t\t管理员密码:";
		if (strtmpin == 8)
		{
			if (mima.size() > 0)
			{
				mima = mima.substr(0, mima.size() - 1);
			}
		}
		else if ((strtmpin >= '0'&&strtmpin <= '9')\
			|| (strtmpin >= 'a'&&strtmpin <= 'z')\
			|| (strtmpin >= 'A'&&strtmpin <= 'Z'))
		{
			if (mima.size() <= 18)
			{
				mima += strtmpin;
			}
		}
		for (int i = 0; i < mima.size(); ++i)
		{
			cout << '*';
		}
	}
	ifstream GetAccount(AdminAccountDAT);
	string Login1, Login2;
	getline(GetAccount, Login1);
	getline(GetAccount, Login2);
	if ((zhanghao.compare(JieAccountAdminZ(Login1)) == 0) && (mima.compare(JieAccountAdminM(Login2)) == 0))
	{
		GetAccount.close();
		return 1;
	}
	else
	{
		GetAccount.close();
		return 0;
	}
}

//管理员密码修改↓
int ChangeAdmin()
{
	if (AdminLogin())
	{
		ifstream GetAccount(AdminAccountDAT);
		string strtmp1, strtmp11, strtmp2, strtmp22;
		getline(GetAccount, strtmp11);
		strtmp11 = JieAccountAdminZ(strtmp11);
		while (1)
		{
			system("cls");
			cout << "******************提示:本账号拥有系统账户添加修改权限，请仔细填写************\n\n";
			cout << "******************提示:账号密码长度必须大于8位,小于15位************\n\n";
			cout << "\t\t\t密码:";
			cin >> strtmp2;
			if (strtmp2.size() <9)
			{
				MessageBox(hWnd, L"密码长度过短", L"Error", NULL);
				system("cls");
				continue;
			}
			else if (strtmp2.size() > 15)
			{
				MessageBox(hWnd, L"密码长度过长", L"Error", NULL);
				continue;
			}
			else
			{
				cout << "\t\t\t请再次输入密码:";
				cin >> strtmp22;
				if (strtmp2 == strtmp22)
				{
					ofstream zhuce(AdminAccountDAT);
					while (1)
					{
						strtmp1 = strtmp11;
						strtmp2 = strtmp22;
						strtmp1 = JiaAccountAdminZ(strtmp1);
						strtmp2 = JiaAccountAdminM(strtmp2);
						if (strtmp11 == JieAccountAdminZ(strtmp1) && strtmp22 == JieAccountAdminM(strtmp2))break;
					}

					zhuce << strtmp1 << endl;
					zhuce << strtmp2;
					zhuce.close();
					break;
				}
				else
				{
					MessageBox(hWnd, L"两次输入不一致，请重试", L"Error", NULL);
					continue;
				}
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

/**********************************************************************************************************/

/***************************************经理账户操作*******************************************************/

//检测经理用户存在性↓
int SerchJL(string strtmp1)
{
	ifstream GetAccount(JLAccountDAT);
	string StrGetAccount;
	if (!GetAccount.is_open())
	{
		return 0;
	};
	while (!GetAccount.eof())
	{
		getline(GetAccount, StrGetAccount);
		if (StrGetAccount.size() > 8)
		{
			if (("ZH" + strtmp1) == JieAccountJLZ(StrGetAccount))
			{
				return 1;
			}
		}
	}
	return 0;

} 

//经理用户登录↓
int JLLogin()
{

	string zhanghao, mima;
	char strtmpin;
	system("cls");
	cout << "\t      ";
	for (int i = 0; i < 20; i++)cout << '*';
	cout << "经理账号登录";
	for (int i = 0; i < 20; i++)cout << '*';
	cout << endl;
	cout << "\t\t\t经理账号:";
	while ((strtmpin = _getch()) != 13)
	{
		system("cls");
		cout << "\t      ";
		for (int i = 0; i < 20; i++)cout << '*';
		cout << "经理账号登录";
		for (int i = 0; i < 20; i++)cout << '*';
		cout << endl;
		cout << "\t\t\t经理账号:";
		if (strtmpin == 8)
		{
			if (zhanghao.size() > 0)
			{
				zhanghao = zhanghao.substr(0, zhanghao.size() - 1);
			}
		}
		else if ((strtmpin >= '0'&&strtmpin <= '9')\
			|| (strtmpin >= 'a'&&strtmpin <= 'z')\
			|| (strtmpin >= 'A'&&strtmpin <= 'Z'))
		{
			if (zhanghao.size() <= 18)
			{
				zhanghao += strtmpin;
			}
		}
		cout << zhanghao;
	}
	system("cls");
	cout << "\t      ";
	for (int i = 0; i < 20; i++)cout << '*';
	cout << "经理账号登录";
	for (int i = 0; i < 20; i++)cout << '*';
	cout << endl;
	cout << "\t\t\t经理账号:";
	cout << zhanghao;
	cout << "\n\t\t\t经理密码:";
	while ((strtmpin = _getch()) != 13)
	{
		system("cls");
		cout << "\t      ";
		for (int i = 0; i < 20; i++)cout << '*';
		cout << "经理账号登录";
		for (int i = 0; i < 20; i++)cout << '*';
		cout << endl;
		cout << "\t\t\t经理账号:";
		cout << zhanghao;
		cout << "\n\t\t\t经理密码:";
		if (strtmpin == 8)
		{
			if (mima.size() > 0)
			{
				mima = mima.substr(0, mima.size() - 1);
			}
		}
		else if ((strtmpin >= '0'&&strtmpin <= '9')\
			|| (strtmpin >= 'a'&&strtmpin <= 'z')\
			|| (strtmpin >= 'A'&&strtmpin <= 'Z'))
		{
			if (mima.size() <= 18)
			{
				mima += strtmpin;
			}
		}
		for (int i = 0; i < mima.size(); ++i)
		{
			cout << '*';
		}
	}
	zhanghao = "ZH" + zhanghao;
	mima = "MM" + mima;
	ifstream GetAccount(JLAccountDAT);
	string Login1, Login2;
	if (!GetAccount.is_open())
	{
		return 0;
	}
	else
	{
		while (!GetAccount.eof())
		{
			getline(GetAccount, Login1);
			if (zhanghao.compare(JieAccountJLZ(Login1)) == 0)
			{
				getline(GetAccount, Login2);
				if (mima.compare(JieAccountJLM(Login2)) == 0)
				{
					GetAccount.close();
					JL_ID = zhanghao.substr(2);
					JL_MM = mima.substr(2);
					return 1;
				}
				else
				{
					GetAccount.close();
					return 0;
				}
			}
		}
		GetAccount.close();
		return 0;
	}
}

//添加经理用户↓
int ADDJL()
{
	string strtmp1, strtmp2, strtmp11, strtmp22;
	shuru ADD_JL_SHURU;
	while (1)
	{
		system("cls");
		ADD_JL_SHURU.tishi("\t******************提示:当前注册账号为[经理]************\n\n\
******************提示:账号密码长度必须大于8位,小于15位************\n\n\t\t\t账号:");
		strtmp1 = ADD_JL_SHURU.zimuandshuzi();
		if (strtmp1.size() < 9)
		{
			MessageBox(hWnd, L"账号长度过短", L"Error", NULL);
			system("cls");
			continue;
		}
		else if (strtmp1.size() > 15)
		{
			MessageBox(hWnd, L"账号长度过长", L"Error", NULL);
			system("cls");
			continue;
		}
		else
		{
			if (SerchJL(strtmp1))
			{
				MessageBox(hWnd, L"账号已存在", L"Error", NULL);
				return 0;
			}
			cout << "\n\t\t\t请再次输入账号:";
			cin >> strtmp11;
			if (strtmp1 == strtmp11)
			{
				break;
			}
			else
			{
				MessageBox(hWnd, L"两次输入不一致，请重试", L"Error", NULL);
				continue;
			}
		}
	}
	while (1)
	{
		system("cls");
		cout << "\t******************提示:当前注册账号为[经理]************\n\n";
		cout << "******************提示:账号密码长度必须大于8位,小于15位************\n\n";
		cout << "\t\t\t密码:";
		cin >> strtmp2;
		if (strtmp2.size() < 9)
		{
			MessageBox(hWnd, L"密码长度过短", L"Error", NULL);
			system("cls");
			continue;
		}
		else if (strtmp2.size() > 15)
		{
			MessageBox(hWnd, L"密码长度过长", L"Error", NULL);
			continue;
		}
		else
		{
			cout << "\t\t\t请再次输入密码:";
			cin >> strtmp22;
			if (strtmp2 == strtmp22)
			{
				ofstream zhuce(JLAccountDAT, ios::app);
				strtmp11 = "ZH" + strtmp11;
				strtmp22 = "MM" + strtmp22;
				while (1)
				{
					strtmp1 = strtmp11;
					strtmp2 = strtmp22;
					strtmp1 = JiaAccountJLZ(strtmp1);
					strtmp2 = JiaAccountJLM(strtmp2);
					if (strtmp11 == JieAccountJLZ(strtmp1) && strtmp22 == JieAccountJLM(strtmp2))break;
					else
					{
						cout << strtmp11 << endl << JieAccountJLZ(strtmp1) << endl;
						cout << strtmp22 << endl << JieAccountJLM(strtmp2) << endl;
						system("pause");
					}
				}
				zhuce << strtmp1 << endl;
				zhuce << strtmp2 << endl;
				zhuce.close();
				break;
			}
			else
			{
				MessageBox(hWnd, L"两次输入不一致，请重试", L"Error", NULL);
				continue;
			}
		}
	}
	MessageBox(hWnd, L"注册成功", L"提示", NULL);
	return 0;
}

//删除经理↓
int DelJL(string Strtmp)
{

	if (!SerchJL(Strtmp))
	{
		MessageBox(hWnd, L"没有此账号", L"提示", NULL);
		return 0;
	}
	else
	{
		string OutStrtmp;
		ifstream GetAccount(JLAccountDAT);
		ofstream OutAccount("DatTmp.dat");
		while (!GetAccount.eof())
		{
			getline(GetAccount, OutStrtmp);
			if (("ZH" + Strtmp) == JieAccountJLZ(OutStrtmp))
			{
				getline(GetAccount, OutStrtmp);
				continue;
			}
			OutAccount << OutStrtmp << endl;
		}
		GetAccount.close();
		OutAccount.close();
		remove(JLAccountDAT);
		rename("DatTmp.dat", JLAccountDAT);
	}
}

//展示经理信息↓
void JLAccountShow()
{
	for (int i = 0; i < 15; ++i)
	{
		cout << '*';
	}
	cout << "经理信息如下";
	for (int i = 0; i < 15; ++i)
	{
		cout << '*';
	}
	cout << endl << endl;
	cout << "用户名\t\t\t  密码\n";
	string AccountStrTmp;
	ifstream GetAccount(JLAccountDAT);
	if (GetAccount.is_open())
	{
		int Flag = 0;
		while (!GetAccount.eof())
		{
			getline(GetAccount, AccountStrTmp);
			if (AccountStrTmp.size() > 8)
			{
				if (Flag % 2)
				{
					AccountStrTmp = JieAccountJLM(AccountStrTmp);
					AccountStrTmp = AccountStrTmp.substr(2);
					cout << AccountStrTmp;
					cout << "\n";
				}
				else
				{
					AccountStrTmp = JieAccountJLZ(AccountStrTmp);
					AccountStrTmp = AccountStrTmp.substr(2);
					cout << AccountStrTmp;
					cout << "\t\t";
				}
				Flag++;
			}
		}
	}
	GetAccount.close();
}
//修改经理密码
int ChangeJL(string JL_ID_Tmp)
{
	string JL_MM_Tmp;
	shuru C_JL;
	C_JL.tishi("请输入旧密码:");
	JL_MM_Tmp = C_JL.zimuandshuzi();
	if (JL_MM_Tmp == JL_MM)
	{
		C_JL.tishi("请输入新密码:");
		JL_MM_Tmp = C_JL.zimuandshuzi();
		DelJL(JL_ID_Tmp);
		ofstream Out_JL(JLAccountDAT, ios::app);
		Out_JL << JiaAccountJLZ(("ZH" + JL_ID_Tmp)) << endl
			<< JiaAccountJLM(("MM" + JL_MM_Tmp)) << endl;

	}
	else
	{
		MessageBox(hWnd, L"密码验证失败", L"提示", NULL);
		return 0;
	}
}
/**********************************************************************************************************/

/***************************************售票员账户操作*******************************************************/

//检测售票员用户存在性↓
int SerchSPY(string strtmp1)
{
	ifstream GetAccount(SPYAccountDAT);
	if (!GetAccount.is_open())
	{
		return 0;
	};
	string StrGetAccount;
	while (!GetAccount.eof())
	{
		getline(GetAccount, StrGetAccount);
		if (StrGetAccount.size() > 8)
		{

			if (("ZH" + strtmp1) == JieAccountSPYZ(StrGetAccount))
			{
				return 1;
			}
		}
	}
	return 0;
}

//售票员用户登录
int SPYLogin()
{

	string zhanghao, mima;
	char strtmpin;
	system("cls");
	cout << "\t      ";
	for (int i = 0; i < 20; i++)cout << '*';
	cout << "售票员账号登录";
	for (int i = 0; i < 20; i++)cout << '*';
	cout << endl;
	cout << "\t\t\t售票员账号:";
	while ((strtmpin = _getch()) != 13)
	{
		system("cls");
		cout << "\t      ";
		for (int i = 0; i < 20; i++)cout << '*';
		cout << "售票员账号登录";
		for (int i = 0; i < 20; i++)cout << '*';
		cout << endl;
		cout << "\t\t\t售票员账号:";
		if (strtmpin == 8)
		{
			if (zhanghao.size() > 0)
			{
				zhanghao = zhanghao.substr(0, zhanghao.size() - 1);
			}
		}
		else if ((strtmpin >= '0'&&strtmpin <= '9')\
			|| (strtmpin >= 'a'&&strtmpin <= 'z')\
			|| (strtmpin >= 'A'&&strtmpin <= 'Z'))
		{
			if (zhanghao.size() <= 18)
			{
				zhanghao += strtmpin;
			}
		}
		cout << zhanghao;
	}
	system("cls");
	cout << "\t      ";
	for (int i = 0; i < 20; i++)cout << '*';
	cout << "售票员账号登录";
	for (int i = 0; i < 20; i++)cout << '*';
	cout << endl;
	cout << "\t\t\t售票员账号:";
	cout << zhanghao;
	cout << "\n\t\t\t售票员密码:";
	while ((strtmpin = _getch()) != 13)
	{
		system("cls");
		cout << "\t      ";
		for (int i = 0; i < 20; i++)cout << '*';
		cout << "售票员账号登录";
		for (int i = 0; i < 20; i++)cout << '*';
		cout << endl;
		cout << "\t\t\t售票员账号:";
		cout << zhanghao;
		cout << "\n\t\t\t售票员密码:";
		if (strtmpin == 8)
		{
			if (mima.size() > 0)
			{
				mima = mima.substr(0, mima.size() - 1);
			}
		}
		else if ((strtmpin >= '0'&&strtmpin <= '9')\
			|| (strtmpin >= 'a'&&strtmpin <= 'z')\
			|| (strtmpin >= 'A'&&strtmpin <= 'Z'))
		{
			if (mima.size() <= 18)
			{
				mima += strtmpin;
			}
		}
		for (int i = 0; i < mima.size(); ++i)
		{
			cout << '*';
		}
	}
	zhanghao = "ZH" + zhanghao;
	mima = "MM" + mima;
	ifstream GetAccount(SPYAccountDAT);
	string Login1, Login2;
	if (!GetAccount.is_open())
	{
		return 0;
	}
	else
	{
		while (!GetAccount.eof())
		{
			getline(GetAccount, Login1);
			if (zhanghao.compare(JieAccountSPYZ(Login1)) == 0)
			{
				getline(GetAccount, Login2);
				if (mima.compare(JieAccountSPYM(Login2)) == 0)
				{
					GetAccount.close();
					SPY_ID = zhanghao.substr(2);
					SPY_MM = mima.substr(2);
					return 1;
				}
				else
				{
					GetAccount.close();
					return 0;
				}
			}
		}
		GetAccount.close();
		return 0;
	}
}

//添加售票员用户↓
int ADDSPY()
{
	string strtmp1, strtmp2, strtmp11, strtmp22;
	shuru ADD_SPY_SHURU;
	while (1)
	{
		system("cls");
		ADD_SPY_SHURU.tishi("\t******************提示:当前注册账号为[售票员]************\n\n\
******************提示:账号密码长度必须大于8位,小于15位************\n\n\t\t\t账号:");
		strtmp1 = ADD_SPY_SHURU.zimuandshuzi();
		if (strtmp1.size() < 9)
		{
			MessageBox(hWnd, L"账号长度过短", L"Error", NULL);
			system("cls");
			continue;
		}
		else if (strtmp1.size() > 15)
		{
			MessageBox(hWnd, L"账号长度过长", L"Error", NULL);
			system("cls");
			continue;
		}
		else
		{
			if (SerchSPY(strtmp1))
			{
				MessageBox(hWnd, L"账号已存在", L"Error", NULL);
				return 0;
			}
			cout << "\n\t\t\t请再次输入账号:";
			cin >> strtmp11;
			if (strtmp1 == strtmp11)
			{
				break;
			}
			else
			{
				MessageBox(hWnd, L"两次输入不一致，请重试", L"Error", NULL);
				continue;
			}
		}
	}
	while (1)
	{
		system("cls");
		cout << "\t******************提示:当前注册账号为[售票员]************\n\n"; \
			cout << "******************提示:账号密码长度必须大于8位,小于15位************\n\n";
		cout << "\t\t\t密码:";
		cin >> strtmp2;
		if (strtmp2.size() < 9)
		{
			MessageBox(hWnd, L"密码长度过短", L"Error", NULL);
			system("cls");
			continue;
		}
		else if (strtmp2.size() > 15)
		{
			MessageBox(hWnd, L"密码长度过长", L"Error", NULL);
			continue;
		}
		else
		{
			cout << "\t\t\t请再次输入密码:";
			cin >> strtmp22;
			if (strtmp2 == strtmp22)
			{
				ofstream zhuce(SPYAccountDAT, ios::app);
				strtmp11 = "ZH" + strtmp11;
				strtmp22 = "MM" + strtmp22;
				while (1)
				{
					strtmp1 = strtmp11;
					strtmp2 = strtmp22;
					strtmp1 = JiaAccountSPYZ(strtmp1);
					strtmp2 = JiaAccountSPYM(strtmp2);
					if (strtmp11 == JieAccountSPYZ(strtmp1) && strtmp22 == JieAccountSPYM(strtmp2))break;
				}
				zhuce << strtmp1 << endl;
				zhuce << strtmp2 << endl;
				zhuce.close();
				break;
			}
			else
			{
				MessageBox(hWnd, L"两次输入不一致，请重试", L"Error", NULL);
				continue;
			}
		}
	}
	MessageBox(hWnd, L"注册成功", L"提示", NULL);
	return 1;
}

//删除售票员↓
int DelSPY(string Strtmp)
{
	
	if (!SerchSPY(Strtmp))
	{
		MessageBox(hWnd, L"没有此账号", L"提示", NULL);
		return 0;
	}
	else
	{
		string OutStrtmp;
		ifstream GetAccount(SPYAccountDAT);
		ofstream OutAccount("DatTmp.dat");
		while (!GetAccount.eof())
		{
			getline(GetAccount, OutStrtmp);
			if (("ZH" + Strtmp) == JieAccountSPYZ(OutStrtmp))
			{
				getline(GetAccount, OutStrtmp);
				continue;
			}
			OutAccount << OutStrtmp << endl;
		}
		GetAccount.close();
		OutAccount.close();
		remove(SPYAccountDAT);
		rename("DatTmp.dat", SPYAccountDAT);
		return 1;
	}
}
//展示售票员信息↓
void SPYAccountShow()
{
	for (int i = 0; i < 15; ++i)
	{
		cout << '*';
	}
	cout << "售票员信息如下";
	for (int i = 0; i < 15; ++i)
	{
		cout << '*';
	}
	cout << endl << endl;
	cout << "用户名\t\t\t  密码\n";
	string AccountStrTmp;
	ifstream GetAccount(SPYAccountDAT);
	if (GetAccount.is_open())
	{
		int Flag = 0;
		while (!GetAccount.eof())
		{
			getline(GetAccount, AccountStrTmp);
			if (AccountStrTmp.size() > 8)
			{
				if (Flag % 2)
				{
					AccountStrTmp = JieAccountSPYM(AccountStrTmp);
					AccountStrTmp = AccountStrTmp.substr(2);
					cout << AccountStrTmp;
					cout << "\n";
				}
				else
				{
					AccountStrTmp = JieAccountSPYZ(AccountStrTmp);
					AccountStrTmp = AccountStrTmp.substr(2);
					cout << AccountStrTmp;
					cout << "\t\t";
				}
				Flag++;
			}
		}
	}
	GetAccount.close();
}
//修改售票员密码
int ChangeSPY(string SPY_ID_Tmp)
{
	string SPY_MM_Tmp;
	shuru C_SPY;
	C_SPY.tishi("请输入旧密码:");
	SPY_MM_Tmp = C_SPY.zimuandshuzi();
	if (SPY_MM_Tmp == SPY_MM)
	{
		C_SPY.tishi("请输入新密码:");
		SPY_MM_Tmp = C_SPY.zimuandshuzi();
		DelSPY(SPY_ID_Tmp);
		ofstream Out_SPY(SPYAccountDAT,ios::app);
		Out_SPY << JiaAccountSPYZ(("ZH" + SPY_ID_Tmp)) << endl
			<< JiaAccountSPYM(("MM" + SPY_MM_Tmp)) << endl;

	}
	else
	{
		MessageBox(hWnd, L"密码验证失败", L"提示", NULL);
		return 0;
	}
}
/*************************************************************************************************************/

//添加用户UI
int AddAccount()
{

	xuanzecaidan ADDaccount;
	ADDaccount.tianjiacaidan("\t***********************选择需要添加的账户***********************\n", 1);
	ADDaccount.tianjiacaidan("经理账户");
	ADDaccount.tianjiacaidan("售票员账户");
	switch (ADDaccount.jiantoucaidan())
	{
	case 1:
		ADDJL();
		break;
	case 2:
		ADDSPY();
		break;
	default:
		break;
	}
	return 0;
}
//删除用户UI
int DelAccount()
{
	xuanzecaidan ADDaccount;
	system("cls");
	ADDaccount.tianjiacaidan("\t***********************选择需要删除的账户***********************\n", 1);
	ADDaccount.tianjiacaidan("经理账户");
	ADDaccount.tianjiacaidan("售票员账户");
	string AccountID;
	switch (ADDaccount.jiantoucaidan())
	{
	case 1:
		JLAccountShow();
		cout << "\n请输入需要删除的经理用户名：";
		cin >> AccountID;
		if (DelJL(AccountID))MessageBox(hWnd, L"修改成功", L"提示", NULL);
		break;
	case 2:
		SPYAccountShow();
		cout << "请输入需要删除的售票员用户名：";
		cin >> AccountID;
		if (DelSPY(AccountID))MessageBox(hWnd, L"修改成功", L"提示", NULL);
		break;
	default:
		break;
	}
	return 0;
}
//用户管理UI
int ACCOUNT_admin()
{
//	if (!AdminLogin())return 0;
	xuanzecaidan Account_Admin;
	
	Account_Admin.tianjiacaidan("\t***********************账户管理***********************\n", 1);
	Account_Admin.tianjiacaidan("添加新用户");
	Account_Admin.tianjiacaidan("删除一个用户");
	Account_Admin.tianjiacaidan("查看用户信息");
	Account_Admin.tianjiacaidan("修改管理员密码");
	Account_Admin.tianjiacaidan("返回上级菜单");
	while (1)
	{
		system("cls");
		switch (Account_Admin.jiantoucaidan())
		{
		case 1:
			AddAccount();
			break;
		case 2:
			DelAccount();
			break;
		case 3:
			SPYAccountShow();
			JLAccountShow();
			system("pause");
			break;
		case 4:
			ChangeAdmin();
			break;
		case 5:
			return 0;
		default:
			break;
		}
	}
	return 0;
}
//用户登录UI↓
int Login() 
{
	ifstream GetAdmin(AdminAccountDAT);
	if (!GetAdmin.is_open())
	{
		MessageBox(hWnd, L"暂无管理员账户，即将进入管理员注册系统", L"提示", NULL);
		Initadmin();
	}
	GetAdmin.close();
	xuanzecaidan LoginMenu;
	LoginMenu.tianjiacaidan("\t***********************选择登录账户***********************\n", 1);
	LoginMenu.tianjiacaidan("管理员登录");
	LoginMenu.tianjiacaidan("经理登录");
	LoginMenu.tianjiacaidan("售票员登录");
	while (1)
	{
		string ceshi;
		switch (LoginMenu.jiantoucaidan())
		{
		case 1:
			if (AdminLogin())
			{
				MessageBox(hWnd, L"验证通过", L"提示", NULL);
				return 1;
			}
			else
			{
				MessageBox(hWnd, L"验证失败", L"提示", NULL);
			}
			break;
		case 2:
			if (JLLogin())
			{
				MessageBox(hWnd, L"验证通过", L"提示", NULL);
				return 2;
			}
			else
			{
				MessageBox(hWnd, L"验证失败", L"提示", NULL);
			}
			break;
		case 3:
			if (SPYLogin())
			{
				MessageBox(hWnd, L"验证通过", L"提示", NULL);
				return 3;
			}
			else
			{
				MessageBox(hWnd, L"验证失败", L"提示", NULL);
			}
			break;
		}
	}
	return 0;
}