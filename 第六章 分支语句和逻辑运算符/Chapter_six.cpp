#include<iostream>
#include<climits>
#include<cctype>
#include <fstream>	//for file I/O
#include<cstdlib>	//exit
using namespace std;

bool is_int(double x);
int main()
{
	//加密输出
	/*
	char ch;
	cin.get(ch);
	while (ch != '.') {
		if (ch == '\n')
			cout << ch;
		else
			cout << ++ch;//如果改成ch+1则会出现一串数字
		cin.get(ch);
	} 
	*/

	//C++逻辑OR和逻辑AND运算符优先级都低于关系运算符
	//!运算符优先级高于所有关系运算符和算术运算符
	//逻辑AND运算符优先级高于逻辑OR运算符
	//C++确保程序从左向右进行计算逻辑表达式,并在知道答案后立刻停止

	//其他表示方法
	//	&&		=		and
	//  ||		=		or
	//  !		=		not
	//C语言需头文件ios646.h
	//C++不要求使用头文件

	//字符函数库cctype
	//C++继承了C语言这个函数软件包,它可以简化诸如确定字符是否为大写字母,数字,标点符号等工作
	//头文件	cctype
	//返回类型为int
	//isalnum()					如果参数是字母数字,即字母数字,该函数返回true
	//isalpha()					如果参数是字母,该函数返回true
	//iscntrl()					如果参数是控制字符,该函数返回true
	//isdigit()					如果参数是数字(0~9),该函数返回true
	//isgraph()					如果参数是除空格之外的打印字符,该函数返回true
	//islower()					如果参数是小写字母,该函数返回true
	//isprint()					如果参数是打印字符(包括空格),该函数返回true
	//ispunct()					如果参数是标点符号,该函数返回true
	//isspace()					如果参数是标准空白字符,如空格,进纸,换行符,回车,水平制表符或者垂直制表符,该函数返回true
	//isupper()					如果参数是大写字母,该函数返回true
	//isxdigit()				如果参数是十六进制数字,即0~9,a~f或A~F,该函数返回true
	//tolower()					如果参数是大写字符,则返回其小写,否则返回该参数
	//toupper()					如果参数是小写字符,则返回其大写,否则返回该参数

	//?:运算符
	//int c = a > b ? a : b;
	//等价于
	//int c;	if(a>b)	c=a;else  c=b;


	//goto语句
	/*
	char ch = 'p';
	if(ch == 'p')		goto paris;	//跳转到pris
	cout << "..." ;
	paris:cout<<"sb";
	*/
	/*
	const int MAX = 5;
	double fish[MAX];
	int i = 0;
	while (i<MAX && cin >> fish[i])//cin >> fish[i]实际上是一个cin方法函数调用,该函数返回cin；如果cin位于测试条件中,将被转成bool型,输入成功为true
		if (++i < MAX)			   //如果i=MAX,则循环测试会结束,而不会将一个值读入到数组中
			cout << "fish #" << i + 1 << ": ";
	cout << endl << "DATA:";
	for (int j = 0; j < i; j++)
		cout << fish[j] << " ";
	*/
	/*
	const int MAX = 5;
	int golf[MAX];
	for (int i = 0; i < MAX; i++) {
		cout << "round #" << i + 1 << ": ";
		while (!(cin >> golf[i])) {		//当输入不是数字时,则会判断为true,进入循环

			cout << "state:" << cin.rdstate() << endl;
			//  0 ：goodbit 无错误
			//	1 ：Eofbit 已到达文件尾
			//	2：failbit 非致命的输入 / 输出错误，可挽回
			//	3：badbit　致命的输入 / 输出错误, 无法挽回

			cin.clear();				//清理错误表示符

			cout << "state:" << cin.rdstate() << endl;//再次查看错误状态 对应0 无错误

			while (cin.get() != '\n')	//读取行尾之前的所有输入,从而删除这一行中的错误输入
				continue;

			//cin.sync();//清理缓冲区内容
			cout << "Please enter a number: ";
		}
	}*/

	//C++使得将读取键盘输入和在屏幕上显示(统称控制台输入/输出)的技巧用于文件输入/输出(文件I/O)非常简单
	//使用cin进行输入时,程序将输入视为一系列字节,其中每个字节都被解释为字符编码
	//不管目标数据类型是什么,输入一开始都是字符数据——文本数据
	//然后cin对象负责将文本转换成其他类型
	//假设有如下实例输入行:	
	//38.5 19.2

	//首先使用char数据类型的情况:
	//char ch;
	//cin >> ch;
	//输入行中的第一个字符被赋给ch,即3,其字符编码(二进制)被储存在变量ch中
	//输入和目标变量都是字符,因此不需要进行转换
	//注意,这里存储的数值不是3,而是字符3的编码
	//执行上述输入语句后,输入队列中的下一个字符为字符8,下一个输入操作将对其进行处理

	//接下来看看int类型：
	//int n;
	//cin >> n;
	//在这种情况下 cin将不断读取,直到到遇到非数字字符
	//也就是说它将读取3和8,这样句点将成为输入队列中的下一个字符
	//cin通过计算发现这两个字符对应数值38 ,因此将38的二进制编码复制到变量n中

	//接下来看看double类型：
	//double x;
	//cin >> x;
	//在这种情况下 cin将不断读取,直到到遇第一个不属于浮点数的字符
	//也就是说它将读取3、8和句点和5,使得空格成为输入队列中的下一个字符
	//cin通过计算发现 这四个字符对应于数值38.5,因此将38.5的二进制编码（浮点格式）复制到变量x中
	
	//接下来看看char数组:
	//char word[50];
	//cin >> word;
	//在这种情况下 cin将不断读取,直到到遇空白字符
	//也就是说它将读取3、8、句点 5,使空格成为输入队列中的下一个字符
	//然后,cin将这4个字符的字符编码存储到数组word中,并在末尾加上一个空字符.这里不要进行任何转换
	
	//另一种使用char数组來存储输入的情况:
	//char word[50];
	//cin.getline(word,50);
	//在这种情下cin将不断读取,直到遇到换行符（示例输入行少50个字符）
	//所有字符都将被存储到组word中,并在末尾加上一个空字符
	//换行符被丢弃，输入队列中的下一个字符是下一行中的第一个字符。这里不需要进行任何转换
	
	//这里的要点是，输入一开始为文本。因此，控制台输入的文件版木是文本文件， 每个字节都存储
	//一个字符编码的文件。并非所有的文件都是文本文件，例如，数据库和电子表格以数值格式（即二进制整
	//数或浮点格式）来存储数值数据。另外，字处理文件中可能包含文本信息 但也可能包含用于描述格式、
	//字体、打印机等的非文本数据。

	//对于文件输入，C++使用类似cout的东西
	//头文件iostream声明了一个名为cout的ostream变量(对象）

	//文件输出与此极其相似
	//必须包含头文件fstream
	//头文件fstream定义了一个用于处理输出的ofstream类
	//需要声明一个或多个ofstream变量（对象），并以自己喜欢的方式对其进行命名，条件是遵守常用的命名规则
	//必须指明名称空间std;例如，为引用元素ofstream,必须使用编译指令using或前缀std::
	//需要将ofstream对象与文件关联起来。为此，方法之一是使用open()方法
	//使用完文件后，应使用方法close()将其关闭
	//可结合使用ofstream对象和运算符<<来输出各种类型的数据
	//注意,虽然头文件iostream提供了一个预先定义好的名为cout的ostream对象，但您必须声明自己的ofstream对象,为其命名,并将其同文件关联起来
	//头文件<fstream>
	ofstream outFile;	//outFile an ofstream object
	ofstream fout;		//fout an ofstream object
	//下面演示了如何将这种对象与特定的文件关联起来
	outFile.open("DJ.txt");	//outFile used to write to the fish,txt file
	outFile.close();
	//char filename(50);			
	//cin >> filename;			//user specifies a name
	//fout.open(filename);		//fout used to read specified file
	double year = 520;
	outFile << year;
	char line[99] = "I love you";
	fout << line << endl;
	//重要的是，声明一个ofstream对象并将其同文件关联起來后,便可以像使用cout那样使用它.所有可
	//用于cout的操作和方法（如 <<、endl和setf())都可用于ofstream对象（如前述示例中的outFile和fout)

	//总之，使用文件输出的主要步骤如下
	//包含头文件fstream
	//创建一个ofstream对象
	//将该ofstream对象同一个文件关联起来
	//像使用cout那样使用该ofstream对象
	//使用完close(),否则该对象无法关联其他文件
	ofstream DJ;
	DJ.open("DJDJ.txt");
	DJ << fixed;
	DJ.precision(2);	//设定浮点数精度为两位
	DJ.setf(ios_base::showpoint);	//接下来的输出会输出小数点后面的0
	DJ << "DJ.I love you for thousand times." << endl;
	DJ << year << endl;
	DJ << static_cast<int>(year);
	DJ.close();

	//检查文件是否被成功打开的首先方法是使用方法is_open()
	ifstream inFile;
	inFile.open("DJ.txt");
	if (!inFile.is_open()) {
		exit(EXIT_FAILURE);	//函数exit()的原型是在头文件cstdlib中定义的
							//在该头文件中，还定义了一个用于同操作系统通信的参数值EXIT_FAILURE。函数exit()终止程序
	}
	int count = 0;
	double value;
	double sum = 0.0;   
	inFile >> value;
	while (inFile.good()) {//方法good()指出最后一次读取输入的操作是否成功
		++count;		//one more item read
		sum += value;	//calculate running total
		inFile >> value;//get next value
	}
	cout << "sum=" << sum << endl << "count=" << count << endl;
	inFile.close();



	system("pause");
	return 0;
}

bool is_int(double x)	//给读取int值的程序输入一个过大的值,很多C++实现只是将这个值截短为合适的大小,并不会通知丢失数据.也可long long
{
	if (x <= INT_MAX && x >= INT_MIN)
		return true;
	else
		return false;
}