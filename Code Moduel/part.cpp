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
		printf("������ؼ���\n");
		scanf("%s",x);
		getchar();
		searchname(x); 
	}
	else if(a==2)
	{
		char x[20];
		printf("������������\n");
		scanf("%s",x);
		getchar();
		searchauthor(x);
	}
	else if(a==3)
	{
		int i;
		for(i=0;(book[i].name[0])!='#';i++)
		{
			printf("%s %s %.2fԪ\n",book[i].name,book[i].writer,book[i].price);
		}
	}
	printf("�����ѡ��\n");
}
void searchname(char *x)
{
	printf("����������\n");
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
	if(s[0]==0)printf("δ�ҵ�������\n");
	else
	{
		printf("���йؼ��ֵ�����:\n");
		for(i=0;s[i]!=0;i++)
		{
			int t=s[i]-1;
			printf("%s %s %.2fԪ\n",book[t].name,book[t].writer,book[t].price);
		}
	}
}
void searchauthor(char *x)
{
	printf("����������\n");
	int s[25]={0},i,n=0;
	for(i=0;(book[i].name[0])!='#';i++)
	{
		if(strcmp(book[i].writer,x)==0)
		{
			s[n]=i+1;
			n++;
		}
	}
	if(s[0]==0)printf("δ�ҵ�������\n");
	else
	{
		printf("�����ߵ�����:\n");
		for(i=0;s[i]!=0;i++)
		{
			int t=s[i]-1;
			printf("%s %.2fԪ\n",book[t].name,book[t].price);
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
			printf("%s %s %.2fԪ\n",book[i].name,book[i].writer,book[i].price);
		}
	printf("�����ѡ��\n");
}
void add(int a)
{
	int i;
	Book t;
	printf("�밴�ա����� �۸� ���ߡ��ĸ�ʽ����\n");
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
	printf("������\n");
}
void del(int a)
{
	int i,flag=-1,n=0;
	char x[20];
	printf("����������������\n");
	scanf("%s",x);
	getchar();
	for(i=0;(book[i].name[0])!='#';i++)
	{
		n++;
		if(strcmp(x,book[i].name)==0)flag=i;
	}
	if(flag==-1)printf("δ�ҵ����飬�ѷ�����һ��\n");
	else if(flag!=-1)
	{
		for(i=flag;i<n;i++)
		{
			book[i]=book[i+1];
		}
		printf("ɾ�����\n");
	}
}
void mod(int a)
{
	int i,flag=-1,n=0;
	char x[20];
	printf("����������������\n");
	scanf("%s",x);
	getchar();
	for(i=0;(book[i].name[0])!='#';i++)
	{
		n++;
		if(strcmp(x,book[i].name)==0)flag=i;
	}
	if(flag==-1)printf("δ�ҵ����飬�ѷ�����һ��\n");
	else if(flag!=-1)
	{
		Book t;
		printf("�밴�ա����� �۸� ���ߡ��ĸ�ʽ�����޸ĺ����Ϣ\n");
		scanf("%s %lf %s",t.name,&t.price,t.writer);
		getchar();
		book[flag]=t;
		printf("�޸����\n");
	}
}

void part3(int a)
{
	sort(a);
	int i;
	printf("�����뵼���ļ����ļ���\n��������豣���������У�������books.txt��\n");
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
	printf("�����ѡ��\n");
}
void sort(int a)
{
	printf("����������\n");
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
		printf("����ɹ�\n");
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
		printf("����ɹ�\n");
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
		printf("����ɹ�\n");
	}
}
