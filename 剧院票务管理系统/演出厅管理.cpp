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
		printf("�ݳ���ID:%s\n", temp->ID);
		printf("�ݳ�������%s\n", temp->name);
		printf("�ݳ�����λ����:%s\n", temp->line);
		printf("�ݳ�����λ����:%s\n", temp->column);
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
	printf("\n�ļ��ɹ�����\n");
	system("pause");
}
void Read_inf(struct Perform *h,char ID[100])
{
	struct Perform *per, *temp;
	temp = h;
	per = temp;
	int i;
	printf("\n��ʾID=%s���ݳ���\n", ID); 
	string Str;
	while(1)
	{
		Str = temp->ID;
		if (Str == ID)
			break;
		per = temp;
		temp = temp->next;
	}
	printf("�ݳ���ID:%s\n", temp->ID);
	printf("�ݳ�������%s\n", temp->name);
	printf("�ݳ�����λ����:%s\n", temp->line);
	printf("�ݳ�����λ����:%s\n", temp->column);
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
	printf("������������\n");
	scanf("%s", New->name);
	printf("������������\n");
	scanf("%s", New->line);
	printf("������������\n");
	scanf("%s", New->column);
	New->next = p->next;
	p->next = New;
	return head;
}
int Add_Studio()
{
	int SeatLine, SeatColumn;
	char PerformHotelName[20];
	printf("���������ݳ���������:\n");
	scanf("%s", PerformHotelName);
	printf("\n");
	printf("����������Ҫ��λ����Ϊ���ٵ��ݳ�����ֻ���������֣�\n");
	scanf("%d", &SeatLine);
	printf("\n");
	printf("����������Ҫ��λ����λ���ٵ��ݳ�����ֻ���������֣�\n");
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
	printf("������Ҫ�޸ĵ��ݳ���ID(ֻ���������ּ���):");
	cin >> ID;
	string ID_Tmp = ID;
	if (!Search_Studio(ID_Tmp))
	{
		MessageBox(hWnd, L"���޴�ID", L"��ʾ", NULL);
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
	printf("\n������Ҫɾ����ID(ֻ����������):\n");
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
	cout << "�ݳ���ID\t�ݳ�������\t�ݳ�������\t�ݳ�������\n";
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
	Studio_Menu_Tmp.tianjiacaidan("\t***********************�ݳ�������***********************\n", 1);
	Studio_Menu_Tmp.tianjiacaidan("������ݳ���");
	Studio_Menu_Tmp.tianjiacaidan("�鿴�ݳ���");
	Studio_Menu_Tmp.tianjiacaidan("�޸��ݳ���");
	Studio_Menu_Tmp.tianjiacaidan("ɾ���ݳ���");
	Studio_Menu_Tmp.tianjiacaidan("�����ϼ�");
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
