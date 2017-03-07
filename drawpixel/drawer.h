#ifndef DRAWER_H
#define DRAWER_H
#include <iostream>
#include <vector>
using namespace std;
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
	void set_size(int width, int height);         //����ͼƬ�Ĵ�С 
	void set_pixel(int x, int y, Color color);     //����������ɫ
private:
	int width;
	int height;
	static drawer* instance;
};
struct Color         //Pixel�����r, g, b, a
{
	int r;
	int g;
	int b;
	int a;
};
#endif