
#include"library_mag.h"
#include<fstream>
#include"serchroad.h"
using namespace std;

	int library_mag::get_booknum()
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
void library_mag::part1(int a)
{
	if (a == 1)
	{
		char x[20];
		printf("请输入关键字\n");
		scanf("%s", x);
		getchar();
		searchname(x);
	}
	else if (a == 2)
	{
		char x[20];
		printf("请输入作者名\n");
		scanf("%s", x);
		getchar();
		searchauthor(x);
	}
	else if (a == 3)
	{
		int i;
		for (i = 0;i< this->m_booknum; i++)
		{
			
			printf("%-20s %-12s %.2f元\n", bookarray[i]->name, bookarray[i]->writer, bookarray[i]->price);
		}
	}
	printf("请继续选择\n");
}
void library_mag::searchname(char* x)
{
	printf("正在搜索中\n");
	int s[25] = { 0 }, i, j, k, n = 0;
	int l1 = strlen(x);
	for (i = 0; i<this->m_booknum; i++)
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
	if (s[0] == 0)printf("未找到此书名\n");
	else
	{
		printf("含有关键字的书有:\n");
		for (i = 0; s[i] != 0; i++)
		{
			int t = s[i] - 1;
			printf("%-20s %-12s %.2f元\n", bookarray[t]->name, bookarray[t]->writer, bookarray[t]->price);
		}
	}
}
void library_mag::searchauthor(char* x)
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
	if (s[0] == 0)printf("未找到此作者\n");
	else
	{
		printf("此作者的书有:\n");
		for (i = 0; s[i] != 0; i++)
		{
			int t = s[i] - 1;
			printf("% -20s % .2f元\n", bookarray[t]->name, bookarray[t]->price);
		}
	}
}

void library_mag::part2(int a, floor_* p)
{
	if (a == 1)add(1,p);
	else if (a == 2)del(2);
	else if (a == 3)mod(3,p);
	int i;
	for (i = 0; i < this->m_booknum ; i++)
	{
		printf("%-20s %-12s %.2f元\n", bookarray[i]->name, bookarray[i]->writer, bookarray[i]->price);
	}
	printf("请继续选择\n");
}

int library_mag::searchname_(char* x)
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
			printf("%d  %-20s %-12s %.2f元\n",i+1,bookarray[t]->name, bookarray[t]->writer, bookarray[t]->price);
		}
		printf("选择想查找的书籍编号");
		cin >> select;
		return s[select-1] - 1;
	}
	
}


void library_mag::part3(int a, floor_* p)
{
	if (a == 1)
	{
		p->showinfo();
	}
	else if (a==2)
	{
		cout << "输入想查找的书籍(允许部分)"<<endl;
		char book_name[40];
		scanf("%s", book_name);
		int t=searchname_(book_name);
		 if (t != -1)
		{
	serch_act(p->map,this->bookarray[t]->x, this->bookarray[t]->y,p);
	
		}
		 else {
			 printf("请继续选择\n");
		 }
	}

}

void library_mag::add(int a,floor_* p)
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
	scanf("%s %lf %s", book->name, &book->price, book->writer);	
	getchar();
	int x_;
	int y_;
	int flag_ = 1;
	do
	{
		cout << "请输入书的坐标位置 输入0可退出" << endl;
		cin >> x_;
		if (x_ == 0)
		{
			flag == 0;
		}
		cin >> y_;
		if (p->map[y_][x_] != 0)
		{

			cout << "该位置上存在障碍 输入0可退出" << endl;
		}
	} while (p->map[y_][x_] == 0 && flag == 1);
	if (flag == 1)
	{
		book->x = x_;
		book->y = y_;
	}
	newspace[this->m_booknum ] = book;
	
	delete[]this->bookarray;
	this->m_booknum = newsize;
	this->bookarray = newspace;
	////////////////////////////////////////
	printf("添加完成\n");
}
void library_mag::del(int a)
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
}
void library_mag::mod(int a,floor_* p)
{
	int i, flag = -1, n = 0;
	char x[20];
	printf("请输入完整的书名\n");
	scanf("%s", x);
	getchar();
	for (i = 0; (bookarray[i]->name[0]) != '#'; i++)
	{
		n++;
		if (strcmp(x, bookarray[i]->name) == 0)flag = i;
	}
	if (flag == -1)printf("未找到此书，已返回上一步\n");
	else if (flag != -1)
	{
		Book *t;
		printf("请按照“书名 价格 作者”的格式输入修改后的信息\n");
		scanf("%s %lf %s", t->name, &t->price, t->writer);
		getchar();
		int x_;
		int y_;
		int flag_ = 1;
		do
		{
			cout << "请输入书的坐标位置 输入0可退出" << endl;
			cin >> x_;
			if (x_==0)
				{
				flag == 0;
			}
			cin >> y_;
			if (p->map[y_][x_] != 0)
			{
				
				cout << "该位置上存在障碍 输入0可退出"<<endl;
			}
		} while (p->map[y_][x_]==0&&flag==1);
		if (flag == 1)
		{
			t->x = x_;
			t->y = y_;
		bookarray[flag] = t;
		printf("修改完成\n");
		}
	
	}
}

void library_mag::save()
{
	
	int i;
	FILE* outs;
	outs = fopen(this->floor, "w");
	for (i = 0; i < this->m_booknum; i++)
	{
		fprintf(outs, "%s %.2f %s %d %d\n", bookarray[i]->name, bookarray[i]->price, bookarray[i]->writer, bookarray[i]->x, bookarray[i]->y);
	}
	fclose(outs);
}

void library_mag::bookread()
{
	int i;
	
	
	FILE* books;
	if ((books = fopen(floor, "r")) == NULL)printf("文件打开失败\n");

	for (i = 0; i < this->m_booknum; i++)
	{	Book* book = new Book;
		
		fscanf(books, "%s %lf %s %d %d", book->name, &book->price, book->writer,&book->x,&book->y);
		bookarray[i] = book;
	}
	fclose(books);
}

