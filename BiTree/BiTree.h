#include <iostream>
using namespace std;

typedef char DataType;
const int MaxSize = 9999999;

struct BTNode
{
	DataType    data;    //数据域	
	struct BTNode* lchild;
	struct BTNode* rchild; //结点的左右子树指针	
};//二叉树结点类型

//初始化空二叉树
void TreeInit(BTNode*& root);

//按照前序遍历序列建立二叉树
void CreateBTree_Pre(BTNode*& b, DataType* str);

//释放二叉树中所有结点
void ClearBTree(BTNode*& root);

//计算二叉树叶子结点个数
int LeafCount(BTNode* root);

//计算二叉树结点个数
int DegreeCount(BTNode* root);


//计算二叉树高度
int BTreeDepth(BTNode* root);

//输出二叉树
void DispBtree(BTNode* root);

//求特定结点
BTNode* FindNote(BTNode* root, DataType x);

//求特定结点孩子度数
int BTreeChildNum(BTNode* root, DataType x);

//求二叉树的度
int CountDegree(BTNode* root);

//下面是递归算法进行遍历
//前序遍历二叉树
void PreOrder_01(BTNode* root);

//中序遍历二叉树
void InOrder_01(BTNode* root);

//后序遍历二叉树
void PostOrder_01(BTNode* root);

//下面是非递归算法进行遍历
//前序遍历二叉树
void PreOrder_02(BTNode* root);

//中序遍历二叉树
void InOrder_02(BTNode* root);

//后序遍历二叉树
void PostOrder_02(BTNode* root);




//下面是实现栈相关的内容
struct StackLink     //链栈节点声明
{
	BTNode* data;
	StackLink* next;
};

//初始化栈
void InitStack(StackLink*& s);

//将一个元素进栈（头插法）
bool Push(StackLink*& s, BTNode*& e);

//取栈顶第一个元素
bool GetTop(StackLink* s, BTNode*& e);

//判断栈是否为空
bool StackEmpty(StackLink*& s);

//出栈
bool Pop(StackLink*& s, BTNode*& e);

//销毁栈
void DestroyStack(StackLink*& s);
