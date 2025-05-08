#include"Stack.h"

//���һ�������λ����
int GetRand()
{
	return(rand() % 900 + 100);
}

//��ʼ��ջ
void InitStack(StackLink*& s)
{
	s = new StackLink;
	s->next = nullptr;
	cout << "ջ��ʼ���ɹ�" << endl;
}

//��һ��Ԫ�ؽ�ջ��ͷ�巨��
bool Push(StackLink*& s, DataType& e)
{
	StackLink* p = new StackLink;
	p->data = e;
	p->next = s->next;
	s->next = p;
	// ����ʱ���ã����ս������ע�͵�
	// cout << "��ջ�ɹ�" << endl;
	return true;
}

//��һ��Ԫ�ؽ�ջ��ͷ�巨��
bool Push(StackLink*& s, dataType &e)
{
	StackLink* p = new StackLink;
	p->data = e;
	p->next = s->next;
	s->next = p;
	// ����ʱ���ã����ս������ע�͵�
	// cout << "��ջ�ɹ�" << endl;
	return true;
}

//�������ջ(ͷ�巨)
bool PushArray(StackLink*& s, DataType e[], int n)
{
	for (int i = 0; i < n; i++)
	{
		StackLink* p = new StackLink;
		p->data = e[i];
		p->next = s->next;
		s->next = p;
	}
	cout<<"����ȫ����ջ�ɹ�" << endl;
	return true;
}

//��ջ
bool Pop(StackLink*& s, DataType& e)
{
	if (s->next == nullptr || s == nullptr)
	{ 
		// ����ʱ���ã����ս������ע�͵�
		// cout << "��ջʧ�ܣ���ջΪ��ջ" << endl;  
		return false; 
	}
	StackLink* p;
	p = s->next;
	e = p->data;
	s->next = p->next;
	delete p;
	return true;
}

//��ջ
bool Pop(StackLink*& s, dataType& e)
{
	if (s->next == nullptr || s == nullptr)
	{
		cout << "��ջʧ�ܣ���ջΪ��ջ" << endl;
		return false;
	}
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

//�ж������Ƿ�Ϸ�
void Parenlegal(string input)
{
	StackLink* p;
	InitStack(p);
	dataType e;

	for (char ch : input)
	{
		//ֻ��ջ�����ţ����������ų�ջһ�������ţ����������ַ�
		if (ch == '(')
			Push(p, ch);
		else if (ch == ')')
		{
			if (StackEmpty(p)) //ջ��Ϊ�գ��޷���ջ�������ַ�Բ���ŷǷ�
			{
				cout << "Բ���ŷǷ��������Ź���" << endl;
				return;
			}
			Pop(p, e);
		}
	}

	if (!StackEmpty(p))  //������ջ�ǿգ��������Ź���
	{
		cout << "Բ���ŷǷ��������Ź���" << endl;
		return;
	}
	cout << "Բ���źϷ�" << endl;

	delete p;  //�ͷ�p���ڴ�
}