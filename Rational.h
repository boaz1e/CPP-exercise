#pragma once
#include "Polynomial.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

class Rational
{
private:
	Polynomial nom;
	Polynomial denom;
public:
	Rational(); // Default Constructor. Sets 0 and 1
	Rational(const Polynomial& p1, const Polynomial& p2); // Constructor
	Rational(const Rational& r); // Copy constructor
	~Rational(); // Destructor

	void print(); // pringting
	Polynomial getNom()const; // returning nom polynom
	Polynomial getDenom() const; // returning denom polynom

	Rational& operator*(const Rational& other)const; // Operator overload "*"
	Rational& operator+(const Rational& other)const; // Operator overload "+"
	Rational& operator=(const Rational& other); // Operator overload "="
	Rational& operator-(const Rational& other)const ; // Operator overload "-"
	friend ostream& operator<<(ostream& out, const Rational& other); // Operator overload "<<"
};

