#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <iostream>

class complex  {

public:
	complex();
	complex(int re, int im);
	complex conj(complex z);
	int re;
	int im;

 protected:
  int re_;
  int im_;
};

#endif

