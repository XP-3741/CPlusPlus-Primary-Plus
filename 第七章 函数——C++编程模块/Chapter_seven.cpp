#include<iostream>
#include<string>
#include<array>
using namespace std;

int sum(int ar2[][4], int size);

int main() 
{
	//��C++�У�����Ϊ������������ʹ�ùؼ���void�ǵ�Ч�ġ��� ζ�ź���û�вΔ�����ANSIC�У�
	//����Ϊ����ζ�Ų�ָ���������� ����ζ�Ž��ں��涨������б���C++�У���ָ�������б�ʱӦʹ��ʡ�Ժţ�
	//void slh(...);

	//������һ�ָ������ṩ������Ϣ�ķ���,��ָ��Ԫ�����䣨range),�����ͨ��������ָ�������
	//һ��ָ���ʶ����Ŀ�ͷ����һ��ָ���ʶ�����β��
	//double elbuod[20]�� 
	//ָ����elboud��elboud + 20 ���������䡣���ȣ�������elbmib ָ���һ��Ԫ�ء����ʽelboud+19 
	//�����һ��Ԫ�أ�elboud[19])

	//C + +��ֹ��const�ĵ�ַ������constָ��
	// constָ�븳��constָ���ǿ��Ե�

	//��ָ���������Ϊָ�������ݵ�ָ������������:
	//�������Ա�������������޸����ݶ����µı�̴���
	//ʹ��constʹ�����ܹ�����const�ͷ�constʵ��,����ֻ�ܽ��ܷ�const����
	//�����������,��Ӧ��ָ���β�����Ϊָ��const��ָ��
	
	//Ϊ˵����һ��΢��֮����
	int age = 39;
	const int *pt = &age;
	//�ڶ��������е�constֻ�ܷ�ֹ�޸�pt��ָ���ֵ(39),�����ܷ�ֹ�޸�pt��ֵ
	//Ҳ����˵,���Խ�һ���µĵ�ַ����pt��
	int sage = 80;
	pt = &sage;
	//����Ȼ����ʹ��pt���޸���ָ���ֵ(80)

	//�ڶ���ʹ��const�ķ�ʽʹ�޷��޸�ָ���ֵ
	int sloth = 3;
	const int* ps = &sloth;		//a pointer to const int
	int* const finger = &sloth;	//a const pointer tp int
	//����������ʽʹ��fingerֻ��ָ��sloth, ����ʹ��finger���޸�sloth��ֵ��
	//�м������������ʹ��ps���޸�sloth��ֵ,������psָ����һ��λ��
	//�����֮,finger��*ps����const, ��*finger��ps����

	//���Ը�⻹��������ָ��const�����constָ�룺
	double trouble = 2.0E30;
	const double* const stick = &trouble;
	//stickֻ��ָ��trouble,��stick�����Á��޸�trouble��ֵ
	//stick��*stick����const

	//��ָ����Ϊ��������������ʱ,����ʹ��ָ��const��ָ�����������ݡ�
	void showarray(const double ar[], int n);

	//Ϊ��д����ά������Ϊ�����ĺ����������μǣ�����������Ϊ���ַ����ˣ���Ӧ���β���һ��ָ�룬
	//��һά����һ��,�Ƚ��Ѵ�����������ȷ������ָ�롣
	//����,����������Ĵ��룺
	int data[3][4] = { {1,2,3,4},{5,6,7,8},{2,4,6,8} };
	int total = sum(data, 3);
	//Data��һ������������������3��Ԫ�ء���һ��Ԫ�ر�����һ�����飬��4��intֵ���
	//sum��ԭ������
	int sum(int(*ar2)[4], int size);
	//�е������Ǳز����ٵ�,��Ϊ���������������һ����4��ָ��int��ָ����ɵ�����,��������
	//һ��ָ����4��int��ɵ������ָ�룺���⣬������������������:
	int* ar2[4];
	//��������һ�ָ�ʽ�����ָ�ʽ������ԭ�͵ĺ�������ͬ,���ɶ��Ը�ǿ
	int sum(int ar2[][4], int size);

	//���Խ�һ���ṹ��ֵ������һ���ṹ,ͬ��,Ҳ���԰�ֵ���ݽṹ,������ͨ��������
	//�����������,������ʹ��ԭʼ�ṹ�ĸ���
	//����,����Ҳ���Է��ؽṹ
	//����������������ĵ�һ��Ԫ�صĵ�ַ��ͬ����,�ṹ��ֻ�ǽṹ������,Ҫ��ýṹ�ĵ�ַ,����ʹ�õ�ַ�����&

	//���ṹ�Ƚ�Сʱ,��ֵת�ݽṹ�����
	struct travel_time
	{
		int hour;
		int minute;
	};
	//��������Ϊtravel_time,��������ҲΪ��������
	travel_time sum(travel_time t1, travel_time t2);
	/*{
		travel_time total;

		total.minute = (t1.minute + t2.minute) % Mins_pre_hr;
		total.hour = t1.hour + t2.hour + (t1.minute + t2.minute) / Mins_per_hr;
		return total;
	}*/

	//��ֱ������ϵת���ɼ�����ϵ
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
	//��ѧ���е�atan2()�������Ը���x��y��ֵ����Ƕ�
	//angle = atan2(y,x);
	//����һ��atan()����,������������180��֮�ں�֮��ĽǶ�
	polar rect_to_polar(rect xypos);
	/*{
		polar answer;
		answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
		answer.angle = atan2(xypos.y, xypos.x);
		return answer;
	}*/

	//while(cin >> rplace.x >> rpalce.y);
	//cin��istream���һ������
	//���������( >> )����Ƴ�ʹ��cin>>rplace.xҲ��һ��istream����
	//���������ʹ�ú���ʵ�ֵ�
	//ʹ��cin>>rplace.xʱ,���򽫵���һ������,�ú�������һ��istreamֵ
	//���,whileѭ���Ĳ��Ա�ʽ�����ս��Ϊcin
	//��cin�����ڲ��Ա��ʽʱ,�����������Ƿ�ɹ�,��ת����boolֵ

	//���ݽṹ�ĵ�ַ�����������ṹ�Խ�ʡʱ��Ϳռ�
	//��ӳ�Ա�����( -> )							
	void rect_to_polar(const rect* xypos, polar* pda);
	/*{
		pda->distance = sqrt(xypos->x * xypos->x + xypos->y * xypos->y);
		pda->angle = atan2(xypos->y, xypos->x);
	}*/
	//����rect_to_polar�����Ĳ������ǰ��ʹ�õ��ǽṹ����,����ʹ�õ�ʱָ��,�ú����ܹ���ԭʼ�ṹ���в���

	//ģ����array
	//����Ҫʹ��һ��array����洢һ���ĸ����ȵĿ�֧
	std::array<double, 4> expenses = { 1,2,3,4 };
	std::array < double, 4 >* pa = &expenses;
	cout << (*pa)[2] << endl;
	//ͷ�ļ�<array>,���ƿռ�std
	//�����������ʾexpenses������,�ɰ�ֵ����expenses
	//show(expenses);
	//�������Ҫ�޸Ķ���expenses,���轫�ö���ĵ�ַ���ݸ�����
	//fill(&expenses);
	//��������������
	void show(std::array<double, 4> da);
	void fill(std::array<double, 4>* pa);

	//ʹ��һ��const array����,����4��string����,��ʾ�ĸ�����
	const int seasons = 4;
	const std::array<std::string, seasons>Snames =
	{ "Spring","Summer","Fall","Winter" };
	//array����ֻ�ܴ洢������������,�������Դ洢����

	//����ָ��
	//������������,����Ҳ�е�ַ
	//�����ĵ�ַ�Ǵ洢��������Դ�����ڴ�Ŀ�ʼ��ַ
	//��Щ��ַ���û����Բ���ҪҲ����,���Գ���ȴ������
	//����,���Ա�д����һ�������ĵ�ַ��Ϊ�����ĺ���,������һ���������ܹ��ҵ��ڶ���Ԫ��,��������

	//��ȡ�����ĵ�ַ�ܼ�:ֻҪʹ�ú�����(���治������)����
	//���think()��һ������,��think���Ǹú����ĵ�ַ
	//Ҫ��������Ϊ�������д���,���봫�ݺ�����
	//һ��Ҫ���ִ��ݵ��Ǻ����ĵ�ַ���Ǻ����ķ���ֵ
	//process(think);	//passes address of think() to process()
	//thought(think{});	//passes return value of think() to thought()
	//process()����ʹ��process()�����ܹ������ڲ�����think()����
	//thought()�������ȵ���think()����,Ȼ��think()�ķ���ֵ���ݸ�thought()����

	//����ָ��ĳ���������͵�ָ��ʱ,����ָ��ָ��ָ�������
	//ͬ��,����ָ������ָ��ʱ,Ҳ����ָ��ָ��ָ��ĺ�������
	//����ζ������Ӧָ�������ķ��������Լ�������������(�����б�),������������ԭ��
	//�纯��ԭ������
	double pam(int);
	//����ȷ��ָ��������������
	double (*pf)(int);
	//����pam()��������,���ǽ�pam�滻��(*pf)
	//����pam�Ǻ���,���(*pf)Ҳ�Ǻ���,pf���Ǻ���ָ��

	//Ϊ�ṩ��ȷ����������ȼ�,������������ʹ�����Ž�*pf����
	//*pf(int)��ζ��pf()��һ������ָ��ĺ���,��(*pf)(int)��ζ��pf��һ��ָ������ָ��
	
	//��ȷ������,��ɽ���Ӧ�ĺ����ĵ�ַ��ֵ����
	pf = pam;
	//pam()��������ͷ������ͱ�����pf��ͬ
	//ʹ��C++11���Զ������ƶϹ���,����Ҫ�򵥵Ķ�
	auto pf1 = pam;

	//estimate()����Ҫ����Ҫ��д�Ĵ��������͹����㷨ʱ��ĵ�ַ���ݸ���
	void estimate(int lines, double(*pf)(int));
	//Ҫ����ʹ��pam()����,��Ҫ��pam()�ĵ�ַ���ݸ���
	estimate(50, pam);

	//ʹ��ָ�������ú���
	double x = (*pf)(5);

	const double* f1(const double ar[], int n);
	const double* f2(const double[], int);
	const double* f3(const double*, int);
	//������ʵ������ͬ
	//����ԭ����,�����б�const double ar []��const double *ar�ĺ�����ȫ��ͬ
	//���,�ں���ԭ����,����ʡ�Ա�ʶ��,���,const double ar[]�ɻ���Ϊcont doule []
	//��const double * ar�ɻ���Ϊconst double *

	//����ָ������,��ʹ��forѭ��ͨ��ָ�����ε���ÿ������
	const double* (*pk[3])(const double*, int) = { f1,f2,f3 };
	//Ϊ��[3]������?
	//pa��һ����������Ԫ�ص�����.����������������,������Ҫʹ��pa[3]
	//����������������ָ�������������Ԫ����ʲô����
	//�����[]�����ȼ�����*,���*pa[3]����pa��һ����������ָ�������
	//������������������ָ����ÿ��ָ��ָ��ʲô:������Ϊconst double *,int,�ҷ�������Ϊconst double *�ĺ���
	//���,pa��һ����������ָ�������,����ÿ��ָ�붼ָ�������ĺ���
	//���ﲻ��ʹ��auto
	//�Զ������ƶ�ֻ��ʹ���ڵ�ֵ��ʼ��,���������ڳ�ʼ���б�
	//����������pk��,����ͬ�����͵�����ͺܼ���
	auto pkk = pk;

	//��������ָ���һ��Ԫ�ص�ָ��,���pa��pb����ָ����ָ���ָ��
	//����: pa[i]��pb[i]����ʾ�����е�ָ��,��˿ɽ��κ�һ�ֺ������÷�����������
	const double av[3] = { 2,3,4 };
	const double* px = pk[0](av, 3);
	const double* py = (*pkk[1])(av, 3);
	//Ҫ���ָ��double��ֵ,����ʹ�������*
	double x1 = *pk[0](av, 3);
	double y = *(*pkk[1])(av,3);

	// **&pk == *pk == pk[0		//���ò�һ��Ҫ����,��ȱҲ�������κ�Ӱ��,0�������޵�����


	//Ĭ��ֵ(ȱʡֵ)
	//���οɴ�������
	int f(int a = 1, int b = 2, int c = 3);
	//����
	f(3);//a=3,b=2,c=3
	f(3, 4);//a=3,b=4,c=3
	f();//a=1,v=2,c=3
	//��Ϊ��������,���Զ��岻�ܣ�
	//int f(int a = 3, int b,int c=1);

	//���ַ����ж�ȡ����: "x=12,y=3"


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