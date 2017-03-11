#include "line.h"
#include <cmath>
#include <iostream>
using namespace std;

line::line()
{
	A = 0;
	B = 0;
	C = 0;
}
line::line(int start_x, int start_y, int end_x, int end_y)
{
	set_line(start_x, start_y, end_x, end_y);
}
double line::PointLineDistance_Sqr(double x, double y)
{
	double upper = pow(A * x + B * y + C, 2);
	double lower = pow(A, 2) + pow(B, 2);
	return (double)upper / (double)lower;
}
void line::set_line(int start_x, int start_y, int end_x, int end_y)
{
	A = start_y - end_y;
	B = end_x - start_x;
	C = (start_x - end_x) * end_y - (start_y - end_y) * end_x;
	//cout << "A " << A << "B " << B << "C " << C << endl;
}
line::~line()
{
}
