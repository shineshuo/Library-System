#include"serchroad.h"



bool findend = false;


void show_map(int map[rows][cols])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{

			if (map[i][j] == 1)//�ϰ���
			{
				cout << "��";
			}
			else if (map[i][j] == 2)//�˳�ʼλ��
			{
				cout << "��";
			}
			else if (map[i][j] == 3)//����
			{
				cout << "��";
			}
			else if (map[i][j] == 4)
			{
				cout << "��";
			}
			else if (map[i][j] == 5)
			{
				cout << "��";
			}
			else
			{
				cout << "  ";
			}

		}
		cout << endl;
		
	}
	cout << "��:ǽ ��:��ǰ����λ�� ��:·�� ��:��" << endl;
}


int geth(my_point endpos, my_point pos)//�յ�  ��ǰ��
{
	int x = (endpos.m_col > pos.m_col) ? (endpos.m_col - pos.m_col) : (pos.m_col - endpos.m_col);
	int y = (endpos.m_row > pos.m_row) ? (endpos.m_row - pos.m_row) : (pos.m_row - endpos.m_row);

	return  sqrt(x * x + y * y) * 10;

}


bool needadd(int map[rows][cols], my_point pos, bool map1[rows][cols])// �߽� ǽ �߹�
{
	if (pos.m_row >= rows || pos.m_row < 0 || pos.m_col >= cols || pos.m_col < 0)
	{
		return false;
	}
	if (map[pos.m_row][pos.m_col] == 1)
	{
		return false;
	}
	if (map1[pos.m_row][pos.m_col] == true)//�Ƿ��߹�
	{
		return false;
	}

	return true;
}


//��¼�Ƿ��߹�



void serch_act(int map[11][13],int x,int y,floor_*p)
{
	
	bool map1[rows][cols] = { 0 };

	my_point begpos = { p->init_y,p->init_x };
	my_point endpos = {  y,x };
	map[begpos.m_row][begpos.m_col] = 2;
	map[endpos.m_row][endpos.m_col] = 2;
	map1[begpos.m_row][begpos.m_col] = true;


	tree_Node* pnew = new tree_Node;

	//�����֪����ɶ �����ǳ�ʼ����


	//���Ǹ��ڵ� ָ��ʼ�ĵ�
	tree_Node* proot = pnew;
	proot->pos = begpos;
	//��¼��ͬ�����f 
	vector<tree_Node*> buff;

	tree_Node* pchild = NULL;
	tree_Node* pcurrent = proot;
	//������
	vector <tree_Node*>::iterator it;
	vector <tree_Node*>::iterator itmin;

	while (1)
	{

		//1 �ҵ���ǰ����Χ���ߵĵ�
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

			//2 ��ֵ
			pchild->pos.h = geth(endpos, pchild->pos);
			pchild->pos.setf();
			//3 ���� ��buff ����߹�
			if (needadd(map, pchild->pos, map1))
			{
				pcurrent->childs.push_back(pchild);
				pchild->parent = pcurrent;
				//buff
				buff.push_back(pchild);//
				//�߹�
				map1[pchild->pos.m_row][pchild->pos.m_col] = true;
			}
			else
			{
				delete pchild;
			}

		}
		itmin = buff.begin();//itmin���ڵ�һ��
		for (it = buff.begin(); it != buff.end(); it++)
		{
			if ((*itmin)->pos.f > (*it)->pos.f)
			{
				itmin = it;
			}
		}
		//�仯��ǰ��
		pcurrent = *itmin;
		buff.erase(itmin);/////////////����
		/*
		���buff�������Ĳ��ǰ˸������f ����ÿ���ڵ���ӽڵ�f ֵ ����һ�γ�����·���ϰ�
		����ڵ�ֻ����������λ�õ���f���� ��ͨ��buff����ÿ������С��f
		 �ͻ�ȥ����ͷ�����ӽڵ�ڶ�С��f��Ӧ�Ľڵ�  ��Ϊ��һ���ӽڵ��f��ɾ��ֻʣ���һ��f
		���f��Ӧ��buffָ��ָ��ͷ�����ӽڵ�ڶ�С��f��Ӧ�Ľڵ� �Ӷ���·
		*/
		
		if (pcurrent->pos.m_col == endpos.m_col && pcurrent->pos.m_row == endpos.m_row)
		{
			
			cout << "�ҵ���";
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