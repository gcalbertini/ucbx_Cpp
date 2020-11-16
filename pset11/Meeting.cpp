// MODULE:      Meeting.cpp
   // PROGRAMMER:  Guilherme Albertini
   // LANGUAGE:    C++
   // DATE:        10/13/2020
   //
   // PURPOSE:
   //   Store information about a person.
   //   Derive a concrete type from the ADT ListItem.

#include "Meeting.h"

using std::cout;
using std::endl;

// Clone the item.


ListItem* Meeting::Clone()
{
    Meeting* p;

    p = new Meeting(name, location, day, month, year, min, hour);
    return (ListItem*)p;
}

//The CompareByInsertKey function should order a list of Meetings based on the date and time
int Meeting::CompareByInsertKey(ListItem* item_in_list)
{
    
    if (this->year < ((Meeting*)item_in_list)->year)
    {
        return 1;
    }
    else if (this->month < ((Meeting*)item_in_list)->month)
    {
        return 1;
    }
    else if (this->day < ((Meeting*)item_in_list)->day)
    {
        return 1;
    }
    else if (this->hour < ((Meeting*)item_in_list)->hour)
    {
        return 1;
    }
    else if (this->min < ((Meeting*)item_in_list)->min)
    {
        return 1;
    }
    else
    {
        return -1;
    }

}

void Meeting::print()
{
    cout << "Meeting " << name << " at " << location << endl;
    cout << "On date: " << day << "/" << month << "/" << year << " at " << hour << ":" << min << endl;
}
