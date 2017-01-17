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
	void print() const;
	int re;
	int im;

 protected:
  int re_;
  int im_;
};

#endif

