#pragma once
#include <iostream>
#include <cmath>
class Money
{
	long* rubles;
	unsigned short* kopecks;
public:
	Money();
	Money(const Money& copy);
	~Money();
	Money operator+(Money& b);
	Money operator-(Money& b);
	Money operator*(double num);
	Money operator/(double num);
	bool operator<(Money& b);
	bool operator>(Money& b);
	bool operator==(Money& b);
	Money& operator=(Money& b);
	friend std::ostream& operator<<(std::ostream& os, Money& a);
	friend std::istream& operator>>(std::istream& in, Money& a);
};