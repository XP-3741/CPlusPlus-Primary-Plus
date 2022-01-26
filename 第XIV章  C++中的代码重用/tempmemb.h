// tempmemb.h -- template members
#pragma once
#include<iostream>
using std::cout;
using std::endl;

template<typename T>
class beta
{
private:
	template<template V>	// nest template class member
	class hold
	{
	private:
		V val;
	public:
		hold(V v = 0) :val(v) {}
		void show() const { cout << val << endl; }
		V Value() const { return val; }
	};
	hold<T> q;		// template object	
	hold<int> n;	// template object
public:
	beta(T t, int i) : q(t), n(i) {}
	template<typename U>	// template method
	U blab(U u, T t) { return (n.Value() + q.Value()) * u / t; }
	void Show() const { q.show(); n.show(); }
};
