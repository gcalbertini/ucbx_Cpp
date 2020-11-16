// MODULE:      llmain.cpp
   // PROGRAMMER:  Guilherme Albertini
   // LANGUAGE:    C++
   // DATE:        10/13/2020
   //
   // PURPOSE:
   //   Demonstrate Lists.

#include      <iostream>  
#include      <string.h>
#include      "linklist.h"
#include      "Meeting.h"

int main(void)
{
    Meeting* m, * m1, * m2, * m3, * m4, *m5;
    List           l;
    ListIterator* iter;
    unsigned long  year;
    unsigned long  month;
    unsigned long  day;
    unsigned long  hr;
    unsigned long  min;
    List* cloned_list;

    
    m1 = new Meeting("Merlin", "Nutty Street", 1, 4, 2050, 30, 23);
    l.Insert(m1);
    m2 = new Meeting("Karen", "Parking Lot", 12, 4, 2050, 45, 21);
    l.Insert(m2);
    m3 = new Meeting("Harry Potter", "Burger King", 12, 4, 1999, 30, 6);
    l.Insert(m3);
    m4 = new Meeting("Lazarus", "Conference Room", 12, 4, 1999, 30, 5);
    l.Insert(m4);
    m5 = new Meeting("Peter Pan", "Aisle 4", 12, 4, 1999, 21, 5);
    l.Insert(m5);


    iter = new ListIterator(l);
    while(m = (Meeting*)(iter->NextItemInList())) { m->print(); }
    delete iter;
    

  

}