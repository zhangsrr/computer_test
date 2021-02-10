/**
 * 最简真分数
 * 给出n个正整数，任取两个数分别作为分子和分母组成最简真分数，求共有多少个这样的组合
 * 
 * 最简真分数：
 * 分子小于分母 且 分子分母除1以外没有公因数
 * 
 * INPUT: 
 * n 这组正整数的个数
 * 一行n个正整数
 * 
 * 每组包含n(n<=600)和n个不同的整数m，1<=m<=1000
 * n == 0表示结束
 * OUTPUT:
 * 每行输出最简真分数组合的个数
 **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GCD(int a, int b){
    //确定a、b是否有公因数
    /**
     * (a,b)=(3,2)
     * (b,a%b) = (2,1)
     * (b,a%b) = (1, 0)
     **/ 
    if (b == 0)
        return a;
    else if (b == 1)
        return -1;
    else
        return GCD(b, a%b);    
}

int main(){
    int n=0;
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        
        vector<int> data(n);
        for (int i = 0; i < n; i++)
            cin >> data[i];
        sort(data.begin(), data.end());

        int times=0;
        for (int i = 0; i < n-1; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                //data[j] > data[i]
                if (GCD(data[i], data[j]) == -1)
                    times++;     
            }            
        }
        cout << times << endl;
    }
    return 0;
}