#include "Triangle.h"

Triangle::Triangle(Point a, Point b, Point c)
{
	A = a;
	B = b;
	C = c;
}

Triangle::Triangle()
{
	Point a;
	A = a;
	B = a;
	C = a;
}

bool Triangle::check()
{
	double a = B.distance(C);
	double b = A.distance(C);
	double c = A.distance(B);
	return ((a == b + c) || (b == a + c) || (c == a + b));
}

void Triangle::SetA(Point a)
{
	A = a;
}

void Triangle::SetB(Point a)
{
	B = a;
}

void Triangle::SetC(Point a)
{
	C = a;
}

float Triangle::perimeter()
{
	if (check()) return -1;
	float a = B.distance(C);
	float b = A.distance(C);
	float c = A.distance(B);
	return a + b + c;
}

float Triangle::square()
{
	if (check()) return -1;
	float a = B.distance(C);
	float b = A.distance(C);
	float c = A.distance(B);
	float per = (a + b + c) / 2;
	return sqrt(per * (per - a) * (per - b) * (per - c));
}

float Triangle::heightA()
{
	if (check()) return -1;
	float a = B.distance(C);
	float b = A.distance(C);
	float c = A.distance(B);
	float cos = abs((a * a + c * c - b * b) / (2 * a * c));
	float sin = sqrt(1 - cos * cos);
	if (sin < 1e-7)
	{
		cos = abs((a * a + b * b - c * c) / (2 * a * b));
		sin = sqrt(1 - cos * cos);
 		return sin * b;
	}
	return sin * c;
  }

float Triangle::heightB()
{
	if (check()) return -1;
	float a = B.distance(C);
	float b = A.distance(C);
	float c = A.distance(B);
	float cos = abs((b * b + c * c - a * a) / (2 * b * c));
	float sin = sqrt(1 - cos * cos);
	if (sin < 1e-7)
	{
		cos = abs((a * a + b * b - c * c) / (2 * a * b));
		sin = sqrt(1 - cos * cos);
		return sin * a;
	}
	return sin * c;
}

float Triangle::heightC()
{
	if (check()) return -1;
	float a = B.distance(C);
	float b = A.distance(C);
	float c = A.distance(B);
	float cos = abs((b * b + c * c - a * a) / (2 * b * c));
	float sin = sqrt(1 - cos * cos);
	if (sin < 1e-7)
	{
		cos = abs((a * a + c * c - b * b) / (2 * a * c));
		sin = sqrt(1 - cos * cos);
		return sin*
			a;
	}
	return sin * b;
}

std::string Triangle::type()
{
	if (check()) return "неправильно построен";
	float a = B.distance(C);
	float b = A.distance(C);
	float c = A.distance(B);
	float x;
	if (a < b)
	{
		x = a;
		a = b;
		b = x;
	}
	if (a < c)
	{
		x = a;
		a = c;
		c = x;
	}
	if (b < c)
	{
		x = b;
		b = c;
		c = x;
	}

	float e = 1e-5;
	if (a == b && b == c)
		return "равносторонний";
	else if (a == b || b == c)
	{
		if (abs(a * a - b * b - c * c) < e)
			return "прямоугольный и равнобедренный";
		else
			return "равнобедренный";
	}
	if (abs(a * a - b * b - c * c) < e)
		return "прямоугольный";
}

std::ostream& operator<<(std::ostream& os, Triangle& a)
{
	os << "A: " << a.A << "\n";
	os << "B: " << a.B << "\n";
	os << "C: " << a.C << "\n";
	return os;
}

std::istream& operator>>(std::istream& in, Triangle& a)
{
	in >> a.A >> a.B >> a.C;
	return in;
}
