/**
 * 统计字符
 * 统计给定字符串中指定的字符出现的次数
 * 
 * Input：
 * str1 (长度<=5) (含空格，空格也需要统计，且有重复字符需重复统计)
 * str2 (长度<=80)
 * 
 * 以'#'作为所有测试用例输入结束的标识
 * 
 * Output：
 * ci ni (第i个字符，出现ni次)
 **/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std; 

int main(){
    string s1;
    while (getline(cin,s1))
    {
        if (s1 == "#")
            return 0;
        string s2;
        getline(cin,s2);
        for (int i = 0; i < s1.length(); i++)
        {
            //以下内容也可以直接用 count解决
            // cout << s1[i] << " " << count(s2.begin(), s2.end(), s1[i]) << endl;
            
            int times=0;
            for (int j = 0; j < s2.length(); j++)
            {
                if (s2[j] == s1[i])
                    times++;     
            }
            cout << s1[i] << " " << times << endl;
        }
    }
    return 0;
}
