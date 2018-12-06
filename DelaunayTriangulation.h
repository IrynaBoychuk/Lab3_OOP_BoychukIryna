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
#include"BasePointMethod.h"

//#include "vector2.h"
//#include "triangle.h"
//#include "delaunay.h"

using namespace sf;
class DelaunayTriangulation : public BasePointMethod
{
private:
	std::vector<Point> delaunayTriangulation;
	std::vector<Edge> edges;
public:
	DelaunayTriangulation(vector<Point> points) :BasePointMethod(points) {};
	~DelaunayTriangulation() {};
	void Build();
	void Draw(RenderWindow &window);
	void FillEdges();
};