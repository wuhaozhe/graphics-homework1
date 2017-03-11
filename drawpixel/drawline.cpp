#include "drawline.h"
#include <cstdio>


drawline::drawline()
{
	drawer_instance = drawer::get_instance();
	for(int i = 0; i < 5; i++)                          //归一化
		for (int j = 0; j < 5; j++)
		{
			distribute_matrix[i][j] /= sum;
			distribute_matrix[i][j] *= 255;
		}
}


drawline::~drawline()
{
}

void drawline::anti_aliasing(int x, int y, Color color)              
{
	if (drawer_instance->point_illegal(x, y))
		return;
	else
	{
		Color _color;                      //反走样时当前格点的颜色
		_color.r = color.r, _color.g = color.g, _color.b = color.b, _color.a = 0;
		//cout << x << " " << y << endl;
		for(int i = -2; i <= 2; i++)
			for (int j = -2; j <= 2; j++)
			{
				double pos_x = i * step + (double)x;                        //当前小格点的x坐标
				double pos_y = j * step + (double)y;
				double distance_sqr = current_line.PointLineDistance_Sqr(pos_x, pos_y);
				//cout << pos_x << " " << pos_y << " " << distance_sqr << endl;
				if (distance_sqr < 0.25)                         //默认直线宽度为1， distancesqr<0.25意味着格点在直线内
				{
					_color.a += (unsigned char)distribute_matrix[i + 2][j + 2];          //灰度加上当前格点的权值
				}
			}
		//cout <<(int) _color.a<<endl;
		Color mixed = _color.mix_back(drawer_instance->get_pixel(x, y));
		drawer_instance->set_pixel(x, y, mixed);
	}
}

void drawline::line_drawer(int start_x, int start_y, int end_x, int end_y, Color color)
{
	current_line.set_line(start_x, start_y, end_x, end_y);
	if (start_x > end_x)               //保证起点在终点左侧
	{
		swap(start_x, end_x);
		swap(start_y, end_y);
	}
	if (start_y <= end_y)              //起点在终点下方
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
	if(!k_big_flag)               //斜率绝对值小于1
	{
		drawer_instance->set_pixel(x, y, color);
		if (is_antialiasing)
		{
			anti_aliasing(x, y + 1, color);
			anti_aliasing(x, y - 1, color);
		}
	}
	else
	{
		drawer_instance->set_pixel(y, x, color);
		if (is_antialiasing)
		{
			anti_aliasing(y + 1, x, color);
			anti_aliasing(y - 1, x, color);
		}
	}
}