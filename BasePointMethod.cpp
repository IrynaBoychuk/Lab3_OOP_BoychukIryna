#include "BasePointMethod.h"
#include <array>

BasePointMethod::BasePointMethod(vector<Point> points) {
	for (auto &point:points)
		this->points.push_back(point);
	sort();
	makeUnique();
};

//сортування
void BasePointMethod::sort()
{
	std::sort(points.begin(), points.end(), [](const Point &left, const Point &right)
	{
		if (left.y != right.y)
		{
			return left.y < right.y;
		}
		return left.x < right.x;
	});
}

void BasePointMethod::makeUnique()
{
	points.erase(
		unique(points.begin(), 
			points.end(), 
			[](const Point &left, const Point &right)
			{	return left.x == right.x && left.y == right.y;	}), 
			points.end());

	int n = (int)points.size();
	if (n == 1)
	{
		throw "Can not build convex hull with 1 point";
	}
}

void BasePointMethod::DrawPoints(RenderWindow &window, std::vector<Point> pointList, Color color, int size) 
{
	std::vector<sf::CircleShape*> circles;
	for (const auto p : pointList) {
		sf::CircleShape *c1 = new sf::CircleShape(size);
		c1->setFillColor(color);
		c1->setPosition(p.x, p.y);
		circles.push_back(c1);
	}

	// Draw the circles
	for (const auto &s : circles)
	{
		window.draw(*s);
	}
}

void BasePointMethod::DrawEdges(RenderWindow &window, std::vector<Edge> LineList, Color color, int size) {
	//TODO
	std::vector<std::array<sf::Vertex, 2> > lines;
	for (const auto &e : LineList) {
		lines.push_back({ {
				sf::Vertex(sf::Vector2f(e.p1.x + 4, e.p1.y + 4),color),
				sf::Vertex(sf::Vector2f(e.p2.x + 4, e.p2.y + 4),color)
			} });
	}
	// Draw the lines
	for (const auto &l : lines) {
		window.draw(l.data(), 2, sf::Lines);
	}
}