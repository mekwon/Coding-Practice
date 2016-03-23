#include <iostream>
#include <cstdlib>

using namespace std;

// Create a Fraction class that supports addition, subtraction, multiplication, and division
class Fraction 
{
	private:
		// numerator and denominator
		int n, d; 
	public:
		// constructor
		Fraction() 
		{
			n = 1;
			d = 1;
		}

		Fraction(int numerator, int denominator)
		{
			if (denominator == 0)
			{
				cout << "Cannot divide by 0" << endl;
				exit(0);
			}

			// greatest common divisor
			int gcd;
			for (int i = 1; i <= abs(numerator) && i <= abs(denominator); ++i)
			{
				if (abs(numerator) % i == 0 && abs(denominator) % i == 0)
				{
					gcd = i;
				}
			}
			numerator /= gcd;
			denominator /= gcd;
			
			n = numerator;
			d = denominator;
		}

		Fraction operator+(const Fraction &b)
		{
			int numerator = n * b.d + b.n * d;
			int denominator =  d * b.d;
			return Fraction(numerator, denominator);
		}

		Fraction operator-(const Fraction &b)
		{
			int numerator = n * b.d - b.n * d;
			int denominator = d * b.d;
			return Fraction(numerator, denominator);
		}

		Fraction operator*(const Fraction &b)
		{
			int numerator = n * b.n;
			int denominator = d * b.d;
			return Fraction(numerator, denominator);
		}

		Fraction operator/(const Fraction &b)
		{
			int numerator = n * b.d;
			int denominator = d * b.n;
			return Fraction(numerator, denominator);
		}

		void print() 
		{
			// want to show 2, not 2/1
			if (d == 1)
			{
				cout << n << endl;
			}

			else 
			{
				cout << n << "/" << d << endl;
			}
		}
};