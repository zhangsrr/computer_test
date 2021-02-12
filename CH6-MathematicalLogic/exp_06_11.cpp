/**
 * 递推数列
 * 给定a0，a1，以及an=p*a_(n-1) + q*a_(n-2)中的p和q，其中n>=2
 * 求第k个数对10000的模
 * INPUT:
 * a0 a1 p q k
 * OUTPUT:
 * a_(k)%10000
 * 
 **/ 
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a0=0,a1=0,p=0,q=0,k=0;
    while (cin >> a0 >> a1 >> p >> q >> k)
    {
        /**
         * 可以理解为bn=b_(n-1) + b_(n-2)
         * b_(n-1) = p* a_(n-1)
         * b_(n-2) = q* a_(n-2)
         * b2 = b1+b0
         * b3 = b2+b1
         * ……
         * bk = b(k-1)+b(k-2)
         * 即经过k-1轮才能得到bk的值
         **/ 
        int sum=0;
        vector<int> vec(k+1); //a0-ak
        vec[0] = a0;
        vec[1] = a1;
        for (int i = 2; i <= k; i++)
        {
            vec[i] = ((p*vec[i-1])%10000 + (q*vec[i-2])%10000)%10000;
        }
        cout << vec[k] << endl;        
    }
    return 0; 
}