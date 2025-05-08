#include "Stack.h"
#include <iostream>
using namespace std;

// 迷宫数组: 0表示通道，1表示墙
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

// 初始化栈
void InitStack(StType*& s) {
    s = new StType;
    s->top = -1;
}

// 判断是否空栈
bool EmptyStack(StType* s) {
    return(s->top == -1);
}

// 入栈
bool Push(StType*& s, Box& data) {
    // 栈满不进
    if (s->top == MaxSize - 1) {
        return false;
    }
    s->top++;
    s->data[s->top] = data;
    return true;
}

// 出栈
bool Pop(StType*& s, Box& e) {
    if (s->top == -1) {
        return false;
    }
    e = s->data[s->top];
    s->top--;
    return true;
}

// 取栈顶元素
bool GetTop(StType* s, Box& e) {
    if (s->top == -1) {
        cout << "栈空，无栈顶元素" << endl;
        return false;
    }
    e = s->data[s->top];
    return true;
}

// 销毁栈
void DestroyStack(StType*& s) {
    delete s;
}

// 找到所有迷宫路径
void FindAllPaths(int xi, int yi, int xe, int ye) {
    Box e;
    int i, j, di, il, jl;
    bool find;
    StType* st;
    InitStack(st);
    // 初始化起点

    e.i = xi; e.j = yi; e.di = -1;
    Push(st, e);
    mg[xi][yi] = -1; // 标记起点已访问

    // 开始搜索
    while (!EmptyStack(st)) {
        GetTop(st, e);
        i = e.i; j = e.j; di = e.di;

        // 找到终点
        if (i == xe && j == ye) {
            cout << "一条迷宫路径如下：" << endl;

            // 打印当前栈中的路径
            Box path[MaxSize * MaxSize];
            int k = 0;
            StType* tempSt = new StType;
            InitStack(tempSt);
            Box tempBox;

            // 保存栈中元素到临时栈
            while (!EmptyStack(st)) {
                Pop(st, tempBox);
                Push(tempSt, tempBox);
            }

            // 恢复原栈并同时保存路径到数组
            while (!EmptyStack(tempSt)) {
                Pop(tempSt, tempBox);
                Push(st, tempBox);
                path[k++] = tempBox;
            }

            // 打印路径
            for (int p = 0; p < k; p++) {
                cout << "\t(" << path[p].i << "," << path[p].j << ")";
                if ((p + 1) % 5 == 0) cout << endl;
            }
            cout << endl;

            // 不要在终点继续搜索，弹出终点并回溯
            Pop(st, e);
            mg[e.i][e.j] = 0; // 重置终点标记为未访问
            continue;
        }

        // 尝试四个方向
        find = false;
        while (di < 4 && !find) {
            di++;
            switch (di) {
            case 0: il = i - 1; jl = j; break; // 上
            case 1: il = i; jl = j + 1; break; // 右
            case 2: il = i + 1; jl = j; break; // 下
            case 3: il = i; jl = j - 1; break; // 左
            }
            if (il >= 0 && il < MaxSize && jl >= 0 && jl < MaxSize && mg[il][jl] == 0) 
            {
                find = true;
            }
        }

        if (find) {
            // 更新当前位置的方向信息
            st->data[st->top].di = di;
            // 前进到新位置
            e.i = il; e.j = jl; e.di = -1;
            Push(st, e);
            mg[il][jl] = -1; // 标记新位置已访问
        }
        else {
            // 回溯
            Pop(st, e);
            mg[e.i][e.j] = 0; // 重置当前位置标记为未访问
        }
    }
    DestroyStack(st);
}