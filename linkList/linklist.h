//这是声明数据类型和相应函数的文件
#include <iostream>
#include<ctime>
using namespace std;

typedef int DataType;

//获得一个随机三位整数
int GetRand();

typedef struct LNode
{
	DataType data;
	struct LNode* next;
}LinkNode;

//初始化单链表
void  InitList(LNode*& p);

//尾插法建立链表
void CreatList(LNode*& p, DataType a[], int n);

//遍历单链表
void TraveList(LNode* p);

//向单链表的指定位置插入元素
bool Listinsert(LNode*& p, int pos, DataType item);

//验证插入是否正确
bool TraveList_1(LNode*& p,int &pos,int &item);

//删除第一个与指定值匹配的元素
bool Delete_item(LNode*& p, DataType item);

//翻转链表
void ReserveList(LNode*& p);

//分割链表
void SplitList(LNode*& p, int value);
