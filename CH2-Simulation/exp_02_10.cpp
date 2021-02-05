/*
* 路径打印：打印目录树结构
* 先得到完整路径(含'\')，再单独分割存储
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n = 0;
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        vector<vector<string>> str(n, vector<string>(50));
        string tmp;
        string s;
        //Input
        for (int i = 0; i < n; i++)
        {
            cin >> tmp; 
            int pos = 0;
            //分割字符串
            for (int j = 0; j < tmp.size(); ++j)
            {
                if (tmp[j] == '\\') {
                    str[i][pos++] = s;
                    s.clear();
                    continue;
                }
                else if (j == tmp.size() - 1)
                {
                    s += tmp[j];
                    str[i][pos++] = s;
                    s.clear();
                }
                else
                    s += tmp[j];
            }   
            str[i].resize(pos);
        }
        //升序排序
        sort(str.begin(), str.end());

        for (int i = 0; i < n; i++)
        {
            int pos = 0;
            string space;
            while (i != 0 && pos < str[i].size() && pos < str[i-1].size() && str[i-1][pos] == str[i][pos])
            { //控制缩进空格个数
                space += "  ";
                pos++;
            }
            for (; pos < str[i].size(); pos++, space += "  ")
                cout << space << str[i][pos] << endl;
        }
        cout << endl; //空行
    }
    return 0;
}
