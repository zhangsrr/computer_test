/**
 * 对称平方数1
 * 打印所有不超过256，其平方具有对称性的数，比如2，11，因为2*2 = 4， 11*11 = 121
 * 256*256=65536，所有平方数不超过5位
 * 输出用回车分隔
**/
#include <iostream>
using namespace std;

int Reverse(int a){
    //求反序数
    int rev=0;
    while (a != 0)
    {
        rev*=10;
        rev+=a%10;
        a/=10;
    }
    return rev;
}

int main(){
    for (int i = 0; i <= 256; i++)
    {
        //i*i的反序数 == i*i，说明i是对称平方数
        if (Reverse(i*i) == i*i)
            cout << i<< endl;
    }
    return 0;
}