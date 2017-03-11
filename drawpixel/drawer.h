#ifndef DRAWER_H
#define DRAWER_H
#include <iostream>
#include "lodepng.h"
using namespace std;
struct Color         //Pixel的组成r, g, b, a
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
	Color mix_back(Color background_color);          //与背景色混合
};
class drawer
{
public:
	drawer();
	~drawer();
	static drawer* get_instance()            //单件
	{
		if (instance == nullptr)
		{
			instance = new drawer();
		}
		return instance;
	}
	void set_size(unsigned width, unsigned height);         //设置图片的大小 
	void set_pixel(unsigned x, unsigned y, Color color);     //设置像素颜色图片的左上角为0, 0
	Color get_pixel(unsigned x, unsigned y);
	bool output_image();                           //将图像输出
	bool point_illegal(int x, int y);                          //判断当前点的位置是否合法时
	const char* filename = "test.png";             //图片输出时的文件名
private:
	vector<unsigned char> image;
	unsigned width;
	unsigned height;
	static drawer* instance;
};

#endif