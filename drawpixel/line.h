#pragma once
class line                 //ĳ��ֱ�ߵ��࣬����װ���乹����㵽ֱ�������ķ��� AX + BY + C = 0
{
private:
	double A;          //x�Ĳ���
	double B;          //y�Ĳ���
	double C;          //���������
public:
	line();             //Ĭ�Ϲ���
	line(int start_x, int start_y, int end_x, int end_y);                  //��������ʽ����ֱ��
	float PointLineDistance_Sqr(int x, int y);                             //�㵽ֱ�߾����ƽ��
	~line();
};

