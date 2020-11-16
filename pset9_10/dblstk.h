// MODULE:		dblstk.h
// PROGRAMMER:	Guilherme Albertini
// LANGUAGE:	C++
// DATE:		20/09/21	
//
// PURPOSE:
//		Declarations for class DoubleStack.

#include	<stdlib.h>
using namespace std;


template <typename T>
class	DoubleStack
{
private:
	T* data;		// Pointer to dynamic stack area.
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

	int	push(T& item);

	// Remove top item from stack and return it in item.
	// Return value 1=success/0=failure.

	int	pop(T& item);

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




	/*This approach is the most permissive approach to declaring a templated friend function of a templated class.
	This will work for all cases where explicitly pass an instance of class DoubleStack& to stream with operator<<(). 
	However,side effect of this approach : All template instantiations of DoubleStack are friends with all template instantiations of operator<<(). 
	So, for example, DoubleStack<int> is friends with operator<< <int> but also operator<< <double>. Allowing here though since its a first attempt at templating*/
	template <typename U>
	friend ostream& operator<<(ostream& os, DoubleStack<U>& rhs);

};

template <typename T>
//create an empty stack
DoubleStack<T>::DoubleStack(size_t capacity)
{

	//cout << "Created, you have been." << endl;

	//initialize data as ptr to "dynamic" DoubleStack object
	data = new T[capacity];

	if (!data)
	{
		cerr << "MEMORY ALLOCATION FAILED!\n;";
		exit(1);
	}

	stack_size = capacity;
	tos = -1; //for the sake of initialization, -1 to indicate nothing was done

}

template <typename T>
//copy constructor
DoubleStack<T>::DoubleStack(const DoubleStack& rhs)
{
	//cout << "Copied, you are." << endl;

	size_t i; //loop variable,

	data = new T[rhs.stack_size];

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

template <typename T>
DoubleStack<T>::~DoubleStack(void)
{
	//cout << "Destroyed, you are." << endl;

	delete[] data;
	stack_size = 0;
}

//From text: "Notice that the prototype declares the return type for the assignment operator function
//to be a reference to DoubleStack, and the actual template function definition identifies the
//type as DoubleStack<T>.The former is an abbreviation for the latter, but it can be used only
//within the class scope. That is, you can use DoubleStack inside the template declaration and
//inside the template function definitions, but outside the class, as when identifying return
//types and when using the scope-resolution operator, you need to use the full DoubleStack<T> form."
//Essentially, need to be same type T to assign from one object to another (at least safely)
template <typename T>
DoubleStack<T>& DoubleStack<T>::operator=(DoubleStack<T>& rhs)
{
	//cout << "Assigned, you have been." << endl;

	// if object assigned to itself all done
	if (this == &rhs)
		return *this;

	if (stack_size != rhs.size())
	{

		//free old stack constructed to have capacity for new rhs object
		delete[] data;

		data = new T[rhs.stack_size];
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

template<typename T>
inline int DoubleStack<T>::push(T& item)
{
	if (size() >= capacity())
	{
		cout << "Stack overflow." << endl;
		return false;
	}
	else
	{
		cout << "Inserting " << item << endl;

		//add item to stack
		data[++tos] = item;
		return true;
	}
}

template<typename T>
inline int DoubleStack<T>::pop(T& item)
{
	if (tos < 0 || empty())
	{
		cout << "Stack underflow." << endl;
		return false;
	}
	else
	{
		cout << "Popped " << item << " from stack! " << endl;
		return data[tos--];
	}
}

template<typename T>
int DoubleStack<T>::empty(void)
{
	return size() == 0;
}

template<typename T>
size_t DoubleStack<T>::capacity(void)
{
	return stack_size;
}

template<typename T>
size_t DoubleStack<T>::size(void)
{
	return tos + 1;
}

//see above text; check for equality of objects of same type
template<typename T>
int DoubleStack<T>::operator==(DoubleStack<T>& rhs)
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

template<typename T>
inline size_t DoubleStack<T>::peekaboo(void)
{
	if (!empty())
	{
		return data[tos];
	}

}

template<typename T>
ostream& operator<<(ostream& os, DoubleStack<T>& rhs)
{
	DoubleStack<T>* ptr = &rhs;
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
