#include "Rational.h"


Rational::Rational() : nom(0), denom(1) {}

Rational::Rational(const Polynomial& p1, const Polynomial& p2) : nom(p1), denom(p2) {}

void Rational::print() {
	cout << this->getNom();
	cout << "--------------------------" << endl;
	cout << this->getDenom();
}

Polynomial Rational::getNom() const {
	return this->nom;
}

Polynomial Rational::getDenom() const {
	return this->denom;
}

Rational::Rational(const Rational& r) : nom(r.getNom()), denom(r.getDenom()) {}

Rational::~Rational() {}

ostream& operator<<(ostream& out, const Rational& other)
{
	out << "numerator=" << other.getNom();
	out << "--------------------------" << endl;
	out << "denominator=" << other.getDenom();

	return out;
}

Rational& Rational::operator*(const Rational& other) const
{
	Rational* temp = new Rational;

	temp->nom = (this->nom * other.nom);
	temp->denom = (this->denom * other.denom);

	return *temp;
}

Rational& Rational::operator+(const Rational& other) const
{
	Rational* temp = new Rational;
	temp->nom = this->getNom() * other.getDenom() + this->getDenom() * other.getNom();
	temp->denom = this->getDenom() * other.getDenom();

	return *temp;
}

Rational& Rational::operator-(const Rational& other) const
{
	Rational* temp = new Rational;
	temp->nom = this->getNom() * other.getDenom() - this->getDenom() * other.getNom();
	temp->denom = this->getDenom() * other.getDenom();

	return *temp;
}

Rational& Rational::operator=(const Rational& other)
{
	this->nom = other.getNom();
	this->denom = other.getDenom();

	return *this;
}
