#pragma once

template<class Type>
class Stack_P
{
private:
	enum { SIZE = 10 };	// default size
	int stacksize;
	Type* items;		// holds stack items
	int top;			// index for top stack item
public:
	explicit Stack_P(int ss = SIZE);
	Stack_P(const Stack_P& st);
	~Stack_P() { delete[]items; }
	bool isempty() { return top == 0; }
	bool isfull() { return top == stacksize; }
	bool push(const Type& item);	// add item to stack
	bool pop(Type& item);			// pop top into item
	Stack_P& operator=(const Stack_P& st);
};

template<class Type>
Stack_P<Type>::Stack_P(int ss) :stacksize(ss), top(0)
{
	items = new Type[stacksize];
}

template<class Type>
Stack_P<Type>::Stack_P(const Stack_P& st)
{
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
}

template<class Type>
bool Stack_P<Type>::push(const Type& item)
{
	if (top < stacksize)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

template <class Type>
bool Stack_P<Type>::pop(Type& item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}

template <class Type>
Stack_P<Type>& Stack_P<Type>::operator=(const Stack_P& st)
{
	if (this == &st)
		return *this;
	delete[]items;
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
	return *this;
}