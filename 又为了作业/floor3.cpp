#include"floor3.h"

floor3::floor3(int initx, int inity, int flagf)
{
	this->init_x = initx;
	this->init_y = inity;
	this->flag_f = flagf;
	name_ = "asd";
	name = "dsa";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == 0||i==10)
			{
				map[i][j] = 1;
			}
			else if (j == 0 || j == 12)
			{
				map[i][j] = 1;
			}
			else
			{
				map[i][j] = 0;
			}
		}


	}
}

//这里是这一层介绍
void  floor3::showinfo()
{

	cout << "" << endl;

}
void  floor3::init()
{
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
			else
			{
				map[i][j] = 0;
			}
		}


	}

}