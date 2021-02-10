/**
 * 约数的个数
 * 输入n个整数，依次输出每个整数的约数的个数
 * 约数就是因数，在[1,N]范围内所有能被N整除的数都是约数
 * INPUT:
 * n 一组数据有n个整数 (n<=1000)
 * data_n 输入的n个整数 (1<=N<=1000000000)
 * OUTPUT:
 * 每个数的约数的个数
 * 输出n行
 * 
 * 约数个数定理
 * 将N分解为质因数的乘积，可求每个质因数的幂，ai
 * 则N的约数个数为 Σ(ai+1)
 **/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool IsPrime(int n){
    if (n <= 1)
        return false;
    else
    {
        double bound = sqrt(n);
        for (int i = 2; i < bound; ++i)
        {
            if (n%i==0)
                return false;
        }
    }
    return true;
}

int main(){
    int n=0;
    while (cin >> n)
    {
        int N=0;
        while (n--)
        {
            vector<vector<int>> prime;
            vector<int> tmp; //tmp[0]表示质因数，tmp[1]表示质因数的幂
            
            cin >> N;
            double edge = sqrt(N);
            int times=0;
            int i=0;
            for (i = 2; i <= edge && N > 1; )
            {
                if (N % i == 0 && IsPrime(i))
                {
                    N = N/i;
                    times++;
                }else
                {
                    if (times!=0){ //存储当前质数及对应的幂
                        tmp.push_back(i);
                        tmp.push_back(times);
                        prime.push_back(tmp);
                        tmp.clear();
                    }
                    i++;
                    times=0;
                }                
            }
            if (N > 1) //最多存在一个大于sqrt(N)的质因数
            {
                tmp.push_back(N);
                tmp.push_back(1);
                prime.push_back(tmp);
            }
            else{ //当退出for循环时N<=1则最后的质因数还未存储
                tmp.push_back(N);
                tmp.push_back(times);
                prime.push_back(tmp);
            }
            
            int _sum=1;
            for (int j = 0; j < prime.size(); j++) //定理公式
            {
                _sum *= prime[j][1]+1;
            }
            cout << _sum << endl;
        }
    }    
    return 0;
}