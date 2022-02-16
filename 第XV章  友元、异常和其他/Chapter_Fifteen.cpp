#include<iostream>
#include<cstdlib>		// abort(),exit() EXIT_FAILURE
#include<cfloat>		// (or float.h) for DBL_MAX
#include<cmath>			// or math.h, unix users may need -lm flag
#include<string>
#include<exception>
#include<new>			// for bad_alloc
#include"exc_mean.h"

void error1_cpp();
double hmean(double a, double b);	// abort()����

void error2_cpp();
bool hmean(double a, double b, double* ans);	// ���ش�����Ϣ����

void error3_cpp();
double hmean_throw(double a, double b);		// �쳣���Ʋ���

void error4_cpp();
double hmean_opp(double a, double b);
double gmean_opp(double a, double b);		// �����������쳣���Ͳ���

void error5_cpp();
double means(double a, double b);			// throw �� return �������

void newexcp_cpp();

class demo
{
private:
	std::string word;
public:
	demo(const std::string& str)
	{
		word = str;
		std::cout << "demo " << word << " created\n";
	}
	~demo()
	{
		std::cout << "demo " << word << " destroyed\n";
	}
	void show() const
	{
		std::cout << "demo " << word << " lives!\n";
	}
};

struct Big
{
	double stuff[20000];
};


int main()
{
	int WhichOne = 0;
	// ����ֻ��ӵ����Ԫ����,Ҳ���Խ�����Ϊ��Ԫ����
	// ����,Ҳ���������ϸ������,ֻ���ض��ĳ�Ա����ָ��Ϊ��һ�������Ԫ

	// ��Ԫ��
	//	�������ʹ Remote ��Ϊ��Ԫ��:
	//		friend class Remote;
	//	��Ԫ��������λ�ڹ��С�˽�л򱣻�����,������λ���޹ؽ�Ҫ
	// 
	// ��Ԫ��Ա����
	//	����ѡ�����ض������Ա��Ϊ��һ�������Ԫ,���������������Ϊ��Ԫ
	//  ���� Remote::set_chan()��Ϊ Tv �����Ԫ�ķ�����,�� Tv �������н�������Ϊ��Ԫ:
	//		class Tv
	//		{
	//			friend void Remote::set_chan(Tv & t, int c);
	//			...
	//		}
	//	Ȼ��,Ҫʹ�������ܹ������������,������֪�� Remote �Ķ���
	//	����ζ��Ӧ�� Remote �Ķ���� set_chan() �����������ŵ� Tv �Ķ���ǰ��
	//	Remote �ķ����ᵽ�� Tv ����,������ζ�� Tv ����Ӧ�� λ�� Remote ����֮ǰ
	//	�ܿ�����ѭ�������ķ�����,ʹ�� ǰ������(forward declaration)
	//	Ϊ��,��Ҫ�� Remote �����ǰ�����:
	//		class Tv;		// forward declaration
	//	����,���д�������:
	//		class Tv;		// forward declaration
	//		class Remote { ... };
	//		class Tv { ... };
	//	������������:
	//		class Remote;		// forward declaration
	//		class Tv { ... };
	//		class Remote { ... };
	//	��Ϊ�ڱ������� Tv ����������� Remote ��һ������������Ϊ Tv �����Ԫ֮ǰ
	//	Ӧ���ȿ��� Remote ��������� set_chan() ����������
	//	����һ���鷳,Remote ������������������: void onoff(Tv & t) { t.onoff(); }
	//	�����⽫���� Tv ��һ������,���Ա�������ʱ�����Ѿ������� Tv �������
	//	�����翴����,������λ�� Remote �����ĺ���
	//	��������Ľ��������,ʹ Remote ������ֻ������������
	//	����ʵ�ʵĶ������ Tv ��֮��
	//	�������������������ڲ���,����ζ�ź������������ʹ�ú������ļ���
	//	�� tvfm ��������,��������λ��ͷ�ļ���
	//	�����ʹ�ú������ļ��а���ͷ�ļ���ȷ�����������ȷ�ĵط�
	//	Ҳ���Խ��������ʵ���ļ���,������ɾ���ؼ��� inline ,���������������Խ����ⲿ��
	//	��������� Remote ���Ϊ��Ԫ������Ҫ��ǰ����
	//	��Ϊ��Ԫ��䱾���Ѿ�ָ�� Remote ��һ����
	// 
	// ������Ԫ��ϵ
	//	���߻�Ϊ��Ԫ
	// ��ͬ����Ԫ
	//	��Ҫʹ����Ԫ����һ�������,������Ҫ�����������˽������
	//	���߼��Ͽ�,�����ĺ���Ӧ����ÿ����ĳ�Ա����,�����ǲ����ܵ�
	//	��������һ����ĳ�Ա,ͬʱ����һ�������Ԫ
	//	����ʱ��������Ϊ���������Ԫ������
	//	����,�ٶ���һ�� Probe ���һ�� Analyzer ��
	//	ǰ�߱�ʾĳ�ֿɱ�̵Ĳ����豸,���߱�ʾĳ�ֿɱ�̵ķ����豸
	//	�������඼���ڲ�ʱ��,��ϣ�������ܹ�ͬ��,��Ӧ�ð�������������;
	//	class Analyzer;
	//	class Probe
	//	{
	//		friend void sync(Analyzer & a, const Probe & p);	// sync a to p
	//		friend void sync(Probe & p, const Analyzer & a);	// sync p to a
	//		...
	//	};
	//	class Analyzer
	//	{
	//		friend void sync(Analyzer & a, const Probe & p);	// sync a to p
	//		friend void sync(Probe & p, const Analyzer & a);	// sync p to a
	//		...
	//	};
	//	// define the friend functions
	//	inline void sync(Analyzer & a, const Probe & p)
	//	{
	//		...
	//	}
	//  inline void sync(Probe & p, const Analyzer & a)
	//	{
	//		...
	//	}

	// Ƕ����
	//	���Խ�������������һ������
	//	����һ�����������౻��Ϊ Ƕ����(nested class)
	//	��ͨ���ṩ�µ����������������������ƻ���
	//	�������Ƕ�����������ͬ
	//	������ζ�Ž��������Ϊ��һ����ĳ�Ա,���������Ƕ�ײ��������Ա,���Ƕ�����һ������
	//	�����ͽ��ڰ���Ƕ����������������Ч
	//	�������Ƕ��ͨ����Ϊ�˰���ʵ����һ����,�������Ƴ�ͻ
	//	Queue ��ʾ��:
	//	class Queue
	//	{
	//	private:
	//		struct Node {Item item; struct Node * next;};
	//		...
	//	};
	//	Ψһ���� Node ����ĵط��� enqueue() ����:
	//	bool Queue::enqueue(const Item & item)
	//	{
	//		if(isfull())
	//			return false;
	//		Node* add = new Node;
	//		add->item = item;
	//		add->next = NULL;
	//		...
	//	}
	//	��ʾ�ظ� Node ��Ա��ֵ,���ֹ������ʺ��ɹ��캯�������
	//	class Queue
	//	{
	//		class Node
	//		{
	//		public:
	//			Item item;
	//			Node* next;
	//			Node(const Item & i) :item(i), next(0) {}
	//		};
	//		...
	//	};
	//	���±�д enqueue():
	//	bool Queue::enqueue(const Item & item)
	//	{
	//		if(isfull())
	//			return false;
	//		Node* add = new Node(item);
	//		...
	//	}
	//	��ʹ�ô������Ҹ���ȫ,��Ϊ���Զ����г�ʼ��,�������Ա��סӦ����ʲô
	//	���ڷ����ļ��ж��幹�캯��,�������ָ�� Node ������ Queue ���ж����:
	//	Queue::Node::Node(const Item & i) : item(i), next(0) {}
	// 
	// Ƕ����ͷ���Ȩ��
	//	Ƕ���������λ��ȷ����Ƕ�����������
	//		���������˳������Щ���ֿ��Դ���������Ķ���
	//	���,��������һ��,Ƕ����Ĺ��в��֡��������ֺ�˽�в��ֿ����˶����Ա�ķ���
	// 
	//  -������
	//		���Ƕ����������һ�����˽�в���������,��ֻ�к���֪����
	//		���Ƕ����������һ����ı�������������,�������ں�����˵�ǿɼ���,���Ƕ��ⲿ�������ǲ��ɼ���
	//			Ȼ��,�����������,�����ཫ֪��Ƕ����,������ֱ�Ӵ����������͵Ķ���
	//		���Ƕ����������һ����Ĺ��в���������,��������ߡ����ߵ��������Լ��ⲿ����ȥʹ����
	//			Ȼ��,����Ƕ�����������Ϊ����������,����ⲿ����ʹ������,����ʹ�����޶���
	//   Ƕ�׽ṹ��ö�ٵ������������ͬ
	//		��ʵ,�ܶ����Ա��ʹ�ù���ö�����ṩ�ɹ��ͻ�����Աʹ�õ��ೣ��
	//	-���ʿ���
	//		��������λ�þ���������������ɼ���
	//		��ɼ���,���ʿ��ƹ���(���С�������˽�С���Ԫ)�����������Ƕ�����Ա�ķ���Ȩ��
	// 
	// ģ���е�Ƕ��
	//	��QueueTP

	// �쳣
	//	 ���� abort()
	//		ԭ��λ��ͷ�ļ� cstdlib(��stdlib.h) ��
	//		�����ʵ�������׼������(�� cerr ʹ�õĴ�����)����
	//		��Ϣ abnormal program termination(�����쳣��ֹ),Ȼ����ֹ����
	//		��������һ����ʱ�ȶ����ֵ,���߲���ϵͳ(�������������һ��������õ�,����߸�����)
	//		abort()�Ƿ�ˢ���ļ�������(���ڴ洢��д���ļ��е����ݵ��ڴ�����)ȡ����ʵ��
	//		���Ը��,Ҳ����ʹ�� exit(),�ú���ˢ���ļ�������,������ʾ��Ϣ
	if (WhichOne == 1)error1_cpp();
	//		ע��,�� hmean() �е��� abort() ������ֱ����ֹ����,�������ȷ��ص� main()
	// 
	// ���ش�����
	//		һ�ֱ��쳣��ֹ�����ķ�����,ʹ�ú����ķ���ֵ��ָ������
	//		����, ostream ��� get(void) ��Աͨ��������һ�������ַ��� ASCII ��
	//		�������ļ�βʱ,����������ֵ EOF
	//		�� hmean() ��˵,���ַ���������
	//		�κ���ֵ������Ч�ķ���ֵ,��˲����ڿ�����ָ�����������ֵ
	//		�����������,��ʹ��ָ����������ò�������ֵ���ظ����ó���
	//		��ʹ�ú����ķ���ֵ��ָ���ɹ�����ʧ��
	//		istream ������ >> �����ʹ�������ּ����ı���
	if (WhichOne == 2)error2_cpp();
		
	// �쳣����
	//	�쳣�ṩ�˽�����Ȩ�ӳ����һ�����ִ��ݵ���һ�����ֵ�;��
	//	���쳣�Ĵ�����3����ɲ���:
	//		- �����쳣
	//		- ʹ�ô�����򲶻��쳣
	//		- ʹ�� try ��
	//			�����������ʱ�������쳣
	//			�� error3_cpp() �е� hmean_throw(),ʹ֮�����쳣�����ǵ��� abort() ����
	//			throw ���ʵ��������ת,�������������һ�����
	//			throw �ؼ��ֱ�ʾ�����쳣,��������ֵ(�����ַ��������)ָ�����쳣������
	//		����ʹ���쳣�������(exception handler)�������쳣,�쳣�������λ��Ҫ��������ĳ�����
	//		catch �ؼ��ֱ�ʾ�����쳣
	//		��������Թؼ��� catch ��ͷ,�����λ�������е���������
	//		��ָ���쳣�������Ҫ��Ӧ���쳣����
	//		Ȼ����һ���û������������Ĵ����,ָ��Ҫ��ȡ�Ĵ�ʩ
	//		catch �ؼ��ֺ��쳣����������ǩ,ָ�����쳣����ʱ,����Ӧ�������λ��ִ��
	//		�쳣�������Ҳ����Ϊ catch ��
	//		try ���ʶ�����ض����쳣���ܱ�����Ĵ����,���������һ������ catch ��
	//		try �����ɹؼ��� try ָʾ��
	//		�ؼ��� try ������һ���ɻ���������Ĵ����,������Ҫע����Щ�����������쳣
	if (WhichOne == 3)error3_cpp();
	//		ִ�� throw ���������ִ�з������,��Ϊ��Ҳ����ֹ������ִ��
	//		�� throw ���ǽ�����Ȩ���ظ����ó���,���ǵ��³����غ����������к���
	//		ֱ���ҵ����� try ��ĺ���
	//		����,�����������, throw ���������Ȩ���ظ� error3_cpp()
	//		������ error3_cpp() ��Ѱ�����������쳣����ƥ����쳣�������(λ�� try �����)
	//		catch ��������ں�������,�������Ǻ�������
	//		�ؼ��� catch ��������һ���������,�� char* ������ô���������ַ����쳣ƥ��
	//		s�뺯���������弫������,һλ��ƥ���������������s
	//		����,���쳣��ô������ƥ��ʱ,����ִ�������еĴ���
	//		ִ���� try �������,���û�������κ��쳣,��������� try ������ catch ��
	//		ֱ��ִ�д���������ĵ�һ�����
	//		��������������쳣,��û�� try ���û��ƥ��Ĵ������
	//		��Ĭ�������,�������ս����� abort() ����,�������޸�������Ϊ
	// 
	// �����������쳣����
	//		ͨ��,�����쳣�ĺ���������һ������
	//		���������ŵ�֮һ��,����ʹ�ò�ͬ���쳣���������ֲ�ͬ�����ڲ�ͬ������������쳣
	//		����,�������Я����Ϣ,����Ա���Ը�����Щ��Ϣ��ȷ�������쳣��ԭ��
	//		ͬʱ,catch ����Ը�����Щ��Ϣ��������ȡʲô���Ĵ�ʩ
	if (WhichOne == 4)error4_cpp();
	//		C++11 ֻ��һ��������쳣�淶:ʹ�������Ĺؼ��� noexcept ָ���������������쳣"
	//		double marn() noexcept;
	//		ͨ��ʹ������ؼ���,��д�����ĳ���Ա�൱�������˳���
	// 
	// ջ����
	//		���� try ��û��ֱ�ӵ��������쳣�ĺ���,���ǵ����˶������쳣�ĺ������е��õĺ���
	//		��������̽��������쳣�ĺ����������� try ��ʹ������ĺ���,���漰��ջ����
	//		
	//		���ȿ�һ�� C++ ͨ������δ��������úͷ��ص�
	//		C++ͨ��ͨ������Ϣ�ŵ�ջ��������������
	//		�����˵,���򽫵��ú�����ָ��ĵ�ַ(���ص�ַ)�ŵ�ջ��
	//		�������õĺ���ִ����Ϻ�,����ʹ�øõ�ַ��ȷ�������￪ʼ����ִ��
	//		����,�������ý����������ŵ�ջ��
	//		��ջ��,��Щ������������Ϊ�Զ�����
	//		��������õĺ��������µ��Զ�����,����Щ����Ҳ������ӵ�ջ��
	//		��������õĺ�����������һ������,����ߵ���Ϣ������ӵ�ջ��,�Դ�����
	//		����������ʱ,�������̽������ú���������ʱ�洢�ĵ�ַ��,ͬʱջ����Ԫ�ر��ͷ�
	//		���,����ͨ�������ص��������ĺ���,�Դ�����
	//		ͬʱÿ���������ڽ���ʱ�ͷ����Զ�����
	//		����Զ������������,�������������(����еĻ�)��������
	//		���ڼ��躯�����ڳ����쳣(���������ڷ���)����ֹ
	//		�����Ҳ���ͷ�ջ�е��ڴ�,���������ͷ�ջ�ĵ�һ�����ص�ַ��ֹͣ
	//		���Ǽ����ͷ�,ֱ���ҵ�һ��λ�� try ���еķ��ص�ַ
	//		���,����Ȩ��ת����β���쳣�������,�����Ǻ������ú���ĵ�һ�����
	//		������̱���Ϊ ջ����
	//		�������Ƶ�һ���ǳ���Ҫ��������,�ͺ�������һ��,����ջ�е��Զ������
	//		�������������������
	//		Ȼ��,�������ؽ�������ú�������ջ�еĶ���,�� throw ������� try ��� throw ֮ǰ
	//		���������������з���ջ�еĶ���
	//		���û��ջ������������,�������쳣��,�����м亯�����÷���ջ�е��Զ������
	//		�������������ᱻ����
	if (WhichOne == 5)error5_cpp();
	//		����֪�������õĺ�������������Щ�쳣
	//		�����������,���ܹ���׽�쳣,��ʹ��֪���쳣������
	//		������ʹ��ʡ�Ժ�����ʾ�쳣����
	//		�Ӷ���׽�κ��쳣
	//		catch(...)
	//		�ɽ�����������쳣 catch ��ĺ���
	//		������ switch �е� default
	// 
	//  exception ��
	//		���µ�C++���������쳣�ϲ���������
	//		����,Ϊ֧�ָ�����,exception ͷ�ļ������� exception ��
	//		��һ����Ϊ what() �������Ա����,������һ���ַ���
	//		���ַ�����������ʵ�ֶ���
	//		Ȼ��,��������һ���鷽��,��˿��Դ� exception �����������������¶���
	//		C++�ⶨ���˺ܶ���� exception ���쳣����
	//			1.stdexcept �쳣��
	//			 ͷ�ļ� stdexcept ���������������쳣��
	//			 ����,���ļ������� logic_error �� runtime_error ��
	//			 ���Ƕ��Թ��з�ʽ exception ��������(P632)
	//				logic_error ��������:
	//					�쳣 invalid_argument ָ������������һ������֮���ֵ
	//					�쳣 length_error ָ��û���㹻�Ŀռ���ִ������Ҫ�Ĳ���
	//					�쳣 out_of_bounds ͨ������ָʾ��������
	//					...
	//				runtime_error ��������:
	//					�쳣 range_error 
	//					�쳣 overflow_error 
	//					�쳣 underflow_error 
	//			2.bad_alloc �쳣�� new
	//				����ʹ�� new ���µ��ڴ��������,C++�����´���ʽ���� new ���� bad_alloc �쳣
	//				ͷ�ļ� new ���� bad_alloc ������
	//				���� exception �๫������������
	if (WhichOne == 6)newexcp_cpp();
	//			3.��ָ��� new
	//				C++��׼�ṩ��һ����ʧ��ʱ���ؿ�ָ��� new
	//				int * pi = new (std::nothrow) int;
	//				int * pa = new (std::nowthrow) int[500];
	//				��ɽ� newexcp_cpp() ���Ĵ���ĳ�����:
	//				pb = new (std::nothrow) Big[13000];
	//				if(pb == 0)
	//				{
	//					cout << "Caught not allocate memory. Bye.\n";
	//					exit(EXIT_FAILURE);
	//				}
	// 
	// �쳣����ͼ̳�
	//		�쳣����ͼ̳������ַ�ʽ�໥����
	//		����,�������׼C++������������,��һ���쳣����������һ��
	//		���,�������ඨ����Ƕ���쳣������������쳣
	//		����,����Ƕ����������ɱ��̳�,������������
	//

	return 0;
}

// error1.cpp
void error1_cpp()
{
	double x, y, z;
	std::cout << "Enter two numbers: ";
	while (std::cin >> x >> y)
	{
		z = hmean(x, y);
		std::cout << "Harmonic mean of " << x << " and " << y
			<< " is " << z << std::endl;
		std::cout << "Enter next set of numbers <q to quit>: ";
	}
	std::cout << "Bye!\n";
}
double hmean(double a, double b)
{
	if (a == -b)
	{
		std::cout << "untenable arguments to hmean()\n";
		std::abort();
	}
	return 2.0 * a * b / (a + b);
}

// error2.cpp
void error2_cpp()
{
	double x, y, z;
	std::cout << "Enter two numbers: ";
	while (std::cin >> x >> y)
	{
		if (hmean(x, y, &z))
			std::cout << "Harmonic mean of " << x << " and " << y
			<< " is " << z << std::endl;
		else
			std::cout << "One value should not be the negative "
			<< "of the other - try again.\n";
		std::cout << "Enter next set of numbers <q to quit>: ";
	}
	std::cout << "Bye!\n";
}
bool hmean(double a, double b,double * ans)
{
	if (a == -b)
	{
		*ans = DBL_MAX;
		return false;
	}
	else {
		*ans = 2.0 * a * b / (a + b);
		return true;
	}
}

// error3.cpp
void error3_cpp()
{
	double x, y, z;

	std::cout << "Enter two numbers: ";
	while (std::cin >> x >> y)
	{
		try {							// start of try block
			z = hmean_throw(x, y);
		}								// end of try block
		catch (const char* s)			// start of exception handler
		{
			std::cout << s << std::endl;
			std::cout << "Enter a new pair of numbers: ";
			continue;
		}								// end of handler
		std::cout << "Harmonic mean of " << x << " and " << y
			<< " is " << z << std::endl;
		std::cout << "Enter next set of numbers <q to quit>: ";
	}
	std::cout << "Bye!\n";
}
double hmean_throw(double a, double b)
{
	if (a = -b)
		throw"bad hmean() arguments: a = -b not allowed";
	return 2.0 * a * b / (a + b);
}

// error4.cpp
void error4_cpp()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;

	cout << "Enter two numbers: ";
	while (cin >> x >> y)
	{
		try {						// start of try block
			z = hmean_opp(x, y);
			cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << endl;
			cout << "Geometric mean of " << x << " and " << y
				<< " is " << gmean_opp(x, y) << endl;
			cout << "Enter next set of numbers <q to quit>: ";
		}// end of try block
		catch (bad_hmean& bg)		// start of catch block
		{
			bg.mesg();
			cout << "Try again.\n";
			continue;
		}
		catch (bad_gmean& hg)
		{
			cout << hg.mesg();
			cout << "Values used: " << hg.v1 << ", "
				<< hg.v2 << endl;
			cout << "Sorry, you don't get to play any more.\n";
			break;
		}// end of catch block
	}
	cout << "Bye!\n";
}
double hmean_opp(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a, b);
	return 2.0 * a * b / (a + b);
}
double gmean_opp(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return std::sqrt(a * b);
}

// error5.cpp
void error5_cpp()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;
	{
		demo d1("found in block in error5_cpp()");
		cout << "Enter two numbers: ";
		while (cin >> x >> y)
		{
			try {
				z = means(x, y);
				cout << "The mean mean of " << x << " and " << y
					<< " is " << z << endl;
				cout << "Enter next pair: ";
			}
			catch (bad_hmean& bg)		// bg ָ����Ƿ����쳣����ĸ���
			{							// ʹ�����õ�Ŀ��:�������ÿ���ִ�����������
										// �������쳣���󽫱���һ����֮ƥ��� catch ��׽
										// ����ζ�� catch �������˳��Ӧ��������˳���෴
				bg.mesg();
				cout << "Try again.\n";
				continue;
			}
			catch (bad_gmean& hg)
			{
				cout << hg.mesg();
				cout << "Values used: " << hg.v1 << ", "
					<< hg.v2 << endl;
				cout << "Sorry, you don't get to play any more.\n";
				break;
					// ��� catch ��ʹ�õ��� exit(EXIT_FAILURE)������ break
					// �����������ֹ,�û������������� d1.show() �����
					// �����ܹ����� d1 �����������������
			}
			catch (...)
			{
				cout << "DEFAULT";
			}
		}
		d1.show();
	}
	cout << "Bye!\n";
}

double means(double a, double b)
{
	double am, hm, gm;
	demo d2("found in means()");
	am = (a + b) / 2.0;
	try {
		hm = hmean_opp(a, b);
		gm = gmean_opp(a, b);
	}
	catch (bad_hmean& bg)
	{
		bg.mesg();
		std::cout << "Caught in means()\n";
		throw;             // rethrows the exception 
	}
	d2.show();
	return (am + hm + gm) / 3.0;
}

// newexcp.cpp
void newexcp_cpp()
{
	using namespace std;
	Big* pb;
	try {
		cout << "Trying to get a big block of memory:\n";
		pb = new Big[13000];
		cout << "Got past the new request:\n";
	}
	catch (bad_alloc& ba)
	{
		cout << "Caught the exception!\n";
		cout << ba.what() << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Memory successfully allocated\n";
	pb[0].stuff[0] = 4;
	cout << pb[0].stuff[0] << endl;
	delete[] pb;
}