#include"studenti.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

// public methods

// ���ʻ���ķ���
//	˽�м̳�ʹ���ܹ�ʹ���������������������������û���ķ���
//	��֮,ʹ�ð���ʱ��ʹ�ö����������÷���
//	������˽�м̳�ʱ��ʹ���������������������������÷���
double Studenti::Averagr() const
{
	if (ArrayDb::size() > 0)
		return ArrayDb::sum() / ArrayDb::size();
	else
		return 0;
}

// ���ʻ������
//	ʹ�������������������Է��ʻ���ķ���
//	Student ��İ����汾ʵ����Name()����,������ string �����Ա name
//	��ʹ��˽�м̳�ʱ,�� string ����û������
//	Ҫʹ��ǿ������ת��
//	���� Studneti ���Ǵ� string ������������
//	��˿���ͨ��ǿ������ת���� Student ����ת��Ϊ stirng ����
//	���Ϊ�̳ж����� string ����
//	Ϊ������ù��캯�������µĶ���,��ʹ��ǿ������ת��������һ������
//	������ָ�����ڵ��ø÷����� Studneti �����м̳ж����� string ����
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

// ���ʻ������Ԫ����
//  ��������ʾ���޶����������ʺ�����Ԫ����,��Ϊ��Ԫ��������
//  Ȼ��,����ͨ����ʾ��ת��Ϊ������������ȷ�ĺ���
//  ��ʾ�ؽ� stu ת��Ϊ string ��������,�������ú��� operator<<(ostream&, const string&)
//  ���� stu �����Զ�ת��Ϊ string ����
//  ����ԭ������,��˽�м̳���,�ڲ�������ʽ����ת���������
//  ���ܽ�ָ������������û�ָ�븳���������û�ָ��
//  Ȼ��,��ʹ�������ʹ�õ��ǹ��м̳�,Ҳ����ʹ����ʽ����ת��
//  ԭ��֮һ��,�������������ת��,�������뽫����Ԫ����ԭ��ƥ��,�Ӷ����µݹ����
//      os << stu;
//  ��һ��ԭ����,���������ʹ�õ��Ƕ��ؼ̳�
//  �������޷�ȷ��Ӧת�����ĸ�����,����������඼�ṩ�˺��� operator<<()
// use string version of operator<<()
ostream& operator<<(ostream& os, const Studenti& stu)
{
    os << "Scores for " << (const string&)stu << ":\n";
    stu.arr_out(os);    // use private method for scores
    return os;
}