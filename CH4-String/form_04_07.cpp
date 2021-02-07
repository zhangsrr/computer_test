/**
 * Oulipo
 * 统计在一篇文章（不含空白符）中单词出现的频次 用KMP算法
 * 单词可重叠统计
 *
 * Input:
 * 测试用例数目N
 * 单词 W (1 <= |W| <= 10000)
 * 文章 T (|W| <= |T| <= 1000000)
 *
 * 单词和文章都仅由大写字母构成
 *
 * e.g.
 * INPUT:
 * 3
 * BAPC
 * BAPC
 * AZA
 * AZAZAZA
 * AVERDXIVYERDIAN
 *
 * OUTPUT:
 * 1
 * 3
 * 0
 *
 **/
#include <iostream>
#include <vector>
using namespace std;

void GetNextTable(vector<int>& next, string pattern) { //通用函数
    int j = 0;
    next[j] = -1;
    int i = next[j];
    while (j < pattern.size())
    {
        if (i == -1 || pattern[j] == pattern[i])
        {
            i++;
            j++;
            next[j] = i;
        }
        else
            i = next[i];
    }
    return;
}

int KMP(string text, string pattern, vector<int> Next) {
    int i = 0, j = 0;
    int num = 0;
    while (i < text.size())
    {
        if (j == -1 || pattern[j] == text[i])
        {
            i++;
            j++;
        }
        else
            j = Next[j];

        if (j == pattern.size()) {
            num++;
            j = Next[j]; //继续匹配
        }
    }
    return num;
}

int main() {
    int caseNumber = 0;
    cin >> caseNumber;
    while (caseNumber--)
    {
        string pattern;
        string text;
        cin >> pattern >> text;
        vector<int> Next(pattern.size()+1); //若设为pattern.size() ，则在创建next表时会发生越界
        GetNextTable(Next, pattern);
        int num = KMP(text, pattern, Next);
        cout << num << endl;
    }
    return 0;
}