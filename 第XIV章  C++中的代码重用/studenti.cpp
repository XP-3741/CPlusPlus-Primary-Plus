#include"studenti.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

// public methods

// 访问基类的方法
//	私有继承使得能够使用类名和作用域解析运算符来调用基类的方法
//	总之,使用包含时将使用对象名来调用方法
//	而是用私有继承时将使用类名和作用域解析运算符来调用方法
double Studenti::Averagr() const
{
	if (ArrayDb::size() > 0)
		return ArrayDb::sum() / ArrayDb::size();
	else
		return 0;
}

// 访问基类对象
//	使用作用域解析运算符可以访问基类的方法
//	Student 类的包含版本实现了Name()方法,它返回 string 对象成员 name
//	但使用私有继承时,该 string 对象没有名称
//	要使用强制类型转换
//	由于 Studneti 类是从 string 类派生而来的
//	因此可以通过强制类型转换将 Student 对象转换为 stirng 对象
//	结果为继承而来的 string 对象
//	为避免调用构造函数创建新的对象,可使用强制类型转换来创建一个引用
//	该引用指向用于调用该方法的 Studneti 对象中继承而来的 string 对象
const std::string& Studenti::Name() const
{
	return (const std::string&)*this;
}

double& Studenti::operator[](int i)
{
	return ArrayDb::operator[](i);		// use ArrayDb::operator[]()
}

double Studenti::operator[](int i) const
{
	return ArrayDb::operator[](i);
}

// private method
ostream& Studenti::arr_out(ostream& os) const
{
    int i;
    int lim = ArrayDb::size();
    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
        {
            os << ArrayDb::operator[](i) << " ";
            if (i % 5 == 4)
                os << endl;
        }
        if (i % 5 != 0)
            os << endl;
    }
    else
        os << " empty array ";
    return os;
}

// friends
// use string version of operator>>()
istream& operator>>(istream& is, Studenti& stu)
{
    is >> (string&)stu;
    return is;
}

// use string friend getline(ostream &, const string &)
istream& getline(istream& is, Studenti& stu)
{
    getline(is, (string&)stu);
    return is;
}

// 访问基类的友元函数
//  用类名显示地限定函数名不适合于友元函数,因为友元不属于类
//  然而,可以通过显示的转换为基类来调用正确的函数
//  显示地将 stu 转换为 string 对象引用,进而调用函数 operator<<(ostream&, const string&)
//  引用 stu 不会自动转换为 string 引用
//  根本原因在于,在私有继承中,在不进行显式类型转换的情况下
//  不能将指向派生类的引用或指针赋给基类引用或指针
//  然而,即使这个例子使用的是公有继承,也必须使用显式类型转换
//  原因之一是,如果不适用类型转换,下述代码将与友元函数原型匹配,从而导致递归调用
//      os << stu;
//  另一个原因是,由于这个类使用的是多重继承
//  编译器无法确定应转换成哪个类型,如果两个基类都提供了函数 operator<<()
// use string version of operator<<()
ostream& operator<<(ostream& os, const Studenti& stu)
{
    os << "Scores for " << (const string&)stu << ":\n";
    stu.arr_out(os);    // use private method for scores
    return os;
}