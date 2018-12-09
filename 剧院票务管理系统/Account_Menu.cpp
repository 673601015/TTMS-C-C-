#include<iostream>
#include<string>
#include"caidan.h"
using namespace std;

extern string SPY_ID;
extern string JL_ID;
extern int ChangeSPY(string SPY_ID_Tmp);
extern int ChangeJL(string JL_ID_Tmp);
extern int Ticket_Menu();
extern int Schedule_Menu();
extern int Seat_Menu();
extern int ACCOUNT_admin();
extern int Schdule_Show();
extern int Show_Ticket_DAT(string Schdule_ID);
extern int Play_Menu();
extern int Studio_Menu();
extern int  Creat_Ticket();
//管理员菜单UI
int Admin_Menu()
{
	xuanzecaidan Admin_Menu_Tmp;
	Admin_Menu_Tmp.tianjiacaidan("\t***********************管理员菜单***********************\n", 1);
	Admin_Menu_Tmp.tianjiacaidan("演出计划管理");
	Admin_Menu_Tmp.tianjiacaidan("演出厅管理");
	Admin_Menu_Tmp.tianjiacaidan("演出厅座位修改查看");
	Admin_Menu_Tmp.tianjiacaidan("用户管理");
	Admin_Menu_Tmp.tianjiacaidan("剧目管理");
	Admin_Menu_Tmp.tianjiacaidan("产生票");
	Admin_Menu_Tmp.tianjiacaidan("退出程序");
	while (1)
	{
		switch (Admin_Menu_Tmp.jiantoucaidan())
		{
		case 1:
			Schedule_Menu();
			break;
		case 2:
			Studio_Menu();
			break;
		case 3:
			Seat_Menu();
			break;
		case 4:
			ACCOUNT_admin();
			break;
		case 5:
			Play_Menu();
				break;
		case 6:
			Creat_Ticket();
			break;
		default:
			exit(0);
			break;
		}
	}
	return 0;
}
//经理菜单UI
int JL_Menu()
{
	xuanzecaidan JL_Menu_Tmp;
	string Input_Tmp;
	JL_Menu_Tmp.tianjiacaidan("\t***********************经理菜单\
***********************\n\t当前登录账号为:"+ JL_ID, 1);
	JL_Menu_Tmp.tianjiacaidan("演出计划管理");
	JL_Menu_Tmp.tianjiacaidan("剧目管理");
	JL_Menu_Tmp.tianjiacaidan("演出厅管理");
	JL_Menu_Tmp.tianjiacaidan("查看演出计划票务状态");
	JL_Menu_Tmp.tianjiacaidan("修改密码");
	JL_Menu_Tmp.tianjiacaidan("退出程序");
	while (1)
	{
		switch (JL_Menu_Tmp.jiantoucaidan())
		{

		case 1:
			Schedule_Menu();
			break;
		case 2:
			Play_Menu();
			break;
		case 3:
			Studio_Menu();
			break;
		case 4:
			cout << "请输入需要查询票务信息的演出计划ID:";
			cin >> Input_Tmp;
			Show_Ticket_DAT(Input_Tmp);
			break;
		case 5:
			ChangeJL(JL_ID);
			break;
		default:
			exit(0);
			break;
		}
	}
	return 0;
}
//售票员菜单UI
int SPY_Menu()
{
	xuanzecaidan SPY_Menu_Tmp;
	string Input_Tmp;
	SPY_Menu_Tmp.tianjiacaidan("\t***********************售票员菜单\
***********************\n\t当前登录账号为:"+SPY_ID, 1);
	SPY_Menu_Tmp.tianjiacaidan("查询演出");
	SPY_Menu_Tmp.tianjiacaidan("查询演出票");
	SPY_Menu_Tmp.tianjiacaidan("售票或退票");
	SPY_Menu_Tmp.tianjiacaidan("修改密码");
	SPY_Menu_Tmp.tianjiacaidan("退出程序");
	while (1)
	{
		switch (SPY_Menu_Tmp.jiantoucaidan())
		{
		case 1:
			Schdule_Show();
			break;
		case 2:
			cout << "请输入需要查询票务信息的演出计划ID:";
			cin >> Input_Tmp;
			Show_Ticket_DAT(Input_Tmp);
			break;
		case 3:
			Ticket_Menu();
			break;
		case 4:
			ChangeSPY(SPY_ID);
			break;
		default:
			exit(0);
			break;
		}
	}
	return 0;
}