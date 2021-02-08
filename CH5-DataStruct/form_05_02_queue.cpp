/**
 * 约瑟夫问题 No.2
 * 使用队列进行处理
 * INPUT:
 * n p m
 * n个小孩围成一圈，从编号为p的小孩开始报数，第m个小孩出圈，下一个小孩再从1开始报数，报到m的小孩出圈，
 * 以此类推，直到所有小孩都出圈
 * OUTPUT:
 * 依次输出出圈编号
 **/
#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n=0,p=0,m=0;
    while (cin >> n >> p >> m)
    {
        if (n == 0 && p == 0 && m == 0)
            break;
        
        queue<int> kids;
        for (int i = 1; i <= n; i++)
        {
            kids.push(i);
        }

        for (int i = 1; i < p; i++) //调整队列，使编号为p的小孩在队首
        {
            kids.push(kids.front());
            kids.pop();
        }
        
        int times=0;
        while (!kids.empty())
        {
            times++;
            if (times == m) //如果轮到第m个小孩报数，则输出后直接弹出
            {
                if (kids.size() == 1)
                {
                    cout << kids.front() << endl;
                }else
                {
                    cout << kids.front() << ",";
                }
                                
                kids.pop();
                times=0;
            }else
            {
                kids.push(kids.front());
                kids.pop();
            }
        }
    }
    return 0;
}