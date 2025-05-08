#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cctype>

using namespace std;

// 定义哈夫曼树节点结构
struct HTNode
{
    char data;      // 存储字符
    double weight;  // 字符的权重
    int parent, lchild, rchild;  // 双亲节点，左孩子，右孩子
};

// 定义哈夫曼编码结构
struct HCode
{
    char data;    // 对应的字符
    string cd;    // 存放哈夫曼编码
};

// 比较节点的权重 (用于优先队列)
struct CompareNode
{
    bool operator()(const HTNode& n1, const HTNode& n2)
    {
        return n1.weight > n2.weight; // 小顶堆，权重小的优先级高
    }
};

// 统计字符频率
void CountFrequency(const string& text, unordered_map<char, double>& freq);

// 构造哈夫曼树
void CreateHT(vector<HTNode>& ht, const unordered_map<char, double>& freq);

// 生成哈夫曼编码
void CreateHCode(const vector<HTNode>& ht, vector<HCode>& hcd);

// 构建压缩后的二进制数据
string CompressText(const string& text, const vector<HCode>& hcd);

// 解压哈夫曼编码
string DecompressText(const string& compressed, const vector<HTNode>& ht);

// 打印哈夫曼编码表
void PrintHuffmanCodes(const vector<HCode>& hcd);

// 计算压缩率
double CalculateCompressionRatio(const string& original, const string& compressed);