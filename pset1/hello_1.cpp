// FILENAME:   hello_1.cpp 
// PROGRAMMER: Guilherme Albertini      
// DATE:       05/04/2020
// COMPILER:   MS Visual C++ 2019 Community Edition
// REQUIRED:   hello_1.cpp
// PURPOSE:
//    Illustrate the basic form of a C++ program.
//    Illustrate the use of // which means what follows is a comment.
//    Illustrate the use of << which is used to output stuff.

#include <iostream>         // Allows use of << and >> operators.
#include <string>           //Allows use of C++ string class
using namespace std;        // Eliminates need for std as in std::cout

int main(void)
{
    string firstName;
    cout << "Enter your first name:\n";
    cin >> firstName;
    cout << "Hello, " << firstName << "!\n";

    system("pause");   // required by some compilers to keep output window open.
    return 0;
}