#pragma once
#define _HEAD_H_
class Book
{
public:
	char name[40];
	char num[20];
	double price;
	char writer[12];
	int flag=0;//是否被借
	char user[20] = {'0'};//借书人名
	//位置
	int x;
	int y;

};