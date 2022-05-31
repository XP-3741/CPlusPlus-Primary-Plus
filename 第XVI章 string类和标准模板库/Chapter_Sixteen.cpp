#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include <ctime>
#include <cctype>
#include<memory>		// for auto_ptr, unique_ptr, shared_ptr
#include<vector>
#include<algorithm>
#include<iterator>

void str1_cpp();
void strfile_cpp();
void hangman_cpp();
void str2_cpp();
void smrtptrs_cpp();
void fowl_cpp();
std::unique_ptr<std::string> demo(const char* s);
void vect1_cpp();
void vect2_cpp();
void vect3_cpp();

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
	//	总之,程序试图将一个 unique_ptr 赋给另一个时,如果源 unique_ptr 是个临时右值
	//	编译器允许这样做;如果源 unique_ptr 将存在一段时间,编译器将禁止这样做
	//		unique_ptr<string> pu1(new stirng "Hi ho!");
	//		unique_ptr<string> pu2;
	//		pu2 = pu1;										// not allowed
	//		unique_ptr<string> pu3;
	//		pu3 = unique_ptr<string>(new string"Yo!");		// allowed
	//	C++有一个标准库函数 std::move(),能够将一个 unique_ptr 赋给另一个
	if (false) {
		std::unique_ptr<std::string> ps1, ps2;
		ps1 = demo("Uniquely special");
		ps2 = std::move(ps1);
		ps1 = demo(" and more");
		std::cout << *ps2 << *ps1 << std::endl;
	}
	//	相比于 auto_ptr ,unique_ptr 还有一个优点
	//		它有一个可用于数组的变体,必须将 delete 和 new 配对,将 delete[] 和 new[] 配对
	//		模板 auto_ptr 使用 delete 而不是 delete[],因此只能与 new 一起使用
	//		但 unique_ptr 有使用 new[] 和 delete[] 的版本:
	//			std::unique_ptr<double[]>pda(new double(5));
	//	当 unique_ptr 为右值时,可将其赋给 shared_ptr ,这与将一个 unique_ptr 赋给另一个满足需要的条件相同
	//	模板 shared_ptr 包含一个显示构造函数,可用于将右值 unique_ptr 转换为 shared_ptr
	//	shared_ptr 将接管原来归 unique_ptr 所有的对象

	// 标准模板库
	//	STL提供了一组表示容器、迭代器、函数对象和算法的模板
	//	 - 容器是一个与数组类似的单元,可以存储若干个值,STL容器是同质的,即存储的值的类型相同
	//	 - 算法是完成特定任务(如对数组进行排序或在链表中查找特定值)的处方
	//	 - 迭代器能够用来遍历容器的对象,与能够遍历数组的指针类似.是广义指针
	//	 - 函数对象是类似于函数的对象,可以是类对象或函数指针(包括函数名,因为函数名别用作指针)
	//	STL使得能够构造各种容器(包括数组、队列和链表)和执行各种操作(包括搜索、排序和随机排序)
	//	STL不是面向对象的编程,而是一种不同的编程模式----泛型编程(generic programming)
	// 
	//	模板类 vector
	//		在计算中,矢量(vector)对应数组,而不是11章介绍的数学矢量
	//		计算矢量存储了一组可随机访问的值,即可以使用索引来直接访问矢量的第 i 个元素
	//		而不必先访问前面第 i-1 个元素
	//		要创建 vector 模板对象,可使用通常的 <type> 表示法来指出要使用的类型
	//		另外, vector 模板使用动态内存分配,因此可以用初始化参数来指出需要多少矢量
	//		由于运算符[]被重载,因此可以使用通常的数组表示法来访问各个元素
	// 
	//		分配器:
	//			与 string 类相似,各种STL容器模板都接受一个可选的模板参数
	//			该参数指定使用哪个分配器对象来管理内存
	//			例如,vector 模板的开头与下面类似:
	//			template<class T, class Allocator = allocator<T>>
	//				class vector { ...
	//			如果省略该模板参数的值,则容器模板将默认使用 allocator<T>类,这个类使用 new 和 delete
	if(false)	vect1_cpp();
	//			可对矢量执行的操作:
	//			所有的STL容器都提供了一些基本方法,其中包括
	//				size()----返回容器中元素数目
	//				swap()----交换两个容器内容
	//				begin()----返回一个指向容器第一个元素的迭代器
	//				end()----返回一个表示超过容器尾的迭代器
	//			迭代器:
	//				它是一个广义指针
	//				事实上,它可以是指针,也可以是一个可对其执行类似指针操作
	//				----如解除引用(opeartor*())和递增(如opeartor++())----的对象
	//				稍后将知道,将广义指针化为迭代器,让STL能够为各种不同的容器类
	//				(包括那些简单指针无法处理的类)提供统一的接口
	//				每个容器类都定义了一个合适的迭代器,该迭代器的类型是一个名为
	//				iterator 的 typedef,其作用域为整个类
	//				例如,要为 vector 的 double 类型规范声明一个迭代器,可以这样做:
	//					vector<double>::iterator pd;
	//				假设 scores 是一个 vector<double> 对象
	//				则可以使用迭代器 pd 执行这样的操作:
	//					pd = scores.begin();
	//					*pd = 22.3;
	//					++pd;
	//				正如你所看到的,迭代器的行为就像指针
	//				顺便一提,还有一个 C++11 自动推断类型很有用的地方
	//				例如,可以不这样做:
	//					vector<double>::iterator pd = scores.begin();
	//				而这样做:
	//					auto pd = scores.begin();
	//			回到前面的示例,什么是超过结尾(past-the-end)
	//			它是一种迭代器,指向容器最后一个元素后面的那个元素
	//		所有容器都包含刚才讨论的方法
	//		vector 模板类也包含一些只有某些STL容器才有的方法
	//			push_back()----将元素添加到矢量末尾
	//							这样做时,它将负责内存管理,增加矢量的长度	
	//			erase()----删除矢量中给定区间的元素
	//							它接受两个迭代器参数,这些参数定义了要删除的区间
	//							第一个迭代器指向区间的起始处,第二个迭代器位于区间终止处的后一个位置
	//							下列代码删除第一个和第二个元素
	//								scores.erase(scores.begin(),scores.begin()+2);
	//			insert()----功能与erase()相反,它接受3个迭代器参数
	//							第一个参数指定了新元素的插入位置
	//							第二个二个和第三个迭代器参数定义了被插入区间
	//							该区间通常是另一个容器对象的一部分
	//							例如,下面的代码将矢量 new_v 中除了第一个元素外的所有元素插入到
	//							old_v 矢量的第一个元素前面:
	//								vector<int> old_v;
	//								vector<int> new_v;
	//								...
	//								old_v.insert(old_v.begin(), new_v.begin()+1, new_v.end());
	if(false)	vect2_cpp();
	//	对矢量可执行的其他操作
	//		3个具有代表性的STL函数:
	//			for_each()----接受三个参数,前两个是定义容器中区间的迭代器,最后一个是指向函数的指针
	//							(更普遍的说,最后一个参数是一个函数对象,函数对象将稍后介绍)
	//							此函数将被指向的函数应用于容器区间中的各个元素
	//							被指向的函数不能修改容器元素的值
	//							可以用 for_each() 函数来代替 for 循环
	//							例如,可以将代码:
	//								vector<Review>::iterator pr;
	//								for (pr = books.begin(); pr != books.end(); pr++)
	//								ShowReview(*pr);
	//							替换为:
	//								for_each(books.begin(),books.end(),ShowReview);
	//							这样可避免显示地使用迭代器变量
	//			random_shuffle()----接受两个指定区间的迭代器参数,并随机排列区间中的元素
	//							例如,下面的语句随机排序 books 矢量中所有元素:
	//								random_shuffle(books.begin(),books.end());
	//							与可用于任何容器类的 for_each 不同
	// 							该函数要求容器类允许随机访问,vector 类可以做到这一点
	//							sort()函数也要求容器支持随机访问
	// 							该函数有两个版本,第一个版本接受两个定义区间的迭代器参数
	// 							并使用为存储在容器中的类型元素定义的<运算符,对区间中的元素进行操作
	// 							如果容器元素使用户定义的对象,则要使用sort()
	// 							必须定义能够处理该类型对象的operator<()函数
	//							如 Review 可这样定义:
	//								bool opeartor<(const Review & r1, const Review & r2)
	//								{
	//									if (r1.title < r2.title)
	//										return true;
	// 									else if(r1.title == r2.title && r1.rating < r2.rating)
	// 										return true;
	// 									else
	// 										return false;
	//								}
	//							如果想按照 rating 降序,可使用另一种格式的 sort()
	//							它接受三个参数,前两个参数也是指定区间的迭代器
	//							最后一个参数是指向要使用的函数指针(函数对象)
	//								bool WorseThan(const Review & r1, const Review & r2)
	//								{
	//									if(r1.rating < r2.rating)
	//										return true;
	//									else
	//										return false;
	//								}
	//								sort(books.begin(),books.end(),WorseThan);
	if(false)	vect3_cpp();
	//	基于范围的for循环(C++11)
	//		第5章说过,基于范围的for循环是为用于STL而设计的
	//			double prices[5] = {4.99, 10.99, 6.83, 9.23, 1.33};
	//			for(double x : prices)
	//				cout << x << endl;
	//		在这种for循环中,括号内的代码声明一个类型与容器存储的内容相容的变量
	//		然后指出了容器的名称,接下来,循环体使用指定的变量一次访问容器的每个元素
	//		例如下述语句:
	//			for_each(books.begin(),books.end(),ShowReview);
	//		可替换为:
	//			for(auto x : books)	ShowReview(x);
	//		不同于 for_each(),基于范围的 for 循环可修改容器内容,诀窍是指定一个引用参数
	//		例如:
	//			void InflateReview(Review &r) {r.rating++;}
	//			for(auto& x : books) InflateReview(x);
	
	//	泛型编程
	/*
		STL是一种泛型编程(generic programming)
		面向对象编程关注的是编程的数据方面,而泛型编程关注的是算法
		他们之间的共同点是抽象和创建可重用代码,但它们的理念绝然不同
		泛型编程旨在编写独立于数据类型的代码
		在C++中,完成通用程序的工具是模板
		当然,模板使得能够按泛型定义函数或类,而STL通过通用算法更进了一步
		模板让这一切成为可能,但必须对元素进行仔细设计

		为何使用迭代器:
			模板使得算法独立于存储的数据类型,而迭代器使算法独立于使用的容器类型
			模板提供了存储在容器中的数据类型的通用表示
			因此还需要遍历容器中的值的通用表示,迭代器正是这样的通用表示
			要实现 find 函数,迭代器应具备哪些特征,下面是一个简短的列表
				- 应能够对迭代器执行解除引用的操作,以便能够访问它引用的值
				  即如果 p 是一个迭代器,则应对 *p 进行定义
				- 应能够将一个迭代器赋给另一个
				  即如果 p 和 q 都是迭代器,则应对表达式 p=q 进行定义
				- 应能够将一个迭代器与另一个进行比较,看他们是否相等
				  即如果 p 和 q 都是迭代器,则应对 p==q 和 p!=q 进行定义
				- 应能够使用迭代器遍历容器中的所有元素
				  这可以通过为迭代器 p 定义 ++p 和 p++ 来实现
			对于STL中的某个类,迭代器可能是指针;而对于另一个类,则可能是对象
			唯一不同的是pr的类型
			因此,STL通过为每个类定义适当的迭代器,并以统一的风格设计类
			能够对内部表示绝然不同的容器,编写相同的代码
			使得C++11新增的自动类型推断可进一步简化:对于矢量或列表,都可以:
				for(auto pr = scores.begin();pr != scores.end();pr++)
					cout << *pr << endl;
			作为一种编程风格,最好避免直接使用迭代器,而应尽可能使用STL函数来处理细节
			也可使用C++11新增的基于范围的for循环:
				for(auto x : scores) cout << x << endl;

			来总结下STL方法
			首先是处理容器的算法,应尽可能用通用的术语来表达算法,使之独立于数据类型和容器类型
			为使通用算法能够适用于具体情况
			应定义能够满足算法需求的迭代器,并把要求加到容器设计上
			即基于算法的要求,设计基本迭代器的特征和容器特征
	*/

	// 迭代器类型
	/*
		STL定义了5种迭代器,并根据所需的迭代器类型对算法进行了描述
		这5种迭代器分别是:
		输入迭代器、输出迭代器、正向迭代器、双向迭代器和随机访问迭代器
		例如,find()的原型与下面类似:
			template<class InputIterator, class T>
			InputIterator find(InputIterator first, InputIterator last, const T& value);
		这指出,这种算法需要一个输入迭代器,同样,下面的原型指出排序算法需要一个随机访问迭代器:
			template<class RandomAccessIterator>
			void sort(RandomAccessIterator first, RandomAccessIterator last);
		对于这5种迭代器,都可以执行解除引用操作,也可进行比较,看其相等还是不等
		如果两个迭代器相同,则对它们执行解除引用操作得到的值将相同
			iter1 == iter2
			is true, then the following is also true:
			* iter1 == * iter2
			
		1.输入迭代器
			术语"输入"是从程序的角度说的,即来自容器的信息被视为输入
			就像来自键盘的信息对程序来说是输入一样
			因此,输入迭代器可被程序用来读取容器中的信息
			具体地说,对输入迭代器解除引用将使程序能够读取容器中的值,但不一定能让程序修改值
			输入迭代器必须能够访问容器中所有的值,这是通过支持++运算符(前缀和后缀格式)来实现的
			基于输入迭代器的任何算法都应当是单通行的,不依赖于前一次遍历时的迭代器值
			也不依赖于本次遍历中前面的迭代器值
			输入迭代器是单向迭代器,可以递增,但不能倒退

		2.输出迭代器
			STL使用术语"输出"来只用于将信息从程序传出给容器的迭代器
			因此程序的输出就是容器的输入
			输出迭代器与输入迭代器相似,只是解除引用让程序能修改容器值,而不能读取
			发送到显示器上的输出就是如此,cout可以修改发送到显示器的字符流
			却不能读取屏幕上的内容
			STL足够通用,其容器可以表示输出设备,因此容器也可能如此
			另外,如果算法不用读取做容器的内容就可以修改它(如通过生成要存储的新值)
			则没有理由要求它使用能够读取内容的迭代器
			简而言之,对于单通行、只读算法,可以使用输入迭代器
			而对于单通行、只写算法,则可以使用输出迭代器

		3.正向迭代器
			与输入输出迭代器相似,正向迭代器只是用++运算符来遍历容器
			所以它每次沿容器向前移动一个元素
			然而,与输入输出迭代器不同的是,它总是按相同的顺序遍历一系列值

		4.双向迭代器
			reverse 函数可以交换第一元素和最后一元素、将指向第一个元素指针加1
			将指向第二个元素的指针减1,并重复这种处理过程
			双向迭代器具有正向迭代器的所有特性,同时支持两种(前缀和后缀)递减运算符

		5.随机访问迭代器
			有些算法(如标准排序和二分查找)要求能够直接跳到容器种的任何一个元素
			这叫做 随机访问,需要随机访问迭代器
			随机访问迭代器具有双向迭代器的所有特性
			同时添加了支持随机访问的操作(如指针增加运算)和用于对元素进行排序的关系运算符
			下标列出除双向迭代器操作外,随机访问迭代器还支持的操作
			X 表示随机迭代器类型,T 表示被指向的类型,a 和 b 都是迭代器值, n 为整数
			r 为随机迭代器变量或引用

			表达式						描述
			a + n						指向 a 所指的元素后的第 n 个元素
			n + a						与 a + n 相同
			a - n						指向 a 所指向的元素前的第 n 个元素
			r += n						等价于 r = r + n
			r -= n						等价于 r = r - n
			a[n]						等价于 *(a + n)
			b - a						结果为这样的 n 值,即 b = a + n
			a < b						如果 b - a > 0,则为真
			a > b						如果 b < a,则为真
			a >= b						如果 !(a < b),则为真
			a <= b						如果 !(a > b),则为真
	*/

	// 迭代器层次结构
	/*
		下标总结了主要的迭代器功能
		其中, i 为迭代器, n 为整数

													迭代器性能
			迭代器功能			输入		输出			正向		双向		随机访问
		   解除引用读取			 有			 无				 有			 有			   有
		   解除引用写入			 无			 有				 有			 有			   有
		 固定和可重复排序		 无			 无				 有			 有			   有
			 ++i  i++			 有			 有				 有			 有			   有
		       i  i				 无			 无				 无			 有			   有
			   i[n]				 无			 无				 无			 无			   有
			  i + n				 无			 无				 无			 无			   有
			  i - n				 无			 无				 无			 无			   有
			  i += n		     无			 无				 无			 无			   有
			  i -= n			 无			 无				 无			 无			   有

		需要这么多迭代器的目的:
			为了在编写算法尽可能使用最低的迭代器,并让它适用于容器的最大区间
			这样,通过使用级别最低的输入迭代器,find()函数比那可用于任何包含可读取值的容器
			而sort()函数由于需要随机访问迭代器,所以只能用于支持这种迭代器的容器
	*/

	// 概念、改进和模型
	/*
		1.将指针用作迭代器
			迭代器是广义指针,而指针满足所有的迭代器要求
			迭代器是STL算法的接口,而指针是迭代器,因此STL算法可以使用指针来对基于指针的
			非STL容器进行操作


			int casts[10] = {6, 2, 4, 5, 8, 3, 1, 8, 2, 1};
			vector<int> dice(10);
			copy(casts, casts + 10, dice.begin());

			copy()的前两个迭代器参数表示要复制的范围,最后一个迭代器参数表示要将第一个元素复制到什么位置
			前两个位置必须是(或最好是)输入迭代器,最后一个必须是(或最好是)输出迭代器

			现要将信息复制到显示器上
			STL为这种迭代器提供了 ostream_iterator 模板
			用STL的话说,该模板是输出迭代器概念的一个模型
			它也是一个适配器(adapter) ---- 一个类或函数,可以将一些其他接口转换为STL使用的接口
			可以通过包含头文件 iterator 并作下面的声明来创建这种迭代器:
				#inlcude<iteartor>
				...
				ostream_iterator<int, char> out_iter(cout, " ");
			out_iter 迭代器现在是一个接口,能够使用 cout 来显示信息
			第一个模板参数(这里是 int)指出了被发送给输出流的数据类型
			第二个模板参数(这里为 char)指出了输出流使用的字符类型(另一个可能的值是 wchar_t)
			构造函数的第一个参数(这里为 cout)指出了要使用的输出流,它也可以是用于文件输出的流
			最后一个字符串参数是在发送给输出流的每个数据项后显示的分隔符
				可以这样使用迭代器:
				*out_iter++ = 15;		// works like cout << 15 << " ";
			对于常规指针,这意味着将 15 赋给指针指向的位置,然后将指针加 1
			但对于该 ostream_iterator,这意味着将 15 和由空格组成的字符串
			发送到 cout 管理的输出流中,并未下一个输出操作做好了准备
			可以将 copy() 用于迭代器:
				copy(dice.begin(), dice.end(), out_iter);
			这意味着将 dice 容器的整个区间复制到输出流中,即显示容易的内容
			也可以不创建命名的迭代器,而直接构建一个匿名迭代器:
				copy(dice.begin(), dice.end(), ostream_iterator<int, char>(cout," "));
			iterator 头文件还定义了一个 istream_iterator 模板
			使用 istream 输入可用作迭代器接口
			它是一个输入迭代器概念的模型
			可以使用两个 istream_iterator 对象来定义 copy() 的输入范围:
				copy(istream_iteartor<int, char>(cin),
					istream_iteartor<int, char>(), dice.begin());
			istream_iterator 的第一个参数指出要读取的数据类型
			第二个参数指出输入流使用的字符类型
			使用构造函数参数 cin 意味着使用由 cin 管理的输入流
			省略构造函数参数表述输入失败
			因此上述代码从输入流中读取,直到文件结尾、类型不匹配或出现其他输入故障为止

		2.其他有用的迭代器
			头文件 iterator 提供了一些专用的预定义迭代器类型:
				reverse_iterator、back_iterator、front_insert_iterator 和 insert_iterator

	*/
	std::ostream_iterator<int, char> out_iter(std::cout, " ");
	*out_iter = 15;
	*out_iter++ = 16;

	int casts[10] = { 6, 2, 4, 5, 8, 3, 1, 8, 2, 1 };
	std::vector<int> dice(10); 

	std::copy(casts, casts + 10, dice.begin());

	std::copy(dice.begin(), dice.end(), std::ostream_iterator<int, char>(std::cout," "));

	std::copy(std::istream_iterator<int, char>(std::cin),
		std::istream_iterator<int, char>(), dice.begin());

	std::copy(dice.begin(), dice.end(), std::ostream_iterator<int, char>(std::cout, " "));

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

std::unique_ptr<std::string> demo(const char* s)
{
	std::unique_ptr<std::string> temp(new std::string(s));
	return temp;
}

void vect1_cpp()
{// vect1.cpp -- introducing the vector template
	using std::vector;
	using std::string;
	using std::cin;
	using std::cout;
	using std::endl;
	const int NUM = 5;

	vector<int>ratings(NUM);
	vector<string>titles(NUM);
	cout << "You will do exactly as told. You will enter\n"
		<< NUM << " book titles and your ratings (0-10).\n";
	int i;
	for (i = 0; i < NUM; i++)
	{
		cout << "Enter titles #" << i + 1 << ": ";
		getline(cin, titles[i]);
		cout << "Enter yours rating (0-10): ";
		cin >> ratings[i];
		cin.get();
	}
	cout << "Thank you. You entered the following:\n"
		<< "Rating\tBook\n";
	for (i = 0; i < NUM; i++)
	{
		cout << ratings[i] << "\t" << titles[i] << endl;
	}
	// cin.get();
}

struct Review {
	std::string title;
	int rating;
};

bool FillReview(Review&);
void ShowReview(const Review&);

void vect2_cpp()
{
	using std::cout;
	using std::vector;
	vector<Review>books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);
	int num = books.size();
	if (num > 0)
	{
		cout << "Thank you. You entered the following:\n"
			<< "Rating\tBook\n";
		for (int i = 0; i < num; i++)
			ShowReview(books[i]);
		cout << "Reprising:\n"
			<< "Rating\tBook\n";
		vector<Review>::iterator pr;
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);
		vector<Review> oldlist(books);		// copy constructor used
		if (num > 3)
		{
			// remove 2 items
			books.erase(books.begin() + 1, books.begin() + 3);
			cout << "After erasure:\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
			// insert 1 item
			books.insert(books.begin(), oldlist.begin() + 1,
						oldlist.begin() + 2);
			cout << "After insertion:\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
		}
		books.swap(oldlist);
		cout << "Swapping oldlist with books:\n";
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);
	}
	else
		cout << "Nothing entered, nothing gained.\n";
	// std::cin.get();
}

bool FillReview(Review& rr)		/* 输入范例 */
{
	std::cout << "Enter book title (quit to quit): ";
	std::getline(std::cin, rr.title);
	if (rr.title == "quit")
		return false;
	std::cout << "Enter book rating: ";
	std::cin >> rr.rating;
	if (!std::cin)
		return false;
	// get rid of rest of input line
	while (std::cin.get() != '\n')
		continue;
	return true;
}

void ShowReview(const Review& rr)
{
	std::cout << rr.rating << "\t" << rr.title << std::endl;
}

bool operator<(const Review& r1, const Review& r2);
bool worseThan(const Review& r1, const Review& r2);

void vect3_cpp()
{// vect3.cpp -- using STL functions
	using namespace std;
	vector<Review> books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);
	if (books.size() > 0)
	{
		cout << "Thank you. You entered the following "
			<< books.size() << " ratings:\n"
			<< "Rating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);

		sort(books.begin(), books.end());
		cout << "Sorted by title:\nRating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);

		sort(books.begin(), books.end(), worseThan);
		cout << "Sorted by rating:\nRating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);

		random_shuffle(books.begin(), books.end());
		cout << "After shuffling:\nRating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);
	}
	else
		cout << "No entries. ";
	cout << "Bye.\n";
	// cin.get();
}

bool operator<(const Review& r1, const Review& r2)
{
	if (r1.title < r2.title)
		return true;
	else if (r1.title == r2.title && r1.rating < r2.rating)
		return true;
	else
		return false;
}

bool worseThan(const Review& r1, const Review& r2)
{
	if (r1.rating < r2.rating)
		return true;
	else
		return false;
}