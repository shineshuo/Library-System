#include"serchroad.h"
#include<graphics.h>
//这是寻路的算f法
IMAGE book_image;
bool findend = false;
int count_ = 0;
void map_init()
{
	initgraph(700, 600, EX_SHOWCONSOLE);
	loadimage(&book_image, "./book.jpg");
	setbkcolor(RGB(198, 255, 200));
	cleardevice();

}

void show_map(int map[rows][cols])
{
	if (count_ == 0)
	{
		map_init();
		count_++;
	}
	cleardevice();
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{

			if (map[i][j] == 1)//障碍物
			{
				setfillcolor(RED);
				fillrectangle(50*j, 50*i,50 * j+50, 50 * i+50);
			}
			else if (map[i][j] == 2)//人初始位置
			{
				setfillcolor(WHITE);
				fillrectangle(50 * j, 50 * i, 50 * j + 50, 50 * i + 50);
			}
			
			else if (map[i][j] == 4)//有书
			{
				putimage(50 * j, 50 * i, &book_image);
			}
			
		

		}
		
	}
	char ch = '0';
	int flag = 0;
	for(int i=0;i<11;i++)
	{
		ch += 1;
		settextcolor(BLACK);
		outtextxy(25 + 13 * 50, i * 50 + 25  , ch);
		if (flag == 1)
		{
			outtextxy(25 + 13 * 50-8, i * 50 + 25, '1');
		}
		if (ch == '9')
		{
			ch = '0';
			ch -= 1;
			flag = 1;
		}
	}
	ch = '0';
	flag = 0;
	for (int j = 0; j < 13; j++)
	{
		ch += 1;
		settextcolor(BLACK);
		outtextxy(25 + j * 50, 11 * 50 + 25, ch);
		if (flag == 1)
		{
			outtextxy(j * 50 + 25-8,25 + 11 * 50, '1');
		}
		if (ch == '9')
		{
			ch = '0';
			ch -= 1;
			flag = 1;
		}

	}

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
			setlinecolor(BLACK);
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
		int _x = 0, _y = 0;
		while (pcurrent->pos.m_col != begpos.m_col || pcurrent->pos.m_row != begpos.m_row)
		{
		
			_y = pcurrent->pos.m_row;
			_x = pcurrent->pos.m_col;
			pcurrent = pcurrent->parent;
			
			line(_x * 50 + 25, _y * 50 + 25, pcurrent->pos.m_col*50+25, pcurrent->pos.m_row*50+25);
		}
		map[endpos.m_row][endpos.m_col]= 5;
		cout << endl;
	}
	


}