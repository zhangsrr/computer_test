/**
 * 代理服务器
 * 已知n个代理服务器的IP地址，要用它们去访问m个服务器
 * 已知这m个服务器的IP地址和访问顺序
 * 系统同一时刻只能使用一个代理服务器，并且不能用代理服务器去访问和它【IP地址相同】的服务器
 * 给出使得代理服务器切换的次数尽可能少的访问方案
 * 
 * INPUT:
 * n //一个整数，代理服务器的个数 1<=n<=1000
 * (接下来n行，每行一个字符串，代表代理服务器的IP地址，【两两不同】)
 * m //一个整数，要访问的服务器的个数 1<=m<=5000
 * (接下来m行，每行一个字符串，代表要访问的服务器的IP地址，按照访问顺序给出，可能有相同的)
 * 
 * 字符串的格式:
 * xxx.yyy.zzz.www
 * 任何一部分都是0-255的整数，不包含空格字符
 * 
 * OUTPUT:
 * 每组输入数据输出一个整数 s，代表按要求访问服务器的过程中切换代理服务器的最少次数，
 * 第一次使用的代理服务器不计入切换次数
 * 若没有符合要求的安排方式，则输出 -1
 * 
 * TIPS:
 * 记代理服务器为P，要访问的服务器为A
 * ①对A每次从游标index处开始遍历（第一次从0开始），
 * ②对P每次从首部开始遍历，同时记录每次【最多】【连续】【成功访问】的服务器个数max，
 * ③IF 所有代理服务器遍历完max仍为0且index!=m，则可确定此次访问失败，退出循环
 * ELSE 更新index，偏移量为max
 * 重复①②③，直到index==m
 * 
 **/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n=0,m=0;
    while (cin >> n)
    {
        vector<string> proxy(n); //代理服务器
        for (int i = 0; i < n; ++i)
            cin >> proxy[i];
        cin >> m;
        vector<string> access(m); //要访问的服务器
        for (int i = 0; i < m; ++i)
            cin >> access[i];

        int index=0; //待访问的服务器游标，直到m时表示访问成功
        int flag=1; //==0则访问失败
        int times=0; //切换次数
        int j = 0;
        while (flag && index < m)
        {
            int max=0; //最多连续访问服务器的个数
            for (int i = 0; i < n; ++i) //遍历所有代理服务器，找到可以最大化访问服务器的代理服务器
            {
                j = index;
                while (proxy[i] != access[j] && j < m)
                    j++;
                if (j - index > max) //确定最多连续可成功访问的服务器个数
                    max = j - index; 
            }            
            if (max == 0)
                flag=0;
            times++;
            index += max;
        }
       
        if (flag)
            cout << times - 1 << endl;
        else
            cout << "-1" << endl;        
    }
    return 0;
}