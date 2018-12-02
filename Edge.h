#pragma once

#include <cstdio>
#include <vector>
#include <cmath>
#include<algorithm>
#include<cassert>

#include "Point.h" 

struct Edge
{
	Edge(Point point1, Point point2):p1(point1),p2(point2){}

	Point p1;
	Point p2;
};

