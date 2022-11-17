#pragma once
#include <iostream>
class Point
{
	float x, y;
public:
	Point(float X, float Y);
	Point();
	float distance(Point a);
	Point& operator=(Point& a);
	friend std::ostream& operator<<(std::ostream& os, Point& a);
	friend std::istream& operator>>(std::istream& in, Point& a);
};

