#ifndef SHURU_H_
#define SHURU_H_
#include<string>
#include<iostream>
#include<conio.h>
using namespace std;
class shuru
{
private:
	string strName;
	string strTmp;
public:
	shuru()
	{
		strName = "";
		strTmp = "";
	}
	void tishi(string Tishi)
	{
		strName = Tishi;
		strTmp = "";
	}
	string shuzi()
	{
		char ch;
		system("cls");
		cout << strName;
		cout << strTmp;
		while ((ch = _getch() )!= 13||strTmp.size()==0)
		{
			
			if (ch >= '0'&&ch <= '9')
			{
				strTmp += ch;
			}
			if (ch == 8 && strTmp.size() > 0)
			{
				strTmp = strTmp.substr(0, strTmp.size()-1);
			}
			system("cls");
			cout << strName;
			cout  << strTmp;
		}
		return strTmp;
	}
	string zimu()
	{
		char ch;
		system("cls");
		cout << strName;
		cout << strTmp;
		while ((ch = _getch()) != 13 || strTmp.size() == 0)
		{
			
			if ((ch >= 'a'&&ch <= 'z')|| (ch >= 'A'&&ch <= 'Z'))
			{
				strTmp += ch;
			}
			if (ch == 8 && strTmp.size() > 0)
			{
				strTmp = strTmp.substr(0, strTmp.size() - 1);
			}
			system("cls");
			cout << strName;
			cout  << strTmp;
		}
		return strTmp;
	}
	string shuziandxiaoshu()
	{
		char ch;
		system("cls");
		cout << strName;
		cout << strTmp;
		while ((ch = _getch()) != 13 || strTmp.size() == 0||strTmp[0]=='.')
		{

			if ((ch >= '0'&&ch <= '9')||ch=='.')
			{
				strTmp += ch;
			}
			if (ch == 8 && strTmp.size() > 0)
			{
				strTmp = strTmp.substr(0, strTmp.size() - 1);
			}
			system("cls");
			cout << strName;
			cout << strTmp;
		}
		return strTmp;
	}
	string zimuandshuzi()
	{
		char ch;
		system("cls");
		cout << strName;
		cout << strTmp;
		while ((ch = _getch()) != 13 || strTmp.size() == 0)
		{
			
			if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z')|| (ch >= '0'&&ch <= '9'))
			{
				strTmp += ch;
			}
			if (ch == 8 && strTmp.size() > 0)
			{
				strTmp = strTmp.substr(0, strTmp.size() - 1);
			}
			system("cls");
			cout << strName;
			cout << strTmp;
		}
		return strTmp;
	}
};
#endif // !SHURU_H_
