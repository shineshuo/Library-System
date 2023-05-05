
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include"library_mag.h"
#include"floor.h"
#include"book.h"
#include"floor1.h"
#include"floor2.h"
#include"floor3.h"
#include"serchroad.h"
#include"register.h"
#include<graphics.h>
using namespace std;
void mainmenu(library_mag *lm, floor_* lib_col);
void menu(int a, library_mag *lm, floor_* lib_col);
void firstmenu(user* Newuser);
void menu_user(int a, library_mag* lm, floor_* lib_col, user* User);
void mainmenu_user(library_mag* lm, floor_* lib_col, user* User);
int flag_select;

bool flag;//��¼�����жϱ�־   TRUEΪ��Ч��¼
int main()
{
	while (1)
	{
		floor_* lib_col = NULL;//����ָ��ָ������
		library_mag* lm = NULL;
		user* Newuser = new user;

		int select;
		flag_select = -1;
		firstmenu(Newuser);
		while (1)
		{
			
			if (flag_select == 1)
			{
				cout << "ѡ��ǰ����¥��,��0�˳�ϵͳ" << endl;
				cin >> select;
				switch (select)
				{
				case 1:
					lm = new library_mag(1);
					lib_col = new floor1(1, 2, 1);
					break;
				case 2:
					lm = new library_mag(2);
					lib_col = new floor2(1, 2, 2);
					break;
				case 3:
					lm = new library_mag(3);
					lib_col = new floor3(1, 2, 3);
					break;
				case 0:exit(0);
					break;
				default:break;
				};
				lm->bookread();
				mainmenu(lm, lib_col);
			}
			else if (flag_select == 2)
			{
				cout << "ѡ��ǰ����¥��,��0�˳�ϵͳ" << endl;
				cin >> select;
				switch (select)
				{
				case 1:
					lm = new library_mag(1);
					lib_col = new floor1(1, 2, 1);
					break;
				case 2:
					lm = new library_mag(2);
					lib_col = new floor2(1, 2, 2);
					break;
				case 3:
					lm = new library_mag(3);
					lib_col = new floor3(1, 2, 3);
					break;
				case 0:exit(0); break;
				default:break;
				};
				lm->bookread();
				mainmenu_user(lm, lib_col, Newuser);
			}
		}

		delete lib_col;
		delete lm;
		delete Newuser;
		printf("ллʹ�ã��ټ�\n");
		system("pause");

	}
	
	
	return 0;
}

void firstmenu(user*Newuser) {
	//��¼����
	
A:	system("cls");
	printf("----------------------------------------------------------------\n");
	printf("                       ���ã����ȵ�¼                           \n");
	printf("                      ��ǰ״̬��δ��¼                          \n");
	printf("                         1.�������˻�                           \n");
	printf("                         2.��Ҫע���˻�                         \n");
	printf("                         0.�˳�                                 \n");
	printf("----------------------------------------------------------------\n");
	int k;
	scanf("%d", &k);
	getchar();
	int flag_ = 1;
	//ѡ���¼��ʽ
	
	switch (k) {
	case 1:
		while (flag_==1)
		{
			flag_ = 1;
		system("cls");
		printf("1.����Ա��Ȩ���¼\n2.��ͨ�û���¼\n0.�˳�\n");
		scanf("%d", &flag_select);
		getchar();
		if (flag_select == 1) {
			flag = Newuser->super_login();
			flag_ = 0;
			if (!flag) {
				system("cls");
				goto A;
			}
		}
		else if (flag_select == 2) {
			system("cls");
			flag=Newuser->nomal_login();
			flag_ = 0;
			if (!flag) {
				system("cls");
				goto A;
			}
		}
		else if (flag_select == 0)
		{
			flag_ = 0;
		}
		else
		{
			cout << "��������"<<endl;
			system("pause");
		}

		}
		break;
	case 2:
		system("cls");
		flag=Newuser->registerNuser();
		getchar();
		if (!flag) {
			system("cls");
			goto A;
		}goto A;
		break;
	case 0:
		printf("��лʹ�ñ�ϵͳ\n");
		system("pause");
		exit(0);
	default :
		goto A;
		break;
	}
}

void mainmenu(library_mag *lm, floor_* lib_col)//���ƶ˲˵�
{

	while(1)
	{	

		system("CLS");
	//��ʼ��¥����Ϣ
	lib_col->init();
	lib_col->map[lib_col->init_y][lib_col->init_x] = 2;
	for (int i = 0; i < lm->m_booknum; i++)
	{

		lib_col->map[lm->bookarray[i]->y][lm->bookarray[i]->x] = 4;
		if (lm->bookarray[i]->user[0] != '0')
		{
			lib_col->map[lm->bookarray[i]->y][lm->bookarray[i]->x] = 0;
		}
	}
	//
	show_map(lib_col->map);
	printf("----------------------------------------------------------------\n");
	printf("|\t\t\t  ͼ�����ϵͳ  \t\t\t|\n");
	printf("|\t\t\t 1.����ͼ����Ϣ \t\t\t|\n");
	printf("|\t\t\t 2.�޸�ͼ����Ϣ \t\t\t|\n");
	printf("|\t\t\t   0.�˳�   \t\t\t|\n");
	printf("----------------------------------------------------------------\n");
	printf("��������ѡ����(0~3)\n");
	
	int x;
	int a=0;
		scanf("%d",&x);
		getchar();
		switch(x)
		{
			case 0:menu(0,lm, lib_col);break;
			case 1:menu(1,lm, lib_col);break;
			case 2:menu(2,lm, lib_col);break;
			default:printf("��������");
				system("pause");
		}
		if (x == 0)
		{
			break;
		}
	}
}
void mainmenu_user(library_mag* lm, floor_* lib_col,user*User)//�û��˲˵�
{	

	while (1)
	{

		system("CLS");
		//��ʼ��¥����Ϣ
		lib_col->init();
		lib_col->map[lib_col->init_y][lib_col->init_x] = 2;
		for (int i = 0; i < lm->m_booknum; i++)
		{
			
			lib_col->map[lm->bookarray[i]->y][lm->bookarray[i]->x] = 4;
			if (lm->bookarray[i]->user[0] != '0')
			{
				lib_col->map[lm->bookarray[i]->y][lm->bookarray[i]->x] = 0;
			}
		}
		//
		show_map(lib_col->map);
		printf("----------------------------------------------------------------\n");
		printf("|                        ͼ�����ϵͳ                          |\n");
		printf("|                        1.����ͼ����Ϣ                        |\n");
		printf("|                         2.��ȡͼ��                           |\n");
		printf("|                            3.����                            |\n");
		printf("|                        4.Ѱ���鼮λ��                        |\n");
		printf("|                           0.�˳�                             |\n");
		printf("----------------------------------------------------------------\n");
		printf("��������ѡ����(0~4)\n");
		int x;
		int a = 0;
		scanf("%d", &x);
		getchar();
		switch (x)
		{
		case 0:menu_user(0, lm, lib_col,User); break;
		case 1:menu_user(1, lm, lib_col,User); break;
		case 2:menu_user(2, lm, lib_col,User); break;
		case 3:menu_user(3, lm, lib_col,User); break;
		case 4:menu_user(4, lm, lib_col, User); break;
		default:printf("��������");
			system("pause");
		}
		if (x == 0)
		{
			break;
		}
	}
}


void menu(int a, library_mag *lm, floor_* lib_col)
{
	int flag = 1;
	int x;
	if(a==0)
	{
		lm->save();
		system("CLS");
	
	
	}
	else if(a==1)
	{while(flag==1)
		{
		system("CLS");
		printf("----------------------------------------------------------------\n");
		printf("|\t\t\t1.����������\t\t\t\t|\n");
		printf("|\t\t\t2.�����߲���\t\t\t\t|\n");
		printf("|\t\t\t3.��ʾ������Ϣ\t\t\t\t|\n");
		printf("|\t\t\t0.�����ϼ��˵�\t\t\t\t|\n");
		printf("----------------------------------------------------------------\n");
		printf("��������ѡ����(0~3)\n");
		
			scanf("%d",&x);
			getchar();
			if(x==0)flag=0;
			else if(x==1)lm->part1(1);
			else if(x==2)lm->part1(2);
			else if(x==3)lm->part1(3);
			else printf("�����������������\n");
		}
	}
	else if(a==2)
	{
		while(flag==1)
		{
		system("CLS");
		printf("----------------------------------------------------------------\n");
		printf("|\t\t\t1.���ͼ����Ϣ\t\t\t\t|\n");
		printf("|\t\t\t2.ɾ��ͼ����Ϣ\t\t\t\t|\n");
		printf("|\t\t\t3.�޸�ͼ����Ϣ\t\t\t\t|\n");
		printf("|\t\t\t0.�����ϼ��˵�\t\t\t\t|\n");
		printf("----------------------------------------------------------------\n");
		printf("��������ѡ����(0~3)\n");
		
			scanf("%d",&x);
			getchar();
			if(x==0)flag=0;
			else if(x==1)lm->part2(1, lib_col);
			else if(x==2)lm->part2(2, lib_col);
			else if(x==3)lm->part2(3, lib_col);
			else printf("�����������������\n");
		}
	}
	
}


void menu_user(int a, library_mag* lm, floor_* lib_col,user* User)
{
	int flag = 1;
	int x;
	if (a == 0)
	{
		lm->save();
		system("CLS");
		
	
	}
	else if (a == 1)
	{while (flag == 1)
		{
		system("CLS");
		printf("----------------------------------------------------------------\n");
		printf("|\t\t\t1.����������\t\t\t\t|\n");
		printf("|\t\t\t2.�����߲���\t\t\t\t|\n");
		printf("|\t\t\t3.��ʾ������Ϣ\t\t\t\t|\n");
		printf("|\t\t\t0.�����ϼ��˵�\t\t\t\t|\n");
		printf("----------------------------------------------------------------\n");
		printf("��������ѡ����(0~3)\n");
		
			scanf("%d", &x);
			getchar();
			if (x == 0)flag = 0;
			else if (x == 1)lm->part1(1);
			else if (x == 2)lm->part1(2);
			else if (x == 3)lm->part1(3);
		
			else printf("�����������������\n");
		}
	}
	else if (a == 2)
	{
		system("CLS");
		printf("----------------------------------------------------------------\n");
		printf("|\t\t\t1.ѡ��Ҫ��ȡ��ͼ��\t\t\t\t|\n");
		printf("----------------------------------------------------------------\n");
		int i;
		for (i = 0; i < lm->m_booknum; i++)
		{
			printf("%-d %-25s %-12s %.2fԪ\n", i+1, lm->bookarray[i]->name, lm->bookarray[i]->writer, lm->bookarray[i]->price);
		}
		printf("��������ѡ����(ÿ�ν�һ��������0ȡ��)\n");
		while (flag == 1)
		{
			scanf("%d", &x);
			getchar();
			if (x == 0)flag = 0;
			else if (0<x&&x <= lm->m_booknum)
			{
				if (lm->bookarray[x-1]->user[0] != '0')
				{
					cout << "�ѱ�����" << endl;
					system("pause");
					break;
				}
				strcpy(lm->bookarray[x-1]->user, User->account);
				lm->bookarray[x - 1]->flag = 1;
				flag = 0;
			}
			else printf("�����������������\n");
		}
	}
	else if (a == 3)
	{
		system("CLS");
		printf("--------------------------------------------------------------------\n");
		printf("|                 �����С�����������                               |\n");
		printf("--------------------------------------------------------------------\n");
		int i = 0;
		//����󽫶�Ӧ������������������
		for (i = 0; i < lm->m_booknum; i++)
		{
			if (strcmp(lm->bookarray[i]->user, User->account) == 0)
			{
				strcpy(lm->bookarray[i]->user, "0");
				lm->bookarray[i]->flag = 0;
			}
		}
		cout << "�ѻ���"<<endl;
		system("pause");
	}
	else if (a == 4)
	{
		system("CLS");
		lm->part3(lib_col);
	}
}
