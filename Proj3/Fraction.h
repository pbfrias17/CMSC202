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

/*********
**GCD()
**Calculates the Greatest Common Divisor between the two given integer values
**Pre: None
**Post: None
**	Returns const int of GCD
*********/
const int GCD(int x, int y);

ostream& operator<<(ostream& out, const Fraction& number);
const Fraction operator+(const Fraction& term1, const Fraction& term2);
const Fraction operator-(const Fraction& term1, const Fraction& term2);
const Fraction operator/(const Fraction& term1, const Fraction& term2);
const Fraction operator*(const Fraction& term1, const Fraction& term2);


#endif

