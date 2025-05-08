#include"Stack.h"

//获得一个随机三位整数
int GetRand()
{
	return(rand() % 900 + 100);
}

//初始化栈
void InitStack(StackLink*& s)
{
	s = new StackLink;
	s->next = nullptr;
	cout << "栈初始化成功" << endl;
}

//将一个元素进栈（头插法）
bool Push(StackLink*& s, DataType& e)
{
	StackLink* p = new StackLink;
	p->data = e;
	p->next = s->next;
	s->next = p;
	// 调试时可用，最终结果可以注释掉
	// cout << "入栈成功" << endl;
	return true;
}

//将一个元素进栈（头插法）
bool Push(StackLink*& s, dataType &e)
{
	StackLink* p = new StackLink;
	p->data = e;
	p->next = s->next;
	s->next = p;
	// 调试时可用，最终结果可以注释掉
	// cout << "入栈成功" << endl;
	return true;
}

//将数组进栈(头插法)
bool PushArray(StackLink*& s, DataType e[], int n)
{
	for (int i = 0; i < n; i++)
	{
		StackLink* p = new StackLink;
		p->data = e[i];
		p->next = s->next;
		s->next = p;
	}
	cout<<"数据全部入栈成功" << endl;
	return true;
}

//出栈
bool Pop(StackLink*& s, DataType& e)
{
	if (s->next == nullptr || s == nullptr)
	{ 
		// 调试时可用，最终结果可以注释掉
		// cout << "出栈失败，该栈为空栈" << endl;  
		return false; 
	}
	StackLink* p;
	p = s->next;
	e = p->data;
	s->next = p->next;
	delete p;
	return true;
}

//出栈
bool Pop(StackLink*& s, dataType& e)
{
	if (s->next == nullptr || s == nullptr)
	{
		cout << "出栈失败，该栈为空栈" << endl;
		return false;
	}
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

//判断括号是否合法
void Parenlegal(string input)
{
	StackLink* p;
	InitStack(p);
	dataType e;

	for (char ch : input)
	{
		//只进栈左括号，遇到右括号出栈一个左括号，忽略其他字符
		if (ch == '(')
			Push(p, ch);
		else if (ch == ')')
		{
			if (StackEmpty(p)) //栈内为空，无法出栈，输入字符圆括号非法
			{
				cout << "圆括号非法，右括号过多" << endl;
				return;
			}
			Pop(p, e);
		}
	}

	if (!StackEmpty(p))  //如果最后栈非空，则左括号过多
	{
		cout << "圆括号非法，左括号过多" << endl;
		return;
	}
	cout << "圆括号合法" << endl;

	delete p;  //释放p的内存
}
