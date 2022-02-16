#include<iostream>
#include<cstdlib>		// abort(),exit() EXIT_FAILURE
#include<cfloat>		// (or float.h) for DBL_MAX
#include<cmath>			// or math.h, unix users may need -lm flag
#include<string>
#include<exception>
#include<new>			// for bad_alloc
#include"exc_mean.h"

void error1_cpp();
double hmean(double a, double b);	// abort()测试

void error2_cpp();
bool hmean(double a, double b, double* ans);	// 返回错误信息测试

void error3_cpp();
double hmean_throw(double a, double b);		// 异常机制测试

void error4_cpp();
double hmean_opp(double a, double b);
double gmean_opp(double a, double b);		// 将对象用作异常类型测试

void error5_cpp();
double means(double a, double b);			// throw 和 return 区别测试

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
	// 并非只能拥有友元函数,也可以将类作为友元函数
	// 另外,也可以做更严格的限制,只将特定的成员函数指定为另一个类的友元

	// 友元类
	//	下面语句使 Remote 作为友元类:
	//		friend class Remote;
	//	友元声明可以位于公有、私有或保护部分,其所在位置无关紧要
	// 
	// 友元成员函数
	//	可以选择让特定的类成员称为另一个类的友元,而不必让整个类成为友元
	//  如让 Remote::set_chan()称为 Tv 类的友元的方法是,在 Tv 类声明中将其声明为友元:
	//		class Tv
	//		{
	//			friend void Remote::set_chan(Tv & t, int c);
	//			...
	//		}
	//	然而,要使编译器能够处理这条语句,它必须知道 Remote 的定义
	//	这意味着应将 Remote 的定义和 set_chan() 方法的声明放到 Tv 的定义前面
	//	Remote 的方法提到了 Tv 对象,而这意味着 Tv 定义应当 位于 Remote 定义之前
	//	避开这种循环依赖的方法是,使用 前向声明(forward declaration)
	//	为此,需要在 Remote 定义的前面插入:
	//		class Tv;		// forward declaration
	//	这样,排列次序如下:
	//		class Tv;		// forward declaration
	//		class Remote { ... };
	//		class Tv { ... };
	//	不能如下排列:
	//		class Remote;		// forward declaration
	//		class Tv { ... };
	//		class Remote { ... };
	//	因为在编译器在 Tv 类的声明看到 Remote 的一个方法被声明为 Tv 类的友元之前
	//	应该先看到 Remote 类的声明和 set_chan() 方法的声明
	//	还有一个麻烦,Remote 声明包含了内联代码: void onoff(Tv & t) { t.onoff(); }
	//	由于这将调用 Tv 的一个方法,所以编译器此时必须已经看到了 Tv 类的声明
	//	但正如看到的,该声明位于 Remote 声明的后面
	//	这种问题的解决方法是,使 Remote 声明中只包含方法声明
	//	并将实际的定义放在 Tv 类之后
	//	内联函数的链接性是内部的,这意味着函数定义必须在使用函数的文件中
	//	在 tvfm 的例子中,内联定义位于头文件中
	//	因此在使用函数的文件中包含头文件可确保定义放在正确的地方
	//	也可以将定义放在实现文件中,但必须删除关键字 inline ,这样函数的链接性将是外部的
	//	如果让整个 Remote 类称为友元并不需要向前声明
	//	因为友元语句本身已经指出 Remote 是一个类
	// 
	// 其他友元关系
	//	两者互为友元
	// 共同的友元
	//	需要使用友元的另一种情况是,函数需要访问两个类的私有数据
	//	从逻辑上看,这样的函数应该是每个类的成员函数,但这是不可能的
	//	它可以是一个类的成员,同时是另一个类的友元
	//	但有时将函数作为两个类的友元更合理
	//	例如,假定有一个 Probe 类和一个 Analyzer 类
	//	前者表示某种可编程的测量设备,后者表示某种可编程的分析设备
	//	这两个类都有内部时钟,且希望它们能够同步,则应该包含下述代码行;
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

	// 嵌套类
	//	可以将类声明放在另一个类中
	//	在另一个类声明的类被称为 嵌套类(nested class)
	//	它通过提供新的类型类作用域来避免名称混乱
	//	对类进行嵌套与包含并不同
	//	包含意味着将类对象作为另一个类的成员,而对类进行嵌套不创建类成员,而是定义了一种类型
	//	该类型仅在包含嵌套类声明的类中有效
	//	对类进行嵌套通常是为了帮助实现另一个类,避免名称冲突
	//	Queue 类示例:
	//	class Queue
	//	{
	//	private:
	//		struct Node {Item item; struct Node * next;};
	//		...
	//	};
	//	唯一创建 Node 对象的地方是 enqueue() 方法:
	//	bool Queue::enqueue(const Item & item)
	//	{
	//		if(isfull())
	//			return false;
	//		Node* add = new Node;
	//		add->item = item;
	//		add->next = NULL;
	//		...
	//	}
	//	显示地给 Node 成员赋值,这种工作更适合由构造函数来完成
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
	//	重新编写 enqueue():
	//	bool Queue::enqueue(const Item & item)
	//	{
	//		if(isfull())
	//			return false;
	//		Node* add = new Node(item);
	//		...
	//	}
	//	这使得代码简短且更安全,因为它自动进行初始化,无需程序员记住应该做什么
	//	如在方法文件中定义构造函数,则定义必须指出 Node 类是在 Queue 类中定义的:
	//	Queue::Node::Node(const Item & i) : item(i), next(0) {}
	// 
	// 嵌套类和访问权限
	//	嵌套类的声明位置确定了嵌套类的作用域
	//		即它决定了程序的哪些部分可以创建这种类的对象
	//	其次,和其它类一样,嵌套类的共有部分、保护部分和私有部分控制了对类成员的访问
	// 
	//  -作用域
	//		如果嵌套类是在另一个类的私有部分声明的,则只有后者知道它
	//		如果嵌套类是在另一个类的保护部分声明的,则它对于后者来说是可见的,但是对外部世界则是不可见的
	//			然而,在这种情况中,派生类将知道嵌套类,并可以直接创建这种类型的对象
	//		如果嵌套类是在另一个类的公有部分声明的,则允许后者、后者的派生类以及外部世界去使用它
	//			然而,由于嵌套类的作用域为包含它的类,因此外部世界使用它是,必须使用类限定符
	//   嵌套结构和枚举的作用域与此相同
	//		其实,很多程序员都使用公有枚举来提供可供客户程序员使用的类常数
	//	-访问控制
	//		类声明的位置决定了类的作用域或可见性
	//		类可见后,访问控制规则(公有、保护、私有、友元)将决定程序对嵌套类成员的访问权限
	// 
	// 模板中的嵌套
	//	类QueueTP

	// 异常
	//	 调用 abort()
	//		原型位于头文件 cstdlib(或stdlib.h) 中
	//		其典型实现是向标准错误流(即 cerr 使用的错误流)发送
	//		消息 abnormal program termination(程序异常终止),然后终止程序
	//		他还返回一个随时先而异的值,告诉操作系统(如果程序是由另一个程序调用的,则告诉父进程)
	//		abort()是否刷新文件缓冲区(用于存储读写到文件中的数据的内存区域)取决于实现
	//		如果愿意,也可以使用 exit(),该函数刷新文件缓冲区,但不显示消息
	if (WhichOne == 1)error1_cpp();
	//		注意,在 hmean() 中调用 abort() 函数将直接终止程序,而不是先返回到 main()
	// 
	// 返回错误码
	//		一种比异常终止更灵活的方法是,使用函数的返回值来指出问题
	//		例如, ostream 类的 get(void) 成员通常返回下一个输入字符的 ASCII 码
	//		但到达文件尾时,将返回特殊值 EOF
	//		对 hmean() 来说,这种方法不管用
	//		任何数值都是有效的返回值,因此不存在可用于指出问题的特殊值
	//		在这种情况下,可使用指针参数或引用参数来将值返回给调用程序
	//		并使用函数的返回值来指出成功还是失败
	//		istream 族重载 >> 运算符使用了这种技术的变体
	if (WhichOne == 2)error2_cpp();
		
	// 异常机制
	//	异常提供了将控制权从程序的一个部分传递到另一个部分的途径
	//	对异常的处理有3个组成部分:
	//		- 引发异常
	//		- 使用处理程序捕获异常
	//		- 使用 try 块
	//			程序出现问题时将引发异常
	//			如 error3_cpp() 中的 hmean_throw(),使之引发异常而不是调用 abort() 函数
	//			throw 语句实际上是跳转,即命令程序跳另一条语句
	//			throw 关键字表示引发异常,紧随其后的值(例如字符串或对象)指出了异常的特征
	//		程序使用异常处理程序(exception handler)来捕获异常,异常处理程序位于要处理问题的程序中
	//		catch 关键字表示捕获异常
	//		处理程序以关键字 catch 开头,随后是位于括号中的类型声明
	//		它指出异常处理程序要响应的异常类型
	//		然后是一个用花括号括起来的代码块,指出要采取的措施
	//		catch 关键字和异常类型用作标签,指出当异常发生时,程序应跳到这个位置执行
	//		异常处理程序也被称为 catch 块
	//		try 块标识其中特定的异常可能被激活的代码块,它后面更着一个或多个 catch 块
	//		try 块是由关键字 try 指示的
	//		关键字 try 后面是一个由花括号括起的代码块,表明需要注意这些代码引发的异常
	if (WhichOne == 3)error3_cpp();
	//		执行 throw 语句类似于执行返回语句,因为它也将终止函数的执行
	//		但 throw 不是讲控制权返回给调用程序,而是导致程序沿函数调用序列后退
	//		直到找到包含 try 块的函数
	//		另外,在这个例子中, throw 将程序控制权返回给 error3_cpp()
	//		程序将在 error3_cpp() 中寻找与引发的异常类型匹配的异常处理程序(位于 try 块后面)
	//		catch 块点类似于函数定义,但并不是函数定义
	//		关键字 catch 表明这是一个处理程序,而 char* 则表明该处理程序与字符串异常匹配
	//		s与函数参数定义极其类似,一位内匹配的引发将被赋给s
	//		另外,当异常与该处理程序匹配时,程序将执行括号中的代码
	//		执行完 try 块的语句后,如果没有引发任何异常,则程序跳过 try 块后面的 catch 块
	//		直接执行处理程序后面的第一条语句
	//		如果函数引发了异常,而没有 try 块或没有匹配的处理程序
	//		在默认情况下,程序最终将调用 abort() 函数,但可以修改这种行为
	// 
	// 将对象用作异常类型
	//		通常,引发异常的函数将传递一个对象
	//		这样做的优点之一是,可以使用不同的异常类型来区分不同函数在不同情况下引发的异常
	//		另外,对象可以携带信息,程序员可以更具这些信息来确定引发异常的原因
	//		同时,catch 块可以根据这些信息来决定采取什么样的措施
	if (WhichOne == 4)error4_cpp();
	//		C++11 只吃一种特殊的异常规范:使用新增的关键字 noexcept 指出函数不会引发异常"
	//		double marn() noexcept;
	//		通过使用这个关键字,编写函数的程序员相当于做出了承若
	// 
	// 栈解退
	//		假设 try 块没有直接调用引发异常的函数,而是调用了对引发异常的函数进行调用的函数
	//		则程序流程将从引发异常的函数跳到包含 try 块和处理程序的函数,这涉及到栈解退
	//		
	//		首先看一看 C++ 通常是如何处理函数调用和返回的
	//		C++通常通过将信息放到栈中来处理函数调用
	//		具体地说,程序将调用函数的指令的地址(返回地址)放到栈中
	//		当被调用的函数执行完毕后,程序将使用该地址来确定从哪里开始继续执行
	//		另外,函数调用将函数参数放到栈中
	//		在栈中,这些函数参数被视为自动变量
	//		如果被调用的函数创建新的自动变量,则这些变量也将被添加到栈中
	//		如果被调用的函数调用了另一个函数,则后者的信息将被添加到栈中,以此类推
	//		当函数结束时,程序流程将跳到该函数被调用时存储的地址处,同时栈顶的元素被释放
	//		因此,函数通常都返回到调用它的函数,以此类推
	//		同时每个函数都在结束时释放其自动变量
	//		如果自动变量是类对象,则类的析构函数(如果有的话)将被调用
	//		现在假设函数由于出现异常(而不是由于返回)而终止
	//		则程序也将释放栈中的内存,但不会在释放栈的第一个返回地址后停止
	//		而是继续释放,直到找到一个位于 try 块中的返回地址
	//		随后,控制权将转到块尾的异常处理程序,而不是函数调用后面的第一条语句
	//		这个过程被称为 栈解退
	//		引发机制的一个非常重要的特性是,和函数返回一样,对于栈中的自动类对象
	//		类的析构函数将被调用
	//		然而,函数返回仅仅处理该函数放在栈中的对象,而 throw 语句则处理 try 块和 throw 之前
	//		整个函数调用序列放在栈中的对象
	//		如果没有栈解退这种特性,则引发异常后,对于中间函数调用放在栈中的自动类对象
	//		其析构函数不会被调用
	if (WhichOne == 5)error5_cpp();
	//		当不知道被调用的函数可能引发哪些异常
	//		在这种情况下,仍能够捕捉异常,即使不知道异常的类型
	//		方法是使用省略号来表示异常类型
	//		从而捕捉任何异常
	//		catch(...)
	//		可将其放在所有异常 catch 块的后面
	//		类似于 switch 中的 default
	// 
	//  exception 类
	//		较新的C++编译器将异常合并到语言中
	//		例如,为支持该语言,exception 头文件定义了 exception 类
	//		有一个名为 what() 的虚拟成员函数,它返回一个字符串
	//		该字符串的特征随实现而异
	//		然而,由于这是一个虚方法,因此可以从 exception 派生而来的类中重新定义
	//		C++库定义了很多基于 exception 的异常类型
	//			1.stdexcept 异常类
	//			 头文件 stdexcept 定义了其他几个异常类
	//			 首先,该文件定义了 logic_error 和 runtime_error 类
	//			 它们都以公有方式 exception 派生而来(P632)
	//				logic_error 的派生类:
	//					异常 invalid_argument 指出函数传递了一个意料之外的值
	//					异常 length_error 指出没有足够的空间来执行所需要的操作
	//					异常 out_of_bounds 通常用于指示索引错误
	//					...
	//				runtime_error 的派生类:
	//					异常 range_error 
	//					异常 overflow_error 
	//					异常 underflow_error 
	//			2.bad_alloc 异常和 new
	//				对于使用 new 导致的内存分配问题,C++的最新处理方式是让 new 引发 bad_alloc 异常
	//				头文件 new 包含 bad_alloc 类声明
	//				它从 exception 类公有派生而来的
	if (WhichOne == 6)newexcp_cpp();
	//			3.空指针和 new
	//				C++标准提供了一个再失败时返回空指针的 new
	//				int * pi = new (std::nothrow) int;
	//				int * pa = new (std::nowthrow) int[500];
	//				则可将 newexcp_cpp() 核心代码改成如下:
	//				pb = new (std::nothrow) Big[13000];
	//				if(pb == 0)
	//				{
	//					cout << "Caught not allocate memory. Bye.\n";
	//					exit(EXIT_FAILURE);
	//				}
	// 
	// 异常、类和继承
	//		异常、类和继承以三种方式相互关联
	//		首先,可以像标准C++库所做的那样,从一个异常类派生出另一个
	//		其次,可以在类定义中嵌套异常类声明来组合异常
	//		第三,这种嵌套声明本身可被继承,还可用作基类
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
			catch (bad_hmean& bg)		// bg 指向的是发生异常对象的副本
			{							// 使用引用的目的:基类引用可以执行派生类对象
										// 引发的异常对象将被第一个与之匹配的 catch 捕捉
										// 这意味着 catch 块的排列顺序应该与派生顺序相反
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
					// 如果 catch 块使用的是 exit(EXIT_FAILURE)而不是 break
					// 则程序将立即终止,用户将看不到下面 d1.show() 的输出
					// 但仍能够看到 d1 调用析构函数的输出
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