// MODULE:		Imperial.cpp
// PROGRAMMER:	Guilherme Albertini
// LANGUAGE:	C++
// DATE:		20/09/05	
//
// PURPOSE:
//		Implementations for class conversions.

const double FT_PER_METER = 3.2808399;
const int YD_PER_FUR = 220;
const int FT_PER_YD = 3;

class Metric; //forward declaration
#include "Metric.h";

Imperial::Imperial(int fur, int yd, double ft)
{
	furlongs = fur;
	yards = yd;
	feet = ft;
}

Imperial::Imperial(Metric& M)
{
	int km = M.getKM();
	double m = M.getM();

	while (m >= 1000.0)
	{
		m -= 1000.0;
		++km;
	}

	km *= 1000;
	m = m + double(km);
	double ft = m * FT_PER_METER; //say 1009.0 ft
	
	double tot_yd = ft/FT_PER_YD; //all yds, 336.333 yd
	
	int fur = int(tot_yd / YD_PER_FUR); //take out fur of 220 yd (1 fur)
	
	//breaking up sum to avoid overflow warnings (cast from 4 byte value to 8 byte value)
	int sum = int(fur * YD_PER_FUR);
	
	double yd_left = (tot_yd - sum); //all converted to doubles; 116.333 leftover yd, but can be further split between yd and feet

	int yd = int(yd_left); //now 116 yd
	ft = ((yd_left - yd) * FT_PER_YD); //convert to doubles 116.333 - 116.0 = .333 yd -->.999 ft left

	feet = ft;
	furlongs = fur;
	yards = yd;
	
}

std::ostream& operator<<(std::ostream& str, Imperial& I)
{
	str << I.furlongs << " fur " << I.yards << " yd "<< I.feet <<" ft\n";
	return str;
}
