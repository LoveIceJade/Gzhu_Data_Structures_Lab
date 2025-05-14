#include"ClassProgramFinal.h"

// strcpy_s First

//  首页功能菜单
void FirstMenu()
{

	cout << "\t======= 城市路径查询系统 =======" << endl;
	cout << "\t1.查询最短里程" << endl;
	cout << "\t2.查询最低花费" << endl;
	cout << "\t3.查询最短时间" << endl;
	cout << "\t4.查询最少中转次数" << endl;
	cout << "\t5.查询逛遍其他所有城市的最优路径" << endl;
	cout << "\t0.退出系统" << endl;
	cout << "\t================================" << endl;
	cout << endl;

	cout << "请输入您要实现的功能：";
}

//  二级菜单
void SecondMenu(CityGraph& G, int& input)
{

	if (input < 0 || input > 4)
	{
		cout << "请输入正确的数字！请重新输出！" << endl;
		return;
	}

	cout << "你想从哪里出发：";
	char start[CharSize];
	cin >> start;
	char end[CharSize];
	cout << "你想去哪里：";
	cin >> end;
	cout << endl;

	while (!Search(G, start, end, input))
	{
		cout << endl;
		cout << "请重新输入！输入0则退出系统" << endl;
		cout << endl;

		cout << "你想从哪里出发：";
		cin >> start;
		if (!strcmp(start, "0"))  // 如果start=0，则退出
		{
			input = 0;
			return;
		}
		cout << "你想去哪里：";
		cin >> end;
		if (!strcmp(end,"0"))
		{
			input = 0;
			return;
		}
		cout << endl;
	}

	cout << endl;
}

//第三页菜单
void ThirdMenu(CityGraph& G, int dist[MAXNODE][MAXNODE], int cost[MAXNODE][MAXNODE], double time0[MAXNODE][MAXNODE]) 
{
	while (true) 
	{
		system("cls");
		cout << "\t======= 选择以何种条件优先 =======" << endl;
		cout << "\t=========== 1. 距离优先 ==========" << endl;
		cout << "\t=========== 2. 花销优先 ==========" << endl;
		cout << "\t=========== 3. 时间优先 ==========" << endl;
		cout << "\t=========== 0. 退出系统 ==========" << endl;
		cout << "\t==================================" << endl;
		cout << "请输入你想实现的功能的数字：" ;
		int input;
		cin >> input;

		switch (input)
		{
		case 1:
			DijkstraOptimalPath(G, dist);
			break;
		case 2:
			DijkstraOptimalPath(G, cost);
			break;
		case 3:
			DijkstraOptimalPath(G, time0);
			break;
		case 0:
			return; // 返回上级菜单
		default:
			cout << "输入错误！请重新输入。" << endl;
			system("pause");
			break;
		}
		system("pause");
		system("cls");
	}
}


CityGraph InitGraph(CityGraph& G,int cityNo[MAXNODE], char cityName[][CharSize], int dist[][MAXNODE], int cost[][MAXNODE], double time[][MAXNODE],int trans[][MAXNODE], int pathDist[][MAXNODE],int pathCost[][MAXNODE],int pathTime[][MAXNODE],int pathTrans[][MAXNODE])
{
	int i, j;

	for (i = 0; i < MAXNODE; i++)  //初始化城市名字与编号
	{
		strcpy_s(G.cityList[i].cityName, cityName[i]);
		G.cityList[i].no = cityNo[i];
	}

	for (i = 0; i < MAXNODE; i++)
	{  
		G.cityList[i].firstArc = nullptr;  //  初始化头指针为空
		DestinationCity* p = nullptr;

		for (j = 0; j < MAXNODE; j++)
		{
			//  复制path系列数组，输出路径时使用
			G.pathDist[i][j] = pathDist[i][j];
			G.pathCost[i][j] = pathCost[i][j];
			G.pathTime[i][j] = pathTime[i][j];
			G.pathTrans[i][j] = pathTrans[i][j];

			if (i != j && dist[i][j] != INF)  //  判断是否可达
			{
				DestinationCity* newCity = new DestinationCity;
				newCity->no = cityNo[j];
				strcpy_s(newCity->cityName, cityName[j]);
				newCity->minCost = cost[i][j];
				newCity->minDistance = dist[i][j];
				newCity->minTime = time[i][j];
				newCity->minTrans = trans[i][j];
				newCity->nextArc = nullptr;

				if (G.cityList[i].firstArc == nullptr)  //  如果头指针为空，则查到头指针这
					G.cityList[i].firstArc = newCity;
				else                                    //  否则插在p后面
					p->nextArc = newCity;
				p = newCity;                            //  指针p指向newCity
			}
		}
	}
	return G;
}

//  Floyd算法求出最短里程、最少花费以及最短时间的数组及其路径
CityGraph FloydAndInitGraph(int cityNo[MAXNODE], char cityName[MAXNODE][CharSize], int dist[MAXNODE][MAXNODE], int cost[MAXNODE][MAXNODE], double time[MAXNODE][MAXNODE])
{
	int edgesDistance[MAXNODE][MAXNODE], edgesCost[MAXNODE][MAXNODE], edgesTrans[MAXNODE][MAXNODE];
	double edgesTime[MAXNODE][MAXNODE];
	int pathDist[MAXNODE][MAXNODE], pathCost[MAXNODE][MAXNODE], pathTime[MAXNODE][MAXNODE], pathTrans[MAXNODE][MAXNODE];  //  路径数组
	int i, j, k;

	for (i = 0; i < MAXNODE; i++)   //复制dist等数组到edges等数组里
		for (j = 0; j < MAXNODE; j++)
		{
			edgesDistance[i][j] = dist[i][j];
			edgesCost[i][j] = cost[i][j];
			edgesTime[i][j] = time[i][j];

			if (i == j)
				edgesTrans[i][j] = 0;
			else if (dist[i][j] == INF)
				edgesTrans[i][j] = INF;
			else
				edgesTrans[i][j] = 1;
		}

	for (i = 0; i < MAXNODE; i++) //  初始化path系列数组
		for (j = 0; j < MAXNODE; j++)
		{
			if (i != j && edgesDistance[i][j] < INF)  //  因为一项数据存在，其他的数据也存在，故只需要比较其中一项数据即可
				pathDist[i][j] = pathCost[i][j] = pathTime[i][j] = pathTrans[i][j] = i;   //i到j有边时
			else
				pathDist[i][j] = pathCost[i][j] = pathTime[i][j] = pathTrans[i][j] = -1;  //i到j无边时
		}

	for (k = 0; k < MAXNODE; k++)         // 中间城市
	{
		for (i = 0; i < MAXNODE; i++)     // 出发城市
		{
			for (j = 0; j < MAXNODE; j++) // 目标城市
			{
				// 计算最短距离
				if (edgesDistance[i][j] > edgesDistance[i][k] + edgesDistance[k][j])
				{
				    edgesDistance[i][j] = edgesDistance[i][k] + edgesDistance[k][j];
					pathDist[i][j] = pathDist[k][j];
				}

				// 计算最少花费
				if (edgesCost[i][j] > edgesCost[i][k] + edgesCost[k][j])
				{
					edgesCost[i][j] = edgesCost[i][k] + edgesCost[k][j];
					pathCost[i][j] = pathCost[k][j];
				}

				// 计算最短时间
				if (edgesTime[i][j] > edgesTime[i][k] + edgesTime[k][j])
				{
					edgesTime[i][j] = edgesTime[i][k] + edgesTime[k][j];
					pathTime[i][j] = pathTime[k][j];
				}

				// 计算最少中转次数
				if (edgesTrans[i][j] > edgesTrans[i][k] + edgesTrans[k][j])
				{
					edgesTrans[i][j] = edgesTrans[i][k] + edgesTrans[k][j];
					pathTrans[i][j] = pathTrans[k][j];
				}
			}
		}
	}

	CityGraph G = InitGraph(G,cityNo, cityName, edgesDistance, edgesCost, edgesTime, edgesTrans, pathDist, pathCost, pathTime, pathTrans);
	return G;
}

//  查找算法
bool Search(CityGraph& G, char start[], char end[], int n)
{
	if (!strcmp(start, end))
	{
		cout << "目的地即是出发点，您已到达！" << endl;
		return true;
	}

	for (int i = 0; i < MAXNODE; i++)
	{
		if (!strcmp(G.cityList[i].cityName, start))
		{
			DestinationCity* p = G.cityList[i].firstArc;
			while (p != nullptr)
			{
				if (!strcmp(p->cityName, end))
				{
					cout << "查找成功！从" << G.cityList[i].cityName << "到" << p->cityName << "的信息如下：" << endl;
					switch (n)
					{
					case 1:
					{
						DispPath(G, G.pathDist, G.cityList[i].no, p->no);
						cout << "最短里程：" << p->minDistance << "公里" << endl;
						break;
					}
					case 2:
					{
						DispPath(G, G.pathCost, G.cityList[i].no, p->no);
						cout << "最少花费：" << p->minCost << "元" << endl;
						break;
					}
					case 3:
					{
						DispPath(G, G.pathTime, G.cityList[i].no, p->no);
						cout << "最短时间：" << p->minTime << "小时" << endl;
						break;
					}
					case 4:
					{
						DispPath(G, G.pathTrans, G.cityList[i].no, p->no);
						cout << "最少中转次数：" << p->minTrans - 1 << "次" << endl;
						break;
					}
					}

					return true;
				}
				p = p->nextArc;
			}
			cout << "查找失败，你输入的目的城市有误！" << endl;
			return false;
		}
	}
	cout << "查找失败，你输入的出发城市有误！" << endl;
	return false;
}

// 输出从初始城市到目的城市的相应最优路径
void DisplayPath(CityGraph& G, int path[MAXNODE][MAXNODE], int startNo, int endNo, bool& isFirstNode)
{
	// 递归调用，找到路径上的前驱节点
	if (startNo != endNo)
		DisplayPath(G, path, startNo, path[startNo - 1][endNo - 1] + 1, isFirstNode);

	// 输出路径节点，格式化为 "->"
	if (isFirstNode)
	{
		cout << "路径: " << G.cityList[endNo - 1].cityName; // 第一个节点前不加 "->"
		isFirstNode = false;
	}
	else
		cout << " -> " << G.cityList[endNo - 1].cityName;
}

void DispPath(CityGraph& G, int path[MAXNODE][MAXNODE], int startNo, int endNo)
{
	bool isFirstNode = true; // 初始状态
	DisplayPath(G, path, startNo, endNo, isFirstNode);
	cout << endl;
}

//根据输入的城市找到他在矩阵终点编号（不是城市编号，而是城市编号-1）
int SearchNo(CityGraph& G, char input[5])
{
	for (int i = 0; i < MAXNODE; i++)
		if (!strcmp(G.cityList[i].cityName, input))
			return G.cityList[i].no - 1;
	cout << "不存在该城市！请重新输入" << endl;
	return -1;
}

template <typename T>
bool DijkstraOptimalPath(CityGraph& G, T A[MAXNODE][MAXNODE])
{
	char input[5];
	int v = -1;

	// 输入出发城市并获得其矩阵编号
	while (v == -1) 
	{
		cout << "请输入出发城市：";
		cin >> input;
		v = SearchNo(G, input);
		if (v == -1)
		{
			system("pause");
			system("cls");
		}
	}

	int lowCost[MAXNODE];  // 存储从出发城市到各个城市的最短路径
	int closest[MAXNODE];  // 记录每个城市的前驱城市
	bool visited[MAXNODE] = { false };  // 标记城市是否被访问过

	// 初始化，设置从出发城市到其他城市的距离
	for (int i = 0; i < MAXNODE; i++) 
	{
		lowCost[i] = A[v][i];
		closest[i] = v;
		visited[i] = false;
	}

	lowCost[v] = 0;  // 起点的距离是0
	visited[v] = true;  // 标记起点已访问

	cout << "最优路径为：" << G.cityList[v].cityName << "->";
	for (int i = 1; i < MAXNODE; i++) 
	{
		// 找到当前未访问城市中距离起点最近的城市
		int minDist = INF;
		int k = -1;
		for (int j = 0; j < MAXNODE; j++) 
			if (!visited[j] && lowCost[j] < minDist) 
			{
				minDist = lowCost[j];
				k = j;
			}

		visited[k] = true;  // 标记城市 k 为已访问

		// 输出路径（避免多余的 "->"）
		if (i == MAXNODE - 1) 
			cout << G.cityList[k].cityName << endl;
		else 
			cout << G.cityList[k].cityName << "->";
		

		// 更新与城市 k 相邻的城市的最短路径
		for (int j = 0; j < MAXNODE; j++) 
			if (!visited[j] && A[k][j] < INF && lowCost[k] + A[k][j] < lowCost[j]) 
			{
				lowCost[j] = lowCost[k] + A[k][j];
				closest[j] = k;  // 更新前驱城市
			}
	}
	cout << endl;
	return true;
}