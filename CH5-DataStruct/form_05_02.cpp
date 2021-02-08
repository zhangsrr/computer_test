/**
 * 约瑟夫问题 No.2
 * n个小孩围坐成一圈，并按顺时针编号为1，2，……，n，从编号为p的小孩顺时针依次报数
 * 由1报到m时，这名小孩从圈中出去；
 * 然后下一名小孩再从1报数，报到m时再出去
 * 以此类推,直到所有小孩都从圈中出去
 * 按出去的先后顺序输出小孩的编号
 * INPUT:
 * n p m (0<m,n<300)
 * 最后一行为0 0 0，即测试用例结束
 * 
 * OUTPUT:
 * 按出圈的顺序输出编号，用','分隔
 * 
 **/ 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n=0,p=0,m=0;
    while (cin >> n >> p >> m)
    {
        if (n == 0 && p == 0 && m == 0)
            return 0;
        
        int times=0;
        vector<int> kids(n);
        for (int i = 0; i < n; i++) //便于控制出圈以及输出编号，为0表示不在圈内了
        {
            kids[i] = i+1;
        }
        int i=p-1;
        int flag=0; //控制逗号的输出
        while (count(kids.begin(), kids.end(), 0) != n)
        {
            if (kids[i] != 0) //圈内小孩报数
            {
                times++;
                if (times == m)
                {
                    if (flag == 0) //控制输出格式用逗号分隔
                    {
                        cout << kids[i];
                        flag = 1;
                    }else
                        cout << "," << kids[i];
                    
                    kids[i] = 0; //出圈
                    times = 0;
                }
            }
            i++;
            if (i == n) //循环处理
                i %= n;
        }
        cout << endl;
    }
    return 0;
}
