#include <iostream>
#include<ctime>
#include<string>
using namespace std;

//���һ�������λ����
int GetRand();

typedef int DataType;  //ʹ��int����Ϊ��������
typedef char dataType;  //ʹ��char����Ϊ��������,���Բ�����Ƿ�Ϸ�ʱ��

struct StackLink     //��ջ�ڵ�����
{
	DataType data;
	StackLink* next;
};

//��ʼ��ջ
void InitStack(StackLink*& s);

//��һ��Ԫ�ؽ�ջ��ͷ�巨��
bool Push(StackLink*& s, DataType& e);
bool Push(StackLink*& s, dataType& e); // ���Բ�����Ƿ�Ϸ�ʱ��

//�������ջ(ͷ�巨)
bool PushArray(StackLink*& s, DataType e[], int n);

//��ջ
bool Pop(StackLink*& s, DataType& e);
bool Pop(StackLink*& s, dataType& e); // ���Բ�����Ƿ�Ϸ�ʱ��

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(StackLink*& s);

//�ж������Ƿ�Ϸ�
void Parenlegal(string input);