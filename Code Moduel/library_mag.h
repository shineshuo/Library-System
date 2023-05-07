#pragma once
#include"Book.h"
#include<iostream>
#include"floor.h"
using namespace std;
class library_mag
{
public:
	char flag;
	char floor[20] = { "books0.txt" };
	int m_booknum;
	Book** bookarray;
	void part1(int a);
	int get_booknum();
	void searchname(char* x);
	void searchauthor(char* x);
	void part2(int a,floor_* p);
	void part3(floor_* p);
	void add(int a,floor_* p);
	void del(int a);
	void mod(int a,floor_* p);
	void save();
	void bookread();
	int searchname_(char* x);
		/////
	library_mag(int i);



};	

