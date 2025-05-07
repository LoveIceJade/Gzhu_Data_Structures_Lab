#include<iostream>
#include<string>
#include<ctime>
using namespace std;

typedef int KeyType;
typedef int DataType;

//������ݵĽ��
struct ReeType
{
	KeyType key;
};

//չʾ������key
void ShowKey(ReeType R[], int n);

//չʾ�������
void ShowNum(int& num);

//չʾ����������
void Show(ReeType R[], int n, int &num);

//��ȡ���������
void GetRand(ReeType R[], ReeType A[], ReeType B[], ReeType C[], ReeType D[], ReeType E[]);

//��ȡ���������
void GetRand(ReeType R[]);

//��ȡ�����ĸ���飨��ĸ���ظ���
void GetRand(char *ch);

//ֱ������
void InsertSort(ReeType R[], int n);

//ð������
void BubbletSort(ReeType A[], int n);

//˫��ð������
void BubbletSort1(ReeType R[], int n);

//��������1
//�ص㣺ʹ����ʽ������ʽ��ѡ������ĩβԪ����Ϊ��׼
void QuickSort(ReeType R[], int s, int t, int& n);

//���������㷨2
//�ص㣺ʹ���ڿ�������ʽ��ѡ��������Ԫ����Ϊ��׼
int partion1(ReeType R[], int s, int t, int& n);

//������
void HeapSort(ReeType R[], int n, int& no);

//��·�鲢����
void MergeSort(ReeType R[], int n, int& no);

//˳�����
void SeqSearch(char R[], KeyType k);

//�ǵݹ���ֲ���
int BinSearch_0(ReeType R[], KeyType k, int n);

//�ݹ���ֲ���
int BinSearch_1(ReeType R[], KeyType k, int low, int high);

//�����������Ľ��
struct BSTNode
{
	char key;
	BSTNode* lchild, *rchild;
};

//���������������һ�����
BSTNode* InsertBSTNode(BSTNode*& root, char k);

//���ɶ���������
void CreatBSTree(BSTNode*& root, char* ch);

//�ݹ������������
void PreOrder(BSTNode* root);

//�ݹ������������
void InOrder(BSTNode* root);

//�����������ķǵݹ����
BSTNode* SearchBST_0(BSTNode* root, KeyType k);

//�����������ĵݹ����
BSTNode* SearchBST_1(BSTNode* root, KeyType k);