#include "drawline.h"
#include <cstdio>


drawline::drawline()
{
	drawer_instance = drawer::get_instance();
	for(int i = 0; i < 5; i++)                          //归一化
		for (int j = 0; j < 5; j++)
		{
			distribute_matrix[i][j] /= sum;
		}
}


drawline::~drawline()
{
}

void drawline::anti_aliasing()              //todo: 有待实现
{

}

void drawline::line_drawer(int start_x, int start_y, int end_x, int end_y, Color color)
{
	if (start_x > end_x)               //保证起点在终点左侧
	{
		swap(start_x, end_x);
		swap(start_y, end_y);
	}
	if (start_y < end_y)              //起点在终点下方
	{
		if ((end_x - start_x) > (end_y - start_y))            //0<= k < 1
		{
			partline_drawer(start_x, start_y, end_x, end_y, color, false, false);
		}
		else                                                  //1 <= k < +infinite
		{
			partline_drawer(start_y, start_x, end_y, end_x, color, false, true);
		}
	}
	else                              //起点在终点上方
	{
		if ((end_x - start_x) > (start_y - end_y))                        //-1 < k <= 0
		{
			partline_drawer(start_x, start_y, end_x, end_y, color, true, false);
		}
		else
		{
			partline_drawer(end_y, end_x, start_y, start_x, color, true, true);
		}
	}
}

bool drawline::line_parameters_judge(int start_x, int start_y, int end_x, int end_y)
{
	if (start_x < end_x && start_y <= end_y && (end_x - start_x) >= (end_y - start_y))               //可以是水平的直线
	{
		return true;
	}
	else
	{
		return false;
	}
}
void drawline::draw_line_pixel(unsigned int x, unsigned int y, bool k_big_flag, Color color)                 //根据flag决定
{
	if(!k_big_flag)               //斜率绝对值小于1并且斜率为正
	{
		drawer_instance->set_pixel(x, y, color);
	}
	else
	{
		drawer_instance->set_pixel(y, x, color);
	}
}