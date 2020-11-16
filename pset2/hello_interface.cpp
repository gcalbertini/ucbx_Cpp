// FILENAME: hello_interface.h
  // PROGRAMMER: Guilherme Albertini
  // DATE: 6/8/2020
  // COMPILER: MVSC 2019
  // REQUIRED: hello_interface.cpp, hello_driver.cpp, hello_interface.h
  // PURPOSE:  Display user's first name on screen 

#include <iostream>         // Allows use of << and >> operators.
#include "hello_interface.h"

int main()
{
    std::string input;
    std::cout << "Hello, " << fname(input) << "!\n";

    system("pause");   // required by some compilers to keep output window open.
    return 0;
}