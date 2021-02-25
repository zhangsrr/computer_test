/**
 * 2的幂次方
 * 每一个正整数都能用指数形式表示，例如：
 * 137=2^7+2^3+2^0
 * 用a(b)来表示a^b，那么137可表示为2(7)+2(3)+2(0)
 * 而7、3又可以继续拆解，则
 * 137 = 2(2(2)+2+2(0))+2(2+2(0))+2(0)
 * 给定一个正整数n，给出其指数形式的表达式，只包含2、0以及必要的+、括号
 * 
 * INPUT:
 * n //n<=20000
 * OUTPUT:
 * 指数表达形式
 * 
 * e.g.
 * INPUT:
 * 1315
 * OUTPUT:
 * 2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
 * 
 * 1024+256+32+2+1
 * 10100100011
 * TIPS:
 * 对于0、1、2都可以直接输出
 * 否则就要先输出左括号，在输出中间部分，最后是右括号
 * 
 * n应该先转换为完整的二进制数，根据位数可以得到幂次
 * 因为n<=20000，所以其实每一个位置的幂次可以提前用字符串存储
 * 1     0     2(0)
 * 2     1     2
 * 4     2     2(2)
 * 8     3     2(3)
 * 16    4     2(4)
 * 32    5     2(5)
 * 64    6     2(6)
 * 128   7     2(7)
 * 256   8     2(8)
 * 512   9     2(9)
 * 1024  10    2(10)
 * 2048  11    2(11)
 * 4096  12    2(12)
 * 8192  13    2(13)
 * 16384 14    2(14)
 * 
 * 对于一个正整数，要表示为2的幂次，
 * 3 = 0011 = 2 + 2^0
 * 7 = 0111 = 2^2 + 2 + 2^0
 * 9 = 1001 = 2^3 + 2^0
 * 要求得对应的幂次就要先将每个数转为二进制
 * 
 **/ 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void GetBinaryArray(vector<string>& binary){
    binary[0] = "2(0)";
    binary[1] = "2";
    binary[2] = "2(2)";
    binary[3] = "2(2+2(0))";
    binary[4] = "2(2(2))";
    binary[5] = "2(2(2)+2(0))";
    binary[6] = "2(2(2)+2)";
    binary[7] = "2(2(2)+2+2(0))";
    binary[8] = "2(2(2+2(0)))";
    binary[9] = "2(2(2+2(0))+2(0))";
    binary[10] = "2(2(2+2(0))+2)";
    binary[11] = "2(2(2+2(0))+2+2(0))";
    binary[12] = "2(2(2+2(0))+2(2))";
    binary[13] = "2(2(2+2(0))+2(2)+2(0))";
    binary[14] = "2(2(2+2(0))+2(2)+2)";
    return;
}

string GetBinaryStr(int n){
    //将n转换为二进制表示，最后的结果是逆序的
    string str;
    if (n == 0)
        return "0";
    
    while (n != 0)
    {
        if (n % 2 == 1)
            str += "1";
        else
            str += "0";
        n/=2;
    }
    return str;
}
int main(){
    int n;
    while (cin >> n)
    {
        string str = GetBinaryStr(n);
        //1315 = 10100100011
        //Reverse(1315) = 11000100101
        
        vector<string> binary(15);
        GetBinaryArray(binary);
        
        string ans;
        int sum = count(str.begin(), str.end(), '1'); //决定还要添加sum-1个加号
        int times=0;
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] != '0') //11 = 1011 其逆序为 1101，str的存储顺序
            {
                for (int j = binary[i].length()-1; j >= 0; --j) //i的数值正好是对应的幂次
                {
                    ans.insert(ans.begin(), binary[i][j]);
                }                
                times++;
                if (times != sum)
                    ans.insert(ans.begin(), '+'); //用插入是为了结果的正序
            }          
        }
        cout << ans << endl;
    }
    return 0;
}
