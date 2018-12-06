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
class VoronoiDiagram : public BasePointMethod
{
private:
	std::vector<Point> voronoidiagram;
	//std::vector<Point> voronoiCentr;
	std::vector<Edge> edges;
public:
	VoronoiDiagram(vector<Point> points) :BasePointMethod(points) {};
	~VoronoiDiagram() {};
	void VoronoiFindCentr();
	void Build();
	void Draw(RenderWindow &window);
	void FillEdges();
};