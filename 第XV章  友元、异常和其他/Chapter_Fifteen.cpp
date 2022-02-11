
int main()
{
	// 并非只能拥有友元函数,也可以将类作为友元函数
	// 另外,也可以做更严格的限制,只将特定的成员函数指定为另一个类的友元

	// 友元类
	//	下面语句使 Remote 作为友元类:
	//		friend class Remote;
	//	友元声明可以位于公有、私有或保护部分,其所在位置无关紧要
	// 
	// 友元成员函数
	//	可以选择让特定的类成员称为另一个类的友元,而不必让整个类成为友元
	//  如让 Remote::set_chan()称为 Tv 类的友元的方法是,在 Tv 类声明中将其声明为友元:
	//		class Tv
	//		{
	//			friend void Remote::set_chan(Tv & t, int c);
	//			...
	//		}
	//	然而,要使编译器能够处理这条语句,它必须知道 Remote 的定义
	//	这意味着应将 Remote 的定义和 set_chan() 方法的声明放到 Tv 的定义前面
	//	Remote 的方法提到了 Tv 对象,而这意味着 Tv 定义应当 位于 Remote 定义之前
	//	避开这种循环依赖的方法是,使用 前向声明(forward declaration)
	//	为此,需要在 Remote 定义的前面插入:
	//		class Tv;		// forward declaration
	//	这样,排列次序如下:
	//		class Tv;		// forward declaration
	//		class Remote { ... };
	//		class Tv { ... };
	//	不能如下排列:
	//		class Remote;		// forward declaration
	//		class Tv { ... };
	//		class Remote { ... };
	//	因为在编译器在 Tv 类的声明看到 Remote 的一个方法被声明为 Tv 类的友元之前
	//	应该先看到 Remote 类的声明和 set_chan() 方法的声明
	//	还有一个麻烦,Remote 声明包含了内联代码: void onoff(Tv & t) { t.onoff(); }
	//	由于这将调用 Tv 的一个方法,所以编译器此时必须已经看到了 Tv 类的声明
	//	但正如看到的,该声明位于 Remote 声明的后面
	//	这种问题的解决方法是,使 Remote 声明中只包含方法声明
	//	并将实际的定义放在 Tv 类之后
	//	内联函数的链接性是内部的,这意味着函数定义必须在使用函数的文件中
	//	在 tvfm 的例子中,内联定义位于头文件中
	//	因此在使用函数的文件中包含头文件可确保定义放在正确的地方
	//	也可以将定义放在实现文件中,但必须删除关键字 inline ,这样函数的链接性将是外部的
	//	如果让整个 Remote 类称为友元并不需要向前声明
	//	因为友元语句本身已经指出 Remote 是一个类
	// 
	// 其他友元关系
	//	两者互为友元
	// 共同的友元
	//	需要使用友元的另一种情况是,函数需要访问两个类的私有数据
	//	从逻辑上看,这样的函数应该是每个类的成员函数,但这是不可能的
	//	它可以是一个类的成员,同时是另一个类的友元
	//	但有时将函数作为两个类的友元更合理
	//	例如,假定有一个 Probe 类和一个 Analyzer 类
	//	前者表示某种可编程的测量设备,后者表示某种可编程的分析设备
	//	这两个类都有内部时钟,且希望它们能够同步,则应该包含下述代码行;
	//	class Analyzer;
	//	class Probe
	//	{
	//		friend void sync(Analyzer & a, const Probe & p);	// sync a to p
	//		friend void sync(Probe & p, const Analyzer & a);	// sync p to a
	//		...
	//	};
	//	class Analyzer
	//	{
	//		friend void sync(Analyzer & a, const Probe & p);	// sync a to p
	//		friend void sync(Probe & p, const Analyzer & a);	// sync p to a
	//		...
	//	};
	//	// define the friend functions
	//	inline void sync(Analyzer & a, const Probe & p)
	//	{
	//		...
	//	}
	//  inline void sync(Probe & p, const Analyzer & a)
	//	{
	//		...
	//	}

	// 嵌套类
	//	可以将类声明放在另一个类中
	//	在另一个类声明的类被称为 嵌套类(nested class)
	//	它通过提供新的类型类作用域来避免名称混乱
	//	对类进行嵌套与包含并不同
	//	包含意味着将类对象作为另一个类的成员,而对类进行嵌套不创建类成员,而是定义了一种类型
	//	该类型仅在包含嵌套类声明的类中有效
	//	对类进行嵌套通常是为了帮助实现另一个类,避免名称冲突
	//	Queue 类示例:
	//	class Queue
	//	{
	//	private:
	//		struct Node {Item item; struct Node * next;};
	//		...
	//	};
	//	唯一创建 Node 对象的地方是 enqueue() 方法:
	//	bool Queue::enqueue(const Item & item)
	//	{
	//		if(isfull())
	//			return false;
	//		Node* add = new Node;
	//		add->item = item;
	//		add->next = NULL;
	//		...
	//	}
	//	显示地给 Node 成员赋值,这种工作更适合由构造函数来完成
	//	class Queue
	//	{
	//		class Node
	//		{
	//		public:
	//			Item item;
	//			Node* next;
	//			Node(const Item & i) :item(i), next(0) {}
	//		};
	//		...
	//	};
	//	重新编写 enqueue():
	//	bool Queue::enqueue(const Item & item)
	//	{
	//		if(isfull())
	//			return false;
	//		Node* add = new Node(item);
	//		...
	//	}
	//	这使得代码简短且更安全,因为它自动进行初始化,无需程序员记住应该做什么
	//	如在方法文件中定义构造函数,则定义必须指出 Node 类是在 Queue 类中定义的:
	//	Queue::Node::Node(const Item & i) : item(i), next(0) {}
	//	
	return 0;
}