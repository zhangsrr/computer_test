/**
 * 单词替换
 * 输入一个字符串(由若干单词与空格组成)，以回车结束
 * 将其中某个单词替换成另一个单词，并输出替换后的字符串
 * Input:
 * str
 * word_a
 * word_b
 * 将str中的word_a替换成word_b
 * 
 * !!要注意替换单位是单词，即某个单词中字串为word_a但该单词不等于word_a，也不能进行替换
 * 考虑分割单位为空格，可以直接用数组存储，再整个替换，输出的时候再添加空格
 **/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string str,a,b;
    while (getline(cin, str))
    {
        cin >> a >> b;
        string tmp="";
        vector<string> words;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ')
                tmp+=str[i];
            else
            {
                words.push_back(tmp);
                tmp.clear();
            }
        }
        words.push_back(tmp);
        replace(words.begin(), words.end(), a, b);
        for (int i = 0; i < words.size(); i++)
        {
            if (i != 0)
                cout << " ";
            cout << words[i];
        }
        cout << endl;
    }
    return 0;
}