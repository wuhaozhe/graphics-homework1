#include "drawer.h"
#include "DDAdrawline.h"
#include "Bresenhamdrawline.h"
#include "PolygonDrawer.h"
#include "line.h"
#include <cmath>
using namespace std;
const double pi = 3.1415926;

int main()
{
	Color a;
	a.r = 255; a.g = 255; a.b = 255; a.a = 255;
	drawer::get_instance()->set_size(1000, 1000);
	for(int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
		{
			(drawer::get_instance())->set_pixel(i, j, a);
		}
	drawline *temp = new Bresenhamdrawline();
	a.g = 0, a.b = 0, a.r = 255;
	PolygonDrawer *temp2 = new PolygonDrawer();
	temp2->add_vertex(1, 1);
	temp2->add_vertex(500, 500);
	temp2->add_vertex(400, 300);
	temp2->add_vertex(100, 0);
	temp2->fill_polygon(a);
	temp->line_drawer(10, 20, 0, 0, a);
	for (int i = 0; i < 360; i += 10)
	{
		int x = 490 * cos(i * pi / 180) + 500;
		int y = 490 * sin(i * pi / 180) + 500;
		a.r = x % 256, a.g = y % 256;
		temp->line_drawer(500, 500, x, y, a);
	}
	drawer::get_instance()->output_image();
	return 0;
}

