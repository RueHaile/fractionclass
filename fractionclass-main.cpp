/**
Fraction class example is written to show simple use of a C++ class
with
- constructor (aka initializer),
- and operator overloading
*/

#include <iostream>
using namespace std;

//function to find the greatest common divisor
int gcd(int m, int n) {
	while (m % n != 0) {
		int oldm = m;
		int oldn = n;

		m = oldn;
		n = oldm % oldn;
	}
	return n;
}

//class definition
class Fraction {
public:

	//default constructor
	Fraction(int top = 0, int bottom = 1) {
		num = top;
		den = bottom;
	}

	//overload the << operator: see definition below class
	friend ostream& operator<<(ostream& stream, const Fraction& frac);

	//overload the == operator: see definition below class
	friend bool operator ==(const Fraction& frac1, const Fraction& frac2);

	//overload the + operator: see definition below class
	friend Fraction operator +(const Fraction& frac1, const Fraction& frac2);

private:
	int num, den;
}; //the ; is required here at the end of the class definition

//define the overloading of the + operator
Fraction operator +(const Fraction& frac1, const Fraction& frac2) {
	int newnum = frac1.num * frac2.den + frac1.den * frac2.num;
	int newden = frac1.den * frac2.den;
	int common = gcd(newnum, newden);
	return Fraction(newnum / common, newden / common);
}

//define the overloading of the == operator
bool operator ==(const Fraction& frac1, const Fraction& frac2) {
	return  (frac1.num == frac2.num && frac1.den == frac2.den);
}

//define the overloading of the << operator
ostream& operator<<(ostream& stream, const Fraction& frac) {
	stream << frac.num/frac.common << "/" << frac.den/frac.common;
	return stream;
}

int main() {
	char enterme;
	int numerator, denominator;

	cout << "Demo use of the constructor & operator overloading." << endl;

	Fraction f0; //uses default constructor
	cout << "f0 = " << f0 << endl;

	Fraction f1(2); //uses default constructor
	cout << "f1 = " << f1 << endl;

	Fraction f2(1, 4); //uses default constructor
	cout << "f2 = " << f2 << endl;

	Fraction f3 = f0 + f2; //uses overloaded + operator
	cout << "f3 is f0 + f2 = " << f3 << endl;

	Fraction f4 = f2 + f2; //uses overloaded + operator
	cout << "f4 is f2 + f2 = " << f4 << endl;

	cout << "Enter numerator: ";
	cin >> numerator;
	cout << "Enter demoninator: ";
	cin >> denominator;
	Fraction f5(numerator, denominator); //uses default constructor
	cout << "You entered = " << f5 << endl;

	cin >> enterme; //holds console open in some situations
	return 0;
}
