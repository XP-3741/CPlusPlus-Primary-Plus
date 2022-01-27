#pragma once

#include<iostream>
#include"stacktp.h"

template<template<typename T> class Thing>
class Crab
{
private:
	Thing<int>s1;
	Thing<double>s2;
public:
	Crab() {};
	// assumes the thing class has push() and pop() members
	bool push(int a, double x) { return s1.push(a) && s2.push(x); }
	bool pop(int & a, double & x) { return s1.pop(a) && s2.pop(x); }
};
