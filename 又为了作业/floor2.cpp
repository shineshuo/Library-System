#include"floor2.h"

floor2::floor2(int initx, int inity, int flagf)
{
	this->init_x = initx;
	this->init_y = inity;
	this->flag_f = flagf;
	

}

//这里是这一层介绍
void  floor2::showinfo()
{

	cout << "这是历史层" << endl;
	cout << "你可以在这里找到历史性质的书" << endl;
}
void  floor2::init()
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
			else if (j > 0 && j < 9&&i==3)
			{
				this->map[i][j] = 1;
			}
			else if (i < 10 && i>6&&j==3)
			{
				this->map[i][j] = 1;
			}
			else if (i < 10 && i>6 && j == 8)
			{
				this->map[i][j] = 1;
			}
			else
			{
				map[i][j] = 0;
			}
		}


	}

}