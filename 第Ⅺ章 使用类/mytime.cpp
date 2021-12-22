#include<iostream>
#include"mytime.h"

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

/*
Time Time::Sum(const Time& t) const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}*/
// 参数是引用,提高效率
// 然而,返回值不能是引用
// 因为函数将创建一个新的Time对象(sum),来表示另外两个Time对象的和
// 返回对象(如代码所做的)将创建对象的副本,而调用函数可以使用
// 然而,如果返回类型为Time&,则引用的将是sum对象
// 但由于sum对想是局部变量,在函数结束时将被刪除,因此引用将指向一个不存在的对象
// 使用返回类型Time意味着程序将在删除sum之前构造它的拷贝,调用函数将得到该拷贝
// 将Time类转换为重载的加法运算符很容易,只要将Sum()的名称改为operator+()可
Time Time::operator+(const Time& t) const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time Time::operator-(const Time& t) const
{
	Time diff;
	int tot1, tot2;
	tot1 = t.minutes + 60 * t.hours;
	tot2 = minutes + 60 * hours;
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;
	return diff;
}

Time Time::operator*(double mult) const
{
	Time result;
	long totalminutes = hours * mult * 60 + minutes * mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

//void operator<<(std::ostream & os, const Time & t)
//{
//	os << t.hours << " hours,"<< t.minutes << " minutes";
//}
std::ostream & operator<<(std::ostream& os, const Time& t)
{
	os << t.hours << " hours," << t.minutes << " minutes";
	return os;
}


void Time::Show() const
{
	std::cout << hours << "hours, " << minutes << "minutes";
}