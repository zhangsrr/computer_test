/*
* 奥运排序问题
* 按要求，给国家进行排名。
* 给定国家或地区的奥运金牌数、奖牌数、人口数（百万）
* 采用4种排序方式分别进行排名，得出各个国家最高排名以及对应的排名方式，
* 若不同的排名方式得出的最高排名相同则采用编号更小的排名方式，
* 既然4种排名方式都要考虑，且最后选择编号更小的方式，那么就可以直接从编号最大的开始计算
* 
* 4种排序方式编号从小到大：金牌总数，奖牌总数，金牌人口比例，奖牌人口比例
* 
* ！需考虑并列排名
* ！需要考虑金牌总数、奖牌总数、人口数为零的情况，且当：
- 1.金牌总数、人口数均为0时，金牌人口比例为0
- 2.奖牌总数、人口数均为0时，奖牌人口比例为0
- 3.人口数为0，但金牌、奖牌不为0时，金牌奖牌人口比例取无穷大
* 
* Input：
* N M 
* N行各个国家的信息
* M个要排名的国家号（M<=N），即只要对给定的国家进行排名
* 
* Output：
* N个国家各自的最佳排名以及相应的排名方式
* 输出格式：排名:排名方式
* 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Data {
	int nationid; //国家号
	int gold; //金牌数
	int medal; //奖牌数
	int population; //人口数
	float gold_ratio; //金牌人口比例
	float medal_ratio; //奖牌人口比例
	int rank[4]; //四种排名方式下的排名
}Data;

bool gold_amount(Data d1, Data d2) {
	return d1.gold > d2.gold;
}
bool medal_amount(Data d1, Data d2) {
	return d1.medal > d2.medal;
}
bool gold_per(Data d1, Data d2) {
	return d1.gold_ratio > d2.gold_ratio;
}
bool medal_per(Data d1, Data d2) {
	return d1.medal_ratio > d2.medal_ratio;
}
bool order(Data d1, Data d2) {
	return d1.nationid < d2.nationid;
}
int main() {
	int N = 0, M = 0;
	while (cin >> N >> M)
	{
		Data* data = new Data[N];
		for (int i = 0; i < N; i++)
		{
			cin >> data[i].gold >> data[i].medal >> data[i].population;
			data[i].nationid = i;
			//population有可能为0
			if (data[i].population == 0)
			{
				data[i].gold_ratio = data[i].gold == 0 ? 0 : 9999999.0;
				data[i].medal_ratio = data[i].medal == 0 ? 0 : 9999999.0;
			}
			else
			{
				data[i].gold_ratio = (float)data[i].gold / data[i].population;
				data[i].medal_ratio = (float)data[i].medal / data[i].population;
			}
		}

		Data* Nation = new Data[M];
		int id = 0;
		for (int i = 0; i < M; i++)
		{
			cin >> id;
			Nation[i].gold = data[id].gold;
			Nation[i].medal = data[id].medal;
			Nation[i].gold_ratio = data[id].gold_ratio;
			Nation[i].medal_ratio = data[id].medal_ratio;
			Nation[i].nationid = data[id].nationid;
			Nation[i].population = data[i].population;
		}
		sort(Nation, Nation + M, gold_amount); //按金牌总数排名
		int rank = 1; //初始化
		Nation[0].rank[0] = 1; 
		for (int i = 1; i < M; i++)
		{
			if (Nation[i].gold == Nation[i - 1].gold)
				Nation[i].rank[0] = rank;
			else {
				Nation[i].rank[0] = i + 1;
				rank = i + 1;
			}
		}

		sort(Nation, Nation + M, medal_amount); //按奖牌总数排名
		rank = 1; //初始化
		Nation[0].rank[1] = 1;
		for (int i = 1; i < M; i++)
		{
			if (Nation[i].medal == Nation[i - 1].medal)
				Nation[i].rank[1] = rank;
			else {
				Nation[i].rank[1] = i + 1;
				rank = i + 1;
			}
		}

		sort(Nation, Nation + M, gold_per); //按金牌人口比例排名
		rank = 1; //初始化
		Nation[0].rank[2] = 1;
		for (int i = 1; i < M; i++)
		{
			if (Nation[i].gold_ratio == Nation[i - 1].gold_ratio)
				Nation[i].rank[2] = rank;
			else {
				Nation[i].rank[2] = i + 1;
				rank = i + 1;
			}
		}

		sort(Nation, Nation + M, medal_per); //按奖牌人口比例排名
		rank = 1; //初始化
		Nation[0].rank[3] = 1;
		for (int i = 1; i < M; i++)
		{
			if (Nation[i].medal_ratio == Nation[i - 1].medal_ratio)
				Nation[i].rank[3] = rank;
			else {
				Nation[i].rank[3] = i + 1;
				rank = i + 1;
			}
		}

		sort(Nation, Nation + M, order); //按国家号排序
		for (int i = 0; i < M; i++)
		{
			int min = Nation[i].rank[0]; //初始化最高排名以及排名方式
			int method = 1; 
			for (int j = 1; j < 4; j++)
			{
				if (Nation[i].rank[j] < min)
				{
					min = Nation[i].rank[j];
					method = j + 1; //因为j从0开始，但是method输出从1开始
				}
			}
			cout << min << ":" << method << endl;
		}
		cout << endl;
	}
	return 0;
}
