#pragma once
#include<string>
#include <iostream>
class Pair
{
protected:
	int a;
	int b;
public:
	Pair() { a = 0; b = 0;};
	Pair(int A, int B) { a = A; b = B; };
	virtual Pair* sum(Pair* Sec)=0;
	virtual Pair* sub(Pair* Sec)=0;
	virtual Pair* mul(Pair* Sec)=0;
	virtual Pair* div(Pair* Sec)=0;
	virtual bool equ(Pair* Sec)=0;
	virtual std::string print()=0;
	virtual Pair* inp() = 0;
};

