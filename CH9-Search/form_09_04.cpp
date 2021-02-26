/**
 * Square
 * 给定一系列不同长度的棍子，是否有可能将其首尾连接形成一个正方形square
 * INPUT:
 * N //测试用例的数目
 * 每一个测试用例占一行，第一个数为 M， 其后紧接着M个数表示各根棍子长度len
 * 4<=M<=20, 1<=len<=10000
 * 
 * OUTPUT:
 * yes
 * no
 * 
 * TIPS:
 * 1. 若能形成正方形，则其长度之和必能被4整除
 * 2. 若有长度大于边长的木棍，也不能拼凑为正方形
 * 以sum(len)/4作为tag
 * 将棍子长度升序排列，从第一个开始搜索，加和若超过tag则退回，直到满足其和等于tag
 * 将满足和等于tag的棍子都标记为true
 **/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int side;
int M;

bool DFS(int sum, int number, int position, vector<int>& sticks, vector<bool>& visit){
    //sum表示当前正在凑的边的长度，number表示当前在凑第几条边，position代表sticks的下标
    if (number == 3)
        return true; //已凑齐三条边
    int sample=0; //剪枝
    for (int i = position; i < M; ++i)
    {
        if (visit[i] || sum + sticks[i] > side || sticks[i] == sample) //已使用 或 超出边长 或对于当前已积累的棍子长度不能凑成边长
            continue;
        visit[i] = true; //暂时标记
        if (sum + sticks[i] == side)
        {
            if (DFS(0, number+1, 0, sticks, visit)) 
                return true;
            else
                sample = sticks[i]; //失败棍子长度           
        }else{
            if (DFS(sum+sticks[i], number, i+1, sticks, visit))
                return true;
            else
                sample = sticks[i];            
        }
        visit[i] = false; //不成功则撤回
    }
    return false;
}
bool cmp(int a, int b){
    return a > b;
}

int main(){
    int N;
    while (cin >> N)
    {
        while (N--)
        {
            cin >> M;
            int sum=0;
            vector<int> sticks(M); //保存棍子长度
            vector<bool> visit(M); //记录已访问的
            for (int i = 0; i < M; ++i){
                cin >> sticks[i];
                sum+= sticks[i]; //总长度
            }
            if (sum % 4 != 0) //总长度不能被4整除，则必不能凑成正方形
            {
                cout << "no" << endl; 
                continue;
            }
            side = sum/4; //边长
            sort(sticks.begin(), sticks.end(),cmp); //按长度升序排序
            if (sticks[0] > side) //若最长的棍子比边长还长，则必不能凑成正方形
            {
                cout << "no" << endl;
                continue;
            }
            if (DFS(0,0,0, sticks, visit))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
    return 0;
}