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
#include<list>
#include<set>

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
void copyit_cpp();
void inserts_cpp();
void list_cpp();
void setops_cpp();

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
	//	�����Խ�ָ��ָ����󸳸���һ��ͬ���͵�����ָ�����,��������һ������,������һ������
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
	//		  ���Ϊ ���ü���(reference counting)
	//		  ����,��ֵʱ,��������1,��ָ�����ʱ,������1
	//		  �������һ��ָ�����ʱ,�ŵ��� delete,���� shared_ptr �Ĳ���
	//	��Ȼ,ͬ���Ĳ���Ҳ�����ڸ��ƹ��캯��
	//	���������һ��������ʹ�� auto_ptr ��ʾ��
	if(false)	fowl_cpp();
	//	�� i = 2 ʱ,�쳣��ֹ����
	//	�������ڽ�����Ȩ�� films[2] ת�ø� pwin
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
	if(false)	vect1_cpp();
	//			�ɶ�ʸ��ִ�еĲ���:
	//			���е�STL�������ṩ��һЩ��������,���а���
	//				size()----����������Ԫ����Ŀ
	//				swap()----����������������
	//				begin()----����һ��ָ��������һ��Ԫ�صĵ�����
	//				end()----����һ����ʾ��������β�ĵ�����
	//			������:
	//				����һ������ָ��
	//				��ʵ��,��������ָ��,Ҳ������һ���ɶ���ִ������ָ�����
	//				----��������(opeartor*())�͵���(��opeartor++())----�Ķ���
	//				�Ժ�֪��,������ָ�뻯Ϊ������,��STL�ܹ�Ϊ���ֲ�ͬ��������
	//				(������Щ��ָ���޷��������)�ṩͳһ�Ľӿ�
	//				ÿ�������඼������һ�����ʵĵ�����,�õ�������������һ����Ϊ
	//				iterator �� typedef,��������Ϊ������
	//				����,ҪΪ vector �� double ���͹淶����һ��������,����������:
	//					vector<double>::iterator pd;
	//				���� scores ��һ�� vector<double> ����
	//				�����ʹ�õ����� pd ִ�������Ĳ���:
	//					pd = scores.begin();
	//					*pd = 22.3;
	//					++pd;
	//				��������������,����������Ϊ����ָ��
	//				˳��һ��,����һ�� C++11 �Զ��ƶ����ͺ����õĵط�
	//				����,���Բ�������:
	//					vector<double>::iterator pd = scores.begin();
	//				��������:
	//					auto pd = scores.begin();
	//			�ص�ǰ���ʾ��,ʲô�ǳ�����β(past-the-end)
	//			����һ�ֵ�����,ָ���������һ��Ԫ�غ�����Ǹ�Ԫ��
	//		���������������ղ����۵ķ���
	//		vector ģ����Ҳ����һЩֻ��ĳЩSTL�������еķ���
	//			push_back()----��Ԫ����ӵ�ʸ��ĩβ
	//							������ʱ,���������ڴ����,����ʸ���ĳ���	
	//			erase()----ɾ��ʸ���и��������Ԫ��
	//							��������������������,��Щ����������Ҫɾ��������
	//							��һ��������ָ���������ʼ��,�ڶ���������λ��������ֹ���ĺ�һ��λ��
	//							���д���ɾ����һ���͵ڶ���Ԫ��
	//								scores.erase(scores.begin(),scores.begin()+2);
	//			insert()----������erase()�෴,������3������������
	//							��һ������ָ������Ԫ�صĲ���λ��
	//							�ڶ����͵��������������������˱���������
	//							������ͨ������һ�����������һ����
	//							����,����Ĵ��뽫ʸ�� new_v �г��˵�һ��Ԫ���������Ԫ�ز��뵽
	//							old_v ʸ���ĵ�һ��Ԫ��ǰ��:
	//								vector<int> old_v;
	//								vector<int> new_v;
	//								...
	//								old_v.insert(old_v.begin(), new_v.begin()+1, new_v.end());
	if(false)	vect2_cpp();
	//	��ʸ����ִ�е���������
	//		3�����д����Ե�STL����:
	//			for_each()----������������,ǰ�����Ƕ�������������ĵ�����,���һ����ָ������ָ��
	//							(���ձ��˵,���һ��������һ����������,���������Ժ����)
	//							�˺�������ָ��ĺ���Ӧ�������������еĸ���Ԫ��
	//							��ָ��ĺ��������޸�����Ԫ�ص�ֵ
	//							������ for_each() ���������� for ѭ��
	//							����,���Խ�����:
	//								vector<Review>::iterator pr;
	//								for (pr = books.begin(); pr != books.end(); pr++)
	//								ShowReview(*pr);
	//							�滻Ϊ:
	//								for_each(books.begin(),books.end(),ShowReview);
	//							�����ɱ�����ʾ��ʹ�õ���������
	//			random_shuffle()----��������ָ������ĵ���������,��������������е�Ԫ��
	//							����,��������������� books ʸ��������Ԫ��:
	//								random_shuffle(books.begin(),books.end());
	//							��������κ�������� for_each ��ͬ
	// 							�ú���Ҫ�������������������,vector �����������һ��
	//							sort() ����ҲҪ������֧���������
	// 							�ú����������汾,��һ���汾����������������ĵ���������
	// 							��ʹ��Ϊ�洢�������е�����Ԫ�ض���� < �����,�������е�Ԫ�ؽ��в���
	// 							�������Ԫ��ʹ�û�����Ķ���,��Ҫʹ�� sort()
	// 							���붨���ܹ���������Ͷ���� operator<() ����
	//							�� Review ����������:
	//								bool opeartor<(const Review & r1, const Review & r2)
	//								{
	//									if (r1.title < r2.title)
	//										return true;
	// 									else if(r1.title == r2.title && r1.rating < r2.rating)
	// 										return true;
	// 									else
	// 										return false;
	//								}
	//							����밴�� rating ����,��ʹ����һ�ָ�ʽ�� sort()
	//							��������������,ǰ��������Ҳ��ָ������ĵ�����
	//							���һ��������ָ��Ҫʹ�õĺ���ָ��(��������)
	//								bool WorseThan(const Review & r1, const Review & r2)
	//								{
	//									if(r1.rating < r2.rating)
	//										return true;
	//									else
	//										return false;
	//								}
	//								sort(books.begin(),books.end(),WorseThan);
	if(false)	vect3_cpp();
	//	���ڷ�Χ��forѭ��(C++11)
	//		�� 5 ��˵��,���ڷ�Χ�� for ѭ����Ϊ���� STL ����Ƶ�
	//			double prices[5] = {4.99, 10.99, 6.83, 9.23, 1.33};
	//			for(double x : prices)
	//				cout << x << endl;
	//		������ for ѭ����,�����ڵĴ�������һ�������������洢���������ݵı���
	//		Ȼ��ָ��������������,������,ѭ����ʹ��ָ���ı���һ�η���������ÿ��Ԫ��
	//		�����������:
	//			for_each(books.begin(),books.end(),ShowReview);
	//		���滻Ϊ:
	//			for(auto x : books)	ShowReview(x);
	//		��ͬ�� for_each(),���ڷ�Χ�� for ѭ�����޸���������,������ָ��һ�����ò���
	//		����:
	//			void InflateReview(Review &r) {r.rating++;}
	//			for(auto& x : books) InflateReview(x);
	
	//	���ͱ��
	/*
		STL ��һ�ַ��ͱ��(generic programming)
		��������̹�ע���Ǳ�̵����ݷ���,�����ͱ�̹�ע�����㷨
		����֮��Ĺ�ͬ���ǳ���ʹ��������ô���,�����ǵ������Ȼ��ͬ
		���ͱ��ּ�ڱ�д�������������͵Ĵ���
		�� C++ ��,���ͨ�ó���Ĺ�����ģ��
		��Ȼ,ģ��ʹ���ܹ������Ͷ��庯������,�� STL ͨ��ͨ���㷨������һ��
		ģ������һ�г�Ϊ����,�������Ԫ�ؽ�����ϸ���

		Ϊ��ʹ�õ�����:
			ģ��ʹ���㷨�����ڴ洢����������,��������ʹ�㷨������ʹ�õ���������
			ģ���ṩ�˴洢�������е��������͵�ͨ�ñ�ʾ
			��˻���Ҫ���������е�ֵ��ͨ�ñ�ʾ,����������������ͨ�ñ�ʾ
			Ҫʵ�� find ����,������Ӧ�߱���Щ����,������һ����̵��б�
				- Ӧ�ܹ��Ե�����ִ�н�����õĲ���,�Ա��ܹ����������õ�ֵ
				  ����� p ��һ��������,��Ӧ�� *p ���ж���
				- Ӧ�ܹ���һ��������������һ��
				  ����� p �� q ���ǵ�����,��Ӧ�Ա��ʽ p=q ���ж���
				- Ӧ�ܹ���һ������������һ�����бȽ�,�������Ƿ����
				  ����� p �� q ���ǵ�����,��Ӧ�� p==q �� p!=q ���ж���
				- Ӧ�ܹ�ʹ�õ��������������е�����Ԫ��
				  �����ͨ��Ϊ������ p ���� ++p �� p++ ��ʵ��
			���� STL �е�ĳ����,������������ָ��;��������һ����,������Ƕ���
			Ψһ��ͬ���� pr ������
			���,STL ͨ��Ϊÿ���ඨ���ʵ��ĵ�����,����ͳһ�ķ�������
			�ܹ����ڲ���ʾ��Ȼ��ͬ������,��д��ͬ�Ĵ���
			ʹ�� C++11 �������Զ������ƶϿɽ�һ����:����ʸ�����б�,������:
				for(auto pr = scores.begin();pr != scores.end();pr++)
					cout << *pr << endl;
			��Ϊһ�ֱ�̷��,��ñ���ֱ��ʹ�õ�����,��Ӧ������ʹ�� STL ����������ϸ��
			Ҳ��ʹ�� C++11 �����Ļ��ڷ�Χ�� for ѭ��:
				for(auto x : scores) cout << x << endl;

			���ܽ��� STL ����
			�����Ǵ����������㷨,Ӧ��������ͨ�õ�����������㷨,ʹ֮�������������ͺ���������
			Ϊʹͨ���㷨�ܹ������ھ������
			Ӧ�����ܹ������㷨����ĵ�����,����Ҫ��ӵ����������
			�������㷨��Ҫ��,��ƻ�������������������������
	*/

	// ����������
	/*
		STL ������ 5 �ֵ�����,����������ĵ��������Ͷ��㷨����������
		�� 5 �ֵ������ֱ���:
		���������������������������������˫���������������ʵ�����
		����,find()��ԭ������������:
			template<class InputIterator, class T>
			InputIterator find(InputIterator first, InputIterator last, const T& value);
		��ָ��,�����㷨��Ҫһ�����������,ͬ��,�����ԭ��ָ�������㷨��Ҫһ��������ʵ�����:
			template<class RandomAccessIterator>
			void sort(RandomAccessIterator first, RandomAccessIterator last);
		������ 5 �ֵ�����,������ִ�н�����ò���,Ҳ�ɽ��бȽ�,������Ȼ��ǲ���
		���������������ͬ,�������ִ�н�����ò����õ���ֵ����ͬ
			iter1 == iter2
			is true, then the following is also true:
			* iter1 == * iter2
			
		1.���������
			����"����"�Ǵӳ���ĽǶ�˵��,��������������Ϣ����Ϊ����
			�������Լ��̵���Ϣ�Գ�����˵������һ��
			���,����������ɱ�����������ȡ�����е���Ϣ
			�����˵,�����������������ý�ʹ�����ܹ���ȡ�����е�ֵ,����һ�����ó����޸�ֵ
			��������������ܹ��������������е�ֵ,����ͨ��֧��++�����(ǰ׺�ͺ�׺��ʽ)��ʵ�ֵ�
			����������������κ��㷨��Ӧ���ǵ�ͨ�е�,��������ǰһ�α���ʱ�ĵ�����ֵ
			Ҳ�������ڱ��α�����ǰ��ĵ�����ֵ
			����������ǵ��������,���Ե���,�����ܵ���

		2.���������
			STL ʹ������"���"��ֻ���ڽ���Ϣ�ӳ��򴫳��������ĵ�����
			��˳���������������������
			������������������������,ֻ�ǽ�������ó������޸�����ֵ,�����ܶ�ȡ
			���͵���ʾ���ϵ�����������,cout �����޸ķ��͵���ʾ�����ַ���
			ȴ���ܶ�ȡ��Ļ�ϵ�����
			STL �㹻ͨ��,���������Ա�ʾ����豸,�������Ҳ�������
			����,����㷨���ö�ȡ�����������ݾͿ����޸���(��ͨ������Ҫ�洢����ֵ)
			��û������Ҫ����ʹ���ܹ���ȡ���ݵĵ�����
			�����֮,���ڵ�ͨ�С�ֻ���㷨,����ʹ�����������
			�����ڵ�ͨ�С�ֻд�㷨,�����ʹ�����������

		3.���������
			�������������������,���������ֻ���� ++ ���������������
			������ÿ����������ǰ�ƶ�һ��Ԫ��
			Ȼ��,�����������������ͬ����,�����ǰ���ͬ��˳�����һϵ��ֵ

		4.˫�������
			reverse �������Խ�����һԪ�غ����һԪ�ء���ָ���һ��Ԫ��ָ���1
			��ָ��ڶ���Ԫ�ص�ָ���1,���ظ����ִ������
			˫������������������������������,ͬʱ֧������(ǰ׺�ͺ�׺)�ݼ������

		5.������ʵ�����
			��Щ�㷨(���׼����Ͷ��ֲ���)Ҫ���ܹ�ֱ�����������ֵ��κ�һ��Ԫ��
			����� �������,��Ҫ������ʵ�����
			������ʵ���������˫�����������������
			ͬʱ�����֧��������ʵĲ���(��ָ����������)�����ڶ�Ԫ�ؽ�������Ĺ�ϵ�����
			�±��г���˫�������������,������ʵ�������֧�ֵĲ���
			X ��ʾ�������������,T ��ʾ��ָ�������,a �� b ���ǵ�����ֵ, n Ϊ����
			r Ϊ�������������������

			���ʽ						����
			a + n						ָ�� a ��ָ��Ԫ�غ�ĵ� n ��Ԫ��
			n + a						�� a + n ��ͬ
			a - n						ָ�� a ��ָ���Ԫ��ǰ�ĵ� n ��Ԫ��
			r += n						�ȼ��� r = r + n
			r -= n						�ȼ��� r = r - n
			a[n]						�ȼ��� *(a + n)
			b - a						���Ϊ������ n ֵ,�� b = a + n
			a < b						��� b - a > 0,��Ϊ��
			a > b						��� b < a,��Ϊ��
			a >= b						��� !(a < b),��Ϊ��
			a <= b						��� !(a > b),��Ϊ��
	*/

	// ��������νṹ
	/*
		�±��ܽ�����Ҫ�ĵ���������
		����, i Ϊ������, n Ϊ����

								����������
����������			����		���			����		˫��		�������
������ö�ȡ		��			 ��				 ��			 ��			   ��
�������д��		��			 ��				 ��			 ��			   ��
�̶��Ϳ��ظ�����	��			 ��				 ��			 ��			   ��
++i  i++			��			 ��				 ��			 ��			   ��
i  i				��			 ��				 ��			 ��			   ��
i[n]				��			 ��				 ��			 ��			   ��
i + n				��			 ��				 ��			 ��			   ��
i - n				��			 ��				 ��			 ��			   ��
i += n				��			 ��				 ��			 ��			   ��
i -= n				��			 ��				 ��			 ��			   ��

		��Ҫ��ô���������Ŀ��:
			Ϊ���ڱ�д�㷨������ʹ����͵ĵ�����,�������������������������
			����,ͨ��ʹ�ü�����͵����������,find()�������ǿ������κΰ����ɶ�ȡֵ������
			��sort()����������Ҫ������ʵ�����,����ֻ������֧�����ֵ�����������
	*/

	// ����Ľ���ģ��
	/*
		1.��ָ������������
			�������ǹ���ָ��,��ָ���������еĵ�����Ҫ��
			�������� STL �㷨�Ľӿ�,��ָ���ǵ�����,��� STL �㷨����ʹ��ָ�����Ի���ָ���
			�� STL �������в���

			int casts[10] = {6, 2, 4, 5, 8, 3, 1, 8, 2, 1};
			vector<int> dice(10);
			copy(casts, casts + 10, dice.begin());

			copy()��ǰ����������������ʾҪ���Ƶķ�Χ,���һ��������������ʾҪ����һ��Ԫ�ظ��Ƶ�ʲôλ��
			ǰ����λ�ñ�����(�������)���������,���һ��������(�������)���������

			��Ҫ����Ϣ���Ƶ���ʾ����
			STL Ϊ���ֵ������ṩ�� ostream_iterator ģ��
			�� STL �Ļ�˵,��ģ������������������һ��ģ��
			��Ҳ��һ��������(adapter) ---- һ�������,���Խ�һЩ�����ӿ�ת��Ϊ STL ʹ�õĽӿ�
			����ͨ������ͷ�ļ� iterator ����������������������ֵ�����:
				#inlcude<iteartor>
				...
				ostream_iterator<int, char> out_iter(cout, " ");
			out_iter ������������һ���ӿ�,�ܹ�ʹ�� cout ����ʾ��Ϣ
			��һ��ģ�����(������ int)ָ���˱����͸����������������
			�ڶ���ģ�����(����Ϊ char)ָ���������ʹ�õ��ַ�����(��һ�����ܵ�ֵ�� wchar_t)
			���캯���ĵ�һ������(����Ϊ cout)ָ����Ҫʹ�õ������,��Ҳ�����������ļ��������
			���һ���ַ����������ڷ��͸��������ÿ�����������ʾ�ķָ���
				��������ʹ�õ�����:
				*out_iter++ = 15;		// works like cout << 15 << " ";
			���ڳ���ָ��,����ζ�Ž� 15 ����ָ��ָ���λ��,Ȼ��ָ��� 1
			�����ڸ� ostream_iterator,����ζ�Ž� 15 ���ɿո���ɵ��ַ���
			���͵� cout ������������,��δ��һ���������������׼��
			���Խ� copy() ���ڵ�����:
				copy(dice.begin(), dice.end(), out_iter);
			����ζ�Ž� dice �������������临�Ƶ��������,����ʾ���׵�����
			Ҳ���Բ����������ĵ�����,��ֱ�ӹ���һ������������:
				copy(dice.begin(), dice.end(), ostream_iterator<int, char>(cout," "));
			iterator ͷ�ļ���������һ�� istream_iterator ģ��
			ʹ�� istream ����������������ӿ�
			����һ����������������ģ��
			����ʹ������ istream_iterator ���������� copy() �����뷶Χ:
				copy(istream_iteartor<int, char>(cin),
					istream_iteartor<int, char>(), dice.begin());
			istream_iterator �ĵ�һ������ָ��Ҫ��ȡ����������
			�ڶ�������ָ��������ʹ�õ��ַ�����
			ʹ�ù��캯������ cin ��ζ��ʹ���� cin �����������
			ʡ�Թ��캯��������������ʧ��
			�������������������ж�ȡ,ֱ���ļ���β�����Ͳ�ƥ�����������������Ϊֹ

		2.�������õĵ�����
			ͷ�ļ� iterator �ṩ��һЩר�õ�Ԥ�������������:
				reverse_iterator��back_iterator��front_insert_iterator �� insert_iterator

			reverse_iterator:
				�� reverse_iterator ִ�е������������������ݼ�
				��ֱ�ӶԳ�����������еݼ�����Ҫԭ����Ϊ�˼򻯶����к�����ʹ��
				������ʾ dice ���������ݣ���:

					ostream_iterator<int, char> out_iter(cout, " ");
					copy(dice.begin(), dice.end(), out_iter);

				�ּ��跴���ӡ���ݣ�vertor ����һ����Ϊ rbegin() ��һ����Ϊ rend() �ĳ�Ա����
				�ֱ𷵻�ָ��β�ķ����������ָ���һ��Ԫ�صķ��������:

					copy(dice.rbegin(), dice.rend(), out_iter);

				ע��:
					rbegin() �� end() ������ͬ��ֵ(��β)�������Ͳ�ͬ(reverse_iterator �� iterator)
					ͬ��, rend() �� begin() Ҳ������ͬ��ֵ(ָ���һ��Ԫ�صĵ�����)�������Ͳ�ͬ

				����Է����������һ�����ⲹ��
				���� rp ��һ������ʼ��Ϊ dice.rbegin() �ķ�תָ��
				��ô *rp ��ʲô��?
				��Ϊ rbegin() ���س�β����˲��ܶԸõ�ַ���н������
				ͬ������� rend() �ǵ�һ��Ԫ�ص�λ�ã��� copy() ��������һ��λ��ֹͣ
				��Ϊ����Ľ�β����������������
				
				����ָ��ͨ���ȵݼ����ڽӴ����ý��������������
				copyit_cpp() ��ʾ�����ʹ�� copy()��istream �������ͷ��������

	*/
	if (false) copyit_cpp();
	/*
				�����Ŀ����������ʱ
				���ֲ��������ͨ��������ת��Ϊ����������Щ����
				���뽫����µ�Ԫ�أ������Ḳ�����е����ݣ���ʹ���Զ��ڴ������ȷ���ܹ������µ���Ϣ

				back_insert_iterator ��Ԫ�ز��뵽����β��
				front_insert_iterator ��Ԫ�ز��뵽������ǰ��
				insert_iterator ��Ԫ�ز��뵽 insert_iterator ���캯���Ĳ���ָ����λ��ǰ��

				�������������������������������ģ��

				����һЩ����:
					back_insert_iterator ֻ������������β�����ٲ��������, vector ���������Ҫ��
					front_insert_iterator ֻ��������������ʼλ����ʱ��̶��������������, vector �಻����, queue �����
					insert_iterator û����Щ����,��˿�����������Ϣ���뵽ʸ����ǰ��
					Ȼ��,front_insert_iterator ������Щ֧������������˵�����������ٶȸ���

				��Щ������������������Ϊģ���������ʵ�ʵ�������ʶ����Ϊ���캯������
				ҪΪ��Ϊ dice �� vector<int> ��������һ�� back_insert_iterator :
					back_insert_iterator<vector<int>> back_iter(dice);
				���������������͵�ԭ����,����������ʹ�ú��ʵ���������
				front_insert_iterator �ķ�ʽ�����ͬ
				���� insert_iterator ����,����Ҫһ��ָʾ����λ�õĹ��캯������:
					insert_iterator<vector<int>> insert_iter(dice, dice.begin());

				���� insert_cpp() ��ʾ�������ֵ��������÷�, ������ for_each() ������ ostream �������������
	*/
	if(false) inserts_cpp();

	// ��������
	/*
		STL ���������������������
		�����Ǿ�������(��������������������������)��ͨ�����
		���������ǿ����ڴ����������������ģ��

		��ǰ�� 11 ���������ͷֱ��� deque, list, queue, priority_queue, stack, vector, map, multimap,
		set, multiset �� bitset (���²����� bitset,�����ڱ��ؼ��������ݵ�����)
		C++11 ������ forward_list, unordered_map, unordered_multimap, unordered_set �� unordered_multiset

		1. ��������:
			û����������������Ӧ�����ͣ����������������������඼ͨ�õ�Ԫ��
			����һ������ĳ������----˵�����������Ϊ�����ಢ������ʹ�ü̳л���
			���仰˵����������ָ�������� STL �����඼���������һϵ��Ҫ��

			���ܽ��κ����͵Ķ���洢��������,�����˵,���ͱ����ǿɸ��ƹ���ĺͿɸ�ֵ��
			��������������ЩҪ��,ֻҪ�ඨ��û�н����ƹ��캯���͸�ֵ���������Ϊ˽�л򱣻���
			��Ҳ��������Ҫ��
			C++11 �Ľ�����Щ����,���������ɸ��Ʋ���(CopyInsertable)�Ϳ��ƶ�����(MoveInsertable),������ֻ���м򵥵ĸ���

			�����������ܱ�֤��Ԫ�ض����ض���˳��洢,Ҳ���ܱ�֤Ԫ�ص�˳�򲻱�
			���Ը�����иĽ���,��������������ı�֤
			�����������ṩĳϵ�����Ͳ���,�±��һЩͨ�������������ܽ�
			����,X ��ʾ��������,�� vector
			T ��ʾ�洢�������еĶ�������
			a, b ��ʾ����Ϊ X ��ֵ
			r ��ʾ����Ϊ X& ��ֵ
			u ��ʾ����Ϊ X �ı�ʶ��(����� X ��ʾ vector<int>,�� u ��һ�� vector<int> ����)

���ʽ				��������						˵��										���Ӷ�
X::iterator			ָ�� T �ĵ���������				�������������Ҫ����κε�����				����ʱ��
X::value_type		T								T ������									����ʱ��
X u													����һ����Ϊ u �Ŀ�����						�̶�
X()													����һ�������Ŀ�����						�̶�
X u(a)												���ø��ƹ��캯���� u == a					����
X u = a												����ͬ X u(a)		 						����
r = a				X&								���ø�ֵ������� r == a						����
(&a)->~X()			void							��������ÿ��Ԫ��Ӧ����������				����
a.begin()			������							����ָ��������һ��Ԫ�صĵ�����				�̶�
a.end()				������							���س�βֵ������							�̶�
a.size()			�޷�������						����Ԫ�ظ���,�ȼ��� a.end()-a.begin()		�̶�
a.swap(b)			void							���� a �� b ������							�̶�
a == b				��ת��Ϊ bool					��� a �� b Ԫ�س�����ͬ,�� a ��ÿ��		����
													Ԫ�ض�����(== Ϊ��)b ����Ӧ��Ԫ��,��
													Ϊ��
a != b				��ת��Ϊ bool					���� !(a==b)								����

			���е�"���Ӷ�"һ��������ִ�в��������ʱ��
			������г��� 3 �п�����,�ӿ쵽������Ϊ:
				- ����ʱ��
				- �̶�ʱ��
				- ����ʱ��

			������Ӷ�Ϊ����ʱ��,��������ڱ���ʱִ��,ִ��ʱ��Ϊ 0
			�̶����Ӷ���ζ�Ų��������н׶�,�������ڶ����е�Ԫ����Ŀ
			���Ը��Ӷ���ζ��ʱ����Ԫ����Ŀ������
		
			���Ӷ�Ҫ���� STL ����,��Ȼʵ��ϸ�ڿ�������,�����ܹ��Ӧ����
			�Ա����Ա�ܶ�֪������ض������ļ���ɱ�

		2. C++11 ����������Ҫ��
			�±��г��� C++11 ������ͨ������Ҫ��
			���������,rv ��ʾ����Ϊ X �ķǳ�����ֵ,�纯���ķ���ֵ

���ʽ				��������						˵��										���Ӷ�
X u(rv)												�����ƶ����캯����,u ��ֵ�� rv ��			����
													ԭʼֵ��ͬ
X u = rv											����ͬ X u(rv)
a = rv				X&								�����ƶ���ֵ�������,u ��ֵ�� rv			����
													��ԭʼֵ��ͬ
a.cbegin()			const_iterator					����ָ��������һ��Ԫ�ص� const ��			�̶�
													����
a.cend()			const_iterator					���س�βֵ const ������						�̶�

			���ƹ���͸�ֵ��ֵ�Լ��ƶ�������ƶ���ֵ֮��Ĳ������
			���Ʋ�������Դ����,���ƶ��������޸�Դ����,������ת������Ȩ,�������κθ���
			���Դ����ʱ��,�ƶ�������Ч�ʽ����ڳ��渴��

		3. ����
			����ͨ�����Ҫ�����Ľ���������������
			����(sequence)��һ����Ҫ�ĸĽ�
			��Ϊ 7 �� STL ��������(deque��forward_list��queue��priority_queue��stack �� vector)
			��������
			���и��������˵��������������������������Ҫ��
			�Ᵽ֤Ԫ�ؽ����ض�˳������,���������ε���֮�䷢���仯
			array Ҳ�����ൽ��������,��Ȼ�������������е�����Ҫ��

			���л�Ҫ����Ԫ�ذ��ϸ������˳������,�����ڵ�һ��Ԫ�ء����һ��Ԫ��
			����һ��Ԫ�غ����һ��Ԫ����,ÿ��Ԫ��ǰ�󶼷ֱ���һ��Ԫ��
			���ֺ�����������,����֧�ṹ����

			�±��г������б�����ɵĲ���
			t ��ʾ����Ϊ T(�洢��������ֵ������)��ֵ
			n ��ʾ����,p��q��i �� j ��ʾ������

���ʽ					��������						˵��
X a(n, t)												����һ����Ϊ a ���� n �� t ֵ��ɵ�����
X(n, t)													����һ���� n �� t ֵ��ɵ���������
X a(i, j)												����һ����Ϊ a ������,�������ʼ��Ϊ����[i, j)������
X(i, j)													����һ����������,�������ʼ��Ϊ����[i, j)������
a.insert(p, t)			������							�� t ���뵽 p ��ǰ��
a.insert(p, n, t)		void							�� n �� t ���뵽 p ��ǰ��
a.insert(p, i, j)		void							������ [i, j) �е�Ԫ�ز��뵽 p ��ǰ��
a.erase(p)				������							ɾ�� p ָ���Ԫ��
a.erase(p, q)			������							ɾ�� [p, q) �е�Ԫ��
a.clear()				void							�ȼ��� erase(begin(), end())

			��Ϊģ���� deque��list��queue��priority_queue��stack �� vector �������и���ģ��
			�������Ƕ�֧���ϱ����,����֮�⻹��ʹ����������,�����������,���ǵĸ��Ӷ�Ϊ�̶�ʱ��
			�±��г�����������

���ʽ					��������					����						����
a.front()				T&							*a.begin()					vector��list��deque
a,back()				T&							*--a.end()					vector��list��deque
a.push_front(t)			void						a.insert(a.begin(), t)		list��deque
a.push_back(t)			void						a.insert(a.end(), t)		vector��list��deque
a.pop_front(t)			void						a.erase(a.begin())			list��deque
a.pop_back(t)			void						a.erase(--a.end())			vector��list��deque
a[n]					T&							*(a,begin()+n)				vector��deque
a.at(t)					T&							*(a,begin()+n)				vector��deque

			a[n] �� a.at(n) ����������,��� n ������������Ч����,�� a.at(n) ��ִ�б߽���,������
			out_of_range �쳣

			��������� 7 ��������������
			(1) vector
				��ģ������ vector ͷ�ļ���������
				�򵥵�˵,vector �������һ�����ʾ,���ṩ�Զ��ڴ������
				���Զ�̬�ĸı� vector ����ĳ���
				������Ԫ�ص���Ӻ�ɾ�����������С
				���ṩ��Ԫ�ص��������
				��β����Ӻ�ɾ��Ԫ�ص�ʱ���ǹ̶���
				����ͷ�����м�����ɾ��Ԫ�صĸ��Ӷ�Ϊ����ʱ��
				��������,vector ���� �ɷ�ת����(reversible container) �����ģ��
				�������������෽��: rbegin() �� rend()
				ǰ�߷���һ��ָ��ת���еĵ�һ��Ԫ�صĵ�����
				���߷��ط�ת���еĳ�β������
				����,Show(int)	����ʾһ�������ĺ���:
					for_each(dice.begin(), dice.end(), Show);		// display in order
					cout << endl;
					for_each(dice.rbegin(), dice.rend(), Show);		// display in reversed order
					cout << endl;
				�����з������صĵ����������༶���� reverse_iterator

			(2) deque
				deque ģ������ deque ͷ�ļ�������,��ʾ˫�˶���(double-ended queue)
				ͨ�������Ϊ deque
				�� STL ��,��ʵ�������� vector ����,֧���������
				��Ҫ��������,�� deque ����Ŀ�ʼλ�ò����ɾ��Ԫ�ص�ʱ���ǹ̶���
				Ϊʵ�� deque ����ִ�в����ɾ��������ʱ��Ϊ�̶���һĿ��
				deque �������Ʊ� vector �����Ϊ����
				���������ʺ������в������ɾ������ vector �ٶ�Ҫ��Щ

			(3) list
				list ģ������ list ͷ�ļ�������,��ʾ˫������
				����һ�������һ��Ԫ����,ÿ��Ԫ�ض���ǰ���Ԫ��������
				����ζ�����˫���������
				�� vector �Ĺؼ���������,list ����������һλ�ý��в����ɾ����ʱ�䶼�ǹ̶���
				���,vector ǿ������ͨ��������ʽ��п��ٷ���,�� list ǿ������Ԫ�صĿ��ٲ���
				list Ҳ�ǿɷ�ת����
				�� vector ��ͬ����,list ��֧�������ʾ�����������
				��ʸ����������ͬ,�������в����ɾ��Ԫ��֮��,���������ָ��Ԫ�ؽ�����
				�����кͿɷ�ת�����ĺ�����,list ģ���໹����������ר�õĳ�Ա����
				�±��г�������һЩ(��¼ G ���������б�)
				ͨ�����ص��� Alloc ģ�����,��Ϊ����Ĭ��ֵ

����												˵��
void merge(list<T, Alloc>& x)						������ x ���������ϲ�,������������Ѿ�����
													�ϲ���ľ���������������ڵ���������,x Ϊ��
													��������ĸ��Ӷ�Ϊ����
void remove(const T& val)							��������ɾ�� val ������ʵ��,��������ĸ��Ӷ�Ϊ����ʱ��
void sort()											ʹ�� < ��������������������: N ��Ԫ�صĸ��Ӷ�Ϊ NlogN
void splice(iterator pos, list<T, Alloc>x)			������ x �����ݲ��뵽 pos ��ǰ��,x ��Ϊ��
													��������ĸ��Ӷ�Ϊ�̶�ʱ��
void unique()										����������ͬԪ��ѹ��Ϊ����Ԫ��
													��������ĸ��Ӷ�Ϊ����ʱ��

				���� list_cpp() ��ʾ����Щ����
	*/
	if (false)	list_cpp();
	/*
				insert() �� splice() ����Ҫ��������: insert() ��ԭʼ����ĸ������뵽Ŀ���ַ
				�� splice() ��ԭʼ�����Ƶ�Ŀ���ַ
				splice() ִ�к�,����������Ч
				���зǳ�Ա sort() ����,������Ҫ������ʵ�����
				��Ϊ���ٲ���Ĵ����Ƿ���������ʹ���
				���Բ��ܽ��ǳ�Ա���� sort() ��������
				���,������а�����һ��ֻ��������ʹ�õĳ�Ա�汾

				list ������
					list ���������һ������Ĺ�����
					sort()��merge()�� unique()����������ӵ�н�����һ�������İ汾
					�ò�������ָ�������Ƚ�Ԫ�صĺ���
					remove()����Ҳ��һ��������һ�������İ汾
					�ò�������ָ������ȷ���Ƿ�ɾ��Ԫ�صĺ���
					��Щ��������ν�ʺ���

			(4) forward_list
				C++11 ������������ forward_list,��ʵ���˵�����
				forward_list ֻ��Ҫ���������,������Ҫ˫�������
				�ǲ��ɷ�ת����

			(5) queue
				queue ģ������ͷ�ļ� queue ����������һ����������
				��Ǯ����,ostream_iterator ģ�����һ��������
				��������ܹ�ʹ�õ������ӿ�
				ͬ��,queue ģ���õײ���(Ĭ��Ϊ deque)չʾ���͵Ķ��нӿ�
				queue ģ������Ʊ� deque ����
				������������������ʶ���Ԫ��,�����������������

						queue �Ĳ���
����								˵��
bool empty()const				�������Ϊ��,�򷵻� true;���򷵻� false
size_type size()const			���ض�����Ԫ�ص���Ŀ
T& front()						����ָ�������Ԫ�ص�����
T& back()						����ָ�����βԪ�ص�����
void push(const T& x)			�ڶ�β���� x
void pop()						ɾ������Ԫ��

			(6) priority_queue
				priority_queue ģ������ queue ͷ�ļ�������,��һ����������
				��֧�ֵĲ����� queue ��ͬ
				����֮�����Ҫ��������,�� priority_queue ��,
				����Ԫ�ر��Ƶ�����
				�ڲ�����������,Ĭ�ϵĵײ����� vector
				�����޸�����ȷ���ĸ�Ԫ�طŵ����׵ıȽϷ�ʽ
				�������ṩһ����ѡ�Ĺ��캯������:
					priority_queue<int>	pq1;					// default version
					priority_queue<int>	pq2(greater<int>);		// use greater<int> to order
				
				greater<int>() ������һ��Ԥ����ĺ�������	

			(7) stack
				stack ��ͷ�ļ� stack ������,Ҳ�Ǹ���������
				�����ײ�(Ĭ�������Ϊ vector)�ṩ���͵�ջ�ӿ�
				stack ģ������Ʊ� vector ����
				�������������������ջԪ��,�������������ջ

							stack �Ĳ���
����								˵��
bool empty()const				���ջΪ��,�򷵻� true;���򷵻� false
size_type size()const			����ջ��Ԫ�ص���Ŀ
T& top()						����ָ��ջ��Ԫ�ص�����
void push(const T& x)			��ջ�������� x
void pop()						ɾ��ջ��Ԫ��

			(8) array
				�� 4 �½��ܹ�
				ģ���� array ��ͷ�ļ� array �ж����,������ STL ����
				��Ϊ�䳤���ǹ̶���,���,array û�ж������������С�Ĳ���
				�������˶�����˵������ĳ�Ա����,�� operator[]() �� at()
				�ɽ��ܶ��׼ STL �㷨���� array ����,�� copy() �� for_each()
		
		4. ��������
			��������(associative container)�Ƕ������������һ���Ľ�
			����������ֵ���������һ��,��ʹ�ü�������ֵ
			����,ֵ�����Ǳ�ʾ��Ա��Ϣ�Ľṹ,����������Ψһ��Ա�����
			Ϊ��ȡ��Ա��Ϣ,����ʹ�ü����ҹ�Ա�ṹ
			ǰ��˵��,�������� X,���ʽ X::value_type ͨ��ָ���˴洢��������ֵ������
			���ڹ���������˵,���ʽ X::key_type ָ���˼�������

			�����������ŵ�����,���ṩ�˶�Ԫ�صĿ��ٷ���
			����������,��������Ҳ���������Ԫ��
			������ָ��Ԫ�صĲ���λ��,ԭ����
			��������ͨ��������ȷ�����ݷ���λ�õ��㷨,�Ա��ܹ����ټ�����Ϣ

			��������ͨ����ʹ��ĳ����ʵ�ֵ�

			STL �����ֹ�������: set��multiset��map �� multimap
			ǰ��������ͷ�ļ� set �ж����
			����������ͷ�ļ� map �ж����

			��򵥵Ĺ��������� set,��ֵ���������ͬ,����Ψһ��
			����ζ�ż����в����ж����ͬ�ļ�,�� set ��˵,ֵ���Ǽ�
			multiset ������ set,ֻ�ǿ����ж��ֵ�ļ���ͬ

			�� map ��,ֵ��������Ͳ�ͬ,����Ψһ��,ÿ������Ӧһ��ֵ
			multimap �� map ����,ֻ��һ������������ֵ�����
	*/
			// [1] set ʾ��
			/*
				STL set ģ���˶������,���ǹ�������,�ɷ�ת,������,�Ҽ���Ψһ��,���Բ��ܴ洢�����ͬ��ֵ
				���� setops_cpp() ��ʾһЩ���� 
			*/
	if (true)	setops_cpp();

			// [2] multimap ʾ��


	if (false) {
		std::ostream_iterator<int, char> out_iter(std::cout, " ");
		*out_iter = 15;
		*out_iter++ = 16;

		int casts[10] = { 6, 2, 4, 5, 8, 3, 1, 8, 2, 1 };
		std::vector<int> dice(10);

		std::copy(casts, casts + 10, dice.begin());

		std::copy(dice.begin(), dice.end(), std::ostream_iterator<int, char>(std::cout, " "));

		std::copy(std::istream_iterator<int, char>(std::cin),
			std::istream_iterator<int, char>(), dice.begin());

		std::copy(dice.begin(), dice.end(), std::ostream_iterator<int, char>(std::cout, " "));
	}

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

bool FillReview(Review& rr)		/* ���뷶�� */
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

void copyit_cpp()
{// copyit.cpp -- copy() and iterator
	
	using namespace std;

	int casts[10] = { 6, 7, 2, 9, 4, 11, 8, 7, 10, 5 };
	std::vector<int> dice(10);
	// copy from array to vertor
	copy(casts, casts + 10, dice.begin());
	cout << "Let the dice be cast!\n";
	// create an ostream iterator
	ostream_iterator<int, char> out_iter(cout, " ");
	// copy from vector to output
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;
	cout << "Implict use of reverse iterator.\n";
	copy(dice.rbegin(), dice.rend(), out_iter);
	cout << endl;
	cout << "Explicit use of reverse iterator.\n";
	vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
		cout << *ri << " ";
	cout << endl;
}

void output(const std::string& s) { std::cout << s << " "; }

void inserts_cpp()
{// inserts.cpp -- copy() and insert iterators

	using namespace std;

	string s1[4] = { "fine", "fish", "fashion", "fate" };
	string s2[2] = { "busy", "bats" };
	string s3[2] = { "silly", "singers" };

	vector<string> words(4);
	copy(s1, s1 + 4, words.begin());
	for_each(words.begin(), words.end(), output);
	cout << endl;

// construct anonymous back_insert_iterator object
	copy(s2, s2 + 2, back_insert_iterator<vector<string>>(words));
	for_each(words.begin(), words.end(), output);
	cout << endl;

// construct anonymous insert_iterator object
	copy(s3, s3 + 2, insert_iterator<vector<string>>(words, words.begin()));
	for_each(words.begin(), words.end(), output);
	cout << endl;
}

void outint(int n) { std::cout << n << " "; }

void list_cpp()
{// list.cpp -- using a list
	using namespace std;

	list<int> one(5, 2);		// list of 5 2s
	int stuff[5] = { 1, 2, 4, 8, 6 };
	list<int> two;
	two.insert(two.begin(), stuff, stuff + 5);
	int more[6] = { 6, 4, 2, 4, 6, 5 };
	list<int> three(two);
	three.insert(three.end(), more, more + 6);

	cout << "List one: ";
	for_each(one.begin(), one.end(), outint);
	cout << endl << "List two: ";
	for_each(two.begin(), two.end(), outint);
	cout << endl << "List three: ";
	for_each(three.begin(), three.end(), outint);
	three.remove(2);
	cout << endl << "List three minus 2s: ";
	for_each(three.begin(), three.end(), outint);
	three.splice(three.begin(), one);
	cout << endl << "List three after splice: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl << "List one: ";
	for_each(one.begin(), one.end(), outint);
	three.unique();
	cout << endl << "List three after unique: ";
	for_each(three.begin(), three.end(), outint);
	three.sort();
	three.unique();
	cout << endl << "List three after sort & unique: ";
	for_each(three.begin(), three.end(), outint);
	two.sort();
	three.merge(two);
	cout << endl << "Sorted two merged into three: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl;
	// cin.get();
}
void setops_cpp()
{// setops.cpp -- some set operations
	using namespace std;

	const int N = 6;
	string s1[N] = { "buffoon", "thinkers", "for", "heavy", "can", "for" };
	string s2[N] = { "metal", "any", "food", "elegant", "deliver","for" };

	// �� vector �� list ����,set Ҳ����ģ���������ָ��Ҫ�洢��ֵ����
	//		set<string> A
	// �ڶ���ģ������ǿ�ѡ��,����ָʾ�����Լ���������ıȽϺ��������
	// Ĭ������½�ʹ��ģ�� less<>
	//		set<string, less<string>> A;
	
	set<string> A(s1, s1 + N);
	set<string> B(s2, s2 + N);
	// set Ҳ��һ����������������Ϊ�����Ĺ��캯��
	// ���ṩ��һ�ֽ����ϳ�ʼ��Ϊ�������ݵļ򵥷���

	ostream_iterator<string, char> out(cout, " ");
	cout << "Set A: ";
	copy(A.begin(), A.end(), out);
	cout << endl << endl;
	cout << "Set B: ";
	copy(B.begin(), B.end(), out);
	cout << endl << endl;
	// ����������������,����Ψһ��

	// ��ѧΪ���϶�����һЩ��׼����,����,���������������Ϻϲ��������
	// ���������������϶��е�Ԫ��
	// �������ϵĲ��ǵ�һ�����ϼ�ȥ�������϶��е�Ԫ��
	// STL �ṩ��֧����Щ�������㷨
	// ������ͨ�ú���,�����Ƿ���
	// ���� set �����Զ�����ʹ����Щ�㷨���Ⱦ�����,�������Ǿ��������

	cout << "Union of A and B:\n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl << endl;
	// set_union() �󼯺ϵĲ���
	// �����������: 
	// ǰ���������������˵�һ�����ϵ�����
	// �����������������������˵ڶ������ϵ�����
	// ���һ�������������������
	
	cout << "Intersection of A and B:\n";
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl << endl;
	// set_intersection()�������ҽ���

	cout << "Difference of A and B:\n";
	set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl << endl;
	// set_difference()��������������ϵĲ�

	set<string> C;
	cout << "Set C:\n";
	set_union(A.begin(), A.end(), B.begin(), B.end(),
		insert_iterator<set<string>>(C, C.begin()));
	copy(C.begin(), C.end(), out);
	cout << endl << endl;
	// ����Ҫ��������ڼ��� C ��,�����һ������Ӧ��һ��ָ�� C �ĵ�����
	// �Զ��׼�ѡ�� C.begin(),��������
	// ԭ��:
	// ����,�������Ͻ�����������,���� C.begin() ���ص������ǳ���������,�����������������
	// �ڶ���ԭ��,�� copy() ����,set_union() ���������������е�����
	// ��Ҫ���������㹻�Ŀռ���������Ϣ
	// C �ǿյ�,������������Ҫ��
	// ����ģ�� insert_iterator ���Խ������������

	string s3("grungy");
	C.insert(s3);
	cout << "Set C after insertion:\n";
	copy(C.begin(), C.end(), out);
	cout << endl << endl;
	// ��������˲����λ��,�������������ָֻ��Ҫ�������Ϣ
	// ����ָ��λ�õĲ��뷽��

	cout << "Showing a range:\n";
	copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
	cout << endl << endl;
	// ���� lower_bound() ������Ϊ����������һ��ָ�򼯺��е�һ����С�ڼ������ĳ�Ա�ĵ�����
	// ���� upper_bound() ������Ϊ����������һ��ָ�򼯺��е�һ�����ڼ������ĳ�Ա�ĵ�����

	// cin.get();
}
