/*
* 查找
* 输入数组长度n，输入数组 a[1...n]，输入查找个数m，输入查找数字b[1...m]
* 对每一个查找的数字分别输出 YES or NO  
* 在数组中查找到则YES，否则NO 。
* 
* Input：
* n
* data_n
* m
* x_m
* 
* Output：
* (m行)
* YES or NO
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool BinarySearch(vector<int> vec, int x) {
	int left = 0;
	int right = vec.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2; 
		//int mid = left + (right - left) / 2;
		if (vec[mid] < x)
			left = mid + 1;
		else if (vec[mid] > x)
			right = mid - 1;
		else return true;
	}
	return false;
}


int main() {
	//线性遍历
	/*int n = 0;
	while (cin >> n)
	{
		vector<int> vec(n);
		for (int i = 0; i < n; i++)
			cin >> vec[i];

		int m = 0;
		cin >> m;
		vector<int> x(m);
		for (int i = 0; i < m; i++)
			cin >> x[i];

		for (int i = 0; i < m; i++)
		{
			int flag = 0;
			for (int j = 0; j < n; j++)
			{
				if (vec[j] == x[i])
				{
					flag = 1;
					cout << "YES" << endl;
					break;
				}
			}
			if (flag == 0)
				cout << "NO" << endl;
		}
	}*/

	//二分查找
	int n = 0;
	while (cin >> n)
	{
		vector<int> vec(n);
		for (int i = 0; i < n; i++)
			cin >> vec[i];

		sort(vec.begin(), vec.end());

		int m = 0;
		cin >> m;
		int x = 0;
		for (int i = 0; i < m; i++) {
			cin >> x;
			if (BinarySearch(vec, x))
				cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}
