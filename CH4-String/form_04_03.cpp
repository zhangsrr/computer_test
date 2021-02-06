/**
 * 简单密码
 * 密文 
 * A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 
 * 明文 
 * V W X Y Z A B C D E F G H I J K L M N O P Q R S T U 
 * 你的任务是对给定的密文进行解密得到明文。
 * 密文中也包括非字母的字符，对这些字符不用进行解码。
 * 
 * Input：
 * 输入中的测试数据不超过100组。每组数据都有如下的形式，而且各组测试数据之间没有空白的行。
 * 一组测试数据包括三部分：
 * 1.    起始行 - 一行，包括字符串 "START" 
 * 2.    密文 - 一行，给出密文，密文不为空，而且其中的字符数不超过200
 * 3.    结束行 - 一行，包括字符串 "END" 
 * 在最后一组测试数据之后有一行，包括字符串 "ENDOFINPUT"。 
 **/
/**
 * 简单密码
 * 密文 
 * A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 
 * 明文 
 * V W X Y Z A B C D E F G H I J K L M N O P Q R S T U 
 * 你的任务是对给定的密文进行解密得到明文。
 * 密文中也包括非字母的字符，对这些字符不用进行解码。
 * 
 * Input：
 * 输入中的测试数据不超过100组。每组数据都有如下的形式，而且各组测试数据之间没有空白的行。
 * 一组测试数据包括三部分：
 * 1.    起始行 - 一行，包括字符串 "START" 
 * 2.    密文 - 一行，给出密文，密文不为空，而且其中的字符数不超过200
 * 3.    结束行 - 一行，包括字符串 "END" 
 * 在最后一组测试数据之后有一行，包括字符串 "ENDOFINPUT"。 
 **/
#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    while (getline(cin, str))
    {
        if (str == "ENDOFINPUT")
            return 0;
        if (str != "START" && str != "END" && str != "ENDOFINPUT")
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] >= 'A' && str[i] <= 'E')
                    str[i] += 21;
                else if (str[i] >= 'F' && str[i] <= 'Z')
                    str[i] -= 5;                
            }            
            cout << str << endl;
        }           
    }
    return 0;
}