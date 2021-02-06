/**
 * 字母统计
 * 输入一行字符串，统计其中大写字母A-Z出现的次数，按升序输出
 * 输出格式
 * A:n1
 * B:n2
 * 为零的也需要输出
 **/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string str;
    char ch='A';
    while (getline(cin, str))
    {
        for (; ch <= 'Z' ; ch++)
        {
            cout << ch << ":" << count(str.begin(), str.end(), ch) << endl;   
        }
    }
    return 0;
} 