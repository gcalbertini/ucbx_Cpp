// MODULE:		vehicleADT.h
// PROGRAMMER:	Guilherme Albertini
// LANGUAGE:	C++
// DATE:		20/09/07	
//
// PURPOSE:
//		Implementations for vehicle ADT.




#include "vehicleADT.h"
#include <cmath>

using std::cout;
using std::string;
using std::endl;


vehicleADT::vehicleADT(std::string& name, std::string& type, double w0, double wf, double v)
{
	id = name;
	mode = type;
	emptyWeight = w0;
	maxWeight = wf;
	speed = v;
}


const std::string& airplane::Mode()
{
	mode = "By Air";
	return mode;
}

double airplane::Range()
{
	
	range = howFast()* 0.44704 * (C_l / C_d) / c_t * log(maxW() / emptyW()); //in m, ct in g/(kN·s) or s/m
	 
	cout << "Commercial aircraft range (using fuel consumption of GE9X engine) in miles: " << endl;
	//do not be shocked; there is a lot this isn't capturing, and other characteristics of the aircraft that we can design to lead to a greater "range"
	return range* 0.000621371;
}

double car::Range()
{
	range = MPG * fuelCap;
	cout << "Car range in miles: " << endl;
	return range;
}

const std::string& car::Mode()
{
	mode = "By Land";
	return mode;
}

double boat::Range()
{
	range = fuelCap * nMPG;
	cout << "Boat range in miles: " << endl;
	return range;
}

const std::string& boat::Mode()
{
	mode = "By Sea";
	return mode;
}

