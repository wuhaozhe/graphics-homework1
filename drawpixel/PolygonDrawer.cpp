#include "PolygonDrawer.h"



PolygonDrawer::PolygonDrawer()
{
	
}


PolygonDrawer::~PolygonDrawer()
{
}

void PolygonDrawer::add_vertex(int x, int y)
{
	vertex.push_back(make_pair(x, y));
}

bool PolygonDrawer::draw_border()
{

}