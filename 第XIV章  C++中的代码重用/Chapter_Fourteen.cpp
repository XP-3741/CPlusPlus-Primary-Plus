#include<valarray>

int main()
{
	// valarray ����
	//	��������ڴ�����ֵ(������������Ե���)
	//	valarray ������Ϊһ��ģ����,�Ա��ܹ�����ͬ����������
	//	ģ����������ζ����������ʱ,����ָ���������������
	//	���,ʹ�� valarray ��������һ������ʱ
	//	���ڱ�ʶ�� valarray �������һ�Լ�����,�������а�������Ҫ����������
	std::valarray<int> q_values;		// an array of int
	std::valarray<double> weights;		// an array of double
	// �����Ǽ���ʹ�ù��캯��������:
	double gpa[5] = { 3.1, 3.5, 3.8, 2.9, 3.3 };
	std::valarray<double> v1;		// an array of double, size 0
	std::valarray<int> v2(8);		// an array of 8 int elements
	std::valarray<int> v3(10, 8);	// an array of 8 int elements
									// each set to 10
	std::valarray<double>v4(gpa, 4);// an array of 4 elements
						// initialized to the first 4 elements of gpa
	// ��C++11��,Ҳ����ʹ�ó�ʼ���б�
	std::valarray<int> v5 = { 20, 32, 17, 9 };	// C++11
	// ������������һЩ����
	//	- operator[]()	���ʸ���Ԫ��
	//	- size()		���ذ�����Ԫ����
	//	- sum()			�������е�Ԫ���ܺ�
	//	- max()			��������Ԫ��
	//	- min()			������С��Ԫ��

	// Student ������
	//	��ȷ�� Student �����Ƽƻ�:
	//		string�����ʾ������valarray<double>��ʾ����
	//	����ѧ����������֮�䲻�� is-a ģ��,���Բ��ʺϽ�ѧ������������������
	//	����Ĺ�ϵ�� has-a ,ѧ����������һ�鿼�Է���
	//	ͨ��,���ڽ��� has-a ��ϵ��C++���������(����),������һ������������������
	
	// �ӿں�ʵ��
	//	ʹ�ù��м̳�ʱ,����Լ̳нӿ�,���ܻ���ʵ��
	//		(����Ĵ��麯���ṩ�ӿ�,�����ṩʵ��)
	//	��ýӿ��� is-a ��ϵ����ɲ���
	//	���������,����Ի��ʵ��,�����ܻ�ýӿ�
	//	���̳нӿ��� has-a ��ϵ����ɲ���
	//
	return 0;
}