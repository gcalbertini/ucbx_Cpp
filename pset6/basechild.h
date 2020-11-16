// MODULE:		basechild.h
// PROGRAMMER:	Guilherme Albertini
// LANGUAGE:	C++
// DATE:		20/09/04	
//
// PURPOSE:
//		Declarations for classes.

#ifndef BASE_CHILDS_
#define BASE_CHILDS_

#include <string>
using std::string;


//base class, employee

class person
{
private:
	//things we can change
	string fullName;
	string gender;
	string homeAddress;
	long long homePhone;

	//things we don't want to modify
	long long SSN;
	int DOB;
	

public:
	person(const string &fn = "none", const string &gen = "none", const string &home = "none", long long social = 0, int date = 0, long long num = 0);
	

	virtual ~person() {};

	//person methods
	virtual void ChangeString(int i, string& s);
	void ChangeNum(long long n);
	virtual void Show() const;
};


class employee : public person
{
private:
	//we can change
	long long workPhone;

	//things to keep as is
	int hireDate;
	string workAddress;
	double salary;

public:
	employee(const string& fn = "none", const string& gen = "none", const string& home = "none", long long social = 0,
			int date = 0, long long num = 0, const string& work = "none", int hired = 0, long long num2 = 0, double money = 0.0);

	employee(const person& p, const string& work, int hired = 0, long long num2 = 0, double money = 0.0);

	//employee methods
	
	virtual void ChangeString(int i, string& s);
	virtual void Show() const;
};

class dependent : employee
{
private:
	string dephomeAddress;

public:

	dependent(const employee& e, const string& childHome = "none");

	dependent(const string& fn = "none", const string& gen = "none", const string& home = "none", long long social = 0,
	int date = 0, long long num = 0, const string& work = "none", int hired = 0, long long num2 = 0, double money = 0.0, const string& childHome = "none");

	
	virtual void Show() const;
	virtual void ChangeString(int i, string& s);

};

class manager : employee
{
private:
	string title;
public:  
	manager(const employee& e, const string& role = "none");

	manager(const string& fn = "none", const string& gen = "none", const string& home = "none", long long social = 0,
		int date = 0, long long num = 0, const string& work = "none", int hired = 0, long long num2 = 0, double money = 0.0, const string& role = "none");


	virtual void Show() const;
	virtual void ChangeString(int i, string& s);

};

class worker : employee
{
private:
	string project;
public:
	worker(const employee& e, const string& job = "none");

	worker(const string& fn = "none", const string& gen = "none", const string& home = "none", long long social = 0,
		int date = 0, long long num = 0, const string& work = "none", int hired = 0, long long num2 = 0, double money = 0.0, const string& job = "none");


	virtual void Show() const;
	virtual void ChangeString(int i, string& s);
};

#endif // !BASE_CHILDS_
