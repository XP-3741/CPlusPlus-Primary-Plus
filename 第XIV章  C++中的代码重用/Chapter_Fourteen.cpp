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