#pragma once
#include <utility>
#include <vector>
using namespace std;
class PolygonDrawer
{
	vector<pair<int, int>> vertex;                     //多边形顶点
public:
	PolygonDrawer();
	~PolygonDrawer();
	void add_vertex(int x, int y);                      //为多边形添加定点
	bool draw_border();
};

