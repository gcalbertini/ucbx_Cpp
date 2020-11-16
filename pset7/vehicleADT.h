// MODULE:		vehicleADT.h
// PROGRAMMER:	Guilherme Albertini
// LANGUAGE:	C++
// DATE:		20/09/07	
//
// PURPOSE:
//		Header for vehicle ADT.


#ifndef VEHICLEADT_H_
#define VEHICLEADT_H_
#include <iostream>
#include <string>

// Abstract Base Class
class vehicleADT
{
private:
	std::string id;
	double emptyWeight;
	double maxWeight;
	double speed;
	
	
protected:
	double range;
	std::string mode;
public:
	vehicleADT( std::string& name, std::string& type, double w0 = -1.0, double wf = -1.0, double v = 0.0);
	virtual double Range() = 0; 
	virtual const std::string& Mode() = 0;
	const std::string& Identity() const { return id; }
	double emptyW() const { return emptyWeight; };
	double howFast() const { return speed; };
	double maxW() const { return maxWeight; };

	virtual ~vehicleADT() {}
};

class airplane : public vehicleADT 
	/*only valid for jet propulsion, not propeller or electric..option for range cruising at a fixed height,
	a fixed angle of attack and a constant specific fuel consumption AND constant local speed of sound in the stratosphere...
	more sophisticated analyses with regards to endurance, air resistance, drag effects, or not in stratosphere and other structural mechanics not included*/
	//below must be in metric
{
private:
	double C_l; //lift ratio
	double C_d; //drag ratio
	double c_t = 290; //thrust specific fuel consumption; assume 14 g/(kN·s) for GE9X engine
	double KM_TO_MI = 0.621371;
public:
	airplane( std::string& name, std::string& type, double w0 = -1.0, double wf = -1.0, double v = 0.0,
		double cl = 0.0, double cd = 0.0) : vehicleADT(name, type, w0, wf, v), C_l(cl), C_d(cd) { }
	virtual const std::string& Mode();
	virtual double Range();
	virtual ~airplane() {}
};


class car : public vehicleADT
	//assume gas-powered only
{
private:
	double MPG;
	double fuelCap;
public:
	car( std::string& name, std::string& type, double w0 = -1.0, double wf = -1.0, double v = 0.0,
		double mpg = 0, double fuel = 0.0) : vehicleADT(name, type, w0, wf, v), MPG(mpg), fuelCap(fuel) { };
	virtual double Range();
	virtual const std::string& Mode();
	virtual ~car() {}
};


class boat : public vehicleADT
	//assume gas-powered only
{
private:
	double fuelCap;
	double nMPG;

public:
	boat( std::string& name,  std::string& type, double w0 = -1.0, double wf = -1.0, double v = 0.0,
		double nmpg = 0, double fuel = 0.0) : vehicleADT(name, type, w0, wf, v), nMPG(nmpg), fuelCap(fuel) { };
	virtual double Range();
	virtual const std::string& Mode();
	virtual ~boat() {}
};


#endif