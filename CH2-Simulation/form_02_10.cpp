/*
* 手机键盘, a的ASCII码从'a'开始
* 1：abc
* 2：def
* 3：ghi
* 4：jkl
* 5：mno
* 6：pqrs
* 7：tuv
* 8：wxyz
* keyboard之差 == 字母之差
* 按一次times+1，等待times+2
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> keyboard = { 1,2,3,  1,2,3,  1,2,3,  1,2,3,  1,2,3,  1,2,3,4,  1,2,3,  1,2,3,4 }; //(int)ch-'a'
	string s;
	while (cin >> s)
	{
		int times = 0;
		int len = s.length();
		for (int i = 0; i < s.length(); ++i)
		{ //等待时间
			int ch1 = int(s[i - 1]);
			int ch2 = int(s[i]);
			if (i != 0 && ((ch1 - ch2) == (keyboard[ch1 - 'a'] - keyboard[ch2 - 'a'])))
				times += 2; //在同一个键上则要等待
			times += keyboard[int(s[i]) - 'a'];
		}
		cout << times << endl;
	}
}