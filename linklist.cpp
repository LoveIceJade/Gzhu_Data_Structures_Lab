//����һ��ʵ�ֺ������ܵ��ļ�
#include"linklist.h"

//���һ�������λ����
int GetRand()
{
	return(rand() % 900  + 100);
}

//��ʼ��������
void  InitList(LNode *& p)
{   //pΪ�������ͷָ��
	p = new LNode;
	if(!p)
	{
		cout << "��ʼ������" << endl;
		return;
	}
	p->next = NULL;
	cout << "��ʼ���ɹ���" << endl;
}

//β�巨��������
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
	cout << "�����ɹ���" << endl;
}

//���������������
void TraveList(LNode* p)
{
	int i = 1;
	if (p->next == NULL)
	{
		cout<<"�������ǿձ�" << endl;
		return;
	}
	LNode* L = p->next;
	while (L != NULL)
	{
		cout<<"��������ݵ�" << i <<"��Ԫ��Ϊ" << L->data << endl;
		L = L->next;
		i++;
	}
}

//���ص�һ����ָ��ֵƥ���Ԫ��λ��
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

//�������ָ��λ�ò���Ԫ��
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

//��֤�����Ƿ���ȷ
bool TraveList_1(LNode*& p, int& pos, int& item)
{
	bool T = 0;
	int i = 1;
	LNode* L = p->next;
	while (L != NULL)
	{
		cout << "��������ݵ�" << i << "��Ԫ��Ϊ" << L->data;
		if (i == pos && L->data == item)
		{
			cout << "\t����ɹ�" ;
			T = 1;
		}
		cout << endl;
		L = L->next;
		i++;
	}
	return T;
}
//ɾ����һ����ָ��ֵƥ���Ԫ�ص�����
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
		cout << "�����ݲ��ڵ�������" << endl;
		return false;
	}

	else
	{
		pre->next = L->next;
		L->next = NULL;
		delete L;
		cout << "ɾ���ɹ�" << endl;
		return true;
	}
}

//��ת����
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
	cout << "��ת�ɹ���" << endl << endl;
}

//�ָ�����
void SplitList(LNode*& p, int value)
{
	if (p == nullptr || p->next == nullptr)
	{
		cout << "����Ԫ������������������з�ת" << endl;
		return;
	}

	// ��������ͷ�ڵ㣬�ֱ�����С�ڻ�׼ֵ�ʹ��ڵ��ڻ�׼ֵ������
	LNode* lessHead = new LNode;
	LNode* greaterHead = new LNode;
	InitList(lessHead);
	InitList(greaterHead);
	LNode* less = lessHead;
	LNode* greater = greaterHead;

	// ������������ڵ�
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

	// �ϲ���������
	less->next = greaterHead->next;
	greater->next = nullptr;  // ȷ���µ�����β��ָ��nullptr

	// ��������ͷ
	p = lessHead->next;

	// ɾ������ͷ���
	delete lessHead;
	delete greaterHead;

	cout << "�Ѿ��ָ����" << endl;
}