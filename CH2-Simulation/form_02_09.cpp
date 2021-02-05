/*
* 剩下的树
* 相当于给定一段大区间，要从中挖去M段小区间
* 可以创建一个长度为L+1的数组，初始化全为1
* 处理每一组数据，就进行一次循环，将对应位置置为0
* 最后输出该数组1的个数
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int L = 0, M = 0;
	cin >> L >> M;
	vector<int> Tree(L + 1, 1); //初始化全为1

	int a = 0, b = 0;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		for (int j = a; j <= b; j++)
			Tree[j] = 0;
	}

	int sum = 0;
	for (int i = 0; i < L+1; i++)
		if (Tree[i] == 1)
			sum++;
	cout << sum;
	return 0;
}
