/**
 * 鸡兔同笼
 * 一只笼子里面关了鸡和兔子（鸡2只脚，兔子4只脚）
 * 已知笼子里脚总数是a，问笼子里至少有多少只动物，至多有多少只动物
 * 
 * INPUT:
 * a(a<32768)
 * 
 * OUTPUT:
 * 每行两个整数
 * 第一个是最少的动物数min，第二个是最多的动物数max
 * 若没有满足要求的答案，则输出两个0
 * 
 * 设有鸡x，兔子y
 * 2x+4y==a
 * 显然
 * if a%2==1 then output 0 0
 **/
#include <iostream>
using namespace std;

int main(){
    int a=0;
    while (cin >> a)
    {
        if (a%2 == 1 || a == 0)
            cout << "0 0" << endl;
        else
        {
            int minA=0, maxA=0;
            //可以整除2，则最多就全是鸡
            //可以整除2，则最少的情况是1只鸡，其余全是兔子 或 没有鸡全是兔子
            maxA = a/2;
            if (a % 4 == 0)
                minA = a/4;
            else
                minA = a/4 + 1;                       
            cout << minA << " " << maxA << endl;            
        }
        
    }
    return 0;    
}