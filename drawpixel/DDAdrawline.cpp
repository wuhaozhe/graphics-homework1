#include "DDAdrawline.h"



DDAdrawline::DDAdrawline()
{

}


DDAdrawline::~DDAdrawline()
{
}

bool DDAdrawline::partline_drawer(int start_x, int start_y, int end_x, int end_y, Color color, bool k_negative_flag, bool k_big_flag)
{
	int x_adder;                   //x方向上的累加器
	float dx, dy, y_adder, k;      //y方向上的累加器
	if (!line_parameters_judge(start_x, start_y, end_x, end_y))            //输入是否保证斜率为0 <= k < 1
	{
		return false;
	}
	else
	{
		dx = end_x - start_x;
		dy = end_y - start_y;
		k = dy / dx, y_adder = start_y;
		for (x_adder = start_x; x_adder <= end_x; x_adder++)
		{
			drawer_instance->set_pixel(x_adder, (int)(y_adder + 0.5), color);
			y_adder += k;
		}
	}
	return true;
}