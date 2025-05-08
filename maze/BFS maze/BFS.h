#include <iostream>
using namespace std;

const int MaxSize = 100;

extern int mg[10][10];

struct Box
{
	int i, j;  //方块的位置
	int pre;   //本路径中上一个方块在队列中的下标
};

struct QuType 
{
	Box data[MaxSize];
	int front, rear;          // 队头指针和队尾指针
};


// 初始化队列
void InitQueue(QuType*& qu);

// 入队
bool enQueue(QuType*& qu, Box e);

// 出队
bool deQueue(QuType*& qu, Box& e);

// 检查队列是否为空
bool QueueEmpty(QuType* qu);

// 销毁队列
void DestroyQueue(QuType*& qu);

//查找迷宫最优路径
bool mepath(int xi, int yi, int xe, int ye);
bool mepath(int xi, int yi, int xe, int ye, int mg[10][10]);

//打印路径
void dispapath(QuType* qu, int front);
