#pragma once
#include<iostream>
#include"Book.h"

using namespace std;
#define rows 11
#define cols 13





class floor_
{
public:
	string name;
	string name_;
	int init_x;
	int init_y;
	int flag_f;
	int map[11][13];
	virtual void showinfo() = 0;
	virtual void init() = 0;

};





