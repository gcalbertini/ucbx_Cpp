
// FILENAME: hello_driver.cpp
  // PROGRAMMER: Guilherme Albertini
  // DATE: 6/8/2020
  // COMPILER: MVSC 2019
  // REQUIRED: hello_interface.cpp, hello_driver.cpp, hello_interface.h
  // PURPOSE:  Prompts the user for their first name and returns the name back to main()

#include <iostream>
#include <string>
#include "hello_interface.h"
using namespace std;


string fname(string str)
{
    cout << "Enter your first name:\n";
    cin >> str;
    return str;
}
