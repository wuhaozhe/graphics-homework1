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
	Color mix_back(Color background_color);          //�뱳��ɫ���
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
	Color get_pixel(unsigned x, unsigned y);
	bool output_image();                           //��ͼ�����
	bool point_illegal(int x, int y);                          //�жϵ�ǰ���λ���Ƿ�Ϸ�ʱ
	const char* filename = "test.png";             //ͼƬ���ʱ���ļ���
private:
	vector<unsigned char> image;
	unsigned width;
	unsigned height;
	static drawer* instance;
};

#endif