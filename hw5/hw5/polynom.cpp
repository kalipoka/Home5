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
polynom::polynom()
{
	coefs_ = NULL;
	n_ = 0;
}


/************************************
Function Name: polynom
Description: Copy Constructor for the polynom class.
Parameters: p polynom
Return Value: a new polynom
*************************************/
polynom::polynom(const polynom& p):n_(p.n_) 
{
	coefs_ = new int[n_ + 1];
	for (int i = 0; i < n_ + 1; i++)
		coefs_[i] = p.coefs_[i];
}


/************************************
Function Name: polynom
Description: Default Constructor for the polynom class.
Parameters: int n - oreder of the polynom
int* coefs - the list of coefficients
Return Value: -
*************************************/
polynom::polynom(int n, int* coefs)
{
	coefs_ = NULL;
	if (coefs) {
		coefs_ = new int[n + 1];
		for (int i = 0; i <= n; i++)
			coefs_[i] = coefs[i];
	}
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
	delete[] coefs_;
}




/************************************
Function Name: GetCoefs
Description: Returns a copy of the coefficients list.
Parameters: -
Return Value: coefs - a pointer to the list
*************************************/
int* polynom::GetCoefs() const
{
	if (!coefs_)
		return NULL;

	int* new_coefs = NULL;
	int j = n_ + 1;
	new_coefs = new int[j];

	for (int i = 0; i <= n_; i++)
		new_coefs[i] = coefs_[i];
	return new_coefs;
}

/************************************
Function Name: =
Description: Assign a polynom to a new one
Parameters: const polynom& p -  the polynom to be assigned.
Return Value: The reference to the assigned polynom
*************************************/
polynom& polynom::operator=(const polynom& p)
{
	if (this != &p)
	{
		n_ = p.n_;
		int j = n_ + 1;
		delete[] coefs_;
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
Description: Returns a polynom that is a substruction of two polynoms
Parameters: polynom& p - The first polynom
polynom& q - The second polynom
Return Value: A substructed polynom
*************************************/
polynom operator-(polynom& p, polynom& q)
{
	if (!p.coefs_ || !q.coefs_) {
		polynom r(0, NULL);
		return r;
	}
	int size = 0;
	int* coefs = NULL;

	if (p.GetOrder() > q.GetOrder()) {
		coefs = p.GetCoefs();
		for (int i = 0; i <= q.GetOrder(); i++)
			coefs[i] = coefs[i] - q.coefs_[i];
		size = p.GetOrder();
	}
	else {
		coefs = q.GetCoefs();
		for (int i = 0; i <= p.GetOrder(); i++) //till 
			coefs[i] = -coefs[i] + p.coefs_[i];
		for (int i = p.GetOrder() + 1; i <= q.GetOrder(); i++)
			coefs[i] = -coefs[i];
		size = q.GetOrder();
	}
	polynom r(size, coefs);
	delete[] coefs;
	return r;
}

/************************************
Function Name: +
Description: Returns a polynom that is a sum of two polynoms
Parameters: polynom& p - The first polynom
polynom& q - The second polynom
Return Value: A substructed polynom
*************************************/
polynom operator+(polynom& p, polynom& q)
{
	if (!p.coefs_ || !q.coefs_) {
		polynom r(0, NULL);
		return r;
	}

	int size = 0;
	int* coefs = NULL;

	if (p.GetOrder() > q.GetOrder()) {
		coefs = p.GetCoefs();
		for (int i = 0; i <= q.GetOrder(); i++)
			coefs[i] = coefs[i] + q.coefs_[i];
		size = p.GetOrder();
	}
	else {
		coefs = q.GetCoefs();
		for (int i = 0; i <= p.GetOrder(); i++) //till 
			coefs[i] = coefs[i] + p.coefs_[i];
		size = q.GetOrder();
	}
	polynom r(size, coefs);
	delete[] coefs;
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
	if (!p.coefs_)
		return os;
	
	int i = p.n_, flag=0;
	for (; 2 <= i; i--)
	{
		if (p.coefs_[i] != 0)
		{
			if (p.coefs_[i] == 1) {
				os << "x^" << i;
				flag = 1;
			}
			else if (p.coefs_[i] == -1){
				os << "x^"  <<i;
				flag = 1;
			}
			else{
				os << p.coefs_[i] << "x^" << i;
				flag = 1;
			}
			int j = i-1;
			while (j >= 0) {
				if (p.coefs_[j] != 0)
				{
					if (p.coefs_[j] > 0)
						os << "+";
					break;
				}
				j--;
			}
		}
	}

	if (i == 1) {
		if (p.coefs_[1] != 0)
		{
			if (p.coefs_[1] != 1 && p.coefs_[1] != -1){
				os << p.coefs_[i] << "x";
				flag = 1;
			}
			else
				if (p.coefs_[i] == -1){
					os << "-x";
					flag = 1;
				}
				else{
					os << "x";
					flag = 1;
				}
			if (p.coefs_[0] > 0)
				os << "+";
		}
		i--;
	}
	if (i == 0)
		if (p.coefs_[0] != 0) {
			if (p.coefs_[0] > 0)
				os << p.coefs_[0];
			else
				os << "-" << abs(p.coefs_[0]);
		}
		else{
			if (flag ==0)
				os << "0";
		}

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

	float calc = .0;
	for (int i = p.GetOrder(); 0 <= i; i--)
		for (int j = q.GetOrder(); 0 <= j; j--) {
			calc = calc + (static_cast<float>(p.coefs_[i]) * static_cast<float>(q.coefs_[j])) / (i + j + 1);
		}
	return static_cast<int>(calc);
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
	if (p.GetOrder() > q.GetOrder()) {
		polynom j = p - q;
		return  static_cast<int>(SqNorm(j));
	}
	else {
		polynom j = q - p;
		return  static_cast<int>(SqNorm(j));
	}
}



/*
int main()
{
int* coefs1;
coefs1 = new int[3]{ 1,8,1};// ({ a0, a1, a2 });
polynom p1(2, coefs1);

int* coefs2;
coefs2 = new int[4]{-1,0,0,50};// ({ 1, 1, 1 });
polynom p2(3, coefs2);

int* coefs3;
coefs3 = new int[3]{ 1,8,1 };// ({ a0, a1, a2 });
polynom p3(2, coefs3);

int* coefs4;
coefs4 = new int[4]{ -1,0,0,50 };// ({ 1, 1, 1 });
polynom p4(3, coefs4);



TempVec<polynom, 2> v1;
TempVec<polynom, 2> v2;
TempVec<polynom, 2> v3;
TempVec<polynom, 2> v4;

v1[0] = p1;
v1[1] = p2;
v2[0] = p3;
v2[1] = p4;


v3[1] = v2[0];
v3[0] = v2[1];

//v4 = v1 + v2;


cout <<v1 << "\n";

return 0;
}
*/