#include<iostream>
#include<string>

void str1_cpp();

int main()
{
	int whichOne = 1;
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
	if (whichOne == 1)str1_cpp();

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