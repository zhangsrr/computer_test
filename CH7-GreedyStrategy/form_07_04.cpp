/**
 * 今年暑假不AC
 * 假设你已经知道了所有你喜欢看的电视节目的转播时间表，你会合理安排吗？
 * 目标是能看尽量多的【完整节目】
 * INPUT:
 * (要考虑多个测试用例)
 * n (n<=100) //节目总数，n==0表示结束
 * Ti_s Ti_e //第i个节目起止时间 (n行数据，每行两个数据)，为简化问题，每个时间都用一个整数表示
 * 
 * OUTPUT:
 * 输出能完整看到的节目个数
 * 
 * TIPS:
 * 对每一个节目用结构体表示
 * 为了尽可能看到更多的完整节目，应优先持续时间短的，
 * 则需对输入的节目进行排序处理
 * 1. 优先起始时间小的
 * 2. 优先持续时间短的
 * 
 **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Show{
    int start;
    int end;
    int last; //节目持续时间 end
};

bool cmp(Show s1, Show s2){
    if (s1.start == s2.start)
        return s1.last < s2.last;
    else
        return s1.start < s2.start;
}

int main(){
    int n=0;
    while (cin >> n)
    {
        if (n == 0)
            break;
        vector<Show> shows(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> shows[i].start >> shows[i].end;
            shows[i].last = shows[i].end - shows[i].start;
        }
        sort(shows.begin(), shows.end(), cmp);
        int time=0; //时间点 
        int i=1; //节目索引
        int count=0; //可看的完整节目数
        /**
         * 经过排序，前一个节目的起始时间必不小于后一个节目的起始时间
         * 且前一个节目的持续时间必不小于后一个节目的持续时间
         * 
         * 若当前时间点<=后一个节目的起始时间，则可看后一个节目
         * 否则就遍历直到满足上述条件
         **/ 

        while (i < n)
        {
            if (time <= shows[i].start)
            {
                count++;
                time = shows[i].end;
                i++;
            }else
            {
                while (time > shows[i].start && i < n)
                    i++;
            }
        }
        cout << count+1 << endl;
    }
    return 0;
}