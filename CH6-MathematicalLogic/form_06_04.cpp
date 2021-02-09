/**
 * 进制转换2
 * 将M进制的数X转换为N进制的数输出
 * 
 * 可以借助10进制过渡，M->10->N
 * 
 * INPUT:
 * M N (2<=M,N<=36) 超出10的位要用字母表示，字母 ch-'A'+10
 * X (X是M进制的数)
 * 
 * OUTPUT:
 * 将X转换成N进制输出
 * 
 * 输入时若有字母则字母为大写，输出时若有字母，则字母为小写
 **/
#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

char IntToChar(int x){
    if (x < 10)
        return x + '0';
    else
        return x - 10 + 'a';
}

int CharToInt(char ch){
    if (ch >= '0' && ch <= '9')
        return ch-'0';
    else   
        return ch - 'A' + 10; 
}

int main(){
    int M=0,N=0;
    cin >> M >> N;
    string str;
    cin >> str; //M进制的数
    ll number=0;
    for (int i = 0; i < str.size(); i++)
    {
        number *= M;
        number += CharToInt(str[i]);
    }
    vector<char> ans;
    while (number != 0)
    {
        ans.push_back(IntToChar(number%N));
        number /= N;
    }
    for (int i = ans.size() - 1; i >= 0; --i)
        cout << ans[i];
    cout << endl;
    return 0;
}