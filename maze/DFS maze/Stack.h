#include <iostream>
using namespace std;

const int MaxSize = 35;

extern int mg[10][10];

struct Box
{
	int i, j, di;
};

struct StType
{
	Box data[MaxSize];
	int top; //ջ��ָ��
};

//��ʼ��˳���
void InitStack(StType*& s);

//�ж��Ƿ�ձ�
bool EmptyStack(StType* s);

//��ջ
bool Push(StType*& s, Box& data);

//��ջ
bool Pop(StType*& s, Box& e);

//ȡջ��Ԫ��
bool GetTop(StType* s, Box& e);

//����ջ
void DestroyStack(StType*& s);

//���Թ�
void FindAllPaths(int xi, int yi, int xe, int ye);