#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"caidan.h"
#include<fstream>
#include<string>
struct Perform
{
	char ID[200];
	char name[200];
	char line[200];
	char column[200];
	struct Perform *next;
};
struct Perform *create_inf()
{
	int i = 0;
	struct Perform *head, *r, *per;
	FILE *fp;
	head = (struct Perform *)malloc(sizeof(struct Perform));
	head->next = NULL;
	fp = fopen("PerformHotel.dat", "rt");
	r = head;
	while (!feof(fp))
	{
		per = (struct Perform *)malloc(sizeof(struct Perform));
		fscanf(fp, "ID=%s\nName=%s\nSeatLine=%s\nSeatColumn=%s\n", per->ID, per->name, per->line, per->column);
		r->next = per;
		r = per;
	}
	r->next = NULL;
	fclose(fp);
	return head;
}
extern int Search_Studio(string Studio_ID);
extern HWND hWnd;
void Print_inf(struct Perform *h)
{
	struct Perform *temp;
	temp = h->next;
	while (temp != NULL)
	{
		printf("演出厅ID:%s\n", temp->ID);
		printf("演出厅名称%s\n", temp->name);
		printf("演出厅座位行数:%s\n", temp->line);
		printf("演出厅座位列数:%s\n", temp->column);
		temp = temp->next;

	}
}
void Delete_inf(struct Perform *head, char ID[100])
{
	int i;
	struct Perform *temp;
	struct Perform *per;
	temp = head;
	per = temp;
	string Str = temp->ID;
	while(Str!=ID)
	{
		
		per = temp;
		temp = temp->next;
		Str = temp->ID;
	}
	per->next = temp->next;
	free(temp);
}
void Keep_inf(struct Perform *h)
{
	struct Perform *per;
	FILE *fp;
	fp = fopen("PerformHotel.dat", "wt");
	for (per = h->next; per != NULL; per = per->next)
		fprintf(fp, "ID=%s\nName=%s\nSeatLine=%s\nSeatColumn=%s\n", per->ID, per->name, per->line, per->column);
	fclose(fp);
	printf("\n文件成功保存\n");
	system("pause");
}
void Read_inf(struct Perform *h,char ID[100])
{
	struct Perform *per, *temp;
	temp = h;
	per = temp;
	int i;
	printf("\n显示ID=%s的演出厅\n", ID); 
	string Str;
	while(1)
	{
		Str = temp->ID;
		if (Str == ID)
			break;
		per = temp;
		temp = temp->next;
	}
	printf("演出厅ID:%s\n", temp->ID);
	printf("演出厅名称%s\n", temp->name);
	printf("演出厅座位行数:%s\n", temp->line);
	printf("演出厅座位列数:%s\n", temp->column);
}
struct Perform *insert(struct Perform *head, char ID[100])
{
	struct Perform *New, *p = head;
	int i;
	string Str = p->ID;
	while (Str != ID)
	{
		p = p->next;
		Str = p->ID;
	}
	New = (struct Perform *)malloc(sizeof(struct Perform));
	strcpy(New->ID, ID);
	printf("请输入新名字\n");
	scanf("%s", New->name);
	printf("请输入新行数\n");
	scanf("%s", New->line);
	printf("请输入新列数\n");
	scanf("%s", New->column);
	New->next = p->next;
	p->next = New;
	return head;
}
int Add_Studio()
{
	int SeatLine, SeatColumn;
	char PerformHotelName[20];
	printf("请输入新演出厅的名字:\n");
	scanf("%s", PerformHotelName);
	printf("\n");
	printf("请输入您想要座位列数为多少的演出厅（只需输入数字）\n");
	scanf("%d", &SeatLine);
	printf("\n");
	printf("请输入您想要座位行数位多少的演出厅（只需输入数字）\n");
	scanf("%d", &SeatColumn);
	printf("\n");
	FILE *fp;
	string ID="";
	for (int i = 1;; ++i)
	{
		ID = "";
		for (int m = i; m != 0; m/=10)
		{
			ID = (char)((m % 10) + 48) + ID;
		}
		if (!Search_Studio(ID))
		{
			break;
		}
	}
	fp = fopen("PerformHotel.dat", "a+");
	fprintf(fp, "ID=%s",ID.c_str());
	fputc('\n', fp);
	fprintf(fp, "Name=%s", PerformHotelName);
	fputc('\n', fp);
	fprintf(fp, "SeatLine=%d", SeatLine);
	fputc('\n', fp);
	fprintf(fp, "SeatColumn=%d", SeatColumn);
	fputc('\n', fp);
	fclose(fp);
	return 0;
}

int Change_Studio()
{
	struct Perform *head;
	head = create_inf();
	char ID[100];
	printf("请输入要修改的演出厅ID(只需输入数字即可):");
	cin >> ID;
	string ID_Tmp = ID;
	if (!Search_Studio(ID_Tmp))
	{
		MessageBox(hWnd, L"查无此ID", L"提示", NULL);
		return 0;
	}
	Read_inf(head, ID);
	head = insert(head, ID);
	Delete_inf(head, ID);
	Keep_inf(head);
	return 0;
}

int Del_Studio()
{
	struct Perform *head;
	head = create_inf();
	//Print_inf(head);
	char ID[100];
	printf("\n请输入要删除的ID(只需输入数字):\n");
	cin >> ID;
	Delete_inf(head, ID);
	//Print_inf(head);
	Keep_inf(head);
	return 0;
}

int Studio_Show()
{
	FILE *fp;
	string ID, Name, Seat_Line, Seat_Column;
	char Str_Tmp[100];
	cout << "演出厅ID\t演出厅名称\t演出厅行数\t演出厅列数\n";
	if (fp = fopen("PerformHotel.dat","r"))
	{
		while (1)
		{
			if (feof(fp))
			{
				fclose(fp);
				return 0;
			}
			fscanf(fp, "ID=%s\n", Str_Tmp);
			if (feof(fp))
			{
				fclose(fp);
				return 0;
			}
			ID = Str_Tmp;
			fscanf(fp, "Name=%s\n", Str_Tmp);
			if (feof(fp))
			{
				fclose(fp);
				return 0;
			}
			Name = Str_Tmp;
			fscanf(fp, "SeatLine=%s\n", Str_Tmp);
			Seat_Line = Str_Tmp;
			fscanf(fp, "SeatColumn=%s\n", Str_Tmp);
			Seat_Column = Str_Tmp;
			cout << ID;
			for (int i = 0; i < 16 - ID.size(); ++i)
				cout << " ";
			cout << Name;
			for (int i = 0; i < 16 - Name.size(); ++i)
				cout << " ";
			cout << Seat_Line;
			for (int i = 0; i < 16 - Seat_Line.size(); ++i)
				cout << " ";
			cout << Seat_Column;
			for (int i = 0; i < 16 - Seat_Column.size(); ++i)
				cout << " ";
			cout << endl;
		}
	}
	else
	{

		fclose(fp);
		return 0;

	}

}

int Studio_Menu()
{
	ifstream Init_Studio("PerformHotel.dat");
	if (!Init_Studio.is_open())
	{
		ofstream Creat_Studio("PerformHotel.dat");
		Creat_Studio.close();
	}
	Init_Studio.close();
	xuanzecaidan Studio_Menu_Tmp;
	Studio_Menu_Tmp.tianjiacaidan("\t***********************演出厅管理***********************\n", 1);
	Studio_Menu_Tmp.tianjiacaidan("添加新演出厅");
	Studio_Menu_Tmp.tianjiacaidan("查看演出厅");
	Studio_Menu_Tmp.tianjiacaidan("修改演出厅");
	Studio_Menu_Tmp.tianjiacaidan("删除演出厅");
	Studio_Menu_Tmp.tianjiacaidan("返回上级");
	while (1)
	{
		switch (Studio_Menu_Tmp.jiantoucaidan())
		{
		case 1:
			Add_Studio();
			break;
		case 2:
			Studio_Show();
			system("pause");
			break;
		case 3:
			Change_Studio();
			break;
		case 4:
			Del_Studio();
			break;
		default:
			return 0;
		}
	}
}
