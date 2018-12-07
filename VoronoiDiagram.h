#pragma once

#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include <vector>
//#include <cstdio>
#include <vector>
#include<algorithm>
#include "Point.h"
#include"DelaunayTriangulation.h"

using namespace sf;
class VoronoiDiagram : public DelaunayTriangulation
{
private:
	std::vector<Point> voronoidiagram;
	std::vector<Point> centryKil;
	std::vector<Edge> voroniyEdges;
public:
	VoronoiDiagram(vector<Point> points) :DelaunayTriangulation(points) {};
	~VoronoiDiagram() {};
	void VoronoiFindCentr();
	void Build();
	void Draw(RenderWindow &window);
	void FillEdges();
	void FillCentryKil();
};