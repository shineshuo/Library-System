#include<stdio.h>
#include<string.h>
#include"read.h"
#include"part.h"
#include"Book.h"
void part1(int a)
{
	if(a==1)
	{
		char x[20];
		printf("请输入关键字\n");
		scanf("%s",x);
		getchar();
		searchname(x); 
	}
	else if(a==2)
	{
		char x[20];
		printf("请输入作者名\n");
		scanf("%s",x);
		getchar();
		searchauthor(x);
	}
	else if(a==3)
	{
		int i;
		for(i=0;(book[i].name[0])!='#';i++)
		{
			printf("%s %s %.2f元\n",book[i].name,book[i].writer,book[i].price);
		}
	}
	printf("请继续选择\n");
}
void searchname(char *x)
{
	printf("正在搜索中\n");
	int s[25]={0},i,j,k,n=0;
	int l1=strlen(x);
	for(i=0;(book[i].name[0])!='#';i++)
	{
		int flag=1;
		int l2=strlen(book[i].name);
		for(j=0;j<=l2-l1;j++)
		{
			if(book[i].name[j]==x[0])
			{
				flag=0;
				for(k=1;k<l1;k++)
				{
					if(book[i].name[j+k]!=x[k])
					{
						flag=1;
						break;
					}
				}
			}
			if(flag==0)break;
		}
		if(flag==0)
		{
			s[n]=i+1;
			n++;
		}
	}
	if(s[0]==0)printf("未找到此书名\n");
	else
	{
		printf("含有关键字的书有:\n");
		for(i=0;s[i]!=0;i++)
		{
			int t=s[i]-1;
			printf("%s %s %.2f元\n",book[t].name,book[t].writer,book[t].price);
		}
	}
}
void searchauthor(char *x)
{
	printf("正在搜索中\n");
	int s[25]={0},i,n=0;
	for(i=0;(book[i].name[0])!='#';i++)
	{
		if(strcmp(book[i].writer,x)==0)
		{
			s[n]=i+1;
			n++;
		}
	}
	if(s[0]==0)printf("未找到此作者\n");
	else
	{
		printf("此作者的书有:\n");
		for(i=0;s[i]!=0;i++)
		{
			int t=s[i]-1;
			printf("%s %.2f元\n",book[t].name,book[t].price);
		}
	}
}

void part2(int a)
{
	if(a==1)add(1);
	else if(a==2)del(2);
	else if(a==3)mod(3);
	int i;
	for(i=0;(book[i].name[0])!='#';i++)
		{
			printf("%s %s %.2f元\n",book[i].name,book[i].writer,book[i].price);
		}
	printf("请继续选择\n");
}
void add(int a)
{
	int i;
	Book t;
	printf("请按照“书名 价格 作者”的格式输入\n");
	scanf("%s %lf %s",t.name,&t.price,t.writer);
	getchar();
	for(i=0;;i++)
	{
		if(book[i].name[0]=='#')
		{
			book[i]=t;
			book[i+1].name[0]='#';
			break;
		}
	}
	printf("添加完成\n");
}
void del(int a)
{
	int i,flag=-1,n=0;
	char x[20];
	printf("请输入完整的书名\n");
	scanf("%s",x);
	getchar();
	for(i=0;(book[i].name[0])!='#';i++)
	{
		n++;
		if(strcmp(x,book[i].name)==0)flag=i;
	}
	if(flag==-1)printf("未找到此书，已返回上一步\n");
	else if(flag!=-1)
	{
		for(i=flag;i<n;i++)
		{
			book[i]=book[i+1];
		}
		printf("删除完成\n");
	}
}
void mod(int a)
{
	int i,flag=-1,n=0;
	char x[20];
	printf("请输入完整的书名\n");
	scanf("%s",x);
	getchar();
	for(i=0;(book[i].name[0])!='#';i++)
	{
		n++;
		if(strcmp(x,book[i].name)==0)flag=i;
	}
	if(flag==-1)printf("未找到此书，已返回上一步\n");
	else if(flag!=-1)
	{
		Book t;
		printf("请按照“书名 价格 作者”的格式输入修改后的信息\n");
		scanf("%s %lf %s",t.name,&t.price,t.writer);
		getchar();
		book[flag]=t;
		printf("修改完成\n");
	}
}

void part3(int a)
{
	sort(a);
	int i;
	printf("请输入导出文件的文件名\n（如果仅需保存在数据中，请输入books.txt）\n");
	char x[30];
	gets_s(x);
	FILE *outs;
	outs=fopen(x,"w");
	for(i=0;(book[i].name[0])!='#';i++)
	{
		fprintf(outs,"%s %.2f %s\n",book[i].name,book[i].price,book[i].writer);
	}
	fprintf(outs,"#");
	fclose(outs);
	printf("请继续选择\n");
}
void sort(int a)
{
	printf("正在排序中\n");
	Book t;
	int i,j,min;
	if(a==1)
	{
		for(i=0;(book[i].name[0])!='#';i++)
		{
			min=i;
			for(j=i;(book[j].name[0])!='#';j++)
			{
				if(strcmp(book[j].name,book[min].name)<0)min=j;
			}
			t=book[i];
			book[i]=book[min];
			book[min]=t;
		}
		printf("排序成功\n");
	}
	else if(a==2)
	{
		for(i=0;(book[i].name[0])!='#';i++)
		{
			min=i;
			for(j=i;(book[j].name[0])!='#';j++)
			{
				if(strcmp(book[j].writer,book[min].writer)<0)min=j;
			}
			t=book[i];
			book[i]=book[min];
			book[min]=t;
		}
		printf("排序成功\n");
	}
	else if(a==3)
	{
		for(i=0;(book[i].name[0])!='#';i++)
		{
			min=i;
			for(j=i;(book[j].name[0])!='#';j++)
			{
				if(book[j].price<book[min].price)min=j;
			}
			t=book[i];
			book[i]=book[min];
			book[min]=t;
		}
		printf("排序成功\n");
	}
}
