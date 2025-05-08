#include "LinkQueue.h"

int main()
{
    int a[10], e=0;
    LinkQueue* q;
    //获取十个三位整数
    for (int i = 0; i < 10; i++)
    {
        a[i] = GetRand();
    }

    //初始化队列
    InitQueue(q);
    cout << endl;

    //将数据进队列
    for (int j = 0; j < 10; j++)
    {
        EnQueue(q, a[j]);
    }
    cout << endl;
    system("pause"); // 暂停

    //遍历队列
    TraverseQueue(q);
    cout << endl;
    system("pause"); // 暂停

    //翻转队列
    RervseQueue(q);

    //出列全部队列元素
    while (DeQueue(q,e));
    cout << endl;
}
