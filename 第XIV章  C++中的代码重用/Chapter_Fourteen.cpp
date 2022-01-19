#include<valarray>

int main()
{
	// valarray 类简介
	//	这个类用于处理数值(或具有类似特性的类)
	//	valarray 被定义为一个模板类,以便能够处理不同的数据类型
	//	模板类特性意味着声明对象时,必须指定具体的数据类型
	//	因此,使用 valarray 类来声明一个对象时
	//	须在标识符 valarray 后面加上一对尖括号,并在其中包含所需要的数据类型
	std::valarray<int> q_values;		// an array of int
	std::valarray<double> weights;		// an array of double
	// 下面是几个使用构造函数的例子:
	double gpa[5] = { 3.1, 3.5, 3.8, 2.9, 3.3 };
	std::valarray<double> v1;		// an array of double, size 0
	std::valarray<int> v2(8);		// an array of 8 int elements
	std::valarray<int> v3(10, 8);	// an array of 8 int elements
									// each set to 10
	std::valarray<double>v4(gpa, 4);// an array of 4 elements
						// initialized to the first 4 elements of gpa
	// 在C++11中,也可以使用初始化列表
	std::valarray<int> v5 = { 20, 32, 17, 9 };	// C++11
	// 下面是这个类的一些方法
	//	- operator[]()	访问各个元素
	//	- size()		返回包含的元素数
	//	- sum()			返回所有的元素总和
	//	- max()			返回最大的元素
	//	- min()			返回最小的元素

	// Student 类的设计
	//	以确定 Student 类的设计计划:
	//		string对象表示姓名、valarray<double>表示分数
	//	由于学生与这列类之间不是 is-a 模型,所以不适合将学生从这两个类派生出
	//	这里的关系是 has-a ,学生有姓名和一组考试分数
	//	通常,用于建立 has-a 关系的C++技术是组合(包含),及创建一个包含其他类对象的类
	
	// 接口和实现
	//	使用公有继承时,类可以继承接口,可能还有实现
	//		(基类的纯虚函数提供接口,但不提供实现)
	//	获得接口是 is-a 关系的组成部分
	//	而是用组合,类可以获得实现,但不能获得接口
	//	不继承接口是 has-a 关系的组成部分
	//
	return 0;
}