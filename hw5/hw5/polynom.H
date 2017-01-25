#ifndef _POLY_F
#define _POLY_F
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <ostream>
#include <cmath>
#include "TempVec.h"


//using namespace std;

// first number is the size of the polynom and then the numbers

class polynom {
private:

public:
	polynom(int n, int* coefs);
	polynom();
	polynom(const polynom& p);
	~polynom();
	int GetOrder() { return this->n_; }
	int* GetCoefs() const; //get a COPY of coefs;
	polynom& operator=(const polynom& p);
	friend polynom operator*(const int i, polynom& a);
	friend polynom operator-(polynom& p, polynom& q);
	friend polynom operator+(polynom& p, polynom& q);
	friend ostream& operator<<(ostream& os, const polynom&);
	friend int InnerProduct(polynom& p, polynom& q);

protected:
	int n_; //number of 
	int* coefs_;
};

polynom operator*(const int i, polynom& a);
polynom operator-(polynom& p, polynom& q);
polynom operator+(polynom& p, polynom& q);
int InnerProduct(polynom& p, polynom& q); // from 1 to 0
int SqNorm(polynom& p);
int SqDistance(polynom& p, polynom& q);



#endif

