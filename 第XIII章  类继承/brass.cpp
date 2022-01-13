#include<iostream>
#include"brass.h"

using std::cout;
using std::endl;
using std::string;

// formating stuff
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

// Brass methods
Brass::Brass(const string& s, long an, double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}

void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "Negative deposit not allowed; "
		<< "deposit is cancelled.\n";
	else
		balance += amt;
}

void Brass::Withdraw(double amt)
{
	// set up ###.## format
	format initialState = setFormat();
	precis prec = cout.precision(2);

	if (amt < 0)
		cout << "Withdrawal amount must be positive; "
		<< "Withdrawal canceled.\n";
	else if (amt <= balance)
		balance -= amt;
	else
		cout << "Withdrawal amount of $" << amt
		<< "exceeds your balance.\n"
		<< "Withdrawal canceled.\n";
	restore(initialState, prec);
}

void Brass::ViewAcct() const
{
	// set up ###.## format
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout << "Client: " << fullName << endl;
	cout << "Account Number: " << acctNum << endl;
	cout << "Balance: $" << balance << endl;
	restore(initialState, prec);		// restore original format
}

// BrassPlus Method
BrassPlus::BrassPlus(const string& s, long an, double bal,
	double ml, double r) :Brass(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass& ba, double ml, double r) 
	:Brass(ba)		// use implict copy constructor
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}
// 派生类不能直接访问基类的私有成员,必须使用基类的公有方法才能访问这些数据
// 访问的方式取决于方法,构造函数使用一种技术,而其它成员函数使用另一种技术
// 派生类构造函数在初始化基类私有数据时,采用成员初始化列表语法
// 将基类信息传递给基类构造函数,然后使用构造函数体初始化 BrassPlus 类新增的数据项
// 非构造函数不能使用成员初始化列表语法
//

// redefine how ViewAcct() works
void BrassPlus::ViewAcct() const
{
	// set up ###.## format
	format initialState = setFormat();
	precis prec = cout.precision(2);

	Brass::ViewAcct();		// display base portion
	cout << "Maximun loan: $" << maxLoan << endl;
	cout << "Owed to bank: $" << owesBank << endl;
	cout.precision(3);		// ###.### format
	cout << "Loan Rate: " << 100 * rate << "%\n";
	restore(initialState, prec);
}
// 派生类方法可以调用公有的基类方法
// 换句话说, BrassPlus::ViewAcct()显示新增的 BrassPlus 数据成员
// 并调用基类方法 Brass::ViewAcct() 来显示基类数据成员
// 在派生类中,标准技术是使用作用域解析运算符来调用基类方法
// 如果没有作用域解析运算符,编译器将认为 ViewAcct() 是 BrassPlus::ViewAcct()
// 这将创建不会终止的递归函数
//

// redefine how WirhDraw() works
void BrassPlus::Withdraw(double amt)
{
	// set up ###.## format
	format initialState = setFormat();
	precis prec = cout.precision(2);

	//double bal = Balance;
	double bal = 0;
	if (amt <= bal)
		Brass::Withdraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank = advance * (1.0 + rate);
		cout << "Bank adcance: $" << advance << endl;
		cout << "Finance charge: $" << advance * rate << endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else
		cout << "Credit linit exceeded. Tansaction cancelled.\n";
	restore(initialState, prec);
}

format setFormat()
{
	// set up ###.## format
	return cout.setf(std::ios_base::fixed,
		std::ios_base::floatfield);
}

void restore(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}
