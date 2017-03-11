#include "line.h"



line::line()
{
	A = 0;
	B = 0;
	C = 0;
}
line::line(int start_x, int start_y, int end_x, int end_y)
{
	A = start_y - end_y;
	B = end_x - start_x;

}

line::~line()
{
}
