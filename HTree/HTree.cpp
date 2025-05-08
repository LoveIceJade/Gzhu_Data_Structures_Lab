#include"HTree.h"

// 统计字符频率
void CountFrequency(const string& text, unordered_map<char, double>& freq) 
{
    for (char c : text) 
    {
        if (isalpha(c) || isspace(c) || ispunct(c)) {  // 统计字母、空格和标点
            freq[c]++;
        }
    }
}

// 构造哈夫曼树
void CreateHT(vector<HTNode>& ht, const unordered_map<char, double>& freq) 
{
    // 先创建叶子节点
    int leafCount = freq.size();
    ht.resize(2 * leafCount - 1); // 哈夫曼树节点总数

    int i = 0;
    for (auto& entry : freq) 
    {
        ht[i].data = entry.first;
        ht[i].weight = entry.second;
        ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
        i++;
    }

    // 使用优先队列构建哈夫曼树
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    // 将所有叶子节点加入优先队列
    for (int j = 0; j < leafCount; j++) 
    {
        pq.push({ ht[j].weight, j });
    }

    // 构建哈夫曼树
    for (int k = leafCount; k < 2 * leafCount - 1; k++) 
    {
        // 取出权重最小的两个节点
        auto min1 = pq.top(); pq.pop();
        auto min2 = pq.top(); pq.pop();

        int idx1 = min1.second;
        int idx2 = min2.second;

        // 创建新的内部节点
        ht[k].weight = ht[idx1].weight + ht[idx2].weight;
        ht[k].lchild = idx1;
        ht[k].rchild = idx2;
        ht[k].parent = -1; // 新节点暂无父节点

        // 更新子节点的父节点指针
        ht[idx1].parent = k;
        ht[idx2].parent = k;

        // 将新节点加入优先队列
        pq.push({ ht[k].weight, k });
    }
}

// 生成哈夫曼编码
void CreateHCode(const vector<HTNode>& ht, vector<HCode>& hcd) 
{
    int n = ht.size();
    int leafCount = (n + 1) / 2;
    hcd.resize(leafCount);

    for (int i = 0; i < leafCount; i++) 
    {
        int c = i;
        int p = ht[i].parent;
        hcd[i].data = ht[i].data;
        hcd[i].cd = "";

        // 从叶子到根逆向求编码
        while (p != -1) 
        {
            if (ht[p].lchild == c) 
            {
                hcd[i].cd = "0" + hcd[i].cd;
            }
            else 
            {
                hcd[i].cd = "1" + hcd[i].cd;
            }
            c = p;
            p = ht[p].parent;
        }
    }
}

// 构建压缩后的二进制数据
string CompressText(const string& text, const vector<HCode>& hcd) 
{
    unordered_map<char, string> charToCode;
    for (const auto& code : hcd) 
    {
        charToCode[code.data] = code.cd;
    }

    string compressed;
    for (char c : text) 
    {
        if (charToCode.find(c) != charToCode.end()) 
        {
            compressed += charToCode[c];
        }
    }
    return compressed;
}

// 解压哈夫曼编码
string DecompressText(const string& compressed, const vector<HTNode>& ht) 
{
    if (compressed.empty()) return "";

    string decompressed;
    int root = ht.size() - 1;  // 根节点索引
    int p = root;

    for (char bit : compressed) 
    {
        if (bit == '0') 
        {
            p = ht[p].lchild;
        }
        else if (bit == '1') 
        {
            p = ht[p].rchild;
        }

        // 如果到达叶子节点
        if (ht[p].lchild == -1 && ht[p].rchild == -1) 
        {
            decompressed += ht[p].data;
            p = root;  // 回到根节点，继续解码
        }
    }

    return decompressed;
}

// 打印哈夫曼编码表
void PrintHuffmanCodes(const vector<HCode>& hcd) 
{
    cout << "哈夫曼编码表:" << endl;
    for (const auto& code : hcd) 
    {
        cout << "'" << (code.data == ' ' ? "SPACE" : string(1, code.data))
            << "': " << code.cd << endl;
    }
}

// 计算压缩率
double CalculateCompressionRatio(const string& original, const string& compressed) 
{
    double originalBits = original.length() * 8;  // ASCII每字符8位
    double compressedBits = compressed.length();  // 哈夫曼编码每字符1位
    return (1 - compressedBits / originalBits) * 100;
}

