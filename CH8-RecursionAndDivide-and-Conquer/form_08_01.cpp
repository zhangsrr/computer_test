/**
 * n的阶乘
 * 输入一个整数n，输出n的阶乘
 * INPUT: 多组测试用例
 * n (1<=n<=20)
 * OUTPUT:
 * n!
 **/
#include <iostream>
using namespace std;

typedef long long int ll;
ll Recursion(int n){
    if (n == 1)
        return 1;
    else
        return n*Recursion(n-1);    
}

int main(){
    int n=0;
    while (cin >> n)
    {
        cout << Recursion(n) << endl;
    }
    return 0;
}