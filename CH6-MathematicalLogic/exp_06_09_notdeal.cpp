/**
 * root(N,k)
 * N<k时，root(N,k) = N
 * N>=k时，root(N,k) = root(N',k),N'为N的k进制表示的各位数字之和
 * 
 * INPUT:
 * x y k
 * 2<=k<=16, 0<x,y<2000 000 000
 * 
 * OUTPUT:
 * root(x^y, k) x的y次方
 * 4 4 10
 * 4^4=256 10
 * root(256,10) = root(13,10) = root(4,10) = 4
 * 
 **/
#include <iostream>
using namespace std;

typedef long long int ll;
ll FastExp(ll x, ll y, int k){
    /**
     * 求x^y
     * 若y是偶数，则指数减半 底数平方
     * 若y是奇数，同样指数减半 底数平方，只是最后再乘一个x
     * N = a0+a1*k+a2*k^(2)+……+a_(n-1)*k^(n-1) ①
     * N' = a0+a1+a2+……+a_(n-1) ②
     * ①-②可得 (N-N')%(k-1) == 0
     * 所以N'=N%(k-1)，但N'∈[0,k-1],所以要单独判断N'=k-1
     **/ 
    ll ans = 1;
    while (y != 0)
    {
        if (y%2 == 1) //快速幂，指数减半 底数平方, 质数为奇数要多乘1个x
            ans = (ans*x)%(k-1);
        x = (x*x)%(k-1);
        y /= 2;
    }
    return ans;
}
void Root(ll x, ll y, int k){
    ll ans=0;
    ans = FastExp(x, y, k); //ans返回值是[0,k-2],
    //因为在FastExp过程中结果每次都对k-1取模，且x，y>0所以x^y的幂不会是0，所以取模为0的结果只可能是结果==k-1
    ans = (ans==0) ? k-1:ans; 
    cout << ans << endl;
}

int main(){
    ll x=0,y=0;
    int k=0;
    while (cin >> x >> y >> k)
    {
        Root(x,y,k);
    }
    return 0;
}