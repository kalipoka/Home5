#include <iostream>
#include "complex.H"

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

/*
complex* conj(complex& z)
{
	complex tmp;
	tmp = z;
	tmp.conj;
	return tmp;
}
*/

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


int main()
{
	
	complex A,M,S,CON;
	complex B(1, 2);
	complex C(2, 3);

	A = B + C;
	S = C - B;
	M = B * C;
	CON = conj(M);

	return 0;
}

