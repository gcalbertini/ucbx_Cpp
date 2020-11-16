// MODULE:		vehicleADT.h
// PROGRAMMER:	Guilherme Albertini
// LANGUAGE:	C++
// DATE:		20/09/07	
//
// PURPOSE:
//		Driver for vehicle ADT.
#include "vehicleADT.h"
using namespace std;

void display();
void options(vehicleADT* p, int i);

int main(void)
{
	const double MPH_2_MS = 0.44704;
	const int MODES = 3;
	int range = 0;
	int type;
	string name, method;
	double w0, wf, speed;
	
	


	cout << "Enter 1 if by air, 2 if by land, and 3 if by sea: " << endl;
	cin >> type;
	cout << "Enter vehicle speed (mph): " << endl;
	(cin >> speed).get();
	cout << "Enter vehicle identification: \n";
	getline(cin, name);
	cout << "Enter empty weight of vehicle: \n";
	cin >> w0;
	cout << "Enter max weight of vehicle: \n";
	cin >> wf;
	

	if (type == 1)
	{
		method = "air";
		double cl, cd;
		cout << "Enter aircraft lift coefficient (0.3 - 1.5 is typical): " << endl;
		cin >> cl;
		cout << "Enter aircraft drag coefficient (0.02 - 0.06 is typical): " << endl;
		cin >> cd;

		vehicleADT* p = new airplane(name, method, w0, wf, speed, cl, cd);

		int option;
		display();
		cin >> option;
		cout << endl;

		options(p, option);

		delete p;
	}
	else if (type == 2)
	{
		method = "land";
		double fuelCap, mpg;
		cout << "Enter car MPG rating: " << endl;
		cin >> mpg;
		cout << "Enter car fuel capacity in gallons: " << endl;
		cin >> fuelCap;

		vehicleADT* p = new car(name, method, w0, wf, speed, mpg, fuelCap);

		int option;
		display();
		cin >> option;
		cout << endl;

		options(p, option);

		delete p;

	}
	else if (type == 3)
	{
		method = "sea";
		double fuelCap, nmpg;
		cout << "Enter boat nautical MPG rating: " << endl;
		cin >> nmpg;
		cout << "Enter boat fuel capacity in gallons: " << endl;
		cin >> fuelCap;

		vehicleADT* p = new boat(name, method, w0, wf, speed, nmpg, fuelCap);

		int option;
		display();
		cin >> option;
		cout << endl;

		options(p, option);

		delete p;
	}
	else
	{
		return 1;
	}

	
	return 0;
}

void display()
{
	cout << "Select which characteristics you would you like to view: \n";
	cout << "===========================================================\n";
	cout << "1. Vehicle name" << endl;
	cout << "2. Mode of transport" << endl;
	cout << "3. Vehicle empty weight" << endl;
	cout << "4. Vehicle max weight" << endl;
	cout << "5. Vehicle speed" << endl;
	cout << "6. Vehicle range" << endl;
	cout << "7. Quit" << endl;
}

void options(vehicleADT*p, int i)
{
	while (i != 7)
	{
		switch (i)
		{
		case 1:
			cout << p->Identity() << endl;
			break;
		case 2:
			cout << p->Mode() << endl;
			break;
		case 3:
			cout << p->emptyW() << endl;
			break;
		case 4:
			cout << p->maxW() << endl;
			break;
		case 5:
			cout << p->howFast() << endl;
			break;
		case 6:
			cout << p->Range() << endl;
		default:
			i = 7;
			break;
		}
		cout << endl;
		display();
		cin >> i;
		cout << endl;
	}
}