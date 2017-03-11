#include "drawline.h"
#include <cstdio>


drawline::drawline()
{
	drawer_instance = drawer::get_instance();
	for(int i = 0; i < 5; i++)                          //��һ��
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
		Color _color;                      //������ʱ��ǰ������ɫ
		_color.r = color.r, _color.g = color.g, _color.b = color.b, _color.a = 0;
		//cout << x << " " << y << endl;
		for(int i = -2; i <= 2; i++)
			for (int j = -2; j <= 2; j++)
			{
				double pos_x = i * step + (double)x;                        //��ǰС����x����
				double pos_y = j * step + (double)y;
				double distance_sqr = current_line.PointLineDistance_Sqr(pos_x, pos_y);
				//cout << pos_x << " " << pos_y << " " << distance_sqr << endl;
				if (distance_sqr < 0.25)                         //Ĭ��ֱ�߿��Ϊ1�� distancesqr<0.25��ζ�Ÿ����ֱ����
				{
					_color.a += (unsigned char)distribute_matrix[i + 2][j + 2];          //�Ҷȼ��ϵ�ǰ����Ȩֵ
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
	if (start_x > end_x)               //��֤������յ����
	{
		swap(start_x, end_x);
		swap(start_y, end_y);
	}
	if (start_y <= end_y)              //������յ��·�
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
	else                              //������յ��Ϸ�
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
	if (start_x < end_x && start_y <= end_y && (end_x - start_x) >= (end_y - start_y))               //������ˮƽ��ֱ��
	{
		return true;
	}
	else
	{
		return false;
	}
}
void drawline::draw_line_pixel(unsigned int x, unsigned int y, bool k_big_flag, Color color)                 //����flag����
{
	if(!k_big_flag)               //б�ʾ���ֵС��1
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