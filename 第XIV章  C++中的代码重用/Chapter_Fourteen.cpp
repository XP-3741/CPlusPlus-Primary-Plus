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