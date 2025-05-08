#include <iostream>
#include <ctime>
using namespace std;

//���һ�������λ����
int GetRand();

typedef int DataType;

struct QNode
{ //���ṹ
	DataType	data;
	QNode* next;
};

struct LinkQueue
{ //���нṹ
	QNode* front;
	QNode* rear;
};

//��ʼ����ͷ����������
void InitQueue(LinkQueue*& Q);

//�������п�
bool QueueEmpty(LinkQueue* Q);

//���
int EnQueue(LinkQueue*& Q, DataType &item);

//����
int DeQueue(LinkQueue*& Q, DataType& item);

//��������
int TraverseQueue(LinkQueue* Q);

//��ת����
void RervseQueue(LinkQueue*& Q);