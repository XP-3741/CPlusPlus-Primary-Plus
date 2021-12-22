#include<iostream>
#include<string>
#include<array>
using namespace std;

int sum(int ar2[][4], int size);

int main() 
{
	//在C++中，括号为空与在括号中使用关键字void是等效的—— 味着函数没有参數。在ANSIC中，
	//括号为空意味着不指出参数—— 这意味着将在后面定义参数列表。在C++中，不指定参数列表时应使用省略号：
	//void slh(...);

	//还有另一种给函数提供所需信息的方法,即指定元素区间（range),这可以通过传两个指针来完成
	//一个指针标识数组的开头，另一个指针标识数组的尾部
	//double elbuod[20]； 
	//指则针elboud，elboud + 20 定义了区间。首先，数组名elbmib 指向第一个元素。表达式elboud+19 
	//向最后一个元素（elboud[19])

	//C + +禁止将const的地址赋给非const指针
	// const指针赋给const指针是可以的

	//将指针参数声明为指向常量数据的指针有两条理由:
	//这样可以避免由于无意间修改数据而导致的编程错误；
	//使用const使函数能够处理const和非const实参,否则将只能接受非const数据
	//如果条件允许,则应将指针形参声明为指向const的指针
	
	//为说明另一个微妙之处：
	int age = 39;
	const int *pt = &age;
	//第二个声明中的const只能防止修改pt所指向的值(39),而不能防止修改pt的值
	//也就是说,可以将一个新的地址赋给pt：
	int sage = 80;
	pt = &sage;
	//但仍然不能使用pt来修改它指向的值(80)

	//第二种使用const的方式使无法修改指针的值
	int sloth = 3;
	const int* ps = &sloth;		//a pointer to const int
	int* const finger = &sloth;	//a const pointer tp int
	//这种声明格式使得finger只能指向sloth, 但许使用finger来修改sloth的值。
	//中间的声明不允许使用ps来修改sloth的值,但允许将ps指向另一个位置
	//简而言之,finger和*ps都是const, 而*finger和ps不是

	//如果愿意还可以声明指向const对象的const指针：
	double trouble = 2.0E30;
	const double* const stick = &trouble;
	//stick只能指向trouble,而stick不能用來修改trouble的值
	//stick和*stick都是const

	//将指针作为函数参数来传递时,可以使用指向const的指针来保护数据。
	void showarray(const double ar[], int n);

	//为编写将二维数组作为参数的函数，必须牢记，数组名被视为其地址，因此，相应的形参是一个指针，
	//像一维数组一样,比较难处理的是如何正确地声明指针。
	//例如,假设有下面的代码：
	int data[3][4] = { {1,2,3,4},{5,6,7,8},{2,4,6,8} };
	int total = sum(data, 3);
	//Data是一个数组名，该数组有3个元素。第一个元素本身是一个数组，有4个int值组成
	//sum得原型如下
	int sum(int(*ar2)[4], int size);
	//中的括号是必不可少的,因为下面的声明将声明一个由4个指向int的指针组成的数组,而不是由
	//一个指向由4个int组成的数组的指针：另外，函数参数不能是数组:
	int* ar2[4];
	//还有另外一种格式，这种格式与上述原型的含义完相同,但可读性更强
	int sum(int ar2[][4], int size);

	//可以将一个结构赋值给另外一个结构,同样,也可以按值传递结构,就像普通变量那样
	//在这种情况下,函数将使用原始结构的副本
	//另外,函数也可以返回结构
	//与数组名就是数组的第一个元素的地址不同的是,结构名只是结构的名称,要获得结构的地址,必须使用地址运算符&

	//当结构比较小时,按值转递结构最合理
	struct travel_time
	{
		int hour;
		int minute;
	};
	//返回类型为travel_time,两个参数也为这种类型
	travel_time sum(travel_time t1, travel_time t2);
	/*{
		travel_time total;

		total.minute = (t1.minute + t2.minute) % Mins_pre_hr;
		total.hour = t1.hour + t2.hour + (t1.minute + t2.minute) / Mins_per_hr;
		return total;
	}*/

	//由直角坐标系转化成极坐标系
	struct rect
	{
		double x;
		double y;
	};
	struct polar
	{
		double distance;
		double angle;
	};
	//数学库中的atan2()函数可以根据x和y的值计算角度
	//angle = atan2(y,x);
	//还有一个atan()函数,但他不能区分180度之内和之外的角度
	polar rect_to_polar(rect xypos);
	/*{
		polar answer;
		answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
		answer.angle = atan2(xypos.y, xypos.x);
		return answer;
	}*/

	//while(cin >> rplace.x >> rpalce.y);
	//cin是istream类的一个对象
	//抽象运算符( >> )被设计成使得cin>>rplace.x也是一个istream对象
	//类运算符是使用函数实现的
	//使用cin>>rplace.x时,程序将调用一个函数,该函数返回一个istream值
	//因此,while循环的测试表法式的最终结果为cin
	//而cin被用于测试表达式时,将根据输入是否成功,被转换成bool值

	//传递结构的地址而不是整个结构以节省时间和空间
	//间接成员运算符( -> )							
	void rect_to_polar(const rect* xypos, polar* pda);
	/*{
		pda->distance = sqrt(xypos->x * xypos->x + xypos->y * xypos->y);
		pda->angle = atan2(xypos->y, xypos->x);
	}*/
	//两个rect_to_polar函数的差别在于前者使用的是结构副本,后者使用的时指针,让函数能够对原始结构进行操作

	//模板类array
	//假如要使用一个array对象存储一年四个季度的开支
	std::array<double, 4> expenses = { 1,2,3,4 };
	std::array < double, 4 >* pa = &expenses;
	cout << (*pa)[2] << endl;
	//头文件<array>,名称空间std
	//如果函数来显示expenses的内容,可按值传递expenses
	//show(expenses);
	//如果函数要修改对象expenses,则需将该对象的地址传递给函数
	//fill(&expenses);
	//声明这两个函数
	void show(std::array<double, 4> da);
	void fill(std::array<double, 4>* pa);

	//使用一个const array对象,包含4个string对象,表示四个季度
	const int seasons = 4;
	const std::array<std::string, seasons>Snames =
	{ "Spring","Summer","Fall","Winter" };
	//array并非只能存储基本数据类型,它还可以存储对象

	//函数指针
	//与数据项类似,函数也有地址
	//函数的地址是存储其机器语言代码的内存的开始地址
	//这些地址对用户而言不重要也无用,但对程序却很有用
	//例如,可以编写将另一个函数的地址作为参数的函数,这样第一个函数将能够找到第二个元素,并运行他

	//获取函数的地址很简单:只要使用函数名(后面不更参数)即可
	//如果think()是一个函数,则think就是该函数的地址
	//要将函数作为参数进行传递,必须传递函数名
	//一定要区分传递的是函数的地址还是函数的返回值
	//process(think);	//passes address of think() to process()
	//thought(think{});	//passes return value of think() to thought()
	//process()调用使得process()函数能够在其内部调用think()函数
	//thought()调用首先调用think()函数,然后将think()的返回值传递给thought()函数

	//声明指向某种数据类型的指针时,必须指定指针指向的类型
	//同样,声明指向函数的指针时,也必须指定指针指向的函数类型
	//这意味着声明应指定函数的返回类型以及函数的特征标(参数列表),就像声明函数原型
	//如函数原型如下
	double pam(int);
	//则正确的指针类型声明如下
	double (*pf)(int);
	//这与pam()声明类似,这是将pam替换成(*pf)
	//由于pam是函数,因此(*pf)也是函数,pf就是函数指针

	//为提供正确的运算符优先级,必须在声明中使用括号将*pf括起
	//*pf(int)意味着pf()是一个返回指针的函数,而(*pf)(int)意味着pf是一个指向函数的指针
	
	//正确声明后,便可将相应的函数的地址赋值给他
	pf = pam;
	//pam()的特征标和返回类型必须与pf相同
	//使用C++11的自动类型推断功能,代码要简单的多
	auto pf1 = pam;

	//estimate()函数要将将要编写的代码行数和估算算法时间的地址传递给他
	void estimate(int lines, double(*pf)(int));
	//要让其使用pam()函数,需要将pam()的地址传递给他
	estimate(50, pam);

	//使用指针来调用函数
	double x = (*pf)(5);

	const double* f1(const double ar[], int n);
	const double* f2(const double[], int);
	const double* f3(const double*, int);
	//这三个实际上相同
	//函数原型中,参数列表const double ar []与const double *ar的含义完全相同
	//其次,在函数原型中,可以省略标识符,因此,const double ar[]可化简为cont doule []
	//而const double * ar可化简为const double *

	//函数指针数组,可使用for循环通过指针依次调用每个函数
	const double* (*pk[3])(const double*, int) = { f1,f2,f3 };
	//为何[3]放在这?
	//pa是一个包含三个元素的数组.而声名这样的数组,首先需要使用pa[3]
	//该声明的其他部分指出了数组包含的元素是什么样的
	//运算符[]的优先级高于*,因此*pa[3]表明pa是一个包含三个指针的数组
	//上述声明的其他部分指出了每个指针指向什么:特征标为const double *,int,且返回类型为const double *的函数
	//因此,pa是一个包含三个指针的数组,其中每个指针都指向这样的函数
	//这里不能使用auto
	//自动类型推断只能使用于单值初始化,而不能用于初始化列表
	//但声明数组pk后,声明同样类型的数组就很简单了
	auto pkk = pk;

	//数组名是指向第一个元素的指针,因此pa和pb都是指向函数指针的指针
	//调用: pa[i]和pb[i]都表示数组中的指针,因此可将任何一种函数调用方法用于他们
	const double av[3] = { 2,3,4 };
	const double* px = pk[0](av, 3);
	const double* py = (*pkk[1])(av, 3);
	//要获得指向double的值,可以使用运算符*
	double x1 = *pk[0](av, 3);
	double y = *(*pkk[1])(av,3);

	// **&pk == *pk == pk[0		//美好不一定要完美,残缺也不会有任何影响,0有着无限的遐想


	//默认值(缺省值)
	//函参可从右向左
	int f(int a = 1, int b = 2, int c = 3);
	//调用
	f(3);//a=3,b=2,c=3
	f(3, 4);//a=3,b=4,c=3
	f();//a=1,v=2,c=3
	//因为从右向左,所以定义不能：
	//int f(int a = 3, int b,int c=1);

	//在字符串中读取数字: "x=12,y=3"


	return 0;
}

int sum(int ar2[][4], int size)
{
	int total = 0;
	for (int r = 0; r < size; r++)
		for (int c = 0; c < 4; c++)
			total += ar2[r][c];
	return total;
}

void display(const string sa, int n)
{
	for (int i = 0; i < n; i++)
		cout << i + 1 << ":" << sa[i] << endl;
}