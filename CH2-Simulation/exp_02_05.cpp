/*
* Hello World for U
* 给定一个长度为N的字符串组成U字形
* U的左垂线（含底）占n1个字符，右垂线（含底）占n3个字符
* 底边占n2个字符，n2=N+2 - (n1+n3)
* n1=n3=max{k | k <= n2 for all 3 <= n2 <= N}
* 要求n1和n2都尽可能大，则只可能是n1==n2或n2-n1==1
* 最后的图形大小为n1*n2
*/
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;


int main() {
	int n1 = 0, n2 = 0;
	int N = 0;
	int left = 0, right = 0;
	string str;
	while (cin >> str)
	{
		auto start = system_clock::now();
		N = str.length();
		//因为n1和n2要尽可能接近，且n2必不小于n1，则可先假设n1==n2，那么n1==N/3
		n1 = (N + 2) / 3;
		n2 = N + 2 - 2 * n1;

		left = 0;
		right = N-1;
		for (int i = 0; i < n1; i++)
		{
			cout << str[left++];
			for (int j = 0; j < n2 - 2; j++)
				i != n1 - 1 ? cout << " " : cout << str[left++];
			cout << str[right--] << endl;
		}
		auto end = system_clock::now();
		auto duration = duration_cast<microseconds>(end - start);
		cout << "TIME: " << double(duration.count()) * microseconds::period::num / microseconds::period::den << " s" << endl;
	}
	return 0;
}
