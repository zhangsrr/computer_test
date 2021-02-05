/*
* 与7无关的数
* 一个正整数，如果能被7整除或它的十进制表示法中某一个位数上的数字为7，那么称其为与7有关的数
* 现求所有小于等于n(n<100)的与7无关的正整数的平方和
*/
#include <iostream>
#include <cstdio>
using namespace std;

bool is_related(int n) {
	//判断数字n的某个位数上的数字为7，是返回true，否则返回false
	int x = 0;
	while (n!=0)
	{
		x = n % 10;
		if (x == 7)
			return true;
		n = n / 10;
	}
	return false;
}

int main() {
	int n = 0;
	long long int sum = 0;
	while (scanf("%d", &n) != EOF) //C++11可运行
	{
		for (int i = 0; i <= n; i++)
		{
			if ((i % 7 != 0) && !is_related(i))
			{
				sum += i * i;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
