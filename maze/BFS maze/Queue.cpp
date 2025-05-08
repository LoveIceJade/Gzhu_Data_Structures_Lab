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

// ��ʼ������
void InitQueue(QuType*& qu) 
{
    qu = new QuType;
    qu->front = qu->rear = 0;
}

// ���
bool enQueue(QuType*& qu, Box e) 
{
    if ((qu->rear + 1) % MaxSize == qu->front)
    {  // ������
        return false;
    }
    qu->data[qu->rear] = e;
    qu->rear = (qu->rear + 1) % MaxSize;
    return true;
}

// ���Ӳ���
bool deQueue(QuType*& qu, Box& e)
{
    if (qu->front == qu->rear) 
    {  // ���п�
        return false;
    }
    e = qu->data[qu->front];
    qu->front = (qu->front + 1) % MaxSize;
    return true;
}

// �������Ƿ�Ϊ��
bool QueueEmpty(QuType* qu) 
{
    return qu->front == qu->rear;
}

// ���ٶ���
void DestroyQueue(QuType*& qu)
{
    if (qu != nullptr) {
        delete qu;
        qu = nullptr;  // ��ֹ����ָ��
    }
}

// ������ȱ�����ȡ�Թ���̳�·
bool mepath(int xi, int yi, int xe, int ye)
{
    Box e;
    int i, j, di, il, jl;
    QuType* qu;
    InitQueue(qu);
    e.i = xi; e.j = yi; e.pre = -1;
    enQueue(qu, e);
    mg[xi][yi] = -1;  // �������ѷ���

    while (!QueueEmpty(qu))
    {
        deQueue(qu, e);
        i = e.i; j = e.j;

        if (i == xe && j == ye)  // �ҵ��յ�
        {
            dispapath(qu, e.pre);  // ��ȷ�����յ�ǰһ��λ�õ�����
            DestroyQueue(qu);
            return true;
        }

        for (di = 0; di < 4; di++)  // ����ĸ�����
        {
            switch (di)
            {
            case 0: il = i - 1; jl = j; break;    // ��
            case 1: il = i; jl = j + 1; break;    // ��
            case 2: il = i + 1; jl = j; break;    // ��
            case 3: il = i; jl = j - 1; break;    // ��
            }

            // ȷ����λ�����Թ�����δ����
            if (il >= 0 && il < MaxSize && jl >= 0 && jl < MaxSize && mg[il][jl] == 0)
            {
                e.i = il; e.j = jl;
                e.pre = qu->front - 1;  // ��ǰ�ڵ��ڶ����е�����
                enQueue(qu, e);
                mg[il][jl] = -1;  // ����ѷ���
            }
        }
    }

    DestroyQueue(qu);  // �ͷŶ���
    return false;  // û���ҵ�·��
}
// �Ӷ��� qu ���ҵ�һ���Թ�·�������
void dispapath(QuType* qu, int front)
{
    Box path[MaxSize];
    int p = front, k = 0, i;

    while (p != -1 && k < MaxSize)
    {
        path[k++] = qu->data[p];
        p = qu->data[p].pre;
    }

    // ��ѡ�����·�����ضϣ���Ӿ���
    if (p != -1) {
        cout << "���棺·��̫����ֻ��ʾǰ " << MaxSize << " ����\n";
    }

    cout << "һ���Թ�·������:\n";
    for (i = k - 1; i >= 0; i--)
    {
        cout << "\t(" << path[i].i << "," << path[i].j << ")";
        if ((k - i) % 5 == 0) cout << endl;
    }
    cout << endl;
}