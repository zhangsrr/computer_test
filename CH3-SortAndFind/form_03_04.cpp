/*
* 找x
* 输入一个数n，然后输入n个不同的数值，再输入一个值x，输出这个数值在数组中的下标（从0开始，若不在数组中则输出-1）
* 
* Input:
* n 
* data
* x
* 
* Output:
* pos_x
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n = 0, x = 0;
	while (cin >> n)
	{
		vector<int> vec(n);
		for (int i = 0; i < n; i++)
			cin >> vec[i];
		cin >> x;
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			if (vec[i] == x)
			{
				cout << i << endl;
				flag = 1;
				break;
			}
		}
		if (flag==0)
			cout << "-1" << endl;
	}
	return 0;
}
