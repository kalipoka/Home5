#ifndef _TEMPVEC_H
#define _TEMPVEC_H

#include <iostream>

using namespace std;

template <class T,int size>
class TempVec {
 public:
	TempVec() {};
	TempVec& operator=();
	T& operator[]();
	T operator+();
	T operator-(TempVec& a, TempVec& b);
	friend operator*(); //scalar multiply
	osstream& operator<<(osstream& os, os);









 protected:
  T coordinates_[size];
};


#endif
