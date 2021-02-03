/*
 * 打印日期 年-月-日
 * Input:
 *   year day
 * Output:
 *  year-month-day
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool isLeap(int year) {
	return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

int main() {
	int year = 0, day = 0;
	vector<vector<int>> mon = { {31,28,31,30,31,30,31,31,30,31,30,31}, {31,29,31,30,31,30,31,31,30,31,30,31} };
	while (cin >> year >> day)
	{
		int month = 0;
		int flag = 0;
		if (isLeap(year))
			flag = 1;
		while (day >= 0 && (day - mon[flag][month]) >= 0)
		{ //下一个月还有天数可减
			day = day - mon[flag][month];
			if (day == 0) { //恰为最后一天
				day = mon[flag][month];
				break;
			}
			month++;
		}

		month++; //左侧补零，setw()为限制宽度
		cout << setw(4) << setfill('0') << year << "-" << setw(2) << setfill('0') << month << "-" << setw(2) << setfill('0') << day << endl;
	}
}