//这是一个实现函数功能的文件
#include"linklist.h"

//获得一个随机三位整数
int GetRand()
{
	return(rand() % 900  + 100);
}

//初始化单链表
void  InitList(LNode *& p)
{   //p为单链表的头指针
	p = new LNode;
	if(!p)
	{
		cout << "初始化错误" << endl;
		return;
	}
	p->next = NULL;
	cout << "初始化成功！" << endl;
}

//尾插法建立链表
void CreatList(LNode*& p, DataType a[], int n)
{
	LNode* r, * s;
	p = new LNode;
	r = p;
	for (int i=0; i < n; i++)
	{
		s = new LNode;
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
	cout << "创建成功！" << endl;
}

//遍历并输出单链表
void TraveList(LNode* p)
{
	int i = 1;
	if (p->next == NULL)
	{
		cout<<"该链表是空表" << endl;
		return;
	}
	LNode* L = p->next;
	while (L != NULL)
	{
		cout<<"链表的数据第" << i <<"个元素为" << L->data << endl;
		L = L->next;
		i++;
	}
}

//返回第一个与指定值匹配的元素位置
int Find_item(LNode* p, DataType item)
{
	int i = 1;
	LNode* L = p->next;
	while (L != NULL && L->data != item)
	{
		L = L->next;
		i++;
	}
	if (L == NULL) 
		return 0; 
	else 
		return i; 
}

//向单链表的指定位置插入元素
bool Listinsert(LNode*& p, int pos, DataType item)
{
	if (pos <= 0)
		return false;
	int i = 0;
	LNode* L = p, * s;
	while (i < pos - 1 && p != NULL)
	{
		i++;
		L = L->next;
	}
	if (L == NULL)
		return false;
	else
	{
		s = new LNode;
		s->data = item;
		s->next = L->next;
		L->next = s;
		return true;
	}
}

//验证插入是否正确
bool TraveList_1(LNode*& p, int& pos, int& item)
{
	bool T = 0;
	int i = 1;
	LNode* L = p->next;
	while (L != NULL)
	{
		cout << "链表的数据第" << i << "个元素为" << L->data;
		if (i == pos && L->data == item)
		{
			cout << "\t插入成功" ;
			T = 1;
		}
		cout << endl;
		L = L->next;
		i++;
	}
	return T;
}
//删除第一个与指定值匹配的元素的链表
bool Delete_item(LNode*& p, DataType item)
{
	LNode* L = p->next, * pre=p;
	while (L != NULL && L->data!=item)
	{
		L = L->next;
		pre = pre->next;
	}

	if (L == NULL)
	{
		cout << "该数据不在单链表内" << endl;
		return false;
	}

	else
	{
		pre->next = L->next;
		L->next = NULL;
		delete L;
		cout << "删除成功" << endl;
		return true;
	}
}

//翻转链表
void ReserveList(LNode*& p)
{
	LNode* L = p->next, * pre = NULL;
	while (L)
	{
		LNode* Next = L->next;
		L->next = pre;
		pre = L;
		L = Next;
	}
	p->next = pre;
	cout << "翻转成功！" << endl << endl;
}

//分割链表
void SplitList(LNode*& p, int value)
{
	if (p == nullptr || p->next == nullptr)
	{
		cout << "链表元素少于两个，无需进行翻转" << endl;
		return;
	}

	// 两个虚拟头节点，分别用于小于基准值和大于等于基准值的链表
	LNode* lessHead = new LNode;
	LNode* greaterHead = new LNode;
	InitList(lessHead);
	InitList(greaterHead);
	LNode* less = lessHead;
	LNode* greater = greaterHead;

	// 遍历链表并分类节点
	LNode* L = p;
	while (L != nullptr) 
	{
		if (L->data < value) 
		{
			less->next = L;
			less = less->next;
		}
		else 
		{
			greater->next = L;
			greater = greater->next;
		}
		L = L->next;
	}

	// 合并两个链表
	less->next = greaterHead->next;
	greater->next = nullptr;  // 确保新的链表尾部指向nullptr

	// 更新链表头
	p = lessHead->next;

	// 删除虚拟头结点
	delete lessHead;
	delete greaterHead;

	cout << "已经分割完成" << endl;
}