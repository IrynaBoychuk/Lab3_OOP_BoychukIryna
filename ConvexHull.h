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
class ConvexHull: public BasePointMethod
{
private:
	std::vector<Point> convexHull;
	std::vector<Edge> edges;
protected:		
	void VectorMultip();
	void GrahamScan();
	void FillEdges();
public:
	ConvexHull(vector<Point> points) :BasePointMethod(points) {};
	~ConvexHull(){}

	void Build();
	void Draw(RenderWindow &window);
};