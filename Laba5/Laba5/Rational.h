#pragma once
#include "Pair.h"
class Rational:public Pair
{
public:
	Rational();
	Rational(int A, int B);
	virtual Pair* sum(Pair* Sec);
	virtual Pair* sub(Pair* Sec);
	virtual Pair* mul(Pair* Sec);
	virtual Pair* div(Pair* Sec);
	virtual bool equ(Pair* Sec);
	void reduction();
	virtual std::string print();
	virtual Pair* inp();
};


