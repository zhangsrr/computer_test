/*
* 输出格式化梯形
* 向右对齐
* 下一行总比上一行多两个**
* 输入为h，表示梯形上底和高
* 梯形有h层，每下层比上层多两个**，第一层为h个**
* 则第二层为h+2
* 第三层h+2*2
* 第h层为h+2*（h-1）=3h-2
* 
* 第i层有h+2*（i-1）个**，有3h-2-h-2(i-1)=2(h-i)个空格
*/

#include <iostream>
using namespace std;

int main() {
	int h = 0;
	int i = 0;
	while (cin>>h)
	{
		for (i = 1; i <= h; i++)
		{
			for (int j = 0; j < 2 * (h - i); j++)
				cout << " ";
			for (int k = 0; k < h+2*(i-1); k++)
				cout << "*";
			cout << endl;
		}
	}
}