#include"Graph.h"

int main()
{
    //��ͼת��Ϊ����
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
    //��������Ͷ�����
	int n = MAXV, e = 9;
    //����ͼ����ӡ
	AdjGraph* AG;
	CreatGraph(AG, A, n, e);
    cout << "�������ڽӱ�" << endl;
    PrintGraph(AG);

    cout << endl;
    //������ȱ���
    cout << "��������������㷨��" << endl;
    DFS(AG, 0);
    cout << endl;

    //������ȱ���
    cout << "�����ǹ�������㷨��" << endl;
    BFS(AG, 0);
    cout << endl;

    //���ڽӱ�ת��Ϊ�ڽӾ����ɾ��
    MatGraph *MG;
    AdjToMat(AG, MG);
    DestoryGraph(AG);
 
    //����ķ�㷨
    cout << "����������ķ�㷨��" << endl;
    Prim(*MG, 0);
    cout << endl;

    //��³˹�����㷨
    cout << "�����ǿ�³˹�����㷨��" << endl;
    Kruskal(*MG);
    cout << endl;

    ////��˹���ض��㷨
   cout << "�����ǵ�˹���ض��㷨��" << endl;
   Dijkstra(*MG, 0);

}