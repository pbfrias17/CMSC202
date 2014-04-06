/***********************************************
** File:     Fraction.h
** Project:  CMSC 202 Project 3, Spring 14
** Author:   Paolo Frias
** Due Date: 4/10/14
** Section:  07
** E-mail:   pfrias2@umbc.edu
**
**   This defines the Fraction class. The class has 3 distinct parts representing
**	 all the components of a mixed number. Arithmetic operations and the output operation
**	 are all overloaded to accept parameters of the Fraction type.
**
***********************************************/

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
		/****************************************************************
		* Name: Fraction
		*   Default (no-arg) constructor
		* Preconditions: None
		* Postconditions:
		*   Creates a mixed number of 0&0/1
		****************************************************************/
		Fraction();

		/****************************************************************
		* Name: Fraction
		*   Standard constructor
		* Preconditions: 
		*	Denominator cannot be Zero
		* Postconditions:
		*   Creates a mixed number given parameter values
		****************************************************************/
		Fraction(int m_whole, int m_num, int m_den);

		/****************************************************************
		* Name: GetWhole
		*   Accessor for m_whole
		* Preconditions: None
		* Postconditions:
		*   Returns m_whole of Fraction object
		****************************************************************/
		int GetWhole() const;

		/****************************************************************
		* Name: GetNumerator
		*   Accessor for m_num
		* Preconditions: None
		* Postconditions:
		*   Returns m_num of Fraction object
		****************************************************************/
		int GetNumerator() const;

		/****************************************************************
		* Name: GetDenominator
		*   Accessor for m_den
		* Preconditions: None
		* Postconditions:
		*   Returns m_den of Fraction object
		****************************************************************/
		int GetDenominator() const;

		/****************************************************************
		* Name: SetWhole
		*   Mutator for m_whole
		* Preconditions: None
		* Postconditions:
		*   m_whole member of Fraction object is set
		****************************************************************/
		void SetWhole(int whole);

		/****************************************************************
		* Name: SetNumerator
		*   Mutator for m_num
		* Preconditions: None
		* Postconditions:
		*   m_num member of Fraction object is set
		****************************************************************/
		void SetNumerator(int num);

		/****************************************************************
		* Name: SetDenominator
		*   Mutator for m_den
		* Preconditions: 
		*	Cannot use Zero as parameter
		* Postconditions:
		*   m_den member of Fraction object is set
		****************************************************************/
		void SetDenominator(int den);

		/****************************************************************
		* Name: Normalize
		*   Converts given Fraction so that it complies with provided
		*	fractional representation standards
		* Preconditions: None
		* Postconditions:
		*   Fraction is now represented in proper mixed number format
		****************************************************************/
		void Normalize();
	
};


// Free Functions

/****************************************************************
* Name: GCD
*   Calculates greatest common divisor between the two 
*	provided integers
* Preconditions:
*	Neither of the parameters can be Zero
* Postconditions:
*   Gives int of GCD
****************************************************************/
const int GCD(int x, int y);


// Operation Overloading

/****************************************************************
* Name: operator<<
*   ostream out overloaded operator
* Preconditions: None
* Postconditions:
*   Displays Fraction object in form: 'm_whole&m_num/m_den'
****************************************************************/
ostream& operator<<(ostream& out, const Fraction& number);

/****************************************************************
* Name: operator+
*   Addition+ overloaded operator
* Preconditions: None
* Postconditions:
*   Returns sum of the two given Fractions. 
*	Sum is in improper form, then normalized
****************************************************************/
const Fraction operator+(const Fraction& term1, const Fraction& term2);

/****************************************************************
* Name: operator-
*   Subtraction- overloaded operator
* Preconditions: None
* Postconditions:
*   Returns difference of the two given Fractions.
*	Difference is in improper form, then normalized
****************************************************************/
const Fraction operator-(const Fraction& term1, const Fraction& term2);

/****************************************************************
* Name: operator/
*   Division/ overloaded operator
* Preconditions: 
*	term2 cannot equal 0&0/0
* Postconditions:
*   Returns result of dividing the two given Fractions.
*	Result is in improper form, then normalized
****************************************************************/
const Fraction operator/(const Fraction& term1, const Fraction& term2);

/****************************************************************
* Name: operator*
*   Multiplication* overloaded operator
* Preconditions: None
* Postconditions:
*   Returns product of the two given Fractions.
*	Product is in improper form, then normalized
****************************************************************/
const Fraction operator*(const Fraction& term1, const Fraction& term2);


#endif

