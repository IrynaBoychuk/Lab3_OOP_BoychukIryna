#include "DelaunayTriangulation.h"

void DelaunayTriangulation::Build() {
	/*Delaunay<float> triangulation;
	const std::vector<Triangle<float> > triangles = triangulation.triangulate(points);
	std::cout << triangles.size() << " triangles generated\n";
	const std::vector<Edge<float> > edges = triangulation.getEdges();*/
}


void DelaunayTriangulation::Draw(RenderWindow &window) {
	DrawEdges(window, edges);
	DrawPoints(window, points);
	DrawPoints(window, delaunayTriangulation, Color::Blue);
}
void DelaunayTriangulation::FillEdges()
{

}