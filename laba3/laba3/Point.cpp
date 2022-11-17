#include "Point.h"

Point::Point(float X, float Y)
{
	x = X;
	y = Y;
}

Point::Point()
{
	x = y = 0;
}

float Point::distance(Point a)
{
	return sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y));
}

Point& Point::operator=(Point& a)
{
	x = a.x;
	y = a.y;
	return *this;
}

std::ostream& operator<<(std::ostream& os, Point& a)
{
	os << a.x << ", " << a.y;
	return os;
}

std::istream& operator>>(std::istream& in, Point& a)
{
	in >> a.x >> a.y;
	return in;
}
