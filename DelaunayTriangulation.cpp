#include "DelaunayTriangulation.h"

Edge EdgeConversion(TestSFML::Edge<double> e) {
	return Edge(Point(e.p1.x, e.p1.y), Point(e.p2.x, e.p2.y));
}
TestSFML::Vector2<double> PointToVector2Conversion(Point p) {
	return TestSFML::Vector2<double>(p.x, p.y);
}

void DelaunayTriangulation::Build() {
	FillTrianglesAndEdges();
}

void DelaunayTriangulation::FillTrianglesAndEdges() {
	std::vector<TestSFML::Vector2<double> > points22;
	for (auto p : points)
		points22.push_back(PointToVector2Conversion(p));

	TestSFML::Delaunay<double> triangulation;
	const std::vector<TestSFML::Triangle<double> > triangles = triangulation.triangulate(points22);
	this->triangles = triangles;
	const std::vector<TestSFML::Edge<double> > edges = triangulation.getEdges();
	for (auto e : edges)
		this->edges.push_back(EdgeConversion(e));
}

void DelaunayTriangulation::Draw(RenderWindow &window) {
	DrawEdges(window, edges);
	DrawPoints(window, points);
	DrawPoints(window, delaunayTriangulation, Color::Blue);
}