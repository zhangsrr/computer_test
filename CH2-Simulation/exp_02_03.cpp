/*
* Old Bill
* 五位价格标（单价），*ABC*，首尾模糊
* 给出火鸡总数N、总价和中间三位标价ABC
* 求最大的总价以及对应的火鸡单价
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int x = 0, y = 0, z = 0; //总价格中间三位
	int num = 0; //火鸡总数
	int i = 0, j = 0; //总价格的首尾
	int flag = 0;
	int maxfront = 0, maxtail = 0;
	while (cin >> num)
	{
		cin >> x >> y >> z;
		flag = 0;
		for (int i = 1; i < 10; i++)
		{ //首
			for (int j = 0; j < 10; j++)
			{ //尾				
				if ((i*10000+x*1000+y*100+z*10+j) % num == 0)
				{
					maxfront = i;
					maxtail = j;
					flag = 1;
				}
			}
		}
		if (flag == 1)
			cout << maxfront << " " << maxtail << " " << (maxfront * 10000 + x * 1000 + y * 100 + z * 10 + maxtail) / num << endl;
		if (flag == 0)
			cout << "0" << endl;
	}
}
