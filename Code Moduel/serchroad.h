#pragma once
#include<iostream>
#include<vector>
#include<math.h>
#include"secretary.h"

using namespace std;
#define rows 11
#define cols 13


void show_map(int map[rows][cols]);

// 代价 = 起点到当前点代价+当前点到终点代价

struct my_point
{
	int m_row;//y
	int m_col;//x
	int f;
	int g;
	int h;
	void setf()
	{
		this->f = g + h;
	}

};
int geth(my_point endpos, my_point pos);
void serch_act(int map[11][13], int x, int y, floor_* p);
//节点类型 
struct tree_Node
{
	my_point pos;//当前坐标
	vector<tree_Node*> childs; //存储 当前点的子节点
	tree_Node* parent;

};
enum direct { p_up, p_down, p_left, p_right, p_lup, p_ldown, p_rup, p_rdown };

