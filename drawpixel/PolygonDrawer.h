#pragma once
#include <utility>
#include <vector>
#include <climits>
#include "drawer.h"
using namespace std;
class PolygonDrawer
{
	vector<pair<int, int>> vertex;                     //����ζ���
	int min_x, min_y, max_x, max_y;                    //�������С/��� x/y
	bool** edge_flag;
public:
	PolygonDrawer();
	~PolygonDrawer();
	void add_vertex(int x, int y);                      //Ϊ�������Ӷ���
	bool draw_border(Color color);                                 //�����߽磬���ػ��߽��Ƿ�ɹ�
	bool fill_polygon(Color color);                                //�������
	void set_lineflag(int x, int y);                            //��ʶ��ǰ�������б�
protected:
	drawer* drawer_instance;
	void reset_extreme_value(int x, int y);
	void set_edge_flag(int width, int height);                  //���ñ߽��ʶ����Ĵ�С
	void release_edge_flag(int width, int height);              //�ͷű߽��ʶ����
	void produce_edge_flag();                                   //�������㣬�����߽��ʶ����Ĵ�С
	void fill_polygon_inside(Color color);                                 //�����Ѿ������ĵ�ľ����������
};

