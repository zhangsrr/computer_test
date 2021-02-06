/*
* 反序数
* 设N是一个4位数，它的9倍恰好是其反序数，例如1234的反序数是4321
* 求N的值
* 输出用回车分隔
*/
#include <iostream>
using namespace std;

int main(){
    //已知N为四位数，且其9倍仍为四位数，则其范围应是[1000, 10000/9]
    //i的反序数等于i的9倍
    for (int i = 1000; i < 10000/9; i++)
    {
        int thou = i/1000;
        int hund = (i/100)%10;
        int tens = (i/10)%10;
        int single = i%10;
        if (thou + hund*10 + tens*100 + single*1000 == i*9)
            cout << i << endl;
    }
    return 0;
}