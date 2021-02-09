/**
 * 10进制 VS 2进制
 * 对于一个十进制数A，将A转换为二进制数，然后按位逆序输出，再转换为10进制数B
 * 则称B为A的二进制逆序数
 * 
 * e.g.
 * 十进制数173，二进制形式10101101
 * 逆序排列得到10110101，对应的十进制数为181
 * 则181是173的二进制逆序数
 * 
 * INPUT:
 * 一个1000位(10^999)以内的十进制数
 * OUTPUT:
 * 输出对应的二进制逆序数
 * 
 * 输入过长只能用字符串处理，同样应用form6.2的Divide代码可以获取十进制转换的二进制数
 * 而二进制数转换为十进制数则新写一个函数，
 * 从最低位开始处理，设置remainder=0，
 **/
#include <iostream>
#include <vector>
using namespace std;

string Divide(string str, int base){ //转换为base进制的数
    int remainder=0; //余数
    for (int i = 0; i < str.size(); i++)
    {
        int current = remainder*10 + str[i] - '0';
        str[i] = current/base + '0';
        remainder = current % base;
    }
    int pos = 0;
    while (str[pos] == '0')
        pos++;

    return str.substr(pos);
}

string Multi(string str, int base){ //二进制转十进制的乘法
    int carry = 0; //保存进位
    for (int i = str.size() - 1; i >= 0; --i)
    {
        int current = base * (str[i] - '0') + carry;
        str[i] = current % 10 + '0';
        carry = current/10;
    }
    if (carry != 0)
        str = "1" + str;
    return str;
}

string Add(string str, int base){
    int carry = base; 
    for (int i = str.size() - 1; i >= 0; --i)
    {
        int current = (str[i] - '0') + carry;
        str[i] = current % 10 + '0';
        carry = current/10;
    }
    if (carry != 0)
        str = "1" + str;
    return str;
}

int main(){
    string str;
    while (cin >> str)
    {
        vector<int> binary;
        while (str.size() != 0) //得到逆序的二进制串
        {
            int last = str[str.size() - 1] - '0';
            binary.push_back(last % 2);
            str = Divide(str, 2); 
        }
        string ans = "0";
        for (int i = 0; i < binary.size(); i++)
        {
            ans = Multi(ans, 2); //二进制转十进制就是 先移位(即乘法)再相加
            ans = Add(ans, binary[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
