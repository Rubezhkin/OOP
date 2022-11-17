#include "Money.h"

Money::Money()
{
    a = b = 0;
}

Money::Money(int R, int C):Pair( R, C)
{
    normal();
}

Money* Money::operator+=(Money& Sec)
{
    Pair::operator+=(Sec);
    normal();
    return this;
}

Money* Money::operator-=(Money& Sec)
{
    Pair::operator-=(Sec);
    normal();
    return this;
}

void Money::operator/=(double n)
{
    int t = a*100+b;
    t /= n;
    a  = t/100 ;
    b = t%100;
}

bool Money::operator>(Money& Sec)
{
    if ((a>Sec.a)||(a==Sec.a&&b>Sec.b))
        return true;
    return false;
}

bool Money::operator<(Money& Sec)
{
    if ((a < Sec.a) || (a == Sec.a && b < Sec.b))
        return true;
    return false;
}

void Money::normal()
{
    if (b >= 100)
    {
        a += b / 100;
        b = b % 100;
    }
    else if (b < 0)
    {
        b += 100;
        a--;
    }
}

std::ostream& operator<<(std::ostream& on, Money& a)
{
    on << a.a << " рублей " << a.b << "  копеек\n";
    return on;
}

std::istream& operator>>(std::istream& is, Money& a)
{
    is >> a.a >> a.b;
    a.normal();
    return is;
}
