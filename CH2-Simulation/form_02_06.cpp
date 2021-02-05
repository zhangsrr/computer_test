//输出今年的第几天
#include <iostream>
#include <vector>
using namespace std;

bool isLeap(int year) {
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		return true;
	else return false;
}

int getDay(int year, int month, int date, vector<vector<int>> mon) {
	int day = 0;
	if (isLeap(year))
	{ //如果是闰年
		for (int i = 0; i < month-1; i++)
			day += mon[1][i];
		day += date;
	}
	else
	{
		for (int i = 0; i < month - 1; i++)
			day += mon[0][i];
		day += date;
	}
	return day;
}

int main() {
	int year = 0, month = 0, date = 0;
	int day = 0;
	vector<vector<int>> mon = { {31,28,31,30,31,30,31,31,30,31,30,31}, {31,29,31,30,31,30,31,31,30,31,30,31} };
	while (cin >> year)
	{
		cin >> month >> date;
		cout << getDay(year, month, date, mon) << endl;
	}
	return 0;
}
