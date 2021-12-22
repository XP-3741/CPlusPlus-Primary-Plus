#include<iostream>
#include<new>

int main()
{
	// 可以将程序分成三个部分
	// -头文件:包含程序声明和使用这些结构的函数的原型
	// -源代码文件:包含与结构有关的函数的代码
	// -源代码文件:包含调用与结构相关的函数的代码

	// 下面列出头文件.h中常包含的的内容
	// -函数原型
	// -使用 #define 或 const 定义的符号常量
	// -结构声明
	// -类声明
	// -模板声明
	// -内联函数

	// 如果文件名包含在尖括号中,则编译器将在存储标准头文件的主机系统的文件系统中查找
	// 如果文件名包含在双引号中,则编译器将首先查找当前的工作目录或源代码目录(或其他目录,这取决于编译器)
	//							如果没有在那你找到头文件,将在标准位置查找

	// 头文件管理
	// 在同一个文件中只能将同一个头文件包含一次
	// 很可能在不知情的情况下将头文件包含多次
	// 例如,可能使用包含了另外一个头文件的头文件
	// 有一种标准的C/C++技术可以避免多次包含同一个头文件
	// 它是基于预处理器编译指令 #ifndef (即if not defined)的
	// 下面的代码片段意味 
	// 仅当以前没有使用预处理器编译指#define定义名林COORDIN_H时,才处理#ifndef和#endif之间的语句
	/*
		#ifndef COORDIN_H
		...
		#endif
	*/

	// 注:这种方法并不能防止编译器将文件包含两次,而只是让它忽略除第一次包含之外的所有内容

	// 虽然我们讨论的是根据文件进行单独编译,但为保持通用性,C++标准使用了术语翻译单元(translation unit),而不是文件文件并不是计算机组织信息时的唯一方式
	// 出于简化目的,本书使用术语文件,可将其解释为翻译单元

	// 多个库的链接
	// C++标准允许每个编译器设计人员以他认为合适的方式实现名称修饰
	// 因此不同的编译器创建的二进制模块(对象代码文件)很可能无法正确的链接
	// 在连接编译模块时,请确保所有对象文件或库都是由一个编译器生成的
	// 如果有源代码,通常可以用自己的编译器重新编译源代码来消除链接错误

	// 回顾一下四种存储数据的方案:
	// -动态存储持续性:和函数定义中声明的变量(包含函数参数)的存储持续性为自动的
	//					他在程序开始执行其所属的函数或代码块时被创建,在执行完函数或代码块时
	//					它们使用的内存被释放,C++有两种存储持续性为自动的变量
	// -静态存储持续性:在函数定义外定义的变量和使用关键字 static 的变量的存储存储持续性都为静态
	//					它们在程序整个运行过程中都存在
	//					C++有三种存储持续性为静态的变量
	// -线程存储持续性:当前,多核处理器很常见,这些CPU可同时处理多个执行任务
	//					这让程序能够将计算放在可并行处理的不同线程中
	//					如果变量是使用关键词 thread_local 声明的,则其生命周期与所属的线程一样长
	// -动态存储持续性:用 new 运算符分配的内存将一直存在,直到使用 delete 运算符将其释放或程序结束为止
	//					这种内存的存储持续性为动态,有时被称为自由存储(free store)或堆(heap)

	// 作用域(scope)描述了名称在文件(翻译单元)的多大范围内可见
	// 链接性(linkage)描述了名称如何在不同单元间共享
	// -链接性为外部的名称可在文件间共享,链接性为内部的名称只能由一个文件中的函数共享
	//  自动变景的名称没有链接性,因为它们不能共享

	// 不同的C++存储方式是通过存储持续性、作用域和链接性來描述的

	// 自动变量和栈
	// 由于自动变量的数目随函数的开始和结束而增减,因此程序必须在运行时对自动变行进行管理
	// 常用的方法是留出一段内存,并将其视为栈以管理变量的增减
	// 之所以被称为栈,是由于新数据被象征性地放在原有数据的上面(也就是说,在相邻的内存单元中,而不是在同一个内存单元中),当程序使用完后,将其从栈中删除
	// 栈的默认长度取决于实现,但编译器通常提供改变栈长度的选项
	// 程序使用两个指针来跟踪栈,一个指针指向栈底——栈的开始位置,另一个指针指向堆顶——下一个可用内存单元
	// 当函数被调用时,其自动变量将被加入到栈中,栈顶指针指向变量后面的下一个可用的内存单元
	// 函数结束时,栈顶指针被重置为函数被调用前的值,从而释放新变量使用的内存

	// 这种设计简化了参数传递
	// 函数调用将其参数的值放在栈顶,然后重新设置栈顶指针
	// 被调用的函数根据其形参描述来确定每个参数的地址
 
	// 当fib()结束时,栈顶指针重新指向以前的位置
	// 新值没有被删除,但不再被标记,它们所占据的空间将被下一个将值加入到栈中的函数调用所使用

	// 寄存器变量
	// 关键词 register 最初是由C语言引入的,它建议编辑器使用CPU寄存器存储自动变量
	register int count_fast;
	// 这旨在提高访问变量的速度

	// 静态持续变量
	// C++也为静态存储持续性变量提供了3种链接性:
	// 外部链接性(可在其他文件中访问)、内部链接性(只能在当前文件中访问)和无链接性(只能在当前函数或代码块中访问)
	// 这3种链接性都在整个程序执行期间存在,与自动变量相比,它们的寿命更长
	// 由于静态变量的数目在程序运行期间是不变的,因此程序不需要使用特殊的装置(如栈)来管理它们
	// 编译器将分配固定的内存块来存储所有的静态变量,这些变量在整个程序执行期间一直存在
	// 如果没有显示的初始化静态变量,编译器将把它设为0
	// 在默认情况下,静态数组和结构将每个元素或成员的所有位都设为0
	
	// 要想创建链接性为外部的静态持续变量,必须在代码块的外面声明它
	// 想要创建链接性为内部的静态持续变量,必须在代码块的外面声明它,并使用 static 限定符
	// 要创建没有链接性的静态持变量,必须在代码块内声明它,并使用 static 限定符
	
	/*
		int global = 1000;
		static int one_file = 50;
		int main()
		{
			...
		}
		void funct1(int n)
		{
			static int count = 0;
			int llama = 0;
			...
		}
		void funct2(int n)
		{
			...
		}
	*/
	// 正如前面指出的,所有静态持续变量(上述示例中的global、one_file和count)在整个程序执行期间都存在
	// 在funct1()中声明的变量count的作用域为局部,没有链接性,这意味着只能在funct1()函数中使用,就像自动变量llama一样
	// 然而,与llama不同的是,即使在funct1()函数没有被执行时,count也留在内存中
	// global和one_file的作用域都为整个文件,即在从声明位置到文件结尾的范围内都可以被使用
	// 具体地说,可以在main()、functl()和fimct2()中使用它们
	// 由于one_file的链接性为内部,因此只能在包含上述代码的文件中使用它
	// 由于global的链接性为外部,因此可以在程序的其他文件中使用

	// 所有的静态持续变量都有下述初始化特征:未被初始化的静态变量的所有位都被设置为0
	// 这种变量被称为零初始化的(zero - initialized)
	
	//  单定义规则:
	//  一方面,在每个使用外部变量的文件中,都必须声明它
	//  另一方面,C++有"单定义规则"(One Definition Rule, ODR),该规则指出,变量只能有一次定义

	// 	为满足这种需求,C++提供了两种变量声明
	// 	一种是定义声明(defining declaration)或简称为定义(definition),给变量分配存储空间
	// 	另一种是引用声明(referencing declaration)简称为声明(declaration),它不给变量分配存储空间<因为它引用已有的变最
	//  引用声明使用关键字 extern ,且不进行初始化
	//  否则,声明为定义,导致分配存储空间：

	//  注:单定义规则并不意味不能有多个变量的名称相同
	//  例如,在不同函数中声明的同名自动变是彼此独立的,它们都有自己的地址
	//  局部变量可能隐藏同名的全局变量
	//  然而,虽然程序中可包含多个同名的变量,但每个变量都只有一个定义

	// 作用域解析运算符(::)
	// 放在变量名前面时,该运算符表示使用变量的全局版本

	// 静态持续性、内部链接性
	// 将 static 限定符作用于作用域为整个文件的变量时,该变量的链接性将为内部的
	// 如果要在其他文件中使用相同的名称來表示其他变量,该如何办呢?只需省略关键字 extern 即可吗?
	// 这种做法将失败的,因为它违反了单定义规则
	// 但如果文件定义了一个静态外部变最,其名称与另一个文件中声明的常规外部变最相同,则在该文件
	// 中,静态变量将隐藏常规外部变量
	// 这没有违反单定义规则,因为关键字 static 指出标识符 errors 的链接性为内部,因此并非要提供外部定义

	// cv-限定符: const  volatile
	// 关键字 volatile 表明,即使程序代码没有对内存单元进行修改,其值也可能发生变化
	// 例如,可以将一个指针指向某个硬件位置,包含来自串行端口的时间或信息
	// 在这种情况下,硬件(而不是程序)可能修改其中的内容.或者两个程序可能互相影响,共享数据
	// 该关键字的作用是为了改善编译器的优化能力
	// 例如,假设编译器发现,程序在几条语句中两次使用了某个变量的值,则编译器可能不是让程序查找这个值两次
	// 而是将这个值缓存到寄存器中.这种优化假设变量的值在这两次使用之间不会变化
	// 如果不将变量声明为 volatile ,则编译器将进行这种优化
	// 将变量声明为 volatile ,相当于告诉编译器,不要进行这种优化
	
	// mutable
	// 可以用它来指出,即使结构(或类)变量为 const ,其某个成员也可以被修改
	struct data {
		char name[10];
		mutable int accesses;
	};
	const data veep = { "X_P",0 };
	// strcpy(veep.name, "YL");	// not allowed
	veep.accesses++;	// allowed
	// veep的 const 限定符禁程程序修改 veep 的成员,但 acccss 成员的 mutable 说明符使 access 不受这种限制

	// 再谈 const
	// 在C++(但不是在C语言)中, const 限定符对默认存储类型稍有影响
	// 在默认情况下,全局变量的链接性为外部的,但 const 全局变量的链接性为内部的
	
	// 如果出于某种原因,程序员希望某个常量的链接性为外部的
	// 则可以使用 extern 关键字来覆盖默认的内部链接性:
	// extern const int status = 50;
	// 在这种情况下,必须在所有使用该常量的文件中使用 extern 关键字来声明它

	// 函数和链接性
	// 函数也有链接性,虽然可选范围比变量小
	// 和 C语言 一样, C++ 不允许在一个函数中定义另一个函数,因此函数的存储持续性都自动为静态
	// 即在整个程序执行期间一直存在
	// 在默认情况下,函数的链接性为外部的,即可以在文件间共享
	// 实际上,可以在函数原型中使用关键字 extern 来指出函数是在另一个文件中定义,不过这是可选的
	// 还可以使用关键字 static 将函数的链接性设置为内部的,使之只能在一个文件中使用
	// 必须同时在原型和函数定义中使用该关键词
	// 	static int private(double x);
	// 	...
	// static int private(double x)
	// {
	//		...
	//  }
	// 这意味该函数只在这个文件中可见,还意味可以在其他文件中定义同名的的函数
	// 和变量一样,在定义静态函数的文件中,静态函数将覆盖外部定义
	// 因此,使在外部定义了同名的函数,该文件仍将使用静态函数

	// 定义规则也适用于非内联函数,因此对于每个非内联函数,程序只能包含一个定义
	// 对于链接性为外部的函数来,这意味着在多文件程序中,只能有一个文件(该文件可能是库文件,而不是您提供的）
	// 包含该函数的定义,但使用该函数的每个文件都应包含其函数原型
	// 内联函数不受这项规则的约束,这允许程序员能够将内联函数的定义放在头文件中
	
	// 语言链接性
	// 链接程序要求每个不同的函数都有不同的符号名
	// 在C++中,同一个名称可能对应多个函数,必须将这些函数翻译为不同的符号名称。
	// 因此,C++编译器执行名称矫正或名称修饰,为重载函数生成不同的符号名称
	// 这种方式被称为 C++语言链接 ( C++ language linkage)
	// 链接程序寻找C++函数调用匹配的函数时,使用的方法与C语言不同
	// 但如果要在C++程序中使用C库中预编译的函数,如:
	// spiff(22); // want spiff(int) from a C library
	// 它在C库文件中的符号名称 _spiff ,但对于我们假设的链接程序来说,C++查询约定是查找符号名称
	// _spiff_i 为解决这种问题,可以用函数原型来指出要使用的约定：
	// extern "C" void spiff(int);
	// extern void spiff(int);
	// extern "C++" void spiff(int);
	// 第一个原型使用C语言链接性
	// 而后面的两个使用C++语言链接性
	// 第二个原型是通过默认方式这指出这点的,而第三个显式地指出了这点

	// 动态内存由运算符 new 和 delete 控制,而不是由作用域和链接性规则控制
	// 因此,可以在一个函数中分配动态内存,而在另一个函数中将其释放

	// 通常,编译器使用三块独立的内存：
	// 一块用于静态变量(可能再细分),一块用于自动变量,另外一块用于动态存储

	// 要为内置的标量类型(如int,double)分配存储空间并初始化,可在类型名后面加上初始值并将其用括号括起
	// int *pi = new int (6);
	// 然而,要初始化常规结构或数组,需要使用大括号的列表初始化,这要求编译器支持C++11
	// struct where { double x; double y; double z;};
	// where *one = new where{2.3, 3.5, 4.2};
	// int *ar = new int [4] {2,3,4,5};
	// 在C++11中,还可将列表初始化用于单值变量
	// int *pin = new int {6};
	// double *pdo = new double {99.99};

	// new 失败时
	// new 可能找不到请求的内存量
	// 在最初的10年中,C++在这种情况下让 new 返回空指针,但现在将引发异常 std::bad_alloc
	
	// 运算符 new 和 new[] 分别调用如下函数
	void* operator new(std::size_t);
	void* operator new[](std::size_t);
	// 这些函数被称为 分配函数 (alloction function),它们位于全局名称空间
	// 同样,也有 delete 和 delete[] 调用的 释放函数 (dealloction function)
	void operator delete(void*);
	void operator delete[](void*);

	// 定位 new 运算符
	// new 负责在堆 (heap) 中找到一个足以能够满足要求的内存块
	// new 运算符还有另一种变体,被称为 定位 (placement) new 运算符,它能够指定要使用的位置
	// 程序员可能使用这种特性來设置其内存管理规程,处理需要通过特定地址进行访问的硬件或在特定位置创建对象
	// 要使用定位 new 特性,首先需要包含头文件 new ,提供了这种版本的 new 运算符的原型
	// 然后将 new 运算符用于提供了所需地址的参数
	// 除需要指定参数外,句法与常规 new 运算符相同
	// 使用定 new 运算符时,变量后面可以有方括号,也可以没有
	struct chaff
	{
		char dross[20];
		int slag;
	};
	char buffer1[50];
	char buffer2[500];
	chaff* p1, * p2;
	int* p3, * p4;
	// first,the regular forms of new
	p1 = new chaff;		// place structure in heap
						// invokes new(sizeof(int))
	p3 = new int[20];	// place int array in heap
	// now,the two forms of placement new
	p2 = new(buffer1)chaff;		// place structure in buffer1
								// invokes new(sizeof(chaff),buffer1)
	p4 = new(buffer2)int[20];	// place int array in buffer2
								// invokes new(20*sizeof(int),buffer2)

	delete p1;
	delete[]p3;
	// 上述代码从 bufferl 中分配空间给结构 chaff
	// 从 buffer2 中分配空间给一个包含20个元素的 int 数组
	char buf[20];
	std::cout << "buf:" << buf << std::endl << "(void*)buf:" << (void*)buf << std::endl;
	double* burn;
	burn = new(buf) double(10);
	for (int i = 0; i < 10; i++)
		buf[i] = i+49;
	std::cout << "buf_:" << buf << std::endl;
	std::cout << "burn_:" << burn << std::endl;
	// 定位 new 运算符使用传递给它的地址,它不跟踪哪些内存单元已被使用,也不查找未使用的内存块
	// 这将一些内存管理的负担交给了程序员,例如:
	double* burn_ = new(buf + 10 * sizeof(double))double(10);
	// 提供了一个从数组 buf 开头算起的偏移量
	
	// 第三点差别是,是否使用 delete 来释放内存
	// delete 只能用于这样的指针: 指向常规 new 运算符分配的堆内存
	// 也就是说 buffer 位于 delete 的管辖区域之外

	// 定位 new 运算符的另一个用法是,将其与初始化结合使用.从而将信息放在特定的硬件地址处
	// 定位 new 运算符的工作原理:
	// 基本上,他只是返回传递给他的地址,并将其强制转换为 void* ,以便能够赋值给任何指针类型
	// 但这说的是默认定位 new 运算符,C++允许程序员重载定位 new 函数
	// 将定位 new 运算符用于类对象时,情况将更复杂,这将在第 12 章介绍
	
	// 名称空间
	// C++中,名称可以是变量、函数、结构、枚举、类以及类和结构的成员
	// 当随着项目的增大,名称相互冲突的可能性也就增大
	// 使用多个厂商的类库时,可能导致名称冲突
	// C++标准提供了名称空间工具,以便更好的控制名称的作用域
	 
	// 先复习一下C++已有的名称空间属性,并介绍一些术语
	// -声明区域(declaration region)
	//  声明区域是可以在其中进行声明的区域
	// 	例如,可以在函数外面声明全局变量,对于这种变量,其声明区域为其声明所在文件
	// 	对于函数中声明的变量,其声明区域为其声明所在的代码块
	// -潜在作用域(potential scope)
	//  变量潜在作用域从声明点开始,到其声明区域的结尾
	//  然而,变量并非在其潜在作用域内的任何位置都是可见的
	//  例如,他可能被另一个嵌套声明区域中声明的同名变量隐藏
	// 	例如,在函数中声明的局部变量(对于这种变量,声明区域为整个函数)将隐藏在同一个文件中声明的
	// 	全局变量(对于这种变量,声明区域为整个文件)
	// 	变量对程序而言可见的范围被称为 作用域(scope)
	
	// C++关于全局变量和局部变量的规则定义了一种名称空间层次
	// 每个声明区域都可以声明名称,这些名称独立于在其他声明区域中声明的变量
	 
	// 新的名称空间特性
	// 通过定义一种新的声明区域来创建命名的名称空间,这样做的目的之一是提供一个声明名称的区域
	// 一个名称空间中的名称不会与另外一个名称空间的相同名称发生冲突
	// 同时允许程序的其他部分使用该名称空间中声明的东西
	// 例如,下面的代码使用新的关键词 namespace 创建了两个名称空间: Tack 和 Jill
	/*
	namespace Tack {
		double pail;				// variable declaration
		void fetch();				// function prototype
		int pal;					// variable declaration	
		struct Well{...};			// structure declaration
	}
	namespace Jill {
		double bucket(double n) { ... };				// function declaration
		double fetch;									// variable declaration
		int pal;										// variable declaration	
		struct Hill { ... };							// structure declaration
	}
	*/
	// 名称空间可以是全局的,也可以位于另一个名称空间中,但不能位于代码块中
	// 因此,默认情况下,在名称空间中声明的的名称的链接性为外部的(除非他引用了常量)

	// 除了用户定义的名称空间外,还存在另一个名称空间——全局名称空间(global namespace)
	// 它对应于文件级声明区域,因此前面所说的全局变量现在被描述为位于全局名称空间中
	// 任何名称空间中的名称都不会与其他名称空间中的名称发生冲突
	// 名称空间中的声明和定义规则同全局声明和定义规则相同
	// 名称空间是开放的(open),即可以把名称空间加入到已有的名称空间中
	// namespace Jill{
	//	char *goose(const char *);
	// }
	// 同样,原来的 Jack 名称空间为 fetch() 函数提供了原型
	// 可以在该文件后面(或另外一个文件中)再次使用 Jack 名称空间來提供该函数的代码
	// 当然,需要有一种方法来访问给定名称空间中的名称
	// 最简单的方法是,通过作用域解析运算符 :: ,使用名称空间来限定该名称
	// Jack::fetch();
	// 未被装饰的名称(如 pail)称为 未限定的名称(unqualified name)
	// 包含名称空间的名称(如 Jack::pail)称为 限定的名称(qualified name)
	
	// using 声明和 using 编译指令
	// using 声明是特定的标识符可用
	// using 编译指令使整个名称空间可用

	// using 声明由被限定的名称和它前面的关键词 using 组成:
	// using Jill::fetch;		// a using declaration
	// 例如 main() 中的 using 声明 Jill::fetch 将 fetch 添加到 main() 定义的声明区域中
	// 完成该声明后,便可以使用名称 fetch 代替 Jill::fetch
	/*
		namespace Jill{
			double bucket(double n) {...}
			double fetch;
			struct Hill {...};
		}
		char fetch;
		int main()
		{
			using Jill::fetch;	// put fetch into local namespace
			double fetch;		// Error! Already have a local fetch
			cin >> fetch;		// read a value into Jill::fetch
			cin >> ::fetch;		// read a value into global fetch
			...
		}
		由于 using 声明将名称添加到局部声明区域中,因此这个示例避免了将另一个局部变量也命名为 fetch
		另外,和其他局部变一样, fetch 也将覆盖同名的全局变量
	*/
	/*
		在函数的外面使用 using 声明时,将把名称添加到全局名称空间中：
		void other();
		namespace Jill{
			double bucket(double n) {...}
			double fetch;
			struct Hill {...};
		}
		using Jill::fetch;	// put fetch into global namespace
		int main()
		{
			cin >> fetch;	// read a value into Jill::fetch
			other();
			...
		}
		void other()
		{
			cout << fetch;	// display Jill::fetch
			...
		}
	*/

	// using 声明使一个名称可用,而 using 编译指令使所有的名称都可用
	// using 编译指令由名称空间名和它前面的关键词 using namespace 组成
	// 它使名称空间中所有的名称都可用,而不需要使用作用域解析运算符
	
	// 有关 using 编译指令和 using 声明,需要记住的一点是,它们增加了名称冲突的可能性
	// 如有名称空间jack和jill,并在代码中使用作用域解析运算符,则不会存在二义性：
	// jack::pal = 3;
	// jill::pal = 10;
	// 变量 jack::pal 和 jill::pal 是不同的标识符,表示不同的内存单元
	// 然而,如果使用 using 声明,情况将发生变化：
	// using jack::pal;
	// using jill::pal;
	// pal = 4;		// whilch one???
	// 事实上,编译器不允许同时使用上述两个 using 声明,因为这将导致二义性
	
	// using 编译指令和 using 声明之比较
	// 如果使用 using 编译指令导入一个已经在函数中声明的名称,则局部名称将隐藏名称空间名,就像隐藏同名的全局变量一样 
	// 不过仍可以像下面的示例中使用作用域解析运算符：
	/*
	namespace Jill{
		double bucket(double n) {...}
		double fetch;
		struct Hill {...};
	}
	char fetch;		// global namesace
	int main()
	{
		using namespace Jill;
		Hill Thrill;				// create a type Jill::Hill structure
		double water = bucket(2);	// use Jill::bucket;
		double fetch;				// not an error; hides Jill::fetch
		cin >> fetch;				// read a value into the local fetch
		cin >> ::fetch;				// read a value into global fetch
		cin >> Jill::fetch;			// read a value into Jill::fetch
		...
	}
	*/
	// —般说來,使用 using 声明比使用 using 编译指令更安全这是由于只导入指定的名称
	// 如果该名称局部名称发生冲突,编译器将发出指示
	// using 编译指令导入所有名称,包括可能并不需要的名称
	// 如果与局部名称发生冲突,则局部名称将覆盖名称空间版木,而编译器并不会发出警告
	// 另外,名称空间的开放性意味着名称空间的名称可能分散在多个地方,这使得难以准确知道添加了哪些名称
	
	// 名称空间的其他特性
	// 可以将名称空间声明进行嵌套:
	// namespace elements
	// {
	//		namespace fire
	//		{
	//			int flame;
	//			...
	//		}
	//		float water;
	// }
	// 这里,flame指的是 elements::fire::flame 
	// 同样,可以使用下面的 using 编译指令使内部的名称可用:
	// using namespace elements::fire;
	//  
	// 另外,也可以在名称空间中使用 using 编译指令和 using 声明,如下所示
	// namespace nyth
	// {
	//		using Jill::fetch;
	//		using namespace elements;
	//		using std::cout;
	// }
	// 假设要访问 Jill::fetch 由于 Jill::fetch 现在位于名称空间 myth 
	// (在这里,它被叫做 fetch)中,因此可以这样访问它:
	// std::cin >> myth::fetch;
	// 当然,由于它也位于 Jill 名称空间中,因此仍然可以称作 Jill::fetch
	// 
	// using 编译指令是可传递的
	// 如 A op B 且 B op C,则 A op C, 则说操作 op 是可传递的
	// 
	// 可以给名称空间创建别名：
	// 例如,假设有下面的名称空间：
	// namespace my_very_favorite_things {...};
	// 则可以使用下面的语句让 mvft 成为 my_very_favorite_things 的别名：
	// namespace mvft = my_very_favorite_things;
	// 可以使用这种技术来简化对嵌套名称空间的使用：
	// namespace MEF = elements::fire::flame;
	// using MEF::flame;
	// 
	// 未命名的名称空间:
	// 可以通过省略名称空间的名称来创建未命名的名称空间：
	// namespcace
	// {
	//		int ice;
	//		int nb;
	// }
	// 这就像后面跟着 using 编译指令一样,也是是说,在该名称空间中声明的名称的潜在作用域为：
	// 从声明点到该声明区域末尾
	// 从这个方面看,它们与全局变量相似
	// 然而,由于这种名称空间没有名称,因此不能显式地使用 using 编译指令或 using 声明来使它在其他位置都可用
	// 具体地说,不能在未命名名称空间所属文件之外的其他件中,使用该名称空间中的名称
	// 这提供了链接性为内部的静态变量的替代品
	// 
	// 名称空间示例:
	// P331		namesp.h	namesp.cpp -- namespaces		usenmsp. cpp -- u sin g namespaces
	// 
	// 名称空间及其前途:
	// 随着程序员逐渐熟悉名称空间,将出现统一的编程理念.下面是当前的一些指导原则:
	// -使用在已命名的名称空间中声明的变量,而不是使用外部全局变量;
	// -使用在已命名的名称空间中声明的变量,而不是使用静态全局变量;
	// -如果开发了一个函数库或类库,将其放在一个名称空间中
	//  事实上,C++当前提倡将标准函数库放在名称空间 std 中,这种做法扩展到了來自C语言中的函数
	//  例如,头文件 math.h 是C语言兼容的,没有使用名称空间
	//  但C++头文件 cmath 应将各种数学库函数放在名称空间 std 中
	//  实际上,并非所有的编译器都完成了这种过渡
	// -仅将编译指令 using 作为一种将旧代码转换为使用名称空间的权宜之计
	// -不要在头文件中使用 using 编译指令
	//  首先,这样做掩盖了要让哪些名称可用;另外,包含头文件的顺序可能影响程序的行为
	//  如果非要使用编译指令 using ,应将其放在所有预处理器编译指令 #include 之后
	// -导入名称时,首选使用作用域解析运算符或 using 声明的方法
	// -对于 using 声明,首选将其作用域设置为局部而不是全局
	//
return 0;
}