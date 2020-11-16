// MODULE:		Metric.cpp
// PROGRAMMER:	Guilherme Albertini
// LANGUAGE:	C++
// DATE:		20/09/05	
//
// PURPOSE:
//		Implementations for class conversions.

const double FT_PER_METER = 3.2808399;
const int YD_PER_FUR = 220;
const int FT_PER_YD = 3;

#include "Metric.h";

Metric::Metric(int km, double m)
{
	kilometers = km;
	meters = m;
}

Metric::Metric(Imperial& I)
{
	int fur = I.getFUR();
	int yd = I.getYD();
	double ft = I.getFT();
	
	while (ft >= 3.0)
	{
		ft -= 3.0;
		yd++;
	}

	while (yd >= 220)
	{
		yd -= 220;
		fur++;
	}
	
	double m = 0.0;
	int km = 0;

	double yd2m = FT_PER_YD / FT_PER_METER;

	int sum1 = fur * YD_PER_FUR; //fur-->yd
	m += double(sum1)*yd2m; //yd-->ft-->m

	m += yd*yd2m; //ft-->m

	m += ft / FT_PER_METER; //ft-->m


	while (m >= 1000.0)
	{
		m -= 1000.0;
		km++;
	}

	meters = m;
	kilometers = km;
}

std::ostream& operator<<(std::ostream& str, Metric& M)
{
	str << M.kilometers << " km " << M.meters << " m\n";
	return str;
}
