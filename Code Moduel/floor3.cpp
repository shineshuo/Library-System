#include"floor3.h"

floor3::floor3(int initx, int inity, int flagf)
{
	this->init_x = initx;
	this->init_y = inity;
	this->flag_f = flagf;


}

//这里是这一层介绍
void  floor3::showinfo()
{
	cout << "这是哲学层" << endl;
	cout << "你可以在这里找到哲学性质的书" << endl;
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
			else if (j < 10 && j>0 && i == 4)
			{
				this->map[i][j] = 1;
			}
			else if (j < 10 && j>0 && i == 7)
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