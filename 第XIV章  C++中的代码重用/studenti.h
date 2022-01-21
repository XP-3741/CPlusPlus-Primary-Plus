#pragma once

#include<iostream>
#include<valarray>
#include<string>
// 初始化基类组件
//	要进行私有继承,使用关键字 private
//	实际上 private 是默认值,省略关访问限定符也将导致私有继承
//	Studenti 类应从两个类派生而来,因此声明将列出这两个类
//	使用多个基类的继承被称为 多重继承(multiple inheritance, MI)
//	新的 Studenti 类不需要私有数据,因为两个基类已经提供了所需的所有数据成员
//	包含版本提供了两个被显示命名的对象成员
//	而私有继承提供了两个无名称的子对象成员
class Studenti :private std::string, private std::valarray<double>
{
private:
	typedef std::valarray<double> ArrayDb;
	// private method for scores output
	std::ostream& arr_out(std::ostream& os) const;
public:
	// 隐式地继承组件而不是成员对象将影响代码的编写
	// 因为再也不能使用name和scores来描述对象了
	// 而必须使用用于公有继承的技术
	// 对于继承类,新版本的构造函数将使用成员初始化列表语法
	// 它使用类名而不是成员名来标识构造函数
	Studenti() :std::string("Null Studnet"), ArrayDb() {}
	explicit Studenti(const std::string& s) 
			: std::string(s), ArrayDb() {}
	explicit Studenti(int n) :std::string("Nully"), ArrayDb(n) {}
	Studenti(const std::string& s, int n)
			: std::string(s), ArrayDb(n) {}
	Studenti(const std::string& s, const ArrayDb& a)
			: std::string(s), ArrayDb(a) {}
	Studenti(const char* str, const double* pd, int n)
			: std::string(str), ArrayDb(pd, n) {}
	~Studenti() {}
	double Averagr() const;
	double& operator[](int i);
	double operator[](int i) const;
	const std::string& Name() const;
// friends
	// input
	friend std::istream& operator>>(std::istream& is, Studenti& stu);
	friend std::istream& getline(std::istream& is, Studenti& stu);
	// output
	friend std::ostream& operator<<(std::ostream& os, const Studenti& stu);
};