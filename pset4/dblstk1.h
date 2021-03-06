// MODULE:		dblstk1.h
// PROGRAMMER:	Guilherme Albertini
// LANGUAGE:	C++
// DATE:		20/08/30	
//
// PURPOSE:
//		Declarations for class DoubleStack.

#include	<stdlib.h>
using namespace std;

class	DoubleStack
{
private:
	double* data;		// Pointer to dynamic stack area.
	size_t	stack_size;	// Capacity of stack.
	size_t	tos;		// Top of stack. tos==0 ==> empty stack.

public:

	// Constructor.

	DoubleStack(size_t	capacity);

	// Copy Constructor.

	DoubleStack(const DoubleStack& rhs);

	// Destructor.

	~DoubleStack(void);

	// Assignment operator=.

	DoubleStack& operator=(DoubleStack& rhs);

	// Add item to stack, making it the topmost item.
	// Return value 1=success/0=failure.

	int	push(double& item);

	// Remove top item from stack and return it in item.
	// Return value 1=success/0=failure.

	int	pop(double& item);

	// Determine if the stack is empty.
	// Return value 1=empty/0=non-empty.

	int	empty(void);

	// Inquire the capacity of the stack.

	size_t	capacity(void);

	// Inquire the number of items on the stack.

	size_t	size(void);

	// Compare 2 stacks to see if the contain the same data.

	int	operator==(DoubleStack& rhs);

	//return top of stack element

	size_t peekaboo(void);

	//adding friend as one possible way to display stack values (void function returning values with overload [] works too)
	friend ostream& operator << (ostream& os, DoubleStack& rhs);

};

