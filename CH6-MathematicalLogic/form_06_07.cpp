/**
 * 素数判定
 * 给定一个数n，判断其是否为素数(0, 1, 负数都是非素数)
 * 素数：因数只有1和其本身
 * 测试数据有多组，每组一个 n
 * 若是素数则输出yes，否则输出no
 **/
#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(int n){
    if (n <= 1)
        return false;
    int bound = sqrt(n);
    for (int i = 2; i <= bound; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}


int main(){
    int n=0;
    while (cin >> n)
    {
        if (IsPrime(n))
            cout << "yes" << endl;
        else
            cout << "no" << endl; 
    }
    return 0;
}