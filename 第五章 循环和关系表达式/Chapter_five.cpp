#include<iostream>
#include<string>
#include<cstring>
#include<ctime>
using namespace std;
int main()
{
	int x;
	cout << (x = 100) << endl;
	cout << x << endl;
	cout << (x < 3) << endl;
	cout << (x > 3) << endl;
	cout.setf(ios_base::boolalpha);
	cout << (x < 3) << endl;
	cout << (x > 3) << endl;

	//����iֻ������for�����,�������뿪ѭ����,���ֱ�������ʧ
	for (int i = 0; i < 3; i++)
		cout << "I love you" << endl;
	//cout << i << endl;

	//forѭ�������ַ���
	string word;
	word = "word";
	for (int i = word.size() - 1; i >= 0; i--)
		cout << word[i];
	cout << endl;

	//˳���:�κ������ı��ʽ����һ��˳���
	cout << (4 + x++) + (6 + x++) << endl;
	//x������ִ����x+4�ͼ�һ��,�����������ʽ��ɲŵ���

	//ǰ׺��ʽ���׺��ʽ
	//C++������ඨ��������Щ�����,�����������,�û���������ǰ׺����:��ֵ��1,Ȼ�󷵻ؽ��
	//����׺�汾���ȸ���һ������,�����1,Ȼ�󽫸��Ƶİ汾����.���,�������,ǰ׺�汾��Ч�ʱȺ�׺�汾��
	//������������,�������ָ�ʽ�������в��;�������û����������,������û�����ĵ�����ݼ������,ǰ׺Ч�ʸ�

	//ǰ׺�������ݼ��ͽ��������������ȼ���ͬ,���ҵ�����
	//��׺�������ݼ����ȼ���ͬ,����ǰ׺���ȼ���,�����ҽ��
	int* pt = &x;
	++* pt;	//��ȡ��ptָ���ֵ,Ȼ�����1
	*++pt;	//�Ƚ�++Ӧ����pt,Ȼ��*Ӧ���ڱ�������pt
	*pt++;	//++����pt,��ָ�����.Ȼ����׺�������ζ�Ž�ԭ���ĵ�ַ�����ǵ�������µ�ַ�������,
			//���ִ�����ptָ���һ����ַ

	x = 17, 240;//,����������ȼ�����͵�
	cout << x << endl;
	x = (17, 240);//,�����������˳���������,��������ұ߲���
	cout << x << endl;

	word == "mate";	//�ⲻ���ж������ַ����Ƿ���ͬ,���ǲ鿴���ǵ��Ƿ�洢����ͬλ����,���Ƿ񶨵�

	//�����ַ�����ʹ�洢�ڳ��Ȳ�ͬ��������,Ҳ������ͬ
	char big[10] = "Daffy";
	char little[6] = "Daffy";

	//strcmp(&string,&string);
	//ͷ�ļ�cstring
	//�������ַ�����ַ��Ϊ����,������ָ�롢�ַ����������ַ�������
	//���ַ�����ͬ,������
	//��һ���ַ�������ĸ˳�����ڵڶ���֮ǰ,���ظ�ֵ;��֮������ֵ
	char worrd[5] = "?ate";
	for (char ch = 'a'; strcmp(worrd, "mate"); ch++) {
		cout << worrd << endl;
		worrd[0] = ch;
	}
	cout << "result:" << worrd << endl << endl;

	//�Ƚ�string���ַ���
	//������ܹ�ʹ�ù�ϵ��������бȽ�
	//�ຯ������(���¶���)����Щ�����
	string word1 = "?ate";
	for (char ch = 'a'; word1 != "mate"; ch++) {
		cout << word1 << endl;
		word1[0] = ch;
	}
	cout << "result:" << word1 << endl;

	//Ҫ��ӡASXII��,Ҫ��ǿ������ת��
	cout << static_cast<int>(word1[0]) << endl;
	//string����ʹ�ÿ��ַ�������ַ�����β

	//����clock()
	//���س���ʼִ�к����õ�ϵͳʱ��
	//����: 1.����ʱ��ĵ�λ��һ������	2.����������ĳЩϵͳ�Ͽ�����long,����һЩϵͳ�Ͽ�����unsigned long���ʺ�ϵͳ����������
	//ͷ�ļ�ctime�ṩ�˽������
	//��������һ�����ų�������CLOCKS_PER_SEC,�ó�������ÿ���Ӱ�����ϵͳʱ�䵥λ��,ϵͳʱ��������ֵ��������
	//���,ctime��clock_t��Ϊclock()�������͵ı���
	//����ζ�ſ��Խ���������Ϊclock_t����,������������ת��Ϊlong,unsigned int���ʺ�ϵͳ����������

	//��clock()������ʾѭ��
	cout << "Enter de delay time,in second: ";
	float secs;
	//cin >> secs;
	secs = 0;
	clock_t delay = secs * CLOCKS_PER_SEC;	//convert to clock ticks
	cout << "starting\a\n";
	clock_t start = clock();
	while (clock() - start < delay)				//wait until time elapses
		//cout << clock()/ CLOCKS_PER_SEC << endl;
		;//note the semicolon
	cout << "done \a\n";
	//�ó�����ϵͳʱ�䵥λΪ��λ������ʱʱ��,������ÿ��ѭ���н�ϵͳʱ��ת��Ϊ��

	//���ͱ���
	//����һ:
		//ʹ��Ԥ������: #define BYTE char
		//Ԥ���������ڱ������ʱ��char�滻���е�BYTE,�Ӷ�ʹBYTE��Ϊchar�ı���
	//������:
		//ʹ�ùؼ���typedef����������
		//typedef char byte;
		//typedef char* byte_point;

	//ʹ��#define����һϵ��ָ�����ʱ,�Ͳ�����
	//#define FLOAT_POINT float*;
	//FLOAT_POINT pa,pb;
	//Ԥ�������û���������ת��Ϊ:
	//float* pa,pb;		//pb����ָ��
	//typedef�Ͳ����������������

	//���ڷ�Χ��forѭ��
	//������(��������,��vector��array)��ÿ��Ԫ��ִ����ͬ�Ĳ���
	double prices[5] = { 1.2,1.3,1.4,1.5,1.6 };
	for (double x : prices)
		cout << x << '\t';
	cout << endl;
	//x�����ʾ����prices�ĵ�һ��Ԫ��,��ʾ��һ��Ԫ�غ�,����ִ��ѭ��,��x�Դ˱�ʾ���������Ԫ��

	//Ҫ�޸������Ԫ��,��Ҫʹ�ò�ͬ��ѭ�������﷨
	for (double& x : prices)
		x *= 0.80;
	//����&����x��һ�����ñ���,���������ý������Ĵ����ܹ��޸����������
	for (double x : prices)
		cout << x << '\t';
	cout << endl;

	//���ɽ��ʹ�û��ڷ�Χ��forѭ���ͳ�ʼ���б�
	for (int x : {3, 4, 5, 6, 7})
		cout << x << " ";
	cout << '\n';

	//cin����֧��3�ֲ�ͬģʽ�ĵ��ַ�����
	//1.ʹ��ԭʼ��cin��������

	/*
	char ys;
	int count = 0;
	cout << "Enter the character; enter # to quit:\n";
	cin >> ys;
	while (ys != '#'){	//�ڱ��ַ�,��Ϊֹͣ���
		cout << ys;		//���¼����ϵļ������Զ����ַ���ʾ����Ļ��,�������ͨ�����������ַ�����������,�ɲ���ϵͳ����
		count++;		
		cin >> ys;		//����:see ken run#really fast
	}
	cout << endl << count << " characters read\n";	//���:seekenrun	
													//9 characters read
	*/

	//cin��ȡcharֵʱ,���ȡ��������һ��,���Կո�ͻ��з�,��˿ո�û�б�����,Ҳû�б������ڼ�����
	//���͸�cin�ĳ��뱻����,ֻ�а��»س�����,��������ݲŻᱻ���͸�����,����������#�ַ��󽫽���������Ĵ���

	//2.ʹ��cin.get(char)���в���
	//ͨ������ַ�ȡ����ĳ�����Ҫ���ÿ���ַ�,�����ո��Ʊ���ͻ��з�

	/*
	char ys;
	int count = 0;
	cout << "Enter the character; enter # to quit:\n";
	cin.get(ys);
	while (ys != '#') {	
		cout << ys;		
		count++;
		cin.get(ys);		//����:see key run#really fast
	}
	cout << endl << count << " characters read\n";	//���:see key run	
													//11 characters read
													*/

	//c������,��Ҫ�޸ı�����ֵ,���뽫�����ĵ�ַ���ݸ�����
	//������ĳ���cin.get()���ݵ���ch������&ch
	//C++��,ֻҪ��������������Ϊ�������ͼ���
	//ͷ�ļ�iostream��cin.get(ch)�Ĳ�������Ϊ��������

	//�������ص�OOP����
	//�����������������ͬ������,���������ǵĲ������Ͳ�ͬ
	//cin.get(char);		cin.get(char*,int);		ch = cin.get();

	//�ļ�β����
	//��������������ļ������ʹ��һ�ֹ��ܸ�ǿ��ļ�����������ļ�β(EOF)
	//C++���빤�ߺͲ���ϵͳЭͬ����,������ļ�β����������Ϣ��֪����
	//�ܶ����ϵͳ(Unix,Linux,Windows������ʾ��ģʽ)��֧���ض���,�������ļ��滻��������
	//��Windows���и�gofish.exe�Ŀ�ִ�г����fishtale���ı��ļ�,�����������ʾ��ģʽ������
	//gofish < fishtale
	//���򽫴�fishtale��ȡ����
	// < ����ʱUnix��Windows������ʾ��ģʽ���ض��������

	//�ܶ����ϵͳ������ͨ��������ģ���ļ�β����
	//Unix��,���������װ���Ctrl+D��ʵ��;Windows������ʾ����,����������λ�ð���Ctrl+Z��Enter

	//��⵽EOF��,cin����λ(eofbit��failbit)������Ϊ1
	//����ͨ����Ա����eof()���鿴eofbit�Ƿ�����
	//�����⵽EOF,��cin.eof()������boolֵtrue,���򷵻�false
	//ͬ��,eofbit��failbit������Ϊ1,��fail()��Ա��������true,���򷵻�false
	//eof()��fail()�������������ȡ�Ľ��
	//Ҳ����˵������ʱ�򱨸�,������Ԥ�ȱ���
	//���Ӧ��cin.eof()��cin.fail()���Է��ڶ�ȡ��
	/*
	int count = 0;
	char ch;
	cin.get(ch);
	while (cin.fail() == false)	// while(!cin.fail())
	{
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << " characters read\n";
	*/

	//cin.clear()�����������EOF���,ʹ�������

	//����cin.get(char)�ķ���ֵ��һ��cin����
	//Ȼ��,istream���ṩ��һ�����Խ�istream����(��cin)ת��Ϊboolֵ�ĺ���
	//��cin��������Ҫboolֵ�ĵط�(����whileѭ���Ĳ���������)ʱ,��ת��������������
	//������һ�ζ�ȡ�ɹ�,��ת���õ���boolֵΪtrue,����Ϊfalse
	//���Ը�д��
	//while(cin)	//while input is successful
	//���!cin.fail��!cin.eof()��ͨ��,��Ϊ�����Լ�⵽����ʧ�ܵ�ԭ��,����̹���
	//���,����cin.get(char)�ķ���ֵΪcin,��˿��Խ�ѭ�������:
	/*
		while(cin.get(ch))
		{
			...
		}
	*/
	//����,cin.get(char)ֻ��������һ��
	/*
	char ch;
	int count = 0;
	while (cin.get(ch))	// while(!cin.fail())
	{
		cout << ch;
		++count;
	}
	cout << endl << count << " characters read\n";
	*/

	//ch = cin.get();���ַ�������Ϊintֵ����
	//cin.get(ch);����һ������,�����Ƕ�ȡ�ַ�

	//put()������ԭ��:put(char),put(signed char),put(unsigned char)
	//��put()����һ��int���������´�����Ϣ,��Ϊת��int�ķ�����ֹһ��
	//cout.put(char(ch))

	return 0;
}