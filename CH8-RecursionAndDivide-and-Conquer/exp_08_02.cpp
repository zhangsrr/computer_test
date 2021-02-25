/**
 * 全排列
 * 给定一个由不同的小写字母组成的字符串，输出这个字符串的所有全排列
 * 假设：
 * 对于小写字母'a'<'b'<'c'<……<'y'<'z'，且给定的字符串中已经按照从小到大的顺序排列
 * 
 * INPUT:
 * 一行由【不同的】小写字母组成的字符串，字符串的长度在1到6之间
 * OUTPUT:
 * 输出这个字符串的所有排列方式，每行一个排列，要求字母序比较小的排在前面
 * 字母序：
 * S=s1s2...sk, T=t1t2...tk,则S<T等价于，
 * 存在p(1<=p<=k)，使得前p-1个字母相等，sp<tp成立
 * 
 * e.g.
 * INPUT:
 * abc
 * OUTPUT:
 * abc
 * acb
 * bac
 * bca
 * cab
 * cba
 * 
 * TIPS:
 * 长度为6的字符串有6x5x4x3x2x1=720次排列
 * A1_1 = 1
 * A2_2 = 2
 * A3_3 = 6
 * A4_4 = 24
 * A5_5 = 120
 * A6_6 = 720
 * 穷举当然也可以做，直接用数组存储字符串全排列各符号的下标即可
 * 
 * 用递归的话 
 * 对于长度为n的字符串，要找到它的全排列
 * 子问题是找其后n-1个字母组成的字符串的全排列
 * 最小子问题是最后一个字母的全排列，即它本身
 * 对于一个长度为n的字符串，输出一部分全排列时
 * 先顺序打印前k个字符，再调用函数依次求其后n-k个字符的全排列
 * 
 * 对于长度为1的字符串
 * 1 -> 1
 * 对于长度为2的字符串
 * 12->12, 21
 * 对于长度为3的字符串
 * 123->123, 132, 213, 231, 312, 321
 * 
 **/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string str;
    while (cin >> str)
    {
        sort(str.begin(), str.end());
        do
        {
            cout << str << endl;
        } while (next_permutation(str.begin(),str.end()));
        //该库函数就是实现全排列的，且排列完并不改变str原序列
        //http://www.cplusplus.com/reference/algorithm/next_permutation/
        cout << endl;        
    }
    return 0;
}