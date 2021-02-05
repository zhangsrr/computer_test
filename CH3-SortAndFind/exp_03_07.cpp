/*
* 找位置
* 对给定的一个字符串，找出【有重复】的【字符】，并给出其位置。
* 如：abcaaAB12ab12
* 输出：
* a:0,a:3,a:4,a:9
* b:1,b:10
* 1:7,1:11
* 2:8,2:12
*
* 直接的方法就是直接两层遍历
* 一个指针p定位，一个指针q扫描，
* 当*p==*q，输出并将*q修改为非字母非数字的字符，比如'*'
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string str;
	while (cin >> str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			int flag = 0;
			if (str[i] != '*') //为*的表示之前已经输出过了，直接跳过
			{
				for (int j = i + 1; j < str.length(); j++)
				{
					if (str[i] == str[j])
					{
						if (flag == 0) //该字符第一次输出
						{
							flag = 1;
							cout << str[i] << ":" << i;
						}
						cout << "," << str[j] << ":" << j;
						str[j] = '*'; //之后就不会再处理了
					}
				}
			}
			if (flag == 1)
				cout << endl;
		}
	}
	return 0;
}
