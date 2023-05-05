#pragma once
#include<iostream>
#include"Book.h"

using namespace std;
#define rows 11
#define cols 13





class floor_//抽象类 链接三层楼 
{
public:
	string name;
	string name_;
	int init_x;//人初始位置
	int init_y;
	int flag_f;
	int map[11][13];
	virtual void showinfo() = 0;//介绍
	virtual void init() = 0;//位置初始化

};





