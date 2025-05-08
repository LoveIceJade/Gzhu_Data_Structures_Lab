#include"linklist.h"

int main()
{

    srand(time(0));
    LNode* p = NULL;
    int a[10],b,c;

    //获取十个三位整数
    for (int i = 0; i < 10; i++)
    {
        a[i] = GetRand();
    }

    InitList(p); //初始化单链表
    CreatList(p, a, 10); //将数据导入单链表
    TraveList(p);  //遍历单链表

    cout << endl;
    //将一个数据插入单链表并遍历是否成功
    cout << "分别输入要插入的数据和位置：" ;
    cin >> b >> c;
    Listinsert(p, c, b);
    TraveList_1(p, c, b);
    system("pause"); // 暂停

    cout << endl;
    //删除单链表
    cout << "输入要删除的数据：";
    cin >> b;
    Delete_item(p,b);
    TraveList(p);  //遍历单链表
    system("pause"); // 暂停

    cout << endl;
    ReserveList(p);  //翻转单链表
    TraveList(p);  //遍历单链表
}




/* 根据基准值将链表分段

int main()
{
    srand(time(0));
    LNode* p = NULL;
    int a[10], b, c;

    //获取十个三位整数
    for (int i = 0; i < 10; i++)
    {
        a[i] = GetRand();
    }

    InitList(p); //初始化单链表
    CreatList(p, a, 10); //将数据导入单链表
    TraveList(p);  //遍历单链表

    int value;
    cout << "请输入基准值：";
    cin >> value;
    SplitList(p, value);
    TraveList(p);
}
*/
