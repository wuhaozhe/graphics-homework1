#pragma once
class line                 //ĳ��ֱ�ߵ��࣬����װ���乹����㵽ֱ�������ķ��� AX + BY + C = 0
{
private:
	int A;          //x�Ĳ���
	int B;          //y�Ĳ���
	int C;          //���������
public:
	line();
	line(int start_x, int start_y, int end_x, int end_y);                  //��������ʽ����ֱ��
	double PointLineDistance_Sqr(double x, double y);                             //�㵽ֱ�߾����ƽ��
	~line();
	void set_line(int start_x, int start_y, int end_x, int end_y);
};

