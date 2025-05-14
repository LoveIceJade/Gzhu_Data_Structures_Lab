#include"ClassProgramFinal.h"

//  初始化城市编号
int cityNo[MAXNODE] = { 1,2,3,4,5,6,7 };

//  初始化城市名字数组
char cityName[MAXNODE][CharSize] = { "北京", "西安", "郑州", "徐州", "成都", "广州", "上海" };

// 初始化距离数组、费用数组、时间数组
int dist[MAXNODE][MAXNODE] =
{
    {0, 2553, 695, 704, INF, INF, INF},
    {2553, 0, 511, INF, 812, INF, INF},
    {695, 511, 0, 349, INF, 1579, INF},
    {704, INF, 349, 0, INF, INF, 651},
    {INF, 812, INF, INF, 0, 2368, INF},
    {INF, INF, 1579, INF, 2368, 0, 1385},
    {INF, INF, INF, 651, INF, 1385, 0}
};

double time0[MAXNODE][MAXNODE] = 
{
    {0, 8, 2.3, 2.5, INF, INF, INF},
    {8, 0, 1.5, INF, 3, INF, INF},
    {2.3, 1.5, 0, 1.2, INF, 5, INF},
    {2.5, INF, 1.2, 0, INF, INF, 2},
    {INF, 3, INF, INF, 0, 7, INF},
    {INF, INF, 5, INF, 7, 0, 4},
    {INF, INF, INF, 2, INF, 4, 0}
};

int cost[MAXNODE][MAXNODE] = 
{
    {0, 885, 202, 225, INF, INF, INF},
    {885, 0, 148, INF, 283, INF, INF},
    {202, 148, 0, 112, INF, 495, INF},
    {225, INF, 112, 0, INF, INF, 162},
    {INF, 283, INF, INF, 0, 684, INF},
    {INF, INF, 495, INF, 684, 0, 386},
    {INF, INF, INF, 162, INF, 386, 0}
};

int main()
{
    CityGraph G = FloydAndInitGraph(cityNo, cityName, dist, cost, time0);
    int input;
    FirstMenu();  //  展示菜单并输入相应函数
    cin >> input;

    while (input)
    {
        FirstMenu();  //  展示菜单并输入相应函数
        cin >> input;
        if (input == 5)
        {
            ThirdMenu(G, dist, cost, time0);
            break;
        }
        SecondMenu(G, input);
        system("pause");
        system("cls");
    }

    cout << endl << "系统已经退出！" << endl << "欢迎再次使用！" << endl;

    return 0;
}