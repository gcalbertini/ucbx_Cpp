// MODULE:		basechild.cpp
// PROGRAMMER:	Guilherme Albertini
// LANGUAGE:	C++
// DATE:		20/09/04	
//
// PURPOSE:
//		Implementations for classes.

#include <iostream>
#include "basechild.h"
using std::cout;
using std::cin;
using std::endl;

//person methods

person::person(const string& fn, const string& gen, const string& home, long long social, int date, long long num) : fullName(fn), gender(gen), homeAddress(home), SSN(social), DOB(date), homePhone(num) {}


void person::ChangeString(int i, string& s)
{
	if (i == 1)
	{
		fullName = s;
	}
	else if (i == 2)
	{
		gender = s;
	}
	else if (i == 3)
	{
		homeAddress = s;
	}
}

void person::ChangeNum(long long n)
{
	homePhone = n;
}

void person::Show() const
{
	cout << "Name: "<< fullName << endl;
	cout << "Gender: " << gender << endl;
	cout << "Home address: " << homeAddress << endl;
	cout << "SSN: " << SSN << endl;
	cout << "DOB: " << DOB << endl;
	cout << "Home phone: " << homePhone << endl;
	
}

//employee methods

employee::employee(const string& fn, const string& gen, const string& home, long long social, int date, long long num, 
	const string& work, int hired, long long num2, double money) 
	: person(fn, gen, home, social, date, num)
{
	hireDate = hired;
	workAddress = work;
	workPhone = num2;
	salary = money;
}

employee::employee(const person& p, const string& work, int hired, long long num2, double money) : person(p) //implict copy constructor
{
	hireDate = hired;
	workAddress = work;
	workPhone = num2;
	salary = money;
}

void employee::ChangeString(int i, string& s)
{
	if (i < 4)
	{
		person::ChangeString(i, s);
	}
	else if (i == 4)
	{
		person::ChangeNum(stoll(s));
	}
	else if (i == 5)
	{
		long long num = stoll(s);
		workPhone = num;
	}
	else if (i == 6)
	{
		double money = stod(s);
		salary = money;
	}
}

void employee::Show() const
{
	person::Show();
	cout << "Work address: " << workAddress << endl;
	cout << "Salary: " << salary << endl;
	cout << "Work phone: " << workPhone << endl;
	cout << "Date hired: " << hireDate << endl;
}

//dependent methods

dependent::dependent(const employee& e, const string& childHome) : employee(e)//implicit copy constructor
{
	dephomeAddress = childHome;
}

dependent::dependent(const string& fn, const string& gen, const string& home, long long social, int date, long long num, 
	const string& work, int hired, long long num2, double money, const string& childHome) :
	employee(fn, gen, home, social, date, num, work, hired, num2, money)
{
	dephomeAddress = childHome;
}


void dependent::Show() const
{
	person::Show();
}

void dependent::ChangeString(int i, string& s)
{
	employee::ChangeString(i, s);
}

//manager methods

manager::manager(const employee& e, const string& role) : employee(e), title(role) {}
manager::manager(const string& fn, const string& gen, const string& home, long long social, int date,
	long long num, const string& work, int hired, long long num2, double money, const string& role)
	: employee(fn, gen, home, social, date, num, work, hired, num2, money)
{
	title = role;
}
void manager::Show() const
{
	employee::Show();
	cout << "Manager title: " << title << endl;
}
void manager::ChangeString(int i, string& s)
{
	if (i < 7)
	{
		employee::ChangeString(i, s);
	}
	else if (i == 7)
	{
		title = s;
	}
}

//worker methods

worker::worker(const employee& e, const string& job) : employee(e)
{
	project = job;
}

worker::worker(const string& fn, const string& gen, const string& home, long long social, int date, long long num, const string& work, int hired, long long num2, double money, const string& job)
	: employee(fn, gen, home, social, date, num, work, hired, num2, money)
{
	project = job;
}

void worker::Show() const
{
	employee::Show();
	cout << "Working project: " << project << endl;
}

void worker::ChangeString(int i, string& s)
{
	if (i < 7)
	{
		employee::ChangeString(i, s);
	}
	else if (i == 7)
	{
		project = s;
	}
}

