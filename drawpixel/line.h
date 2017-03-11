#pragma once
class line                 //某个直线的类，并封装了其构造与点到直线求距离的方法 AX + BY + C = 0
{
private:
	int A;          //x的参数
	int B;          //y的参数
	int C;          //常数项参数
public:
	line();
	line(int start_x, int start_y, int end_x, int end_y);                  //根据两点式构造直线
	double PointLineDistance_Sqr(double x, double y);                             //点到直线距离的平方
	~line();
	void set_line(int start_x, int start_y, int end_x, int end_y);
};

