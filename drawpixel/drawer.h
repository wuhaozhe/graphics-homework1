#ifndef DRAWER_H
#define DRAWER_H
#include <iostream>
#include "lodepng.h"
using namespace std;
struct Color         //Pixel�����r, g, b, a
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
};
class drawer
{
public:
	drawer();
	~drawer();
	static drawer* get_instance()            //����
	{
		if (instance == nullptr)
		{
			instance = new drawer();
		}
		return instance;
	}
	void set_size(unsigned width, unsigned height);         //����ͼƬ�Ĵ�С 
	void set_pixel(unsigned x, unsigned y, Color color);     //����������ɫͼƬ�����Ͻ�Ϊ0, 0
	bool output_image();                           //��ͼ�����
	const char* filename = "test.png";             //ͼƬ���ʱ���ļ���
private:
	vector<unsigned char> image;
	unsigned width;
	unsigned height;
	static drawer* instance;
};

#endif