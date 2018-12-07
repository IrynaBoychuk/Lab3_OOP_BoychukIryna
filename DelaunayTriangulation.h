#pragma once

#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"

//#include <cstdio>
#include <vector>
#include<algorithm>
#include "Point.h"
#include"BasePointMethod.h"

#include "FromTestSFML/numeric.h"
#include "FromTestSFML/vector2.h"
#include "FromTestSFML/triangle.h"
#include "FromTestSFML/delaunay.h"

using namespace sf;
class DelaunayTriangulation : public BasePointMethod
{
protected:
	std::vector<Point> delaunayTriangulation;
	std::vector<Edge> edges;
	std::vector<TestSFML::Triangle<double>> triangles;
public:
	DelaunayTriangulation(vector<Point> points) :BasePointMethod(points) {};
	~DelaunayTriangulation() {};
	void Build();
	void Draw(RenderWindow &window);
	void FillEdges();
	void FillTrianglesAndEdges();
};