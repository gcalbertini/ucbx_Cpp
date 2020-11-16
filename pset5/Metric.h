// MODULE:		Metric.h
// PROGRAMMER:	Guilherme Albertini
// LANGUAGE:	C++
// DATE:		20/09/05	
//
// PURPOSE:
//		Header for class conversions.


#include "Imperial.h"
#include <iostream>

class Metric
{
private:
    int kilometers;
    double meters;
public:
    Metric(void) { kilometers = 0; meters = 0.0; };
    Metric(int km, double m);
    Metric(Imperial& I);//using constructor but may use assignment such as: Metric &operator=(Imperial &I); instead
    int  getKM(void) { return kilometers; };
    double getM(void) { return meters; };

    //friend to output data
    friend std::ostream& operator<<(std::ostream& str, Metric& M);
};
