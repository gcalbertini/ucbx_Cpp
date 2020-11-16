
/* FILENAME: EnglishWeight.cpp
   PROGRAMMER: Guilherme Albertini
   DATE: 6/20/20
   COMPILER: MSVC++ 2019
   REQUIRED: EnglishWeight.h, EW_Driver.cpp
   PURPOSE: Implement the EnglishWeight class*/


#include "EnglishWeight.h"
#include <cmath>

EnglishWeight::EnglishWeight()
{
	oz_ = lb_ = 0;
}


EnglishWeight::~EnglishWeight()
{
}

EnglishWeight EnglishWeight::operator+(EnglishWeight const& w) const
{
	/* recall that ob1 + obj2 = obj1.operator+(obj2)*/
	EnglishWeight sum; //temp obj 
	sum.oz_ = oz_ + w.oz_;
	sum.lb_ = lb_ + w.lb_ + sum.oz_/16;
	sum.oz_ = sum.oz_ % 16;
	return sum;
}

EnglishWeight EnglishWeight::operator-(EnglishWeight const& w) const
{
	/* recall that ob1 - obj2 = obj1.operator-(obj2)*/
	EnglishWeight diff; //temp obj
	int tot1, tot2;
	tot2 = w.oz_ + 16 * w.lb_; 
	tot1 = oz_ + 16 * lb_; 
	diff.oz_ = (tot1 - tot2) % 16;
	diff.lb_ = (tot1 - tot2) / 16;
	return diff;
}

double EnglishWeight::operator/(EnglishWeight const& w) const
{
	/* recall that ob1 / obj2 = obj1.operator/(obj2) and is a scalar value*/
	double div = 1;
	double tot1, tot2;
	//all computation to be converted to oz
	tot1 = (double)lb_ * 16.0 + (double)oz_;
	tot2 = (double)w.lb_ * 16.0 + (double)w.oz_;
	div = tot1 / tot2;
	return div;


}

EnglishWeight EnglishWeight::operator*(long n) const
{   
	/* recall that ob1 * n = obj1.operator*(n)*/
	EnglishWeight tot;
	long totOz = n * lb_ * 16 + oz_ * n;
	tot.lb_ = totOz / 16;
	tot.oz_ = totOz % 16;
	return tot;
}

EnglishWeight EnglishWeight::operator/(double n) const
{
	/* recall that ob1 / n = obj1.operator/(n) which is the same as mult by inverse*/
	EnglishWeight div;
	double totOz = 1/n * ( (double)lb_ * 16 + (double)oz_ );

	double fractpartOz, fractpartLb, intpartOz, intpartLb;
	fractpartOz = modf(totOz, &intpartOz);
	fractpartLb = modf(totOz / 16.0, &intpartLb);

	div.lb_ = (int)intpartLb;
	div.oz_ = (int)(floor(fractpartOz)+16.0 * fractpartLb);
	return div;
	
}

void EnglishWeight::addOz(int oz)
{
	oz_ += oz;
	lb_ += oz_ / 16;
	lb_ %= 16;
}

void EnglishWeight::addLb(int lb)
{
	lb_ += lb;
}

std::ostream& operator<<(std::ostream& os, const EnglishWeight& w)
{
	os << w.lb_ << " pounds, " << w.oz_ << " ounces " << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, EnglishWeight& w)
{
	std::cout << "How many lbs? " << std::endl;
	is >> w.lb_;
	std::cout << "How many oz? " << std::endl;
	is >> w.oz_;
	return is;
}

