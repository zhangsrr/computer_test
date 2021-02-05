/*
* 计算一个日期加上若干天后是什么日期
* Input:
* m yyyy-mm-dd day
* Output:
* yyyy-mm-dd
*/
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int isLeap(int year) {
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		return 1;
	else return 0;
}

int main() {
	int m = 0;
	cin >> m;

	vector<vector<int>> mon = { {31,28,31,30,31,30,31,31,30,31,30,31},
													{31,29,31,30,31,30,31,31,30,31,30,31} };
	vector<vector<int>> input(m,vector<int>(4));
	vector<vector<int>> output(m, vector<int>(3));
	int year = 0, month = 0, date = 0;
	int day = 0;
	//输入
	for (int i = 0; i < m; i++)
		cin >> input[i][0] >> input[i][1] >> input[i][2] >> input[i][3];
	
	//处理
	for (int i = 0; i < m; i++)
	{
		year = input[i][0];
		month = input[i][1];
		date = input[i][2];
		day = input[i][3];
		if (day >= mon[isLeap(year)][month - 1] - date)
		{ //调整日期到1号 方便运算
			day = day - (mon[isLeap(year)][month - 1] - date + 1);
			date = 1;
			month++; 
			if (month > 12)
			{
				year++;
				month = 1;
			}
		}
		else {
			date += day;
			day = 0;
		}
		while (day > 0) //day > 0
		{
			if (date+day <= mon[isLeap(year)][month-1])
			{ //累加后还在当月
				date += day;
				break;
			}
			else
			{
				day -= mon[isLeap(year)][month - 1]; 
				month++;
				if (month > 12)
				{
					year++;
					month = 1;
				}
			}
		}
		output[i][0] = year;
		output[i][1] = month;
		output[i][2] = date;
	}

	//输出
	for (int i = 0; i < m; i++)
	{
		cout << setw(4) << setfill('0') << output[i][0] << "-";
		cout << setw(2) << setfill('0') << output[i][1] << "-";
		cout << setw(2) << setfill('0') << output[i][2];
		if (i != m - 1)
			cout << endl;
	}
	return 0;
}
