/**
 * 素数
 * 输入有多组数据
 * 输入一个整数n (2<=n<=10000)，
 * 要求输出所有从1到n之间(不包括1和n)【个位为1】的素数，如果没有则输出-1
 * INPUT:
 * n
 * OUTPUT:
 * 从1到n(不含1和n)之间【个位为1】的所有素数，用空格分隔，且最后一个数后没有空格
 * 如果没有符合条件的素数，则输出-1
 **/
#include <iostream> 
#include <vector>
#include <cmath>
using namespace std;

bool IsPrime(int n){
    if (n <= 1)
        return false;
    int bound = sqrt(n);
    for (int i = 2; i < bound; i++)
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
        //data[0]:0 data[1]:1 data[2]:2 data[n-1]:n-1 data[n]:n
        vector<int> data(n+1, 0); //[2,n-1],还未检测的是0，素数为本身，较小的数为素数，则其倍数必不是素数，标记为1
        for (int i = 2; i < n; i++)
        {
            if (data[i] == 1) //其因数已被判定为素数，则其本身为非素数
                continue;
            else{
                if (IsPrime(i))
                {
                    data[i] = i; //i为素数，则其倍数为非素数 
                    for (int j = i; j <= n/i; j++)
                        data[i*j] = 1;
                }
            }
        }
        vector<int> prime; //存放符合条件的素数
        for (int i = 2; i < n; i++)
        {            
            if (data[i] != 0 && data[i] != 1 && (data[i] % 10) == 1)
                prime.push_back(data[i]);
        }        

        if (prime.size() == 0)
            cout << "-1" << endl;
        else{
            for (int i = 0; i < prime.size(); i++)
            {
                if (i == 0)
                    cout << prime[i];
                else
                    cout << " " << prime[i];                                
            }            
        }                
    }
    return 0;
}