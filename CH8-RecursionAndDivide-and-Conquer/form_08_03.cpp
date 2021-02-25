/**
 * Fibonacci
 * Fibonacci数 {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ……}
 * 的通式：
 * F_0=0,
 * F_1=1,
 * F_n=F_(n-1)+F_(n-2) (n>=2)
 * 求斐波那契数列
 * INPUT:
 * n //求F_n, 0<=n<=30
 * OUTPUT:
 * F_n
 **/ 
#include <iostream>
using namespace std;

typedef long long int ll;

ll Fibonacci(int n){
    if (n == 0 || n == 1)
        return n;
    else
        return Fibonacci(n-1)+Fibonacci(n-2);
}

int main(){
    int n=0;
    while (cin >> n)
    {
        cout << Fibonacci(n) << endl;
    }
    return 0;
}