#include"floor1.h"

floor1::floor1(int initx, int inity,int flagf)
{
	this->init_x = initx;
	this->init_y = inity;
	this->flag_f = flagf;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == 0||i==10)
			{
				map[i][j] = 1;
			}
			else if(j == 0 || j == 12)
			{
				map[i][j] = 1;
			}
			else if (j > 0 && j < 8)
			{
				map[4][j] = 1;
			}
			else if (i < 10 && i>6)
			{
				map[i][9] = 1;
			}
			else
			{
				map[i][j] = 0;
			}
	}
		

	}

	name_="asd";
	name = "dsa";
}

 //��������һ�����
 void  floor1::showinfo()
 {

	 cout << "" << endl;

}
 void  floor1::init()
 {
	 cout << 1;
	 for (int i = 0; i < rows; i++)
	 {
		 for (int j = 0; j < cols; j++)
		 {
			 if (i == 0 || i == 10)
			 {
				 map[i][j] = 1;
			 }
			 else if (j == 0 || j == 12)
			 {
				 map[i][j] = 1;
			 }
			 else if (j > 0 && j < 8)
			 {
				 map[4][j] = 1;
			 }
			 else if (i < 10 && i>6)
			 {
				 map[i][9] = 1;
			 }
			 else
			 {
				 map[i][j] = 0;
			 }
		 }


	 }

 }
 /*	int map[rows][cols] ={
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,0,0,0,1,0,1,0,0,0,0,0,1},
	{ 1,0,0,0,1,0,1,0,0,0,0,0,1},
	{ 1,0,0,0,1,0,1,0,0,0,0,0,1},
	{ 1,0,0,0,1,0,1,1,1,1,0,0,1},
	{ 1,0,0,0,1,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,1,0,1,1,0,0,0,0,1},
	{ 1,0,0,0,1,0,1,0,0,0,0,0,1},
	{ 1,0,0,0,1,0,1,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,1,0,0,0,0,0,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1},
	};*/