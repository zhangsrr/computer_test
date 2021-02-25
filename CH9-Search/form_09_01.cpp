/**
 * Catch That Cow
 * 有一名农夫已经知晓逃跑的牛的位置，并且想马上抓住它
 * 起始位置，农夫在点N(0<=N<=100000)，牛在点K(0<=K<=100000)
 * 二者在同一根数轴上
 * 现在农夫有两种方式去抓牛：Walking和Teleporting
 * Walking:每分钟内，农夫可以从X的位置移动到X-1或X+1的位置
 * Teleporting:每分钟内，农夫可以从X的位置移动到2X的位置
 * 若牛始终都不会移动，求农夫抓到牛的最短用时是多少？
 * INPUT:
 * N K
 * OUTPUT:
 * 农夫抓到牛的用时(单位:分钟)
 * 
 * e.g.
 * INPUT:
 * 5 17
 * OUTPUT:
 * 4
 * 
 * TIPS:
 * 要想尽快抓到牛，就要求从N到K最短用时
 * 设t时刻，农夫的状态为(n, t)，这表示经时间t，农夫从N到达了n
 * 下一时刻，有三种可能状态，(n-1, t+1), (n+1, t+1), (2n, t+1)
 * 初始状态(N, 0)，终止状态(K, T)
 * 搜索过程类似广度搜索三叉树，找到经过边最少的一条路径
 * 
 * BFS
 *    1
 *  2   3
 * 4 5 6 7
 * 遍历过程：1->(1)23->(2)345->(3)4567
 * ()内的表示出队同时读入其子节点
 **/
#include <iostream>
#include <queue>
using namespace std;

const int MAXN=100001;

struct Status
{
    int n,t;
    Status(int n, int t): n(n), t(t) {}
};

bool visit[MAXN]; 

int BFS(int n, int k){
    queue<Status> myQueue;
    myQueue.push(Status(n,0)); //初始化
    visit[n] = true; //根节点已访问
    while (!myQueue.empty())
    {
        Status cur = myQueue.front(); //访问队头元素
        myQueue.pop();
        if (cur.n == k)
            return cur.t;
        for (int i = 0; i < 3; ++i)
        {
            Status next(cur.n, cur.t+1);
            if (i == 0)
                next.n -= 1;
            else if (i == 1)
                next.n += 1;
            else if (i == 2)
                next.n *= 2; //三种合法状态
            
            if (next.n < 0 || next.n >= MAXN || visit[next.n] == true)
                continue;
            myQueue.push(next);
            visit[next.n] = true;
        }
    }
    return 0;
}

int main(){
    int N,K;
    while (cin >> N >> K)
    {
        cout << BFS(N, K);
    }
    return 0;
}