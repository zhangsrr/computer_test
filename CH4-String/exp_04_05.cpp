/**
 * 后缀字串排序
 * 对于一个字符串，将其后缀子串进行排序，
 * 例如grain 
 * 其子串有： grain rain ain in n 
 * 然后对各子串按字典顺序排序，即： ain,grain,in,n,rain
 * 
 * INPUT:
 * 一行字符串
 * 
 * OUTPUT:
 * 按字典顺序换行输出后缀子串
 * 
 **/ 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string str;
    cin >> str;
    vector<string> post_str(str.size());
    for (int i = 0, j = 0; i < str.size(); i++, j++)
    {
        post_str[j] = str.substr(i, str.size()-i);
    }
    sort(post_str.begin(), post_str.end());
    for (int i = 0; i < post_str.size(); i++)
    {
        cout << post_str[i] << endl;
    }
    return 0;
}