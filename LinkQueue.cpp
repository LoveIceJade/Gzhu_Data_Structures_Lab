#include"LinkQueue.h"

//���һ�������λ����
int GetRand()
{
	return(rand() % 900 + 100);
}

//��ʼ����ͷ����������
void InitQueue(LinkQueue*& Q)
{
	Q = new LinkQueue;
	Q->front = Q->rear = nullptr;
	cout << "���ӳ�ʼ���ɹ�" << endl;
}

//�������п�
bool QueueEmpty(LinkQueue* Q)
{
	if (Q->rear == nullptr)
	{
		cout << "����Ϊ��" << endl;
		return true;
	}
	cout << "���ӷǿ�" << endl;
	return(false);
}

//���
int EnQueue(LinkQueue*& Q, DataType &item)
{
	QNode* p = new QNode;  //�����½��
	p->data = item;
	p->next = nullptr;
	if (Q->rear == nullptr)  //������Ϊ�գ����½������׽������β���
		Q->front = Q->rear = p;
	else
	{
		Q->rear->next = p;
		Q->rear = p;
	}
	cout << "����  " << item << "  �Ѿ���ӳɹ�" << endl;
	return 1;
}

//����
int DeQueue(LinkQueue*& Q, DataType& item)
{
	if (Q->rear == nullptr)
	{
		// ����ʱ��ȡ��ע��
		// cout << "����Ϊ�գ�����ʧ��" << endl;
		return 0;
	}
	QNode* t = Q->front;
	if (Q->front == Q->rear)
		Q->front = Q->rear = nullptr;
	else
		Q->front = Q->front->next;
	item = t->data;
	delete t;
	cout << "���ӳɹ����ѳ��ӵ�����Ϊ" << item << endl;
	return 1;
}


//��������
int TraverseQueue(LinkQueue* Q)
{
	QNode* p = Q->front;
	if (p == nullptr)
	{
		cout << "�ö���Ϊ��" << endl;
		return 0;
	}
	int i = 1;
	while (p!=nullptr)
	{
		cout << "���еĵ�" << i << "������Ϊ" << p->data << endl;
		p = p->next;
		i++;
	}
	cout << "�ö����ѱ������" << endl;
	return 1;
}

//��ת����
void RervseQueue(LinkQueue*& Q)
{
	if (Q->front == nullptr || Q->front->next == nullptr)
	{
		cout << "�ö���Ϊ�ջ�ֻ��һ��Ԫ�أ����跭ת" << endl;
		return;
	}

	QNode* prev = nullptr;
	QNode* current = Q->front;
	QNode* next = nullptr;

	// �����ת�ڵ��ָ��
	while (current != nullptr) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	// ���� front �� rear
	Q->rear = Q->front;
	Q->front = prev;

	cout << "���з�ת��ɣ�" << endl;
}