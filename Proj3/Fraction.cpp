//fraction.cpp
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "Fraction.h"
using namespace std;

Fraction::Fraction() 
: m_whole(0), m_num(0), m_den(1)
{}

Fraction::Fraction(int whole, int num, int den)
: m_whole(whole), m_num(num), m_den(den) {
	if(!m_den) {
		cout << "ERROR: DIVISION BY ZERO IS NOT ALLOWED. \n    OPERATIONS ABORTED... \n";
		exit(0);
	}
}

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
	cout << "Normalizing: " << m_whole << "&" << m_num << "/" << m_den << endl;

	
	cout << endl << "GCD of " << m_num << " and " << m_den << " is.... ";
	int gcd = GCD(m_num, m_den);
	cout << gcd << endl;
	m_num /= gcd;
	m_den /= gcd;

	cout << m_whole << "&" << m_num << "/" << m_den << endl;

	m_whole += floor(m_num / m_den);
	m_num -= m_den * floor(m_num / m_den);

	cout << m_whole << "&" << m_num << "/" << m_den << endl;


	if(m_den < 0) {
		cout << "if 1... \n";
		m_den *= -1;
		m_num *= -1;
		cout << m_whole << "&" << m_num << "/" << m_den << endl;
	}
	if(m_num < 0) {
		cout << "if 2... \n";
		m_num *= -1;
		m_whole *= -1;
		cout << m_whole << "&" << m_num << "/" << m_den << endl;
	}
	if(m_num == 0) {
		cout << "if 3... \n";
		m_den = 1;
		cout << m_whole << "&" << m_num << "/" << m_den << endl;
	}

}

//free functions

const int GCD(int x, int y) {
	cout << "calculating GCD... \n";
	
	if(y > x) {
		int temp;
		temp = y;
		y = x;
		x = temp;
	}

	cout << x << " is bigger than " << y << endl;

	int rem = 1;
	while(rem) {
		cout << "Dividing " << x << " by " << y << endl;
		float quo = floor(x / y);
		rem = x - (quo*y);
		x = y;
		y = rem;
		cout << "quotient is " << quo << endl;
		cout << "remainder is " << rem << endl;

	}

	return x;

}




//operator overloading here

ostream& operator<<(ostream& out, const Fraction& fraction) {

	out << fraction.GetWhole() << "&" << fraction.GetNumerator() << "/" << fraction.GetDenominator();
	return out;
}

const Fraction operator+(const Fraction& term1, const Fraction& term2) {
	Fraction frac1(0, ((term1.GetWhole() * term1.GetDenominator() * term2.GetDenominator()) + (term1.GetNumerator() * term2.GetDenominator())), (term1.GetDenominator() * term2.GetDenominator()));
	Fraction frac2(0, ((term2.GetWhole() * term2.GetDenominator() * term1.GetDenominator()) + (term2.GetNumerator() * term1.GetDenominator())), (term1.GetDenominator() * term2.GetDenominator()));
	
	Fraction result(0, (frac1.GetNumerator() + frac2.GetNumerator()), frac1.GetDenominator());
	result.Normalize();
	
	return result;
}

const Fraction operator-(const Fraction& term1, const Fraction& term2) {
	Fraction frac1(0, ((term1.GetWhole() * term1.GetDenominator() * term2.GetDenominator()) + (term1.GetNumerator() * term2.GetDenominator())), (term1.GetDenominator() * term2.GetDenominator()));
	Fraction frac2(0, ((term2.GetWhole() * term2.GetDenominator() * term1.GetDenominator()) + (term2.GetNumerator() * term1.GetDenominator())), (term1.GetDenominator() * term2.GetDenominator()));
	
	Fraction result(0, (frac1.GetNumerator() - frac2.GetNumerator()), frac1.GetDenominator());
	result.Normalize();
	
	return result;
}

const Fraction operator/(const Fraction& term1, const Fraction& term2) {
	Fraction result;
	result.SetNumerator(((term1.GetWhole() * term1.GetDenominator()) + term1.GetNumerator()) * term2.GetDenominator());
	result.SetDenominator(term1.GetDenominator() * ((term2.GetWhole() * term2.GetDenominator()) + term2.GetNumerator()));
	result.Normalize();
	
	return result;
}

const Fraction operator*(const Fraction& term1, const Fraction& term2) {
	Fraction result;
	result.SetNumerator(((term1.GetWhole() * term1.GetDenominator()) + term1.GetNumerator()) * ((term2.GetWhole() * term2.GetDenominator()) + term2.GetNumerator()));
	result.SetDenominator(term1.GetDenominator() * term2.GetDenominator());
	result.Normalize();
	
	return result;
}

