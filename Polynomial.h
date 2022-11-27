#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

class Polynomial
{
private:
	int maxDegree;
	double* coeff_arr = NULL;
	static int staticMaxDegree;
public:

	Polynomial(int _degree); // Constructor
	Polynomial(); // Constructor
	Polynomial(double* c_arr, int _maxDegree); // Constructor
	Polynomial(const Polynomial& p1); // Copy Constructor
	~Polynomial(); // Destructor. free the allocated Coefficients Array

	static int getMaxDegree(); // return the max degree
	void setDegree(int degree);
	int getDegree(bool _b = false) const; // return polynomial's degree
	void setCoeff(int _degree, double coefficient); // setting degree and coefficient
	double getCoeff(const int index) const; // getting specific degree's coefficient

	friend ostream& operator<<(ostream& out, const Polynomial& other); // Operator overloading printing object
	friend Polynomial& operator*(double num, const Polynomial& other); // Operator overloading printing object
	Polynomial& operator+(Polynomial& other); // Operator overloading "+" between objects
	Polynomial& operator-(Polynomial& other); // Operator overloading "-" between objects
	Polynomial& operator*(const Polynomial& other) const; // Operator overloading "*" between objects
	double& operator[](int index) const; // Operator "[]"
	double& operator[](int index);  // Operator "[]"
	
	friend Polynomial& operator+(double num,Polynomial& other); // Operator overload "+" between num and object
	Polynomial& operator=(const Polynomial& other); // Operator overloading "=" between objects

};

