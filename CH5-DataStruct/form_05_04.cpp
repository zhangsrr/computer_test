/**
 * Zero-complexity Transposition
 * 给定一组整数序列
 * 输出其逆序列
 * INPUT:
 * n 序列长度
 * n integers numbers n个整数 (-1 000 000 000 000 000 <= ai <= 1 000 000 000 000 000)
 * 
 * OUTPUT:
 * 逆序列
 **/
#include <iostream>
#include <stack>
using namespace std;

typedef long long int ll;

int main(){
    int n=0;
    stack<ll> numbers;
    while (cin >> n)
    {
        int tmp=0;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            numbers.push(tmp);
        }
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                cout << numbers.top();
            else
                cout << " " << numbers.top();
            numbers.pop();            
        }        
    }
    return 0;
} 