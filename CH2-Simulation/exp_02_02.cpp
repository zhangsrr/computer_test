/*
* 百鸡问题
* n元买100只鸡，大鸡5元/只，小鸡有3元/只和1/3元/只的两种，分别记为x, y, z只
* 求解xyz的所有可能解，允许花费为非整数
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n = 0;
	int x = 0, y = 0, z = 0;
	int i = 0, j = 0, k = 0;
	while (cin>>n)
	{
		for (i = 0; i <= 100; i++)
		{
			for (j = 0; j <= 100; j++)
			{
				for (k = 0; k <= 100; k++)
				{
					if ((i+j+k == 100) && (5*i + 3*j + (float)k/3 <= n))
					{
						cout << "x=" << i << ",y=" << j << ",z=" << k << endl;
					}
				}
			}
		}
	}
}