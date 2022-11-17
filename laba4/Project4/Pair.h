#pragma once
#include <iostream>
class Pair
{
protected:
	int a, b;
public:
	Pair(int A, int B);
	Pair();
	Pair * operator+=(Pair& Sec);
	Pair* operator-=(Pair& Sec);
	void operator*=(double n);
	friend std::ostream& operator<<(std::ostream& on, Pair& a);
	friend std::istream& operator>>(std::istream& is, Pair& a);
};

