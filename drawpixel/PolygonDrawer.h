#pragma once
#include <utility>
#include <vector>
#include <climits>
#include "drawer.h"
using namespace std;
class PolygonDrawer
{
	vector<pair<int, int>> vertex;                     //多边形顶点
	int min_x, min_y, max_x, max_y;                    //顶点的最小/最大 x/y
	bool** edge_flag;
public:
	PolygonDrawer();
	~PolygonDrawer();
	void add_vertex(int x, int y);                      //为多边形添加定点
	bool draw_border(Color color);                                 //画出边界，返回画边界是否成功
	bool fill_polygon(Color color);                                //填充多边形
	void set_lineflag(int x, int y);                            //标识当前像素上有边
protected:
	drawer* drawer_instance;
	void reset_extreme_value(int x, int y);
	void set_edge_flag(int width, int height);                  //设置边界标识矩阵的大小
	void release_edge_flag(int width, int height);              //释放边界标识矩阵
	void produce_edge_flag();                                   //遍历顶点，产生边界标识矩阵的大小
	void fill_polygon_inside(Color color);                                 //根据已经产生的点的矩阵填充多边形
};

