// MODULE:		Imperial.h
// PROGRAMMER:	Guilherme Albertini
// LANGUAGE:	C++
// DATE:		20/09/05	
//
// PURPOSE:
//		Header for class conversions.


class Metric; //forward declare so compiler knows to not loop back and forth from header files

#include <iostream>

class Imperial
{
private:
    int furlongs;
    int yards;
    double feet;
public:
    Imperial(void) { furlongs = 0.0; yards = 0; feet = 0.0; };
    Imperial(int fur, int yd, double ft);
    Imperial(Metric& M); //using constructor but may use assignment such as: Imperial &operator=(Metric &M); instead
    int  getFUR(void) { return furlongs; };
    int getYD(void) { return yards; };
    double getFT(void) { return feet; };

    //friend to output data
    friend std::ostream& operator<<(std::ostream& str, Imperial& I);

};
