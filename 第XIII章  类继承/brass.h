#pragma once
#include<string>
// Brass Account Class
class Brass
{
private:
	std::string fullName;
	long acctNum;
	double balance;
public:
	Brass(const std::string& s = "Nullbody", long an = -1,
		double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt);
	double Balance() const;
	virtual void ViewAcct() const;
	virtual ~Brass() {}
};

// Brass Plus Account Class
class BrassPlus :public Brass
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string& s = "Nullbody", long an = -1,
		double bal = 0.0, double ml = 500,
		double r = 0.11125);
	BrassPlus(const Brass& ba, double ml = 500,
		double r = 0.11125);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
};

// Brass 类和 BrassPlus 类都声明 ViewAcct() 和 Withdraw()方法
//	但 BrassPlus 对象和 Brass 对象的这些方法的行为是不同的
//	两个 ViewAcct() 原型表明将有2个独立的方法定义
//	基类版本的限定名为Brass::ViewAcct(),派生类版本的限定名为BrassPlus::ViewAcct()
//	程序将使用使用对象类型来确定使用哪个版本:
//		Brass dom;
//		BrassPlus dot;
//		dom.ViewAcct();
//		dot.ViewAcct();
//	同样,Withdraw()也有2个版本,一个供Brass对象使用,另一个供BrassPlus对象使用

// Brass类在声明ViewAcct()和Withdraw()时使用了新关键字virtual
// 这些方法被称为 虚方法(virtual method)
//	如果方法是通过引用或指针而不是对象调用的,它将确定使用哪一种方法
//	如果没有使用关键字virtual
//		程序将根据引用类型或指针类型选择方法
//	如果使用了virtual
//		程序将根据引用或指针指向的对象的类型来选择方法
//			如果 ViewAcct() 不是虚的,则程序的行为如下:
//				Brass dom("Dominic Banker", 11224, 4183.45);
//				BrassPlus dot("Dorothy Banker", 12118, 2592.00);
//				Brass & b1_ref = dom;
//				Brass & b2_ref = dot;
//				b1_ref.ViewAcct();		// use Brass::ViewAcct()
//				b2_ref.ViewAcct();		// use Brass::ViewAcct()
//				引用变量的类型为Brass,所以选择 Brasc::ViewAccoimt()
//				使用 Brass 针代替引用时,行为将与此类似
//			如果 ViewAcct() 是虚的,则行为如下:
//				Brass dom("Dominic Banker", 11224, 4183.45);
//				BrassPlus dot("Dorothy Banker", 12118, 2592.00);
//				Brass & b1_ref = dom;
//				Brass & b2_ref = dot;
//				b1_ref.ViewAcct();		// use Brass::ViewAcct()
//				b2_ref.ViewAcct();		// use BrassPlus::ViewAcct()
//				这里两个引用类型都是 Brass,但 b2_ref 引用的是一个 BrassPlus 对象
//				所以使用的是 BrassPlus::ViewAcct()
//				使用 Brass 指针代替引用时,行为将类似
//
