#include "Pair.h"

Pair::Pair(int A, int B)
{
	a = A;
	b = B;
}

Pair::Pair()
{
	a = b = 0;
}

Pair* Pair::operator+=(Pair& Sec)
{
	a = a + Sec.a;
	b = b + Sec.b;
	return this;
}

Pair* Pair::operator-=(Pair& Sec)
{
	a -= Sec.a;
	b -= Sec.b;
	return this;
}

void Pair::operator*=(double n)
{
	a = a * n;
	b = b * n;
}

std::ostream& operator<<(std::ostream& on, Pair& a)
{
	on << a.a <<  ", " << a.b << '\n';
	return on;
}

std::istream& operator>>(std::istream& is, Pair& a)
{
	is >> a.a >> a.b;
	return is;
}
