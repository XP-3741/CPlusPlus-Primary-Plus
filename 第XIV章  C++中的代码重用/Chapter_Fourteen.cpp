#include<valarray>
#include<iostream>
#include"studentc.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student& sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main()
{
	// valarray ����
	//	��������ڴ�����ֵ(������������Ե���)
	//	valarray ������Ϊһ��ģ����,�Ա��ܹ�����ͬ����������
	//	ģ����������ζ����������ʱ,����ָ���������������
	//	���,ʹ�� valarray ��������һ������ʱ
	//	���ڱ�ʶ�� valarray �������һ�Լ�����,�������а�������Ҫ����������
	std::valarray<int> q_values;		// an array of int
	std::valarray<double> weights;		// an array of double
	// �����Ǽ���ʹ�ù��캯��������:
	double gpa[5] = { 3.1, 3.5, 3.8, 2.9, 3.3 };
	std::valarray<double> v1;		// an array of double, size 0
	std::valarray<int> v2(8);		// an array of 8 int elements
	std::valarray<int> v3(10, 8);	// an array of 8 int elements
									// each set to 10
	std::valarray<double>v4(gpa, 4);// an array of 4 elements
						// initialized to the first 4 elements of gpa
	// ��C++11��,Ҳ����ʹ�ó�ʼ���б�
	std::valarray<int> v5 = { 20, 32, 17, 9 };	// C++11
	// ������������һЩ����
	//	- operator[]()	���ʸ���Ԫ��
	//	- size()		���ذ�����Ԫ����
	//	- sum()			�������е�Ԫ���ܺ�
	//	- max()			��������Ԫ��
	//	- min()			������С��Ԫ��

	// Student ������
	//	��ȷ�� Student �����Ƽƻ�:
	//		string�����ʾ������valarray<double>��ʾ����
	//	����ѧ����������֮�䲻�� is-a ģ��,���Բ��ʺϽ�ѧ������������������
	//	����Ĺ�ϵ�� has-a ,ѧ����������һ�鿼�Է���
	//	ͨ��,���ڽ��� has-a ��ϵ��C++���������(����),������һ������������������
	
	// �ӿں�ʵ��
	//	ʹ�ù��м̳�ʱ,����Լ̳нӿ�,���ܻ���ʵ��
	//		(����Ĵ��麯���ṩ�ӿ�,�����ṩʵ��)
	//	��ýӿ��� is-a ��ϵ����ɲ���
	//	���������,����Ի��ʵ��,�����ܻ�ýӿ�
	//	���̳нӿ��� has-a ��ϵ����ɲ���

	// �ؼ��� explicit �÷�:
	//		explicit Student(const std::string& s)
	//				:name(s), scores() {}	
	//		explicit Student(int n)
	//				:name("Nully"), scores(n) {}
	//	������һ���������õĹ��캯���������Ӳ������͵������͵���ʽת������
	//	����ͨ�����Ǻ�����
	//	�����ڶ���,������ʾ����Ԫ�صĸ���,�����������е�ֵ
	//	��˽�һ�����캯������ int �� student ��ת��������û�������
	//	����ʹ�� explicit �ر���ʽת��
	//	���ʡ��:
	//	Student doh("Homer", 10);	// store "Homer", create array of 10 elements
	//	doh = 5;	// reset name to "Nully", reset to empty array of 5 elements
	//	������캯��ʡ�� explicit ,��ʹ�ù��캯������ Student(5)
	//	��5ת��Ϊһ����ʱ Student ����
	//	ʹ���� explicit ,����������Ϊ����������Ǵ����

	// ��Ա��ʼ���б�
	//	�����ʹ�ó�Ա��ʼ���б�
	//	C++Ҫ���ڹ����������������֮ǰ,�ȹ����̳ж�������г�Ա����
	//	���,���ʡ�Գ�ʼ���б�,C++��ʹ�ó�Ա�����������Ĭ�Ϲ��캯��
	// ��ʼ��˳��
	//	����ʼ���б���������Ŀʱ,��Щ��Ŀ����ʼ����˳��Ϊ���Ǳ�������˳��
	//	�����������ڳ�ʼ���б��е�˳��
	//	���������һ����Ա��ֵ��Ϊ��һ����Ա�ĳ�ʼ�����ʽ��һ����
	//	��ʼ��˳��ͷǳ���Ҫ��

	// ʹ�ñ���������Ľӿ�
	//	����������Ľӿڲ��ǹ��е�,���������෽����ʹ����
	
	// Student(Studenti) �����
	Student ada[pupils] =
	{ Student(quizzes),Student(quizzes), Student(quizzes) };

	int i;
	for (i = 0; i < pupils; i++)
		set(ada[i], quizzes);
	cout << "\nStudent List:\n";
	for (i = 0; i < pupils; i++)
		cout << ada[i].Name() << endl;
	cout << "\nResults:";
	for (i = 0; i < pupils; i++)
	{
		cout << endl << ada[i];
		cout << "average: " << ada[i].Average() << endl;
	}
	cout << "Done.\n";
	// cin.get();

	// ˽�м̳�
	//	C++����һ��ʵ�� has-a ��ϵ��;��----˽�м̳�
	//	ʹ��˽�м̳�,����Ĺ��г�Ա�ͱ�����Ա������Ϊ�������˽�г�Ա
	//	����ζ����෽���������Ϊ����������нӿڵ�һ����
	//	��������������ĳ�Ա������ʹ������
	// 
	//	ʹ�ù��м̳�,����Ĺ��з�������Ϊ������Ĺ��з���
	//		��֮,�����ཫ�̳л���Ľӿ�:���� is-a ��ϵ��һ����
	//	ʹ��˽�м̳�,����Ĺ��з�������Ϊ�������˽�з���
	//		��֮,�����಻�̳л���Ľӿ�
	//		����ӱ����������п�����,���ֲ���ȫ�̳��� has-a ��ϵ��һ����
	// 
	//	ʹ��˽�м̳�,�ཫ�̳�ʵ��
	// 
	//	������������Ϊһ�������ĳ�Ա������ӵ�����
	//	��˽�м̳н�������Ϊһ��δ�����ļ̳ж�����ӵ�����
	//	������ �Ӷ���(subobject)����ʾͨ���̳л������ӵĶ���
	//	���,˽�м̳��ṩ�������������ͬ:���ʵ��,������ýӿ�
	//

	return 0;
}

void set(Student& sa, int n)
{
	cout << "Please enter the student's name: ";
	getline(cin, sa);
	cout << "Please enter " << n << " quiz scores:\n";
	for (int i = 0; i < n; i++)
		cin >> sa[i];
	while (cin.get() != '\n')
		continue;
}