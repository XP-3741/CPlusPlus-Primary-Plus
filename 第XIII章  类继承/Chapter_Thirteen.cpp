#include<iostream>

int main()
{
	// P488续

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
	//

	return 0;
}