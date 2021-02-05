/*
* 小白鼠排队
* N只小白鼠(1 <= N <= 100)，每只鼠头上戴着一顶有颜色的帽子。
* 现在称出每只白鼠的重量，要求按照白鼠重量【从大到小】的顺序输出它们头上帽子的颜色。
* 帽子的颜色用“red”，“blue”等字符串来表示
* 不同的小白鼠可以戴相同颜色的帽子。白鼠的重量用整数表示。
* 
* Input：
* 每个案例的输入第一行为一个整数N，表示小白鼠的数目。
* 下面有N行，每行是一只白鼠的信息。
* 第一个为不大于100的【正整数】，表示白鼠的重量；
* 第二个为【字符串】，表示白鼠的帽子颜色，字符串长度不超过10个字符。
* 注意：白鼠的重量各不相同。
* 
* Output：
* 按照白鼠的重量【从大到小】的顺序输出白鼠的帽子【颜色】。
*/
#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 100

typedef struct Mouse {
	int weight;
	string hat;
};

bool comp(Mouse m1, Mouse m2) {
	return m1.weight > m2.weight;
}

int main() {
	int N = 0;
	while (cin >> N)
	{
		Mouse mice[SIZE];
		for (int i = 0; i < N; i++)
			cin >> mice[i].weight >> mice[i].hat;
		sort(mice, mice + N, comp);
		for (int i = 0; i < N; i++)
			cout << mice[i].hat << endl;

	}
}
