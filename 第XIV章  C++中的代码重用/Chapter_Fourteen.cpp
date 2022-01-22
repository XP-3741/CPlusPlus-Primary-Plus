#include<valarray>
#include<iostream>
#include"studentc.h"
#include"Worker0.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student& sa, int n);

const int pupils = 3;
const int quizzes = 5;

const int LIM = 4;

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
	//  ͨ��,Ӧʹ�ð��������� has-a ��ϵ
	//	���������Ҫ����ԭ����ı�����Ա,����Ҫ���¶����麯��
	//	��Ӧʹ��˽�м̳�
	//
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

	// �����̳�
	//	�����̳����г�����ʱʹ�ùؼ��� protected
	//	ʹ�ñ����̳�ʱ,����Ĺ��г�Ա�ͱ�����Ա������Ϊ������ı�����Ա	
	//	��˽�м̳�һ��,����Ľӿ�����������Ҳ�ǿ��õ�
	//	���ڼ̳в�νṹ֮���ǲ����õ�
	//	������������������һ����ʱ
	//	ʹ��˽�м̳�ʱ,�������ཫ����ʹ�û���Ľӿ�
	//	������Ϊ����Ĺ��з������������н����˽�з���
	//	ʹ�ñ����̳�ʱ,����Ĺ��з����ڵڶ����н�����ܱ�����
	//	��˵��������������ʹ������

	// ʹ��using���¶������Ȩ��
	//	����Ҫ�û���ķ����������������
	//	- ����֮һ�Ƕ���һ��ʹ�øû��෽���������෽��
	//	- ��һ�ַ�����,���������ð�װ����һ������������
	//		��ʹ��һ�� using ������ָ�����������ʹ���ض��Ļ����Ա
	//		��ʹ���õ���˽������
	//		����:
	//		class Studenti :private std::string, private std::valarray<double>
	//		{
	//		...
	//		public:
	//			using std::valarray<double>::min;
	//			using std::valarray<double>::max;
	//			...
	//		};
	//		���� using ����ʹ�� valarray<double>::min �� valarray<double>::max ����
	//		���������� Studenti �Ĺ��з���һ��
	//		cout << "high score: " << ada[i].max() << endl;
	//		ע��,using����ֻ���ó�Ա��----û��Բ���š�����������ͷ�������
	//		using����ֻ�����ڼ̳�,���������ڰ���

	// ���ؼ̳�
	//	�뵥�̳�һ��,����MI��ʾ��Ҳ�� is-a ��ϵ
	//	˽��MI�ͱ���MI���Ա�ʾ has-a ��ϵ
	//	MI���ܻ�����ܶ�������
	//	����������Ҫ������:
	//	- ��������ͬ�Ļ���̳�ͬ������
	//	- �������������ػ�������̳�ͬһ����Ķ��ʵ�� 
	//
	// Worker0 ����
	Waiter bob("Bob Apple", 314L, 5);
	Singer bev("Beverly Hills", 522L, 3);
	Waiter w_temp;
	Singer s_temp;

	Worker* pw[LIM] = { &bob, &bev, &w_temp, &s_temp };

	int i;
	for (i = 2; i < LIM; i++)
		pw[i]->Set();
	for (i = 0; i < LIM; i++)
	{
		pw[i]->Show();
		std::cout << std::endl;
	}
	// std::cin.get();
	// 
	//	�ж���Worker
	//		�������ȴ� Singer �� Waiter ���������� SingingWaiter:
	//		class SingingWaiter : public Singer, public Waiter {...}
	//		��Ϊ Singer �� Waiter ���̳���һ�� Worker ���
	//		�⽫��������,ͨ�����Խ����������ĵ�ַ��������ָ��,�����ڳ��ֶ�����:
	//			SingingWaiter ed;
	//			Worker * pw = &ed;		// ambiguous
	//		ͨ��,���ָ�ֵ���ѻ���ָ������Ϊ����������еĻ������ĵ�ַ
	//		�� ed �а������� Worker ����,��������ַ�ɹ�ѡ��,����Ӧʹ������ת����ָ������:
	//			Worker * pw = (Waiter *)&ed;
	//			Worker * pw = (Singer *)&ed;
	//		�������� Worker ���󿽱����ᵼ����������
	//		Ȼ��������������:Ϊʲô��Ҫ Worker �������������
	//		��������ߺ����� Worker ����һ��,ҲӦֻ����һ��������һ��ID
	//		C++������ؼ̳е�ͬʱ,������һ���¼���----�����(virtual base class),ʹMI��Ϊ����
	// 
	// �����
	//	�����ʹ�ôӶ����(���ǵĻ�����ͬ)�������Ķ���ֻ�̳�һ���������
	//	����:ͨ������������ʹ�ùؼ��� virtual ,����ʹ Worker ������ Singer �� Waiter �������
	//	( virtual �� public �Ĵ����޹ؽ�Ҫ)
	//		class Waiter :virtual public Worker {...};
	//		class Singer :public virtual Worker {...};
	//	Ȼ��,���Խ� SingingWaiter �ඨ��Ϊ;
	//		class SingingWaiter :public Singer,public Waiter {...};
	//	����,SingingWaiter ����ֻ���� Worker �����һ������
	//	�ӱ�����˵,�̳е� Singer �� Waiter ������һ�� Worker ����
	//	�����Ǹ��������Լ��� Worker ���󸱱�
	// 
	// �µĹ��캯������
	//	
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