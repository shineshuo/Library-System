
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

bool flag;//登录类型判断标志   TRUE为有效登录
int main()
{
	while (1)
	{
		floor_* lib_col = NULL;//父类指针指向子类
		library_mag* lm = NULL;
		user* Newuser = new user;

		int select;
		flag_select = -1;
		firstmenu(Newuser);
		while (1)
		{
			
			if (flag_select == 1)
			{
				cout << "选择前往的楼层,按0退出系统" << endl;
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
				cout << "选择前往的楼层,按0退出系统" << endl;
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
		printf("谢谢使用，再见\n");
		system("pause");

	}
	
	
	return 0;
}

void firstmenu(user*Newuser) {
	//登录界面
	
A:	system("cls");
	printf("----------------------------------------------------------------\n");
	printf("                       您好，请先登录                           \n");
	printf("                      当前状态：未登录                          \n");
	printf("                         1.我已有账户                           \n");
	printf("                         2.我要注册账户                         \n");
	printf("                         0.退出                                 \n");
	printf("----------------------------------------------------------------\n");
	int k;
	scanf("%d", &k);
	getchar();
	int flag_ = 1;
	//选择登录方式
	
	switch (k) {
	case 1:
		while (flag_==1)
		{
			flag_ = 1;
		system("cls");
		printf("1.管理员授权码登录\n2.普通用户登录\n0.退出\n");
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
			cout << "输入有误"<<endl;
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
		printf("感谢使用本系统\n");
		system("pause");
		exit(0);
	default :
		goto A;
		break;
	}
}

void mainmenu(library_mag *lm, floor_* lib_col)//控制端菜单
{

	while(1)
	{	

		system("CLS");
	//初始化楼层信息
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
	printf("|\t\t\t  图书管理系统  \t\t\t|\n");
	printf("|\t\t\t 1.查找图书信息 \t\t\t|\n");
	printf("|\t\t\t 2.修改图书信息 \t\t\t|\n");
	printf("|\t\t\t   0.退出   \t\t\t|\n");
	printf("----------------------------------------------------------------\n");
	printf("输入数字选择功能(0~3)\n");
	
	int x;
	int a=0;
		scanf("%d",&x);
		getchar();
		switch(x)
		{
			case 0:menu(0,lm, lib_col);break;
			case 1:menu(1,lm, lib_col);break;
			case 2:menu(2,lm, lib_col);break;
			default:printf("输入有误");
				system("pause");
		}
		if (x == 0)
		{
			break;
		}
	}
}
void mainmenu_user(library_mag* lm, floor_* lib_col,user*User)//用户端菜单
{	

	while (1)
	{

		system("CLS");
		//初始化楼层信息
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
		printf("|                        图书管理系统                          |\n");
		printf("|                        1.查找图书信息                        |\n");
		printf("|                         2.借取图书                           |\n");
		printf("|                            3.还书                            |\n");
		printf("|                        4.寻找书籍位置                        |\n");
		printf("|                           0.退出                             |\n");
		printf("----------------------------------------------------------------\n");
		printf("输入数字选择功能(0~4)\n");
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
		default:printf("输入有误");
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
		printf("|\t\t\t1.按书名查找\t\t\t\t|\n");
		printf("|\t\t\t2.按作者查找\t\t\t\t|\n");
		printf("|\t\t\t3.显示所有信息\t\t\t\t|\n");
		printf("|\t\t\t0.返回上级菜单\t\t\t\t|\n");
		printf("----------------------------------------------------------------\n");
		printf("输入数字选择功能(0~3)\n");
		
			scanf("%d",&x);
			getchar();
			if(x==0)flag=0;
			else if(x==1)lm->part1(1);
			else if(x==2)lm->part1(2);
			else if(x==3)lm->part1(3);
			else printf("输入错误，请重新输入\n");
		}
	}
	else if(a==2)
	{
		while(flag==1)
		{
		system("CLS");
		printf("----------------------------------------------------------------\n");
		printf("|\t\t\t1.添加图书信息\t\t\t\t|\n");
		printf("|\t\t\t2.删除图书信息\t\t\t\t|\n");
		printf("|\t\t\t3.修改图书信息\t\t\t\t|\n");
		printf("|\t\t\t0.返回上级菜单\t\t\t\t|\n");
		printf("----------------------------------------------------------------\n");
		printf("输入数字选择功能(0~3)\n");
		
			scanf("%d",&x);
			getchar();
			if(x==0)flag=0;
			else if(x==1)lm->part2(1, lib_col);
			else if(x==2)lm->part2(2, lib_col);
			else if(x==3)lm->part2(3, lib_col);
			else printf("输入错误，请重新输入\n");
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
		printf("|\t\t\t1.按书名查找\t\t\t\t|\n");
		printf("|\t\t\t2.按作者查找\t\t\t\t|\n");
		printf("|\t\t\t3.显示所有信息\t\t\t\t|\n");
		printf("|\t\t\t0.返回上级菜单\t\t\t\t|\n");
		printf("----------------------------------------------------------------\n");
		printf("输入数字选择功能(0~3)\n");
		
			scanf("%d", &x);
			getchar();
			if (x == 0)flag = 0;
			else if (x == 1)lm->part1(1);
			else if (x == 2)lm->part1(2);
			else if (x == 3)lm->part1(3);
		
			else printf("输入错误，请重新输入\n");
		}
	}
	else if (a == 2)
	{
		system("CLS");
		printf("----------------------------------------------------------------\n");
		printf("|\t\t\t1.选择要借取的图书\t\t\t\t|\n");
		printf("----------------------------------------------------------------\n");
		int i;
		for (i = 0; i < lm->m_booknum; i++)
		{
			printf("%-d %-25s %-12s %.2f元\n", i+1, lm->bookarray[i]->name, lm->bookarray[i]->writer, lm->bookarray[i]->price);
		}
		printf("输入数字选择功能(每次借一本，输入0取消)\n");
		while (flag == 1)
		{
			scanf("%d", &x);
			getchar();
			if (x == 0)flag = 0;
			else if (0<x&&x <= lm->m_booknum)
			{
				if (lm->bookarray[x-1]->user[0] != '0')
				{
					cout << "已被借走" << endl;
					system("pause");
					break;
				}
				strcpy(lm->bookarray[x-1]->user, User->account);
				lm->bookarray[x - 1]->flag = 1;
				flag = 0;
			}
			else printf("输入错误，请重新输入\n");
		}
	}
	else if (a == 3)
	{
		system("CLS");
		printf("--------------------------------------------------------------------\n");
		printf("|                 还书中。。。。。。                               |\n");
		printf("--------------------------------------------------------------------\n");
		int i = 0;
		//还书后将对应的书所属的名字置零
		for (i = 0; i < lm->m_booknum; i++)
		{
			if (strcmp(lm->bookarray[i]->user, User->account) == 0)
			{
				strcpy(lm->bookarray[i]->user, "0");
				lm->bookarray[i]->flag = 0;
			}
		}
		cout << "已还书"<<endl;
		system("pause");
	}
	else if (a == 4)
	{
		system("CLS");
		lm->part3(lib_col);
	}
}
