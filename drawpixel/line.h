#pragma once
class line                 //某个直线的类，并封装了其构造与点到直线求距离的方法 AX + BY + C = 0
{
private:
	double A;          //x的参数
	double B;          //y的参数
	double C;          //常数项参数
public:
	line();             //默认构造
	line(int start_x, int start_y, int end_x, int end_y);                  //根据两点式构造直线
	float PointLineDistance_Sqr(int x, int y);                             //点到直线距离的平方
	~line();
};

