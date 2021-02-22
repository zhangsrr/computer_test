/**
 * 杨辉三角形
 * 输入n值，利用递归函数，求杨辉三角中各个位置上的值
 * INPUT: 有多组测试用例
 * n (n>=2,整型)
 * OUTPUT:
 * 输出相应输入的杨辉三角
 * 
 * e.g.
 * INPUT:
 * 6
 * OUTPUT: 【给的测试用例有输出第一行的一个1，但是实际的用例中却不需要输出这个1】
 * 1
 * 1 1
 * 1 2 1
 * 1 3 3 1
 * 1 4 6 4 1
 * 1 5 10 10 5 1
 * 
 * TIPS:
 * 1. 最小子问题n==2
 *  1
 * 1 1
 * 2. 要输出n层的杨辉三角，先要输出n-1层的杨辉三角，即n层的前n-1层
 * 每一行的输出都是一个for循环
 * Cn_0……Cn_n
 * e.g
 * C5_0=1, C5_1=5, C5_2=10, C5_3=10, C5_4=5, C5_5=1
 * Cn_k = n!/((n-k)!*k!)
 **/ 
#include <iostream>
using namespace std;

typedef long long int ll;

ll Recursion(int n){
    if (n == 0)
        return 1;
    else
        return n*Recursion(n-1);    
}
int main(){
    ll n = 0;
    while (cin >> n)
    {
        for (int i = 1; i < n; i++)
        {
            ll up = Recursion(i); //Cn_k的分子部分        
            for (int j = 0; j <= i; j++)
            {            
                ll down1 = Recursion(j);
                ll down2 = Recursion(i-j);    
                if (j != 0)
                    cout << " ";
                cout << up/(down1*down2);
            }
            cout << endl;
        }        
    }
    return 0;
}