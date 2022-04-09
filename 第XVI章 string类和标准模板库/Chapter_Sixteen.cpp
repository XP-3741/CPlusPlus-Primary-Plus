#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include <ctime>
#include <cctype>
#include<memory>		// for auto_ptr, unique_ptr, shared_ptr
#include<vector>

void str1_cpp();
void strfile_cpp();
void hangman_cpp();
void str2_cpp();
void smrtptrs_cpp();
void fowl_cpp();
std::unique_ptr<std::string> demo(const char* s);
void vect1_cpp();

int main()
{
	// string ��Ĺ��캯��
	//		���캯��									����
	//	string(const char* s)				�� string �����ʼ��Ϊ s ָ��� NBTS
	//	string(size_type n,char c)			����һ������ n ��Ԫ�ص� string ����,����ÿ��Ԫ�ض�����ʼ��Ϊ�ַ� c
	//	string(const string& str)			��һ�� string �����ʼ��Ϊ string ���� str(���ƹ��캯��)
	//	string()							����һ��Ĭ�ϵ� string ����,����Ϊ 0(Ĭ�Ϲ��캯��)
	//	string(const char* s,size_type n)	�� string �����ʼ��Ϊ s ָ��� NBTS ��ǰ n ���ַ�
	//										��ʹ������ NBTS �Ľ�β
	//	template<class Iter>
	//	string(Iter begin,Iter end)			�� string �����ʼ��Ϊ����[begin,end)�ڵ��ַ�
	//										���� begin �� end ����Ϊ����ָ��
	//										����ָ��λ��,��Χ���� begin ����,�������� end
	//	string(const string& str,			��һ�� string �����ʼ��Ϊ���� str �д�λ�� pos
	//			string size_type pos = 0,	��ʼ����β���ַ�,���λ�� pos ��ʼ�� n ���ַ�
	//			size_type n = npos)
	//	string(string&& str) noexcept		���� C++11 ������,����һ�� string �����ʼ��Ϊ
	//										string ���� str,�������޸� str(�ƶ����캯��)
	//	string(initializer_list<char>il)	���� C++11 ������,����һ�� string �����ʼ��
	//										Ϊ��ʼ���б� il �е��ַ�
	// 
	//	ʹ�ù��캯��ʱ�������˼�,��������һ����ʵ:
	//	string ʵ������ģ����廯 basic_string<char> ��һ�� typedef
	//	ͬʱʡ�������ڴ������صĲ���
	//	size_type ��һ��������ʵ�ֵ�����,����ͷ�ļ� string �ж����
	//	string �ཫ string::npos ����Ϊ�ַ�������󳤶�,ͨ��Ϊ unsigned int �����ֵ
	//	����,�����ʹ����д NBTS(null-terminated string)����ʾ�Կ��ַ��������ַ���--��ͳC�ַ���
	if (false) str1_cpp();
	
	// string ������
	//	C-����ַ���,�����ַ�ʽ:
	//		char info[100];
	//		cin >> info;			// read a word
	//		cin.getline(info, 100);	// read a line, discard \n
	//		cin.get(info, 100);		// read a line, leave \n in queue
	//	���� string ����,�����ַ�ʽ:
	//		string stuff;
	//		cin >> stuff;			// read a word
	//		getline(cin, stuff);	// read a line, discard \n
	//	�����汾�� getline() ����һ����ѡ����,����ָ��ʹ���Ǹ��ַ���ȷ������߽�:
	//		cin.getline(info, 100, ';');	// read up to ; ,discard
	//		getline(stuff, ';');			// read up to ; ,discard
	//	�ڹ�����,����֮����Ҫ��������,string �汾�Ľ��Զ�����Ŀ�� string �����С
	//	��������:
	//		- string ��������������,�ɳ��� string::npos ָ��
	//		- ʹ�õ��ڴ���
	//	string �汾�� getline() �����������ж�ȡ�ַ�,������洢��Ŀ�� string ��
	//	ֱ�����������������֮һ:
	//		- �����ļ�β,�����������,�������� eofbit ��������
	//		  ����ζ�ŷ��� fail() �� eof() �������� true
	//		- �����ֽ��ַ�(Ĭ��Ϊ\n),�����������,���ѷֽ��ַ�����������ɾ��,�����洢��
	//		- ��ȡ���ַ����ﵽ�������ֵ,�����������,�������������� failbit
	//		  ����ζ�ŷ��� fail() ������ true
	//	������������һ��ͳ��ϵͳ,���ڸ������Ĵ���״̬
	//		�����ϵͳ��,��⵽�ļ�β������ eofbit �Ĵ���
	//		��⵽�������ʱ������ failbit �Ĵ���
	//		�����޷�ʶ��Ĺ���(��Ӳ�̹���)ʱ������ badbit �Ĵ���
	//		һ��˳��ʱ������ goodbit �Ĵ���
	//	string �汾�� operator<<() ������Ϊ�������
	//	ֻ�������϶�ȡ
	//	ֱ�������հ��ַ��������������������
	//	�����ǲ��϶�ȡ,ֱ�������ֽ��ַ������䶪��
	//  �հ��ַ�ָ���ǿո�,���з����Ʊ��
	//	���ձ��˵,���κν�����Ϊ���������� isspace() ʱ,�ú������� ture ���ַ�
	// 
	//	����������һ�����ļ���ȡ�ַ��ļ��ʾ��
	//	�������ļ��а�����ð���ַ��ָ����ַ���,��ʹ��ָ���ֽڷ� getline() ����
	//	Ȼ����ʾ�ַ����������Ǳ��
	if (false) strfile_cpp();
	// ע��,�� : ָ��Ϊ�ֽ��ַ���,���з�������Ϊ�����ַ�
	// 
	// ʹ���ַ���
	//	����ÿ����ϵ�����,�������ַ�ʽ������
	//	�Ա��ܹ��� string ��������һ�� string ����C-����ַ����Ƚ�
	//	���ܹ��� C-����ַ��� �� string ������бȽ�:
	//		operator<(const string&, const string&)
	//		operator==(const string&, const char *)
	//		operator!=(const char *, const string&)
	//	ȷ���ַ�������
	//		size()��length()��Ա�����������ַ����е��ַ���
	//		length()��Ա���Խ���汾�� string ��
	//		�� size() ����Ϊ�ṩ STL �����Զ���ӵ�
	// 
	// ���ص� find() ����
	//		����ԭ��												����
	//	size_type find(const string& str,			���ַ����� pos λ�ÿ�ʼ,�������ַ��� str
	//	size_type pos = 0) const					����ҵ����ظ����ַ����״γ���ʱ�����ַ�������
	//												����,���� string::npos
	//	size_type find(const char* s,				���ַ����� pos λ�ÿ�ʼ,�������ַ��� s
	//	size_type pos = 0) const					����ҵ����ظ����ַ����״γ���ʱ�����ַ�������
	//												����,���� string::npos
	//	size_type find(const char* s,				���ַ����� pos λ�ÿ�ʼ,���� s ��ǰ n ���ַ���ɵ����ַ���
	//	size_type pos = 0,size_type n)				����ҵ����ظ����ַ����״γ���ʱ�����ַ�������
	//												����,���� string::npos
	//	size_type find(char ch,						���ַ����� pos λ�ÿ�ʼ,�����ַ� ch
	//	size_type pos = 0) const					����ҵ�,�򷵻ظ��ַ��״γ��ֵ�λ��
	//												����,���� string::npos
	// 
	//	string �⻹�ṩ����صķ���:
	//		rfind()��find_first_of()��find_last_of()��find_first_not_of()��find_last_not_of()
	//		���ǵ����غ��������궼�� find()������ͬ
	//		rfind()����
	//			�������ַ������ַ����һ�γ��ֵ�λ��
	//		find_first_of()����
	//			���ַ����в��Ҳ������κ�һ���ַ��״γ��ֵ�λ��
	//			����������䷵�� r ��"cobra"�е�λ��,��Ϊ����"hark"�и�����ĸ��"cobra"�״γ��ֵ�λ��:
	//			int where = snake1.find_first_of("hark");
	//		find_last_of()����
	//			����������ͬ,ֻ�������ҵ������һ�γ��ֵ�λ��
	//			����������䷵�� a ��"cobra"�е�λ��:
	//			int where = snake1.find_last_of("hark");
	//		find_first_not_of()����
	//			���ַ����в��ҵ�һ���������ڲ����е��ַ�
	//			����������䷵�� c ��"cobra"�е�λ��,��Ϊ"hark"��û�� c:
	//			int where = snake1.find_last_of("hark");
	if(false)	hangman_cpp();
	// string �ṩ����������
	//	string �⻹�ṩ�˺ܶ������Ĺ���,��������������ܵĺ���:
	//		(��¼F��Ҫ�ؽ����� string ���еĺ���)
	//	���� capacity() ���ص�ǰ������ַ������ڴ��Ĵ�С
	//	�� reserve() �����ܹ������ڴ�����С����
	if(false)	str2_cpp();

	// ����� string ����,����Ҫ C-����ַ���,����ΰ�:
	//		����,�������һ�������ƴ洢�� string �����е��ļ�
	//			string filename;
	//			cout << "Enter file name: ";
	//			cin >> filename;
	//			ofstream fout;
	//		���ҵ���,open()����Ҫ��ʹ��һ�� C-����ַ�����Ϊ����
	//		���˵���, c_str() ��������һ��ָ�� C-����ַ�����ָ��
	//		�� C-����ַ��������������ڵ��� c_str() ������ string ������ͬ:
	//			fout.open(filename.c_str());
	// 
	// �ַ�������
	//	���ڽ� string �࿴���ǻ��� char ���͵�
	//	��ʵ��,����ǰ��ָ��,string ��ʵ�����ǻ���һ��ģ�����:
	//		template<class charT, class traits = char_traits<charT>,
	//				class Allocator = allocator<charT> >
	//		basic_string {...}
	//	ģ�� basic_string ��4�����廯,ÿ�����廯����һ�� typedef ����:
	//		typedef basic_string<char> string;
	//		typedef basic_string<wchar_t> wstring;
	//		typedef basic_string<char16_t> u16string;		// C++11
	//		typedef basic_string<char32_t> u32string;		// C++11
	// 
	// ����ָ��ģ����
	//	����ָ������Ϊ������ָ��������,�����ֶ�������������
	//	����������ָ��ģ��(auto_ptr,unique_ptr��shared_ptr)������������ָ��Ķ���
	//	���Խ� new ���(ֱ�ӻ���)�ĵ�ַ�������ֶ���
	//	������ָ�����ʱ,������������ʹ�� delete ���ͷ��ڴ�
	//	���,����� new ���صĵ�ַ������Щ����,�����ס�Ժ��ͷ���Щ�ڴ�
	if(false)	smrtptrs_cpp();
	//	��������ָ�붼��һ�� explicit ���캯��,�ù��캯����ָ����Ϊ����
	//	��˲���Ҫ�Զ���ָ��ת��Ϊ����ָ�����:
	//		shared_ptr<double> pd;
	//		double* p_red = new double;
	//		pd = p_reg;								// not allowed (implicit conversion)
	//		pd = shared_ptr<double>(p_red);			// allowed (explicit conversion)
	//		shared_ptr<double> pshared = p_reg;		// not allowed (implicit conversion)
	//		shared_ptr<double> pshared(p_reg);		// allowed (explicit conversion)
	//	��������ָ��ģ����Ķ��巽ʽ,����ָ�����ĺܶ෽�涼�����ڳ���ָ��
	//	����,��� ps ��һ��ָ��ָ�����,����Զ���ִ�н�����ò���(*ps)
	//	���������ʽṹ��Ա(ps->puffIndex),��������ָ����ͬ���͵ĳ���ָ��
	//	�����Խ�ָ��ָ����󸳸���һ��ͬ���͵�����ָ�����,��������һ������,���ڼ�һ������
	//	�ڴ�֮ǰ,��˵˵��ȫ����������ָ�붼Ӧ�����һ��:
	//		string vacation("T wandered lonely as a cloud.");
	//		shared_ptr<string> pvac(&vacation);		// NO!
	//	pvac ����ʱ,���򽫰� delete ��������ڷǶ��ڴ�,���Ǵ����
	// 
	// �й�����ָ���ע������
	//	Ϊ������������ָ��?ʵ����������,�����鲻���� weak_ptr,Ϊ������ auto_ptr?
	//	����������ĸ�ֵ���:
	//		auto_ptr<string> ps (new string("Fuck YOU"));
	//		auto_ptr<string> vacation;
	//		vacation = ps;
	//	��� ps �� vacation �ǳ���ָ��,������ָ�뽫ָ��ͬһ�� string ����
	//	���ǲ��ܽ��ܵ�,��Ϊ������ͼɾ��ͬһ����������----һ���� ps ����ʱ,��һ���� vacation ����
	//	Ҫ������������,�����ж���
	//		- ���帳ֵ�����,ʹִ֮�����
	//		  ��������ָ�뽫ָ��ͬ�Ķ���,���е�һ����������һ������ĸ���
	//		- ��������Ȩ(ownership)����,�����ض��Ķ���,ֻ����һ������ָ���ӵ����
	//		  ����ֻ��ӵ�ж��������ָ��Ĺ��캯����ɾ���ö���
	//		  Ȼ��,�ø�ֵ����ת������Ȩ
	//		  ��������� auto_ptr �� unique_ptr �Ĳ���,�� unique_ptr �Ĳ��Ը��ϸ�
	//		- �������ܸ��ߵ�ָ��,���������ض����������ָ����
	//		  ���Ϊ���ü���(reference counting)
	//		  ����,��ֵʱ,��������1,��ָ�����ʱ,������1
	//		  �������һ��ָ�����ʱ,�ŵ��� delete,���� shared_ptr �Ĳ���
	//	��Ȼ,ͬ���Ĳ���Ҳ�����ڸ��ƹ��캯��
	//	���������һ��������ʹ�� auto_ptr ��ʾ��
	if(false)	fowl_cpp();
	//	�� i = 2 ʱ,�쳣��ֹ����
	//	��������M������Ȩ�� films[2] ת�ø� pwin
	//	�⵼�� films[2] �������ø��ַ���,�� auto_ptr ������������Ȩ��,�����ʹ���������ʶ���
	//	�������ӡ films[2] ָ����ַ���ʱ,ȴ��������һ����ָ��
	//	���ʹ�� shared_ptr ����,�������������
	//	���ʹ�� unique_ptr ���� auto_ptr һ��,��Ҳ��������Ȩģ��
	//	��ʹ�� unique_ptr ʱ,����ȵ��������н׶α���,���ڱ�����������������ִ���:
	//		pwin = films[2];
	// 
	// unique_ptr Ϊ������ auto_ptr
	//	��������:
	//		auto_ptr<string> p1(new string("auto"));	// #1
	//		auto_ptr<string> p2;						// #2
	//		p2 = p1;									// #3
	//	����� #3 ��,p2 �ӹܶ��������Ȩ��,p1 ������Ȩ��������
	//	ǰ��˵��,���Ǽ�����,�ɷ�ֹ p1 �� p2 ������������ͼɾ��ͬһ������
	//	��������������ͼʹ�� p1,���Ǽ�����,��Ϊ p1 ����ָ����Ч����
	//	������� unique_ptr ����������Ϊ�Ƿ�
	//	����ʱ��,��һ������ָ�븳����һ������������Σ�յ�����ָ��,���������º�������:
	//		unique_ptr<string> demo(const char* s)
	//		{
	//			unique_ptr<string> temp(new string(s));
	//			retuen temp;
	//		}
	//	�������д�����´���:
	//		unique_ptr<stirng> ps;
	//		ps = demo("Uniquely special");
	//	demo() ����һ����ʱ unique_ptr ,Ȼ�� ps �ӹ���ԭ���鷵�ص� unique_ptr ���еĶ���
	//	�����ص� unique_ptr ������,��û������,��Ϊ ps ӵ���� string ���������Ȩ
	//	��֮,������ͼ��һ�� unique_ptr ������һ��ʱ,���Դ unique_ptr �Ǹ���ʱ��ֵ
	//	����������������;���Դ unique_ptr ������һ��ʱ��,����������ֹ������
	//		unique_ptr<string> pu1(new stirng "Hi ho!");
	//		unique_ptr<string> pu2;
	//		pu2 = pu1;										// not allowed
	//		unique_ptr<string> pu3;
	//		pu3 = unique_ptr<string>(new string"Yo!");		// allowed
	//	C++��һ����׼�⺯�� std::move(),�ܹ���һ�� unique_ptr ������һ��
	if (false) {
		std::unique_ptr<std::string> ps1, ps2;
		ps1 = demo("Uniquely special");
		ps2 = std::move(ps1);
		ps1 = demo(" and more");
		std::cout << *ps2 << *ps1 << std::endl;
	}
	//	����� auto_ptr ,unique_ptr ����һ���ŵ�
	//		����һ������������ı���,���뽫 delete �� new ���,�� delete[] �� new[] ���
	//		ģ�� auto_ptr ʹ�� delete ������ delete[],���ֻ���� new һ��ʹ��
	//		�� unique_ptr ��ʹ�� new[] �� delete[] �İ汾:
	//			std::unique_ptr<double[]>pda(new double(5));
	//	�� unique_ptr Ϊ��ֵʱ,�ɽ��丳�� shared_ptr ,���뽫һ�� unique_ptr ������һ��������Ҫ��������ͬ
	//	ģ�� shared_ptr ����һ����ʾ���캯��,�����ڽ���ֵ unique_ptr ת��Ϊ shared_ptr
	//	shared_ptr ���ӹ�ԭ���� unique_ptr ���еĶ���

	// ��׼ģ���
	//	STL�ṩ��һ���ʾ������������������������㷨��ģ��
	//	 - ������һ�����������Ƶĵ�Ԫ,���Դ洢���ɸ�ֵ,STL������ͬ�ʵ�,���洢��ֵ��������ͬ
	//	 - �㷨������ض�����(����������������������в����ض�ֵ)�Ĵ���
	//	 - �������ܹ��������������Ķ���,���ܹ����������ָ������.�ǹ���ָ��
	//	 - ���������������ں����Ķ���,��������������ָ��(����������,��Ϊ������������ָ��)
	//	STLʹ���ܹ������������(�������顢���к�����)��ִ�и��ֲ���(����������������������)
	//	STL�����������ı��,����һ�ֲ�ͬ�ı��ģʽ----���ͱ��(generic programming)
	// 
	//	ģ���� vector
	//		�ڼ�����,ʸ��(vector)��Ӧ����,������11�½��ܵ���ѧʸ��
	//		����ʸ���洢��һ���������ʵ�ֵ,������ʹ��������ֱ�ӷ���ʸ���ĵ� i ��Ԫ��
	//		�������ȷ���ǰ��� i-1 ��Ԫ��
	//		Ҫ���� vector ģ�����,��ʹ��ͨ���� <type> ��ʾ����ָ��Ҫʹ�õ�����
	//		����, vector ģ��ʹ�ö�̬�ڴ����,��˿����ó�ʼ��������ָ����Ҫ����ʸ��
	//		���������[]������,��˿���ʹ��ͨ���������ʾ�������ʸ���Ԫ��
	// 
	//		������:
	//			�� string ������,����STL����ģ�嶼����һ����ѡ��ģ�����
	//			�ò���ָ��ʹ���ĸ������������������ڴ�
	//			����,vector ģ��Ŀ�ͷ����������:
	//			template<class T, class Allocator = allocator<T>>
	//				class vector { ...
	//			���ʡ�Ը�ģ�������ֵ,������ģ�彫Ĭ��ʹ�� allocator<T>��,�����ʹ�� new �� delete
	vect1_cpp();

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
				// ����� 40 ���� 20,������ 15 �����õ��ַ������Ƶ� five �Ľ�β��
				// �����캯�����ڴ���λ���ַ���"All's well that ends well"�����������Ϊ�ַ�
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
	fin.open("E:\\Projects_Myself\\VS2022_Projects\\C++PrimaryPlus\\��XVI�� string��ͱ�׼ģ���\\tobuy.txt");
	// C-����ַ�����ת������ \\ ��ʾһ��б��
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