#include "drawline.h"
#include <cstdio>


drawline::drawline()
{
	drawer_instance = drawer::get_instance();
	for(int i = 0; i < 5; i++)                          //��һ��
		for (int j = 0; j < 5; j++)
		{
			distribute_matrix[i][j] /= sum;
		}
}


drawline::~drawline()
{
}

void drawline::anti_aliasing()              //todo: �д�ʵ��
{

}

void drawline::line_drawer(int start_x, int start_y, int end_x, int end_y, Color color)
{
	if (start_x > end_x)               //��֤������յ����
	{
		swap(start_x, end_x);
		swap(start_y, end_y);
	}
	if (start_y < end_y)              //������յ��·�
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
	if(!k_big_flag)               //б�ʾ���ֵС��1����б��Ϊ��
	{
		drawer_instance->set_pixel(x, y, color);
	}
	else
	{
		drawer_instance->set_pixel(y, x, color);
	}
}