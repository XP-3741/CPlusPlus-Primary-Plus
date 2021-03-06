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
#include"arraytp.h"
#include"pairs.h"
#include"tempmemb.h"
#include"tempparm.h"
#include"frnd2tmp.h"
#include"tmp2tmp.h"
#include"manyfrnd.h"

using std::cin;
using std::cout;
using std::endl;
using std::strchr;
using std::string;

void set(Student& sa, int n);

const int pupils = 3;
const int quizzes = 5;

const int LIM = 4;

const int SIZE = 5;

const int Num = 10;

int main()
{
	// valarray 类简介
	//	这个类用于处理数值(或具有类似特性的类)
	//	valarray 被定义为一个模板类,以便能够处理不同的数据类型
	//	模板类特性意味着声明对象时,必须指定具体的数据类型
	//	因此,使用 valarray 类来声明一个对象时
	//	须在标识符 valarray 后面加上一对尖括号,并在其中包含所需要的数据类型
	std::valarray<int> q_values;		// an array of int
	std::valarray<double> weights;		// an array of double
	// 下面是几个使用构造函数的例子:
	double gpa[5] = { 3.1, 3.5, 3.8, 2.9, 3.3 };
	std::valarray<double> v1;		// an array of double, size 0
	std::valarray<int> v2(8);		// an array of 8 int elements
	std::valarray<int> v3(10, 8);	// an array of 8 int elements
									// each set to 10
	std::valarray<double>v4(gpa, 4);// an array of 4 elements
						// initialized to the first 4 elements of gpa
	// 在C++11中,也可以使用初始化列表
	std::valarray<int> v5 = { 20, 32, 17, 9 };	// C++11
	// 下面是这个类的一些方法
	//	- operator[]()	访问各个元素
	//	- size()		返回包含的元素数
	//	- sum()			返回所有的元素总和
	//	- max()			返回最大的元素
	//	- min()			返回最小的元素

	// Student 类的设计
	//	以确定 Student 类的设计计划:
	//		string对象表示姓名、valarray<double>表示分数
	//	由于学生与这列类之间不是 is-a 模型,所以不适合将学生从这两个类派生出
	//	这里的关系是 has-a ,学生有姓名和一组考试分数
	//	通常,用于建立 has-a 关系的C++技术是组合(包含),及创建一个包含其他类对象的类
	
	// 接口和实现
	//	使用公有继承时,类可以继承接口,可能还有实现
	//		(基类的纯虚函数提供接口,但不提供实现)
	//	获得接口是 is-a 关系的组成部分
	//	而是用组合,类可以获得实现,但不能获得接口
	//	不继承接口是 has-a 关系的组成部分

	// 关键词 explicit 用法:
	//		explicit Student(const std::string& s)
	//				:name(s), scores() {}	
	//		explicit Student(int n)
	//				:name("Nully"), scores(n) {}
	//	可以用一个参数调用的构造函数将用作从参数类型到类类型的隐式转换函数
	//	但这通常不是好主意
	//	上述第二个,参数表示数组元素的个数,而不是数组中的值
	//	因此将一个构造函数用作 int 到 student 的转换函数是没有意义的
	//	所以使用 explicit 关闭隐式转换
	//	如果省略:
	//	Student doh("Homer", 10);	// store "Homer", create array of 10 elements
	//	doh = 5;	// reset name to "Nully", reset to empty array of 5 elements
	//	如果构造函数省略 explicit ,则将使用构造函数调用 Student(5)
	//	将5转换为一个临时 Student 对象
	//	使用了 explicit ,编译器将认为上述运算符是错误的

	// 成员初始化列表
	//	如果不使用成员初始化列表
	//	C++要求在构建对象的其他部分之前,先构建继承对象的所有成员对象
	//	因此,如果省略初始化列表,C++将使用成员对象所属类的默认构造函数
	// 初始化顺序
	//	当初始化列表包含多个项目时,这些项目被初始化的顺序为它们被声明的顺序
	//	而不是它们在初始化列表中的顺序
	//	如果代码用一个成员的值作为另一个成员的初始化表达式的一部分
	//	初始化顺序就非常重要了

	// 使用被包含对象的接口
	//	被包含对象的接口不是公有的,但可以在类方法中使用它

	// 私有继承
	//	C++的另一种实现 has-a 关系的途径----私有继承
	//	使用私有继承,基类的公有成员和保护成员都将成为派生类的私有成员
	//	这意味这基类方法将不会成为派生类对象公有接口的一部分
	//	但可以在派生类的成员函数中使用它们
	// 
	//	使用公有继承,基类的公有方法将成为派生类的公有方法
	//		总之,派生类将继承基类的接口:这是 is-a 关系的一部分
	//	使用私有继承,基类的公有方法将成为派生类的私有方法
	//		总之,派生类不继承基类的接口
	//		正如从被包含对象中看到的,这种不完全继承是 has-a 关系的一部分
	// 
	//	使用私有继承,类将继承实现
	// 
	//	包含将对象作为一个命名的成员对象添加到类中
	//	而私有继承将对象作为一个未命名的继承对象添加到类中
	//	用术语 子对象(subobject)来表示通过继承或包含添加的对象
	//	因此,私有继承提供的特性与包含相同:获得实现,但不获得接口
	// 
	//  通常,应使用包含来建立 has-a 关系
	//	如果新类需要访问原有类的保护成员,或需要重新定义虚函数
	//	则应使用私有继承
	//
	// Student(Studenti) 类测试
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

	// 保护继承
	//	保护继承在列出基类时使用关键字 protected
	//	使用保护继承时,基类的公有成员和保护成员都将成为派生类的保护成员	
	//	和私有继承一样,基类的接口在派生类中也是可用的
	//	但在继承层次结构之外是不可用的
	//	当从派生类派生出另一个类时
	//	使用私有继承时,第三代类将不能使用基类的接口
	//	这是因为基类的公有方法在派生类中将变成私有方法
	//	使用保护继承时,基类的公有方法在第二代中将变成受保护的
	//	因此第三代派生类可以使用它们

	// 使用using重新定义访问权限
	//	假设要让基类的方法在派生类外可用
	//	- 方法之一是定义一个使用该基类方法的派生类方法
	//	- 另一种方法是,将函数调用包装在另一个函数调用中
	//		即使用一个 using 声明来指出派生类可以使用特定的基类成员
	//		即使采用的是私有派生
	//		例如:
	//		class Studenti :private std::string, private std::valarray<double>
	//		{
	//		...
	//		public:
	//			using std::valarray<double>::min;
	//			using std::valarray<double>::max;
	//			...
	//		};
	//		上述 using 声明使得 valarray<double>::min 和 valarray<double>::max 可用
	//		就像它们是 Studenti 的公有方法一样
	//		cout << "high score: " << ada[i].max() << endl;
	//		注意,using声明只是用成员名----没有圆括号、函数特征标和返回类型
	//		using声明只适用于继承,而不适用于包含

	// 多重继承
	//	与单继承一样,公有MI表示的也是 is-a 关系
	//	私有MI和保护MI可以表示 has-a 关系
	//	MI可能会带来很多新问题
	//	其中两个主要的问题:
	//	- 从两个不同的基类继承同名方法
	//	- 从两个或更多相关基类那里继承同一个类的多个实例 
	//
	// Worker0 测试
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
	//	有多少Worker
	//		假设首先从 Singer 和 Waiter 公有派生出 SingingWaiter:
	//		class SingingWaiter : public Singer, public Waiter {...}
	//		因为 Singer 和 Waiter 都继承了一个 Worker 组件
	//		这将引起问题,通常可以将派生类对象的地址赋给基类指针,但现在出现二义性:
	//			SingingWaiter ed;
	//			Worker * pw = &ed;		// ambiguous
	//		通常,这种赋值将把基类指针设置为派生类对象中的基类对象的地址
	//		但 ed 中包含两个 Worker 对象,有两个地址可供选择,所以应使用类型转化来指定对象:
	//			Worker * pw = (Waiter *)&ed;
	//			Worker * pw = (Singer *)&ed;
	//		包含两个 Worker 对象拷贝还会导致其他问题
	//		然而真正的问题是:为什么需要 Worker 对象的两个拷贝
	//		唱歌的侍者和其他 Worker 对象一样,也应只包含一个姓名和一个ID
	//		C++引入多重继承的同时,引入了一种新技术----虚基类(virtual base class),使MI成为可能
	// 
	// 虚基类
	//	虚基类使得从多个类(它们的基类相同)派生出的对象只继承一个基类对象
	//	例如:通过在类声明中使用关键字 virtual ,可以使 Worker 被用作 Singer 和 Waiter 的虚基类
	//	( virtual 和 public 的次序无关紧要)
	//		class Waiter :virtual public Worker {...};
	//		class Singer :public virtual Worker {...};
	//	然后,可以将 SingingWaiter 类定义为;
	//		class SingingWaiter :public Singer,public Waiter {...};
	//	现在,SingingWaiter 对象将只包含 Worker 对象的一个副本
	//	从本质上说,继承的 Singer 和 Waiter 对象共享一个 Worker 对象
	//	而不是各自引入自己的 Worker 对象副本
	// 
	// 新的构造函数规则
	//	对于非虚基类,唯一可以出现在初始化列表中的构造函数是即是基类构造函数
	//	但这些构造函数可能需要将信息传递给其基类
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
	//	C类构造函数只能调用B类构造函数,而B类构造函数只能调用A类构造函数
	//	如果Worker是虚基类,则这种信息自动传递将不起作用
	//		SingingWaiter(const Worker & wk, int p = 0, int v = Singer::other)
	//						: Waiter(wk,p), Singer(wk,v) {}		// flawed
	//	存在的问题是,自动传递信息时,将通过两条不同的路径(Singer和Waiter)将wk传递给Worker对象
	//	为避免冲突,C++在基类是虚的时,禁止信息通过中间类自动传递给基类
	//	因此<上述构造函数将初始化成员panache和voice,但wk参数中的信息将不会传递给子对象Waiter
	//	然而,编译器必须在构造派生对象之前构造基类对象组件
	//	上述情况下,编译器将使用 Worker 的默认构造函数
	//	如需要显示地调用所需基类构造函数:
	//		SingingWaiter(const Worker & wk, int p = 0, int v = Singer::other)
	//						: Worker(wk), Waiter(wk,p), Singer(wk,v) {}		// flawed
	//	这种用法是合法的,对于虚基类,必须这样做
	//	但对于非虚基类,则是非法的
	//	如果类有间接虚基类.则除非只需要该虚基类的默认构造函数,否则必须显示地调用该虚基类的某个构造函数
	//
	// SingingWaiter类测试
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
	//	C-风格字符串函数 strchr()
	//	该函数返回参数 choice 指定的字符在字符串 "wstq" 中第一次出现的地址
	//  如果没有这样的字符,则返回NULL指针

	// 混合使用虚基类和非虚基类
	//	假设类 B 被用作类 C 和 D 的虚基类,同时被用作类 X 和 Y 的非虚基类
	//	而类 M 是从 C、D、X 和 Y 派生而来
	//	那么,类 M 从虚派生祖先那里共继承了一个 B 类子对象
	//	并从每一个非虚派生祖先分别继承了一个 B 类子对象
	//	因此,它包含三个 B 类子对象
	// 
	// 虚基类和支配
	//	使用非虚基类时,如果类从不同的类那里继承了两个或多个同名成员
	//	 如没有类名限定,将导致二义性
	//	如果是虚基类,不一定二义性,如果某个名称优先于其他所有名称,不用限定去使用也没问题
	//	 派生类中的名称优先于直接或间接祖先类中的同名称

	// 类模板
	//	模板提供参数化类型,即能够将类型名作为参数传递给接受放建立类或函数
	//	和模板函数一样,模板类以下面这样的代码开头:
	//		template <class Type>
	//	关键字 template 告诉编译器,将要定义一个模板
	//	尖括号中的内容相当于函数的参数列表
	//	可以把关键字 class 看作是变量的类型名,该变量接受类型作为其值
	//	把 Type 看作是该变量的名称,称为类型参数(type parameter)
	//	这里的 class 并不意味着 Type 必须是一个类
	//	而只是表明 Type 是一个通用的类型说明符,在使用模板时,将使用实际的类型替换他
	//	较新的C++实现允许在这种情况下使用不太容易混淆的关键字 typename 代替 class
	//		template <typename Type>
	//  同样,可以使用模板成员函数替换所有类的类方法
	//	每个函数头都将以相同的模板声明打头:
	//		template <class Type>
	//	还需将类限定符从 ClassName:: 改为 ClassName<Type>::
	//	如果在类声明中定义了方法(内联定义),则可以省略模板前缀和类限定符
	//	由于模板不是函数,它们不能单独编译
	//	模板必须与特定的模板实例化请求一起使用
	//	为此,最简单的方法就是将所有模板信息放在一个头文件中
	//	并在要使用这些模板的文件中包含该头文件
	// 
	// 使用模板类
	//	仅在程序包含模板并不能生成模板,而必须请求实例化
	Stack<int> kernels;
	Stack<std::string> colonels;
	//	编译器将按 Stack<Type> 模板来生成两个独立的类声明和两组独立的类方法
	// 
	// 正确使用指针栈
	//	方法之一是,让调用程序提供一个指针数组,其中每个指针都指向不同的字符串
	// 
	// Stack_P类测试
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

	// 数组模板示例和非类型参数
	//	允许指定数组大小的简单模板:
	//		方法一:在类中使用动态数组和构造函数参数来提供元素(Stack_P类)
	//		方法二:使用模板参数来提供常规数组大小(STL::array类、ArrayTP类)
	//	 template<class T,int n>
	//	 关键字 class(typename) 指出 T 为类型参数,int 指出 n 的类型为 int
	//	 这种参数(指定特殊类型而不是用作泛型名)称为 非类型(non-type) 或 表达式(expression) 参数
	//	表达式参数有一些限制:
	//		-表达式参数可以是整形、枚举、引用或指针
	//			因此,double m 是不合法的,但 double * pm 是合法的
	//		-另外,模板代码不能修改参数的值,也不能使用参数的地址
	//			所以,ArrayTP 模板不能使用如 n++ 和 &n 登表达式
	//		-实例化模板时,用作表达式参数的值必须是常量表达式
	//	优点:
	//		-构造函数方法使用的是 new 和 delete 管理的堆内存
	//		 而参数表达式使用的是为自动变量维护的内存栈,速度更快
	//	缺点:
	//		-每种数组大小都将生成自己的模板
	//		 也就是说,下面声明将生成两个独立的类声明:
	//			ArrayTP<double, 12> eggweights;
	//			ArrayTP<double, 13> donuts;
	//		 但下面的声明只生成一个类声明:
	//			Stack_P<int> eggs(12);
	//			Stack_P<int> dunkers(13);
	//		-构造函数发放更通用,因为数组大小是作为类成员(而不是硬编码)存储在定义中的
	//		 这样可以将一种尺寸的数组赋给另一种尺寸的数组,也可以创建允许数组大小可变的类

	// 模板多功能性
	//	可以将用于常规类的技术用于模板类
	//	模板可用作基类,也可用作组件类,还可用作其他模板的类型参数
	//		template<typename T>
	//		class Array
	//		{
	//		private:
	//			T entry;
	//			...
	//		};
	//		
	//		template<typename Type>
	//		class GrowArray : public Array<Type>
	//		{ ... };
	// 
	//		template<typename Tp>
	//		class Stack
	//		{
	//			Array<Tp> ar;
	//			...
	//		};
	//		...
	//		Array< Stack<int> > asi;
	// 
	// 递归使用模板
	ArrayTP<ArrayTP<int, 5>, 10> two;
	//		这使得 two 是一个包含10个元素的数组,其中每个元素是一个包含5个int元素的数组
	//		与之等价的是:
	//		int two[10][5];
	ArrayTP<int, 10> sums;
	ArrayTP<double, 10> aves;
	ArrayTP<ArrayTP<int, 5>, 10>twodee;
	int i, j;
	for (i = 0; i < 10; i++) {
		sums[i] = 0;
		for (j = 0; j < 5; j++) {
			twodee[i][j] = (i + 1) * (j + 1);
			sums[i] += twodee[i][j];
		}
		aves[i] = (double)sums[i] / 10;
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cout.width(2);	// 设置新域宽,返回旧域宽
			cout << twodee[i][j] << ' ';
		}
		cout << ": sum = ";
		cout.width(3);	// 设置新域宽
		cout << sums[i] << ", average = " << aves[i] << endl;
	}
	cout << "Done.\n";
	// std::cin.get();
	// 
	// 使用多个类型参数
	//	模板可以包含多个参数类型(STL::pair 、Pair)
	Pair<string, int>rating[4] =
	{
		Pair<string,int>("The Purpled Duck",5),
		Pair<string,int>("Jaquie's Frisco Al Fresco", 4),
		Pair<string,int>("Cafe Souffle", 5),
		Pair<string,int>("Bertie's Eats", 3)
	};

	int joints = sizeof(rating) / sizeof(Pair<string, int>);
	cout << "Rating:\t Eatery\n";
	for (int i = 0; i < joints; i++)
		cout << rating[i].second() << ":\t"
			<< rating[i].first() << endl;
	cout << "Oops! Revised rating:\n";
	rating[3].first() = "Bertie's Fab Eats";
	rating[3].second() = 6;
	cout << rating[3].second() << ":\t "
		<< rating[3].first() << endl;
	// std::cin.get();

	// 默认类型模板参数
	//	类模板的另一项新特性,可以为类型参数提供默认值:
	//		template<class T1, class T2 = int> class Topo {...}
	//	这样,如果省略 T2 的值,编译器将使用 int
	//	虽然可以为类模板类型参数提供默认值,但不能为函数模板参数提供默认值

	// 模板具体化
	//	类模板与函数模板很类似,因为可以有隐式实例化、显式实例化和显式具体化
	//	统称为 具体化
	//	模板以泛型的方式描述类,而具体化是使用具体的类型生成声明
	//	- 隐式实例化
	//		编译器在需要对象之前,不会生成类的隐式实例化:
	//			ArrayTP<int, 100> stuff;		// a pointer, no object needed yet
	//			stuff = new ArrayTP<int, 100>;	// now an object is needed
	//		第二条语句导致编译器生成类定义,并根据该定义创建一个对象
	//	- 显式实例化
	//		当使用关键字 template 并指出所需类型来声明类时,编译器将生成类声明的显式实例化
	//		声明必须位于模板定义所在的名称空间中
	//		例如下面声明将 ArrayTP<string, 100> 声明为一个类:
	//			template class ArrayTP<string, 100>;
	//		在这种情况下,虽然没有创建或提及类对象,编译器也将生成类声明(包括方法定义)
	//		和隐式实例化一样,也将根据通用模板来生成具体化
	//	- 显式具体化
	//		显式具体化是 特定类型(用于替换模板中的泛型) 的定义
	//		可能需要在为特殊类型实例化时,对模板进行修改,使其行为不同
	//		在这种情况下,可以创建显式具体化
	//		具体化类模板定义的格式如下:
	//			template <> class Classname<specilized-type-name> {...};
	//		要使用新的表示法提供一个专供 const char *类型使用的 SortedArray 模板:
	//			template <> class SortedArray<const char *>
	//			{
	//				...// details omitted
	//			};
	//		当请求 const char * 类型的 SortedArray 模板时
	//		编译器将使用上述专用的定义,而不是通用的模板定义
	//	- 部分具体化
	//		即部分限制模板的通用性
	//		例如,部分具体化可以给类型参数之一指定具体的类型:
	//			// general template
	//				template <class T1, class T2> class Pair {...};
	//			// specialization with T2 set to int
	//				template <class T1> class Pair<T1,int> {...};
	//		关键字 template 后面的 <> 声明的是没有被具体化的类型参数
	//		因此,上述第二个声明将 T2 具体化为 int,但 T1 保持不变
	//		注意,如果指定所有的类型,则<>内将为空,这将导致显式具体化:
	//			// specialization with T1 and T2 set to int
	//				template <> class Pair<int,int> {...};
	//		如果有多个模板可供选择,编译器将使用具体化程度最高的模板
	//			Pair<double, double> p1;		// use general Pair template
	//			Pair<double, int> p2;			// use Pair<T1,int> partial specialization
	//			Pair<int, int> p3;				// use Pair<int,int> explicit specialization
	//		也可以通过为指针提供特殊版本来部分具体化现有的模板:
	//			template<class T>		// general version
	//			class Feeb {...};
	//			template<class T*>		// pointer partial specialization
	//			class Feed {...};		// modified code
	//		示例;
	//			Feeb<char>fb1;			//	use general Feeb template, T is char
	//			Feeb<char *>fb2;		//	use Feeb T* specialization, T is char
	//		部分具体化特性使得能够设置各种限制:
	//			// general template
	//				template<class T1,class T2,class T3> class Trio{...};
	//			// specialization with T3 set to T2
	//				template<class T1,class T2> class Trio<T1,T2,T2>{...};
	//			// specialization with T3 and T2 set to T1*
	//				template<class T1> class Trio<T1,T1*,T1*>{...};
	//		编译器会做出如下选择:
	//			Trio<int,short,char *> t1;	// use general template
	//			Trio<int,short> t2;			// use Trio<T1,T2,T2>
	//			Trio<char,char*,char*> t3;	// use Trio<T1,T1*,T1*>

	// 成员模板
	//	模板可用作结构、类或模板类的成员
	beta<double>guy(3.5, 3);
	cout << "T was set to double\n";
	guy.Show();
	cout << "V was set to T, which is double, then V was set to int\n";
	cout << guy.blab(10, 2.3) << endl;
	cout << "U was set to int\n";
	cout << guy.blab(10.0, 2.3) << endl;
	cout << "U was set to double\n";
	cout << "Done\n";
	// std::cin.get();
	//	blab()方法的 U 类型由该方法被调用时的参数值显示确定
	
	// 将模板用作参数
	//		template<template<typename T> class Thing>
	//		class Crab
	//	模板参数是 template<typename T> class Thing
	//	其中 template<typename T> class 是类型,Thing 是参数
	//	假设有如下声明:
	//		Crab<King> legs;
	//	为使上述声明被接受,模板参数King必须是一个模板类,其声明与模板参数Thing的声明匹配
	//		template<typename T> class King {...};
	Crab<Stack> nebula;
// Stack must match template <typename T> class thing 
	int ni;
	double nb;
	cout << "Enter int double pairs, such as 4 3.5 (0 0 to end):\n";
	while (cin >> ni >> nb && ni > 0 && nb > 0)
	{
		if (!nebula.push(ni, nb))
			break;
	}
	while (nebula.pop(ni, nb))
		cout << ni << ", " << nb << endl;
	cout << "Done.\n";
	// 可以混合使用模板参数和常规参数
	//		template<template<Typename> class Thing, typename U, typename V>
	//		class Crab
	//		{
	//		...
	//		private:
	//			Thing<U> s1;
	//			Thing<V> s2;
	//		...
	//		};
	//	现在,成员s1和s2可存储的数据类型为泛型,而不是用硬编码指定的类型

	// 模板类和友元
	//	模板的友元分3类:
	//		- 非模板友元
	//		- 约束模板友元,即友元的类型取决于类被实例化时的类型
	//		- 非约束模板友元,即友元的所有具体化都是类的每一个具体化的友元
	// 
	//	 模板类的非模板友元函数
	//		在模板类中将一个常规函数声明为友元:
	//		template<class T>
	//		class HasFriend
	//		{
	//		public:
	//			friend void counts();
	//			...
	//		};
	//		上述声明使 counts() 函数称为模板所有实例化的友元
	//		假设要为友元函数提供模板类参数
	//		friend void counts(HasFriend &);
	//		这样的声明是不可以的
	//		原因是不存在 HasFriend 这样的对象,而只有特定的具体化:
	//		friend void counts(HasFriend<T> &);
	cout << "No objects declared: ";
	counts();
	HasFriend<int> hfil(10);
	cout << "After hfi1 declared: ";
	counts();
	HasFriend<int> hfi2(20);
	cout << "After hfi2 declared: ";
	counts();
	HasFriend<double> hfdb(10.5);
	cout << "After hfdb declared: ";
	counts();
	reports(hfil);
	reports(hfi2);
	reports(hfdb);

	// 模板类的约束模板友元函数
	//	为约束模板友元做准备,要使类的每个具体化都获得与友元匹配的具体化
	//	分三步:
	//		- 首先,在类定义的前面声明每个模板函数
	//			template <typename T> void counts();
	//			template <typename T> void reports(T &);
	//		- 然后,在函数中再次将模板声明为友元,这些语句根据类模板参数的类型声明具体化
	//			template <typename TT> class HasFriendT
	//			{
	//			...
	//				friend void counts<TT>();
	//				friend void reports<>(HasFriendT<TT> &);
	//			};
	//		  声明中的<>指出这是模板具体化
	//		  对于report(),<>可以为空
	//		  因为可以从函数参数推断出如下模板类型参数:
	//			HasFriendT<TT>
	//		  然而,也可以使用:
	//			report<HasFriendT<TT> >(HasFriendT<TT> &)
	//		  但 counts()函数没有参数,因此必须使用模板参数语法(<TT>)来指明其具体化
	//		  还需要注意的是,TT 是 HasFriendT 类的参数类型
	Counts<int>();
	HasFriendT<int> hfi1(10);
	HasFriendT<int> hfi2(20);
	HasFriendT<double> hfib(10.5);
	Report(hfi1);	// generate report(HasFriendT<int> &)
	Report(hfi2);	// generate report(HasFriendT<int> &)
	Report(hfib);	// generate report(HasFriendT<double> &)
	cout << "counts<int>() output:\n";
	Counts<int>();
	cout << "counts<double>() output:\n";
	Counts<double>();

	// 模板类的非约束模板友元函数
	//	通过在类内部声明模板,可以创建非约束友元函数,即每个函数具体化都是每个类具体化的友元
	//	对于非约束友元,友元模板类型参数与模板类类型参数是不同的:
	//		template<typename T> class ManyFriend
	//		{
	//		...
	//			template<typename C, typename D> friend void show2(C &, D &);
	//		};
	ManyFriend<int> hfi1(10);
	ManyFriend<int> hfi2(20);
	ManyFriend<double> hfdb(10.5);
	cout << "hfi1, hfi2: ";
	show2(hfi1, hfi2);
	cout << "hfdb, hfi2: ";
	show2(hfdb, hfi2);

	// 模板别名(C++11)
	//  如果能为类型指定别名,将很方便,在模板设计中尤为如此
	//  可使用 typedef 为模板具体化指定别名:
	//	typedef std::array<double, 12> arrd;
	//  C++11 新增了一项功能----使用模板提供一系列别名:
	//		template<typename T>
	//			using arraype = std::array<T,12>;
	//	这将 arraypt 定义为一个模板别名,可使用他来指定类型:
	//		arraype<double> gallons;
	//	C++11 允许将语法 using = 用于非模板
	//	用于非模板时,这种语法与常规 typedef 等价:
	//		typedef const char * pc1;			// typedef syntax
	//		using pc2 = const char *;			// using = syntax
	//		typedef const int *(*pa1)[10];		// typedef syntax
	//		using pa2 = const int *(*)[10];		// using = syntax

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