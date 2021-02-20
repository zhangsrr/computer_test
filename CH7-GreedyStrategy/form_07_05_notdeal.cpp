/**
 * Case of Fugitive
 * 搭桥问题
 * 有n座小岛紧凑地排成一行，为简化问题，小岛起止位置无交叉
 * 第i个小岛的坐标[li,ri], ri<l_(i+1) for 1<=i<=n-1
 * 为了达成这个目的各小岛直接连通，需要在每一对相邻的小岛之间搭桥，
 * 桥的长度记为a，li<= x <=ri, l_(i+1)<= y <=r_(i+1) and y-x=a,即桥长应不短于两岛最短间距，不长于两岛最长间距
 * l_(i+1)-ri <= a <= r_(i+1)-l_i
 * 
 * 现有m架桥，每一架桥最多使用一次，判断这m架桥能否使各岛均连通
 * 
 * INPUT:
 * n m (2<=n<=2x10^5,1<=m<=2x10^5) //岛数和桥数
 * li ri (n行 每座岛起止坐标) //1<=li<=ri<=10^18
 * a1,a2,……,am (m个数 每架桥的长度) //1<=ai<=10^18
 * 
 * OUTPUT:
 * 第一行输出Yes Or No //若桥可以使各岛连通，则输出Yes，否则No
 * 第二行输出n-1个数，b1,b2,……,b_(n-1),代表所用桥的编号，编号从1开始
 * 
 * TIPS:
 * 得到各座岛的坐标后，新建一个数据结构存储两相邻岛之间最短与最长间距，同时存储order，即后一座岛的编号
 * 将岛屿间距按最短间距升序排序，再按最长间距升序排列
 * 再将桥长升序排序，在满足mingap<=a<=maxgap的桥中，选择maxgap最大的岛屿
 * 
 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

typedef long long int ll;

struct Island{
    ll left;
    ll right;
};
struct Gap{
    ll min_gap;
    ll max_gap;
    int order; //岛屿编号，填入的是后一座岛屿，把握输出顺序
    int bridge_order; //搭建的桥的编号
};
struct Bridge
{
    ll length;
    int order; //桥的编号输出时从1开始
};
//岛屿间距按最短间距升序排序，再按最长间距升序排列
bool cmp1(Gap g1, Gap g2){
    if (g1.min_gap == g2.min_gap)
        return g1.max_gap < g2.max_gap;
    else
        return g1.min_gap < g2.min_gap;
}
//再将桥长升序排序
bool cmp2(Bridge b1, Bridge b2){
    return b1.length < b2.length;
}

int main(){
    ll n=0,m=0;
    while (cin >> n >> m)
    {
        vector<Island> islands(n);
        vector<Bridge> bridges(m);
        vector<Gap> gaps(n-1);
        for (ll i = 0; i < n; ++i)
        {
            cin >> islands[i].left >> islands[i].right;
            if (i != 0)
            {
                gaps[i-1].min_gap = islands[i].left - islands[i-1].right;
                gaps[i-1].max_gap = islands[i].right - islands[i-1].left;
                gaps[i-1].order = i-1; //从0开始 
            }             
        }
        for (ll i = 0; i < m; ++i)
        {
            cin >> bridges[i].length;
            bridges[i].order = i; //此处桥编号从0开始，输出时要记得处理
        }
        sort(gaps.begin(), gaps.end(), cmp1);
        sort(bridges.begin(), bridges.end(), cmp2);
        
        //对于同一座桥，可能满足多个岛屿的mingap<=a<=maxgap，应将此桥搭在maxgap最大的间距之间
        //用栈可以找到上述要求的桥
        stack<Gap> myQueue;
        //因为gap先按mingap升序排序，再按maxgap降序排序，所以后者mingap必不小于前者，
        //桥长升序排列
        int pos=0; //gaps的游标
        vector<ll> ans(n-1);
        ll count=0;
        for (int i = 0; i < m; ++i)
        {
            while (!myQueue.empty() && myQueue.top().max_gap < bridges[i].length)
                myQueue.pop();
            //找到满足条件的最长区间
            while (pos < n-1 && bridges[i].length >= gaps[pos].min_gap && bridges[i].length <= gaps[pos].max_gap)
            {
                myQueue.push(gaps[pos]);
                pos++;
            }
            if (!myQueue.empty())
            {
                Gap current = myQueue.top();
                myQueue.pop();
                ans[current.order] = bridges[i].order;
                count++;
            }
        }
        if (count != n-1)
            cout << "No" << endl;
        else
        {
            cout << "Yes" << endl;
            for (int i = 0; i < n-1; ++i)
            {
                if (i != 0)
                    cout << " ";
                cout << ans[i];
            }
        }
    }
    return 0;
}