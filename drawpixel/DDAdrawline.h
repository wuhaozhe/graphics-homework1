#pragma once
#include "drawline.h"
class DDAdrawline : public drawline
{
public:
	DDAdrawline();
	~DDAdrawline();
	bool partline_drawer(int start_x, int start_y, int end_x, int end_y, Color color, bool k_negative_flag ,bool k_big_flag);
};

