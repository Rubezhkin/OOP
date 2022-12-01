#include "Complex.h"

Complex::Complex():Pair()
{
}

Complex::Complex(int A, int B):Pair(A, B)
{
}

Pair* Complex::sum(Pair* Sec)
{
    Complex * obj = dynamic_cast<Complex*>(Sec);
    a = a+ obj->a;
    b = b+ obj->b;
    return Sec;
}

Pair* Complex::sub(Pair* Sec)
{
    Complex* obj = dynamic_cast<Complex*>(Sec);
    a = a - obj->a;
    b = b - obj->b;
    return Sec;
}

Pair* Complex::mul(Pair* Sec)
{
    Complex* obj = dynamic_cast<Complex*>(Sec);
    Complex tmp;
    tmp.a = a * obj->a - b * obj->b;
    tmp.b = a*obj->b+b*obj->a;
    a = tmp.a;
    b = tmp.b;
    return Sec;
}

Pair* Complex::div(Pair* Sec)
{
    Complex* obj = dynamic_cast<Complex*>(Sec);
    Complex tmp;
    tmp.a = (a * obj->a + b * obj->b) / (obj->a * obj->a + obj->b * obj->b);
    tmp.b = (b * obj->a + a * obj->b) / (obj->a * obj->a + obj->b * obj->b);
    a = tmp.a;
    b = tmp.b;
    return Sec;
}

bool Complex::equ(Pair* Sec)
{
    Complex* obj = dynamic_cast<Complex*>(Sec);
    return (a == obj->a) && (b == obj->b);
}

std::string Complex::print()
{
    return std::to_string(this->a) + '+' + std::to_string(b) + "i\n";
}

Pair* Complex::inp()
{
    std::cin >> a >> b;
    return this;
}




