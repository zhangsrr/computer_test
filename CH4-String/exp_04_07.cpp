/**
 * String Matching
 * 文章T，模式串P都仅由字母构成，
 * 统计在T中有多少个子串能与P匹配
 * 
 * INPUT:
 * T P
 * 1<=(|T|,|P|)<=1000000
 * 
 * OUTPUT:
 * n
 **/
#include <iostream>
#include <vector>
using namespace std;

void GetNext(string pattern, vector<int> &next){
    int j=0;
    next[j] = -1;
    int i = next[j];
    while (j < pattern.size())
    {
        if (i == -1 || pattern[j] == pattern[i])
        {
            i++;
            j++;
            next[j] = i;
        }else
            i = next[i];
    }
    return;
}

int KMP(string text, string pattern){
    vector<int> next(pattern.size()+1);
    GetNext(pattern, next);
    int i=0,j=0;
    int num=0;
    while (i < text.size())
    {
        if (j == -1 || pattern[j] == text[i])
        {
            i++;
            j++;
        }else
            j = next[j];

        if (j == pattern.size())
        {
            num++;
            j = next[j];
        }                
    }
    return num;
}

int main(){
    string T,P;
    cin >> T >> P;
    cout << KMP(T, P) << endl;
    return 0;
}