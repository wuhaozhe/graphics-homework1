#include "drawer.h"
#include <assert.h>
drawer* drawer::instance = new drawer();      //对静态成员实例化
drawer::drawer()
{
}


drawer::~drawer()
{
}

void drawer::set_pixel(unsigned x, unsigned y, Color color)
{
	assert(x < width && y < height);
	y = width - 1 - y;               //将坐标轴上下颠倒
	image[4 * width * y + 4 * x + 0] = color.r;
	image[4 * width * y + 4 * x + 1] = color.g;
	image[4 * width * y + 4 * x + 2] = color.b;
	image[4 * width * y + 4 * x + 3] = color.a;
}
void drawer::set_size(unsigned input_width, unsigned input_height)
{
	height = input_height;
	width = input_width;
	image.resize(4 * width * height);
}
bool drawer::output_image()
{
	unsigned error = lodepng::encode(filename, image, width, height);
	if (error)
	{
		cout << "encode error" << error << ": " << lodepng_error_text(error) << endl;
		return false;
	}
	else
		return true;
}