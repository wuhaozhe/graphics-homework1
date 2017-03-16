#include "Polygondrawline.h"



Polygondrawline::Polygondrawline()
{
}
Polygondrawline::Polygondrawline(PolygonDrawer* in) : drawline(in)
{

}

bool Polygondrawline::partline_drawer(int start_x, int start_y, int end_x, int end_y, Color color, bool k_negative_flag, bool k_big_flag)
{
	int x, y, dx, dy, e;
	dx = end_x - start_x, dy = end_y - start_y;
	x = start_x, y = start_y;
	if (k_negative_flag)
	{
		e = dx;
		if (func != nullptr)
		{
			if (k_big_flag)
			{
				for (int i = 0; i < dx; i++)
				{
					x++;
					e += 2 * dy;
					if (e <= 0)
					{
						y--;
						e += 2 * dx;
					}
					(polygon_drawer->*func)(y, x);
				}
			}
			else
			{
				(polygon_drawer->*func)(x, y);
				for (int i = 0; i < dx; i++)
				{
					x++;
					e += 2 * dy;
					if (e <= 0)
					{
						y--;
						if(y != end_y)
							(polygon_drawer->*func)(x, y);
						e += 2 * dx;
					}
				}
			}
		}	
	}
	else
	{
		e = -1 * dx;
		if (func != nullptr)
		{
			if (k_big_flag)
			{
				for (int i = 0; i < dx; i++)
				{
					x++;
					e += 2 * dy;
					if (e >= 0)
					{
						y++;
						e -= 2 * dx;
					}
					(polygon_drawer->*func)(y, x);
				}
			}
			else
			{
				for (int i = 0; i < dx; i++)
				{
					x++;
					e += 2 * dy;
					if (e >= 0)
					{
						y++;
						(polygon_drawer->*func)(x, y);
						e -= 2 * dx;
					}
				}
			}
		}
	}
	return true;
}
Polygondrawline::~Polygondrawline()
{
}
