/**
 * 最大公约数
 * 测试数据有多组，每组输入两个正整数，
 * 对于每组输入，输出最大公约数
 * INPUT:
 * a b
 * OUTPUT:
 * a和b的最大公约数
 **/ 

#include <iostream>
using namespace std;

int GCD(int a, int b){
    /**
     * a = g * l
     * b = g * m
     * a = k*b + a%b
     * 
     * a = 18 = 3 x 6
     * b = 15 = 3 x 5
     * a = 15 + 3 = k x b + a%b
     * (a, b) = (18, 15)
     * (b, a%b) = (15, 3)
     * (b, a%b) = (3, 0)
     * 
     * a = 15
     * b = 18
     * (a, b) = (15, 18)
     * (b, a%b) = (18, 15)
     * (b, a%b) = (15, 3)
     * (b, a%b) = (3, 0)
     * 
     **/ 
    if (b == 0)
        return a;
    else
        return GCD(b, a%b);
}

int main(){
    int a=0,b=0;
    while (cin >> a >> b)
    {
        cout << GCD(a, b) << endl;
    }
    return 0;
}