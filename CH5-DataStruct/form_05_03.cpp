/**
 * 猫狗收容所
 * 有两种收养方式
 * 1. 直接收养所有动物中最早进入收容所的
 * 2. 选择收养的动物类型，并收养该种动物中最早进入收容所的
 * 
 * 给定一个操作序列代表所有事件
 * 若第一个元素为1，则代表有动物进入收容所，
 * 第二个元素为动物的编号，正数为狗，负数为猫，
 * 
 * 若第一个元素为2，则代表有人收养动物，
 * 第二个元素若为0，则采取第一种收养方式
 * 第二个元素若为1，则指定收养狗
 * 第二个元素若为-1，则指定收养猫
 * 
 * 按顺序输出收养动物的序列
 * 若出现不合法的操作，则没有可以符合领养要求的动物，忽略此次操作
 * 
 * INPUT:
 * n 代表操作序列的次数
 * 接下来n行，每行两个值
 * m t代表操作的两个元素
 * 
 * OUTPUT:
 * 按顺序输出收养动物的序列
 **/
#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n=0,m=0,t=0;
    cin >> n;
    queue<int> all;
    int animal=0;
    int flag=0;
    while (n--)
    {
        cin >> m >> t;
        /**
         * 收容：
         * 直接存放到同一个队列
         * 领养：
         * ==0则直接pop
         * ==1且队首不为狗，则队首元素放到队尾，pop队首，再输出新队首且pop
         *                  输出后，再将原队首重新放置到队首
         * ==-1同==1
         **/ 
        if (m == 1)
        {
            if (t != 0)
                all.push(t);       
        }else if (m == 2 && !all.empty())
        {
            if (t == 0)
            { //直接领养            
                animal = all.front();  
                all.pop();
            }
            else if (t == 1 || t == -1)
            {
                if ((t == 1 && all.front() < 0) || (t == -1 && all.front() > 0))
                { //领养狗但队首是猫 或 领养猫但队首是狗 都需要调整
                    all.push(all.front());
                    all.pop();
                    
                    if (all.size() == 1)            
                        cout << all.front();
                    else
                        cout << " " << all.front();      
                    all.pop();    

                    for (int i = 0; i < all.size()-1; i++)
                    {
                        all.push(all.front());
                        all.pop();
                    }            
                } else
                {
                    animal = all.front();    
                    all.pop();  
                }
            }
            if (flag == 0)
            {
                flag = 1;
                cout << animal;
            }else
                cout << " " << animal;
        }
    }
    return 0;
}