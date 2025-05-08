#include <iostream>
#include<ctime>
#include<string>
using namespace std;

//获得一个随机三位整数
int GetRand();

typedef int DataType;  //使用int类型为数据类型
typedef char dataType;  //使用char类型为数据类型,检查圆括号是否合法时用

struct StackLink     //链栈节点声明
{
	DataType data;
	StackLink* next;
};

//初始化栈
void InitStack(StackLink*& s);

//将一个元素进栈（头插法）
bool Push(StackLink*& s, DataType& e);
bool Push(StackLink*& s, dataType& e); // 检查圆括号是否合法时用

//将数组进栈(头插法)
bool PushArray(StackLink*& s, DataType e[], int n);

//出栈
bool Pop(StackLink*& s, DataType& e);
bool Pop(StackLink*& s, dataType& e); // 检查圆括号是否合法时用

//判断栈是否为空
bool StackEmpty(StackLink*& s);

//判断括号是否合法
void Parenlegal(string input);