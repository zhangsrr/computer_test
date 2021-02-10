/**
 * Prime Number
 * INPUT:
 * k
 * OUTPUT:
 * 输出第k个素数，从2开始
 * 
 * e.g.
 * INPUT:
 * 3
 * OUTPUT:
 * 5
 * 因为素数 2 3 5，5为第三个素数
 **/
#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(int n){
    if (n <= 1)
        return false;
    else
    {
        int bound = sqrt(n);
        for (int i = 2; i <= bound; i++)
        {
            if (n%i == 0)
                return false;
        }        
    }
    return true;
}

int main(){
    int k=0;
    while (cin >> k) 
    {
        int i=2;
        while (k>0)
        {
            if (IsPrime(i))
                k--;
            i++;            
        }
        cout << i-1 << endl;
    }
    return 0;
}