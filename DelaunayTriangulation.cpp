#include "DelaunayTriangulation.h"

void DelaunayTriangulation::Build() {
	
}


void DelaunayTriangulation::Draw(RenderWindow &window) {
	DrawEdges(window, edges);
	DrawPoints(window, points);
	DrawPoints(window, delaunayTriangulation, Color::Blue);
}