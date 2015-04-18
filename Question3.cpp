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
	Fraction(){};
	Fraction(int n, int d) { num = n; denom = d; };
	void print() { cout << num << "/" << denom; };
	                                        
	bool operator>(Fraction& F);                       //operator overloading
	
	static Fraction add(int num1, Fraction F2)
	{
		F2.num += num1*F2.denom;
		return F2;
	}

	static Fraction add(Fraction F3, int num2)
	{
		F3.num += num2*F3.denom;
		return F3;
	}
};

bool Fraction::operator>(Fraction& F)
{
	Fraction Fa, Fb;                                          //Copy original fractions into new addresses
	Fa.num = num; Fa.denom = denom;                           //this way we don't alter the way the
	Fb.num = F.num; Fb.denom = F.denom;                       //original fractions look when comparing
	
	if (Fa.denom != Fb.denom)                                 //we can only compare the numerators if
	{                                                         //the denominators are the same
		Fa.num *= Fb.denom;                                   //therefore establish a common denominator
		Fb.num *= Fa.denom;                                   //then compare the numerators
		Fa.denom *= Fb.denom;
		Fb.denom = Fa.denom;
	}

	if (Fa.num > Fb.num)                                 
		return true;
	else
		return false;
}



int main()
{
	Fraction F1(1, 7);
	Fraction F2(5, 9);
	Fraction ans1, ans2;
	int num1 = 5;
	
	ans1 = Fraction::add(F1, num1);
	cout << "Addition with fraction First = ";
	ans1.print();
	ans2 = Fraction::add(num1, F1);
	cout << "\n\nAddition with integer First = ";
	ans2.print();

	if (F1 > F2)
	{
		cout << "\n\n";
		F1.print();
		cout << " is greater than ";
		F2.print();
	}
	else
	{
		cout << "\n\n";
		F2.print();
		cout << " is greater than ";
		F1.print();
	}

	cout << "\n\n\n";

	system("Pause");
	return 0;
}