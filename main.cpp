#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include "Vector2.h"
#include "Point.h"
#include "BasePointMethod.h"
#include "ConvexHull.h"

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
	int n;
	scanf_s("%d", &n);
	vector <Point> p;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf_s("%d %d", &x, &y);
		p.push_back(Point{ x,y });
	}

	BasePointMethod *method = new ConvexHull(p);
	//*method = new Voronnyi(p);
	method->Build();

	sf::RenderWindow window(sf::VideoMode(1200, 900), "ConvexHull");
	bool drawn = false;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (!drawn) {
			drawn = true;
			window.clear();

			method->Draw(window);

			window.display();
		}
	}
	p.at(0);
	system("pause");
	return 0;
}

////визначення к-сті точок
//int numberPoints = 20;
//if (argc > 1)
//{
//	numberPoints = atoi(argv[1]); // convert the first argument to an int 
//}

////генерація точок
//cout << "Generating " << numberPoints << " random points" << endl;
//srand(time(NULL));
//vector<Vector2<float> > points;
//for (int i = 0; i < numberPoints; ++i) {
//	points.push_back(Vector2<float>(RandomFloat(0, 800), RandomFloat(0, 600)));
//}
//// SFML window
//sf::RenderWindow window(sf::VideoMode(800, 600), "Delaunay triangulation");
////Перетворення точок в кружочки Transform each points of each vector as a Circle
//	std::vector<sf::CircleShape*> circles;
//	for (const auto p : points) {
//		sf::CircleShape *c1 = new sf::CircleShape(4);
//		c1->setPosition(p.x, p.y);
//		circles.push_back(c1);
//	}

//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//		window.clear();
//		// Draw the circles
//		for (const auto &s : circles) {
//			window.draw(*s);
//		}	

//		window.display();
//	}





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