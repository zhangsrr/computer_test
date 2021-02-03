/*
* 日期类
* Input：
* m yyyy mm dd
* Output：
* yyyy-mm-dd
* 
* 算法1：
* 计算出给定日期为当年第几天，
* if 为该年最后一天则可直接输出
* else if 为当月最后一天 也可直接输出
* else dd+1输出 
* 
* 算法2：
* dd++
* if dd > 当月可能的最大天数
* then dd=1, mm++  
*					if mm>12 
* 	     			then yyyy++，mm=1
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int isLeap(int year) {
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		return 1;
	else return 0;
}

int getYearDay(int year) {
	return (isLeap(year) == 1 ? 366 : 365);
}

int getDayth(int yyyy, int mm, int dd, vector<vector<int>> month) { //该日期为该年第几天
	int countday = 0;
	int flag = isLeap(yyyy);
	
	for (int i = 0; i < mm-1; i++)
		countday += month[flag][i];
	countday += dd;
	return countday;
}

int main() {
	int m = 0;
	int yyyy = 0, mm = 0, dd = 0;
	vector<vector<int>> month = { {31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31} };

	cin >> m;
	vector<vector<int>> caseData(m, vector<int>(3));

	//Input
	for (int i = 0; i < m; i++)
		cin >> caseData[i][0] >> caseData[i][1] >> caseData[i][2]; //yyyy mm dd

	//Output
	for (int i = 0; i < m; i++)
	{
		yyyy = caseData[i][0];
		mm = caseData[i][1];
		dd = caseData[i][2]+1;
		if (dd > month[isLeap(yyyy)][mm-1])
		{
			dd = 1;
			mm++;
			if (mm>12)
			{
				yyyy++;
				mm = 1;
			}
		}
		cout << setw(4) << setfill('0') << yyyy << "-";
		cout << setw(2) << setfill('0') << mm << "-";
		cout << setw(2) << setfill('0') << dd;
		if (i != m - 1)
			cout << endl;
	}
	/*int daycount = 0;
	for (int i = 0; i < m; i++)
	{
		yyyy = caseData[i][0];
		mm = caseData[i][1];
		dd = caseData[i][2];
		daycount = getDayth(yyyy, mm, dd, month);
		if (daycount == getYearDay(yyyy))
		{
			cout << setw(4) << setfill('0') << yyyy + 1 << "-";
			cout << setw(2) << setfill('0') << 1 << "-";
			cout << setw(2) << setfill('0') << 1;
			if (i != m - 1)
				cout << endl;
		}
		else if (caseData[i][2] == month[isLeap(yyyy)][mm-1])
		{
			cout << setw(4) << setfill('0') << yyyy << "-";
			cout << setw(2) << setfill('0') << mm+1 << "-";
			cout << setw(2) << setfill('0') << 1;
			if (i != m - 1)
				cout << endl;			
		}
		else
		{
			cout << setw(4) << setfill('0') << yyyy << "-";
			cout << setw(2) << setfill('0') << mm << "-";
			cout << setw(2) << setfill('0') << dd+1;
			if (i != m - 1)
				cout << endl;
		}
	}*/
}