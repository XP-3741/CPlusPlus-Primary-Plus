#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include <ctime>
#include <cctype>
#include<memory>		// for auto_ptr, unique_ptr, shared_ptr

void str1_cpp();
void strfile_cpp();
void hangman_cpp();
void str2_cpp();
void smrtptrs_cpp();
void fowl_cpp();

int main()
{
	// string 类的构造函数
	//		构造函数									描述
	//	string(const char* s)				将 string 对象初始化为 s 指向的 NBTS
	//	string(size_type n,char c)			创建一个包含 n 个元素的 string 对象,其中每个元素都被初始化为字符 c
	//	string(const string& str)			将一个 string 对象初始化为 string 对象 str(复制构造函数)
	//	string()							创建一个默认的 string 对象,长度为 0(默认构造函数)
	//	string(const char* s,size_type n)	将 string 对象初始化为 s 指向的 NBTS 的前 n 个字符
	//										即使超过了 NBTS 的结尾
	//	template<class Iter>
	//	string(Iter begin,Iter end)			将 string 对象初始化为区间[begin,end)内的字符
	//										其中 begin 和 end 的行为就像指针
	//										用于指定位置,范围包括 begin 在内,但不包括 end
	//	string(const string& str,			将一个 string 对象初始化为对象 str 中从位置 pos
	//			string size_type pos = 0,	开始到结尾的字符,或从位置 pos 开始的 n 个字符
	//			size_type n = npos)
	//	string(string&& str) noexcept		这是 C++11 新增的,它将一个 string 对象初始化为
	//										string 对象 str,并可能修改 str(移动构造函数)
	//	string(initializer_list<char>il)	这是 C++11 新增的,它是一个 string 对象初始化
	//										为初始化列表 il 中的字符
	// 
	//	使用构造函数时都进行了简化,即隐藏了一个事实:
	//	string 实际上是模板具体化 basic_string<char> 的一个 typedef
	//	同时省略了与内存管理相关的参数
	//	size_type 是一个依赖于实现的整型,是在头文件 string 中定义的
	//	string 类将 string::npos 定义为字符串的最大长度,通常为 unsigned int 的最大值
	//	另外,表格中使用缩写 NBTS(null-terminated string)来表示以空字符结束的字符串--传统C字符串
	if (false) str1_cpp();
	
	// string 类输入
	//	C-风格字符串,有三种方式:
	//		char info[100];
	//		cin >> info;			// read a word
	//		cin.getline(info, 100);	// read a line, discard \n
	//		cin.get(info, 100);		// read a line, leave \n in queue
	//	对于 string 对象,有两种方式:
	//		string stuff;
	//		cin >> stuff;			// read a word
	//		getline(cin, stuff);	// read a line, discard \n
	//	两个版本的 getline() 都有一个可选参数,用于指定使用那个字符来确定输入边界:
	//		cin.getline(info, 100, ';');	// read up to ; ,discard
	//		getline(stuff, ';');			// read up to ; ,discard
	//	在功能上,他们之间主要区别在于,string 版本的将自动调整目标 string 对象大小
	//	限制因素:
	//		- string 对象的最大允许长度,由常量 string::npos 指定
	//		- 使用的内存量
	//	string 版本的 getline() 函数从输入中读取字符,并将其存储到目标 string 中
	//	直到遇到下列三种情况之一:
	//		- 到达文件尾,在这种情况下,输入流的 eofbit 将被设置
	//		  这意味着方法 fail() 和 eof() 都将返回 true
	//		- 遇到分界字符(默认为\n),在这种情况下,将把分界字符从输入流中删除,但不存储它
	//		- 读取的字符数达到最大允许值,在这种情况下,将设置输入流的 failbit
	//		  这意味着方法 fail() 将返回 true
	//	输入流对象有一个统计系统,用于跟踪流的错误状态
	//		在这个系统中,检测到文件尾后将设置 eofbit 寄存器
	//		检测到输入错误时将设置 failbit 寄存器
	//		出现无法识别的故障(如硬盘故障)时将设置 badbit 寄存器
	//		一切顺利时将设置 goodbit 寄存器
	//	string 版本的 operator<<() 函数行为与此类似
	//	只是它不断读取
	//	直到遇到空白字符并将其留在输入队列中
	//	而不是不断读取,直到遇到分界字符并将其丢弃
	//  空白字符指的是空格,换行符和制表符
	//	更普遍的说,是任何将其作为参数来调用 isspace() 时,该函数返回 ture 的字符
	// 
	//	下例程序是一个从文件读取字符的简短示例
	//	它假设文件中包含用冒号字符分隔的字符串,并使用指定分节符 getline() 方法
	//	然后显示字符串并给他们编号
	if (false) strfile_cpp();
	// 注意,将 : 指定为分解字符后,换行符将被视为常规字符
	// 
	// 使用字符串
	//	对于每个关系运算符,都以三种方式被重载
	//	以便能够将 string 对象与另一个 string 对象、C-风格字符串比较
	//	并能够将 C-风格字符串 与 string 对象进行比较:
	//		operator<(const string&, const string&)
	//		operator==(const string&, const char *)
	//		operator!=(const char *, const string&)
	//	确定字符串长度
	//		size()和length()成员函数都返回字符串中的字符数
	//		length()成员来自较早版本的 string 类
	//		而 size() 则是为提供 STL 兼容性而添加的
	// 
	// 重载的 find() 方法
	//		方法原型												描述
	//	size_type find(const string& str,			从字符串的 pos 位置开始,查找子字符串 str
	//	size_type pos = 0) const					如果找到返回该子字符串首次出现时其首字符的索引
	//												否则,返回 string::npos
	//	size_type find(const char* s,				从字符串的 pos 位置开始,查找子字符串 s
	//	size_type pos = 0) const					如果找到返回该子字符串首次出现时其首字符的索引
	//												否则,返回 string::npos
	//	size_type find(const char* s,				从字符串的 pos 位置开始,查找 s 的前 n 个字符组成的子字符串
	//	size_type pos = 0,size_type n)				如果找到返回该子字符串首次出现时其首字符的索引
	//												否则,返回 string::npos
	//	size_type find(char ch,						从字符串的 pos 位置开始,查找字符 ch
	//	size_type pos = 0) const					如果找到,则返回该字符首次出现的位置
	//												否则,返回 string::npos
	// 
	//	string 库还提供了相关的方法:
	//		rfind()、find_first_of()、find_last_of()、find_first_not_of()和find_last_not_of()
	//		它们的重载函数特征标都与 find()方法相同
	//		rfind()方法
	//			查找子字符串或字符最后一次出现的位置
	//		find_first_of()方法
	//			在字符串中查找参数中任何一个字符首次出现的位置
	//			例如下面语句返回 r 再"cobra"中的位置,因为这是"hark"中各个字母在"cobra"首次出现的位置:
	//			int where = snake1.find_first_of("hark");
	//		find_last_of()方法
	//			功能与上相同,只是他查找的是最后一次出现的位置
	//			因此下面的语句返回 a 在"cobra"中的位置:
	//			int where = snake1.find_last_of("hark");
	//		find_first_not_of()方法
	//			在字符串中查找第一个不包含在参数中的字符
	//			因此下面的语句返回 c 在"cobra"中的位置,因为"hark"中没有 c:
	//			int where = snake1.find_last_of("hark");
	if(false)	hangman_cpp();
	// string 提供的其他功能
	//	string 库还提供了很多其他的工具,包括完成下述功能的函数:
	//		(附录F简要地介绍了 string 库中的函数)
	//	方法 capacity() 返回当前分配给字符串的内存块的大小
	//	而 reserve() 方法能够请求内存块的最小长度
	if(false)	str2_cpp();

	// 如果有 string 对象,但需要 C-风格字符串,该如何办:
	//		例如,可能想打开一个其名称存储在 string 对象中的文件
	//			string filename;
	//			cout << "Enter file name: ";
	//			cin >> filename;
	//			ofstream fout;
	//		不幸的是,open()方法要求使用一个 C-风格字符串作为参数
	//		幸运的是, c_str() 方法返回一个指向 C-风格字符串的指针
	//		该 C-风格字符串的内容与用于调用 c_str() 方法的 string 对象相同:
	//			fout.open(filename.c_str());
	// 
	// 字符串种类
	//	本节将 string 类看作是基于 char 类型的
	//	事实上,正如前面指出,string 库实际上是基于一个模板类的:
	//		template<class charT, class traits = char_traits<charT>,
	//				class Allocator = allocator<charT> >
	//		basic_string {...}
	//	模板 basic_string 有4个具体化,每个具体化都有一个 typedef 名称:
	//		typedef basic_string<char> string;
	//		typedef basic_string<wchar_t> wstring;
	//		typedef basic_string<char16_t> u16string;		// C++11
	//		typedef basic_string<char32_t> u32string;		// C++11
	// 
	// 智能指针模板类
	//	智能指针是行为类似于指针的类对象,但这种对象还有其他功能
	//	这三个智能指针模板(auto_ptr,unique_ptr和shared_ptr)都定义了类似指针的对象
	//	可以将 new 获得(直接或间接)的地址赋给这种对象
	//	当智能指针过期时,其析构函数将使用 delete 来释放内存
	//	因此,如果将 new 返回的地址赋给这些对象,无需记住稍后释放这些内存
	if(false)	smrtptrs_cpp();
	//	所有智能指针都有一个 explicit 构造函数,该构造函数将指针作为参数
	//	因此不需要自动将指针转换为智能指针对象:
	//		shared_ptr<double> pd;
	//		double* p_red = new double;
	//		pd = p_reg;								// not allowed (implicit conversion)
	//		pd = shared_ptr<double>(p_red);			// allowed (explicit conversion)
	//		shared_ptr<double> pshared = p_reg;		// not allowed (implicit conversion)
	//		shared_ptr<double> pshared(p_reg);		// allowed (explicit conversion)
	//	由于智能指针模板类的定义方式,智能指针对象的很多方面都类似于常规指针
	//	例如,如果 ps 是一个指针指针对象,则可以对他执行解除引用操作(*ps)
	//	用它来访问结构成员(ps->puffIndex),将他赋给指向相同类型的常规指针
	//	还可以将指针指针对象赋给另一个同类型的智能指针对象,但将引起一个问题,将在加一节讨论
	//	在此之前,先说说对全部三种智能指针都应避免的一点:
	//		string vacation("T wandered lonely as a cloud.");
	//		shared_ptr<string> pvac(&vacation);		// NO!
	//	pvac 过期时,程序将把 delete 运算符用于非堆内存,这是错误的
	// 
	// 有关智能指针的注意事项
	//	为何有三种智能指针?实际上有四种,但本书不讨论 weak_ptr,为何摒弃 auto_ptr?
	//	先来看下面的赋值语句:
	//		auto_ptr<string> ps (new string("Fuck YOU"));
	//		auto_ptr<string> vacation;
	//		vacation = ps;
	//	如果 ps 和 vacation 是常规指针,则两个指针将指向同一个 string 对象
	//	这是不能接受的,因为程序将试图删除同一个对象两次----一次是 ps 过期时,另一个是 vacation 过期
	//	要避免这种问题,方法有多种
	//		- 定义赋值运算符,使之执行深复制
	//		  这样两个指针将指向不同的对象,其中的一个对象是另一个对象的副本
	//		- 建立所有权(ownership)概念,对于特定的对象,只能有一个智能指针可拥有它
	//		  这样只有拥有对象的智能指针的构造函数会删除该对象
	//		  然后,让赋值操作转让所有权
	//		  这就是用于 auto_ptr 和 unique_ptr 的策略,但 unique_ptr 的策略更严格
	//		- 创建智能更高的指针,跟踪引用特定对象的智能指针数
	//		  这称为引用计数(reference counting)
	//		  例如,赋值时,计数将加1,而指针过期时,计数减1
	//		  仅当最后一个指针过期时,才调用 delete,这是 shared_ptr 的策略
	//	当然,同样的策略也适用于复制构造函数
	//	下面程序是一个不合适使用 auto_ptr 的示例
	if(false)	fowl_cpp();
	//	当 i = 2 时,异常终止程序
	//	问题在于M将所有权从 films[2] 转让给 pwin
	//	这导致 films[2] 不在引用该字符串,在 auto_ptr 放弃对象所有权后,便可能使用它来访问对象
	//	当程序打印 films[2] 指向的字符串时,却发现这是一个空指针
	//	如果使用 shared_ptr 代替,则程序正常运行
	//	如果使用 unique_ptr 会与 auto_ptr 一样,其也采用所有权模型
	//	但使用 unique_ptr 时,不会等到程序运行阶段崩溃,而在编译器因下述代码出现错误:
	//		pwin = films[2];
	// 
	// unique_ptr 为何优于 auto_ptr
	//	下面的语句:
	//		auto_ptr<string> p1(new string("auto"));	// #1
	//		auto_ptr<string> p2;						// #2
	//		p2 = p1;									// #3
	//	在语句 #3 中,p2 接管对象的所有权后,p1 的所有权将被剥夺
	//	前面说过,这是件好事,可防止 p1 和 p2 的析构函数试图删除同一个对象
	//	但如果程序随后试图使用 p1,这是件坏事,因为 p1 不在指向有效数据
	//	但如果是 unique_ptr 编译器会认为非法
	//	但有时候,将一个智能指针赋给另一个并不会留下危险的悬挂指针,假设有如下函数定义:
	//		unique_ptr<string> demo(const char* s)
	//		{
	//			unique_ptr<string> temp(new string(s));
	//			retuen temp;
	//		}
	//	并假设编写了如下代码:
	//		unique_ptr<stirng> ps;
	//		ps = demo("Uniquely special");
	//	demo() 返回一个临时 unique_ptr ,然后 ps 接管了原本归返回的 unique_ptr 所有的对象
	//	而返回的 unique_ptr 被销毁,这没有问题,因为 ps 拥有了 string 对象的所有权
	//	
	//

	return 0;
}

void str1_cpp()
{// introducing the string class
	using namespace std;
	string one("Lottery Winner!");		// ctor #1
	cout << one << endl;				// overloaded <<
	string two(20, '$');				// ctor #2
	cout << two << endl;
	string three(one);					// ctor #3
	cout << three << endl;
	one += " Oops!";					// overloaded +=
	cout << one << endl;
	two = "Sorry! That was ";
	three[0] = 'P';
	string four;						// ctor #4
	four = two + three;					// overloaded +, =
	cout << four << endl;
	char alls[] = "All's well that ends well";
	string five(alls, 20);				// ctor #5
				// 如果用 40 代替 20,将导致 15 个无用的字符被复制到 five 的结尾处
				// 即构造函数将内存中位于字符串"All's well that ends well"后面的内容作为字符
	cout << five << "!\n";
	string six(alls + 6, alls + 10);	// ctor #6
	cout << six << ", ";
	string seven(&five[6], &five[10]);	// ctor #6 again
	cout << seven << "...\n";
	string eight(four, 7, 16);			// ctor #7
	cout << eight << " in motion!" << endl;
}

void strfile_cpp()
{
	using namespace std;
	ifstream fin;
	//fin.open("tobuy.txt");
	fin.open("E:\\Projects_Myself\\VS2022_Projects\\C++PrimaryPlus\\第XVI章 string类和标准模板库\\tobuy.txt");
	// C-风格字符串中转义序列 \\ 表示一个斜杠
	if (fin.is_open() == false)
	{
		cerr << "Can't open file. Bye.\n";
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0;

	getline(fin, item, ':');
	while (fin) {	// while input is good
		++count;
		cout << count << ": " << item << endl;
		getline(fin, item, ':');
	}
	cout << "Done\n";
	fin.close();
	// std::cin.get();
	// std::cin.get();
}

void hangman_cpp()
{
	using std::string;
	using std::cout;
	using std::cin;
	using std::tolower;
	using std::endl;

	const int NUM = 26;
	const string wordlist[NUM]= { "apiary", "beetle", "cereal",
	"danger", "ensign", "florid", "garage", "health", "insult",
	"jackal", "keeper", "loaner", "manage", "nonce", "onset",
	"plaid", "quilt", "remote", "stolid", "train", "useful",
	"valid", "whence", "xenon", "yearn", "zippy" };

	std::srand(std::time(0));
	char play;
	cout << "Will you play a word game? <y/n> ";
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		string target = wordlist[std::rand() % NUM];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout << "Guess my secret word. It has " << length
			<< " letters, and you guess\n"
			<< "one letter at a time. You get " << guesses
			<< " wrong guesses.\n";
		cout << "Your word: " << attempt << endl;
		while (guesses > 0 && attempt != target)
		{
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos
				|| attempt.find(letter) != string::npos)
			{
				cout << "You already guessed that. Try again.\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "Oh, bad guess!\n";
				--guesses;
				badchars += letter; // add to string
			}
			else
			{
				cout << "Good guess!\n";
				attempt[loc] = letter;
				// check if letter appears again
				loc = target.find(letter, loc + 1);
				while (loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "Your word: " << attempt << endl;
			if (attempt != target)
			{
				if (badchars.length() > 0)
					cout << "Bad choices: " << badchars << endl;
				cout << guesses << " bad guesses left\n\n";
			}
		}
		if (guesses > 0)
			cout << "\nThat's right!\n";
		else
			cout << "\nSorry, the word is " << target << ".\n";

		cout << "\nWill you play another? <y/n> ";
		cin >> play;
		play = tolower(play);
	}
	cout << "\nBye\n";
}

void str2_cpp()
{
	using namespace std;
	string empty;
	string small = "bit";
	string larger= "Elephants are a girl's best friend";
	cout << "Sizes:\n";
	cout << "\tempty: " << empty.size() << endl;
	cout << "\tsmall: " << small.size() << endl;
	cout << "\tlarger: " << larger.size() << endl;
	cout << "Capacities:\n";
	cout << "\tempty: " << empty.capacity() << endl;
	cout << "\tsmall: " << small.capacity() << endl;
	cout << "\tlarger: " << larger.capacity() << endl;
	empty.reserve(50);
	cout << "Capacity after empty.reserve(50): "
		<< empty.capacity() << endl;
	// cin.get();
}

void smrtptrs_cpp()
{// smrtptrs.cpp -- using three kinds of smart pointers
	class Report
	{
	private:
		std::string str;
	public:
		Report(const std::string s):str(s) { std::cout << "Object created!\n"; }
		~Report() { std::cout << "Object deleted!\n\n"; }
		void comment() const { std::cout << str << "\n"; }
	};

	{
		Report* ps = new Report("using nohting");
		ps->comment();
		std::cout << std::endl;
	}
	{
		std::auto_ptr<Report>ps(new Report("using auto_ptr"));
		ps->comment();
	}
	{
		std::shared_ptr<Report>ps(new Report("using shared_ptr"));
		ps->comment();
	}
	{
		std::unique_ptr<Report>ps(new Report("using unique_ptr"));
		ps->comment();
	}
}

void fowl_cpp()
{// fowl.cpp  -- auto_ptr a poor choice
	using namespace std;
	auto_ptr<string> films[5] =
	{
		auto_ptr<string>(new string("Fowl Balls")),
		auto_ptr<string>(new string("Duck Walks")),
		auto_ptr<string>(new string("Chicken Runs")),
		auto_ptr<string>(new string("Turkey Errors")),
		auto_ptr<string>(new string("Goose Edds"))
	};
	auto_ptr<string> pwin;
	/*shared_ptr<string> films[5] =
	{
		shared_ptr<string>(new string("Fowl Balls")),
		shared_ptr<string>(new string("Duck Walks")),
		shared_ptr<string>(new string("Chicken Runs")),
		shared_ptr<string>(new string("Turkey Errors")),
		shared_ptr<string>(new string("Goose Edds"))
	};
	shared_ptr<string> pwin;
	*/
	pwin = films[2];	// films[2] loses ownership

	cout << "The nominees for best avian baseball film are\n";
	for (int i = 0; i < 5; i++)
		cout << *films[i] << endl;
	cout << "The winner is " << *pwin << "!\n";
	// cin.get();
}