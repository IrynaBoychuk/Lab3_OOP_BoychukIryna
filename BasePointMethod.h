#pragma once

#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include <vector>
#include <cstdio>
#include <vector>
#include <cmath>
#include<algorithm>
#include<cassert>
#include "Edge.h"

using namespace sf;
using namespace std;
class BasePointMethod
{
protected:
	std::vector<Point> points;
public:
	BasePointMethod(std::vector<Point> points);
	~BasePointMethod() {};

	void sort();
	void makeUnique();

	virtual void Build()=0;
	virtual void Draw(RenderWindow &window)=0;

	void static DrawPoints(RenderWindow &window, std::vector<Point> pointList, Color color=Color::White, int size=4);
	void static DrawEdges(RenderWindow &window, std::vector<Edge> lineList, Color color=Color::White, int size=4);
};