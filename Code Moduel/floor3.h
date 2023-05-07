#pragma once
#pragma once
#include"floor.h"
#include"library_mag.h"
#include"secretary.h"

using namespace std;
class floor3 : public floor_
{
public:
	floor3(int init_x, int init_y, int flag_f);

	virtual void showinfo();
	
	virtual void init();
};
