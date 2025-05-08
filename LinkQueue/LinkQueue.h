#include <iostream>
#include <ctime>
using namespace std;

//获得一个随机三位整数
int GetRand();

typedef int DataType;

struct QNode
{ //结点结构
	DataType	data;
	QNode* next;
};

struct LinkQueue
{ //队列结构
	QNode* front;
	QNode* rear;
};

//初始化带头结点的链队列
void InitQueue(LinkQueue*& Q);

//判链队列空
bool QueueEmpty(LinkQueue* Q);

//入队
int EnQueue(LinkQueue*& Q, DataType &item);

//出队
int DeQueue(LinkQueue*& Q, DataType& item);

//遍历队列
int TraverseQueue(LinkQueue* Q);

//翻转队列
void RervseQueue(LinkQueue*& Q);
