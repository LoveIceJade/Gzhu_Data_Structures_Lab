#include "BiTree.h"

//初始化空二叉树
void TreeInit(BTNode*& root)
{
	root = nullptr;
}

//按照前序遍历序列建立二叉树
void CreateBTree_Pre(BTNode*& b, DataType *str)
{
	BTNode* St[100], * p;  //St数组为链栈
	p = new BTNode;     
	int top = -1, k = 0, j = 0;  //top为栈顶指针
	char ch;
	TreeInit(b);     //初始化b为空
	ch = str[j];
	while (ch != '\0')  //遍历str的所有字符
	{
		switch (ch)
		{
		case'(':top++; St[top] = p; k = 1; break;  //处理左孩子结点
		case')':top--; break;   //栈顶指针子树处理
		case',':k = 2; break;   //处理右孩子结点
		default:
			p = new BTNode;  //创建一个新结点，p指向其
			p->data = ch;  //存放结点数据
			p->lchild = p->rchild = nullptr;  //将左右指针设定为空
			if (b == nullptr)  //若尚未根节点
				b = p;        //p即为根节点
			else  //已建立根节点
			{
				switch (k)
				{
				case 1:St[top]->lchild = p; break;  //为栈顶指针左孩子
				case 2:St[top]->rchild = p; break;  //为栈顶指针右孩子
				}
			}
		}
		j++;  //继续遍历str
		ch = str[j];
	}
}

//释放二叉树中所有结点
void ClearBTree(BTNode*& root)
{
	if (root != nullptr)
	{
		ClearBTree(root->lchild);
		ClearBTree(root->rchild);
		delete root;
	}
}

//计算二叉树双分支结点个数
int TwoDegreeCount(BTNode* root)
{
	if (root == nullptr)  //空树直接返回0
		return 0;

	if (root->lchild != nullptr && root->rchild != nullptr)
		return 1;

	return(TwoDegreeCount(root->lchild) + TwoDegreeCount(root->rchild));
}

//计算二叉树高度
int BTreeDepth(BTNode* root)
{
	if (root == nullptr)  //空树高度为0
		return 0;
	int lchildp, rchildp;
	lchildp = BTreeDepth(root->lchild);  //求左子树高度
	rchildp = BTreeDepth(root->rchild);  //求右子树高度
	return (lchildp > rchildp) ? (lchildp + 1) : (rchildp + 1);  //比较左右子树高度后，取较大值+1（根节点高度）
}

//输出二叉树
void DispBtree(BTNode* root)
{
	if (root != nullptr)  //非空树则输出
	{
		cout << root->data;  //输出根节点
		if (root->lchild != nullptr || root->rchild != nullptr)
		{
			cout << "(";  //有孩子结点时再输出"("
			DispBtree(root->lchild);  //递归左子树
			if (root->rchild != nullptr)  //有右孩子结点时才输出","
				cout << ",";  
			DispBtree(root->rchild);  //递归右子树
			cout << ")";  //有孩子结点时才输出")"
		}
	}
}

//计算二叉树叶子结点个数
int LeafCount(BTNode* root)
{
	if (root == nullptr)  //空树，则返回0
		return 0;
	if (root->lchild == nullptr && root->rchild == nullptr)  //若为叶子结点，则返回1
		return 1;

	return LeafCount(root->lchild) + LeafCount(root->rchild);  //结果返回右子树和左子树的叶子结点之和
}

//计算二叉树结点个数
int DegreeCount(BTNode* root)
{
	if (root == nullptr)  //空树，则返回0
		return 0;

	return DegreeCount(root->lchild) + DegreeCount(root->rchild) + 1;  //结果返回左子树和右子树结点之以及加本结点
}

//求特定结点
BTNode *FindNote(BTNode* root, DataType x)
{
	BTNode* p;
	if (root == nullptr)  //空树则直接返回
		return nullptr;
	else if (root->data == x)  //找到则返回目标结点
		return root;
	else
	{
		p = FindNote(root->lchild, x);  //遍历左子树
		if (p != nullptr)  //在左子树中找到了
			return p;  
		else
			return FindNote(root->rchild, x);  //遍历右子树
	}
}


//求特定结点孩子度数
int BTreeChildNum(BTNode* root, DataType x)
{
	BTNode* p = FindNote(root, x);
	if (p == nullptr)  //找不到目标节点，返回-1
		return -1;

	int count = 0;
	if (root->lchild != nullptr)  //孩子左子树存在
	{
		if (root->lchild->lchild != nullptr)
			count++;
		if (root->lchild->rchild != nullptr)
			count++;
	}
	if (root->rchild != nullptr)  //孩子右子树存在
	{
		if (root->rchild->lchild != nullptr)
			count++;
		if (root->rchild->rchild != nullptr)
			count++;
	}
	return count;
}

//求二叉树的度
int CountDegree(BTNode* root)
{
	if (root == nullptr)
	{
		return 0;  // 空树没有度
	}

	int degree = 0;  // 当前节点的度数

	// 判断当前节点是否有左子树
	if (root->lchild != nullptr)
	{
		degree++;  // 有左子树，度数+1
	}

	// 判断当前节点是否有右子树
	if (root->rchild != nullptr) 
	{
		degree++;  // 有右子树，度数+1
	}

	// 递归计算左子树和右子树的度数，并累加
	return degree + CountDegree(root->lchild) + CountDegree(root->rchild);
}


//下面是递归算法进行遍历
//前序遍历二叉树
void PreOrder_01(BTNode* root)
{
	if (root != nullptr)
	{
		cout << root->data;
		PreOrder_01(root->lchild);
		PreOrder_01(root->rchild);
	}
}

//中序遍历二叉树
void InOrder_01(BTNode* root)
{
	if (root != nullptr)
	{
		InOrder_01(root->lchild);
		cout << root->data;
		InOrder_01(root->rchild);
	}
}

//后序遍历二叉树
void PostOrder_01(BTNode* root)
{
	if (root != nullptr)
	{
		PostOrder_01(root->lchild);
		PostOrder_01(root->rchild);
		cout << root->data;
	}
}

//下面是非递归算法进行遍历
//前序遍历二叉树
void PreOrder_02(BTNode* root)
{
	BTNode* p = root;
	StackLink* st;
	InitStack(st);
	while (p != nullptr || !StackEmpty(st))
	{
		while (p != nullptr)
		{
			cout << p->data;
			Push(st, p);
			p = p->lchild;
		}
		if (!StackEmpty(st))
		{
			Pop(st, p);
			p = p->rchild;
		}
	}
	cout << endl;
	DestroyStack(st);
}

//中序遍历二叉树
void InOrder_02(BTNode* root)
{
	BTNode* p = root;
	StackLink* st;
	InitStack(st);
	while (p != nullptr || !StackEmpty(st))
	{
		while (p != nullptr)
		{
			Push(st, p);
			p = p->lchild;
		}
		if (!StackEmpty(st))
		{
			Pop(st, p);
			cout << p->data ;
			p = p->rchild;
		}
	}
	cout << endl;
	DestroyStack(st);
}

//后序遍历二叉树
void PostOrder_02(BTNode* root)
{
	BTNode* p = root, * r;
	StackLink* st; 
	InitStack(st); 
	bool flag;
	do
	{
		while (p != nullptr)
		{
			Push(st, p);
			p = p->lchild;
		}
		r= nullptr;
		flag = true;
		while (!StackEmpty(st) && flag)
		{
			GetTop(st, p);
			if (p->rchild == r)
			{
				cout << p->data;
				Pop(st, p);
				r = p;
			}
			else
			{
				p = p->rchild;
				flag = false;
			}
		}
	} while (!StackEmpty(st));
	cout << endl;
	DestroyStack(st);
}


//下面是实现栈的功能的内容
//初始化栈
void InitStack(StackLink*& s)
{
	s = new StackLink;
	s->next = nullptr;
}

//将一个元素进栈（头插法）
bool Push(StackLink*& s, BTNode*& e)
{
	StackLink* p = new StackLink;
	p->data = e;
	p->next = s->next;
	s->next = p;
	return true;
}
//取栈顶第一个元素
bool GetTop(StackLink* s, BTNode*& e)
{
	if (s->next == nullptr)
		return false;
	e = s->next->data;
	return true;
}

//出栈
bool Pop(StackLink*& s, BTNode*& e)
{
	if (s->next == nullptr)
		return false;
	StackLink* p;
	p = s->next;
	e = p->data;
	s->next = p->next;
	delete p;
	return true;
}

//判断栈是否为空
bool StackEmpty(StackLink*& s)
{
	return(s->next == nullptr);
}

//销毁栈
void DestroyStack(StackLink*& s)
{
	StackLink* pre = s, * p = s->next;
	while (p != nullptr)
	{
		delete pre;
		pre = p;
		p = pre->next;
	}
	delete pre;
}


