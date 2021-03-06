#include "VoronoiDiagram.h"



Point Vector2ConversionToPoint(TestSFML::Vector2<double> p) {
	return Point(p.x, p.y);
}

void VoronoiDiagram::Build()
{
	FillTrianglesAndEdges();
	FillCentryKil();
	//VoronoiFindCentr();
	//FillEdges();
}

void VoronoiDiagram::FillCentryKil()
{
	for (auto t : this->triangles)
	{
		centryKil.push_back(Vector2ConversionToPoint(t.circumCircleCenter()));
	}
	//FIND also edges
	for (int i = 0; i < triangles.size(); i++)
	{
		auto t1 = triangles[i];
		for (int j = i + 1; j < triangles.size(); j++)
		{
			auto t2 = triangles[j];
			if (t1.hasCommonEdge(t2)) {
				auto center1 = t1.circumCircleCenter();
				auto center2 = t2.circumCircleCenter();
				voroniyEdges.push_back(Edge(Vector2ConversionToPoint(center1), Vector2ConversionToPoint(center2)));
			}
		}
	}
}

//
//void VoronoiDiagram::VoronoiFindCentr()
//{
//	voronoidiagram.clear();
//	int n = (int)points.size();
//	for (int i = 0; i < n; i++)
//	{
//		while (voronoidiagram.size() > 2)
//		{
//
//			Point &first = voronoidiagram[voronoidiagram.size() - 1];
//			Point &second = voronoidiagram[voronoidiagram.size() - 2];
//			Point &third = voronoidiagram[voronoidiagram.size() - 3];
//			Point centr = points[i];
//			double x1 = first.x, x2 = second.x, x3 = third.x;
//			double y1 = first.y, y2 = second.y, y3 = third.y;
//			double x12 = x1 - x2, x23 = x2 - x3, x31 = x3 - x1;
//			double y12 = y1 - y2, y23 = y2 - y3, y31 = y3 - y1;
//			double SumKvadr1 = pow(x1, 2) + pow(y1, 2);
//			double SumKvadr2 = pow(x2, 2) + pow(y2, 2);
//			double SumKvadr3 = pow(x3, 2) + pow(y3, 2);
//
//			centr.y = (SumKvadr1*x23 + SumKvadr2*x31 + SumKvadr3*x12) / (2 * (y31*x12 - y12*x31));
//			centr.x = -(SumKvadr1*y23 + SumKvadr2*y31 + SumKvadr3*y12) / (2 * (y31*x12 - y12*x31));
//			cout << "X:" << centr.x << endl;
//			cout << "Y:" << centr.y << endl; //���� ���������
//			voronoidiagram.pop_back();
//		}
//		voronoidiagram.push_back(points[i]);
//	}
//}


void VoronoiDiagram::Draw(RenderWindow &window) {
	DrawEdges(window, edges);
	DrawPoints(window, points);
	DrawPoints(window, voronoidiagram, Color::Blue);
	DrawPoints(window, centryKil, Color::Magenta);
	DrawEdges(window, voroniyEdges, Color::Magenta);
}

void VoronoiDiagram::FillEdges()
{
	//edges.clear();
	////last
	//Point prev = voronoidiagram[voronoidiagram.size() - 1];
	//Point current = voronoidiagram[0];
	//edges.push_back(Edge(prev, current));

	//for (int i = 1; i < voronoidiagram.size(); i++)
	//{
	//	prev = current;
	//	current = voronoidiagram[i];
	//	edges.push_back(Edge(prev, current));
	//}

}