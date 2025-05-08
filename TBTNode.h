#include <iostream>
using namespace std;

typedef char DataType;

struct TBTNode
{
	DataType    data;    //数据域	
	int lflag, rflag;
	struct TBTNode* lchild;
	struct TBTNode* rchild; //结点的左右子树指针	
};//二叉树结点类型



//初始化空二叉树
void TreeInit(TBTNode*& root);

//按照前序遍历序列建立二叉树
void CreateBTree_Pre(TBTNode*& b, DataType* str);

//释放二叉树中所有结点
void ClearBTree(TBTNode*& root);

//输出二叉树
void DispBtree(TBTNode* root);

//对二叉树进行中序线索化
void Thread(TBTNode*& root);

//中序线索化二叉树
TBTNode* CreatThread(TBTNode*& b);

//遍历线索化二叉树
void ThInOrder(TBTNode* tb);

//寻找特定结点的前驱和后继
void FindPreAndNext(TBTNode* root, DataType e);