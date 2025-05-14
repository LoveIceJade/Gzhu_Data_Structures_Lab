#include <iostream>

using namespace std;

#define MAXV 7
#define INF 32767	
#define MAX_EDGES (MAXV * MAXV)  // 最大可能的边数
typedef char DataType;
typedef int InfoType;

struct VertexType
{
	int no;            //顶点编号
	DataType info;     //顶点数据
};

struct MatGraph
{
	int edges[MAXV][MAXV]; 	//邻接矩阵
	int n;
	int e;  			    //顶点数，边数
	VertexType vexs[MAXV];	//存放顶点信息
};

//以下邻接表
struct ArcNode            //边
{
	int adjvex;           //该边终点编号
	ArcNode* nextaec;     //指向下一条边的指针
	int weight;           //权值等数据
};

struct VNode            //结点
{
	DataType data;      //顶点信息
	ArcNode* firstarc;  //指向第一条边
};

struct AdjGraph
{
	VNode adjlist[MAXV];  //顶点表
	int n, e;            //边数和顶点数
};


//队列结点（BFS使用该数据结构）
struct QueueNode
{
	InfoType data;
	QueueNode* next;
};

//队列结构
struct Queue
{
	QueueNode* front;  //指向头结点
	QueueNode* rear;  //指向尾结点
};

//初始化队列
void InitQueue(Queue*& qu);

//判断队列是否为空
bool EmptyQueue(Queue* qu);

//入队一个元素
bool enQueue(Queue*& qu, InfoType v);

//出队一个元素
bool deQueue(Queue*& qu, InfoType &w);

//创建图的邻接表
void CreatGraph(AdjGraph*& G, int A[MAXV][MAXV], int n, int e);

//输出图
void PrintGraph(AdjGraph* G);

//销毁图
void DestoryGraph(AdjGraph* G);

//深度优先遍历
void DFS(AdjGraph* G, int v);

//广度优先遍历
void BFS(AdjGraph* G, int v);

//将邻接表转为邻接矩阵
void AdjToMat(AdjGraph* AG, MatGraph*& MG);

//普利姆算法
void Prim(MatGraph G, int v);

struct Edge
{
	int v;   //起点
	int w;   //终点
	int weight;   //权重
};

//直插排序法
void InsertSort(Edge E[], int n);

//克鲁斯卡尔算法
void Kruskal(MatGraph G);

//输出图的最短路径
void PrintPath(MatGraph G, int dist[], int path[], int S[], int v);

//迪斯卡特尔算法
void Dijkstra(MatGraph G, int v);