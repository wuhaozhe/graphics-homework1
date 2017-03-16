#include "PolygonDrawer.h"
#include "Polygondrawline.h"
#include "Bresenhamdrawline.h"


PolygonDrawer::PolygonDrawer()
{
	drawer_instance = drawer::get_instance();
	min_x = INT_MAX, min_y = INT_MAX;
	max_x = INT_MIN, max_y = INT_MIN;
}


PolygonDrawer::~PolygonDrawer()
{
}

void PolygonDrawer::add_vertex(int x, int y)
{
	vertex.push_back(make_pair(x, y));
}

bool PolygonDrawer::draw_border(Color color)
{
	if (vertex.size() < 3)
	{
		return false;            //没有足够多的定点，无法画多边形
	}
	else
	{
		Polygondrawline* line_draw = new Polygondrawline(this);
		Bresenhamdrawline* border_draw = new Bresenhamdrawline();
		int start_x = vertex[0].first, start_y = vertex[0].second;
		for (int i = 1; i < vertex.size(); i++)
		{
			int terminal_x = vertex[i].first, terminal_y = vertex[i].second;
			line_draw->line_drawer(start_x, start_y, terminal_x, terminal_y, color);
			border_draw->line_drawer(start_x, start_y, terminal_x, terminal_y, color);
			start_x = terminal_x, start_y = terminal_y;
		}
		line_draw->line_drawer(start_x, start_y, vertex[0].first, vertex[0].second, color);
		border_draw->line_drawer(start_x, start_y, vertex[0].first, vertex[0].second, color);
		delete line_draw;
		delete border_draw;
		return true;
	}
}

void PolygonDrawer::reset_extreme_value(int x, int y)
{
	if (x < min_x)
		min_x = x;
	if (y < min_y)
		min_y = y;
	if (x > max_x)
		max_x = x;
	if (y > max_y)
		max_y = y;
}
void PolygonDrawer::set_edge_flag(int width, int height)
{
	edge_flag = new bool*[height];
	for (int i = 0; i < height; i++)
	{
		edge_flag[i] = new bool[width] {0};
	}
}
void PolygonDrawer::release_edge_flag(int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		delete[] edge_flag[i];
	}
	delete[] edge_flag;
}
void PolygonDrawer::produce_edge_flag()
{
	for (int i = 0; i < vertex.size(); i++)
	{
		reset_extreme_value(vertex[i].first, vertex[i].second);
	}
	int width = 1 + max_x - min_x;
	int height = 1 + max_y - min_y;
	set_edge_flag(width, height);
}
void PolygonDrawer::set_lineflag(int x, int y)
{
	edge_flag[y - min_y][x - min_x] = !edge_flag[y - min_y][x - min_x];
}
bool PolygonDrawer::fill_polygon(Color color)
{
	produce_edge_flag();
	if (!draw_border(color))
	{
		return false;
	}
	else
	{
		fill_polygon_inside(color);
		return true;
	}
}
void PolygonDrawer::fill_polygon_inside(Color color)
{
	for (int i = min_y + 1; i < max_y; i++)
	{
		bool draw_flag = false;
		for (int j = min_x; j <= max_x; j++)
		{
			if (edge_flag[i - min_y][j - min_x])
			{
				draw_flag = !draw_flag;
			}
			if (draw_flag)
			{
				drawer_instance->set_pixel(j, i, color);
			}
		}
	}
}