
int main()
{
	// ����ֻ��ӵ����Ԫ����,Ҳ���Խ�����Ϊ��Ԫ����
	// ����,Ҳ���������ϸ������,ֻ���ض��ĳ�Ա����ָ��Ϊ��һ�������Ԫ

	// ��Ԫ��
	//	�������ʹ Remote ��Ϊ��Ԫ��:
	//		friend class Remote;
	//	��Ԫ��������λ�ڹ��С�˽�л򱣻�����,������λ���޹ؽ�Ҫ
	// 
	// ��Ԫ��Ա����
	//	����ѡ�����ض������Ա��Ϊ��һ�������Ԫ,���������������Ϊ��Ԫ
	//  ���� Remote::set_chan()��Ϊ Tv �����Ԫ�ķ�����,�� Tv �������н�������Ϊ��Ԫ:
	//		class Tv
	//		{
	//			friend void Remote::set_chan(Tv & t, int c);
	//			...
	//		}
	//	Ȼ��,Ҫʹ�������ܹ������������,������֪�� Remote �Ķ���
	//	����ζ��Ӧ�� Remote �Ķ���� set_chan() �����������ŵ� Tv �Ķ���ǰ��
	//	Remote �ķ����ᵽ�� Tv ����,������ζ�� Tv ����Ӧ�� λ�� Remote ����֮ǰ
	//	�ܿ�����ѭ�������ķ�����,ʹ�� ǰ������(forward declaration)
	//	Ϊ��,��Ҫ�� Remote �����ǰ�����:
	//		class Tv;		// forward declaration
	//	����,���д�������:
	//		class Tv;		// forward declaration
	//		class Remote { ... };
	//		class Tv { ... };
	//	������������:
	//		class Remote;		// forward declaration
	//		class Tv { ... };
	//		class Remote { ... };
	//	��Ϊ�ڱ������� Tv ����������� Remote ��һ������������Ϊ Tv �����Ԫ֮ǰ
	//	Ӧ���ȿ��� Remote ��������� set_chan() ����������
	//	����һ���鷳,Remote ������������������: void onoff(Tv & t) { t.onoff(); }
	//	�����⽫���� Tv ��һ������,���Ա�������ʱ�����Ѿ������� Tv �������
	//	�����翴����,������λ�� Remote �����ĺ���
	//	��������Ľ��������,ʹ Remote ������ֻ������������
	//	����ʵ�ʵĶ������ Tv ��֮��
	//	�������������������ڲ���,����ζ�ź������������ʹ�ú������ļ���
	//	�� tvfm ��������,��������λ��ͷ�ļ���
	//	�����ʹ�ú������ļ��а���ͷ�ļ���ȷ�����������ȷ�ĵط�
	//	Ҳ���Խ��������ʵ���ļ���,������ɾ���ؼ��� inline ,���������������Խ����ⲿ��
	//	��������� Remote ���Ϊ��Ԫ������Ҫ��ǰ����
	//	��Ϊ��Ԫ��䱾���Ѿ�ָ�� Remote ��һ����
	// 
	// ������Ԫ��ϵ
	//	���߻�Ϊ��Ԫ
	// ��ͬ����Ԫ
	//	��Ҫʹ����Ԫ����һ�������,������Ҫ�����������˽������
	//	���߼��Ͽ�,�����ĺ���Ӧ����ÿ����ĳ�Ա����,�����ǲ����ܵ�
	//	��������һ����ĳ�Ա,ͬʱ����һ�������Ԫ
	//	����ʱ��������Ϊ���������Ԫ������
	//	����,�ٶ���һ�� Probe ���һ�� Analyzer ��
	//	ǰ�߱�ʾĳ�ֿɱ�̵Ĳ����豸,���߱�ʾĳ�ֿɱ�̵ķ����豸
	//	�������඼���ڲ�ʱ��,��ϣ�������ܹ�ͬ��,��Ӧ�ð�������������;
	//	class Analyzer;
	//	class Probe
	//	{
	//		friend void sync(Analyzer & a, const Probe & p);	// sync a to p
	//		friend void sync(Probe & p, const Analyzer & a);	// sync p to a
	//		...
	//	};
	//	class Analyzer
	//	{
	//		friend void sync(Analyzer & a, const Probe & p);	// sync a to p
	//		friend void sync(Probe & p, const Analyzer & a);	// sync p to a
	//		...
	//	};
	//	// define the friend functions
	//	inline void sync(Analyzer & a, const Probe & p)
	//	{
	//		...
	//	}
	//  inline void sync(Probe & p, const Analyzer & a)
	//	{
	//		...
	//	}

	// Ƕ����
	//	���Խ�������������һ������
	//	����һ�����������౻��Ϊ Ƕ����(nested class)
	//	��ͨ���ṩ�µ����������������������ƻ���
	//	�������Ƕ�����������ͬ
	//	������ζ�Ž��������Ϊ��һ����ĳ�Ա,���������Ƕ�ײ��������Ա,���Ƕ�����һ������
	//	�����ͽ��ڰ���Ƕ����������������Ч
	//	�������Ƕ��ͨ����Ϊ�˰���ʵ����һ����,�������Ƴ�ͻ
	//	Queue ��ʾ��:
	//	class Queue
	//	{
	//	private:
	//		struct Node {Item item; struct Node * next;};
	//		...
	//	};
	//	Ψһ���� Node ����ĵط��� enqueue() ����:
	//	bool Queue::enqueue(const Item & item)
	//	{
	//		if(isfull())
	//			return false;
	//		Node* add = new Node;
	//		add->item = item;
	//		add->next = NULL;
	//		...
	//	}
	//	��ʾ�ظ� Node ��Ա��ֵ,���ֹ������ʺ��ɹ��캯�������
	//	class Queue
	//	{
	//		class Node
	//		{
	//		public:
	//			Item item;
	//			Node* next;
	//			Node(const Item & i) :item(i), next(0) {}
	//		};
	//		...
	//	};
	//	���±�д enqueue():
	//	bool Queue::enqueue(const Item & item)
	//	{
	//		if(isfull())
	//			return false;
	//		Node* add = new Node(item);
	//		...
	//	}
	//	��ʹ�ô������Ҹ���ȫ,��Ϊ���Զ����г�ʼ��,�������Ա��סӦ����ʲô
	//	���ڷ����ļ��ж��幹�캯��,�������ָ�� Node ������ Queue ���ж����:
	//	Queue::Node::Node(const Item & i) : item(i), next(0) {}
	//	
	return 0;
}