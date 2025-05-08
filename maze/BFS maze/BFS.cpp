#include "Queue.h"

int mg[10][10] =
{
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } ,
{ 1, 0, 0, 1, 0, 0, 0, 1, 0, 1 } ,
{ 1, 0, 0, 1, 0, 0, 0, 1, 0, 1 } ,
{ 1, 0, 0, 0, 0, 1, 1, 0, 0, 1 } ,
{ 1, 0, 1, 1, 1, 0, 0, 0, 0, 1 } ,
{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 1 } ,
{ 1, 0, 1, 0, 0, 0, 1, 0, 0, 1 } ,
{ 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 } ,
{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 1 } ,
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } ,
};

// 初始化队列
void InitQueue(QuType*& qu) 
{
    qu = new QuType;
    qu->front = qu->rear = 0;
}

// 入队
bool enQueue(QuType*& qu, Box e) 
{
    if ((qu->rear + 1) % MaxSize == qu->front)
    {  // 队列满
        return false;
    }
    qu->data[qu->rear] = e;
    qu->rear = (qu->rear + 1) % MaxSize;
    return true;
}

// 出队操作
bool deQueue(QuType*& qu, Box& e)
{
    if (qu->front == qu->rear) 
    {  // 队列空
        return false;
    }
    e = qu->data[qu->front];
    qu->front = (qu->front + 1) % MaxSize;
    return true;
}

// 检查队列是否为空
bool QueueEmpty(QuType* qu) 
{
    return qu->front == qu->rear;
}

// 销毁队列
void DestroyQueue(QuType*& qu)
{
    if (qu != nullptr) {
        delete qu;
        qu = nullptr;  // 防止悬挂指针
    }
}

// 广度优先遍历获取迷宫最短出路
bool mepath(int xi, int yi, int xe, int ye)
{
    Box e;
    int i, j, di, il, jl;
    QuType* qu;
    InitQueue(qu);
    e.i = xi; e.j = yi; e.pre = -1;
    enQueue(qu, e);
    mg[xi][yi] = -1;  // 标记起点已访问

    while (!QueueEmpty(qu))
    {
        deQueue(qu, e);
        i = e.i; j = e.j;

        if (i == xe && j == ye)  // 找到终点
        {
            dispapath(qu, e.pre);  // 正确传递终点前一个位置的索引
            DestroyQueue(qu);
            return true;
        }

        for (di = 0; di < 4; di++)  // 检查四个方向
        {
            switch (di)
            {
            case 0: il = i - 1; jl = j; break;    // 上
            case 1: il = i; jl = j + 1; break;    // 右
            case 2: il = i + 1; jl = j; break;    // 下
            case 3: il = i; jl = j - 1; break;    // 左
            }

            // 确保新位置在迷宫内且未访问
            if (il >= 0 && il < MaxSize && jl >= 0 && jl < MaxSize && mg[il][jl] == 0)
            {
                e.i = il; e.j = jl;
                e.pre = qu->front - 1;  // 当前节点在队列中的索引
                enQueue(qu, e);
                mg[il][jl] = -1;  // 标记已访问
            }
        }
    }

    DestroyQueue(qu);  // 释放队列
    return false;  // 没有找到路径
}
// 从队列 qu 中找到一条迷宫路径并输出
void dispapath(QuType* qu, int front)
{
    Box path[MaxSize];
    int p = front, k = 0, i;

    while (p != -1 && k < MaxSize)
    {
        path[k++] = qu->data[p];
        p = qu->data[p].pre;
    }

    // 可选：如果路径被截断，添加警告
    if (p != -1) {
        cout << "警告：路径太长，只显示前 " << MaxSize << " 步。\n";
    }

    cout << "一条迷宫路径如下:\n";
    for (i = k - 1; i >= 0; i--)
    {
        cout << "\t(" << path[i].i << "," << path[i].j << ")";
        if ((k - i) % 5 == 0) cout << endl;
    }
    cout << endl;
}
