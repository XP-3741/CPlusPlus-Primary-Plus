#pragma once
#include<string>

class Stock
{
private:
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
public:
	//Stock();	// default constructor
	//Stock(long n = 0);
	Stock(const std::string& co = "error", long n = 0, double pr = 0.0);
	~Stock();	// noisy destructor
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show() const;
	const Stock& topval(const Stock& s) const;
};