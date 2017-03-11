#ifndef DRAWLINE_H
#define DRAWLINE_H
#include "drawer.h"
#include "line.h"
#include "PolygonDrawer.h"
class drawline
{
public:
	drawline();
	drawline(PolygonDrawer* input);
	~drawline();
	void line_drawer(int start_x, int start_y, int end_x, int end_y, Color color);
	virtual bool partline_drawer(int start_x, int start_y, int end_x, int end_y, Color color, bool k_negative_flag, bool k_big_flag) = 0; //k_negative表示斜率为负, k_big表示斜率绝对值大于1
	bool is_antialiasing = true;                    //反走样的开关
protected:
	drawer* drawer_instance;
	PolygonDrawer* polygon_drawer;                     //画多边形时的多边形drawer实例
	virtual void anti_aliasing(int x, int y, Color color);                //反走样
	bool line_parameters_judge(int start_x, int start_y, int end_x, int end_y);            //判断直线参数是否合法
	void draw_line_pixel(unsigned int x, unsigned int y, bool k_big_flag, Color color);             //根据flag决定画pixel的正负
	double distribute_matrix[5][5] =                //高斯滤波器离散化后的矩阵
	{
		{ 1, 1, 1, 1, 1 },
		{ 1, 2, 4, 2, 1 },
		{ 1, 4, 8, 4, 1 },
		{ 1, 2, 4, 2, 1 },
		{ 1, 1, 1, 1, 1 }
	};
	const int sum = 48;                             //高斯滤波器离散化后的矩阵所有元素之和
	line current_line;
	double step = 0.2;                              //抗锯齿中相邻两点的距离
	void(PolygonDrawer::* func)(int, int);                //边界标志算法中标志边的位置
};
#endif