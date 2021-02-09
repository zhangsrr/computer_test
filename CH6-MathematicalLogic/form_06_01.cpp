/**
 * 二进制数
 * 输出一个unsigned int型十进制数，输出对应的二进制串，不要前导0
 * 例如
 * INPUT:
 * 23
 * OUTPUT:
 * 10111
 **/
#include <iostream>
#include <stack>
using namespace std;

int main(){
    unsigned int num=0;
    while (cin >> num)
    {
        stack<int> binary;
        while (num != 0)
        {
            binary.push(num%2);
            num/=2;
        }    
        int times = binary.size();
        for (int i = 0; i < times; i++)
        {
            cout << binary.top();
            binary.pop();
        }
        cout << endl;      
    }
    return 0;
} 