#include "Money.h"
#include <iostream>
Money::Money()
{
	rubles = new long;
	*rubles = 0;
	kopecks = new unsigned short;
	*kopecks = 0;
}

Money::Money(const Money& copy)
{
	rubles = new long;
	kopecks = new unsigned short;
	*rubles = *copy.rubles;
	*kopecks = *copy.kopecks;
}

Money::~Money()
{
	delete[] rubles;
	delete[] kopecks;
}

Money Money::operator+(Money& b)
{
	Money tmp;
	*tmp.rubles = (*rubles+*b.rubles + ((*kopecks + *b.kopecks) >= 100));
	*tmp.kopecks = (*kopecks + *b.kopecks) % 100;
	return tmp;
}

Money Money::operator-(Money& b)
{
	Money tmp;
	*tmp.rubles = *rubles - *b.rubles - (*kopecks < *b.kopecks);
	*tmp.kopecks = *kopecks - *b.kopecks + 100 * (*kopecks < *b.kopecks);
	return tmp;
}

Money Money::operator*(double num)
{
	long x;
	x = (*rubles * 100 + *kopecks) * num;
	*rubles = x / 100;
	*kopecks = x % 100;
	return *this;
}
Money Money::operator/(double num)
{
	long x;
	x = (*rubles * 100 + *kopecks) / num;
	*rubles = x / 100;
	*kopecks = x % 100;
	return *this;
}
bool Money::operator<(Money& b)
{
	if ((*rubles < *b.rubles) || ((*rubles == *b.rubles) && (*kopecks < *b.kopecks)))
		return true;
	else return false;
}
bool Money::operator>(Money& b)
{

	if ((*rubles > *b.rubles) || ((*rubles == *b.rubles) && (*kopecks > *b.kopecks)))
		return true;
	else return false;
}
bool Money::operator==(Money& b)
{
	if ((*rubles == *b.rubles) && (*kopecks == *b.kopecks))
		return true;
	else return false;
}
Money& Money::operator=(Money& b)
{
	*rubles = *b.rubles;
	*kopecks = *b.kopecks;
	return *this;
}
std::ostream& operator<<(std::ostream& os, Money& a)
{
	os << *a.rubles << '.' << *a.kopecks << "\n";
	return os;
}

std::istream& operator>>(std::istream& in, Money& a)
{
	in >> *a.rubles >> *a.kopecks;
	return in;
}