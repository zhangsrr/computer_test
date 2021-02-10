/**
 * 进制转换
 * 写一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串
 * 含多组测试用例
 * 
 * INPUT:
 * 16进制(0xA)
 * OUTPUT:
 * 10进制
 **/ 
#include <iostream>
#include <vector>
using namespace std;

int CharToInt(char ch){ //0-9 A-F 
    if (ch - 'A' >= 0)
        return ch - 'A' + 10; //B=11 B-A==1
    else
        return ch - '0'; //9
}

int main(){
    string str;
    while (cin >> str)
    {
        str = str.substr(2); //删去 0x
        int sum=0;
        for (int i = 0; i < str.size(); i++)
        {
            sum = sum*16 + CharToInt(str[i]);
        }
        cout << sum << endl;
    }
    return 0;
}