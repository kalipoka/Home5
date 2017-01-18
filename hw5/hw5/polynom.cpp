#include "polynom.h"
#include <string>
#include <iostream>



/************************************
Function Name: polynom
Description: Default Constructor for the polynom class.
Parameters: int n - oreder of the polynom
int* coefs - the list of coefficients
Return Value: -
*************************************/
polynom::polynom(int n, int* coefs)
{
	coefs_ = coefs;
	n_ = n;
}

/************************************
Function Name: ~polynom
Description: Default Destructor for the polynom class.
Parameters: -
Return Value: -
*************************************/
polynom::~polynom()
{
	delete[n_-1] coefs_;
}

/************************************
Function Name: polynom
Description: Copy Constructor for the polynom class.
Parameters: int re - real part of the number
int im - imaginary part of the number
Return Value: -
*************************************/
polynom::polynom(const polynom& p)
	:n_(p.n_), coefs_(p.GetCoefs()) {}


/************************************
Function Name: GetCoefs
Description: Returns a copy of the coefficients list.
Parameters: - 
Return Value: coefs - a pointer to the list
*************************************/
int* polynom::GetCoefs() const 
{
	int* coefs;
	if (!coefs_)
		return NULL;
	coefs = new int[n_+ 1];
	for (int i = 0; i <= n_; i++)
		coefs[i] = coefs_[i];
	return coefs;
}

/************************************
Function Name: =
Description: Assign a polynom to a new one
Parameters: const polynom& p -  the polynom to be assigned.
Return Value: The reference to the assigned polynom
*************************************/
polynom& polynom::operator=(const polynom& p)
{
	if (this != &p);
	{
		n_ = p.n_;
		if (coefs_) delete[] coefs_;
		coefs_ = p.GetCoefs();
	}
	return *this;
}

/************************************
Function Name: *
Description: Returns a polynom that is multiplied by scalar value.
Parameters: const int j - the scalar value
polynom& p - the polynom to be multiplied.
Return Value: A multiplied polynom
*************************************/
polynom operator*(const int j, polynom& p)
{
	polynom	q = p;
	for (int i = 0; i <= q.GetOrder(); i++)
		q.coefs_[i] = j*(q.coefs_[i]);
	return q;
}

/************************************
Function Name: -
Description: Returns a polynom that is substructed by two polynoms
Parameters: polynom& p - The first polynom
polynom& q - The second polynom
Return Value: A substructed polynom
*************************************/
polynom operator-(polynom& p, polynom& q)
{
	int* coefs = p.GetCoefs(); //we need plus one for the free variable
	for (int i = 0; i <= q.GetOrder(); i++)
		coefs[i] = coefs[i] - q.coefs_[i];

	polynom r(p.GetOrder(), coefs);
	return r;
}

/************************************
Function Name: <<
Description: Returns a fixed output to a provided stream.
Parameters: ostream& os - the stream
const polynom& p - the polynom to be presented
Return Value: the stream so can be concatenate to other stream.
*************************************/
ostream& operator<<(ostream& os, const polynom& p)
{
	string s = "";
	int i = p.n_;
	//if (p.coefs_) return os;
	for (; 2 <= i; i--)
	{
		s = s + to_string(p.coefs_[i]) + "x^" + to_string(i);
		if (p.coefs_[i-1] >= 0)
			s = s + "+";
	}

	if (i == 1) {
		s = s + to_string(p.coefs_[i]) + "x";
		if (p.coefs_[i - 1] >= 0)
			s = s + "+";
		i--;
	}
	s = s + to_string(p.coefs_[i]);

	os << s;
	return os;
}

/************************************
Function Name: InnerProduct
Description: Returns a Inner-Product of two polynoms
Parameters: polynom& p - The first polynom
polynom& q - The second polynom
Return Value: An integer with the result
*************************************/
int InnerProduct(polynom& p, polynom& q)
{
	float calc=.0;
	for (int i = p.GetOrder(); 0 <= i; i--)
		for (int j = q.GetOrder(); 0 <= j; j--) {
			calc = calc + (static_cast<float>(p.coefs_[i]) * static_cast<float>(q.coefs_[j])) / (i + j + 1);
			cout << calc << "\n"; 
		}
	return calc;
}

/************************************
Function Name: SqNorm
Description: Returns a Square-Normal of a polynom.
Parameters: polynom& p - The polynom
Return Value: An integer with the result
*************************************/
int SqNorm(polynom& p)
{
	return InnerProduct(p, p);
}

/************************************
Function Name: InnerProduct
Description: Returns the Distance between two polynoms
Parameters: polynom& p - The first polynom
polynom& q - The second polynom
Return Value: An integer with the result
*************************************/
int SqDistance(polynom& p, polynom& q)
{
	if (p.GetOrder() > q.GetOrder())
		return sqrt(SqNorm(p - q));
	else
		return sqrt(SqNorm(q - p));
}

/*
int main()
{
	int* coefs;
	coefs = new int[3]{ 1,8,1};// ({ a0, a1, a2 });
	polynom q(2, coefs);

	int* coefs2;
	coefs2 = new int[4]{-1,0,0,50};// ({ 1, 1, 1 });
	polynom p(3, coefs2);
	//polynom p = q;

	//cout << q-p << "\n";
	//cout << -2*p << "\n";		

	//
	//int* coefs1;
	//coefs = new int[6];
	//coefs1 = q.GetCoefs();
	//for (int i = 0; i != 6; i++)
	//	cout << coefs1[i] << " ";
	//


	cout << SqDistance(p,q) << "\n";

	return 0;
}
*/