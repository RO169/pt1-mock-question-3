///////////////////////////////////////////////////////////////////////////////////////////////////
//                         COMPUTER METHODS 3 PRACTICAL TEST 1 (MOCK)
// Name: RO169
// Student No: 213 000 000
// Date: 04/2015
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

// ***** QUESTION 3 ******
// Question 3 has 3 parts
// 3.1 Using the MINIMAL "Fraction" class provided, overload the greater than operator to work with
//     objects of class Fraction as a NON-MEMBER FUNCTION.   You may modify the Fraction class to 
//     demonstrate friendship.  DO NOT USE FLOATING POINT MATH!!!
// 3.2 Overload two functions called "add" which take two arguements, an integer and a fraction (in 
//     either order) and return a fraction.  
// 3.3 create a driver program to test your overloaded > operators and your overloaded 

class Fraction 
{
private:
	int num;				// numerator;
	int denom;				// denominator;
public:
	Fraction();
	Fraction(int n, int d) : num(n), denom(d) { };
	void print() { cout << num << "/" << denom; };
	                                        
	bool operator>(Fraction& F);                       //operator overloading
	Fraction add(int, Fraction);                       //Function overloading-Accepting data types
	Fraction add(Fraction, int);                       //in any order
};

bool Fraction::operator>(Fraction& F)
{

}

Fraction Fraction::add(int num1, Fraction F2)
{
	F2.num += num1*F2.denom;
	return F2;
}

Fraction Fraction::add(Fraction F3, int num2)
{
	F3.num += num2*F3.denom;
	return F3;
}