// manyfrnd.cpp -- unbound template friend to a template class
#pragma once
#include<iostream>
using std::cout;
using std::endl;

template<typename T> class ManyFriend
{
private:
	T item;
public:
	ManyFriend(const T& i) :item(i) {}
	template<typename C, typename D> friend void show2(C&, D&);
};

template<typename C, typename D> void show2(C&, D&)
{
	cout << c.item << ", " << d.item << endl;
}
