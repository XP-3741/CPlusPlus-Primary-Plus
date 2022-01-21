#pragma once

#include<iostream>
#include<valarray>
#include<string>
// ��ʼ���������
//	Ҫ����˽�м̳�,ʹ�ùؼ��� private
//	ʵ���� private ��Ĭ��ֵ,ʡ�Թط����޶���Ҳ������˽�м̳�
//	Studenti ��Ӧ����������������,����������г���������
//	ʹ�ö������ļ̳б���Ϊ ���ؼ̳�(multiple inheritance, MI)
//	�µ� Studenti �಻��Ҫ˽������,��Ϊ���������Ѿ��ṩ��������������ݳ�Ա
//	�����汾�ṩ����������ʾ�����Ķ����Ա
//	��˽�м̳��ṩ�����������Ƶ��Ӷ����Ա
class Studenti :private std::string, private std::valarray<double>
{
private:
	typedef std::valarray<double> ArrayDb;
	// private method for scores output
	std::ostream& arr_out(std::ostream& os) const;
public:
	// ��ʽ�ؼ̳���������ǳ�Ա����Ӱ�����ı�д
	// ��Ϊ��Ҳ����ʹ��name��scores������������
	// ������ʹ�����ڹ��м̳еļ���
	// ���ڼ̳���,�°汾�Ĺ��캯����ʹ�ó�Ա��ʼ���б��﷨
	// ��ʹ�����������ǳ�Ա������ʶ���캯��
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