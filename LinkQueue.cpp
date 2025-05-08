#include"LinkQueue.h"

//获得一个随机三位整数
int GetRand()
{
	return(rand() % 900 + 100);
}

//初始化带头结点的链队列
void InitQueue(LinkQueue*& Q)
{
	Q = new LinkQueue;
	Q->front = Q->rear = nullptr;
	cout << "链队初始化成功" << endl;
}

//判链队列空
bool QueueEmpty(LinkQueue* Q)
{
	if (Q->rear == nullptr)
	{
		cout << "链队为空" << endl;
		return true;
	}
	cout << "链队非空" << endl;
	return(false);
}

//入队
int EnQueue(LinkQueue*& Q, DataType &item)
{
	QNode* p = new QNode;  //创建新结点
	p->data = item;
	p->next = nullptr;
	if (Q->rear == nullptr)  //若队列为空，则新结点既是首结点又是尾结点
		Q->front = Q->rear = p;
	else
	{
		Q->rear->next = p;
		Q->rear = p;
	}
	cout << "数据  " << item << "  已经入队成功" << endl;
	return 1;
}

//出队
int DeQueue(LinkQueue*& Q, DataType& item)
{
	if (Q->rear == nullptr)
	{
		// 调试时可取消注释
		// cout << "队列为空，出队失败" << endl;
		return 0;
	}
	QNode* t = Q->front;
	if (Q->front == Q->rear)
		Q->front = Q->rear = nullptr;
	else
		Q->front = Q->front->next;
	item = t->data;
	delete t;
	cout << "出队成功，已出队的数据为" << item << endl;
	return 1;
}


//遍历队列
int TraverseQueue(LinkQueue* Q)
{
	QNode* p = Q->front;
	if (p == nullptr)
	{
		cout << "该队列为空" << endl;
		return 0;
	}
	int i = 1;
	while (p!=nullptr)
	{
		cout << "队列的第" << i << "个数据为" << p->data << endl;
		p = p->next;
		i++;
	}
	cout << "该队列已遍历完成" << endl;
	return 1;
}

//翻转队列
void RervseQueue(LinkQueue*& Q)
{
	if (Q->front == nullptr || Q->front->next == nullptr)
	{
		cout << "该队列为空或只有一个元素，无需翻转" << endl;
		return;
	}

	QNode* prev = nullptr;
	QNode* current = Q->front;
	QNode* next = nullptr;

	// 逐个反转节点的指向
	while (current != nullptr) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	// 交换 front 和 rear
	Q->rear = Q->front;
	Q->front = prev;

	cout << "队列翻转完成！" << endl;
}