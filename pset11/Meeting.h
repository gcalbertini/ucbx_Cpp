
// MODULE:      Meeting.h
// PROGRAMMER:  Guilherme Albertini
// LANGUAGE:    C++
// DATE:        10/13/2020
//
// PURPOSE:
//   Store information about a person.
//   Derive a concrete type from the ADT ListItem.

#ifndef      meeting_h
#define      meeting_h

#include     <iostream>  
#include     <string>
#include     "linklist.h"

class Meeting : public ListItem
{
public:
    Meeting(const char* s, const char* l, unsigned int dd, unsigned int mm, unsigned int yy, unsigned int m, unsigned int h )
    {
        strcpy_s(name, s);
        strcpy_s(location, l);
        day = dd;
        year = yy;
        month = mm;
        hour = h;
        min = m;
    };

    virtual int CompareByInsertKey (ListItem* item_in_list);
    virtual void print();
    virtual ListItem* Clone();

    char name[30]; // Person who your meeting
    char location[50]; //Location where meeting occurs

private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
    unsigned int hour;
    unsigned int min;


};

#endif  