#include<iostream>
#include<cstring>
using namespace std;

#define CharSize 10
#define MAXNODE 7      //  顶点数，至关重要！下面所有函数、结构体默认顶点数为MAXNODE，不再在结构体里单独列出顶点数n！！！
#define INF 32767

//  下面是邻接表存储
struct DestinationCity         //  目标城市（邻接表的链表结点，即边结点）
{
	int no;                    //  该城市的编号
	char cityName[CharSize];          //  该城市的名字

	int minCost;               //  出发点城市到该城市的最少花费
	int minDistance;           //  出发点城市到该城市的最短里程
	double minTime;            //  出发点城市到该城市的最短时间
	int minTrans;              //  出发点城市到该城市的最少中转次数

	DestinationCity* nextArc;  //  指向下一个结点
};

struct OriginCity               //  出发点城市（邻接表的头结点）
{
	int no;                     //  该城市的编号
	char cityName[CharSize];           //  该城市的名字
	DestinationCity* firstArc;  //  指向第一个边结点
};

struct CityGraph
{
	//  经过弗洛伊德算法后存储对应最优路径
	int pathDist[MAXNODE][MAXNODE];
	int pathCost[MAXNODE][MAXNODE];
	int pathTime[MAXNODE][MAXNODE];
	int pathTrans[MAXNODE][MAXNODE];

	OriginCity cityList[MAXNODE];  //邻接表的头结点数组
};



//  下面为函数区

//  首页菜单
void FirstMenu();

//  次一页菜单
void SecondMenu(CityGraph& G, int &input);

//第三页菜单(找到一个城市的遍历其他所有城市的一条最优路径)
void ThirdMenu(CityGraph& G, int dist[MAXNODE][MAXNODE], int cost[MAXNODE][MAXNODE], double time0[MAXNODE][MAXNODE]);

//  Floyd算法求出最短里程、最少花费以及最短时间的数组及其路径
CityGraph FloydAndInitGraph(int CityNo[MAXNODE], char cityName[MAXNODE][CharSize], int dist[MAXNODE][MAXNODE], int cost[MAXNODE][MAXNODE], double time[MAXNODE][MAXNODE]);

//  查找算法
bool Search(CityGraph& G, char start[], char end[], int n);

//  展示路径
void DispPath(CityGraph& G, int path[MAXNODE][MAXNODE], int startNo, int endNo);
void DisplayPath(CityGraph& G, int path[MAXNODE][MAXNODE], int startNo, int endNo, bool& isFirstNode);

//  下面是附加功能：根据一个原点找到一条可以遍历其他所有城市的最优路径

//  因为时间带有小数，所以不能合并成一条函数
//  根据输入的城市找到他在矩阵终点编号（不是城市编号，而是城市编号-1）
int SearchNo(CityGraph& G, char input[5]);

//  核心：Dijkstra算法
//  两个函数完全一样，只是参数不同
template <typename T>
bool DijkstraOptimalPath(CityGraph& G, T A[MAXNODE][MAXNODE]);