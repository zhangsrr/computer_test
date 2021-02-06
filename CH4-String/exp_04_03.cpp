/**
 * 对一个字符串中的所有单词，如果单词的首字母不是大写字母，则把单词的首字母变成大写字母。
 * A = a-32 
 * 在字符串中，单词之间通过空白符分隔，空白符包括：空格(' ')、制表符('\t')、回车符('\r')、换行符('\n')
 * Output:
 * 对于每组数据，输出一行(原来字符串中单词的分隔符要保留)
 **/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    char ch;
    int flag=0; //为0的时候表示当前字符的前一个字符为空白符，首字母要大写;为 1则直接输出
    while ((ch = getchar()) != EOF)
    {
        if (!isspace(ch))
        {
            if (flag == 0){
                flag = 1;
                if (ch >= 'a' && ch <= 'z')   //仅将小写字母改为大写，若为数字或其他字符则不修改         
                    cout << (char)toupper(ch);
                else
                    cout << ch;
            }else
                cout << ch;
        }
        else
        {
            flag = 0;
            cout << ch;
        }
    }
    return 0;
}