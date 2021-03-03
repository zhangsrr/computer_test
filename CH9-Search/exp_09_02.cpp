/**
 * 神奇的口袋
 * 有一个口袋，总容积为40，用这个口袋可以变出一些物品
 * 这些物品的总体积必须是40
 * John现在有n个想要得到的物品，每个物品的体积分别是a1,a2,……,an
 * John可以从中选择一些，若选出的物体的总体积是40，则John可以得到这些物品
 * 问：John有多少种不同的选择物品的方式
 * 
 * INPUT:
 * n //表示有多少个不同的物品
 * 接下来n行，每一行一个1到40的正整数，给出a1~an的值
 * OUTPUT:
 * 输出一共有多少只不同的选择方式
 * 
 * e.g.
 * INPUT:
 * 3
 * 20
 * 20
 * 20
 * OUTPUT:
 * 3
 * 
 * TIPS:
 * 和例题9.4类似，先将物品重量降序排序
 * 凑重量，区别在于同一件物品可以出现在不同选择方式中
 * 应用DFS，可以想象成一棵多叉树（森林），每一条从根节点到叶子节点的路径上节点值之和应为40
 * 从头遍历，每一个物品都有成为根节点的机会，且只向后遍历（因为前次必早已包含）
 * 
 **/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int ways=0;
int cut=0;

void DFS(vector<int>& goods, int sum, int pos){
    for (int i = pos; i < goods.size(); ++i)
    {
        if (sum+goods[i] == 40)
            ways++;
        else if (sum+goods[i] > 40)
            DFS(goods, sum, i+1);
        else
            DFS(goods, sum+goods[i], i+1);        
    }
    return;
}

int main(){
    int n=0;
    while (cin >> n)
    {
        vector<int> goods(n);
        for (int i = 0; i < n; ++i)
            cin >> goods[i];
        //sort(goods.begin(), goods.end(), cmp); 为什么排序会出错呢
        ways=0;
        DFS(goods, 0, 0);
        cout << ways << endl;
    }
    return 0;
}