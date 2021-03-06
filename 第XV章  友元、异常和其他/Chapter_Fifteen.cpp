#include<iostream>
#include<cstdlib>		// abort(),exit() EXIT_FAILURE
#include<cfloat>		// (or float.h) for DBL_MAX
#include<cmath>			// or math.h, unix users may need -lm flag
#include<string>
#include<exception>
#include<new>			// for bad_alloc
#include<typeinfo>		// for bad_cast
#include"exc_mean.h"
#include"sales.h"
#include"rtti1.h"
#include"rtti2.h"

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

void use_sales_cpp();

void constcast_cpp();

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
	//	其次,和其它类一样,嵌套类的公有部分、保护部分和私有部分控制了对类成员的访问
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
	//		但 throw 不是将控制权返回给调用程序,而是导致程序沿函数调用序列后退
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
	//		C++11 支持一种特殊的异常规范:使用新增的关键字 noexcept 指出函数不会引发异常"
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
	//				C++标准提供了一个在失败时返回空指针的 new
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
	if (WhichOne == 7)use_sales_cpp();
	// 异常合适会迷失方向
	//		P640	未懂
	
	// RTTI
	//		RTTI 是运行阶段类型识别(Runtime Type Identification)的简称
	//		RTTI 旨在为程序在运行阶段确定对象的类型提供一种标准方式
	// RTTI的工作原理
	//		C++有3种支持 RTTI 的元素
	//		- 如果可能的话,dynamic_cast 运算符将使用一个指向基类的指针来生成一个指向派生类的指针
	//		否则,该运算符返回0——空指针
	//		- typeid 运算符返回一个指出对象的类型的值
	//		- type_info 结构存储了有关特定类型的信息
	//		只能将 RTTI 用于包含虚函数的类层次结构,原因在于只有对于
	//		这种类层次结构,才应该将派生类对象的地址赋给基类指针
	//		警告:RTTI只适用于包含虚函数的类
	// 下面详细介绍 RTTI 的这 3 个元素
	//		1.dynamic_cast 运算符
	//			dynamic_cast是最常见的 RTTI 组件
	//			他不能回答"指针指向的是哪类对象"这样的问题
	//			但能够回答"是否可以安全将对象的地址赋给特定类型的指针"这样的问题
	//			假设有下面这样的类层次结构:
	//				class Grand { // has virtual methods };
	//				class Superb : public Grand { ... };
	//				class Magnificent : public Superb { ... };
	//			接下来假设有下面的指针:
	//				Grand* pg = new Grand;
	//				Grand* ps = new Superb;
	//				Grand* pm = new Magnificent;
	//			最后,对于下面的类型转换:
	//				Magnificent* p1 = (Magnificent*) pm;	// #1
	//				Magnificent* p2 = (Magnificent*) pg;	// #2
	//				Superb* p3 = (Magnificent*) pm;			// #3
	//			#1和#3是安全的,#2是不安全的
	//			注意,与问题"指针指向的是哪类对象"相比,问题"类型转换是否安全",更通用也更有用
	//			通常想知道类型的原因在于:知道类型后,就可以知道调用特定的方法是否安全
	//			要调用方法,类型并不一定要完全匹配,而可以是定义了方法的虚函数版本的基类类型
	//			下面的例子说明了这一点
	//			先看一下 dynamic_cast 的语法
	//				Superb* pm = dynamic_cast<Superb*>(pg);
	//			指针 pg 的类型如果可以被安全地转换为 Superb*,运算符返回对象的地址
	//			否则返回一个空指针
	//			通常,如果指向的对象(*pt)的类型为 Type 或者是从 Type 直接或间接
	//			派生而来的类型,则下面的表达式将指针 pt 转换为 Type 类型的指针:
	//				dynamic_cast<Type*>(pt)
	//			否则,结果为0,即空指针
	if (WhichOne == 8)	rtti1_main();
	//			注意:即使编译器支持 RTTI ,在默认情况下,它也可能关闭该特性	
	//			如果该特性被关闭,程序可能仍能够通过编译,但将出现运行阶段的错误
	//			在这种请况下,应查看文档或菜单选项
	//			也可将 dynamic_cast 用作引用,其用法稍微有点不同:
	//			没有与空指针对应的引用值,因此无法使用特殊的引用值来指示失败
	//			当请求不正确时,dynamic_cast 将引发类型为 bad_cast 的异常
	//			这种异常是从 exception 类派生而来的
	//			它在头文件 typeinof 中定义
	//			因此,可以像下面这样使用该运算符,其中 rg 是对 Grand 对象的引用:
	try {
		// Superb& rs = dynamic_cast<Superb&>(rg);
		// ...
	}
	catch (std::bad_cast &) {
		// ...
	}
	//		2.typeid 运算符和 type_info 运算符
	//			typeid 运算符使得能否确定两个对象是否为同种类型
	//			它与 sizeof 有些相像,可以接受两种参数:
	//				- 类名
	//				- 结果为对象的表达式
	//			typeid 运算符返回一个对 type_info 对象的引用
	//			其中, type_info 在头文件 typeinfo(以前为 typeinfo.h)中定义的一个类
	//			type_info 类重载了 == 和 != 运算符,以便可以使用这些运算符来对类型进行比较
	//			例如,如果 pg 指向的是一个 Magnificent 对象
	//			则下述表达式的结果为 bool 值 true,否则为 false:
	//				typeid(Magnificent) == typeid(*pg)
	//			如果 pg 是一个空指针,程序将引发 bad_typeid 的异常
	//			该异常是从 exception 类派生而来的,是在头文件 typeinfo 中声明的
	//			type_info 类的实现随厂商而异,但包含一个 name() 成员
	//			该函数返回一个随实现而异的字符串: 通常(但并非一定)是类的名称
	//			例如,下面的语句显示指针 pg 指向的对象所属的类定义的字符串:
	//				cout << "Now processing type " << typeid(*pg).name() << ".\n";
	if (WhichOne == 9)	rtti2_main();
	//			提示: 如果发现在扩展的 ifelse 语句系列使用了 typeid,
	//				则应考虑是否应该使用虚函数和 denamic_cast
	// 
	//	类型转换运算符
	//		C++ 采用相比 C 更严格地限制允许的类型转换:
	//			- dynamic_cast
	//			- const_cast
	//			- static_cast
	//			- reinterpret_cast
	//		可以根据目的的选择一个合适的运算符,而不是使用通用的类型转换
	//		这指出了进行类型转换的原因.并让编译器能够检查程序的行为是否与设计者想法吻合
	//		1.dynamic_cast 运算符
	//			已经在前面介绍过了
	//			总之,假设 High 和 Low 是两个类,而 ph 和 pl 的类型分别为 High* 和 Low*
	//			则仅当 Low 是 High 的可访问基类(直接或间接)时
	//			下面的语句才将一个 Low* 指针赋给 pl:
	//				pl = dynamic_cast<Low *> ph;
	//			否则,该语句将空指针赋给 pl. 通常,该运算符的语法如下:
	//				dynamic_cast < type-name > (expression)
	//			该运算符用途是,使得能够在类层次结构中进行向上转换
	//			(由于是 is-a 关系,这样的类型转换时安全的),而不允许其他转换
	//		2.const_cast 运算符
	//			用于执行只有一种用途的类型转换,即改变值为 const 或 volatile
	//			其语法与 dynamic_cast 相同;
	//				const_cast < type-name > (expression)
	//			如果类型的其他方面也被修改,则上述类型转换将出错
	//			也就是说,除了 const 或 volatile 特征(有或无)可以不同外
	//			type-name 和 expression 的类型必须相同
	//			再次假设 High 和 Low 是两个类:
	//				High bar;
	//				const High* pbar = & bar;
	//					...
	//				High* pb = const_cast<High *>(pbar);		// valid
	//				const Low* pl = const_cast<const Low*> (pbar);		// invalid
	//			第一个类型转换使得 *pb 成为一个可用于修改 bar 对象值的指针,他删除了 const 标签
	//			第二个类型转换是非法的,因为它同时尝试将类型从 const High* 修改为 const Low*
	//			提供该运算符的原因是,有时候可能需要这样一个值,他在大多情况下是常量
	//			而有时有时可以修改的,在这种情况下,可以将这个值声明为 const
	//			并在需要修改它的时候,使用 const_cast
	//			这也可以通过通用类型转换来实现,但通用转换也可能同时改变类型:
	//				High bar;
	//				const High* pbar = &bar;
	//					...
	//				High* pb = (High*)(pbar);		// valid
	//				Low* pl = (Low*)(pbar);			// invalid
	//			由于编程时可能无意间同时改变类型和常量特征,因此使用 const_cast 运算符更安全
	//			const_cast 不是万能的,它可以修改指向一个值的指针,但修改 const 值的结果是不确定的
	if (WhichOne == 10)	constcast_cpp();
	//			调用 change() 时,修改了 pop1,但没有修改 pop2
	//			在 change() 中,指针被声明为 const int* ,因此不饿能用来修改指向的 int
	//			指针 pc 删除了 const 特征,因此可用来修改指向的值
	//			但仅当指向的值不是 const 时才可行
	//			因此, pc 可用于修改 pop1 ,但不能用于修改 pop2
	//		3.static_cast 运算符
	//			语法与其他类型转换运算符相同:
	//				static_cast < type-name > (expression)
	//			仅当 type-name 可被隐式转换为 expression 所属的类型
	//			或 expression 可被隐式转换为 type-name 所属类型时
	//			上述转换才是合法的,否则将出错
	//			假设 High 是 Low 的基类,而 Pond 是一个无关的类
	//			则从 High 到 Low 的转换,从 Low 到 High 的转换都是合法的
	//			而从 Low 到 Pond 的转换是不允许的:
	//				High bar;
	//				Low blow;
	//				...
	//				High* pb = static_cast<High*>(&blow);		// valid upcast
	//				Low* pl = static_cast<Low*>(&bar);			// valid downcast
	//				Pond* pmer = static_cast<Pond*>(&blow);		// invalid, Pond unrelated
	//			第一种转换时合法的,因为向上转换可以显示地进行
	//			第二种转换是从基类指针到派生类指针,在不进行显示类型转换的情况下,将无法进行
	//				但由于无需进行类型转换,便可以进行另一个方向的类型转换
	//				因此使用 static_cast 来进行向下转换是合法的
	//				同理,由于无需进行类型转换,枚举量就可以被转换为整型
	//				所以可以用 static_cast 将整型转换为枚举量
	//				同样,可以使用 static_cast 将 double 转换为 int
	//				将 float 转换为 long 以及其他各种数值转换
	//		4.reinterpret_cast 运算符
	//			用于天生危险的类型转换
	//			它不允许删除 const ,但会执行其他令人生厌的操作
	//			又是程序员必须做一些依赖于实现的,令人生厌的操作
	//			使用 reinterpret_cast 运算符可以简化对这种行为的跟踪工作
	//			语法与其他类型转换运算符相同:
	//				reinterpret_cast < type-name > (expression)
	//			示例:
	struct dat {short a; short b;};
	 long value = 0xA224B118;
	dat* pd = reinterpret_cast<dat*>(&value);
	cout << sizeof(long) << " " << sizeof(short) << " " << sizeof(int) << endl;
	cout << hex << pd->a << endl;		// display first 2 bytes of value
	cout << hex << pd->b;				// display second 2 bytes of value
	//			通常,这样的转换适用于依赖于实现的底层编程技术,是不可移植的
	//			例如,不同系统在存储多字节整型时,可能以不同的顺序存储其中的字节
	//			然而, reinterpret_cast 运算符不支持所有的类型转换
	//			例如,可以将指针类型转换为足以存储指针表示的整型
	//			但不能将指针转换为更小的整型或浮点型
	//			另一个限制是,不能将函数指针转换为数据指针,反之亦然

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

// use_sales.cpp
void use_sales_cpp()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double vals1[12] =
	{
		1220, 1100, 1122, 2212, 1232, 2334,
		2884, 2393, 3302, 2922, 3002, 3544
	};

	double vals2[12] =
	{
		12, 11, 22, 21, 32, 34,
		28, 29, 33, 29, 32, 35
	};

	Sales sales1(2011, vals1, 12);
	LabelSales sales2("Blogstar", 2012, vals2, 12);

	cout << "First try block:\n";
	try {
		int i;
		cout << "Year = " << sales1.Year() << endl;
		for (i = 0; i < 12; ++i)
		{

			cout << sales1[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "Year = " << sales2.Year() << endl;
		cout << "Label = " << sales2.Label() << endl;
		for (i = 0; i <= 12; ++i)
		{

			cout << sales2[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "End of try block 1.\n";
	}
	catch (LabelSales::nbad_index& bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.label_val() << endl;
		cout << "bad index: " << bad.bi_val() << endl;
	}
	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		cout << "bad index: " << bad.bi_val() << endl;
	}
	cout << "\nNext try block:\n";
	try
	{
		sales2[2] = 37.5;
		sales1[20] = 23345;
		cout << "End of try block 2.\n";
	}
	catch (LabelSales::nbad_index& bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.label_val() << endl;
		cout << "bad index: " << bad.bi_val() << endl;
	}
	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		cout << "bad index: " << bad.bi_val() << endl;
	}
	cout << "done\n";
}

// constcast.cpp
void change(const int* pt, int n)
{
	int* pc;

	pc = const_cast<int*>(pt);
	*pc += n;
}
void constcast_cpp()
{
	int pop1 = 28282;
	const int pop2 = 2000;
	cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;
	change(&pop1, -103);
	change(&pop2, -103);
	cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;
}