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
// ����������,���Ч��
// Ȼ��,����ֵ����������
// ��Ϊ����������һ���µ�Time����(sum),����ʾ��������Time����ĺ�
// ���ض���(�����������)����������ĸ���,�����ú�������ʹ��
// Ȼ��,�����������ΪTime&,�����õĽ���sum����
// ������sum�����Ǿֲ�����,�ں�������ʱ�����h��,������ý�ָ��һ�������ڵĶ���
// ʹ�÷�������Time��ζ�ų�����ɾ��sum֮ǰ�������Ŀ���,���ú������õ��ÿ���
// ��Time��ת��Ϊ���صļӷ������������,ֻҪ��Sum()�����Ƹ�Ϊoperator+()��
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