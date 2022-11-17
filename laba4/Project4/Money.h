#pragma once
#include "Pair.h"
class Money: public Pair
{
public:
	Money();
	Money(int R, int C);
	Money* operator+=(Money& Sec);
	Money* operator-=(Money& Sec);
	void operator/=(double n);
	bool operator>(Money& Sec);
	bool operator<(Money& Sec);
	void normal();
	friend std::ostream& operator<<(std::ostream& on, Money& a);
	friend std::istream& operator>>(std::istream& is, Money& a);
}; 
 
