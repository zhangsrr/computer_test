/**
 * 整除问题
 * 给定n和a，求最大的k，使 n! 可被 a^k整除 但不能被 a^(k+1)整除
 * INPUT:
 * n a
 * (2<=n<=1000, 2<=a<=1000)
 * OUTPUT:
 * 整数k
 * 
 * 输入的n因为最大为1000，而1000!超出了longlong的表示范围，所以要用字符串处理
 * 
 **/
#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;

int main(){
    int n,a;
    while (cin >> n >> a)
    {
        /**
         * n的阶乘也可以分解成质因数的乘积，要找k，就是看n!最多能整除多少次a
         * n!=p1^e1 * p2^e2 * …… * pm^em
         * a = q1^t1 * q2^t2 * …… * qs^es
         * n!要整除a，那么a的所有质因数在n中都存在，且n!对应的幂次不小于a的幂次
         * 因为1000!位数过长，所以在处理的过程中要逐步缩小
         * 
         * 或者
         * 
         * 【这种方式仍会超出longlong表示范围，还会超时】
         * 利用for循环遍历从[1,n]的每一个数，m为中间的某个数         
         * 当m!不能被a整除时就再乘下一个数m+1，
         * 能整除就将当前结果除以a，再乘下一个数
         **/ 
        int times=0;
        ll ans=1;

        for (int i = 1; i <= n; i++)
        {
            ans *= i;
            while (ans % a == 0)
            {
                times ++;
                ans /= a;
            }                 
        }
        cout << times << endl;        
    }
    return 0;
}