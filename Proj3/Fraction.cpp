//fraction.cpp
#include <iostream>
#include "Fraction.h"
using namespace std;

Fraction::Fraction() 
: m_whole(0), m_num(0), m_den(1)
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
	if(m_den < 0) {
		m_den *= -1;
		m_num *= -1;
	}
	if(m_num < 0) {
		m_num *= -1;
		m_whole *= -1;
	}
	if(m_num == 0) {
		m_den = 0;
	}

}

//free functions
const int GCD(const int& x, const int& y) {
	if(x > y) {
		int big = x;
		int small = y;
	} else {
		int big = y;
		int small = x;
	}

	int rem = 1;
	int count = 0;
	while(rem) {
		while(big >= 0) {
			big -= small;
			count++;
		}
		rem = big - (small*(count-1));
		big = small;
		small = rem;
	}
	
	return rem;

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
	result.Normalize();
	return result;
}

const Fraction operator-(const Fraction& term1, const Fraction& term2) {
	cout << "subtracting " << term1 << " - " << term2 << endl;
	Fraction result;

	result.SetWhole(term1.GetWhole() - term2.GetWhole());
	result.SetDenominator(term1.GetDenominator() * term2.GetDenominator());
	result.SetNumerator((term1.GetNumerator() * term2.GetDenominator()) - (term2.GetNumerator() * term1.GetDenominator()));
	result.Normalize();
	return result;
}

const Fraction operator/(const Fraction& term1, const Fraction& term2) {
	cout << "dividing " << term1 << " / " << term2 << endl;
	Fraction result;

	result.SetNumerator(((term1.GetWhole() * term1.GetDenominator()) + term1.GetNumerator()) * term2.GetDenominator());
	result.SetDenominator(term1.GetDenominator() * ((term2.GetWhole() * term2.GetDenominator()) + term2.GetNumerator()));
	result.Normalize();
	return result;
}

const Fraction operator*(const Fraction& term1, const Fraction& term2) {
	cout << "multiplying " << term1 << " * " << term2 << endl;
	Fraction result;

	result.SetWhole(term1.GetWhole() * term2.GetWhole());
	result.SetNumerator(term1.GetNumerator() * term2.GetNumerator());
	result.SetDenominator(term1.GetDenominator() * term2.GetDenominator());
	result.Normalize();
	return result;
}

