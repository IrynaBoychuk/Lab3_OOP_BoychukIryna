#include<iostream>

using namespace std;

class Point
{
private:
	int **P;       
public:
	int x, y; 
	Point(int a = 0, int b = 0);

	void display()const;    

	Point operator + (Point & point);
	Point operator - (Point & point);
};

int main()
{

	system("pause");
	return 0;
}