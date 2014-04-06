//fraction.h
#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;

class Fraction {
	
	private:
		int m_whole;
		int m_num;
		int m_den;
		
	public:
		Fraction();
		Fraction(int m_whole, int m_num, int m_den);
		int GetWhole() const;
		int GetNumerator() const;
		int GetDenominator() const;
		void SetWhole(int whole);
		void SetNumerator(int num);
		void SetDenominator(int den);
		void Normalize();
	
};


ostream& operator<<(ostream& out, const Fraction& number);
const Fraction operator+(const Fraction& term1, const Fraction& term2);
const Fraction operator-(const Fraction& term1, const Fraction& term2);
const Fraction operator/(const Fraction& term1, const Fraction& term2);
const Fraction operator*(const Fraction& term1, const Fraction& term2);


#endif

