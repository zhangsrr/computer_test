/*
* 坠落的蚂蚁
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N = 0;
	while (cin >> N)
	{
		vector<vector<int>> ants(N, vector<int>(2));
		for (int i = 0; i < N; i++) {
			cin >> ants[i][0] >> ants[i][1];
		}

		sort(ants.begin(), ants.end());
		
		int left = 0, right = 0; //初始向左向右
		int center = 0;

		for (int i = 0; i < ants.size(); i++)
		{ //得到初始静止蚂蚁左边且向右移动的数目left和在右边且向左移动的数目right
			if (ants[i][1] == 0)
				center = i + 1; //第center个蚂蚁静止
			else if (center == 0 && ants[i][1] == 1)
			  //左边且向右移动的 left
				left++;
			else if (i+1 > center && center != 0 && ants[i][1] == -1)
			  //右边且向左移动的 right
				right++;
		}

		/*
		* 先假设一个简单的情况，
		* 1）只有两只蚂蚁，一只A静止，另一只B在静止的左边且向右移动，那么当二者相撞时BA
		* 此时BA交换速度，B静止，A向右移动直到掉下去，经过的时间数值上等于B到边缘的距离
		* 2）有三只蚂蚁，中间A静止，A左边的B向右移动，C向左移动，那么A与二者都发生碰撞后，仍会静止，不会掉落
		* 3）对于2）这种情况，可以理解为BC穿过A继续移动，也就是说我们不需要管在A左边且向左移动的蚂蚁，同理不需要管在A右边且向右移动的蚂蚁
		* 因为这两种情况都不会影响A的掉落
		* 那么只需要得出在A左边且向右移动 与 在A右边且向左移动的蚂蚁个数，记作left和right
		* if left == right 不会掉落
		* if left < right 向左掉落，time = 右边与左边抵消后的第一个蚂蚁到坐标0的距离
		* if left > right 向右掉落，time = 第left-right个蚂蚁到左边100的距离
		*/
		int pos = 0;
		if (left == right)
			cout << "Cannot fall!" << endl;
		else if (left < right) {
			//从左边掉下去
			for (int i = center; i < N; i++)
			{
				if (ants[i][1]==-1)
					pos++;
				if (pos == left+1) {
					cout << ants[i][0] << endl;
					break;
				}
			}			
		}
		else {
			//从右边掉下去
			for (int i = 0; i < center; i++)
			{
				if (ants[i][1] == 1)
					pos++;
				if (pos == left - right) {
					cout << 100 - ants[i][0] << endl;
					break;
				}
			}
		}
	}
	return 0;
}
