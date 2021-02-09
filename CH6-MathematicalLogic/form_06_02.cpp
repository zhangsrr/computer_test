/**
 * 进制转换
 * 将一个长度最多为【30位数字】的十进制非负整数转换为二进制数输出
 * INPUT:
 * 十进制数
 * OUTPUT:
 * 二进制数
 **/
#include <iostream>
#include <stack>
using namespace std;

string Divide(string str){
    int remainder=0; //余数
    for (int i = 0; i < str.size(); i++)
    {
        int current = remainder*10 + str[i] - '0';
        str[i] = current/2 + '0';
        remainder = current % 2;
    }
    int pos = 0;
    while (str[pos] == '0')
        pos++;

    return str.substr(pos);
}

int main(){
    string str;
    while (cin >> str){
        /**
         * 取模运算用最低位的数取，
         * 除2运算则从高到低依次/2，无法整除的留下余数与后一位相加后再除         * 
         **/ 
        stack<int> binary;
        while (str.size() != 0)
        {
            int last = str[str.size() - 1] - '0';
            binary.push(last % 2);
            str = Divide(str);
        }
        while (!binary.empty())
        {
            cout << binary.top();
            binary.pop();
        }
        
        cout << endl;        
    }
    return 0;
}