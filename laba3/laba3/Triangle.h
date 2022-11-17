#pragma once
#include "Point.h"
#include <iostream>
#include <cmath>
class Triangle
{
	Point A, B, C;
public:
	Triangle(Point a, Point b, Point c);
	Triangle();
	bool check();
	void SetA(Point a);
	void SetB(Point a);
	void SetC(Point a);
	float perimeter();
	float square();
	float heightA();
	float heightB();
	float heightC();
	std::string type();
	friend std::ostream& operator<<(std::ostream& os, Triangle& a);
	friend std::istream& operator>>(std::istream& in, Triangle& a);
};

