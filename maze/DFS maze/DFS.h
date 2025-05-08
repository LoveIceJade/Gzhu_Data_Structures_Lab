#include <iostream>
using namespace std;

const int MaxSize = 35;

extern int mg[10][10];

struct Box
{
	int i, j, di;
};

struct StType
{
	Box data[MaxSize];
	int top; //栈顶指针
};

//初始化顺序表
void InitStack(StType*& s);

//判断是否空表
bool EmptyStack(StType* s);

//入栈
bool Push(StType*& s, Box& data);

//进栈
bool Pop(StType*& s, Box& e);

//取栈顶元素
bool GetTop(StType* s, Box& e);

//销毁栈
void DestroyStack(StType*& s);

//走迷宫
void FindAllPaths(int xi, int yi, int xe, int ye);
