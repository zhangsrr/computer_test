/*
* 整数奇偶排序
* 输入10个整数(0~100)，彼此以空格分隔。重新排序以后输出(也按空格分隔)，
* 要求: 
* 1.先输出其中的奇数,并按从大到小排列； 
* 2.然后输出其中的偶数,并按从小到大排列。
* 
* 可以在输入的时候就直接分两个数组存放，那么就可以直接调用sort
* 或者输入完再重新排序，将奇数放在前一部分，重新编写一个sort的比较函数即可实现优先奇数，两个奇数大数在前，两个偶数小数在前的效果
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 10

bool comp(int x, int y) {
	return x > y;
}

bool cmp(int x, int y) {
	if (x%2 != y%2)
		return x % 2 != 0;
	else
	{
		if (x % 2 == 1)
			return x > y;
		else
			return x < y;
	}
}

int main() {
	////方法1 分开存放
	//int num = 0;
	//int count = 0; //控制输入结束后数据的处理输出
	//vector<int> odd;
	//vector<int> even;

	//while (cin >> num)
	//{
	//	count++;
	//	if (num % 2 == 1)
	//		odd.push_back(num);
	//	else even.push_back(num);

	//	if (count == 10)
	//	{ //输入结束
	//		sort(odd.begin(), odd.end(), comp);
	//		sort(even.begin(), even.end());
	//		for (int p1 = 0; p1 < odd.size(); ++p1) {
	//			cout << odd[p1];
	//			if (p1 != 9)
	//				cout << " ";
	//		}
	//		for (int p2 = 0; p2 < even.size(); ++p2) {
	//			cout << even[p2];
	//			if (p2 != 9)
	//				cout << " ";
	//		}
	//		cout << endl;
	//		count = 0;
	//		odd.clear();
	//		even.clear();
	//	}
	//}

	//方法2
	vector<int> num(SIZE);
	while (cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4] >> num[5] >> num[6] >> num[7] >> num[8] >> num[9])
	{
		sort(num.begin(), num.end(), cmp);
		for (int i = 0; i < SIZE; i++)
		{
			if (i != 0)
				cout << " ";
			cout << num[i];
		}
	}

	return 0;
}
