#pragma once
#include <utility>
#include <vector>
using namespace std;
class PolygonDrawer
{
	vector<pair<int, int>> vertex;                     //����ζ���
public:
	PolygonDrawer();
	~PolygonDrawer();
	void add_vertex(int x, int y);                      //Ϊ�������Ӷ���
	bool draw_border();
};

