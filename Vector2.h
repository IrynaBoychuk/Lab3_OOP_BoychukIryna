#ifndef H_VECTOR2
#define H_VECTOR2

//#include "numeric.h"

#include <iostream>
#include <cmath>

template <typename T>
class Vector2
{
public:
	// Constructors
	Vector2() :x(0), y(0) {}

	Vector2(T _x, T _y) : x(_x), y(_y) {}

	Vector2(const Vector2 &v) : x(v.x), y(v.y) {}

	
	// Operations
	// для цього можна використати??? hypot
	/*T dist2(const Vector2 &v) const
	{
		T dx = x - v.x;
		T dy = y - v.y;
		return dx * dx + dy * dy;
	}

	T dist(const Vector2 &v) const
	{
		return sqrt(dist2(v));
	}

	T norm2() const
	{
		return x * x + y * y;
	}*/
	
	T x;
	T y;

};











#endif