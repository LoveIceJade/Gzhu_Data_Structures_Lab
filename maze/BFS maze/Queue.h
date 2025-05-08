#include <iostream>
using namespace std;

const int MaxSize = 100;

extern int mg[10][10];

struct Box
{
	int i, j;  //�����λ��
	int pre;   //��·������һ�������ڶ����е��±�
};

struct QuType 
{
	Box data[MaxSize];
	int front, rear;          // ��ͷָ��Ͷ�βָ��
};


// ��ʼ������
void InitQueue(QuType*& qu);

// ���
bool enQueue(QuType*& qu, Box e);

// ����
bool deQueue(QuType*& qu, Box& e);

// �������Ƿ�Ϊ��
bool QueueEmpty(QuType* qu);

// ���ٶ���
void DestroyQueue(QuType*& qu);

//�����Թ�����·��
bool mepath(int xi, int yi, int xe, int ye);
bool mepath(int xi, int yi, int xe, int ye, int mg[10][10]);

//��ӡ·��
void dispapath(QuType* qu, int front);