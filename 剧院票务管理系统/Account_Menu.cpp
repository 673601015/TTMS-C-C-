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
//����Ա�˵�UI
int Admin_Menu()
{
	xuanzecaidan Admin_Menu_Tmp;
	Admin_Menu_Tmp.tianjiacaidan("\t***********************����Ա�˵�***********************\n", 1);
	Admin_Menu_Tmp.tianjiacaidan("�ݳ��ƻ�����");
	Admin_Menu_Tmp.tianjiacaidan("�ݳ�������");
	Admin_Menu_Tmp.tianjiacaidan("�ݳ�����λ�޸Ĳ鿴");
	Admin_Menu_Tmp.tianjiacaidan("�û�����");
	Admin_Menu_Tmp.tianjiacaidan("��Ŀ����");
	Admin_Menu_Tmp.tianjiacaidan("����Ʊ");
	Admin_Menu_Tmp.tianjiacaidan("�˳�����");
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
//����˵�UI
int JL_Menu()
{
	xuanzecaidan JL_Menu_Tmp;
	string Input_Tmp;
	JL_Menu_Tmp.tianjiacaidan("\t***********************����˵�\
***********************\n\t��ǰ��¼�˺�Ϊ:"+ JL_ID, 1);
	JL_Menu_Tmp.tianjiacaidan("�ݳ��ƻ�����");
	JL_Menu_Tmp.tianjiacaidan("��Ŀ����");
	JL_Menu_Tmp.tianjiacaidan("�ݳ�������");
	JL_Menu_Tmp.tianjiacaidan("�鿴�ݳ��ƻ�Ʊ��״̬");
	JL_Menu_Tmp.tianjiacaidan("�޸�����");
	JL_Menu_Tmp.tianjiacaidan("�˳�����");
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
			cout << "��������Ҫ��ѯƱ����Ϣ���ݳ��ƻ�ID:";
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
//��ƱԱ�˵�UI
int SPY_Menu()
{
	xuanzecaidan SPY_Menu_Tmp;
	string Input_Tmp;
	SPY_Menu_Tmp.tianjiacaidan("\t***********************��ƱԱ�˵�\
***********************\n\t��ǰ��¼�˺�Ϊ:"+SPY_ID, 1);
	SPY_Menu_Tmp.tianjiacaidan("��ѯ�ݳ�");
	SPY_Menu_Tmp.tianjiacaidan("��ѯ�ݳ�Ʊ");
	SPY_Menu_Tmp.tianjiacaidan("��Ʊ����Ʊ");
	SPY_Menu_Tmp.tianjiacaidan("�޸�����");
	SPY_Menu_Tmp.tianjiacaidan("�˳�����");
	while (1)
	{
		switch (SPY_Menu_Tmp.jiantoucaidan())
		{
		case 1:
			Schdule_Show();
			break;
		case 2:
			cout << "��������Ҫ��ѯƱ����Ϣ���ݳ��ƻ�ID:";
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