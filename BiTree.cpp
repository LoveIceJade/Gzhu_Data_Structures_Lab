#include "BiTree.h"

//��ʼ���ն�����
void TreeInit(BTNode*& root)
{
	root = nullptr;
}

//����ǰ��������н���������
void CreateBTree_Pre(BTNode*& b, DataType *str)
{
	BTNode* St[100], * p;  //St����Ϊ��ջ
	p = new BTNode;     
	int top = -1, k = 0, j = 0;  //topΪջ��ָ��
	char ch;
	TreeInit(b);     //��ʼ��bΪ��
	ch = str[j];
	while (ch != '\0')  //����str�������ַ�
	{
		switch (ch)
		{
		case'(':top++; St[top] = p; k = 1; break;  //�������ӽ��
		case')':top--; break;   //ջ��ָ����������
		case',':k = 2; break;   //�����Һ��ӽ��
		default:
			p = new BTNode;  //����һ���½�㣬pָ����
			p->data = ch;  //��Ž������
			p->lchild = p->rchild = nullptr;  //������ָ���趨Ϊ��
			if (b == nullptr)  //����δ���ڵ�
				b = p;        //p��Ϊ���ڵ�
			else  //�ѽ������ڵ�
			{
				switch (k)
				{
				case 1:St[top]->lchild = p; break;  //Ϊջ��ָ������
				case 2:St[top]->rchild = p; break;  //Ϊջ��ָ���Һ���
				}
			}
		}
		j++;  //��������str
		ch = str[j];
	}
}

//�ͷŶ����������н��
void ClearBTree(BTNode*& root)
{
	if (root != nullptr)
	{
		ClearBTree(root->lchild);
		ClearBTree(root->rchild);
		delete root;
	}
}

//���������˫��֧������
int TwoDegreeCount(BTNode* root)
{
	if (root == nullptr)  //����ֱ�ӷ���0
		return 0;

	if (root->lchild != nullptr && root->rchild != nullptr)
		return 1;

	return(TwoDegreeCount(root->lchild) + TwoDegreeCount(root->rchild));
}

//����������߶�
int BTreeDepth(BTNode* root)
{
	if (root == nullptr)  //�����߶�Ϊ0
		return 0;
	int lchildp, rchildp;
	lchildp = BTreeDepth(root->lchild);  //���������߶�
	rchildp = BTreeDepth(root->rchild);  //���������߶�
	return (lchildp > rchildp) ? (lchildp + 1) : (rchildp + 1);  //�Ƚ����������߶Ⱥ�ȡ�ϴ�ֵ+1�����ڵ�߶ȣ�
}

//���������
void DispBtree(BTNode* root)
{
	if (root != nullptr)  //�ǿ��������
	{
		cout << root->data;  //������ڵ�
		if (root->lchild != nullptr || root->rchild != nullptr)
		{
			cout << "(";  //�к��ӽ��ʱ�����"("
			DispBtree(root->lchild);  //�ݹ�������
			if (root->rchild != nullptr)  //���Һ��ӽ��ʱ�����","
				cout << ",";  
			DispBtree(root->rchild);  //�ݹ�������
			cout << ")";  //�к��ӽ��ʱ�����")"
		}
	}
}

//���������Ҷ�ӽ�����
int LeafCount(BTNode* root)
{
	if (root == nullptr)  //�������򷵻�0
		return 0;
	if (root->lchild == nullptr && root->rchild == nullptr)  //��ΪҶ�ӽ�㣬�򷵻�1
		return 1;

	return LeafCount(root->lchild) + LeafCount(root->rchild);  //�����������������������Ҷ�ӽ��֮��
}

//���������������
int DegreeCount(BTNode* root)
{
	if (root == nullptr)  //�������򷵻�0
		return 0;

	return DegreeCount(root->lchild) + DegreeCount(root->rchild) + 1;  //������������������������֮�Լ��ӱ����
}

//���ض����
BTNode *FindNote(BTNode* root, DataType x)
{
	BTNode* p;
	if (root == nullptr)  //������ֱ�ӷ���
		return nullptr;
	else if (root->data == x)  //�ҵ��򷵻�Ŀ����
		return root;
	else
	{
		p = FindNote(root->lchild, x);  //����������
		if (p != nullptr)  //�����������ҵ���
			return p;  
		else
			return FindNote(root->rchild, x);  //����������
	}
}


//���ض���㺢�Ӷ���
int BTreeChildNum(BTNode* root, DataType x)
{
	BTNode* p = FindNote(root, x);
	if (p == nullptr)  //�Ҳ���Ŀ��ڵ㣬����-1
		return -1;

	int count = 0;
	if (root->lchild != nullptr)  //��������������
	{
		if (root->lchild->lchild != nullptr)
			count++;
		if (root->lchild->rchild != nullptr)
			count++;
	}
	if (root->rchild != nullptr)  //��������������
	{
		if (root->rchild->lchild != nullptr)
			count++;
		if (root->rchild->rchild != nullptr)
			count++;
	}
	return count;
}

//��������Ķ�
int CountDegree(BTNode* root)
{
	if (root == nullptr)
	{
		return 0;  // ����û�ж�
	}

	int degree = 0;  // ��ǰ�ڵ�Ķ���

	// �жϵ�ǰ�ڵ��Ƿ���������
	if (root->lchild != nullptr)
	{
		degree++;  // ��������������+1
	}

	// �жϵ�ǰ�ڵ��Ƿ���������
	if (root->rchild != nullptr) 
	{
		degree++;  // ��������������+1
	}

	// �ݹ�������������������Ķ��������ۼ�
	return degree + CountDegree(root->lchild) + CountDegree(root->rchild);
}


//�����ǵݹ��㷨���б���
//ǰ�����������
void PreOrder_01(BTNode* root)
{
	if (root != nullptr)
	{
		cout << root->data;
		PreOrder_01(root->lchild);
		PreOrder_01(root->rchild);
	}
}

//�������������
void InOrder_01(BTNode* root)
{
	if (root != nullptr)
	{
		InOrder_01(root->lchild);
		cout << root->data;
		InOrder_01(root->rchild);
	}
}

//�������������
void PostOrder_01(BTNode* root)
{
	if (root != nullptr)
	{
		PostOrder_01(root->lchild);
		PostOrder_01(root->rchild);
		cout << root->data;
	}
}

//�����Ƿǵݹ��㷨���б���
//ǰ�����������
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

//�������������
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

//�������������
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


//������ʵ��ջ�Ĺ��ܵ�����
//��ʼ��ջ
void InitStack(StackLink*& s)
{
	s = new StackLink;
	s->next = nullptr;
}

//��һ��Ԫ�ؽ�ջ��ͷ�巨��
bool Push(StackLink*& s, BTNode*& e)
{
	StackLink* p = new StackLink;
	p->data = e;
	p->next = s->next;
	s->next = p;
	return true;
}
//ȡջ����һ��Ԫ��
bool GetTop(StackLink* s, BTNode*& e)
{
	if (s->next == nullptr)
		return false;
	e = s->next->data;
	return true;
}

//��ջ
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

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(StackLink*& s)
{
	return(s->next == nullptr);
}

//����ջ
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


