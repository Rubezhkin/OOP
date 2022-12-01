#include "Rational.h"

Rational::Rational():Pair()
{
}

Rational::Rational(int A, int B):Pair(A, B)
{
	reduction();
}

Pair* Rational::sum(Pair* Sec)
{
	Rational* obj = dynamic_cast<Rational*>(Sec);
	a = a * obj->b + obj->a * b;
	b = b * obj->b;
	reduction();
	return Sec;
}

Pair* Rational::sub(Pair* Sec)
{
	Rational* obj = dynamic_cast<Rational*>(Sec);
	a = a * obj->b - obj->a * b;
	b = b * obj->b;
	reduction();
	return Sec;
}

Pair* Rational::mul(Pair* Sec)
{
	Rational* obj = dynamic_cast<Rational*>(Sec);
	a = a * obj->a;
	b = b * obj->b;
	reduction();
	return Sec;
}

Pair* Rational::div(Pair* Sec)
{
	Rational* obj = dynamic_cast<Rational*>(Sec);
	a = a * obj->b;
	b = b * obj->a;
	reduction();
	return Sec;
}

bool Rational::equ(Pair* Sec)
{
	Rational* obj = dynamic_cast<Rational*>(Sec);
	return a * obj->b == obj->a * b;
}

void Rational::reduction()
{
	int n1 = a;
	int n2 = b;
	while (n1 != n2)
	{
		if (n1 > n2)
			n1 -= n2;
		else
			n2 -= n1;
	}
	a /= n1;
	b /= n1;
}

Pair* Rational::inp()
{
	std::cin >> a >> b;
	return this;
}

std::string Rational::print()
{
	return std::to_string(a) + '/' + std::to_string(b) + "\n";
}
