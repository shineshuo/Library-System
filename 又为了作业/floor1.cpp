#include"floor1.h"

floor1::floor1(int initx, int inity,int flagf)
{
	this->init_x = initx;
	this->init_y = inity;
	this->flag_f = flagf;
	
	

	name_="asd";
	name = "dsa";
}

 //这里是这一层介绍
 void  floor1::showinfo()
 {

	 cout << "这是文学层" << endl;
	 cout << "你可以在这里找到文学性质的书" << endl;

}
 void  floor1::init()
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
			 else if (j > 0 && j < 8&&i==4)
			 {
				 map[i][j] = 1;
			 }
			 else if (i < 10 && i>6&&j==9)
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
