#include"Stack.h"

int main()
{
    StackLink* s;
    DataType a[10],e;
    // 获取十个三位整数
    for (int i = 0; i < 10; i++)
        a[i] = GetRand();

    InitStack(s);
    PushArray(s, a, 10);
    while(Pop(s, e))
    {
        cout << "出栈的元素为" << e << endl;
    }
    
    cout << endl;
    string c;
    cout<<"请输入带圆括号的字符串，这可以检测圆括号是否合法" << endl;
    cin >> c;
    Parenlegal(c);
}
