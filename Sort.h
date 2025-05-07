#include<iostream>
#include<string>
#include<ctime>
using namespace std;

typedef int KeyType;
typedef int DataType;

//存放数据的结点
struct ReeType
{
	KeyType key;
};

//展示排序后的key
void ShowKey(ReeType R[], int n);

//展示排序次数
void ShowNum(int& num);

//展示排序后的数组
void Show(ReeType R[], int n, int &num);

//获取随机数数组
void GetRand(ReeType R[], ReeType A[], ReeType B[], ReeType C[], ReeType D[], ReeType E[]);

//获取随机数数组
void GetRand(ReeType R[]);

//获取随机字母数组（字母不重复）
void GetRand(char *ch);

//直插排序法
void InsertSort(ReeType R[], int n);

//冒泡排序法
void BubbletSort(ReeType A[], int n);

//双向冒泡排序法
void BubbletSort1(ReeType R[], int n);

//快速排序法1
//特点：使用显式交换方式，选择数组末尾元素作为基准
void QuickSort(ReeType R[], int s, int t, int& n);

//快速排序算法2
//特点：使用挖坑填数方式，选择数组首元素作为基准
int partion1(ReeType R[], int s, int t, int& n);

//堆排序法
void HeapSort(ReeType R[], int n, int& no);

//二路归并排序法
void MergeSort(ReeType R[], int n, int& no);

//顺序查找
void SeqSearch(char R[], KeyType k);

//非递归二分查找
int BinSearch_0(ReeType R[], KeyType k, int n);

//递归二分查找
int BinSearch_1(ReeType R[], KeyType k, int low, int high);

//二叉排序树的结点
struct BSTNode
{
	char key;
	BSTNode* lchild, *rchild;
};

//插入排序二叉树的一个结点
BSTNode* InsertBSTNode(BSTNode*& root, char k);

//生成二叉排序树
void CreatBSTree(BSTNode*& root, char* ch);

//递归输出先序序列
void PreOrder(BSTNode* root);

//递归输出中序序列
void InOrder(BSTNode* root);

//二叉排序树的非递归查找
BSTNode* SearchBST_0(BSTNode* root, KeyType k);

//二叉排序树的递归查找
BSTNode* SearchBST_1(BSTNode* root, KeyType k);