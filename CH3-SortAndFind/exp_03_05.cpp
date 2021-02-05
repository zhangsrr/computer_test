/*
* 找最小数
* 第一行输入一个数n（1 <= n <= 1000），
* 下面输入n行数据，每一行有两个数，分别是x y。
* 输出一组x y，该组数据是所有数据中x最小，且在x相等的情况下y最小的。 
* 
* 也就是在n组数据中，先以x为基准，找到x最小的数对，再对这些数对，以y为基准，找到y最小的数对
* 
* Input：
* n
* data_n(x y)
* 
* Output：
* x y
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair
{
	int x;
	int y;
};

bool cmp(Pair v1, Pair v2) {
	if (v1.x == v2.x)
		return v1.y < v2.y;
	else
		return v1.x < v2.x;
}

int main() {
	int n = 0;
	while (cin>>n)
	{
		vector<Pair> vec(n);
		for (int i = 0; i < n; i++)
			cin >> vec[i].x >> vec[i].y;
		sort(vec.begin(), vec.end(), cmp);
		cout << vec[0].x << " " << vec[0].y << endl;
	}
}
