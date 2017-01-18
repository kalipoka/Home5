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

/************************************
Function Name: InnerProduct
Description: return the inner product result
Parameters: complex - x,y
Return Value: complex innerP
*************************************/

complex InnerProduct(complex x,complex y)
{
	complex innerP;
	innerP = x*conj(y);
	return innerP;
}

/************************************
Function Name: SqNorm
Description: returns the square norm
Parameters: complex - x
Return Value: complex squarenorm
*************************************/
complex SqNorm(complex x)
{
	complex Snorm;
	Snorm = x*conj(x);
	return Snorm;
}

/************************************
Function Name: SqDistance;
Description: returns the square distance
Parameters: complex - x,y
Return Value: complex Dist
*************************************/
complex SqDistance(complex x, complex y)
{
	int Dist;
	complex tmp;
	Dist = ((x.re - y.re)*(x.re - y.re) + (x.im - y.im)*(x.im - y.im));
	tmp.re = Dist;
	return tmp;
}

int main()
{
	
	complex A,M,S,CON,Z,L,T, inner;
	complex inner1, SN, SN1;
	complex R, dist;
	complex B(1, 2);
	complex C(2, 3);

	inner1 = InnerProduct(B, C); cout << "Inner P is " << inner1 << "\n";
	SN = SqNorm(B); cout << "norm is " << SN << "\n";
	SN1 = SqNorm(C); cout << "norm 2 is " << SN1 << "\n";
	dist = SqDistance(R, C); cout << "dist is " << dist << "\n";

	
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
	

	return 0;
}

