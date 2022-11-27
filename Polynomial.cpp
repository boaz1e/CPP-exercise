#include "Polynomial.h"

int Polynomial::staticMaxDegree = 0;

Polynomial::Polynomial(int _degree) {
	this->setDegree(_degree);
	this->coeff_arr = new double[this->getDegree()];
	if (this->coeff_arr == NULL)
		return;
	for (int i = 0; i < _degree; i++)
		this->coeff_arr[i] = 0;
}

void Polynomial::setDegree(int degree) {
	this->maxDegree = degree;
}

Polynomial::Polynomial(const Polynomial& p1) {
	this->setDegree(p1.getDegree());
	this->coeff_arr = new double[this->getDegree()];
	if (this->coeff_arr == NULL)
		return;
	for (int i = 0; i < this->getDegree(); i++)
		this->coeff_arr[i] = p1.coeff_arr[i];
}

Polynomial::Polynomial() {
	this->maxDegree = 0;
}

Polynomial::Polynomial(double* c_arr, int _maxDegree) {
	this->setDegree(_maxDegree + 1);
	this->coeff_arr = new double[this->getDegree()];
	if (this->coeff_arr == NULL)
		exit(1);
	for (int i = 0; i < _maxDegree + 1; i++)
		this->coeff_arr[i] = c_arr[i];
}

Polynomial::~Polynomial() {
	delete[]this->coeff_arr;
	this->coeff_arr = NULL;
}

int Polynomial::getMaxDegree() {
	return staticMaxDegree;
}

ostream& operator<<(ostream& out, const Polynomial& other)
{
	int flag = -1;
	out << "Polynomial = ";
	if (other.getDegree() == 1)
		out << other.getDegree() << endl;
	else if (other.getDegree() == 0)
		out << other.getDegree() << endl;
	else
	{
		for (int i = 0; i < other.getDegree(); i++)
			if (other.coeff_arr[i] != 0)
				flag = i;
		if (flag != -1)
		{
			out << other.coeff_arr[0];
			for (int i = 1; i <= flag; i++)
			{
				out << "+" << "(" << other.coeff_arr[i] << ")" << "*X^" << i;
			}
			out << endl;
			if (flag > other.getMaxDegree())
				Polynomial::staticMaxDegree = flag;
		}
		else
		{
			out << "0" << endl;
		}
	}
	return out;
}

int Polynomial::getDegree(bool _b) const {
	if (_b == true)
	{
		int flag = 0;
		for (int i = 0; i < this->getDegree(); i++)
			if (this->coeff_arr[i] != 0)
				flag = i;
		return flag;
	}
	else
		return this->maxDegree;
}

void Polynomial::setCoeff(int _degree, double coefficient) {
	this->coeff_arr[_degree] = coefficient;
}

double Polynomial::getCoeff(const int index) const {
	return this->coeff_arr[index];
}

Polynomial& operator*(double num, const Polynomial& other)
{
	int i;
	Polynomial* temp = new Polynomial(other);
	for (i = 0; i <= other.getDegree(true); i++)
		temp->coeff_arr[i] *= num;

	return *temp;
}

Polynomial& operator+(double num, Polynomial& other)
{
	Polynomial* temp = new Polynomial(other);
	for (int i = 0; i < other.getDegree(true); i++)
		other.coeff_arr[i] += num;

	return other;
}

Polynomial& Polynomial::operator+(Polynomial& other)
{
	int i;
	Polynomial* temp;
	if (this->getDegree(true) == 0)
		return other;
	if (other.getDegree(true) == 0)
		return *this;

	if (this->getDegree(true) > other.getDegree(true))
		temp = new Polynomial(*this);
	else
		temp = new Polynomial(other);

	if (this->getDegree(true) > other.getDegree(true))
	{
		for (i = 0; i <= other.getDegree(true); i++)
			temp->coeff_arr[i] = this->coeff_arr[i] + other.coeff_arr[i];
	}
	else
	{
		for (i = 0; i <= this->getDegree(true); i++)
			temp->coeff_arr[i] = this->coeff_arr[i] + other.coeff_arr[i];
	}
	return *temp;
}

Polynomial& Polynomial::operator-(Polynomial& other)
{
	int i;
	Polynomial* temp;

	if (other.getDegree(true) == 0)
		return *this;
	if (this->getDegree(true) == 0)
		return (-1) * other;

	if (this->getDegree(true) > other.getDegree(true))
		temp = new Polynomial(*this);
	else
		temp = new Polynomial(other);

	if (this->getDegree(true) > other.getDegree(true))
	{
		for (i = 0; i <= other.getDegree(true); i++)
			temp->coeff_arr[i] = this->coeff_arr[i] - other.coeff_arr[i];
	}
	else
	{
		for (i = 0; i <= this->getDegree(true); i++)
			temp->coeff_arr[i] = this->coeff_arr[i] - other.coeff_arr[i];
	}
	return *temp;
}

double& Polynomial::operator[](int index) const
{
	return this->coeff_arr[index];
}

double& Polynomial::operator[](int index)
{
	return this->coeff_arr[index];
}

Polynomial& Polynomial::operator*(const Polynomial& other) const
{
	Polynomial* temp = new Polynomial(*this);
	int tempMaxDegree = temp->getDegree(true) + other.getDegree(true);
	double* arr = new double[tempMaxDegree + 1];
	if (arr == NULL)
		exit(1);
	for (int i = 0; i < tempMaxDegree + 1; i++)
		arr[i] = 0;
	for (int i = 0; i <= temp->getDegree(true); i++)
	{
		if (this->coeff_arr[i] != 0)
		{
			for (int j = 0; j <= other.getDegree(true); j++)
			{
				if (other.coeff_arr[j] != 0)
				{
					arr[i + j] += temp->coeff_arr[i] * other.coeff_arr[j];
				}
			}
		}
	}
	temp->coeff_arr = new double[tempMaxDegree + 1];
	if (temp == NULL)
		exit(1);
	for (int i = 0; i < tempMaxDegree + 1; i++)
		temp->coeff_arr[i] = arr[i];
	temp->maxDegree = tempMaxDegree + 1;
	delete[] arr;
	arr = NULL;
	return *temp;
}


Polynomial& Polynomial::operator=(const Polynomial& other)
{
	this->setDegree(other.getDegree());
	this->coeff_arr = new double[this->getDegree()];
	if (this->coeff_arr == NULL)
		exit(1);
	for (int i = 0; i < this->getDegree(); i++)
		this->coeff_arr[i] = other.coeff_arr[i];

	if (other.getDegree(true) > staticMaxDegree)
		staticMaxDegree = other.getDegree(true);

	return *this;
}