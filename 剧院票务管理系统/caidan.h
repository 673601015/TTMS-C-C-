#ifndef XUANZECAIDAN_H_
#define XUANZECAIDAN_H_
#define zuidacaidanshu 64
#include<string>
#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;
class xuanzecaidan
{
private:
	string caidanming;
	int caidanweizhi[zuidacaidanshu * 3];
	int caidanshu;
	int wuxiaocaidan=0;
public:
	xuanzecaidan()
	{
		caidanshu = 0;
	}
	void tianjiacaidan(string a)
	{
		int m;
		m = caidanming.size();
		caidanming += a;
		int i = caidanshu * 3;
		caidanweizhi[i] = (int)(m / 100);
		i++;
		caidanweizhi[i] = (int)((m % 100) / 10);
		i++;
		caidanweizhi[i] = (int)(m % 10);
		caidanshu++;
	};
	void tianjiacaidan(string a,int wuxiao)
	{
		if (wuxiao == 1)wuxiaocaidan++;
		int m;
		m = caidanming.size();
		caidanming += a;
		int i = caidanshu * 3;
		caidanweizhi[i] = (int)(m / 100);
		i++;
		caidanweizhi[i] = (int)((m % 100) / 10);
		i++;
		caidanweizhi[i] = (int)(m % 10);
		caidanshu++;
	};
	void show(int a)
	{
		int m, caidantou;
		for (int i = 0; i < wuxiaocaidan; ++i)
		{
			int caidanmo;
			m = i * 3;
			caidantou = caidanweizhi[m] * 100;
			m++;
			caidantou += (caidanweizhi[m] * 10);
			m++;
			caidantou += caidanweizhi[m];
			m++;
			caidanmo = caidanweizhi[m] * 100;
			m++;
			caidanmo += (caidanweizhi[m] * 10);
			m++;
			caidanmo += caidanweizhi[m];
			if (i == (a - 1))cout << (char)16;
			for (int ii = caidantou; ii < caidanmo; ii++)
			{
				cout << caidanming[ii];
			}
			cout << endl;
		}
		for (int i = wuxiaocaidan; i < caidanshu - 1; i++)
		{
			int caidanmo;
			m = i * 3;
			caidantou = caidanweizhi[m] * 100;
			m++;
			caidantou += (caidanweizhi[m] * 10);
			m++;
			caidantou += caidanweizhi[m];
			m++;
			caidanmo = caidanweizhi[m] * 100;
			m++;
			caidanmo += (caidanweizhi[m] * 10);
			m++;
			caidanmo += caidanweizhi[m];
			cout << "\t\t\t     ";
			if (i == (a - 1))cout << (char)16;
			for (int ii = caidantou; ii < caidanmo; ii++)
			{
				cout << caidanming[ii];
			}
			cout << endl;
		}
		if (caidanshu > 0)
		{
			int i = caidanshu - 1;
			m = i * 3;
			caidantou = caidanweizhi[m] * 100;
			m++;
			caidantou += (caidanweizhi[m] * 10);
			m++;
			caidantou += caidanweizhi[m];
			cout << "\t\t\t     ";
			if (i == (a - 1))cout << (char)16;
			for (int ii = caidantou; caidanming[ii] != '\0'; ii++)
			{
				cout << caidanming[ii];
			}
			cout << endl;
		}
	};
	int caidanshuzhi()
	{
		return caidanshu;
	}
	int jiantoucaidan()
	{
		int a = 1+wuxiaocaidan;
		while (1)
		{
			system("cls");
			show(a);
			int ch;
			ch = _getch();
			switch (ch)
			{
			case (int)'w':if (a > wuxiaocaidan+1)a--;
						  else if (a == wuxiaocaidan+1)
						  {
							  a = caidanshuzhi();
						  }
				break;
			case (int)'s':if (a < caidanshuzhi())a++;
						  else if(a==caidanshuzhi())
						  {
							  a = 1 + wuxiaocaidan;
						  }
				break;
			case 72:if (a > wuxiaocaidan + 1)a--;
						  else if (a == wuxiaocaidan + 1)
						  {
							  a = caidanshuzhi();
						  }
						  break;
			case 80:if (a < caidanshuzhi())a++;
						  else if (a == caidanshuzhi())
						  {
							  a = 1 + wuxiaocaidan;
						  }
						  break;
			case 13:return a-wuxiaocaidan;
				break;
			default:
				break;
			}
		}
	}
};
#endif