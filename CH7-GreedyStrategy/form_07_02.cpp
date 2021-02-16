/**
 * FatMouse' Trade
 * FatMouse准备了M磅的猫粮，打算与守仓库的猫做交易，换取FatMouse最爱的食物JavaBean
 * 仓库有N间房，第i个房间有J[i]磅JavaBean，需要F[i]磅的猫粮换取
 * FatMouse不需要换取房间所有的食物，
 * 已知它如果付出a% * F[i]的猫粮可以换取a% * J[i]的JavaBean
 * a是个实数，求FatMouse最多可以换取多少JavaBeans
 * 
 * INPUT:
 * M N(M,N是非负整数)
 * (接下来N行，每行有两个非负整数)
 * J[i] F[i] //房间内粮食数 所需的猫粮数，各个房间所需多少没有比例关系
 * 
 * 有多个测试用例
 * 以-1 -1输入标识所有测试用例输入结束
 * 所有整数不超过1000
 * 
 * OUTPUT:
 * 每一个测试用例输出一行
 * 最多可以换取的JavaBeans
 * 保留三位小数
 **/
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Trade{
    int JavaBeans;
    int Food;
    float BeansPerFood;
}Trade;

typedef vector<Trade> vec;

bool cmp(Trade t1, Trade t2){
    return t1.BeansPerFood > t2.BeansPerFood;
}

int main(){
    /**
     * 根据贪心算法，此题可转化为M元钱可以购买多少物品
     * 将输入的J[i] F[i]相除，得到每磅猫粮可以换取的JavaBeans数，然后降序排列
     * 因为同一个房间可以等比例兑换物品，所以只需一次遍历，直到钱数非正即可
     **/ 
    int M=0,N=0;
    while (cin >> M >> N)
    {
        if (M == -1 && N == -1)
            break;

        vec trade(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> trade[i].JavaBeans >> trade[i].Food;
            trade[i].BeansPerFood = (float)trade[i].JavaBeans/trade[i].Food;
        }
        sort(trade.begin(), trade.end(), cmp);
        
        float amount=0;
        for (int i = 0; i < N && M > 0; ++i)
        {
            if (M-trade[i].Food >= 0) //当前房间还可全额兑换
            {
                M-=trade[i].Food;
                amount += trade[i].JavaBeans;
            }else
            {
                amount += trade[i].BeansPerFood * M;
                M = 0;
            }   
        }
        
        cout << setiosflags(ios_base::fixed) << setprecision(3) << amount << endl; //保留三位小数
    }
    return 0;
} 