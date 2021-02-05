/*
* 特殊排序
* 输入一系列整数，将其中最大的数挑出(如果有多个，则挑出一个即可)，
* 并将剩下的数进行升序排序，如果无剩余的数，则输出-1。
* 
* 寻找最大元素先直接排序，控制输出即可
* 根据数组第一个元素是否等于最大元素可以确定是否要输出-1
*/
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N = 0;
	while (cin >> N)
	{
		vector<int> num(N);
		for (int i = 0; i < N; i++)
			cin >> num[i];

		sort(num.begin(), num.end());
		cout << num[N - 1] << endl;

		if (num[0] == num[N-1])
			cout << "-1";
		else
			for (int i = 0; i < N-1; i++) {
				cout << num[i];
				if (i != N - 2)
					cout << " ";
			}
		cout << endl;
	}
	return 0;
}
