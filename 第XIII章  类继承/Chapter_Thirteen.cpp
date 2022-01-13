#include<iostream>
#include<string>
#include"brass.h"
const int CLIENTS = 4;

int main()
{
	// P488��

	using std::cin;
	using std::cout;
	using std::endl;

	// ������ͻ���֮��������ϵ
	//	- ����֮һ��������������ʹ�û���ķ���,�����Ƿ�������˽�е�
	//	- ����ָ������ڲ�������ʽ����ת���������ָ�����������
	//	- �������ÿ����ڲ�������ʽ����ת����������������������
	//		Ȼ��,����ָ�������ֻ�����ڵ��û��෽��
	//		ͨ��,C++Ҫ�����ú�ָ�������븳��������ƥ��,����һ����Լ̳���˵������
	//		Ȼ��,��������ֻ�ǵ����,�����Խ��������͵�ַ�������������ú�ָ��
	//		����������ú�ָ�����ָ�����������,������һЩ����Ȥ�Ľ��
	//		��֮һ�ǻ������ö���ĺ�����ָ����������ڻ����������������
	//	���ü���������Ҳ�ܹ�����������ʼ��Ϊ���������
	//		RatedPlayer olaf1(1840,"Olaf","Loaf",true);
	//		TableTennisPlayer olaf2(olaf1);
	//		Ҫ��ʼ��olaf2,ƥ��Ĺ��캯��ԭ������:
	//		TableTennisPlayer(const RatedPlayer &);
	//		����û�������Ĺ��캯��,��������ʽ���ƹ��캯��:
	//		TableTennisPlayer(const TableTennisPlayer &);
	//	ͬ��,Ҳ���Խ����������ֵ���������:
	//		RatedPlayer olaf1(1840,"Olaf","Loaf",true);
	//		TableTennisPlayer winner;
	//		winner = olaf1;
	//		�����������,����ʹ����ʽ���ظ�ֵ�����:
	//		TableTennisPlayer & operator=(const TableTennisPlayer &) const;
	
	// �̳�: is-a��ϵ	P490
	//	C++��3�ּ̳з�ʽ:���м̳С������̳к�˽�м̳�
	//	���м̳�������ķ�ʽ,������һ��is-a(is-a-kind-of)��ϵ,�����������Ҳ��һ���������
	//	���ԶԻ������ִ�е��κβ���,Ҳ���Զ����������ִ��
	
	// ��̬���м̳�
	//	RatedPlayer�̳�ʾ���ܼ�,���������ʹ�û���ķ���,��δ���κ��޸�
	//	Ȼ��,���ܻ��������������,��ϣ��ͬһ��������������ͻ����е���Ϊ�ǲ�ͬ��
	//	���仰��˵,��������Ϊȡ���ڵ��ø÷����Ķ���
	//	���ָ��ӵ���Ϊ��Ϊ ��̬---���ж�����̬
	//	��������Ҫ�Ļ��ƿ�����ʵ�ֶ�̬���м̳�:
	//		- �������������¶������ķ���
	//		- ʹ���鷽��
	
	// ��ʾ�鷽������Ϊ
	// �����ʹ��ͬһ������������ Brsss �� BrassPlus ����,�����а���
	// �����ǲ����ܵ�.����������Ԫ�ص����ͱ�����ͬ,�� Brass �� BrassPlus �ǲ�ͬ������
	// Ȼ��,���Դ���ָ�� Brass ��ָ������,����ÿ��Ԫ�ص����Ͷ���ͬ,������ʹ�õ���
	// ���м̳�ģ��,��� Brass ָ�����ָ�� Brass ����,Ҳ����ָ�� BrassPlus ����
	// ���,����ʹ��һ����������ʾ�������͵Ķ���,����Ƕ�̬��
	Brass* p_clients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;
	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "Enter client's name: ";
		getline(cin, temp);
		cout << "Enter client's account number: ";
		cin >> tempnum;
		cout << "Enter opening ba;ance: $";
		cin >> tempbal;
		cout << "Enter 1 for Brass Account or "
			<< "2 for BrassPlus Account: ";

		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "Enter either 1 or 2: ";
		if (kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "Enter the overdraft limit: $";
			cin >> tmax;
			cout << "Enter the interest rate "
				<< "as a decimal fraction: ";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal,
										tmax, trate);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i = 0; i < CLIENTS; i++) {
		p_clients[i]->ViewAcct();
		cout << endl;
	}
	for (int i = 0; i < CLIENTS; i++) {
		delete p_clients[i];
	}
	cout << "Done.\n";

	return 0;
}