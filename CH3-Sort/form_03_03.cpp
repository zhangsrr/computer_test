/*
* 输入任意（用户，成绩）序列，可以获得成绩从高到低或从低到高的排列,
* 相同成绩都按先录入排列在前的规则处理。
* Input:
* N 
* method(排序方法以0降序，1升序表示)
* Name Score
* 
* Output:
* Name Score
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 1000

typedef struct Student {
	string name;
	int score;
	int order;
}Stu;

bool comp1(Stu s1, Stu s2) { //降序
	if (s1.score == s2.score)
		return s1.order < s2.order;
	return s1.score > s2.score;
}

bool comp2(Stu s1, Stu s2) { //升序
	if (s1.score == s2.score)
		return s1.order < s2.order;
	return s1.score < s2.score;
}

int main() {
	int N = 0, method = 0;
	while (cin >> N >> method)
	{
		Stu stu[SIZE];
		for (int i = 0; i < N; i++) {
			cin >> stu[i].name >> stu[i].score;
			stu[i].order = i;
		}
		if (method == 0) //降序
			sort(stu, stu + N, comp1);
		else //升序
			sort(stu, stu+N, comp2);
		for (int i = 0; i < N; i++)
			cout << stu[i].name << " " << stu[i].score << endl;
	}
	return 0;
}