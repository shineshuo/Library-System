#pragma once
#include<iostream>
#include<vector>
#include<math.h>
#include"secretary.h"

using namespace std;
#define rows 11
#define cols 13


void show_map(int map[rows][cols]);

// ���� = ��㵽��ǰ�����+��ǰ�㵽�յ����

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
//�ڵ����� 
struct tree_Node
{
	my_point pos;//��ǰ����
	vector<tree_Node*> childs; //�洢 ��ǰ����ӽڵ�
	tree_Node* parent;

};
enum direct { p_up, p_down, p_left, p_right, p_lup, p_ldown, p_rup, p_rdown };

