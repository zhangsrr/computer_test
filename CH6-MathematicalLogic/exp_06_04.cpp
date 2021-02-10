/**
 * 数制转换
 * 求任意两个不同进制非负整数的转换(2进制~16进制)
 * 所给整数在long所能表达的范围
 * 不同进制的表示符号为(0,1,……,9,a,b,……,f)或(0,1,……,9,A,B,……,F)
 * 
 * INPUT:
 * a n b
 * a表示其后的n是a进制数
 * b表示要将n转换为b进制数
 * a,b均为10进制数
 * 2 <= a,b <= 16
 * 数据可能存在前导零
 * 输入可能同时存在大小写字母
 * 
 * OUTPUT:
 * 输出b进制数，字母符号全部用大写
 **/
#include <iostream>
#include <vector>
using namespace std;

int CharToInt(char ch){
    if (ch - 'A' >= 0)
        return ch-'A'+10;
    else 
        return ch - '0';
}

char IntToChar(int i){
    if (i < 10)
        return i+'0';
    else 
        return i-10+'A'; //11 B   
}

int main(){
    string str;
    int a=0,b=0;
    while (cin >> a >> str >> b)
    {
        int pos=0;
        while (str[pos] == '0') //去除前导零
            pos++;
        str = str.substr(pos);       

        for (int i = 0; i < str.size(); i++) //输入的小写字母全改大写
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] = toupper(str[i]);
        }
        
        //a转10
        int sum=0;
        for (int i = 0; i < str.size(); ++i)
            sum = sum*a + CharToInt(str[i]);
                    
        //10转b
        vector<char> ans;
        while (sum != 0)
        {
            ans.push_back(IntToChar(sum%b));
            sum = sum/b;    
        }
        for (int i = ans.size() - 1; i >= 0; --i)
            cout << ans[i];

        cout << endl;
    }
    return 0;
}