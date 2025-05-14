#include <iostream>

using namespace std;

#define MAXV 7
#define INF 32767	
#define MAX_EDGES (MAXV * MAXV)  // �����ܵı���
typedef char DataType;
typedef int InfoType;

struct VertexType
{
	int no;            //������
	DataType info;     //��������
};

struct MatGraph
{
	int edges[MAXV][MAXV]; 	//�ڽӾ���
	int n;
	int e;  			    //������������
	VertexType vexs[MAXV];	//��Ŷ�����Ϣ
};

//�����ڽӱ�
struct ArcNode            //��
{
	int adjvex;           //�ñ��յ���
	ArcNode* nextaec;     //ָ����һ���ߵ�ָ��
	int weight;           //Ȩֵ������
};

struct VNode            //���
{
	DataType data;      //������Ϣ
	ArcNode* firstarc;  //ָ���һ����
};

struct AdjGraph
{
	VNode adjlist[MAXV];  //�����
	int n, e;            //�����Ͷ�����
};


//���н�㣨BFSʹ�ø����ݽṹ��
struct QueueNode
{
	InfoType data;
	QueueNode* next;
};

//���нṹ
struct Queue
{
	QueueNode* front;  //ָ��ͷ���
	QueueNode* rear;  //ָ��β���
};

//��ʼ������
void InitQueue(Queue*& qu);

//�ж϶����Ƿ�Ϊ��
bool EmptyQueue(Queue* qu);

//���һ��Ԫ��
bool enQueue(Queue*& qu, InfoType v);

//����һ��Ԫ��
bool deQueue(Queue*& qu, InfoType &w);

//����ͼ���ڽӱ�
void CreatGraph(AdjGraph*& G, int A[MAXV][MAXV], int n, int e);

//���ͼ
void PrintGraph(AdjGraph* G);

//����ͼ
void DestoryGraph(AdjGraph* G);

//������ȱ���
void DFS(AdjGraph* G, int v);

//������ȱ���
void BFS(AdjGraph* G, int v);

//���ڽӱ�תΪ�ڽӾ���
void AdjToMat(AdjGraph* AG, MatGraph*& MG);

//����ķ�㷨
void Prim(MatGraph G, int v);

struct Edge
{
	int v;   //���
	int w;   //�յ�
	int weight;   //Ȩ��
};

//ֱ������
void InsertSort(Edge E[], int n);

//��³˹�����㷨
void Kruskal(MatGraph G);

//���ͼ�����·��
void PrintPath(MatGraph G, int dist[], int path[], int S[], int v);

//��˹���ض��㷨
void Dijkstra(MatGraph G, int v);