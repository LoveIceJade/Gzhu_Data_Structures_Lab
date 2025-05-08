#include "HTree.h"

int main()
{
    string text = "The Chinese official said he viewed the Trump Presidency not as an aberration but as the product of a failing political system. "
        "This jibes with other accounts. The Chinese leadership believes that the United States, and Western democracies in general, "
        "haven't risen to the challenge of a globalized economy, which necessitates big changes in production patterns, as well as major upgrades "
        "in education and public infrastructure. In Trump and Trumpism, the Chinese see an inevitable backlash to this failure.";

    // Step 1: 统计字符频率
    unordered_map<char, double> freq;
    CountFrequency(text, freq);

    cout << "字符频率:" << endl;
    for (const auto& pair : freq)
    {
        cout << "'" << (pair.first == ' ' ? "SPACE" : string(1, pair.first))
            << "': " << pair.second << endl;
    }
    cout << endl;

    // Step 2: 构造哈夫曼树
    vector<HTNode> ht;
    CreateHT(ht, freq);

    // Step 3: 生成哈夫曼编码
    vector<HCode> hcd;
    CreateHCode(ht, hcd);

    // 打印哈夫曼编码
    PrintHuffmanCodes(hcd);
    cout << endl;

    // Step 4: 压缩文本
    string compressed = CompressText(text, hcd);
    cout << "原始文本长度: " << text.length() * 8 << " 比特" << endl;
    cout << "压缩后文本长度: " << compressed.length() << " 比特" << endl;
    cout << "压缩率: " << CalculateCompressionRatio(text, compressed) << "%" << endl;
    cout << endl;

    // Step 5: 解压文本
    string decompressed = DecompressText(compressed, ht);

    // 检查原文和解压后的文本是否一致
    if (text == decompressed)
    {
        cout << "验证成功: 解压后的文本与原始文本匹配！" << endl;
    }
    else
    {
        cout << "错误: 解压后的文本与原始文本不匹配。" << endl;
    }

    return 0;
}