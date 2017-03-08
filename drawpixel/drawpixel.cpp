#include "drawer.h"
#include "DDAdrawline.h"
using namespace std;

int main()
{
	Color a;
	a.r = 255; a.g = 255; a.b = 255; a.a = 255;
	drawer::get_instance()->set_size(100, 100);
	for(int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
		{
			(drawer::get_instance())->set_pixel(i, j, a);
		}
	drawline *temp = new DDAdrawline();
	a.g = 0, a.b = 0;
	temp->partline_drawer(0, 0, 50, 0, a);
	drawer::get_instance()->output_image();
	return 0;
}

