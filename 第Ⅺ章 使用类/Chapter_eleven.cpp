#include<iostream>
#include<Windows.h>
#include"mytime.h"
#include<fstream>

int main()
{
	// 运算符重载
	// 运算符重载是一种形式的C++多态
	// 第8章介绍了C++是如何使用户能够定义多个名称相同但特征标(参数列表)不同的函数的
	// 这被称为函数重载或函数多态
	// 旨在能够用同名的函数来完成相同的基本操作,即使这种操作被用于不同的数据类型
	// 运算符重载将重载概念扩展到运算符上,允许赋予C++运算符多种含义
	// 通常,需要使用下面这样的for循环来实现:
	// for(int i = 0; i < 20; i++)
	//		evening[i] = sam[i] + janet[i];	// add element by element
	// 但在C++中,可以定义一个表示数组的类,并重载运算符.于是,便可以有这样的语句:
	// evening = sam + janet;
	// 这种简单的加法表示法隐藏了內部机理,并强调了实质
	// 运算符函数的格式如下:
	// operatorop(argument list);
	// 例如:
	// operator+()		重载+运算符
	// operator*()		重载*运算符
	// op 必须是有效的C++运算符,不能虚构一个新的符号
	// 然而,operator[]()函数将重载[]运算符,因为[]是数组索引运算符
	// 假设有一个Salperson类,并为它定义operator+()成员函数,以重载+运算符
	// 则如果 district、sid和sara都是Saleperson类对象,便可这样编写:
	// district = sid + sara;
	// 编译器发现,操作数是Salperson类对,因此使用相应的运算符函数替换上述运算符:
	// district = sid.operator+(sara);
	// 然后隐式的使用sid,显式的使用sara,来计算总和,并返回这个值

	Time First(2, 55);
	Time Second(1, 35);
	Time total = First + Second;	// total = First.operator+(Second);
	total.Show();
	std::cout << std::endl;
	// 注意,在运算符表示法中,运算符左侧的对象(这里为First)是调用对象
	// 运算符右边的对象(这里为Second)是作为参数被传递的对象

	// 编译器将根据操作数的类型来确定如何做:
	// int A,B,C;
	// Time a,b,c;
	// C = A + B;	use int addition
	// c = a + b;	use additon as defined for Time objects
	
	// 两个以上对象相加？
	// t4 = t3 + t2 + t1;
	// 等价于:
	// t4 = t3.operator+(t2.operator+(t1));	Valid

	// 重载限制
	// 1、重载后的运算符必须至少有一个操作数是用户定义的类型,这将防止用户为标准类型重载运算符
	// 2、使用运算符时不能违反运算符原来的句法规则
	//		例如,不能将求模运算符(％)重载成使用一个操作数
	//		同样,不能修改运算符的优先级.
	//		因此,如果将加号运算符重载成将两个类相加,则新的运算符与原来的加号有相同的有先级
	// 3、不能创建新运算符
	// 4、不能重载下面的运算符:
	//		sizeof				sizeof运算符
	//		.					成员运算符
	//		.*					成员指针运算符
	//		::					作用域解析运算符
	//		?:					条件运算符
	//		typeid				一个RTTI运算符
	//		const_cast			强制类型转换运算符
	//		dynamic_cast		强制类型转换运算符
	//		reinterpret_cast	强制类型转换运算符
	//		static_cast			强制类型转换运算符
	// 5、表11.1(书P387)中的大多数运算符都可以通过成员或非成员函数进行重载
	//	  但下面的运算符只能通过成员函数进行重载
	//		=	赋值运算符
	//		()	函数调用运算符
	//		[]	下标运算符
	//		->	通过指针访问类成员运算符
	
	total = total - First;
	total.Show();
	std::cout << std::endl;
	total = total * 1.5;
	total.Show();
	std::cout << std::endl;

	// 友元
	// 友元有三种:
	//		友元函数、友元类、友元成员函数
	// 通过让函数成为类的友元,可以赋予该函数与类的成员函数相同的访问权限
	
	// 为何需要友元
	// 在为类重载二元运算符时(带两个参数的运算符)常常需要友元
	// 将Time对象乘以实数就属于这种情况
	// Time类示例中,重载的乘法运算符与其他两种重载运算符的区别在于,使用了两种不同的类型
	// 这限制了该运算符的使用方式,记住,左侧的操作数是调用对象
	// 即 A = B * 2.75;
	// 将被转换为下面的成员函数调用:
	// A = B.operator*(2.75);
	// 但 A = 2.75 * B; 不对应于成员函数,因为2.75不是Time类型的对象
	// 编译器不能使用成员函数调用来替换该表达式
	// 解决方法一:对服务器友好-客户警惕的(server-friendly,client-beware)解决方案,与OOP无关
	// 解决方法二:非成员函数
	//		大多数运算符都可以通过成员或非成员函数来重载
	//		非成员函数不是由对象调用的,它使用的所有值(包括对象)都是显式参数
	//		这样,编译器能够将表达式:A = 2.75 * B;
	//		与下面的非成员函数调用匹配:
	//		A = operator*(2.75, B);
	//		该函数的原型如下:
	//		Time operator*(double m, const Time & t);
	//		对于非成员重载运算符函数来,运算符表达式左边的操作数对应于运算符函数的第一个参数
	//		运算符表达式右边的操作数对应于运算符函数的第二个参数
	//		而原来的成员函数则按相反的顺序处理操作数,也就是,double值乘以Time值
	//		引发了一个新问题:非成员函数不能直接访问类的私有数据,至少常规非成员函数不能访问
	//		然而,有一类特殊的非成员函数可以访问类的私有成员,它们被称为 友元函数

	// 创建友元
	// 创建友元函数的第一步是将其原型放在类声明中,并在原型声明前加上关键字 friend :
	// friend Time operator*(double m, const Time & t);
	//		该原型味着下面两点:
	//			虽然operator*()函数在类声明中声明的,但它不是成员函数,因此不能使用成员运算符来调用;
	//			虽然operator*()函数不是成员函数,但它与成员函数的访问权限相同
	// 第二步是编写函数定义
	//		因为它不是成员函数,所以不要使用Time::限定符
	//		另外,不要在定义中使用关键字friend,定义应如下:
	//		Time operator*(double m, const Time & t)
	//		{
	//			Time result;
	//			long totalminutes = hours * mult * 60 + minutes * mult;
	//			result.hours = totalminutes / 60;
	//			result.minutes = totalminutes % 60;
	//			return result;
	//		}
	// 有了上述定义后,下面的语句:
	// A = 2.75 * B;
	// 将转换为如下的语句,从而调用刚才定义的非成员友元函数:
	// A = operator*(2.75, B);
	// 总之,类的友元函数是非成员函数,其访问权限与成员函数相同
	// 提示:如果要为类重载运算符,并将非类的项作为其第一个操作数,则可以用友元函数来反转操作数的顺序
 
	// 常见的友元:重在<<运算符
	// 
	// 1、<<的第一种重载版本
	//	要使 Time 类知道使用 cout,必须使用友元函数
	//	因为下面这样的语句使用两个对象,其中第一个是ostream类对象(cout):
	//	cout << trip;
	//	如果使用一个Time成员函数来重载<<,Time对象将是第一个操作数,像使用成员函数重载*运算符那样
	//	这意味着必须这样使用<<:
	//	trip << cout;
	//	这样会令迷惑,但通过使用友元函数,可以像下面这样重载运算符:
	//	void operator<<(ostream & os, const Time & t)
	//	{
	//		os << t.hours << " hours,"<< t.minutes << " minutes";
	//	}
	//	这样可以使用下面的语句:
	//	cout << trip;
	//	按下面这样的格式打印数据据:
	//	4 hours,23 minutes
	Time trip(4, 23);
	std::cout << trip;
	std::cout << std::endl;
	//	通常情况下,os引用cout对象,如表达式cout<<trip所示
	//	但也可以将这个运算符用于其他ostream对象,在这种情况下,os将引用相应的对象
	//	另一个ostream对象是 cerr ,它将输出发送到标准输出流——默认为显示器
	//	但在 UNIX 、Linux和Windows命令行环境中,可将标准错误重定向到文件
	//	用cout<<trip使用cout对象本身,而不是它的拷贝,因此该函数按引用(而不是按值)来传递该对象
	//	这样,表达式cout<<trip将导致os成为cout的一个别名
	//	Time对象可以按值或按引用来传递,因为这两种形式都使函数能够使用对象的值,按引用传使用的内存和时间都比按值传递少
	// 
	// 2、<<的第二种重载版本
	//	前面介绍的实现存在一个问题,像下面这样的语句可以正常工作:
	//	cout<<trip
	//	但这种实现不允许像通常那样将重新定义的<<运算符与cout—起使用:
	//	cout << "Trip time: " << trip << " (Tuesday)\n"; // can not do
	//	要理解这样做不可行的原因以及必须如何做才能使其可行,首先需要了解关于cout操作的一点知识
	//	此条语句: cout << x << y;
	//	C++从左至右读取输出语句,意味着它等同于:
	//	(cout << x) << y;
	//	正如iosream中定义的那样,<<运算符要求左边是一个ostream对象
	//  显然,因为 cout 是 ostream 对象,所以表达式 cout << x 满足这种要求
	//	然而,因为表达式 cout << x 位于 << y 的左侧,所以输出语句也要求该表达式是一个 ostream 类型的对象
	//	因此,ostream类将 operato<<()函数实现为返回一个指向ostream对象的引用
	//	具体地说,它返回一个指向调用对象(这里是cout)的引用
	//	因此,表达式(cout << x)本身就是ostream对象 cout,从而可以位于<<运算符的左侧
	//	可以对友元函数采用相同的方法 
	//	只要修改operator<<()函数,让它返回ostream对象的引用即可:
	//	std::ostream & operator<<(std::ostream& os, const Time& t)
	//	{
	//		os << t.hours << " hours," << t.minutes << " minutes";
	//		return os;
	//	}
	std::cout << "Trip time: " << trip << " (Tuesday)\n";	//can do
	//	逐语句分析:
	//	首先,下面代码调用 ostream 中的 << 定义,它显示字符串并返回 cout 对象:
	//	cout << "Trip time: "
	//	因此表达式 cout << "Trip time: " 将显示字符串,然后被它的返回值cout所替代
	//	原来的语句被简化为下面的形式:
	//	cout << trip << " (Tuesday)\n"; //以此类推
	// 
	//	这个 operator<<() 版本还可用于将输出写入到文件中:
	std::ofstream fout;
	fout.open("savetime.txt");
	fout << trip;
	//	其中最后一条语句将被转换为这样:
	//	operator<<(fout, trip);
	//	另外,正如第8章指出的,类继承属性让 ostream 引用能够指向 ostream 对象和 ofstream 对象
	// 
	// 提示:一般来说,要重载<<运算符来显示 c_name 的对象,可使用一个友元函数,其定义如下:
	//	ostream & operator<<(ostream & os, const c_name & obj)
	//	{
	//		os << ... ;	// display object contents
	//		return os;	
	//	}
	//

	 

	system("pause");
	return 0;
}