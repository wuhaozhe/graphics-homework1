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
	static drawer* get_instance()            //单件
	{
		if (instance == nullptr)
		{
			instance = new drawer();
		}
		return instance;
	}
	void set_size(int width, int height);         //设置图片的大小 
	void set_pixel(int x, int y, Color color);     //设置像素颜色
private:
	int width;
	int height;
	static drawer* instance;
};
struct Color         //Pixel的组成r, g, b, a
{
	int r;
	int g;
	int b;
	int a;
};
#endif