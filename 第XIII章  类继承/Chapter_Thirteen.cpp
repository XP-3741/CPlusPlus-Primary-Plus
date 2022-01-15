#include<iostream>
#include<string>
#include"brass.h"
const int CLIENTS = 4;

int main()
{
	// P488续

	using std::cin;
	using std::cout;
	using std::endl;

	// 派生类和基类之间的特殊关系
	//	- 其中之一是派生类对象可以使用基类的方法,条件是方法不是私有的
	//	- 基类指针可以在不进行显式类型转换的情况下指向派生类对象
	//	- 基类引用可以在不进行显式类型转换的情况下引用派生类对象
	//		然而,基类指针或引用只能用于调用基类方法
	//		通常,C++要求引用和指针类型与赋给的类型匹配,但这一规则对继承来说是例外
	//		然而,这种例外只是单向的,不可以将基类对象和地址赋给派生类引用和指针
	//		如果基类引用和指针可以指向派生类对象,将出现一些很有趣的结果
	//		其之一是基类引用定义的函数或指针参数可用于基类对象或派生类对象
	//	引用兼容性属性也能够将基类对象初始化为派生类对象
	//		RatedPlayer olaf1(1840,"Olaf","Loaf",true);
	//		TableTennisPlayer olaf2(olaf1);
	//		要初始化olaf2,匹配的构造函数原型如下:
	//		TableTennisPlayer(const RatedPlayer &);
	//		类中没有这样的构造函数,但存在隐式复制构造函数:
	//		TableTennisPlayer(const TableTennisPlayer &);
	//	同样,也可以将派生类对象赋值给基类对象:
	//		RatedPlayer olaf1(1840,"Olaf","Loaf",true);
	//		TableTennisPlayer winner;
	//		winner = olaf1;
	//		在这种情况下,程序将使用隐式重载赋值运算符:
	//		TableTennisPlayer & operator=(const TableTennisPlayer &) const;
	
	// 继承: is-a关系	P490
	//	C++有3种继承方式:公有继承、保护继承和私有继承
	//	公有继承是最常见的方式,它建立一种is-a(is-a-kind-of)关系,即派生类对象也是一个基类对象
	//	可以对基类对象执行的任何操作,也可以对派生类对象执行
	
	// 多态公有继承
	//	RatedPlayer继承示例很简单,派生类对象使用基类的方法,而未做任何修改
	//	然而,可能会遇到这样的情况,即希望同一个方法在派生类和基类中的行为是不同的
	//	换句话来说,方法的行为取决于调用该方法的对象
	//	这种复杂的行为称为 多态---具有多种形态
	//	有两种重要的机制可用于实现多态公有继承:
	//		- 在派生类中重新定义基类的方法
	//		- 使用虚方法
	
	// 演示虚方法的行为
	// 如果能使用同一个数组来保存 Brsss 和 BrassPlus 对象,将很有帮助
	// 但这是不可能的.数组中所有元素的类型必须相同,而 Brass 和 BrassPlus 是不同的类型
	// 然而,可以创建指向 Brass 的指针数组,这样每个元素的类型都相同,但由于使用的是
	// 公有继承模型,因此 Brass 指针可以指向 Brass 对象,也可以指向 BrassPlus 对象
	// 因此,可以使用一个数组来表示多种类型的对象,这就是多态性
	Brass* p_clients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;
	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "Enter client's name: ";
		getline(cin, temp);
		cout << "Enter client's account number: ";
		cin >> tempnum;
		cout << "Enter opening ba;ance: $";
		cin >> tempbal;
		cout << "Enter 1 for Brass Account or "
			<< "2 for BrassPlus Account: ";

		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "Enter either 1 or 2: ";
		if (kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "Enter the overdraft limit: $";
			cin >> tmax;
			cout << "Enter the interest rate "
				<< "as a decimal fraction: ";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal,
										tmax, trate);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i = 0; i < CLIENTS; i++) {
		p_clients[i]->ViewAcct();
		cout << endl;
	}
	for (int i = 0; i < CLIENTS; i++) {
		delete p_clients[i];
	}
	cout << "Done.\n";

	// 静态联编和动态联编
	// 将源代码中的函数调用解释为执行特定的函数代码块被称为 函数名联编(binding)
	//	在编译过程中进行联编被称为 静态联编(static binding),又称为 早期联编(early binding)
	// 然而,虚函数使这项工作变得困难,正如上述程序,使用哪一个函数是不能在编译时确定的
	// 因为编译器不知道用户将选择哪种类型的对象
	//	所以,编译器必须生成能够在程序运行时选择正确的虚函数方法,
	//	这被称为 动态联编(dynamic binding),又称为 晚期联编(late binding)
	
	// 指针和引用类型的兼容性
	//  在 C++ 中,动态联编与通过指针和引用调用方法相关,从某种程度上说,这是由继承控制的
	//	公有继承建立 is-a 关系的一种方法是如何处理指向对象的指针和引用
	//	通常,C++不允许将一种类型的地址赋给另一种类型的指针,也不允许一种类型的引用指向另一种类型:
	//		double x = 2.5;
	//		int *pi = &x;
	//			// invalid assignment, mismatched pointer types
	//		long &rl = x;
	//			// invalid assignment, mismatched pointer types
	//	然而,指向基类的引用或指针可以使用派生类对象,而不必进行显示类型转换
	//		BrassPlus dilly("FUCKYOU", 666666, 250);
	//		Brass *pb = &dilly;		// ok
	//		Brass &rb = dilly;		// ok 
	// 将派生类引用或指针转换为基类引用或指针被称为 向上强制转换(upcasting)
	//	这使公有继承不需要进行显式类型转换,该规则使 is-a 关系的一部分
	//	BrassPlus 对象都是 Brass 对象,因为它继承了 Brass 对象所有数据成员和成员函数
	//	所以,可以对 Brass 对象执行的任何操作,都适用于 BrassPlus 对象
	//	因此,为处理 Brass 引用而设计的函数可以对 BrassPlus 对象执行相同的操作
	//	而不必担心导致任何问题
	//	将指向对象的指针作为函数参数时,也是如此
	//	向上强制转换是可以传递的
	//	如果从 BrassPlus 派生出 BrassPlusPlus 类
	//	则 Brass 指针或引用可以引用 Brass 对象、BrassPlus 对象或 BrassPlusPlus 对象
	// 相反的过程-将基类指针或引用转换为派生类指针或引用,称为 向下强制转换(downcasting)
	//	如果不使用显式类型转换,则向下强制类型转换是不允许的
	//	原因是 is-a 关系通常是不可逆的
	//	派生类可以新增数据成员,因此使用这些数据成员的类成员函数不能应用于基类
	// 对于使用基类引用或指针作为参数的函数调用,将进行向上转换
	//		这里假定每个函数都调用虚方法 ViewAcct()
	//		void fr(Brass & rb);	// uses rb.ViewAcct()
	//		void fp(Brass * pb);	// uses pb->ViewAcct()
	//		void fv(Brass b);		// uses b.ViewAcct()
	//		int main()
	//		{
	//			Brass b("Billy Bee", 123412, 1000.0);
	//			BrassPlus bp("Beety Beep", 123321, 123.0);
	//			fr(b);		// uses Brass::ViewAcct()
	//			fr(bp);		// uses BrassPlus::ViewAcct()
	//			fp(b);		// uses Brass::ViewAcct()
	//			fp(bp);		// uses BrassPlus::ViewAcct()
	//			fv(b);		// uses Brass::ViewAcct()
	//			fv(bp);		// uses Brass::ViewAcct()
	//		}
	//	按值传递导致只将 BrassPlus 对象的 Brass 部分传递给函数 fv()
	//	但随引用和指针发生的隐式向上转换导致函数 fr() 和 fp()
	//	分别为 Brass 对象和 BrassPlus 对象使用 Brass::ViewAcct() 和 BrassPlus::ViewAcct()
	// 隐式向上强制转换使基类指针或引用可以指向基类对象或派生类对象,因此需要动态联编
	// C++使用虚成员函数来满足这种需求

	// 虚函数工作原理
	//	编译器处理虚函数的工作方法是: 给每个对象添加一个隐藏成员
	//	隐藏成员中保存了一个指向函数地址数组的指针
	//	这种数组被称为 虚函数表(virtual function table, vtbl)
	//	虚函数表中存储了为类对象进行声明的虚函数的地址
	//		例如,基类对象包含一个指针,该指针指向基类中所有虚函数的地址表
	//		派生类对象将包含一个指向独立地址表的指针
	//		如果派生类提供了虚函数的新定义,该虚函数表将保存新函数的地址
	//		如果派生类没有重新定义虚函数,该vtbl将保存函数原始版本的地址
	//		如果派生类定义了新的虚函数,则该函数的地址也将被添加到vtbl中
	//	注意,无论类中包含的虚函数是1个还是10个,都只需要在对象中添加1个地址成员,只是表的大小不同而已
	//	总之,使用虚函数时,在内存和执行速度方面有一定的成本,包括:
	//		-每个对象都将增大,增大量为存储地址的空间
	//		-对于每个类,编译器都将创建一个虚函数地址表(数组)
	//		-对于每个函数调用,都需要执行一项额外的操作,即到表中查询地址
	//	虽然非虚函数的效率比虚函数稍高,但不具备动态联编功能
	
	// 有关虚函数注意事项
	//	上述要点:
	//		- 在基类方法的声明中使用关键字 virtual 可使该方法在基类
	//		  以及所有的派生类(包括从派生类派生的类)中是虚的
	//		- 如果使用指向对象的引用或指针来调用虚方法,程序将使用为对象类型定义的方法
	//		  而不使用为引用或指针类型定义的方法.这称为动表联编或晚期联编
	//		  这可以使基类指针或引用指向派生类对象
	//		- 如果定义的类将被用作基类,则应将那些要在派生类中重新定义的类方法声明为虚的
	//	其他要点:
	//		- 构造函数
	//			构造函数不能是虚的
	//			创建派生类对象时,将调用派生类的构造函数,而不是基类的构造函数
	//			然后,派生类的构造函数将使用基类的一个构造函数,这种顺粗不同于继承机制
	//		- 析构函数
	//			析构函数应当是虚函数,除非类不用做基类
	//			如:
	//				Employee *pe = new Singer;
	//				delete pe;
	//			这就意味着,即使基类不需要显示析构函数提供服务,也不应依赖于默认构造函数
	//			而应提供虚析构函数,即使他不执行任何操作:
	//				virtual ~BaseClass() {}
	//			给类定义一个虚析构函数并非错误,即使这个类不用做基类,这只是一个效率方面的问题
	//		- 友元
	//			友元不能是虚函数
	//			因为友元不是类成员,而只有成员才能使虚函数
	//		- 没有重新定义
	//			如果派生类没有重新定义函数,将使用该函数的基类版本
	//			如果派生类位于派生链中,则将使用最新的虚函数版本,例外的情况是基类版本是隐藏的
	//		- 重新定义将隐藏方法
	//			假设创建如下代码:
	//			class Dwelling
	//			{
	//			public:
	//				virtual void showperks(int a) const;
	//			...
	//			};
	//			class Hovel: public Dwelling
	//			{
	//			public:
	//				virtual void showperks() const;
	//			...
	//			};
	//			这将导致问题,可能出现类似警告:
	//			Warning: Hovel::showperks(void) hides Dwelling::showperks(int)
	//			代码将具有如下含义:
	//			Hovel trump;
	//			trump.showperks();		// valid
	//			trump.showperks(5);		// invalid
	//			重新定义继承的方法并不是重载
	//			由此两条经验规则:
	//				- 如果重新定义继承的方法,应确保与原来的原型完全相同
	//				  但如果返回类型是基类引用或指针,则可以修改为派生类的引用或指针
	//				  这种特性被称为 返回类型协变(covariance of return type)
	//				  因为允许返回类型随类类型的变化而变化
	//				- 如果基类被重载了,则应在派生类中重新定义所有的基类版本
	//					class Dwelling
	//					{
	//					public:
	//						virtual void showperks(int a) const;
	//						virtual void showperks(double x) const;
	//						virtual void showperks() const;
	//						...
	//					};
	//					class Hovel: public Dwelling
	//					{
	//					public:
	//						virtual void showperks(int a) const;
	//						virtual void showperks(double x) const;
	//						virtual void showperks() const;
	//						...
	//					}
	//					如果只重新定义一个版本,则另外两个版本将被隐藏,派生类对象将无法使用它们
	//					注意,如果不需要修改,则新定义可只调用基类版本:
	//					void Hovel::showperks() const { Dwelling::showperks(); }
	//

	return 0;
}