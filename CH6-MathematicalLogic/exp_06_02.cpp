/**
 * 又一版A+B
 * 输入两个不超过整型定义的非负10进制整数A和B(2^31-1)
 * 输出A+B的m(1<m<10)进制数
 * 
 * 因为AB非负，且A+B有可能超过整型表示范围，所以可以用unsigned int定义
 * 
 * INPUT:
 * m A B
 * OUTPUT:
 * A+B的m进制数
 **/
#include <iostream>
#include <vector>
using namespace std;

typedef unsigned int ui;

vector<ui> TransBase(ui A, ui B, int base){
    //考虑AB都为0的情况，则sum == 0
    ui sum=A+B;
    vector<ui> baseNum;
    while (sum!=0)
    {
        baseNum.push_back(sum%base);
        sum /= base;
    }
    return baseNum;
}

int main(){
    int m=0;
    ui A=0,B=0;
    while (cin >> m >> A >> B)
    {
        if (m == 0) return 0;
        vector<ui> ans = TransBase(A, B, m);
        if (ans.size() == 0){
            cout << "0" << endl;
            break;
        }
        for (int i = ans.size() - 1; i >= 0; --i)
        {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}