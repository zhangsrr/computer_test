/**
 * 玛雅人的密码
 * 玛雅人有一种密码，若字符串中出现连续的2012四个数字时就能解开密码。
 * 给定一个长度为N的字符串(2<=N<=13)，该字符串中只含有0，1，2三个数字，
 * 问这个字符串要移位几次才能解开密码，每次只能移动相邻的两个数字
 * 
 * INPUT:
 * N    //2<=N<=13
 * 一个长度为N的字符串
 * OUTPUT:
 * 最少的移位次数，如果无论移位多少次都解不开密码，则输出-1
 * 
 * e.g.
 * INPUT:
 * 5
 * 02120 //经一次移位可以得到20120，01220，02210，02102
 * OUTPUT:
 * 1 
 * 
 * TIPS:
 * 1. 若字符串中，0的个数小于1，或 1的个数小于1， 或 2的个数小于2，则必然不会有2012这四个数
 * 
 * 初始状态就是原始string
 * 那么每一个状态的扩展状态就有string.length()个
 * 2. 可以用visit数组标记已扩展的状态，但是消耗的内存会很大，MAXN=1 000 000 000 000 00
 *    是否可以考虑用map
 * 3. 如何判断字符串中存在连续的2012呢？难道每一次都要遍历吗，此处倒可以结合KMP，但没写了
 * 
 **/
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
map<string,bool> visit;

struct Status
{
    string str;
    int step;
    Status(string str, int step): str(str), step(step){}
};


bool Match(string str){ 
    //这里有更简单的方法，利用字符串的find
    //return (str.find("2012") != string::npos);
    
    int flag = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == '2' && flag == 0)
            flag++;
        else if (str[i] == '0' && flag == 1)
            flag ++;
        else if (str[i] == '1' && flag == 2)
            flag ++;
        else if (str[i] == '2' && flag == 3){
            flag ++;        
            break;
        }
        else
            flag = 0;      
    }
    return flag == 4;   
}
void BFS(string str){
    if (count(str.begin(), str.end(), '0') < 1 || 
        count(str.begin(), str.end(), '1') < 1 ||
        count(str.begin(), str.end(), '2') < 2) {
        cout << "-1" << endl;
        return;
    }
    int times=0;
    queue<Status> myQueue;
    myQueue.push(Status(str, 0));
    visit.insert(pair(str, true));
    while (!myQueue.empty())
    {
        //弹出队头元素，再扩展
        Status Front=myQueue.front();
        myQueue.pop();
        if (Match(Front.str)){
            cout << Front.step << endl;
            return;
        }
        
        for (int i = 0; i < Front.str.length()-1; ++i)
        {
            //扩展状态一共有Front.length()-1个
            Status tmp = Front;
            tmp.step++;
            char ch = tmp.str[i];
            tmp.str[i] = tmp.str[i+1];
            tmp.str[i+1] = ch;
            auto it=visit.find(tmp.str);
            if (it == visit.end()) //这个字符串还未出现在队列中过
            {
                myQueue.push(tmp);
                visit.insert(pair(tmp.str,true));
            }
        }        
    }
}

int main(){
    int n;
    string str;
    while (cin >> n >> str)
    {        
        BFS(str);
    }
    return 0;
}