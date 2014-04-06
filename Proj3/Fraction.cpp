/***********************************************
** File:     Fraction.cpp
** Project:  CMSC 202 Project 3, Spring 14
** Author:   Paolo Frias
** Due Date: 4/10/14
** Section:  07
** E-mail:   pfrias2@umbc.edu
**
**   This is the implementation of the Fraction class.
**	 It defines mutators, accessors, facilitators and overloaded operations
**	 in order for it to mimic the behavior of mathematical fractions.
**
***********************************************/

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
	if(!den) {
		cout << "INTERNAL ERROR: DIVISION BY ZERO IS NOT ALLOWED \n    OPERATIONS ABORTED... \n";
		exit(0);
	}
	m_den = den;
}

void Fraction::Normalize() {
	int gcd = GCD(m_num, m_den);

	m_num /= gcd;
	m_den /= gcd;

	//Converting from improper fraction to mixed number
	m_whole += (int) floor(m_num / m_den);
	m_num -= m_den * (int) floor(m_num / m_den);

	//Implementing various normalization rules
	if(m_num == 0) {
		m_den = 1;
	}

	if(m_den < 0) {
		m_den *= -1;
		m_num *= -1;
	}

	if(m_whole < 0) {
		if(m_num > 0) {
			m_num *= -1;
		}
	}
}

//free functions

const int GCD(int x, int y) {
	//Swaps parameters so that x > y
	if(y > x) {
		int temp;
		temp = y;
		y = x;
		x = temp;
	}

	//Applies Euclid's method to calculate the GCD
	int rem = 1;
	while(rem) {
		int quo = (int) floor(x / y);
		rem = x - (quo*y);
		x = y;
		y = rem;
	}

	return x;

}




//operator overloading here

ostream& operator<<(ostream& out, const Fraction& fraction) {

	out << fraction.GetWhole() << "&" << fraction.GetNumerator() << "/" << fraction.GetDenominator();
	return out;
}

const Fraction operator+(const Fraction& term1, const Fraction& term2) {
	//Finds least commons denominator, turns into improper fraction and then added
	Fraction frac1(0, ((term1.GetWhole() * term1.GetDenominator() * term2.GetDenominator()) + (term1.GetNumerator() * term2.GetDenominator())), (term1.GetDenominator() * term2.GetDenominator()));
	Fraction frac2(0, ((term2.GetWhole() * term2.GetDenominator() * term1.GetDenominator()) + (term2.GetNumerator() * term1.GetDenominator())), (term1.GetDenominator() * term2.GetDenominator()));
	
	Fraction result(0, (frac1.GetNumerator() + frac2.GetNumerator()), frac1.GetDenominator());
	result.Normalize();
	
	return result;
}

const Fraction operator-(const Fraction& term1, const Fraction& term2) {
	//Finds least commons denominator, turns into improper fraction and then subtracted
	Fraction frac1(0, ((term1.GetWhole() * term1.GetDenominator() * term2.GetDenominator()) + (term1.GetNumerator() * term2.GetDenominator())), (term1.GetDenominator() * term2.GetDenominator()));
	Fraction frac2(0, ((term2.GetWhole() * term2.GetDenominator() * term1.GetDenominator()) + (term2.GetNumerator() * term1.GetDenominator())), (term1.GetDenominator() * term2.GetDenominator()));
	
	Fraction result(0, (frac1.GetNumerator() - frac2.GetNumerator()), frac1.GetDenominator());
	result.Normalize();
	
	return result;
}

const Fraction operator/(const Fraction& term1, const Fraction& term2) {
	//Multiplies by the reciprocal of term2
	Fraction result;
	result.SetNumerator(((term1.GetWhole() * term1.GetDenominator()) + term1.GetNumerator()) * term2.GetDenominator());
	result.SetDenominator(term1.GetDenominator() * ((term2.GetWhole() * term2.GetDenominator()) + term2.GetNumerator()));
	result.Normalize();
	
	return result;
}

const Fraction operator*(const Fraction& term1, const Fraction& term2) {
	//Turned into improper fractions and then mulitplied through
	Fraction result;
	result.SetNumerator(((term1.GetWhole() * term1.GetDenominator()) + term1.GetNumerator()) * ((term2.GetWhole() * term2.GetDenominator()) + term2.GetNumerator()));
	result.SetDenominator(term1.GetDenominator() * term2.GetDenominator());
	result.Normalize();
	
	return result;
}

