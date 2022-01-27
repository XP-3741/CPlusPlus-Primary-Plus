// tempmemb.h -- template members
#pragma once
#include<iostream>
using std::cout;
using std::endl;

/* 类内定义 */
//template<typename T>
//class beta
//{
//private:
//	template<typename V>	// nest template class member
//	class hold
//	{
//	private:
//		V val;
//	public:
//		hold(V v = 0) :val(v) {}
//		void show() const { cout << val << endl; }
//		V Value() const { return val; }
//	};
//	hold<T> q;		// template object	
//	hold<int> n;	// template object
//public:
//	beta(T t, int i) : q(t), n(i) {}
//	template<typename U>	// template method
//	U blab(U u, T t) { return (n.Value() + q.Value()) * u / t; }
//	void Show() const { q.show(); n.show(); }
//};

/* 类外定义 */
template<typename T>
class beta
{
private:
	template<typename V>	// nest template class member
	class hold;
	hold<T> q;		// template object	
	hold<int> n;	// template object
public:
	beta(T t, int i) : q(t), n(i) {}
	template<typename U>	// template method
	U blab(U u, T t);
	void Show() const { q.show(); n.show(); }
};

// memeber definition
template<typename T>
	template<typename V>
	class beta<T>::hold
	{
	private:
		V val;
	public:
		hold(V v = 0) :val(v) {}
		void show() const { cout << val << endl; }
		V Value() const { return val; }
	};

// memeber definition
	template<typename T>
		template<typename U>
		U beta<T>::blab(U u, T t)
		{
			return (n.Value() + q.Value()) * u / t;
		}