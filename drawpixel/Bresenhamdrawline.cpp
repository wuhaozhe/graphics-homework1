#include "Bresenhamdrawline.h"



Bresenhamdrawline::Bresenhamdrawline()
{
}


Bresenhamdrawline::~Bresenhamdrawline()
{
}

bool Bresenhamdrawline::partline_drawer(int start_x, int start_y, int end_x, int end_y, Color color, bool k_negative_flag, bool k_big_flag)
{
	int x, y, dx, dy, e;
	dx = end_x - start_x, dy = end_y - start_y, e = -1 * dx;
	x = start_x, y = start_y;
	for (int i = 0; i <= dx; i++)
	{
		draw_line_pixel(x, y, k_big_flag, color);
		x++;
		e += 2 * dy;
		if (k_negative_flag)
		{
			if (e <= 0)
			{
				y--;
				e += 2 * dx;
			}
		}
		else
		{
			if (e >= 0)
			{
				y++;
				e -= 2 * dx;
			}
		}
	}
	return true;
}