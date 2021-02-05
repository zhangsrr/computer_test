/*
* 密码翻译
* 我们给出一种最简的的加密方法，对给定的一个字符串，
* 把其中从a-y,A-Y的字母用其后继字母替代，把z和Z用a和A替代，则可得到一个简单的加密字符串。
* Input：
* string
*
* Output：
* 加密后的字符串
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int n = 0;
	string str; //含空格
	while (getline(cin, str))
	{
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == 'z' || str[j] == 'Z')
				str[j] -= 25;
			else if ((str[j] >= 'a' && str[j] <= 'y') || (str[j] >= 'A' && str[j] <= 'Y'))
				str[j] += 1;
		}
		cout << str << endl;
	}
	return 0;
}