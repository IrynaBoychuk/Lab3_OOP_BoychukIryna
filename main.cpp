#include<iostream>
#include <fstream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
//#include "Vector2.h"
#include "Point.h"
#include "BasePointMethod.h"
#include "ConvexHull.h"
#include "DelaunayTriangulation.h"
#include "VoronoiDiagram.h"

double Random(double b) {
	double random = ((double)rand()) / (double)RAND_MAX;
	double diff = b;
	double r = random * diff;
	return r;
}

using namespace std;
using namespace sf;


enum EWindowState {
	RandomInput,
	Draw
};

int main(int argc, char * argv[])
{
	int numberPoints = 20;
	EWindowState windowState = Draw;
	vector <Point> chosenPoints;
	int x;
	cout << "Choose method of getting coordinates points from 1 to 3 (file,randow,mouseclick):" << endl;
	cin >> x;
	if (x == 1)
	{
		ifstream fin("input.txt");
		double x, y;
		fin >> numberPoints;
		for (int i = 0; i < numberPoints; i++) {
			fin >> x >> y;
			chosenPoints.push_back(Point{ x,y });
		}
	}
	//генерація точок
	else if (x == 2)
	{
		srand(time(NULL));
		for (int i = 0; i < numberPoints; ++i)
		{
			double x, y;
			x = Random(700);
			y = Random(800);
			chosenPoints.push_back(Point{ x,y });
		}
	}
	else if (x == 3)
	{
		windowState = RandomInput;
		cout << "Mouse method" << endl;
	}

	Texture part1, part2, part3;
	part1.loadFromFile("Convexhull.png");
	part2.loadFromFile("Delaunaytriangulation.png");
	part3.loadFromFile("Voronoidiagram.png");

	Sprite menu1(part1), menu2(part2), menu3(part3);
	menu1.setPosition(800, 50);
	menu2.setPosition(800, 200);
	menu3.setPosition(800, 350);



	bool drawn = false;
	BasePointMethod *method = nullptr;
	ConvexHull *methodCH = nullptr;
	DelaunayTriangulation *methodDT = nullptr;
	VoronoiDiagram *methodV = nullptr;
	sf::RenderWindow window(sf::VideoMode(1200, 900), "Building");
	while (window.isOpen())
	{
		sf::Event event;
		int menuNum = 0;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::Resized)
			{
				drawn = false;
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
				
					auto mousePos = sf::Mouse::getPosition(window);
					auto xx = menu1.getLocalBounds();
					if (sf::IntRect(800, 50, 370, 150).contains(sf::Mouse::getPosition(window))) {
						menuNum = 1;
						windowState = Draw;
						if (methodCH == nullptr) {
							methodCH = new ConvexHull(chosenPoints);
							methodCH->Build();
						}
						drawn = false;
						method = methodCH;
					}
					else if (sf::IntRect(800, 200, 370, 150).contains(sf::Mouse::getPosition(window))) {
						menuNum = 2;
						windowState = Draw;
						if (methodDT == nullptr){
							methodDT = new DelaunayTriangulation(chosenPoints);
							methodDT->Build();
						}
						drawn = false;
						method = methodDT;
					}
					else if (sf::IntRect(800, 350, 370, 150).contains(sf::Mouse::getPosition(window))) {
						menuNum = 3;
						windowState = Draw;
						if (methodV == nullptr) {
							methodV = new VoronoiDiagram(chosenPoints);
							methodV->Build();
						}
						drawn = false;
						method = methodV;
					}
					//select points
					else if (windowState == RandomInput) {
						Vector2i pointParam = Mouse::getPosition(window);
						double x = pointParam.x;
						double y = pointParam.y;
						chosenPoints.push_back(Point{ x, y });
						drawn = false;
					}
				}
			}
		}

		if (!drawn ) {
			drawn = true;
			window.clear();

			window.draw(menu1);
			window.draw(menu2);
			window.draw(menu3);


			if (windowState == RandomInput)
				BasePointMethod::DrawPoints(window, chosenPoints);

			if(method!=nullptr && windowState == Draw)
				method->Draw(window);

			window.display();
		}
	}
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