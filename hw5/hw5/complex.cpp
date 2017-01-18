#include <iostream>
#include "complex.H"

using std::cout;

/************************************
Function Name: complex
Description: Default Constructor for the complex class.
Parameters: -
Return Value: -
*************************************/
complex::complex()
{
	re_ = 0;
	im_ = 0;
	re = 0;
	im = 0;
}

/************************************
Function Name: ~complex
Description: Default Destructor for the complex class.
Parameters: -
Return Value: -
*************************************/

complex::~complex() {
	
}

/************************************
Function Name: complex
Description: Constructor for the complex class. 
Parameters: int re - real part of the number
int im - imaginary part of the number
Return Value: -
*************************************/
complex::complex(int re, int im) :re_(re), im_(im),re(re),im(im) {}

/************************************
Function Name: conj
Description: return conjugate numbers
Parameters: complex - z
Return Value: conjugate comlplex number
*************************************/

complex conj(complex z)
{
	complex tmp;
	tmp = z;
	tmp.im = z.im*(-1);
	return tmp;
}

/************************************
Function Name: +
Description: return the sum of 2 complex numbers
Parameters: complex - c1,c2
Return Value: c
*************************************/

complex operator+(const complex& c1, const complex& c2)
{
	complex c(c1.re + c2.re, c1.im + c2.im);
	return c;
}
/************************************
Function Name: -
Description: return the substraction of 2 complex numbers
Parameters: complex - c1,c2
Return Value: c
*************************************/
complex operator-(const complex& c1, const complex& c2)
{
	complex c(c1.re - c2.re, c1.im - c2.im);
	return c;
}
/************************************
Function Name: *
Description: return the multiplication of 2 complex numbers
Parameters: complex - c1,c2
Return Value: c
*************************************/
complex operator*(const complex& c1, const complex& c2)
{
	complex c((c1.re*c2.re) - (c1.im*c2.im) , (c1.re*c2.im) + (c1.im*c2.re ));
	return c;
}
/************************************
Function Name: <<
Description: print operator for complex number
Parameters: ostream& os, const complex& c
Return Value: ostream& os
*************************************/
ostream& operator<<(ostream& os, const complex& c)
{
	if (c.im == 0 && c.re == 0)
		return os << "0";
	if (c.im == 0)
		return os << c.re;
	if ( c.re == 0 )
	{
		if (c.im == 1)
		{
			return os << "i";
		}
		if (c.im == -1)
		{
			return os << "-i";
		}
		if ( c.im > 0)
		{
			return os << "+" << c.im << "i"; 
		}
		else
		{
			return os << c.im << "i"; 
		}
	}
	else
	{
		if (c.im == 1)
		{
			return os<< c.re << "+i";
		}
		if (c.im == -1)
		{
			return os << c.re <<"-i"; 
		}
		if (c.im > 0)
		{
			return os << c.re << "+" <<c.im << "i";
		}

		else
		{
			return os << c.re << c.im << "i";
		}
	}
}
/************************************
Function Name: print
Description: prints the complex number
Parameters: -
Return Value: -
*************************************/
void complex::print() const
{
	if ((re == 0) && (im == 0))
	{
		cout << "0"; return;
	}
	if (im == 0)
	{
		cout << re; return;
	}
	if (re == 0)
	{
		if (im == 1)
		{
			cout << "i"; return;
		}
		if (im == -1)
		{
			cout << "-i"; return;
		}
		if (im > 0)
		{
			cout << "+" << im << "i"; return;
		}
		else
		{
			cout << im << "i"; return;
		}
	}
	else
	{
		cout << re;
		if (im == 1)
		{
			cout << "+i";
		}
		if (im == -1)
		{
			cout << "-i"; return;
		}
		if (im > 0)
		{
			cout << "+" << im << "i"; return;
		}

		else
		{
			cout << im << "i"; return;
		}
	}
}

int main()
{
	
	complex A,M,S,CON,Z,L,T;
	complex B(1, 2);
	complex C(2, 3);

	L.re = 5;
	T.im = -1;

	A = B + C;
	S = C - B;
	M = B * C;
	CON = conj(M);

	A.print(); cout << "\n";
	M.print(); cout << "\n";
	CON.print(); cout << "\n";
	Z.print(); cout << "\n";
	L.print(); cout << "\n";
	T.print(); cout << "\n";
	cout << "tryin from here";
	cout << A;  cout << "\n";
	cout << M; cout << "\n";
	cout << CON; cout << "\n";
	cout << Z; cout << "\n";
	cout << L; cout << "\n";
	cout << T; cout << "\n";

//	cout << "z is " << A;

	return 0;
}

