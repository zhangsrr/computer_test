/**
 * Senior's Gun
 * 薛杰杰有 n 把枪，每把枪的攻击力为 a[i]
 * 有一天，她外出遇到了 m 只野兽，每只野兽的防御力是 b[j]
 * 薛杰杰使用枪i射杀野兽j，需满足a[i]>=b[j]
 * 射杀成功，得到a[i]-b[j]的奖励分
 * 每把枪最多只能用来射杀一只野兽，且每只野兽最多被一把枪射杀
 * 求最高可获得多少奖励分
 * 
 * INPUT:
 * T (测试用例的数目)
 * (每组测试用例有三行)
 * (第一行)n, m
 * (第二行)n个整数，代表每把枪的攻击力
 * (第三行)m个整数，代表每只野兽的防御力
 * 
 * OUTPUT:
 * 最高可获得的奖励分
 **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T=0;
    cin >> T;
    while (T--)
    {
        int n=0,m=0;
        cin >> n >> m;
        vector<int> guns(n);
        vector<int> monster(m);
        for (int i = 0; i < n; ++i)
            cin >> guns[i];
        for (int i = 0; i < m; ++i)
            cin >> monster[i];
        /**
         * 类似田忌赛马
         * 为了获取最高的奖励分，应该选择最高攻击力的枪去打最低防御力的野兽
         * 每把枪只能攻击一次，每只野兽也只能被攻击一次
         **/

        sort(guns.begin(), guns.end());
        sort(monster.begin(), monster.end());
        int score=0;
        for (int i = n-1, j = 0; i >= 0 && j < m; --i, ++j)
        {
            if (guns[i] >= monster[j])
                score += guns[i]-monster[j];
            else
                break;            
        }
        cout << score << endl;
    }
    return 0;    
}