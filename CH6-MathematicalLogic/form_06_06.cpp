/**
 * 最小公倍数
 * a和b的最小公倍数是(a*b)/(GCD(a,b))
 * INPUT:
 * a b
 * OUTPUT:
 * a和b的最小公倍数
 **/
#include <iostream>
using namespace std;

int GCD(int a, int b){
    if (b == 0)
        return a;
    else    
        return GCD(b, a%b);    
}

int main(){
    int a=0,b=0;
    while (cin >> a >> b)
    {
        cout << (a*b)/GCD(a,b) << endl;
    }
    return 0;
}