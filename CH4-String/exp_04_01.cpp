/**
 * skew数
 * 在 skew binary 表示中，
 * 第k位的值 x[k] 表示 x[k]*(2^(k+1)-1)
 * 每个位上的可能数字是 0 或 1，最后面一个非零位可以是 2，
 * 例如，10120(skew) = 1×(2^5-1) + 0×(2^4-1) + 1×(2^3-1) + 2×(2^2-1) + 0×(2^1-1) = 31 + 0 + 7 + 6 + 0 = 44。
 * 前十个 skew 数是 0、1、2、10、11、12、20、100、101、以及 102。
 * 
 * Output：
 * 输出对应的十进制形式，结果不超过2^31-1
 **/
#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;

int main(){
    ll sum=0;
    string s;
    cout.setf(ios_base::fixed, ios_base::floatfield); //防止数字过大时输出变成科学计数法
    while (cin >> s)
    {
        sum = 0;
        for (int i = 0, j = s.length(); i < s.length(), j > 0; ++i, --j)
        {
            sum += (s[i]-'0')*((pow(2.0,j)-1));
        }
        cout << sum << endl;
    }
    return 0;
}