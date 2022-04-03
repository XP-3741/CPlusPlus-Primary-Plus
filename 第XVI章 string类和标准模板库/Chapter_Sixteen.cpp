#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include <ctime>
#include <cctype>

void str1_cpp();
void strfile_cpp();
void hangman_cpp();

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