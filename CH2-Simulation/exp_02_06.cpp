/*
* 日期差值
* 求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天
* 算法：
* 计算出当前日期是该年的第几天，再作差
*/
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int isLeap(int year) {
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		return 1;
	else return 0;
}

int getYearDay(int year) {
	if (isLeap(year))
		return 366;
	else return 365;
}

int main() {
	int countDay = 0;
	vector<int> input(2);
	vector<vector<int>> date(2, vector<int>(3));
	vector<vector<int>> mon = { {31,28,31,30,31,30,31,31,30,31,30,31},
													{31,29,31,30,31,30,31,31,30,31,30,31} };
	while (cin >> input[0] >> input[1])
	{
		countDay = 0;
		if (input[0] > input[1])
		{ //确保后一个日期更大
			int temp = input[1];
			input[1] = input[0];
			input[0] = temp;
		}
		for (int i = 0; i < 2; i++)
		{
			date[i][0] = input[i] / 10000; //year
			date[i][2] = input[i] % 100; //day
			date[i][1] = (input[i] - date[i][0] * 10000) / 100;
		}

		int dayMinus[2] = { 0 };
		for (int i = 0; i < 2; i++)
		{ //得出该日期是今年的第几天
			int flag = isLeap(date[i][0]);
			for (int j = 0; j < date[i][1] - 1; j++)
			{
				dayMinus[i] += mon[flag][j];
			}
			dayMinus[i] += date[i][2];
		}

		if (date[0][0] == date[1][0] && abs(dayMinus[0] - dayMinus[1]) == 1)
			std::cout << "2" << endl;
		else
		{
			int year = date[0][0];
			if (year != date[1][0])
			{ //便于计算，先求出该年剩余天数
				countDay += getYearDay(year) - dayMinus[0] + 1;
				year++;
			}
			while (year != date[1][0])
			{
				countDay += getYearDay(year);
				year++;
			}
			if (date[0][0] != date[1][0])
				countDay += dayMinus[1];
			else
				countDay = dayMinus[1] - dayMinus[0] + 1;
		}
		cout << countDay << endl;
	}
	return 0;
}