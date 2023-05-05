
#include"library_mag.h"
#include<fstream>
#include"serchroad.h"
using namespace std;

	int library_mag::get_booknum()//获取书籍数量
	{
		ifstream ifs;
		ifs.open(floor, ios::in);
		string id;
		string name;
		int did;
		int num = 0;
		char buf[BUFSIZ];
		while (ifs.getline(buf, BUFSIZ))
		{
			num++;
		}
		ifs.close();
		return num;
	}
library_mag::library_mag(int i)
{
	//
	ifstream ifs;
	switch (i)
	{
	case 1:flag = '1'; break;
	case 2:flag = '2'; break;
	case 3:flag = '3'; break;
	}

	floor[5] = flag;
	ifs.open(floor, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->bookarray = NULL;
		this->m_booknum = 0;
	
		ifs.close();
		return;
	}

	//判断是否有数据
	char ch;
	ifs >> ch;
	//
	if (ifs.eof())//ifs.eof() 检查前面读了东西没
	{
		this->bookarray = NULL;
		this->m_booknum = 0;
		ifs.close();
		return;
	}
	this->m_booknum = get_booknum();
	this->bookarray = new Book * [this->m_booknum];
}
void library_mag::part1(int a)//查找
{
	if (a == 1)
	{
		char x[20];
		printf("请输入关键字,(支持部分搜索)\n");
		scanf("%s", x);
		getchar();
		if (x[0] == '0')
		{
			return;
		}
		searchname(x);
	}
	else if (a == 2)
	{
		char x[20];
		printf("请输入作者名\n");
		scanf("%s", x);
		getchar();
		if (x[0] == '0')
		{
			return;
		}
		searchauthor(x);
	}
	else if (a == 3)
	{
		int i;
		for (i = 0;i< this->m_booknum; i++)
		{
			
			printf("%d  %-25s %-12s %.2f元", i + 1, bookarray[i]->name, bookarray[i]->writer, bookarray[i]->price);
			if (bookarray[i]->user[0] != '0')
			{
				cout << "已被借走:" << bookarray[i]->user;
			}
			printf("\n");
		}
	}
	printf("请继续选择\n");
	system("pause");
}
void library_mag::searchname(char* x)//搜索书名
{
	printf("正在搜索中\n");
	int s[25] = { 0 }, i, j, k, n = 0;
	int l1 = strlen(x);
	for (i = 0; i<this->m_booknum; i++)//部分检索
	{
		int flag = 1;
		int l2 = strlen(bookarray[i]->name);
		for (j = 0; j <= l2 - l1; j++)
		{
			if (bookarray[i]->name[j] == x[0])
			{
				flag = 0;
				for (k = 1; k < l1; k++)
				{
					if (bookarray[i]->name[j + k] != x[k])
					{
						flag = 1;
						break;
					}
				}
			}
			if (flag == 0)break;
		}
		if (flag == 0)
		{
			s[n] = i + 1;
			n++;
		}
	}
	if (s[0] == 0)
	{
		printf("未找到此书名\n");
	
	}
	else
	{
		printf("含有关键字的书有:\n");
		for (i = 0; s[i] != 0; i++)
		{
			int t = s[i] - 1;
			printf("%d  %-25s %-12s %.2f元", i + 1, bookarray[t]->name, bookarray[t]->writer, bookarray[t]->price);
			if (bookarray[t]->user[0] != '0')
			{
				cout <<"已被借走:" << bookarray[t]->user;
			}
			printf("\n");
		}
		
	}
}
void library_mag::searchauthor(char* x)//搜索作者
{
	printf("正在搜索中\n");
	int s[25] = { 0 }, i, n = 0;
	for (i = 0; i < this->m_booknum ; i++)
	{
		if (strcmp(bookarray[i]->writer, x) == 0)
		{
			s[n] = i + 1;
			n++;
		}
	}
	if (s[0] == 0)
	{
		printf("未找到此作者\n");
	
	}
	else
	{
		printf("此作者的书有:\n");
		for (i = 0; s[i] != 0; i++)
		{
			int t = s[i] - 1;
			printf("% -25s % .2f元", bookarray[t]->name, bookarray[t]->price);
			if (bookarray[t]->user[0] != '0')
			{
				cout <<"已被借走:" << bookarray[t]->user;
			}
			printf("\n");
		}
	}
}

void library_mag::part2(int a, floor_* p)//修改信息
{
	cout << "按0退回" << endl;
	if (a == 1)add(1,p);
	else if (a == 2)del(2);
	else if (a == 3)mod(3,p);
	int i;
	for (i = 0; i < this->m_booknum ; i++)
	{
		printf("%-25s %-12s %.2f元\n", bookarray[i]->name, bookarray[i]->writer, bookarray[i]->price);
	}
	printf("请继续选择\n");
}

int library_mag::searchname_(char* x)//
{
	int select;
	printf("正在搜索中\n");
	int s[25] = { 0 }, i, j, k, n = 0;
	int l1 = strlen(x);
	for (i = 0; i < this->m_booknum; i++)
	{
		int flag = 1;
		int l2 = strlen(bookarray[i]->name);
		for (j = 0; j <= l2 - l1; j++)
		{
			if (bookarray[i]->name[j] == x[0])
			{
				flag = 0;
				for (k = 1; k < l1; k++)
				{
					if (bookarray[i]->name[j + k] != x[k])
					{
						flag = 1;
						break;
					}
				}
			}
			if (flag == 0)break;
		}
		if (flag == 0)
		{
			s[n] = i + 1;
			n++;
		}
	}
	if (s[0] == 0)
	{
		printf("未找到此书名\n");
		return -1;
	}
	else
	{
		printf("含有关键字的书有:\n");
		for (i = 0; s[i] != 0; i++)
		{
			int t = s[i] - 1;
			printf("%d  %-25s %-12s %.2f元",i+1,bookarray[t]->name, bookarray[t]->writer, bookarray[t]->price);
			if (bookarray[t]->user[0] != '0')
			{
				cout << bookarray[t]->user;
			}
			printf("\n");
		}
		printf("选择想查找的书籍编号");
		cin >> select;
		return s[select-1] - 1;
	}
	
}


void library_mag::part3( floor_* p)//寻路指路
{

		p->showinfo();

		cout << "输入想查找的书籍(允许部分)"<<endl;
		char book_name[40];
		scanf("%s", book_name);
		int t=searchname_(book_name);
		
		 if (t != -1)
		 {
			 if (this->bookarray[t]->user[0] != '0')
			 {
				 cout << "已被借走" << endl;
			 }
			 else
			 {
			serch_act(p->map,this->bookarray[t]->x, this->bookarray[t]->y,p);
			 }

	
		}
		 else {
			 printf("请继续选择\n");
		 }
		 system("pause");

}

void library_mag::add(int a,floor_* p)//添加
{
	int newsize = this->m_booknum + 1;
	//开辟新空间
	///////////////////////////////////////////////////////////////
	//用一个二级指针指向结构体数组   这个二级指针是在workermanager结构体的 所以在类内可以用this->指代
	///////////////////////////////////////////////////////////////
	Book** newspace = new Book * [newsize];
	///////////////////////////////////////////////////////////////
	//原空间放到这来

	for (int i = 0; i < this->m_booknum; i++)
	{
		newspace[i] = this->bookarray[i];
	}


	int i;
	Book *book=new Book;

	printf("请按照“书名 价格 作者”的格式输入\n");
	scanf("%s", book->name);	
	if (book->name[0] == '0')
	{
		delete book;
		delete newspace;
		return;
	}
	getchar();
	scanf("%lf %s", &book->price, book->writer);
	getchar();
	int x_=-1;
	int y_;
	int flag_ = 1;
	if (0 > book->price || book->price < 100000)
	{
		cout << "价格输入不合理，退出" << endl;
		delete book;
		delete newspace;
		system("pause");
		return;
	}
	do
	{
		flag_ = 1;
		cout << "请输入书的坐标位置 输入0可退出" << endl;
		cin >> x_;
		if (x_ == 0)
		{
			flag_ = 0;
			break;
		}
		cin >> y_;
		y_ -= 1;
		x_ -= 1;
		if (p->map[y_][x_] != 0)
		{
		cout << "该位置上存在障碍" << endl;
		flag_= 0;
		}
		if (y_ > 10 || y_ < 1 || x_>12 || x_ < 1)
		{
			cout << "超出范围" << endl;
			flag_ = 0;
		}
	}while (p->map[y_][x_] != 0 && flag_ != 1);
	if (flag_ == 1)
	{
		
		book->x = x_;
		book->y = y_;
		newspace[this->m_booknum ] = book;
	
	delete[]this->bookarray;//删除原来的空间
	this->m_booknum = newsize;//指向新空间
	this->bookarray = newspace;
	////////////////////////////////////////
	printf("添加完成\n");
		system("pause");
	}
	else {
		delete book;
		delete newspace;
		system("pause");
	}
	
}

void library_mag::del(int a)//删除
{
	
	int i, flag = -1, n = 0;
	char x[20];
	printf("请输入完整的书名\n");
	scanf("%s", x);
	getchar();
	for (i = 0; i<this->m_booknum; i++)
	{
		n++;
		if (strcmp(x, bookarray[i]->name) == 0) {
			flag = i; 
			delete	this->bookarray[i];
			this->m_booknum--;
		}
	}
	if (flag == -1)printf("未找到此书，已返回上一步\n");
	else if (flag != -1)
	{
		for (i = flag; i < n; i++)
		{
			bookarray[i] = bookarray[i + 1];
		}
		printf("删除完成\n");
	}
	system("pause");
}


void library_mag::mod(int a,floor_* p)//修改
{
	int i, flag = -1, n = 0;
	char x[20];
	int x_;
		int y_;
	printf("请输入完整的书名\n");
	scanf("%s", x);
	getchar();
	for (i = 0; i < this->m_booknum; i++)
	{
	
		if (strcmp(x, bookarray[i]->name) == 0)flag = i;
	}
	if (flag == -1)printf("未找到此书，已返回上一步\n");
	else if (flag != -1)
	{
		Book *book=new Book;
		printf("请按照“书名 价格 作者”的格式输入修改后的信息\n");
		scanf("%s", book->name);
		if (book->name[0] == '0')
		{
			delete book;
			return;
		}
		getchar();
		scanf("%lf %s", &book->price, book->writer);
		getchar();
		if (0 > book->price || book->price < 100000)
		{
			cout << "价格输入不合理，退出" << endl;
			system("pause");
			return;
		}
		int flag_ = 1;
		do
		{
			flag_ = 1;
			cout << "请输入书的坐标位置 输入0可退出" << endl;
			cin >> x_;
			if (x_ == 0)
			{
				flag_ = 0;
				break;
			}
			cin >> y_;
			y_ -= 1;
			x_ -= 1;
			if (p->map[y_][x_] != 0)
			{
				cout << "该位置上存在障碍" << endl;
				flag_ = 0;
			}
			if (y_ > 10 || y_ < 1 || x_>12 || x_ < 1)
			{
				cout << "超出范围" << endl;
				flag_ = 0;
			}
		} while (p->map[y_][x_]!=0&&flag_!=1);
		if (flag_ == 1)
		{
			book->x = x_;
			book->y = y_;
		bookarray[flag] = book;
		printf("修改完成\n");
		}
	}
	system("pause");
}

void library_mag::save()//保存文件
{
	
	int i;
	FILE* outs;
	outs = fopen(this->floor, "w");
	for (i = 0; i < this->m_booknum; i++)
	{
		fprintf(outs, "%s %.2f %s %d %d %d %s\n", bookarray[i]->name, bookarray[i]->price, bookarray[i]->writer, bookarray[i]->x, bookarray[i]->y,bookarray[i]->flag,bookarray[i]->user);
	}
	fclose(outs);
}

void library_mag::bookread()//读取文件
{
	int i;
	FILE* books;
	if ((books = fopen(floor, "r")) == NULL)printf("文件打开失败\n");

	for (i = 0; i < this->m_booknum; i++)
	{	Book* book = new Book;
		
		fscanf(books, "%s %lf %s %d %d %d %s", book->name, &book->price, book->writer,&book->x,&book->y,&book->flag, book->user);
		bookarray[i] = book;
	}
	fclose(books);
}

