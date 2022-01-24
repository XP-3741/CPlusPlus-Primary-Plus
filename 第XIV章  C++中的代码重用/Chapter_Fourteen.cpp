#include<valarray>
#include<iostream>
#include<cstring>
#include<cstdlib>		// for rand(),srand()
#include<ctime>			// for time()
#include"studentc.h"
#include"Worker0.h"
#include"workermi.h"
#include"stacktp.h"
#include"stcktp1.h"
using std::cin;
using std::cout;
using std::endl;
using std::strchr;

void set(Student& sa, int n);

const int pupils = 3;
const int quizzes = 5;

const int LIM = 4;

const int SIZE = 5;

const int Num = 10;

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
	//	���ڷ������,Ψһ���Գ����ڳ�ʼ���б��еĹ��캯���Ǽ��ǻ��๹�캯��
	//	����Щ���캯��������Ҫ����Ϣ���ݸ������
	//		class A
	//		{
	//			int a;
	//		public:
	//			A(int n = 0) : a(n) {}
	//			... 
	//		};
	//		class B : public A
	//		{
	//			int b;
	//		public:
	//			b(int m = 0,int n = 0) : A(n), b(m) {}
	//			... 
	//		};
	//		class C : public B
	//		{
	//			int c;
	//		public:
	//			A(int q = 0,int m = 0,int n = 0) : B(m,n), c(q) {}
	//			... 
	//		};
	//	C�๹�캯��ֻ�ܵ���B�๹�캯��,��B�๹�캯��ֻ�ܵ���A�๹�캯��
	//	���Worker�������,��������Ϣ�Զ����ݽ���������
	//		SingingWaiter(const Worker & wk, int p = 0, int v = Singer::other)
	//						: Waiter(wk,p), Singer(wk,v) {}		// flawed
	//	���ڵ�������,�Զ�������Ϣʱ,��ͨ��������ͬ��·��(Singer��Waiter)��wk���ݸ�Worker����
	//	Ϊ�����ͻ,C++�ڻ��������ʱ,��ֹ��Ϣͨ���м����Զ����ݸ�����
	//	���<�������캯������ʼ����Աpanache��voice,��wk�����е���Ϣ�����ᴫ�ݸ��Ӷ���Waiter
	//	Ȼ��,�����������ڹ�����������֮ǰ�������������
	//	���������,��������ʹ�� Worker ��Ĭ�Ϲ��캯��
	//	����Ҫ��ʾ�ص���������๹�캯��:
	//		SingingWaiter(const Worker & wk, int p = 0, int v = Singer::other)
	//						: Worker(wk), Waiter(wk,p), Singer(wk,v) {}		// flawed
	//	�����÷��ǺϷ���,���������,����������
	//	�����ڷ������,���ǷǷ���
	//	������м�������.�����ֻ��Ҫ��������Ĭ�Ϲ��캯��,���������ʾ�ص��ø�������ĳ�����캯��
	//
	// SingingWaiter�����
	Worker* lolas[SIZE];
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "w: waiter  s: singer  "
			<< "t: singing waiter  q: quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w':   lolas[ct] = new Waiter;
			break;
		case 's':   lolas[ct] = new Singer;
			break;
		case 't':   lolas[ct] = new SingingWaiter;
			break;
		}
		cin.get();
		lolas[ct]->Set();
	}

	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for (i = 0; i < ct; i++)
		delete lolas[i];
	cout << "Bye.\n";
	// cin.get();
	// cin.get();
	//	C-����ַ������� strchr()
	//	�ú������ز��� choice ָ�����ַ����ַ��� "wstq" �е�һ�γ��ֵĵ�ַ
	//  ���û���������ַ�,�򷵻�NULLָ��

	// ���ʹ�������ͷ������
	//	������ B �������� C �� D �������,ͬʱ�������� X �� Y �ķ������
	//	���� M �Ǵ� C��D��X �� Y ��������
	//	��ô,�� M ���������������ﹲ�̳���һ�� B ���Ӷ���
	//	����ÿһ�������������ȷֱ�̳���һ�� B ���Ӷ���
	//	���,���������� B ���Ӷ���
	// 
	// ������֧��
	//	ʹ�÷������ʱ,�����Ӳ�ͬ��������̳�����������ͬ����Ա
	//	 ��û�������޶�,�����¶�����
	//	����������,��һ��������,���ĳ������������������������,�����޶�ȥʹ��Ҳû����
	//	 �������е�����������ֱ�ӻ����������е�ͬ����

	// ��ģ��
	//	ģ���ṩ����������,���ܹ�����������Ϊ�������ݸ����ܷŽ��������
	//	��ģ�庯��һ��,ģ���������������Ĵ��뿪ͷ:
	//		template <class Type>
	//	�ؼ��� template ���߱�����,��Ҫ����һ��ģ��
	//	�������е������൱�ں����Ĳ����б�
	//	���԰ѹؼ��� class �����Ǳ�����������,�ñ�������������Ϊ��ֵ
	//	�� Type �����Ǹñ���������,��Ϊ���Ͳ���(type parameter)
	//	����� class ������ζ�� Type ������һ����
	//	��ֻ�Ǳ��� Type ��һ��ͨ�õ�����˵����,��ʹ��ģ��ʱ,��ʹ��ʵ�ʵ������滻��
	//	���µ�C++ʵ�����������������ʹ�ò�̫���׻����Ĺؼ��� typename ���� class
	//		template <typename Type>
	//  ͬ��,����ʹ��ģ���Ա�����滻��������෽��
	//	ÿ������ͷ��������ͬ��ģ��������ͷ:
	//		template <class Type>
	//	���轫���޶����� ClassName:: ��Ϊ ClassName<Type>::
	//	������������ж����˷���(��������),�����ʡ��ģ��ǰ׺�����޶���
	//	����ģ�岻�Ǻ���,���ǲ��ܵ�������
	//	ģ��������ض���ģ��ʵ��������һ��ʹ��
	//	Ϊ��,��򵥵ķ������ǽ�����ģ����Ϣ����һ��ͷ�ļ���
	//	����Ҫʹ����Щģ����ļ��а�����ͷ�ļ�
	// 
	// ʹ��ģ����
	//	���ڳ������ģ�岢��������ģ��,����������ʵ����
	Stack<int> kernels;
	Stack<std::string> colonels;
	//	���������� Stack<Type> ģ������������������������������������෽��
	// 
	// ��ȷʹ��ָ��ջ
	//	����֮һ��,�õ��ó����ṩһ��ָ������,����ÿ��ָ�붼ָ��ͬ���ַ���
	// 
	// Stack_P�����
	std::srand(std::time(0));		// randomize rand()
	std::cout << "Please enter stack size: ";
	int stacksize;
	std::cin >> stacksize;
// create an empty stack with stacksize slots
	Stack_P<const char*>st(stacksize);
// in basket
	const char* in[Num] = {
			" 1: Hank Gilgamesh", " 2: Kiki Ishtar",
			" 3: Betty Rocker", " 4: Ian Flagranti",
			" 5: Wolfgang Kibble", " 6: Portia Koop",
			" 7: Joy Almondo", " 8: Xaverie Paprika",
			" 9: Juan Moore", "10: Misha Mache"
	};
// out basket
	const char* out[Num];

	int processed = 0;
	int nextin = 0;
	while (processed < Num)
	{
		if (st.isempty())
			st.push(in[nextin++]);
		else if (st.isfull())
			st.pop(out[processed++]);
		else if (std::rand() % 2 && nextin < Num)	// 50-50 chance
			st.push(in[nextin++]);
		else
			st.pop(out[processed++]);
	}
	for (int i = 0; i < Num; i++)
		cout << out[i] << endl;

	std::cout << "Bye\n";
	// std::cin.get();
	// std::cin.get();
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