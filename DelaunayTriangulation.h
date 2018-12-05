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
};