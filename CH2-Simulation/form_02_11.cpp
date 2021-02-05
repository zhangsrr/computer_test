/*
* xxx定律
* 对于一个数n，
* 如果是偶数，就把n砍掉一半；
* 如果是奇数，把n变成 3*n+ 1后砍掉一半，直到该数变为1为止。     
* 请计算需要经过几步才能将n变到1
*/
#include <iostream>
using namespace std;

int main() {
	int n = 0;
	while (cin >> n)
	{
		int times = 0;
		if (n == 0)
			return 0;
		while (n != 1)
		{
			if (n % 2 == 0) 
				n /= 2;
			else 
				n = (3 * n + 1) / 2;
			times++;
		}
		cout << times << endl;
	}
	return 0;
}
