/*
* Day of Week
* Input:
* day NameofMonth year
* Output:
* Name of Week
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int matchName(string s, vector<string> vec) {
	auto pos = find(vec.begin(), vec.end(), s);
	if (pos == vec.end())
		return -1;
	else
		return distance(vec.begin(), pos);
}

int isLeap(int year) {
	if ((year % 400==0) || (year % 4 == 0 && year % 100 != 0))
		return 1;
	else return 0;
}

int getYearDay(int year) {
	int yearDay = 0;
	for (int i = 1; i < year; i++)
	{
		if (isLeap(i))
			yearDay += 366;
		else
			yearDay += 365;
	}
	return yearDay;
}

int main() {
	vector<string> Month = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	vector<string> Week = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	
	int day = 0, year = 0;
	string mm;
	int daycount = 0;
	vector<vector<int>> month = { {31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31} };

	while (cin >> day >> mm >> year)
	{
		//公元1年1月1日为星期一
		daycount = getYearDay(year);
		int mpos = matchName(mm, Month); //1月的返回值为0
		for (int i = 0; i < mpos; i++)
		{
			daycount += month[isLeap(year)][i];
		}
		daycount += day;
		cout << Week[daycount % 7] << endl;
	}
	return 0;
}
