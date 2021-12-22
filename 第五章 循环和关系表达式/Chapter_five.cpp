#include<iostream>
#include<string>
#include<cstring>
#include<ctime>
using namespace std;
int main()
{
	int x;
	cout << (x = 100) << endl;
	cout << x << endl;
	cout << (x < 3) << endl;
	cout << (x > 3) << endl;
	cout.setf(ios_base::boolalpha);
	cout << (x < 3) << endl;
	cout << (x > 3) << endl;

	//变量i只存在于for语句中,当程序离开循环后,这种变量会消失
	for (int i = 0; i < 3; i++)
		cout << "I love you" << endl;
	//cout << i << endl;

	//for循环访问字符串
	string word;
	word = "word";
	for (int i = word.size() - 1; i >= 0; i--)
		cout << word[i];
	cout << endl;

	//顺序点:任何完整的表达式后都有一个顺序点
	cout << (4 + x++) + (6 + x++) << endl;
	//x不是在执行完x+4就加一的,而是整个表达式完成才递增

	//前缀格式与后缀格式
	//C++允许对类定义运用这些运算符,在这种情况下,用户这样定义前缀函数:将值加1,然后返回结果
	//但后缀版本得先复制一个副本,将其加1,然后将复制的版本返回.因此,对类而言,前缀版本的效率比后缀版本高
	//对于内置类型,采用哪种格式都不会有差别;但对于用户定义的类型,如果有用户定义的递增或递减运算符,前缀效率高

	//前缀递增、递减和解除引用运算符优先级相同,从右到左结合
	//后缀递增、递减优先级相同,但比前缀优先级高,从左到右结合
	int* pt = &x;
	++* pt;	//先取得pt指向的值,然后将其加1
	*++pt;	//先将++应用于pt,然后将*应用于被递增的pt
	*pt++;	//++用于pt,对指针递增.然而后缀运算符意味着将原来的地址而不是递增后的新地址解除引用,
			//语句执行完后pt指向后一个地址

	x = 17, 240;//,运算符的优先级是最低的
	cout << x << endl;
	x = (17, 240);//,运算符的运算顺序从左向右,结果是最右边部分
	cout << x << endl;

	word == "mate";	//这不是判断两个字符串是否相同,而是查看它们的是否存储在相同位置上,答案是否定的

	//两个字符串即使存储在长度不同的数据中,也可能相同
	char big[10] = "Daffy";
	char little[6] = "Daffy";

	//strcmp(&string,&string);
	//头文件cstring
	//接受两字符串地址作为参数,可以是指针、字符串常量和字符数组名
	//两字符串相同,返回零
	//第一个字符串按字母顺序排在第二个之前,返回负值;反之返回正值
	char worrd[5] = "?ate";
	for (char ch = 'a'; strcmp(worrd, "mate"); ch++) {
		cout << worrd << endl;
		worrd[0] = ch;
	}
	cout << "result:" << worrd << endl << endl;

	//比较string类字符串
	//类设计能够使用关系运算符进行比较
	//类函数重载(重新定义)了这些运算符
	string word1 = "?ate";
	for (char ch = 'a'; word1 != "mate"; ch++) {
		cout << word1 << endl;
		word1[0] = ch;
	}
	cout << "result:" << word1 << endl;

	//要打印ASXII码,要用强制类型转换
	cout << static_cast<int>(word1[0]) << endl;
	//string对象不使用空字符来标记字符串结尾

	//函数clock()
	//返回程序开始执行后所用的系统时间
	//问题: 1.返回时间的单位不一定是秒	2.返回类型在某些系统上可能是long,在另一些系统上可能是unsigned long或适合系统的其他类型
	//头文件ctime提供了解决方案
	//它定义了一个符号常量——CLOCKS_PER_SEC,该常量等于每秒钟包含的系统时间单位数,系统时间除以这个值就是秒数
	//其次,ctime将clock_t作为clock()返回类型的别名
	//这意味着可以将变量声明为clock_t类型,编译器将把他转换为long,unsigned int或适合系统的其他类型

	//用clock()创建演示循环
	cout << "Enter de delay time,in second: ";
	float secs;
	//cin >> secs;
	secs = 0;
	clock_t delay = secs * CLOCKS_PER_SEC;	//convert to clock ticks
	cout << "starting\a\n";
	clock_t start = clock();
	while (clock() - start < delay)				//wait until time elapses
		//cout << clock()/ CLOCKS_PER_SEC << endl;
		;//note the semicolon
	cout << "done \a\n";
	//该程序以系统时间单位为单位计算延时时间,避免在每轮循环中将系统时间转换为秒

	//类型别名
	//方法一:
		//使用预处理器: #define BYTE char
		//预处理器将在编译程序时用char替换所有的BYTE,从而使BYTE称为char的别名
	//方法二:
		//使用关键词typedef来创建别名
		//typedef char byte;
		//typedef char* byte_point;

	//使用#define声明一系列指针变量时,就不合适
	//#define FLOAT_POINT float*;
	//FLOAT_POINT pa,pb;
	//预处理器置换将该声明转换为:
	//float* pa,pb;		//pb不是指针
	//typedef就不会出现这样的问题

	//基于范围的for循环
	//对数组(或容器类,如vector和array)的每个元素执行相同的操作
	double prices[5] = { 1.2,1.3,1.4,1.5,1.6 };
	for (double x : prices)
		cout << x << '\t';
	cout << endl;
	//x最初表示数组prices的第一个元素,显示第一个元素后,不断执行循环,而x以此表示数组的其他元素

	//要修改数组的元素,需要使用不同的循环变量语法
	for (double& x : prices)
		x *= 0.80;
	//符号&表明x是一个引用变量,这种声明让接下来的代码能够修改数组的内容
	for (double x : prices)
		cout << x << '\t';
	cout << endl;

	//还可结合使用基于范围的for循环和初始化列表
	for (int x : {3, 4, 5, 6, 7})
		cout << x << " ";
	cout << '\n';

	//cin对象支持3种不同模式的单字符输入
	//1.使用原始的cin进行输入

	/*
	char ys;
	int count = 0;
	cout << "Enter the character; enter # to quit:\n";
	cin >> ys;
	while (ys != '#'){	//哨兵字符,作为停止标记
		cout << ys;		//按下键盘上的键不能自动将字符显示在屏幕上,程序必须通过回显输入字符来完成这项工作,由操作系统处理
		count++;		
		cin >> ys;		//输入:see ken run#really fast
	}
	cout << endl << count << " characters read\n";	//输出:seekenrun	
													//9 characters read
	*/

	//cin读取char值时,与读取其他类型一样,忽略空格和换行符,因此空格没有被显现,也没有被包括在计数中
	//发送给cin的出入被缓冲,只有按下回车键后,输入的内容才会被发送给程序,但程序遇到#字符后将结束对输入的处理

	//2.使用cin.get(char)进行补救
	//通常逐个字符取输入的程序需要检查每个字符,包括空格、制表符和换行符

	/*
	char ys;
	int count = 0;
	cout << "Enter the character; enter # to quit:\n";
	cin.get(ys);
	while (ys != '#') {	
		cout << ys;		
		count++;
		cin.get(ys);		//输入:see key run#really fast
	}
	cout << endl << count << " characters read\n";	//输出:see key run	
													//11 characters read
													*/

	//c语言中,想要修改变量的值,必须将变量的地址传递给函数
	//但上面的程序cin.get()传递的是ch而不是&ch
	//C++中,只要函数将参数声明为引用类型即可
	//头文件iostream将cin.get(ch)的参数声明为引用类型

	//函数重载的OOP特性
	//函数重载允许创建多个同名函数,条件是它们的参数类型不同
	//cin.get(char);		cin.get(char*,int);		ch = cin.get();

	//文件尾条件
	//如果输入来自于文件则可以使用一种功能更强大的技术——检测文件尾(EOF)
	//C++输入工具和操作系统协同工作,来检测文件尾并将这种信息告知程序
	//很多操作系统(Unix,Linux,Windows命令提示符模式)都支持重定向,允许用文件替换键盘输入
	//如Windows中有个gofish.exe的可执行程序和fishtale的文本文件,则可在命令提示符模式下输入
	//gofish < fishtale
	//程序将从fishtale获取输入
	// < 符号时Unix和Windows命令提示符模式的重定向运算符

	//很多操作系统都允许通过键盘来模拟文件尾条件
	//Unix中,可以在行首按下Ctrl+D来实现;Windows命令提示符下,可以在任意位置按下Ctrl+Z和Enter

	//检测到EOF后,cin将两位(eofbit和failbit)都设置为1
	//可以通过成员函数eof()来查看eofbit是否被设置
	//如果检测到EOF,则cin.eof()将返回bool值true,否则返回false
	//同样,eofbit或failbit别设置为1,则fail()成员函数返回true,否则返回false
	//eof()和fail()方法报告最近读取的结果
	//也就是说他们是时候报告,而不是预先报告
	//因此应将cin.eof()或cin.fail()测试放在读取后
	/*
	int count = 0;
	char ch;
	cin.get(ch);
	while (cin.fail() == false)	// while(!cin.fail())
	{
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << " characters read\n";
	*/

	//cin.clear()方法可以清楚EOF标记,使输入继续

	//方法cin.get(char)的返回值是一个cin对象
	//然而,istream类提供了一个可以将istream对象(如cin)转换为bool值的函数
	//当cin出现在需要bool值的地方(如在while循环的测试条件中)时,该转换函数将被调用
	//如果最后一次读取成功,则转换得到的bool值为true,否则为false
	//可以改写成
	//while(cin)	//while input is successful
	//这比!cin.fail或!cin.eof()更通用,因为它可以检测到其他失败的原因,如磁盘故障
	//最后,由于cin.get(char)的返回值为cin,因此可以将循环精简成:
	/*
		while(cin.get(ch))
		{
			...
		}
	*/
	//这样,cin.get(char)只被调用了一次
	/*
	char ch;
	int count = 0;
	while (cin.get(ch))	// while(!cin.fail())
	{
		cout << ch;
		++count;
	}
	cout << endl << count << " characters read\n";
	*/

	//ch = cin.get();将字符编码作为int值返回
	//cin.get(ch);返回一个对象,而不是读取字符

	//put()的三种原型:put(char),put(signed char),put(unsigned char)
	//给put()传递一个int参数将导致错误消息,因为转换int的方法不止一种
	//cout.put(char(ch))

	return 0;
}