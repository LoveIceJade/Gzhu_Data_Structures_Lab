#include"TBTNode.h"

//初始化空二叉树
void TreeInit(TBTNode*& root)
{
	root = nullptr;
}

//按照前序遍历序列建立二叉树
void CreateBTree_Pre(TBTNode*& b, DataType* str)
{
	TBTNode* St[100], * p;  //St数组为链栈
	p = new TBTNode;
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
			p = new TBTNode;  //创建一个新结点，p指向其
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
void ClearBTree(TBTNode*& root)
{
	if (root != nullptr)
	{
		ClearBTree(root->lchild);
		ClearBTree(root->rchild);
		delete root;
	}
}

//输出二叉树
void DispBtree(TBTNode* root)
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

TBTNode* pre;  //全局声明指针变量

//对二叉树进行中序线索化
void Thread(TBTNode*& root)
{
	if (root != nullptr)
	{
		Thread(root->lchild);
		if (root->lchild == nullptr)
		{
			root->lchild = pre;
			root->lflag = 1;
		}
		else
			root->lflag = 0;
		if (pre->rchild == nullptr)
		{
			pre->rchild = root;
			pre->rflag = 1;
		}
		else
			pre->rflag = 0;
		pre = root;
		Thread(root->rchild);
	}
}

//中序线索化二叉树
TBTNode* CreatThread(TBTNode*& b)
{
	TBTNode* root = new TBTNode;
	root->lflag = 0;
	root->rflag = 1;
	root->rchild = b;
	if (b == nullptr)
		root->lchild = b;
	else
	{
		root->lchild = b;
		pre = root;
		Thread(b);
		pre->rchild = root;
		pre->rflag = 1;
		root->rchild = pre;
	}
	return root;
}

//遍历线索化二叉树
void ThInOrder(TBTNode* tb)  //tb指向指向线索化二叉树的头结点
{
	TBTNode* p = tb->lchild;   //p指向根节点
	while (p != tb)
	{
		while (p->lflag == 0)  //找开始结点
			p = p->lchild;  //访问开始结点
		cout << p->data;
		while (p->rflag == 1 && p->rchild != tb)
		{
			p = p->rchild;
			cout << p->data;
		}
		p = p->rchild;
	}
}

//求特定结点
TBTNode* FindNote(TBTNode* root, DataType x)
{
	TBTNode* p;
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

// 寻找特定节点的前驱和后继节点
void FindPreAndNext(TBTNode* root,DataType e) 
{
	root = FindNote(root, e);
	if (root == nullptr) 
	{
		cout << "结点不存在" << endl;
		return;
	}

	// 找前驱
	TBTNode* pre = nullptr;
	if (root->lflag == 1)
	{
		// 如果是线索，直接指向前驱
		pre = root->lchild;
	}
	else 
	{
		// 如果不是线索，找到左子树最右下的节点
		TBTNode* temp = root->lchild;
		while (temp != nullptr && temp->rflag == 0) 
		{
			temp = temp->rchild;
		}
		pre = temp;
	}

	// 找后继
	TBTNode* next = nullptr;
	if (root->rflag == 1) 
	{
		// 如果是线索，直接指向后继
		next = root->rchild;
	}
	else 
	{
		// 如果不是线索，找到右子树最左下的节点
		TBTNode* temp = root->rchild;
		while (temp != nullptr && temp->lflag == 0) 
		{
			temp = temp->lchild;
		}
		next = temp;
	}

	// 输出结果
	if (pre != nullptr) 
	{
		cout << "前驱节点值: " << pre->data << endl;
	}
	else 
	{
		cout << "无前驱节点" << endl;
	}

	if (next != nullptr) 
	{
		cout << "后继节点值: " << next->data << endl;
	}
	else 
	{
		cout << "无后继节点" << endl;
	}
}