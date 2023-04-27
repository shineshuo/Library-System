#include"serchroad.h"



bool findend = false;


void show_map(int map[rows][cols])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{

			if (map[i][j] == 1)//障碍物
			{
				cout << "■";
			}
			else if (map[i][j] == 2)//人初始位置
			{
				cout << "▲";
			}
			else if (map[i][j] == 3)//有书
			{
				cout << "●";
			}
			else if (map[i][j] == 4)
			{
				cout << "□";
			}
			else if (map[i][j] == 5)
			{
				cout << "★";
			}
			else
			{
				cout << "  ";
			}

		}
		cout << endl;
		
	}
	cout << "■:墙 ▲:当前所在位置 ●:路径 □:书" << endl;
}


int geth(my_point endpos, my_point pos)//终点  当前点
{
	int x = (endpos.m_col > pos.m_col) ? (endpos.m_col - pos.m_col) : (pos.m_col - endpos.m_col);
	int y = (endpos.m_row > pos.m_row) ? (endpos.m_row - pos.m_row) : (pos.m_row - endpos.m_row);

	return  sqrt(x * x + y * y) * 10;

}


bool needadd(int map[rows][cols], my_point pos, bool map1[rows][cols])// 边界 墙 走过
{
	if (pos.m_row >= rows || pos.m_row < 0 || pos.m_col >= cols || pos.m_col < 0)
	{
		return false;
	}
	if (map[pos.m_row][pos.m_col] == 1)
	{
		return false;
	}
	if (map1[pos.m_row][pos.m_col] == true)//是否走过
	{
		return false;
	}

	return true;
}


//记录是否走过



void serch_act(int map[11][13],int x,int y,floor_*p)
{
	
	bool map1[rows][cols] = { 0 };

	my_point begpos = { p->init_y,p->init_x };
	my_point endpos = {  y,x };
	map[begpos.m_row][begpos.m_col] = 2;
	map[endpos.m_row][endpos.m_col] = 2;
	map1[begpos.m_row][begpos.m_col] = true;


	tree_Node* pnew = new tree_Node;

	//这个不知道是啥 可能是初始化的


	//这是根节点 指向开始的点
	tree_Node* proot = pnew;
	proot->pos = begpos;
	//记录不同方向的f 
	vector<tree_Node*> buff;

	tree_Node* pchild = NULL;
	tree_Node* pcurrent = proot;
	//迭代器
	vector <tree_Node*>::iterator it;
	vector <tree_Node*>::iterator itmin;

	while (1)
	{

		//1 找到当前点周围能走的点
		for (int i = 0; i < 8; i++)
		{
			pchild = new tree_Node;

			pchild->pos = pcurrent->pos;
			switch (i)
			{
			case p_up:
				pchild->pos.m_row--;
				pchild->pos.g += 10;
				break;
			case p_down:
				pchild->pos.m_row++;
				pchild->pos.g += 10;
				break;
			case p_left:
				pchild->pos.m_col--;
				pchild->pos.g += 10;
				break;
			case p_right:
				pchild->pos.m_col++;
				pchild->pos.g += 10;
				break;
			case p_lup:
				pchild->pos.m_row--;
				pchild->pos.m_col--;
				pchild->pos.g += 14;
				break;
			case p_ldown:
				pchild->pos.m_row--;
				pchild->pos.m_col++;
				pchild->pos.g += 14;
				break;
			case p_rup:
				pchild->pos.m_row++;
				pchild->pos.m_col--;
				pchild->pos.g += 14;
				break;
			case p_rdown:
				pchild->pos.m_row++;
				pchild->pos.m_col++;
				pchild->pos.g += 14;
				break;
			default:
				break;
			}

			//2 算值
			pchild->pos.h = geth(endpos, pchild->pos);
			pchild->pos.setf();
			//3 入树 入buff 标记走过
			if (needadd(map, pchild->pos, map1))
			{
				pcurrent->childs.push_back(pchild);
				pchild->parent = pcurrent;
				//buff
				buff.push_back(pchild);//
				//走过
				map1[pchild->pos.m_row][pchild->pos.m_col] = true;
			}
			else
			{
				delete pchild;
			}

		}
		itmin = buff.begin();//itmin等于第一个
		for (it = buff.begin(); it != buff.end(); it++)
		{
			if ((*itmin)->pos.f > (*it)->pos.f)
			{
				itmin = it;
			}
		}
		//变化当前点
		pcurrent = *itmin;
		buff.erase(itmin);/////////////看这
		/*
		这个buff数组计入的不是八个方向的f 而是每个节点的子节点f 值 当第一次出现死路或障碍
		这个节点只能走向其他位置导致f增大 而通过buff数组每次找最小的f
		 就会去锁定头结点的子节点第二小的f对应的节点  因为第一条子节点的f都删了只剩最后一个f
		这个f对应的buff指针指向头结点的子节点第二小的f对应的节点 从而换路
		*/
		
		if (pcurrent->pos.m_col == endpos.m_col && pcurrent->pos.m_row == endpos.m_row)
		{
			
			cout << "找到了";
			findend = true;
			break;
		}
		if (buff.empty())
		{
			break;
		}
	}
	if (findend)
	{

		while (pcurrent->pos.m_col != begpos.m_col || pcurrent->pos.m_row != begpos.m_row)
		{
		
			map[pcurrent->pos.m_row][pcurrent->pos.m_col] = 3;
			pcurrent = pcurrent->parent;
		}
		map[endpos.m_row][endpos.m_col]= 5;
		cout << endl;
	}
	show_map(map);


}