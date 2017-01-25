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
complex SqNorm(const complex );
complex SqNorm(const complex );
complex SqDistance(const complex, const complex);


int InnerProduct(const int&,const int&);
int SqNorm(const int&);
int SqDistance(const int&, const int&);


#endif

