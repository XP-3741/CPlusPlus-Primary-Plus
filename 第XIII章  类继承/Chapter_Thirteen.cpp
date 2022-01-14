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
	//

	return 0;
}