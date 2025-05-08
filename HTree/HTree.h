#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cctype>

using namespace std;

// ������������ڵ�ṹ
struct HTNode
{
    char data;      // �洢�ַ�
    double weight;  // �ַ���Ȩ��
    int parent, lchild, rchild;  // ˫�׽ڵ㣬���ӣ��Һ���
};

// �������������ṹ
struct HCode
{
    char data;    // ��Ӧ���ַ�
    string cd;    // ��Ź���������
};

// �ȽϽڵ��Ȩ�� (�������ȶ���)
struct CompareNode
{
    bool operator()(const HTNode& n1, const HTNode& n2)
    {
        return n1.weight > n2.weight; // С���ѣ�Ȩ��С�����ȼ���
    }
};

// ͳ���ַ�Ƶ��
void CountFrequency(const string& text, unordered_map<char, double>& freq);

// �����������
void CreateHT(vector<HTNode>& ht, const unordered_map<char, double>& freq);

// ���ɹ���������
void CreateHCode(const vector<HTNode>& ht, vector<HCode>& hcd);

// ����ѹ����Ķ���������
string CompressText(const string& text, const vector<HCode>& hcd);

// ��ѹ����������
string DecompressText(const string& compressed, const vector<HTNode>& ht);

// ��ӡ�����������
void PrintHuffmanCodes(const vector<HCode>& hcd);

// ����ѹ����
double CalculateCompressionRatio(const string& original, const string& compressed);