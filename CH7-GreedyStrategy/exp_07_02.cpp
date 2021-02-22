/**
 * To Fill or Not to Fill
 * 有了高速公路，从杭州开车去其他城市都很容易，
 * 但是车的油箱量有限，需要时不时中途找到汽油站加油
 * 不同的加油站油价不同，需要计算得出最便宜的加油方案。
 * 
 * INPUT:
 * Cmax D Davg N //第一行有4个正数
 *               //Cmax<=100油箱最大容量，D<=30000杭州到目标城市的距离，
 *               //Davg<=20每升油可跑的距离，N<=500加油站的总数
 * //接下来是N行，每行有两个数
 * Pi Di         //Pi每升油的价格(浮点数)，Di该加油站离杭州的距离
 * 
 * OUTPUT:
 * 输出用最便宜的加油方案的加油价格 //保留两位小数
 * //假设油箱最初是空的，
 * 如果不能到达终点城市，则输出
 * "The maximum travel distance = X" //without quote, X是该车最长可跑的距离，保留两位小数
 * 
 * TIPS:
 * 对加油站先按距离升序排列，再按油价升序排列
 * 
 * PROCEDURE:
 * 1. 必定要在距离为零的加油站加油
 * 
 * 符号说明：
 * old：当前所在加油站
 * 区间：[dist, dist+maxdist]
 * nearest：最近且价格比old便宜或仅次于old的加油站
 * 
 * 1. 无法到达终点的情况
 * 1.1 没有距离为0的加油站
 * 1.2 当前加油站加满油也无法到达下一个加油站
 * 1.3 最后一个加油站加满油也无法到达终点
 * 
 * 2. 如何加油
 * 2.1 当前加油站是区间内最便宜的加油站，则在当前加满油，然后去下一个加油站
 * 2.2 当前加油站不是区间内最便宜的加油站，则加少量足够去下一个比当前油价便宜的加油站nearest
 * 2.3 对于2.1，要考虑是否区间内可达终点，则只需加足够到终点的油
 * 
 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct GasStation
{
    double Price;
    double Distance;
};

bool cmp(GasStation s1, GasStation s2){
    if (s1.Distance == s2.Distance)
        return s1.Price < s2.Price;
    else
        return s1.Distance < s2.Distance;    
}

int main(){
    double Cmax; //油箱容量
    double D; //目标城市离杭州的距离
    double Davg; //每升油可跑的距离 ，则至少要 D/Davg 升油
    double N; //加油站的总数、
    cout << setiosflags(ios_base::fixed) << setprecision(2);
        
    while (cin >> Cmax >> D >> Davg >> N)
    {
        vector<GasStation> gas_stations(N);
        for (int i = 0; i < N; ++i)
            cin >> gas_stations[i].Price >> gas_stations[i].Distance; //每升油的价格(浮点数)，该加油站离杭州的距离
        sort(gas_stations.begin(), gas_stations.end(), cmp); //先按距离升序，再按价格升序

        if (gas_stations[0].Distance != 0) //1.1
        {
            cout << "The maximum travel distance = 0.00" << endl;
            continue;
        }
        
        double totalprice=0;
        double maxdist = Cmax * Davg; //加油满最多可跑的距离
        int nearest=0; //离当前加油站最近的一个较便宜的加油站
        double tank=0; //油箱剩余油量
        bool ret=true; //flase表示无法到达终点
        for (int i = 0; i < N; ++i)
        {
            if (i == N-1)
            {
                double remainder = D - gas_stations[i].Distance;
                if (remainder <= maxdist)
                { //可达
                    if (tank < remainder/Davg) //油不够，再加一点油便可到达终点
                        totalprice += (remainder/Davg - tank) * gas_stations[i].Price;
                }else{ //1.3
                    cout << "The maximum travel distance = " << gas_stations[i].Distance + maxdist << endl;
                    ret = false;
                }               
                break; 
            }
            
            if (gas_stations[i+1].Distance - gas_stations[i].Distance > maxdist)
            { //1.2 加满油也到不了下一个加油站
                cout << "The maximum travel distance = " << gas_stations[i].Distance + maxdist << endl;
                ret = false;
                break;   
            }
            nearest = i;
            for (int j = i+1; j < N && (gas_stations[j].Distance - gas_stations[i].Distance) <= maxdist; ++j)
            {
                if (gas_stations[j].Price < gas_stations[i].Price)
                {
                    nearest = j;
                    break;
                }                
            }
            if (nearest == i) //2.1 当前加油站是区间内最便宜的，则在old加满                
            {
                if (D - gas_stations[i].Distance <= maxdist) //2.3 如果可达终点
                {
                    if (tank < (D-gas_stations[i].Distance)/Davg)
                    {
                        //油不够，还要加油
                        totalprice+= ((D-gas_stations[i].Distance)/Davg - tank) * gas_stations[i].Price;
                    }
                    break;                    
                }
                totalprice += (Cmax - tank)*gas_stations[i].Price;
                tank = Cmax - (gas_stations[i+1].Distance - gas_stations[i].Distance)/Davg;
            }else //2.2 当前加油站不是区间内最便宜的加油站，则加少量足够去下一个比当前油价便宜的加油站nearest
            {
                double costoil = (gas_stations[nearest].Distance - gas_stations[i].Distance)/Davg;
                if (costoil <= tank){
                    tank -= costoil;
                }else
                {
                    totalprice+=(costoil-tank)*gas_stations[i].Price;
                    tank=0;
                }
                i+=(nearest-i-1); //jump的加油站个数，注意这个语句结束i还有一次自加
            }
        }
        
        if (ret)
            cout << totalprice << endl;
    }
    return 0;
}