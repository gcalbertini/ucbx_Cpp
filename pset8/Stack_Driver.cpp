// MODULE:		stack_driver.cpp
// PROGRAMMER:	Guilherme Albertini
// LANGUAGE:	C++
// DATE:		20/09/16
//
// PURPOSE:
//		Driver for class DoubleStack.

//#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>

#include <iostream>
#include <stdlib.h>
#include "dblstk.h"

size_t capacity = 10;
using namespace std;

int main(void)
{
	int option;
	//DoubleStack stack(capacity);
	DoubleStack stack1 = DoubleStack(capacity);
	DoubleStack stack2 = DoubleStack(capacity);
	DoubleStack* pDoubleStack = &stack1;

	cout << endl;
	cout << "1. Display stack 1" << endl;
	cout << "2. Place a double value onto the top of stack 1" << endl;
	cout << "3. Remove a value from the top of stack 1" << endl;
	cout << "4. Check the total capacity of stack 1" << endl;
	cout << "5. Check the current number of items on stack 1" << endl;
	cout << "6. Copy stack 1 to stack 2" << endl;
	cout << "7. Check to see if both stacks are equal" << endl;
	cout << "8. Quit" << endl;
	cout << endl;

	try {
		
		do
		{
			cout << "Enter menu selection: " << endl;
			cin >> option;

			while (cin && cin.get() != '\n')
				continue;

			double top = pDoubleStack->peekaboo();
			double add;

			switch (option)
			{
			case 1:
				cout << "Displaying stack 1: " << endl;
				cout << stack1;
				break;
			case 2:
				cout << "Enter object of type double to push onto stack 1: " << endl;
				cin >> add;
				stack1.push(add);
				break;
			case 3:
				cout << "Popping value from stack 1..." << endl;
				stack1.pop(top);
				break;
			case 4:
				cout << "Capacity of stack 1 is " << pDoubleStack->capacity() << endl;
				break;
			case 5:
				cout << "Current number of items on stack 1 is " << pDoubleStack->size() << endl;
				break;
			case 6:
				cout << "Copying stack 1 to stack 2... " << endl;
				stack2 = stack1;
				break;
			case 7:
				cout << "Checking to see if both stacks equal... " << endl;
				stack1 == stack2;
				break;
			case 8:
				cout << "Exiting...\n";
				option = 8;
				break;
			default:
				cout << "Not a valid selection! Exiting..." << endl;
				return(1);
			}
			cout << endl;
		} while (option != 8);
	}
	catch (DoubleStack::fatty &of)
	{
		cout << of.what() << endl;
		cout << "Pushing item " << of.item_KO() << " onto stack resulted in overflow (" << of.overflow_stack() << ")" << endl;
		exit(EXIT_FAILURE);
	}
	catch (DoubleStack::skinny& uf)
	{
		cout << uf.what() << endl;
		cout << "No items left to pop from stack (" << uf.underflow_stack() << ")" << endl;
		exit(EXIT_FAILURE);
	}
	
	//_CrtDumpMemoryLeaks();

	return 0;

}
