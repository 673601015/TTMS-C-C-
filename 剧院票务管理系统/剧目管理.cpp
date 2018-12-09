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

//操作剧目信息时查找id
jumu *find(jumu *head)
{
	int id;
	printf("\n\n\t\t请输入操作的的剧目的id：");
	scanf("%d", &id);
	jumu *p = head;
	while (p&&p->id != id)
	{
		p = p->next;
	}
	return p;
}

//从文件读取信息入链表
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

//将链表信息存储如文件
int save_list(jumu *head)
{
	struct jumu *jm;
	FILE *fp = fopen("jumu.dat", "wt+");
	if (fp == NULL)
	{
		printf("打开文件失败!");
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

//打印所有剧目信息，5个剧目一页。
void printall(struct jumu *head)
{
	system("cls");
	int n = 1;
	int page = 1;
	printf("\n\n                          剧目信息表                         第%d页\n\n", page);
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	printf("      剧目id           剧目名称          导演            主角      \n\n");
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
			printf("\n\n                          剧目信息表                         第%d页\n\n", ++page);
			printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
			printf("      剧目id           剧目名称          导演            主角      \n\n");
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
//添加新剧目
void addjumu()
{
	Init_Play_Dat();
	system("cls");
	printf("\n\n\t   >>>>> 剧 目 添 加 页 面 <<<<<");
	FILE *fp;
	//以文件是否存在，判断第一次进入添加剧目系统
	if ((fp = fopen("jumu.dat", "rb")) == NULL)
	{
		fp = fopen("jumu.dat", "wb+");
		fclose(fp);
		char choice;
		int icount = 1;
		struct jumu *head = (struct jumu *)malloc(sizeof(struct jumu)), *jm, *p;
		head->next = NULL;
		jm = p = (struct jumu *)malloc(sizeof(struct jumu));
		printf("\n\n\t   暂时无剧目信息，请录入剧目信息。\n\n");
		jm->id = icount;
		printf("\t   请输入id为%d的剧目信息：\n\n", jm->id);
		printf("\t   剧目名称：");
		scanf("%s", jm->name);
		printf("\t   导演名称：");
		scanf("%s", jm->direct);
		printf("\t   主角名称：");
		scanf("%s", jm->actor);
		getchar();
		jm->next = NULL;
		head->next = jm;
		p = head;

		/*printf("\n添加剧目成功。\n\n");
		printf("是否继续输入？（Y/N）");
		choice = getchar();

		while (choice == 'y' || choice == 'Y')
		{
			++icount;
			jm = (struct jumu *)malloc(sizeof(struct jumu));
			jm->id = icount;
			printf("\n\t   请输入id为%d的剧目信息：\n\n", jm->id);
			printf("\t   剧目名称：");
			scanf("%s", jm->name);
			printf("\t   导演名称：");
			scanf("%s", jm->direct);
			printf("\t   主角名称：");
			scanf("%s", jm->actor);
			getchar();
			jm->next = NULL;
			while (p->next)
			{
				p = p->next;
			}
			p->next = jm;
			printf("\n添加剧目成功。\n\n");
			printf("是否继续输入？（Y/N）");
			choice = getchar();
		}*/
		save_list(head);
	}
	//非第一次进入添加剧目系统
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
		printf("\t\t新添加剧目id编号为：%d\n\n", p->id);
		printf("\t\t输入剧目名称：\t");
		scanf("%s", p->name);
		printf("\n\t\t输入剧目导演：\t");
		scanf("%s", p->direct);
		printf("\n\t\t输入剧目主角：\t");
		scanf("%s", p->actor);
		p->next = NULL;

		while (q->next)
		{
			q = q->next;
		}
		q->next = p;
		save_list(head);
	}
	MessageBox(hWnd, L"添加成功", L"提示", NULL);

}

//修改剧目信息
int xiugai(jumu *head)
{
	system("cls");
	int id;
	printf("\n\n\t       >>>>> 剧 目 修 改 页 面 <<<<<");
	jumu *p = find(head);
	if (p)
	{
		printf("\n\n\t\t该剧目的信息如下：\n");
		printf("\n\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
		printf("\t      剧目id           剧目名称          导演            主角      \n\n");
		printf("\t\t%-15d%-15s   %-15s %-15s\n\n", p->id, p->name, p->direct, p->actor);
		printf("\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
		printf("\t\t输入新的剧目名称：\t");
		scanf("%s", p->name);
		printf("\n\t\t输入新的导演名称：\t");
		scanf("%s", p->direct);
		printf("\n\t\t输入新的主角名称：\t");
		scanf("%s", p->actor);
	}
	else
	{
		MessageBox(hWnd, L"未查询到该剧目信息，请检查输入", L"提示", NULL);
		return 0;
	}

	save_list(head);

	MessageBox(hWnd, L"修改成功", L"提示", NULL);
}

//删除剧目信息
int shanchu(jumu *head)
{
	system("cls");
	printf("\n\n\t       >>>>> 剧 目 删 除 页 面 <<<<<");
	int id;
	//打印需要删除的剧目的信息
	jumu *r = find(head);
	if (r)
	{
		printf("\n\n\t\t该剧目的信息如下：\n");
		printf("\n\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
		printf("\t      剧目id           剧目名称          导演            主角      \n\n");
		printf("\t\t%-15d%-15s   %-15s %-15s\n\n", r->id, r->name, r->direct, r->actor);
		printf("\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	}
	else
	{
		MessageBox(hWnd, L"未查询到该剧目信息，请检查输入", L"提示", NULL);
		return 0;
	}

	printf("\n\n\t\t请再次输入删除次剧目id（%d）确认删除：", r->id);
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
	MessageBox(hWnd, L"删除剧目成功", L"提示", NULL);
}

int Play_Menu()
{
	
	FILE *fp;
	struct jumu *head;
	xuanzecaidan JumuMenu;
	JumuMenu.tianjiacaidan("\t\t\t     * * * * * * * * * * * * * * * * * * * * *\n", 1);
	JumuMenu.tianjiacaidan("\t\t\t     *            剧目管理系统               *\n", 1);
	JumuMenu.tianjiacaidan("\t\t\t     * * * * * * * * * * * * * * * * * * * * *\n", 1);
	JumuMenu.tianjiacaidan("*             1.获取全部剧目              *\n");
	JumuMenu.tianjiacaidan("*             2.添加新剧目                *\n");
	JumuMenu.tianjiacaidan("*             3.修改剧目                  *\n");
	JumuMenu.tianjiacaidan("*             4.删除剧目                  *\n");
	JumuMenu.tianjiacaidan("*             5.返回主菜单                *\n\n\t\t\t     * * * * * * * * * * * * * * * * * * * * * * \n");
	while (1)
	{
		switch (JumuMenu.jiantoucaidan())
		{
		case 1:
			if ((fp = fopen("jumu.dat", "r")) == NULL)
			{
				MessageBox(hWnd, L"暂无剧目信息", L"提示", NULL);
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
				MessageBox(hWnd, L"暂无剧目信息", L"提示", NULL);
				break;
			}
			xiugai(head); break;
		case 4:
			if ((head = read_list()) == NULL)
			{
				MessageBox(hWnd, L"暂无剧目信息", L"提示", NULL);
				break;
			};
			shanchu(head); break;
		case 5:
			return 0;
		}
	}
	return 0;
}