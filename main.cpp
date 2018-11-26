#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include "Vector2.h"


//#include <sstream>
//#include<fstream>
//using namespace std;
//
//class Figure
//{
//
//};
//
//class Point
//{
//private:
//	double X, Y;
//public:
//	Point(double x = 0, double  y = 0) :X(x), Y(y) {}
//
//	double getX()const{ return X; }
//	double getY()const{ return Y; }
//
//
//
//	Point operator + (Point & point) {
//		double pointX = this->X + point.getX();
//		double pointY = this->Y + point.getY();
//		Point P(pointX, pointY);
//		return P;
//	}
//	Point plus(Point & point) {
//		double pointX = this->X + point.getX();
//		double pointY = this->Y + point.getY();
//		Point P(pointX, pointY);
//		return P;
//	}
//	static Point staticplus(Point & point1, Point & point2) {
//		double pointX = point1.getX() + point2.getX();
//		double pointY = point1.getY() + point2.getY();
//		Point P(pointX, pointY);
//		return P;
//	}
//	Point operator - (Point & point)
//	{
//		double pointX = this->X - point.getX();
//		double pointY = this->Y - point.getY();
//		Point P(pointX, pointY);
//		return P;
//	}
//	friend ostream & operator<<(ostream & os, const Point & point)
//	{
//		os << "(" <<point.getX()<<","<< point.getY()<<")"<<endl;
//		return os;
//	}
//};

float RandomFloat(float a, float b) {
	const float random = ((float)rand()) / (float)RAND_MAX;
	const float diff = b - a;
	const float r = random * diff;
	return a + r;
}

using namespace std;
//using namespace sf;

int main(int argc, char * argv[]) //argc is the count of argument.argv is short for argument variable
{
	//визначення к-сті точок
	int numberPoints = 100;
	if (argc > 1)
	{
		numberPoints = atoi(argv[1]); // convert the first argument to an int 
	}

	//генерація точок
	cout << "Generating " << numberPoints << " random points" << endl;
	srand(time(NULL));
	vector<Vector2<float> > points;
	for (int i = 0; i < numberPoints; ++i) {
		points.push_back(Vector2<float>(RandomFloat(0, 800), RandomFloat(0, 600)));
	}
	
	// робота з вікном SFML, а саме коодинати точки кліком на вікно
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) // лівою кнопкой миші
	{
	}
	//sf::Vector2f mouse_world = window->mapPixelToCoords(sf::Mouse::getPosition(*window));




	// SFML window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Delaunay triangulation");

	
	//Перетворення точок в квадратики Transform each points of each vector as a Circle
		std::vector<sf::CircleShape*> squares;
		for (const auto p : points) {
			sf::CircleShape *c1 = new sf::CircleShape(2);
			c1->setPosition(p.x, p.y);
			squares.push_back(c1);
		}

	

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();

			// Draw the squares
			for (const auto &s : squares) {
				window.draw(*s);
			}

			

			window.display();
		}
	


	system("pause");
	return 0;
}









//// Make the lines
//std::vector<std::array<sf::Vertex, 2> > lines;
//for (const auto &e : edges) {
//	lines.push_back({ {
//			sf::Vertex(sf::Vector2f(e.p1.x + 2, e.p1.y + 2)),
//			sf::Vertex(sf::Vector2f(e.p2.x + 2, e.p2.y + 2))
//		} });
//}




//// Draw the lines
//for (const auto &l : lines) {
//	window.draw(l.data(), 2, sf::Lines);
//}


//GreenCircle
//sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//sf::CircleShape shape(100.f);
//shape.setFillColor(sf::Color::Green);
//
//while (window.isOpen())
//{
//	sf::Event event;
//	while (window.pollEvent(event))
//	{
//		if (event.type == sf::Event::Closed)
//			window.close();
//	}
//
//	window.clear();
//	window.draw(shape);
//	window.display();
//}


//Point point1(3,4), point2(6,7), point3(5,9);
//
//cout << point1 - point2;
//cout << point1; // <<(cout, point1); //
//point1 = point1.plus(point2);
//point3 = Point::staticplus(point1, point2);
//cout << point3<<endl;
//ifstream fin("input.txt");
//string str;
//while (getline(fin, str))
//{
//	int pos = str.find(" ");
//	string chislo1 = str.substr(0, pos); //get from "" to the end
//	string chislo2 = str.substr(pos + 1); //get from "" to the end
//	cout << chislo1 << endl << chislo2 << endl;
//	double double1, double2;
//	double1 = stod(chislo1);
//	double2 = stod(chislo2);
//	cout << double1;
//}