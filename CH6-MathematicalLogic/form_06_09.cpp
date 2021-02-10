/**
 * 质因数的个数
 * 求正整数N(1<N<10^9)的质因数的个数，相同的质因数需重复计算
 * 如：120=2x2x2x3x5，共有5个质因数
 * 
 * INPUT:
 * 多组测试数据，每组一个正整数N
 * OUTPUT:
 * 输出N的质因数个数
 * 
 * 求质因数的个数 就是不断将N除 可整除的最小质数 * 
 **/ 
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool IsPrime(int n){
    if (n <= 1)
        return false;
    else
    {
        double bound = sqrt(n);
        for (int i = 2; i <= bound; i++)
        {
            if (n%i == 0)
                return false;
        }        
    }
    return true;    
}

int main(){
    int N=0;
    while (cin >> N)
    {
        int times=0;
        double edge = sqrt(N);
        for (int i = 2; i <= edge && N > 1;)
        {
            if (IsPrime(i) && N%i == 0)
            {
                N = N/i;
                times++;
                // cout << i << "\t";
            } else
                i++;   
        }
        if (N > 1) 
            times++;
        // cout << N << endl;
        cout << times << endl;
    }
    return 0;
}