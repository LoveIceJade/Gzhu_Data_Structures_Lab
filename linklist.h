//���������������ͺ���Ӧ�������ļ�
#include <iostream>
#include<ctime>
using namespace std;

typedef int DataType;

//���һ�������λ����
int GetRand();

typedef struct LNode
{
	DataType data;
	struct LNode* next;
}LinkNode;

//��ʼ��������
void  InitList(LNode*& p);

//β�巨��������
void CreatList(LNode*& p, DataType a[], int n);

//����������
void TraveList(LNode* p);

//�������ָ��λ�ò���Ԫ��
bool Listinsert(LNode*& p, int pos, DataType item);

//��֤�����Ƿ���ȷ
bool TraveList_1(LNode*& p,int &pos,int &item);

//ɾ����һ����ָ��ֵƥ���Ԫ��
bool Delete_item(LNode*& p, DataType item);

//��ת����
void ReserveList(LNode*& p);

//�ָ�����
void SplitList(LNode*& p, int value);