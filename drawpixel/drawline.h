#ifndef DRAWLINE_H
#define DRAWLINE_H
#include "drawer.h"
#include "line.h"
#include "PolygonDrawer.h"
class drawline
{
public:
	drawline();
	drawline(PolygonDrawer* input);
	~drawline();
	void line_drawer(int start_x, int start_y, int end_x, int end_y, Color color);
	virtual bool partline_drawer(int start_x, int start_y, int end_x, int end_y, Color color, bool k_negative_flag, bool k_big_flag) = 0; //k_negative��ʾб��Ϊ��, k_big��ʾб�ʾ���ֵ����1
	bool is_antialiasing = true;                    //�������Ŀ���
protected:
	drawer* drawer_instance;
	PolygonDrawer* polygon_drawer;                     //�������ʱ�Ķ����drawerʵ��
	virtual void anti_aliasing(int x, int y, Color color);                //������
	bool line_parameters_judge(int start_x, int start_y, int end_x, int end_y);            //�ж�ֱ�߲����Ƿ�Ϸ�
	void draw_line_pixel(unsigned int x, unsigned int y, bool k_big_flag, Color color);             //����flag������pixel������
	double distribute_matrix[5][5] =                //��˹�˲�����ɢ����ľ���
	{
		{ 1, 1, 1, 1, 1 },
		{ 1, 2, 4, 2, 1 },
		{ 1, 4, 8, 4, 1 },
		{ 1, 2, 4, 2, 1 },
		{ 1, 1, 1, 1, 1 }
	};
	const int sum = 48;                             //��˹�˲�����ɢ����ľ�������Ԫ��֮��
	line current_line;
	double step = 0.2;                              //���������������ľ���
	void(PolygonDrawer::* func)(int, int);                //�߽��־�㷨�б�־�ߵ�λ��
};
#endif