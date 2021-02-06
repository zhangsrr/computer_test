/**
 * 浮点数加法
 * 求两个浮点数相加的和，输入/输出中出现的浮点数形式：
 * P1P2……Pi.Q1Q2……Qj
 * 整数部分P1P2……Pi非负，小数部分Qj不等于0
 * 
 * 算法：
 * 先对齐两个浮点数，再由低位到高位逐一相加，且进位最多为1，注意小数位到整数位的进位
 **/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string a,b;
    while (cin >> a >> b)
    {
        //找小数点位置
        int d1 = find(a.begin(), a.end(), '.')-a.begin();
        int d2 = find(b.begin(), b.end(), '.')-b.begin();
        //[0,d1)整数部分,(d1,a.length()-1]小数部分
        //先将较短的部分补零，使ab对齐
        if (d1 > d2) //a的整数部分更长
        {
            for (int i = 0; i < d1-d2; i++) // 1111.44444  22.333 d1=4,d2=2
                b.insert(0, 1,'0');
        }
        else
        {
            for (int i = 0; i < d2-d1; i++) 
                a.insert(a.begin(),'0');
        }
        //整数部分已对齐
        int subfloat = a.length() - b.length();
        if (subfloat > 0) //a的小数部分更长
        {
            //int subfloat = a.length() - d1 -(b.length() - d2); // 1111.44444  22.333 a=10,b=6 d1=4,d2=2 小数部分a=5,b=3
            int b_end = b.length();
            for (int i = 0; i < subfloat; i++)
                b.insert(b_end , 1, '0');
        }else
        {
            int a_end = a.length();
            for (int i = 0; i < abs(subfloat); i++)
                a.insert(a_end , 1, '0');            
        }
        //小数部分已对齐

        string sumstr="";
        for (int i = a.length() - 1; i >= 0; --i)
        {
            if (a[i] != '.')
            {
                if (a[i]-'0'+b[i]-'0' > 9)
                {
                    sumstr.insert(0, 1, ((a[i]-'0')+(b[i]-'0'))%10 + '0');
                    if (i != 0&& a[i-1]!='.')
                        a[i-1] += 1; //最多进1
                    else if(a[i-1]=='.')
                        a[i-2]+=1;
                    else
                        sumstr.insert(0, 1, '1');
                }else
                    sumstr.insert(0, 1, (a[i]-'0')+(b[i]-'0') + '0'); 
            }
            else
                sumstr.insert(0,1,'.');            
        }
        cout << sumstr << endl;
    }
    return 0;
}