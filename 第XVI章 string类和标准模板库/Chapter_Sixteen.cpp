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