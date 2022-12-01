#pragma once
#include "Pair.h"
class Complex :public Pair
{
public:
	Complex();
	Complex(int A, int B);
	virtual Pair* sum(Pair* Sec);
	virtual Pair* sub(Pair* Sec);
	virtual Pair* mul(Pair* Sec);
	virtual Pair* div(Pair* Sec);
	virtual bool equ(Pair* Sec);
	virtual std::string print();
	virtual Pair* inp();
};
