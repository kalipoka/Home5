#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <iostream>

using std::ostream;
using std::cout;


class complex  {

public:
	complex();
	~complex();
	complex(int re, int im);
	
	friend ostream& operator<<(ostream& os, const complex& c);
	void print() const;  // probalby not necesry
	int re;
	int im;

 protected:
 // int re_;
//  int im_;
};

complex conj(complex x);
complex InnerProduct(complex , complex);
ostream& operator<<(ostream&, const complex& );
complex operator+(const complex& , const complex& );
complex operator-(const complex& , const complex& );
complex operator*(const complex&, const complex&);
complex SqNorm(complex );
complex SqNorm(complex );
complex SqDistance(complex, complex);


int InnerProduct(int, int);
int SqNorm(int);
int SqDistance(int,int);


#endif

