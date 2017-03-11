#include "drawer.h"
#include <assert.h>
drawer* drawer::instance = new drawer();      //�Ծ�̬��Աʵ����
drawer::drawer()
{
}


drawer::~drawer()
{
}

void drawer::set_pixel(unsigned x, unsigned y, Color color)
{
	assert(x < width && y < height);
	y = width - 1 - y;               //�����������µߵ�
	image[4 * width * y + 4 * x + 0] = color.r;
	image[4 * width * y + 4 * x + 1] = color.g;
	image[4 * width * y + 4 * x + 2] = color.b;
	image[4 * width * y + 4 * x + 3] = color.a;
}
Color drawer::get_pixel(unsigned x, unsigned y)
{
	assert(x < width && y < height);
	y = width - 1 - y;
	Color target_color;
	target_color.r = image[4 * width * y + 4 * x + 0];
	target_color.g = image[4 * width * y + 4 * x + 1];
	target_color.b = image[4 * width * y + 4 * x + 2];
	target_color.a = image[4 * width * y + 4 * x + 3];
	return target_color;
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
bool drawer::point_illegal(int x, int y)
{
	if (x < 0 || y < 0 || x >= width || y >= height)
	{
		return true;                   //��ǰ�㲻�Ϸ�
	}
	else
	{
		return false;                  //��ǰ��Ϸ�
	}
}

Color Color::mix_back(Color background_color)
{
	Color mixed_color;
	double ratio = (double)a / 255;
	mixed_color.r = (unsigned char)(ratio * (double)r + (1 - ratio) * (double)background_color.r);            //���ݻҶ�����ϳɵ�r
	mixed_color.g = (unsigned char)(ratio * (double)g + (1 - ratio) * (double)background_color.g);            //���ݻҶ�����ϳɵ�g
	mixed_color.b = (unsigned char)(ratio * (double)b + (1 - ratio) * (double)background_color.b);            //���ݻҶ�����ϳɵ�g
	mixed_color.a = 255;
	return mixed_color;
}