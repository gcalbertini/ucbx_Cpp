// MODULE:		Distance.cpp
// PROGRAMMER:	Guilherme Albertini
// LANGUAGE:	C++
// DATE:		20/09/05	
//
// PURPOSE:
//		Driver for class conversions.

#include <iostream>
#include "Metric.h"

using namespace std;

int main(void)
{
    int i;
    cout << "Enter 1 to convert from Metric to Imperial; Enter 2 to convert from Imperial to Metric. Enter 3 to quit: " << endl;
    cin >> i;

    while (i != 3)
    {
        if (i == 1)
        {
            int km;
            double m;
            cout << "Enter kilometers (whole number): " << endl;
            cin >> km;
            cout << "Enter meters: " << endl;
            cin >> m;

            Imperial I1;
            Metric M1(km, m);
            I1 = M1;
            cout << M1 << " = " << I1 << endl;
        }
        else if (i == 2)
        {
            int fur, yd;
            double ft;
            cout << "Enter furlongs (whole number): " << endl;
            cin >> fur;
            cout << "Enter yards (whole number): " << endl;
            cin >> yd;
            cout << "Enter feet: " << endl;
            cin >> ft;

            Metric M2;
            Imperial I2(fur, yd, ft);
            M2 = I2;
            cout << I2 << " = " << M2 << endl;
        }
        cout << "Enter 1 to convert from Metric to Imperial; Enter 2 to convert from Imperial to Metric. Enter 3 to quit: " << endl;
        cin >> i;
        cout << endl;
    }
    
	return 0;
}