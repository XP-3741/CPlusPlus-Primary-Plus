#pragma once

#include<iostream>
#include<string>
#include<valarray>

class Student
{
private:
	typedef std::valarray<double> ArrayDb;
	std::string name;		// contained object
	ArrayDb scores;			// contained object
	// private method fpr scores output
	std::ostream& arr_out(std::ostream& os) const;
public:
	Student() :name("Null Student"), scores() {}
	explicit Student(const std::string& s)
		:name(s), scores() {}
	explicit Student(int n) : name("Nully"), scores(n) {}
	Student(const std::string& s, int n)
		:name(s), scores(n) {}
	Student(const std::string& s, const ArrayDb& a)
		:name(s), scores(a) {}
	Student(const char* str, const double* pd, int n)
		:name(str), scores(pd, n) {}
	~Student() {}
	double Average() const;
	const std::string& Name() const;
	double& operator[](int i);
	double operator[](int i) const;
// friends
	// input
	friend std::istream& operator>>(std::istream& is, Student& stu);
														// 1 word
	friend std::istream& getline(std::istream& is, Student& stu);
														// 1 line
	// output
	friend std::ostream& operator<<(std::ostream& os, const Student& stu);
};
// 因为 stu.name 是一个 string 对象,所以他将调用函数 operator<<(ostream &, const string &)
// 该函数位于 string 类中
// 注意,operator<<(std::ostream& os, const Student& stu)必须是 Student 类的友元函数
// 这样才能访问 name 成员
// 另一种方法是,在该函数中使用公有方法 Name(),而不是私有数据成员 name
// 同样,该函数也可以使用 valarray 的 << 实现来进行输出
// 不幸的是没有这样的实现
// 因此, Student 类定义了一个私有辅助方法来处理这种问题
//	std::ostream& aarr_out(std::ostream& os) const;
