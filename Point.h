#pragma once

#include <cstdio>
#include <vector>
#include <cmath>
#include<algorithm>
#include<cassert>

struct Point
{
	Point(float xx, float yy) :x(xx), y(yy){}
	Point(double xx, double yy) :x(xx), y(yy){}

	double x;
	double y;
};

