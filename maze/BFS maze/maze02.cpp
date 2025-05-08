#include"Queue.h"


int main()
{
    int xi = 1, yi = 1, xe = 8, ye = 8;  // 起点和终点
    if (!mepath(xi, yi, xe, ye))
    {
        cout << "没有找到路径！" << endl;
    }
    return 0;
}