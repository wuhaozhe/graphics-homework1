#include "drawline.h"



drawline::drawline()
{
	drawer_instance = drawer::get_instance();
}


drawline::~drawline()
{
}

void drawline::anti_aliasing()              //todo: �д�ʵ��
{

}

void drawline::line_drawer()
{
	
}

bool drawline::line_parameters_judge(int start_x, int start_y, int end_x, int end_y)
{
	if (start_x < end_x && start_y <= end_y && (end_x - start_x) >(end_y - start_y))               //������ˮƽ��ֱ��
	{
		return true;
	}
	else
	{
		return false;
	}
}