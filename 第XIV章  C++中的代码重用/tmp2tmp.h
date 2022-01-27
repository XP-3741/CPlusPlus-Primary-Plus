// tmp2tmp.cpp -- template friends to a template class
#pragma once
#include<iostream>
using std::cout;
using std::endl;

// template prototypes
template <typename T> void Counts();
template <typename T> void Report(T&);

// template class
template<typename TT> class HasFriendT
{
private:
	TT item;
	static int ct;
public:
	HasFriendT(const TT& i) :item(i) { ct++; }
	~HasFriendT() { ct--; }
	friend void Counts<TT>();
	friend void Report<>(HasFriendT<TT>&);
};

template<typename T>
int HasFriendT<T>::ct = 0;

// template friend functions definitions
template<typename T> void Counts()
{
	cout << "template size: " << sizeof(HasFriendT<T>) << ": ";
	cout << "template counts(): " << HasFriendT<T>::ct < endl;
}

template<typename T> void Report(T& hf)
{
	cout << hf.item << endl;
}
