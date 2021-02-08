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

struct animal{
    int id;
    int order;
};

int main(){
    int n=0,m=0,t=0;
    cin >> n;
    queue<animal> dogs;
    queue<animal> cats;
    animal tmp;
    int flag = 0;
    int getanimal=0; //被领养的动物编号
    for (int i = 0; i < n; i++)
    {
        cin >> m >> t;
        if (m == 1)
        { //收容
            tmp.id = t;
            tmp.order = i;
            if (t > 0) //狗
                dogs.push(tmp);
            else if (t < 0) //猫
                cats.push(tmp);
        }
        else if (m == 2)
        { //领养
            if (t == 0 && (!dogs.empty() || !cats.empty()))
            { //直接领养
                if (dogs.empty())
                { //只剩猫了                    
                    getanimal = cats.front().id;
                    cats.pop();
                }else if (cats.empty())
                { //只剩狗了
                    getanimal = dogs.front().id;
                    dogs.pop();                    
                }else
                {
                    if (dogs.front().order < cats.front().order)
                    { //狗先进
                        getanimal = dogs.front().id;
                        dogs.pop();
                    }else
                    {
                        getanimal = cats.front().id;
                        cats.pop();
                    }                    
                }                
            }
            else if (t == 1 && !dogs.empty())
            { //领养狗
                getanimal = dogs.front().id;
                dogs.pop();       
            } else if (t == -1 && !cats.empty())
            { //领养猫
                getanimal = cats.front().id;
                cats.pop();
            }
            if (getanimal != 0)
            {
                if (flag == 0)
                {
                    cout << getanimal;
                    getanimal = 0;
                    flag = 1;
                }
                else{                    
                    cout << " " << getanimal;
                    getanimal = 0;
                }
            }
        }
    }
    return 0;
}