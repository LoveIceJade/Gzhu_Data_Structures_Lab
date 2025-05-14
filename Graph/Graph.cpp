#include"Graph.h"

bool visited[MAXV];

//初始化队列
void InitQueue(Queue*& qu)
{
	qu = new Queue;
	qu->front = qu->rear = nullptr;
}

//判断队列是否为空
bool EmptyQueue(Queue* qu)
{
	return(qu->rear==nullptr);
}

//入队一个元素
bool enQueue(Queue*& qu, InfoType v)
{
	QueueNode* Node = new QueueNode;
	Node->data = v;
	Node->next = nullptr;
	if (EmptyQueue(qu))
		qu->front = qu->rear = Node;
	else
	{
		qu->rear->next = Node;
		qu->rear = Node;
	}
	return true;
}

//出队一个元素
bool deQueue(Queue*& qu, InfoType &w)
{
	if (EmptyQueue(qu))
		return false;
	w = qu->front->data;
	if (qu->front == qu->rear)
		qu->front = qu->rear = nullptr;
	else
		qu->front = qu->front->next;
	return true;
}

//创建图的邻接表
void CreatGraph(AdjGraph*& G, int A[MAXV][MAXV], int n, int e)
{
	int i, j;
	ArcNode* p;
	G = new AdjGraph;
	for (i = 0; i < n; i++)
		G->adjlist[i].firstarc = nullptr;
	for (i = 0; i < n; i++)  //检查邻接矩阵每个元素
	{
		for (j = n - 1; j >= 0; j--)
		{
			if (A[i][j] != 0 && A[i][j]<INF)  //存在一条边
			{
				p = new ArcNode;  //创建一个结点
				p->adjvex = j;    //储存终点
				p->weight = A[i][j];  //储存权值
				p->nextaec = G->adjlist[i].firstarc;  //头插法创建结点p
				G->adjlist[i].firstarc = p;
			}
		}
		G->n = n;
		G->e = e;
	}
}

//输出图
void PrintGraph(AdjGraph* G)
{
	ArcNode* p;
	for (int i=0; i < G->n; i++)  //遍历全部结点
	{
		p = G->adjlist[i].firstarc;  //p指向结点指向的第一条边
		cout << i << ": ";
		while (p != nullptr)   //边存在
		{
			cout << p->adjvex << "[" << p->weight << "]  ";  //输出这条边的编号和权重
			p = p->nextaec;  //指向p指向的下一条边，直至p指向的下一条边不存在
		}
		cout << "∧" << endl;  //输出终止符号，并换行，进行下个结点的遍历
	}
}

//销毁图
void DestoryGraph(AdjGraph* G)
{
	ArcNode* pre, * p;
	for (int i=0 ; i < G->n; i++)  //先释放所有结点的边
	{
		pre = G->adjlist[i].firstarc;
		if (pre != nullptr)  //如果边存在
		{
			p = pre->nextaec;  //令p指向pre指向的下一条边
			while (p != nullptr)  //p存在
			{
				delete pre;  //释放上一条边
				pre = p;  //令pre和p各进一步
				p = p->nextaec;
			}
			delete pre;  //释放pre
		}
	}
	delete G;  //释放所有结点
}

//深度优先遍历
void DFS(AdjGraph* G, int v)
{
	ArcNode* p = G->adjlist[v].firstarc;
	int w;
	visited[v] = 1;  //标记为已访问
	cout << v << "  ";     //输出顶点v

	while (p != nullptr)
	{
		w = p->adjvex;
		if (visited[w] == 0)
			DFS(G, w);
		p = p->nextaec;
	}
}

//广度优先遍历
void BFS(AdjGraph* G, int v)
{
	//创建队列方便后面计算
	Queue* qu;
	InitQueue(qu);  

	int w;  //作为出队元素方便后续操作
	ArcNode* p;

	//创建bool数组标记节点是否已访问
	bool visited[MAXV];
	for (int i = 0; i < G->n; i++)
		visited[i] = false;

	//访问v并进队
	cout << v << "  ";   
	visited[v] = true;
	enQueue(qu, v);

	while (!EmptyQueue(qu))
	{
		deQueue(qu, w);
		p = G->adjlist[w].firstarc;

		while (p != nullptr)
		{
			if (visited[p->adjvex] == false)
			{
				cout << p->adjvex << "  ";
				visited[p->adjvex] = true;
				enQueue(qu, p->adjvex);
			}
			p = p->nextaec;
		}
	}
	cout << endl;
}

void AdjToMat(AdjGraph* AG, MatGraph*& MG)
{
	int i, j;
	ArcNode* p;
	MG = new MatGraph;               // 动态分配邻接矩阵
	MG->n = AG->n;                   // 顶点数
	MG->e = AG->e;                   // 边数

	// 初始化邻接矩阵，所有元素设为 INF 或 0
	for (i = 0; i < MG->n; i++) {
		for (j = 0; j < MG->n; j++) {
			if (i == j)              // 对角线初始化为 0
				MG->edges[i][j] = 0;
			else
				MG->edges[i][j] = INF;  // 其他元素初始化为无穷大
		}

		// 如果MatGraph结构中有顶点信息存储，则拷贝顶点信息
		if (AG->n > 0) {
			MG->vexs[i].info = AG->adjlist[i].data;  // 拷贝顶点信息
		}
	}

	// 遍历邻接表
	for (i = 0; i < AG->n; i++) {
		p = AG->adjlist[i].firstarc;  // 指向顶点 i 的第一条边
		while (p != nullptr) {
			MG->edges[i][p->adjvex] = p->weight;  // 填入权值
			p = p->nextaec;          // 访问下一条边（修正拼写错误）
		}
	}
}


//普利姆算法
void Prim(MatGraph G, int v)
{
	int lowcost[MAXV];  //存储顶点到U的最小边
	int closest[MAXV];  //存储记录最小边对应的顶点

	int min, i, j, k;

	for (i = 0; i < G.n; i++)	//给lowcost[]和closest[]置初值
	{
		lowcost[i] = G.edges[v][i];
		closest[i] = v;
	}

	for (i = 1; i < G.n; i++)	  	//输出(n-1)条边
	{
		min = INF;
		for (j = 0; j < G.n; j++) 	//在(V-U)中找出离U最近的顶点k
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;			//k记录最近顶点编号
			}
		
		cout << "边(" << closest[k] << "," << k << ")的权重为" << min << endl;
		lowcost[k] = 0;		//将k加入V中，距离变为0
		for (j = 0; j < G.n; j++)  //修改数组lowcost和closest
			if (lowcost[j] != 0 && G.edges[k][j] < lowcost[j])
			{
				lowcost[j] = G.edges[k][j];
				closest[j] = k;
			}
	}
}

//直插排序法
void InsertSort(Edge E[], int n)
{
	Edge temp;
	int i, j;
	for (i = 1; i < n; i++)
		if (E[i].weight < E[i - 1].weight)
		{
			temp = E[i];
			j = i - 1;
			do
			{
				E[j + 1] = E[j];
				j--;
			} while (j >= 0 && temp.weight < E[j].weight);
			E[j + 1] = temp;
		}
}

//克鲁斯卡尔算法
void Kruskal(MatGraph G)
{
	int i, j;

	//辅助数组的初始化
	int vex[MAXV];
	for (i = 0; i < G.n; i++)
		vex[i] = i;

	//存放所有边的数组的初始化及排序
	Edge E[MAXV * MAXV];
	int k = 0;
	for (i = 0; i < G.n; i++)
		for (j = 0; j < G.n; j++)
			if (G.edges[i][j] != 0 && G.edges[i][j] != INF)
			{
				E[k].v = i;
				E[k].w = j;
				E[k].weight = G.edges[i][j];
				k++;
			}

	InsertSort(E, G.e); // 直插排序法

	k = 1;   //表示：当前构造树的第k条边，初始为1
	j = 0;   //表示：E中边的下标，初始为0
	int vl, wl;   //标记一条边的两个顶点
	int sn1, sn2;   //标记vl和wl所属的顶点编号

	while (k < G.n) // 生成的边数少于n时循环
	{
		vl = E[j].v;
		wl = E[j].w;     //取出一条边的两个顶点
		sn1 = vex[vl];
		sn2 = vex[wl];   //标记这条边的顶点编号
		if (sn1 != sn2)  // 如果两个顶点不在同一个连通分量中，则选择这条边
		{
			cout << "(" << vl << "," << wl << ")" << endl;
			k++;
			for (i = 0; i < G.n; i++)  //统一编号，将所有属于sn2的顶点改为sn1
				if (vex[i] == sn2)
					vex[i] = sn1;
		}
		j++;  //遍历下一条边
	}
}

//输出图的最短路径
void PrintPath(MatGraph G, int dist[], int path[], int S[], int v)
{
	int i, j, k;
	int aPath[MAXV], d;
	for (i = 0; i < G.n; i++)
	{
		if (S[i] == 1 && i != v)
		{
			cout << "从顶点" << v << "到顶点" << i << "的路径长度为" << dist[i] << endl;
			d = 0; aPath[d] = i;
			k = path[i];
			if (k == -1)
				cout << "无路径" << endl;
			else
			{
				cout << "路径为：" << v;  // 直接打印起点v
				while (k != v)
				{
					d++; aPath[d] = k;  // 存储中间节点k，而不是v
					k = path[k];
				}
				for (j = d; j >= 0; j--)  // 从d开始，包含所有中间节点
					cout << "," << aPath[j];
				cout << endl;
			}
		}
	}
}

//迪杰斯特拉算法
void Dijkstra(MatGraph G, int v)
{
	int dist[MAXV], path[MAXV];
	int S[MAXV];    //S[i]=1表示顶点i在S中，S[i]=0表示顶点i在U中
	int mindist, i, j, u;
	for (i = 0; i < G.n; i++)
	{
		dist[i] = G.edges[v][i];  //距离初始化
		S[i] = 0;  //S[]置空
		if (G.edges[v][i] < INF)  //路径初始化
			path[i] = v;  //存在边时将顶点i的前一个顶点置为v
		else
			path[i] = -1;   //不存在时则置为-1
	}
	S[v] = 1; path[v] = v;
	for (i = 0; i < G.n - 1; i++)  //循环，直至所有顶点的最短路径都求出
	{
		mindist = INF;
		u = -1;  // 初始化u，防止没有找到最小距离顶点时出现未定义行为
		for (j = 0; j < G.n; j++)
			if (S[j] == 0 && dist[j] < mindist)  // 修复条件判断
			{
				u = j;  //将j的值储存到u中
				mindist = dist[j];
			}

		if (u == -1) break;  // 如果没有找到可达的顶点则退出循环

		S[u] = 1;
		for (j = 0; j < G.n; j++)
			if (S[j] == 0)
				if (G.edges[u][j] < INF && dist[u] + G.edges[u][j] < dist[j])
				{
					dist[j] = dist[u] + G.edges[u][j];
					path[j] = u;
				}
	}
	PrintPath(G, dist, path, S, v);
}