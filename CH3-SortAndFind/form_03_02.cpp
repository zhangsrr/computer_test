/*
* 成绩排序
* Input:
* 输入第一行包括一个整数N(1<=N<=100)，代表学生的个数
* 接下来的N行每行包括两个整数p和q，分别代表每个学生的学号和成绩
* Output:
* 按照学生的成绩从小到大进行排序，并将排序后的学生信息打印出来
* 如果学生的成绩相同，则按照学号的大小进行从小到大排序
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> v1, vector<int> v2) { //返回参数是true，表示v1会排在v2前面
	if (v1[1] < v2[1]) //成绩不同，低的在前
		return true;
	else if (v1[1] == v2[1]) //成绩相等
	{
		if (v1[0] < v2[0]) //学号小的在前
			return true;
		else return false;
	}
	return false;
}

int main() {
	int N = 0;
	while (cin >> N)
	{
		vector<vector<int>> stus(N, vector<int>(2));
		for (int i = 0; i < N; i++)
			cin >> stus[i][0] >> stus[i][1];
		sort(stus.begin(), stus.end(), comp);
		for (int i = 0; i < N; i++)
			cout << stus[i][0] <<" " << stus[i][1] << endl;
	}
}
