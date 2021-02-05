/*
* 叠筐
* 输入：11 B A 表示最外筐边长或高，中心花色inner，最外筐花色
* 
*/

#include <iostream>
using namespace std;

int main() {
	int h = 0;
	char outer, inner;
	int row = 1, col = 1;
	int trow = 0;
	int count = 1;

	while (cin >> h)
	{
		cin >> inner >> outer;
		for (row = 1; row <= h; row++)
		{
			if (row == 1 || row == h)
			{
				cout << " ";
				for (int i = 0; i < h-2; i++)
					cout << outer;
				cout << " ";
			}
			else if (row == 2 || row == h-1)
			{
				cout << outer;
				for (int i = 0; i < h - 2; i++)
					cout << inner;
				cout << outer;
			}
			else if (row <= (h+1)/2)
			{ //上左部分
				for (col = 1; col < row; col++)
				{ //每行左边
					if (col % 2 == 1)
						cout << outer;
					else cout << inner;
				}
				for (; col <= h-(row-1); col++)
				{ //每行中间
					if (row % 2 == 1)
						cout << outer;
					else cout << inner;
				}
				for (; col <= h; col++)
				{ //每行右边
					if (col % 2 == 1)
						cout << outer;
					else cout << inner;			
				}
			}		
			else
			{ //下半部分，不含中心层
				trow = row - 2*count;
				count++;
				for (col = 1; col < trow; col++)
				{ //每行左边
					if (col % 2 == 1)
						cout << outer;
					else cout << inner;
				}
				for (; col <= h - (trow - 1); col++)
				{ //每行中间
					if (trow % 2 == 1)
						cout << outer;
					else cout << inner;
				}
				for (; col <= h; col++)
				{ //每行右边
					if (col % 2 == 1)
						cout << outer;
					else cout << inner;
				}
			}
			cout << endl;
		}
	}
	return 0;
}
