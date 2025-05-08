#include "Stack.h"
#include <iostream>
using namespace std;

// �Թ�����: 0��ʾͨ����1��ʾǽ
int mg[10][10] = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
    { 1, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
    { 1, 0, 0, 0, 0, 1, 1, 0, 0, 1 },
    { 1, 0, 1, 1, 1, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
    { 1, 0, 1, 0, 0, 0, 1, 0, 0, 1 },
    { 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
    { 1, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};

// ��ʼ��ջ
void InitStack(StType*& s) {
    s = new StType;
    s->top = -1;
}

// �ж��Ƿ��ջ
bool EmptyStack(StType* s) {
    return(s->top == -1);
}

// ��ջ
bool Push(StType*& s, Box& data) {
    // ջ������
    if (s->top == MaxSize - 1) {
        return false;
    }
    s->top++;
    s->data[s->top] = data;
    return true;
}

// ��ջ
bool Pop(StType*& s, Box& e) {
    if (s->top == -1) {
        return false;
    }
    e = s->data[s->top];
    s->top--;
    return true;
}

// ȡջ��Ԫ��
bool GetTop(StType* s, Box& e) {
    if (s->top == -1) {
        cout << "ջ�գ���ջ��Ԫ��" << endl;
        return false;
    }
    e = s->data[s->top];
    return true;
}

// ����ջ
void DestroyStack(StType*& s) {
    delete s;
}

// �ҵ������Թ�·��
void FindAllPaths(int xi, int yi, int xe, int ye) {
    Box e;
    int i, j, di, il, jl;
    bool find;
    StType* st;
    InitStack(st);
    // ��ʼ�����

    e.i = xi; e.j = yi; e.di = -1;
    Push(st, e);
    mg[xi][yi] = -1; // �������ѷ���

    // ��ʼ����
    while (!EmptyStack(st)) {
        GetTop(st, e);
        i = e.i; j = e.j; di = e.di;

        // �ҵ��յ�
        if (i == xe && j == ye) {
            cout << "һ���Թ�·�����£�" << endl;

            // ��ӡ��ǰջ�е�·��
            Box path[MaxSize * MaxSize];
            int k = 0;
            StType* tempSt = new StType;
            InitStack(tempSt);
            Box tempBox;

            // ����ջ��Ԫ�ص���ʱջ
            while (!EmptyStack(st)) {
                Pop(st, tempBox);
                Push(tempSt, tempBox);
            }

            // �ָ�ԭջ��ͬʱ����·��������
            while (!EmptyStack(tempSt)) {
                Pop(tempSt, tempBox);
                Push(st, tempBox);
                path[k++] = tempBox;
            }

            // ��ӡ·��
            for (int p = 0; p < k; p++) {
                cout << "\t(" << path[p].i << "," << path[p].j << ")";
                if ((p + 1) % 5 == 0) cout << endl;
            }
            cout << endl;

            // ��Ҫ���յ���������������յ㲢����
            Pop(st, e);
            mg[e.i][e.j] = 0; // �����յ���Ϊδ����
            continue;
        }

        // �����ĸ�����
        find = false;
        while (di < 4 && !find) {
            di++;
            switch (di) {
            case 0: il = i - 1; jl = j; break; // ��
            case 1: il = i; jl = j + 1; break; // ��
            case 2: il = i + 1; jl = j; break; // ��
            case 3: il = i; jl = j - 1; break; // ��
            }
            if (il >= 0 && il < MaxSize && jl >= 0 && jl < MaxSize && mg[il][jl] == 0) 
            {
                find = true;
            }
        }

        if (find) {
            // ���µ�ǰλ�õķ�����Ϣ
            st->data[st->top].di = di;
            // ǰ������λ��
            e.i = il; e.j = jl; e.di = -1;
            Push(st, e);
            mg[il][jl] = -1; // �����λ���ѷ���
        }
        else {
            // ����
            Pop(st, e);
            mg[e.i][e.j] = 0; // ���õ�ǰλ�ñ��Ϊδ����
        }
    }
    DestroyStack(st);
}