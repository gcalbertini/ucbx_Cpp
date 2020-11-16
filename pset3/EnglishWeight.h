/* FILENAME: EnglishWeight.h
   PROGRAMMER: Guilherme Albertini
   DATE: 6/20/20
   COMPILER: MSVC++ 2019
   REQUIRED: EnglishWeight.cpp, EW_Driver.cpp
   PURPOSE: Define the EnglishWeight class*/

#ifndef ENGLISH_WEIGHT_
#define ENGLISH_WEIGHT_

#include <iostream>
#include <string>

class EnglishWeight
{
private:
	int oz_;
	int lb_;
public:
	EnglishWeight(); //default constructor
	~EnglishWeight();

	//operator overloading
	EnglishWeight operator+(EnglishWeight const& w) const; //second implicit (as method, const member function) const as we are not modifying the invoking object
	EnglishWeight operator-(EnglishWeight const& w) const;
	EnglishWeight operator*(long n) const;
	EnglishWeight operator/(double n) const;
	double operator/(EnglishWeight const& w) const;


	//member function
	void addOz(int oz);
	void addLb(int lb);


	//friend function in case "# * obj" calculation is attempted in that order
	friend EnglishWeight operator*(int n, const EnglishWeight& w)
	{
		return w * n;
	} // inline definition

	friend std::ostream& operator<<(std::ostream &os, const EnglishWeight& w); 

	// note that parameter w must be non-const so we can modify the class members with the input values
	friend std::istream& operator>>(std::istream& is, EnglishWeight& w);

};
#endif