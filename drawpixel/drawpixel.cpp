#include "drawer.h"
#include "DDAdrawline.h"
#include "Bresenhamdrawline.h"
#include "PolygonDrawer.h"
#include "line.h"
#include <cmath>
#include <time.h>
using namespace std;
const double pi = 3.1415926;

int main()
{
	Color a;
	a.r = 255; a.g = 255; a.b = 255; a.a = 255;
	drawer::get_instance()->set_size(1000, 1000);
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
		{
			(drawer::get_instance())->set_pixel(i, j, a);
		}
	drawline *temp = new Bresenhamdrawline();
	a.g = 0, a.b = 0, a.r = 255;
	PolygonDrawer *temp2 = new PolygonDrawer();
	temp2->add_vertex(19, 550);
	temp2->add_vertex(20, 10);
	temp2->add_vertex(21, 540);
	temp2->add_vertex(30, 5);
	temp2->add_vertex(50, 598);
	temp2->fill_polygon(a);
	delete temp2;
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

