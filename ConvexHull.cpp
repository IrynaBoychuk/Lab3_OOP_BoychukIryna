#include "ConvexHull.h"

void ConvexHull::Build() {
	VectorMultip();
	GrahamScan();
	FillEdges();
}

void ConvexHull::FillEdges()
{
	edges.clear();
	//last
	Point prev  = convexHull[convexHull.size() - 1];
	Point current = convexHull[0];
	edges.push_back(Edge(prev, current));
	
	for (int i = 1; i < convexHull.size(); i++)
	{
		prev = current;
		current = convexHull[i];
		edges.push_back(Edge(prev, current));
	}

}

void ConvexHull::Draw(RenderWindow &window) {
	DrawEdges(window, edges);
	DrawPoints(window, points);
	DrawPoints(window, convexHull,Color::Red);
}

void ConvexHull::VectorMultip()
{
	std::sort(points.begin() + 1, points.end(), [&](const Point &left, const Point &right)
	{
		int dxL = left.x - points[0].x;
		int dyL = left.y - points[0].y;
		int dxR = right.x - points[0].x;
		int dyR = right.y - points[0].y;
		//векторное произв
		int vp = dxL*dyR - dxR*dyL;
		if (vp != 0)
		{
			return vp < 0;
		}
		return dxL*dxL + dyL*dyL < dxR*dxR + dyR*dyR;
	});
}


void ConvexHull::GrahamScan()
{
	convexHull.clear();
	int n = (int)points.size();
	convexHull.push_back(points[0]);
	convexHull.push_back(points[1]);
	for (int i = 2; i < n; i++)
	{
		while (true)
		{
			if (convexHull.size() < 2)
			{
				break;
			}
			const Point &last = convexHull[convexHull.size() - 1];
			const Point &prev = convexHull[convexHull.size() - 2];
			const Point &cur = points[i];
			if ((last.x - prev.x)*(cur.y - last.y) - (last.y - prev.y)*(cur.x - last.x) < 0)
			{
				break;
			}
			if ((last.x - prev.x)*(cur.y - last.y) - (last.y - prev.y)*(cur.x - last.x) == 0)
			{
				break;
			}
			convexHull.pop_back();
		}
		convexHull.push_back(points[i]);
	}
}
