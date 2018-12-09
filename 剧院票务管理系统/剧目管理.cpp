#include<stdio.h>
#include<stdlib.h>
#include "caidan.h"
#include<Windows.h>
#include<fstream>
#include<string>
#define PAGE 6
using std::string;

extern HWND hWnd;
struct jumu
{
	int id;
	char name[40];
	char direct[40];
	char actor[40];
	struct jumu *next;
};

//������Ŀ��Ϣʱ����id
jumu *find(jumu *head)
{
	int id;
	printf("\n\n\t\t����������ĵľ�Ŀ��id��");
	scanf("%d", &id);
	jumu *p = head;
	while (p&&p->id != id)
	{
		p = p->next;
	}
	return p;
}

//���ļ���ȡ��Ϣ������
jumu* read_list()
{
	ifstream Get_Play_Dat(".\\jumu.dat");
	if (!Get_Play_Dat)
	{
		Get_Play_Dat.close();
		return NULL;
	}
	Get_Play_Dat.close();
	FILE *fp;
	fp = fopen(".\\jumu.dat","rb");
	struct jumu *r, *jm, *head;
	head = (jumu*)malloc(sizeof(struct jumu));
	r = head;
	while (!feof(fp))
	{
		jm = (jumu*)malloc(sizeof(struct jumu));
		fscanf(fp, "Play_ID=%d\nPlay_Name=%s\nPlay_Dr=%s\nPlay_Ac=%s\n", &jm->id, jm->name, jm->direct, jm->actor);
		r->next = jm;
		r = jm;
	}
	r->next = NULL;
	fclose(fp);
	return head;
}

//��������Ϣ�洢���ļ�
int save_list(jumu *head)
{
	struct jumu *jm;
	FILE *fp = fopen("jumu.dat", "wt+");
	if (fp == NULL)
	{
		printf("���ļ�ʧ��!");
		return 0;
	}
	for (jm = head->next; jm != NULL; jm = jm->next)
	{
		fprintf(fp, "Play_ID=%d\n", jm->id);
		fprintf(fp, "Play_Name=%s\n", jm->name);
		fprintf(fp, "Play_Dr=%s\n", jm->direct);
		fprintf(fp, "Play_Ac=%s\n", jm->actor);
	}
	fclose(fp);
	return 0;
}

//��ӡ���о�Ŀ��Ϣ��5����Ŀһҳ��
void printall(struct jumu *head)
{
	system("cls");
	int n = 1;
	int page = 1;
	printf("\n\n                          ��Ŀ��Ϣ��                         ��%dҳ\n\n", page);
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	printf("      ��Ŀid           ��Ŀ����          ����            ����      \n\n");
	struct jumu *jm;
	for (jm = head->next; jm != NULL; jm = jm->next)
	{
		if (n % PAGE != 0)
		{
			printf("\t%-15d%-15s   %-15s %-15s\n\n", jm->id, jm->name, jm->direct, jm->actor);
		}
		else
		{
			system("pause");
			printf("\n\n                          ��Ŀ��Ϣ��                         ��%dҳ\n\n", ++page);
			printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
			printf("      ��Ŀid           ��Ŀ����          ����            ����      \n\n");
			printf("\t%-15d%-15s   %-15s %-15s\n\n", jm->id, jm->name, jm->direct, jm->actor);
		}
		n++;
	}
	system("pause");

}

int Init_Play_Dat()
{
	ifstream Init_Play_Date(".\\jumu.dat");
	if (Init_Play_Date)
	{
		string Str_Tmp;
		for (int i = 0; i < 5; ++i)
		{
			if (Init_Play_Date.eof())
			{
				Init_Play_Date.close();
				remove(".\\jumu.dat");
				return 0;
			}
			getline(Init_Play_Date, Str_Tmp);
		}
	}
	Init_Play_Date.close();
	return 0;
}
//����¾�Ŀ
void addjumu()
{
	Init_Play_Dat();
	system("cls");
	printf("\n\n\t   >>>>> �� Ŀ �� �� ҳ �� <<<<<");
	FILE *fp;
	//���ļ��Ƿ���ڣ��жϵ�һ�ν�����Ӿ�Ŀϵͳ
	if ((fp = fopen("jumu.dat", "rb")) == NULL)
	{
		fp = fopen("jumu.dat", "wb+");
		fclose(fp);
		char choice;
		int icount = 1;
		struct jumu *head = (struct jumu *)malloc(sizeof(struct jumu)), *jm, *p;
		head->next = NULL;
		jm = p = (struct jumu *)malloc(sizeof(struct jumu));
		printf("\n\n\t   ��ʱ�޾�Ŀ��Ϣ����¼���Ŀ��Ϣ��\n\n");
		jm->id = icount;
		printf("\t   ������idΪ%d�ľ�Ŀ��Ϣ��\n\n", jm->id);
		printf("\t   ��Ŀ���ƣ�");
		scanf("%s", jm->name);
		printf("\t   �������ƣ�");
		scanf("%s", jm->direct);
		printf("\t   �������ƣ�");
		scanf("%s", jm->actor);
		getchar();
		jm->next = NULL;
		head->next = jm;
		p = head;

		/*printf("\n��Ӿ�Ŀ�ɹ���\n\n");
		printf("�Ƿ�������룿��Y/N��");
		choice = getchar();

		while (choice == 'y' || choice == 'Y')
		{
			++icount;
			jm = (struct jumu *)malloc(sizeof(struct jumu));
			jm->id = icount;
			printf("\n\t   ������idΪ%d�ľ�Ŀ��Ϣ��\n\n", jm->id);
			printf("\t   ��Ŀ���ƣ�");
			scanf("%s", jm->name);
			printf("\t   �������ƣ�");
			scanf("%s", jm->direct);
			printf("\t   �������ƣ�");
			scanf("%s", jm->actor);
			getchar();
			jm->next = NULL;
			while (p->next)
			{
				p = p->next;
			}
			p->next = jm;
			printf("\n��Ӿ�Ŀ�ɹ���\n\n");
			printf("�Ƿ�������룿��Y/N��");
			choice = getchar();
		}*/
		save_list(head);
	}
	//�ǵ�һ�ν�����Ӿ�Ŀϵͳ
	else
	{
		struct jumu *head, *p, *i, *q;
		head = read_list();
		q = head; i = head;
		p = (struct jumu *)malloc(sizeof(struct jumu));

		while (i->next != NULL)
		{
			i = i->next;
		}
		p->id = i->id + 1;

		printf("\n\n");
		printf("\t\t����Ӿ�Ŀid���Ϊ��%d\n\n", p->id);
		printf("\t\t�����Ŀ���ƣ�\t");
		scanf("%s", p->name);
		printf("\n\t\t�����Ŀ���ݣ�\t");
		scanf("%s", p->direct);
		printf("\n\t\t�����Ŀ���ǣ�\t");
		scanf("%s", p->actor);
		p->next = NULL;

		while (q->next)
		{
			q = q->next;
		}
		q->next = p;
		save_list(head);
	}
	MessageBox(hWnd, L"��ӳɹ�", L"��ʾ", NULL);

}

//�޸ľ�Ŀ��Ϣ
int xiugai(jumu *head)
{
	system("cls");
	int id;
	printf("\n\n\t       >>>>> �� Ŀ �� �� ҳ �� <<<<<");
	jumu *p = find(head);
	if (p)
	{
		printf("\n\n\t\t�þ�Ŀ����Ϣ���£�\n");
		printf("\n\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
		printf("\t      ��Ŀid           ��Ŀ����          ����            ����      \n\n");
		printf("\t\t%-15d%-15s   %-15s %-15s\n\n", p->id, p->name, p->direct, p->actor);
		printf("\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
		printf("\t\t�����µľ�Ŀ���ƣ�\t");
		scanf("%s", p->name);
		printf("\n\t\t�����µĵ������ƣ�\t");
		scanf("%s", p->direct);
		printf("\n\t\t�����µ��������ƣ�\t");
		scanf("%s", p->actor);
	}
	else
	{
		MessageBox(hWnd, L"δ��ѯ���þ�Ŀ��Ϣ����������", L"��ʾ", NULL);
		return 0;
	}

	save_list(head);

	MessageBox(hWnd, L"�޸ĳɹ�", L"��ʾ", NULL);
}

//ɾ����Ŀ��Ϣ
int shanchu(jumu *head)
{
	system("cls");
	printf("\n\n\t       >>>>> �� Ŀ ɾ �� ҳ �� <<<<<");
	int id;
	//��ӡ��Ҫɾ���ľ�Ŀ����Ϣ
	jumu *r = find(head);
	if (r)
	{
		printf("\n\n\t\t�þ�Ŀ����Ϣ���£�\n");
		printf("\n\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
		printf("\t      ��Ŀid           ��Ŀ����          ����            ����      \n\n");
		printf("\t\t%-15d%-15s   %-15s %-15s\n\n", r->id, r->name, r->direct, r->actor);
		printf("\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	}
	else
	{
		MessageBox(hWnd, L"δ��ѯ���þ�Ŀ��Ϣ����������", L"��ʾ", NULL);
		return 0;
	}

	printf("\n\n\t\t���ٴ�����ɾ���ξ�Ŀid��%d��ȷ��ɾ����", r->id);
	scanf("%d", &id);

	jumu *q = NULL, *p = head;
	if (head->id == id)
	{
		head = head->next;
		free(q);
	}
	else
	{
		while (p)
		{
			if (p->id == id)
			{
				q->next = p->next;
				free(p);
				break;
			}
			q = p;
			p = p->next;
		}
	}
	save_list(head);
	MessageBox(hWnd, L"ɾ����Ŀ�ɹ�", L"��ʾ", NULL);
}

int Play_Menu()
{
	
	FILE *fp;
	struct jumu *head;
	xuanzecaidan JumuMenu;
	JumuMenu.tianjiacaidan("\t\t\t     * * * * * * * * * * * * * * * * * * * * *\n", 1);
	JumuMenu.tianjiacaidan("\t\t\t     *            ��Ŀ����ϵͳ               *\n", 1);
	JumuMenu.tianjiacaidan("\t\t\t     * * * * * * * * * * * * * * * * * * * * *\n", 1);
	JumuMenu.tianjiacaidan("*             1.��ȡȫ����Ŀ              *\n");
	JumuMenu.tianjiacaidan("*             2.����¾�Ŀ                *\n");
	JumuMenu.tianjiacaidan("*             3.�޸ľ�Ŀ                  *\n");
	JumuMenu.tianjiacaidan("*             4.ɾ����Ŀ                  *\n");
	JumuMenu.tianjiacaidan("*             5.�������˵�                *\n\n\t\t\t     * * * * * * * * * * * * * * * * * * * * * * \n");
	while (1)
	{
		switch (JumuMenu.jiantoucaidan())
		{
		case 1:
			if ((fp = fopen("jumu.dat", "r")) == NULL)
			{
				MessageBox(hWnd, L"���޾�Ŀ��Ϣ", L"��ʾ", NULL);
				break;
			}
			else
			{
				fclose(fp);
				head = read_list();
				printall(head); 
			}
			break;
		case 2:
			addjumu(); break;
		case 3:
			if ((head = read_list()) == NULL)
			{
				MessageBox(hWnd, L"���޾�Ŀ��Ϣ", L"��ʾ", NULL);
				break;
			}
			xiugai(head); break;
		case 4:
			if ((head = read_list()) == NULL)
			{
				MessageBox(hWnd, L"���޾�Ŀ��Ϣ", L"��ʾ", NULL);
				break;
			};
			shanchu(head); break;
		case 5:
			return 0;
		}
	}
	return 0;
}