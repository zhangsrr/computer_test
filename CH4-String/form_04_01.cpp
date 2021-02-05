/*
* 特殊乘法
* 写个算法，对2个小于1000000000的输入，求结果。 
* 特殊乘法举例：123 * 45 = 1*4 +1*5 +2*4 +2*5 +3*4+3*5
*/
#include <iostream>
using namespace std;

int main() {
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int sum = 0;
		for (int i = 0; i < s1.length(); i++)
		{
			for (int j = 0; j < s2.length(); j++)
			{
				sum += s1[i] * s2[j];
			}
		}
		cout << sum << endl;
	}
	return 0;
}