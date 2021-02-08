/**
 * 括号匹配问题
 * 在某个字符串(长度不超过100)中有左括号、右括号和大小写字母
 * 规定(与常见的算数式子一样)
 * 任何一个左括号都从内到外 与在它右边且距离最近的右括号匹配
 * 
 * 写一个程序，找到无法匹配的左括号和右括号
 * 输出原来的字符串，并在下一行标出不能匹配的括号
 * 不能匹配的左括号用'$'标注
 * 不能匹配的右括号用'?'标注
 * 
 * INPUT:
 * 每组数据一行，包含一个字符串，只包含左右括号和大小写字母，字符串长度不超过100
 * 
 * OUTPUT:
 * 先输出原来的字符串
 * 第二行在无法匹配的左括号下方输出'$'，在无法匹配的右括号下方输出'?'
 **/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    string s;
    stack<int> left;
    while (cin >> s)
    {
        cout << s << endl;
        vector<char> dots(s.size(), ' '); 
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(') //左括号压栈
                left.push(i);          
            else if (s[i] == ')')
            {
                if (!left.empty()) //扫描到右括号且左括号非空，则匹配
                    left.pop();
                else
                    dots[i] = '?';
            }
        }
        while (!left.empty())
        {
            dots[left.top()] = '$';
            left.pop();
        }
        for (int i = 0; i < s.size(); i++)
            cout << dots[i];
        cout << endl;
    }
    return 0;
}