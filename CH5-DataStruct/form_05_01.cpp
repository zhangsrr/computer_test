/**
 * 一个数如果恰好等于它的各因子（该数本身除外）子和，如：6=3+2+1，则称其为“完数”；
 * 若因子之和大于该数，则称其为“盈数”。
 * 求出2到60之间所有“完数”和“盈数”
 * 
 * 因子：一个数对其因子取模，结果为0
 * 
 * OUTPUT:
 * E: e1 e2 e3……(ei为完数) G: g1 g2 g2……(gi为盈数)
 * 注意空格
 **/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> E_data; //完数
    vector<int> G_data; //盈数
    for (int i = 2; i <= 60; i++)
    {
        int sum=0;
        for (int j = 1; j < i; j++)
        {
            if (i%j == 0)
                sum+=j;
        }
        if (sum == i)
            E_data.push_back(i);
        else if (sum > i)
            G_data.push_back(i);        
    }
    
    for (int i = 0; i < E_data.size(); i++)
    {
        if (i == 0)
            cout << "E:";
        cout << " " << E_data[i];
    }
    
    if (E_data.size() != 0)
        cout << " ";
    for (int i = 0; i < G_data.size(); i++)
    {        
        if (i == 0)
            cout << "G:";
        cout << " " << G_data[i];        
    }
    return 0;    
}