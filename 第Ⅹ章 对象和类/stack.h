#pragma once

typedef unsigned long Item;

class Stack
{
private:
	enum {MAX = 10};
	Item items[MAX];
	int top;
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	// push() returns false if stack already is full,true otherwise
	bool push(const Item& item);
	// pop() returns false if stack already is empty,true otherwise
	bool pop(Item& item);
};
