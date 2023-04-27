
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
using namespace std;
//void mainmenu(library_mag *lm, floor_* lib_col);
void menu(int a, library_mag *lm, floor_* lib_col);
void firstmenu();
bool flag;//��¼�����жϱ�־   TRUEΪ��Ч��¼
int main()
{
	floor_* lib_col=NULL;
	library_mag* lm=NULL;
	int select;
	firstmenu();
	while (1)
	{
cout << "ѡ��ǰ����¥��" << endl;
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
	case 0:
	default:break;
	};
	lm->bookread();
	//mainmenu(lm, lib_col);
	}
	
	return 0;
}

void firstmenu() {
	//��¼����
A:	printf("----------------------------------------------------------------\n");
	
	printf("                       ���ã����ȵ�¼                           \n");
	printf("                      ��ǰ״̬��δ��¼                          \n");
	printf("                1.�������˻�     2.��Ҫע���˻�  0.�˳�         \n");
	printf("----------------------------------------------------------------\n");
	int k;
	scanf("%d", &k);
	getchar();
	//ѡ���¼��ʽ
	user Newuser;
	switch (k) {
	case 1:
		system("cls");
		printf("1.����Ա��Ȩ���¼   2.��ͨ�û���¼\n");
		int u;
		
		scanf("%d", &u);
		getchar();
		if (u == 1) {
			flag = Newuser.super_login();
			if (!flag) {
				system("cls");
				goto A;
			}
		}
		if (u == 2) {
			system("cls");
			flag=Newuser.nomal_login();
			if (!flag) {
				system("cls");
				goto A;
			}
		}
		break;
	case 2:
		system("cls");
		flag=Newuser.registerNuser();
		getchar();
		system("cls");
			goto A;
	case 0:
		printf("��лʹ�ñ�ϵͳ\n");
		system("pause");
		exit(0);
	}
}

void mainmenu(bool flag,library_mag *lm, floor_* lib_col)
{
	firstmenu();
	while(1)
	{	

		system("CLS");
	//��ʼ��¥����Ϣ
	lib_col->init();
	lib_col->map[lib_col->init_y][lib_col->init_x] = 2;
	for (int i = 0; i < lm->m_booknum; i++)
	{
		lib_col->map[lm->bookarray[i]->y][lm->bookarray[i]->x] = 4;
	}
	//
	show_map(lib_col->map);
	printf("----------------------------------------------------------------\n");
	printf("|\t\t\t  ͼ�����ϵͳ  \t\t\t|\n");
	printf("|\t\t1.����ͼ����Ϣ \t\t 2.�޸�ͼ����Ϣ\t\t|\n");
	printf("|\t\t3.���й���˾�� \t\t 0.�˳�ϵͳ\t\t|\n");
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
			case 3:menu(3,lm, lib_col);break;
			default:a++;
			if(a<=3)printf("�����������������\n");
			else if(a==4)printf("��Ҫ������!!!\n");
			else if(a==5)exit(0);
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
		printf("ллʹ�ã��ټ�\n");
		system("pause");
		exit(0);
	}
	else if(a==1)
	{
		system("CLS");
		printf("----------------------------------------------------------------\n");
		printf("|\t\t\t1.����������\t\t\t\t|\n");
		printf("|\t\t\t2.�����߲���\t\t\t\t|\n");
		printf("|\t\t\t3.��ʾ������Ϣ\t\t\t\t|\n");
		printf("|\t\t\t0.�����ϼ��˵�\t\t\t\t|\n");
		printf("----------------------------------------------------------------\n");
		printf("��������ѡ����(0~3)\n");
		while(flag==1)
		{
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
		system("CLS");
		printf("----------------------------------------------------------------\n");
		printf("|\t\t\t1.���ͼ����Ϣ\t\t\t\t|\n");
		printf("|\t\t\t2.ɾ��ͼ����Ϣ\t\t\t\t|\n");
		printf("|\t\t\t3.�޸�ͼ����Ϣ\t\t\t\t|\n");
		printf("|\t\t\t0.�����ϼ��˵�\t\t\t\t|\n");
		printf("----------------------------------------------------------------\n");
		printf("��������ѡ����(0~3)\n");
		while(flag==1)
		{
			scanf("%d",&x);
			getchar();
			if(x==0)flag=0;
			else if(x==1)lm->part2(1, lib_col);
			else if(x==2)lm->part2(2, lib_col);
			else if(x==3)lm->part2(3, lib_col);
			else printf("�����������������\n");
		}
	}
	else if(a==3)
	{
		system("CLS");
		printf("--------------------------------------------------------------------\n");
		cout << "�����ǹ���˾��" << lib_col->name_ << endl;
		printf("|\t\t\t1.�������\t\t\t\t\t|\n");
		printf("|\t\t\t2.�����������鼮λ��\t\t\t\t|\n");
		printf("|\t\t\t0.�����ϼ��˵�\t\t\t\t\t|\n");
		printf("--------------------------------------------------------------------\n");
		printf("��������ѡ����(0~3)\n");
		
		while (flag == 1)
		{
			scanf("%d", &x);
			getchar();
			if (x == 0)flag=0;
			else if (x == 1)lm->part3(1, lib_col);
			else if (x == 2)
			{lm->part3(2, lib_col);
			}
			else if (x == 3)lm->part3(3, lib_col);
			else printf("�����������������\n");
		}
	}
}
