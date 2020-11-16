/* FILENAME: EW_Driver.cpp
   PROGRAMMER: Guilherme Albertini
   DATE: 6/20/20
   COMPILER: MSVC++ 2019
   REQUIRED: EnglishWeight.cpp, EnglishWeight.h
   PURPOSE: Possible interface for class*/

#include <iostream>
#include "EnglishWeight.h"

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	EnglishWeight weight1, weight2;
	cout << "Enter the following weights using standard form; for example, 3 lb and 12 oz." << endl;
	cout << "Entering the weight for EnglishWeight1..." << endl;
	cin >> weight1;
	cout << "Entering the weight for EnglishWeight2... " << endl;
	cin >> weight2;

	int num;
	cout << "Now enter a scale factor (whole number): " << endl;
	cin >> num;
	cout << '\n' << endl;


	//Output the arithmetic
	cout << weight1 <<" + " << weight2 << " = " << weight1 + weight2 << endl;
	cout << weight1 << " - " << weight2 << " = " << weight1 - weight2 << endl;
	cout << weight1 << " / " << weight2 << " = " << weight1 / weight2 << endl;
	cout << weight1 << " * " << num << " = " << weight1 * num << endl;
	cout << num << " * " << weight1 << " = " << num * weight1 << endl;
	cout << weight1 << " / " << num << " = " << weight1 / num << endl;
}





 