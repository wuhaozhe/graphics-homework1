#ifndef DRAWLINE_H
#define DRAWLINE_H
#include "drawer.h"
class drawline
{
public:
	drawline();
	~drawline();
	void line_drawer();
	virtual bool partline_drawer(int start_x, int start_y, int end_x, int end_y, Color color, bool k_negative_flag, bool k_big_flag) = 0; //k_negative��ʾб��Ϊ��, k_big��ʾб�ʾ���ֵ����1
protected:
	drawer* drawer_instance;
	virtual void anti_aliasing();                //������
	bool line_parameters_judge(int start_x, int start_y, int end_x, int end_y);
};
#endif