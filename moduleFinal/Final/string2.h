
// MODULE:		string2.h
// PROGRAMMER:	Guilherme Albertini
// LANGUAGE:	C++
// DATE:		10/14/20
//
// PURPOSE:
//		Final exam 


#ifndef STRING2_H_
#define STRING2_H_
#include <iostream>

using std::ostream;
using std::istream;
class String
{
private:
	char* str; // pointer to string
	int len; // length of string
	static int num_strings; // number of objects
	static const int CINLIM = 80; // cin input limit
public:
	// constructors and other methods
	String(const char* s); // constructor
	String(); // default constructor
	String(const String&); // copy constructor
	~String(); // destructor
	int length() const { return len; }
	String& stringlow();
	String& stringup();
	int has(char) const;
	// overloaded operator methods
	String& operator=(const String&);
	String& operator=(const char*);
	char& operator[](int i);
	const char& operator[](int i) const;
	// overloaded operator friends
	friend String operator+(const String&, const String&);
	friend String operator+(const char*, const String&);
	friend String operator+(const String&, const char*);
	friend bool operator<(const String& st, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st, const String& st2);
	friend ostream& operator<<(ostream& os, const String& st);
	friend istream& operator>>(istream& is, String& st);
	// static function
	static int HowMany();
};
#endif
