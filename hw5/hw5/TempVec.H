#ifndef _TEMPVEC_H
#define _TEMPVEC_H

#include <iostream>
#include "complex.H"

using namespace std;

template <class T,int size>

class TempVec {
 public:
	 TempVec() {}
	 TempVec(const TempVec<T,size>& rhs);
	 TempVec<T, size>& operator=(const TempVec<T, size>& rhs);
	 T& operator[](int i);

 protected:
  T coordinates_[size];
};


// not sure yet how to implement copy const to template $$$$$$$$$$$$$$$$$$$$$
/************************************
Function Name: TempVec - copy constructor
Description: Default Constructor for the TempVec class.
Parameters: TempVec<T,size>& rhs
Return Value: -
*************************************/
template <class T, int size>
TempVec<T, size>::TempVec(const TempVec<T,size>& rhs)
{
	// need to check some legal things
	i = 0;
	while (i < size){
		coordinates_[i] = rhs.coordinates_[i];
		i++;
	}
}


/************************************
Function Name:  operator []
Description: Operator for putting values inside the vector;
Parameters: int i  - the coordinate we want to assing
Return Value: -
*************************************/
// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$4exception not working yet - it still goes to undifined memory
template <class T, int size>
T& TempVec<T, size>::operator[](int i)
{
	if ( i < 0 || i >(size - 1) ) 
	{
		throw("Error TempVec. Illegal index");
	}
	return coordinates_[i];
}


/************************************
Function Name:  operator = 
Description: Default Constructor for the TempVec class.
Parameters: -
Return Value: -
*************************************/
template <class T, int size>
TempVec<T, size>& TempVec<T, size>::operator=(const TempVec<T,size>& rhs)
{
	if (this == &rhs)
		return *this;
	//delete[] coordinates_;
	//coordinates_ = new T[1];
	//T coordinates_[size];
	int i = 0;
	while (i < size)
	{
		coordinates_[i] = rhs.coordinates_[i];
		i++;
	}
}


#endif