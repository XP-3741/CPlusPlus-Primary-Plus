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

// Brass ��� BrassPlus �඼���� ViewAcct() �� Withdraw()����
//	�� BrassPlus ����� Brass �������Щ��������Ϊ�ǲ�ͬ��
//	���� ViewAcct() ԭ�ͱ�������2�������ķ�������
//	����汾���޶���ΪBrass::ViewAcct(),������汾���޶���ΪBrassPlus::ViewAcct()
//	����ʹ��ʹ�ö���������ȷ��ʹ���ĸ��汾:
//		Brass dom;
//		BrassPlus dot;
//		dom.ViewAcct();
//		dot.ViewAcct();
//	ͬ��,Withdraw()Ҳ��2���汾,һ����Brass����ʹ��,��һ����BrassPlus����ʹ��

// Brass��������ViewAcct()��Withdraw()ʱʹ�����¹ؼ���virtual
// ��Щ��������Ϊ �鷽��(virtual method)
//	���������ͨ�����û�ָ������Ƕ�����õ�,����ȷ��ʹ����һ�ַ���
//	���û��ʹ�ùؼ���virtual
//		���򽫸����������ͻ�ָ������ѡ�񷽷�
//	���ʹ����virtual
//		���򽫸������û�ָ��ָ��Ķ����������ѡ�񷽷�
//			��� ViewAcct() �������,��������Ϊ����:
//				Brass dom("Dominic Banker", 11224, 4183.45);
//				BrassPlus dot("Dorothy Banker", 12118, 2592.00);
//				Brass & b1_ref = dom;
//				Brass & b2_ref = dot;
//				b1_ref.ViewAcct();		// use Brass::ViewAcct()
//				b2_ref.ViewAcct();		// use Brass::ViewAcct()
//				���ñ���������ΪBrass,����ѡ�� Brasc::ViewAccoimt()
//				ʹ�� Brass ���������ʱ,��Ϊ���������
//			��� ViewAcct() �����,����Ϊ����:
//				Brass dom("Dominic Banker", 11224, 4183.45);
//				BrassPlus dot("Dorothy Banker", 12118, 2592.00);
//				Brass & b1_ref = dom;
//				Brass & b2_ref = dot;
//				b1_ref.ViewAcct();		// use Brass::ViewAcct()
//				b2_ref.ViewAcct();		// use BrassPlus::ViewAcct()
//				���������������Ͷ��� Brass,�� b2_ref ���õ���һ�� BrassPlus ����
//				����ʹ�õ��� BrassPlus::ViewAcct()
//				ʹ�� Brass ָ���������ʱ,��Ϊ������
//
