#include<iostream>
#include<climits>
#include<cctype>
#include <fstream>	//for file I/O
#include<cstdlib>	//exit
using namespace std;

bool is_int(double x);
int main()
{
	//�������
	/*
	char ch;
	cin.get(ch);
	while (ch != '.') {
		if (ch == '\n')
			cout << ch;
		else
			cout << ++ch;//����ĳ�ch+1������һ������
		cin.get(ch);
	} 
	*/

	//C++�߼�OR���߼�AND��������ȼ������ڹ�ϵ�����
	//!��������ȼ��������й�ϵ����������������
	//�߼�AND��������ȼ������߼�OR�����
	//C++ȷ������������ҽ��м����߼����ʽ,����֪���𰸺�����ֹͣ

	//������ʾ����
	//	&&		=		and
	//  ||		=		or
	//  !		=		not
	//C������ͷ�ļ�ios646.h
	//C++��Ҫ��ʹ��ͷ�ļ�

	//�ַ�������cctype
	//C++�̳���C����������������,�����Լ�����ȷ���ַ��Ƿ�Ϊ��д��ĸ,����,�����ŵȹ���
	//ͷ�ļ�	cctype
	//��������Ϊint
	//isalnum()					�����������ĸ����,����ĸ����,�ú�������true
	//isalpha()					�����������ĸ,�ú�������true
	//iscntrl()					��������ǿ����ַ�,�ú�������true
	//isdigit()					�������������(0~9),�ú�������true
	//isgraph()					��������ǳ��ո�֮��Ĵ�ӡ�ַ�,�ú�������true
	//islower()					���������Сд��ĸ,�ú�������true
	//isprint()					��������Ǵ�ӡ�ַ�(�����ո�),�ú�������true
	//ispunct()					��������Ǳ�����,�ú�������true
	//isspace()					��������Ǳ�׼�հ��ַ�,��ո�,��ֽ,���з�,�س�,ˮƽ�Ʊ�����ߴ�ֱ�Ʊ��,�ú�������true
	//isupper()					��������Ǵ�д��ĸ,�ú�������true
	//isxdigit()				���������ʮ����������,��0~9,a~f��A~F,�ú�������true
	//tolower()					��������Ǵ�д�ַ�,�򷵻���Сд,���򷵻ظò���
	//toupper()					���������Сд�ַ�,�򷵻����д,���򷵻ظò���

	//?:�����
	//int c = a > b ? a : b;
	//�ȼ���
	//int c;	if(a>b)	c=a;else  c=b;


	//goto���
	/*
	char ch = 'p';
	if(ch == 'p')		goto paris;	//��ת��pris
	cout << "..." ;
	paris:cout<<"sb";
	*/
	/*
	const int MAX = 5;
	double fish[MAX];
	int i = 0;
	while (i<MAX && cin >> fish[i])//cin >> fish[i]ʵ������һ��cin������������,�ú�������cin�����cinλ�ڲ���������,����ת��bool��,����ɹ�Ϊtrue
		if (++i < MAX)			   //���i=MAX,��ѭ�����Ի����,�����Ὣһ��ֵ���뵽������
			cout << "fish #" << i + 1 << ": ";
	cout << endl << "DATA:";
	for (int j = 0; j < i; j++)
		cout << fish[j] << " ";
	*/
	/*
	const int MAX = 5;
	int golf[MAX];
	for (int i = 0; i < MAX; i++) {
		cout << "round #" << i + 1 << ": ";
		while (!(cin >> golf[i])) {		//�����벻������ʱ,����ж�Ϊtrue,����ѭ��

			cout << "state:" << cin.rdstate() << endl;
			//  0 ��goodbit �޴���
			//	1 ��Eofbit �ѵ����ļ�β
			//	2��failbit ������������ / ������󣬿����
			//	3��badbit������������ / �������, �޷����

			cin.clear();				//��������ʾ��

			cout << "state:" << cin.rdstate() << endl;//�ٴβ鿴����״̬ ��Ӧ0 �޴���

			while (cin.get() != '\n')	//��ȡ��β֮ǰ����������,�Ӷ�ɾ����һ���еĴ�������
				continue;

			//cin.sync();//������������
			cout << "Please enter a number: ";
		}
	}*/

	//C++ʹ�ý���ȡ�������������Ļ����ʾ(ͳ�ƿ���̨����/���)�ļ��������ļ�����/���(�ļ�I/O)�ǳ���
	//ʹ��cin��������ʱ,����������Ϊһϵ���ֽ�,����ÿ���ֽڶ�������Ϊ�ַ�����
	//����Ŀ������������ʲô,����һ��ʼ�����ַ����ݡ����ı�����
	//Ȼ��cin�������ı�ת������������
	//����������ʵ��������:	
	//38.5 19.2

	//����ʹ��char�������͵����:
	//char ch;
	//cin >> ch;
	//�������еĵ�һ���ַ�������ch,��3,���ַ�����(������)�������ڱ���ch��
	//�����Ŀ����������ַ�,��˲���Ҫ����ת��
	//ע��,����洢����ֵ����3,�����ַ�3�ı���
	//ִ��������������,��������е���һ���ַ�Ϊ�ַ�8,��һ�����������������д���

	//����������int���ͣ�
	//int n;
	//cin >> n;
	//����������� cin�����϶�ȡ,ֱ���������������ַ�
	//Ҳ����˵������ȡ3��8,������㽫��Ϊ��������е���һ���ַ�
	//cinͨ�����㷢���������ַ���Ӧ��ֵ38 ,��˽�38�Ķ����Ʊ��븴�Ƶ�����n��

	//����������double���ͣ�
	//double x;
	//cin >> x;
	//����������� cin�����϶�ȡ,ֱ��������һ�������ڸ��������ַ�
	//Ҳ����˵������ȡ3��8�;���5,ʹ�ÿո��Ϊ��������е���һ���ַ�
	//cinͨ�����㷢�� ���ĸ��ַ���Ӧ����ֵ38.5,��˽�38.5�Ķ����Ʊ��루�����ʽ�����Ƶ�����x��
	
	//����������char����:
	//char word[50];
	//cin >> word;
	//����������� cin�����϶�ȡ,ֱ�������հ��ַ�
	//Ҳ����˵������ȡ3��8����� 5,ʹ�ո��Ϊ��������е���һ���ַ�
	//Ȼ��,cin����4���ַ����ַ�����洢������word��,����ĩβ����һ�����ַ�.���ﲻҪ�����κ�ת��
	
	//��һ��ʹ��char�����洢��������:
	//char word[50];
	//cin.getline(word,50);
	//����������cin�����϶�ȡ,ֱ���������з���ʾ����������50���ַ���
	//�����ַ��������洢����word��,����ĩβ����һ�����ַ�
	//���з�����������������е���һ���ַ�����һ���еĵ�һ���ַ������ﲻ��Ҫ�����κ�ת��
	
	//�����Ҫ���ǣ�����һ��ʼΪ�ı�����ˣ�����̨������ļ���ľ���ı��ļ��� ÿ���ֽڶ��洢
	//һ���ַ�������ļ����������е��ļ������ı��ļ������磬���ݿ�͵��ӱ������ֵ��ʽ������������
	//���򸡵��ʽ�����洢��ֵ���ݡ����⣬�ִ����ļ��п��ܰ����ı���Ϣ ��Ҳ���ܰ�������������ʽ��
	//���塢��ӡ���ȵķ��ı����ݡ�

	//�����ļ����룬C++ʹ������cout�Ķ���
	//ͷ�ļ�iostream������һ����Ϊcout��ostream����(����

	//�ļ������˼�������
	//�������ͷ�ļ�fstream
	//ͷ�ļ�fstream������һ�����ڴ��������ofstream��
	//��Ҫ����һ������ofstream���������󣩣������Լ�ϲ���ķ�ʽ����������������������س��õ���������
	//����ָ�����ƿռ�std;���磬Ϊ����Ԫ��ofstream,����ʹ�ñ���ָ��using��ǰ׺std::
	//��Ҫ��ofstream�������ļ�����������Ϊ�ˣ�����֮һ��ʹ��open()����
	//ʹ�����ļ���Ӧʹ�÷���close()����ر�
	//�ɽ��ʹ��ofstream����������<<������������͵�����
	//ע��,��Ȼͷ�ļ�iostream�ṩ��һ��Ԥ�ȶ���õ���Ϊcout��ostream���󣬵������������Լ���ofstream����,Ϊ������,������ͬ�ļ���������
	//ͷ�ļ�<fstream>
	ofstream outFile;	//outFile an ofstream object
	ofstream fout;		//fout an ofstream object
	//������ʾ����ν����ֶ������ض����ļ���������
	outFile.open("DJ.txt");	//outFile used to write to the fish,txt file
	outFile.close();
	//char filename(50);			
	//cin >> filename;			//user specifies a name
	//fout.open(filename);		//fout used to read specified file
	double year = 520;
	outFile << year;
	char line[99] = "I love you";
	fout << line << endl;
	//��Ҫ���ǣ�����һ��ofstream���󲢽���ͬ�ļ����������,�������ʹ��cout����ʹ����.���п�
	//����cout�Ĳ����ͷ������� <<��endl��setf())��������ofstream������ǰ��ʾ���е�outFile��fout)

	//��֮��ʹ���ļ��������Ҫ��������
	//����ͷ�ļ�fstream
	//����һ��ofstream����
	//����ofstream����ͬһ���ļ���������
	//��ʹ��cout����ʹ�ø�ofstream����
	//ʹ����close(),����ö����޷����������ļ�
	ofstream DJ;
	DJ.open("DJDJ.txt");
	DJ << fixed;
	DJ.precision(2);	//�趨����������Ϊ��λ
	DJ.setf(ios_base::showpoint);	//����������������С��������0
	DJ << "DJ.I love you for thousand times." << endl;
	DJ << year << endl;
	DJ << static_cast<int>(year);
	DJ.close();

	//����ļ��Ƿ񱻳ɹ��򿪵����ȷ�����ʹ�÷���is_open()
	ifstream inFile;
	inFile.open("DJ.txt");
	if (!inFile.is_open()) {
		exit(EXIT_FAILURE);	//����exit()��ԭ������ͷ�ļ�cstdlib�ж����
							//�ڸ�ͷ�ļ��У���������һ������ͬ����ϵͳͨ�ŵĲ���ֵEXIT_FAILURE������exit()��ֹ����
	}
	int count = 0;
	double value;
	double sum = 0.0;   
	inFile >> value;
	while (inFile.good()) {//����good()ָ�����һ�ζ�ȡ����Ĳ����Ƿ�ɹ�
		++count;		//one more item read
		sum += value;	//calculate running total
		inFile >> value;//get next value
	}
	cout << "sum=" << sum << endl << "count=" << count << endl;
	inFile.close();



	system("pause");
	return 0;
}

bool is_int(double x)	//����ȡintֵ�ĳ�������һ�������ֵ,�ܶ�C++ʵ��ֻ�ǽ����ֵ�ض�Ϊ���ʵĴ�С,������֪ͨ��ʧ����.Ҳ��long long
{
	if (x <= INT_MAX && x >= INT_MIN)
		return true;
	else
		return false;
}