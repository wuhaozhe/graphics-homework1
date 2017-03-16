#pragma once
#include "drawline.h"
class Polygondrawline : public drawline
{
public:
	Polygondrawline();
	Polygondrawline(PolygonDrawer* in);
	~Polygondrawline();
	bool partline_drawer(int start_x, int start_y, int end_x, int end_y, Color color, bool k_negative_flag, bool k_big_flag);
};

