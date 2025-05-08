#include <iostream>
using namespace std;

typedef char DataType;
const int MaxSize = 9999999;

struct BTNode
{
	DataType    data;    //������	
	struct BTNode* lchild;
	struct BTNode* rchild; //������������ָ��	
};//�������������

//��ʼ���ն�����
void TreeInit(BTNode*& root);

//����ǰ��������н���������
void CreateBTree_Pre(BTNode*& b, DataType* str);

//�ͷŶ����������н��
void ClearBTree(BTNode*& root);

//���������Ҷ�ӽ�����
int LeafCount(BTNode* root);

//���������������
int DegreeCount(BTNode* root);


//����������߶�
int BTreeDepth(BTNode* root);

//���������
void DispBtree(BTNode* root);

//���ض����
BTNode* FindNote(BTNode* root, DataType x);

//���ض���㺢�Ӷ���
int BTreeChildNum(BTNode* root, DataType x);

//��������Ķ�
int CountDegree(BTNode* root);

//�����ǵݹ��㷨���б���
//ǰ�����������
void PreOrder_01(BTNode* root);

//�������������
void InOrder_01(BTNode* root);

//�������������
void PostOrder_01(BTNode* root);

//�����Ƿǵݹ��㷨���б���
//ǰ�����������
void PreOrder_02(BTNode* root);

//�������������
void InOrder_02(BTNode* root);

//�������������
void PostOrder_02(BTNode* root);




//������ʵ��ջ��ص�����
struct StackLink     //��ջ�ڵ�����
{
	BTNode* data;
	StackLink* next;
};

//��ʼ��ջ
void InitStack(StackLink*& s);

//��һ��Ԫ�ؽ�ջ��ͷ�巨��
bool Push(StackLink*& s, BTNode*& e);

//ȡջ����һ��Ԫ��
bool GetTop(StackLink* s, BTNode*& e);

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(StackLink*& s);

//��ջ
bool Pop(StackLink*& s, BTNode*& e);

//����ջ
void DestroyStack(StackLink*& s);