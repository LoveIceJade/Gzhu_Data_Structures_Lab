#include"Graph.h"

int main()
{
    //将图转换为数组
	int A[MAXV][MAXV] = 
{ 
    { 0, 28,  0,  0,  0, 10,  0 },
    {28,  0, 16,  0,  0,  0, 14 },
    { 0, 16,  0, 12,  0,  0, 18 },
    { 0,  0, 12,  0, 22,  0, 18 },
    { 0,  0,  0, 22,  0, 25, 24 },
    {10,  0,  0,  0, 25,  0,  0 },
    { 0, 14, 18, 18, 24,  0,  0 }
};
    //输入边数和顶点数
	int n = MAXV, e = 9;
    //创建图并打印
	AdjGraph* AG;
	CreatGraph(AG, A, n, e);
    cout << "下面是邻接表：" << endl;
    PrintGraph(AG);

    cout << endl;
    //深度优先遍历
    cout << "下面是深度优先算法：" << endl;
    DFS(AG, 0);
    cout << endl;

    //广度优先遍历
    cout << "下面是广度优先算法：" << endl;
    BFS(AG, 0);
    cout << endl;

    //将邻接表转换为邻接矩阵后删除
    MatGraph *MG;
    AdjToMat(AG, MG);
    DestoryGraph(AG);
 
    //普利姆算法
    cout << "下面是普利姆算法：" << endl;
    Prim(*MG, 0);
    cout << endl;

    //克鲁斯卡尔算法
    cout << "下面是卡鲁斯卡尔算法：" << endl;
    Kruskal(*MG);
    cout << endl;

    ////迪斯卡特尔算法
   cout << "下面是迪斯卡特尔算法：" << endl;
   Dijkstra(*MG, 0);

}