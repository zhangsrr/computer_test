/*
* 打印极值点下标
* 在一个整数数组上，对于下标为i的整数，
* 如果它【大于所有】它相邻的整数，或者【小于所有】它相邻的整数，
* 则称为该整数为一个极值点，极值点的下标就是i。
* 
* 其实就是在一个数组中寻找这样的值的下标：
* 1. 非边界点，满足其值同时小于或同时大于其左右点的值
* 2. 起始点，满足其值小于或大于其右边的值
* 3. 末尾点，满足其值小于或大于其左边的值
* 
* Input：
* k (amount of elements)
* data_k (k elements)
* 
* Output：
* 符合条件的所有极值点下标，对于同一个数组的数据以空格分隔
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int k = 0;
	while (cin >> k)
	{
		vector<int> data(k);
		for (int i = 0; i < k; i++)
			cin >> data[i];
		for (int i = 0; i < k; i++)
		{
			if (i == 0 && (data[i] < data[i + 1] || data[i] > data[i + 1]))
				cout << "0 ";
			else if (i == k - 1 && (data[i] < data[i - 1] || data[i] > data[i - 1]))
				cout << i;
			else if ((data[i] < data[i - 1] && data[i] < data[i + 1]) || (data[i] > data[i - 1] && data[i] > data[i + 1]))
				cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}
