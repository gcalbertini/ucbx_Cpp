// MODULE:		dblstk.cpp
// PROGRAMMER:	Guilherme Albertini
// LANGUAGE:	C++
// DATE:		20/09/16	
//
// PURPOSE:
//		Implementations for class DoubleStack.

#include <iostream>
#include "dblstk.h"


//create an empty stack
DoubleStack::DoubleStack(size_t capacity)
{

	//cout << "Created, you have been." << endl;

	//initialize data as ptr to "dynamic" DoubleStack object
	data = new double[capacity];

	if (!data)
	{
		cerr << "MEMORY ALLOCATION FAILED!\n;";
		exit(1);
	}

	stack_size = capacity;
	tos = -1; //for the sake of initialization, -1 to indicate nothing was done

}

//copy constructor
DoubleStack::DoubleStack(const DoubleStack& rhs)
{
	//cout << "Copied, you are." << endl;

	size_t i; //loop variable,

	data = new double[rhs.stack_size];

	if (!data)
	{
		cerr << "MEMORY ALLOCATION FAILED!\n;";
		exit(1);
	}

	stack_size = rhs.stack_size;
	tos = rhs.tos;

	for (i = 0; i < stack_size; ++i)
		data[i] = rhs.data[i];
}

DoubleStack::~DoubleStack(void)
{
	//cout << "Destroyed, you are." << endl;

	delete[] data;
	stack_size = 0;
}

DoubleStack& DoubleStack::operator=(DoubleStack& rhs)
{
	//cout << "Assigned, you have been." << endl;

	// if object assigned to itself all done
	if (this == &rhs)
		return *this;

	if (stack_size != rhs.size())
	{

		//free old stack constructed to have capacity for new rhs object
		delete[] data;

		data = new double[rhs.stack_size];
	}

	if (!data)
	{
		cerr << "MEMORY ALLOCATION FAILED!\n;";
		exit(1);
	}

	//copy contents
	stack_size = rhs.stack_size;
	tos = rhs.tos;

	size_t i; //loop variable

	for (i = 0; i < stack_size; ++i)
		data[i] = rhs.data[i];

	//return reference to invoking object
	return *this;
}

int DoubleStack::push(double& item)
{
	if (size() >= capacity())
		throw fatty(data, item);
	
	cout << "Inserting " << item << endl;

	//add item to stack
	data[++tos] = item;
	return true;
}

int DoubleStack::pop(double& item)
{
	if (tos < 0 || empty())
		throw skinny(data);

	cout << "Popped " << item << " from stack! " << endl;
	return data[tos--];
}

int DoubleStack::empty(void)
{
	return size() == 0;
}

size_t DoubleStack::capacity(void)
{
	return stack_size;
}

size_t DoubleStack::size(void)
{
	return tos + 1;
}

int DoubleStack::operator==(DoubleStack& rhs)
{
	//if stacks are not same length
	if (size() != rhs.size())
	{
		cout << "Stacks are not equal (capacity mismatch)." << endl;
		return false;
	}

	//if they point to same object
	if (this == &rhs)
	{
		cout << "Stacks are equal (point to same object)." << endl;
		return true;
	}

	//find any mismatched elements
	size_t i;
	for (i = 0; i < tos + 1; ++i)
	{
		if (data[i] != rhs.data[i])
		{
			cout << "Stacks are not equal (discrepant elements)." << endl;
			return false;
		}
	}

	//If stacks are same length; but didn't point to same object; and didn't have mismatched members
	cout << "Stacks are equal. All checks passed." << endl;
	return true;
}

size_t DoubleStack::peekaboo(void)
{

	if (!empty())
	{
		return data[tos];
	}
}

ostream& operator<<(ostream& os, DoubleStack& rhs)
{
	DoubleStack* ptr = &rhs;
	int items = ptr->size();

	for (int i = items - 1; i >= 0; i--)
	{
		if (i >= 0)
		{
			os << "\n";
		}
		os << rhs.data[i];
	}
	cout << endl;
	return os;
}

DoubleStack::fatty::fatty(double* stack, double& item, const std::string& s) : std::overflow_error(s), bigbad(stack), KO(item) {}

DoubleStack::fatty::~fatty() noexcept
{
}


DoubleStack::skinny::skinny(double* stack, const std::string& s) : std::underflow_error(s), smallbad(stack) {}

DoubleStack::skinny::~skinny() noexcept
{
}
