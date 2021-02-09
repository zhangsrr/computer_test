/**
 * 八进制
 * 输入一个整数将其转换为8进制输出
 * INPUT:
 * 一个整数N (0<=N<=100000)
 * 有多组测试数据
 * OUTPUT:
 * 八进制表示数
 * 
 * 因为十进制数的9超出8进制表示，所以当其转换为
 **/  
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N=0;
    while (cin >> N)
    {
        vector<int> EiBase; //8进制
        while (N!=0)
        {
            EiBase.push_back(N%8);
            N /= 8;
        }
        for (int i = EiBase.size() - 1; i >= 0; --i)
            cout << EiBase[i];
        cout << endl;
    }
    return 0;
}