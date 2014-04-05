//fraction.cpp
#include <iostream>
#include "Fraction.h"
using namespace std;

Fraction::Fraction() 
: m_whole(0), m_num(1), m_den(2)
{}

Fraction::Fraction(int whole, int num, int den)
: m_whole(whole), m_num(num), m_den(den)
{}

int Fraction::GetWhole() const {
	return m_whole;
}

int Fraction::GetNumerator() const{
	return m_num;
}

int Fraction::GetDenominator() const {
	return m_den;
}

void Fraction::SetWhole(int whole) {
	m_whole = whole;
}

void Fraction::SetNumerator(int num) {
	m_num = num;
}

void Fraction::SetDenominator(int den) {
	m_den = den;
}

void Fraction::Normalize() {




}

void Fraction::GCD() {

}


//operator overloading here

ostream& operator<<(ostream& out, const Fraction& fraction) {
	out << fraction.GetWhole() << "&" << fraction.GetNumerator() << "/" << fraction.GetDenominator();
	return out;
}

const Fraction operator+(const Fraction& term1, const Fraction& term2) {
	Fraction result;
	cout << "adding " << term1 << " + " << term2 << endl;

	result.SetWhole(term1.GetWhole() + term2.GetWhole());
	result.SetDenominator(term1.GetDenominator() * term2.GetDenominator());
	result.SetNumerator((term1.GetNumerator() * term2.GetDenominator()) + (term2.GetNumerator() * term1.GetDenominator()));
	
	return result;
}

const Fraction operator-(const Fraction& term1, const Fraction& term2) {
	cout << "subtracting " << term1 << " - " << term2 << endl;
	Fraction result;

	result.SetWhole(term1.GetWhole() - term2.GetWhole());
	result.SetDenominator(term1.GetDenominator() * term2.GetDenominator());
	result.SetNumerator((term1.GetNumerator() * term2.GetDenominator()) - (term2.GetNumerator() * term1.GetDenominator()));

	return result;
}

const Fraction operator/(const Fraction& term1, const Fraction& term2) {
	cout << "dividing " << term1 << " / " << term2 << endl;
	Fraction result;

	result.SetNumerator(((term1.GetWhole() * term1.GetDenominator()) + term1.GetNumerator()) * term2.GetDenominator());
	result.SetDenominator(term1.GetDenominator() * ((term2.GetWhole() * term2.GetDenominator()) + term2.GetNumerator()));

	return result;
}

const Fraction operator*(const Fraction& term1, const Fraction& term2) {
	cout << "multiplying " << term1 << " * " << term2 << endl;
	Fraction result;

	result.SetWhole(term1.GetWhole() * term2.GetWhole());
	result.SetNumerator(term1.GetNumerator() * term2.GetNumerator());
	result.SetDenominator(term1.GetDenominator() * term2.GetDenominator());

	return result;
}

