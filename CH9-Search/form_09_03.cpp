/**
 * A Knignt's Journey
 * 找到一种方法让骑士遍历棋盘的每一个格子，棋盘大小小于8x8
 * 骑士可以从任一个格子出发，在任一个格子终止，每一个格子只能经过一次
 * 每一步都只能从一个方向偏离一格，从另一个方向偏移两格
 * 
 * 例如：
 *  11  (12)  13  (14)  15 
 * (21)  22   23   24  (25)
 *  31   32  [33]  34   35 
 * (41)  42   43   44  (45)
 *  51  (52)  53  (54)  55
 * 
 * 从33出发，可以去往8个格子，他们是：
 * 12 21
 * 14 25
 * 41 52
 * 45 54
 * 
 * INPUT:
 * n //n个测试用例
 * (下面是n行，每行两个正数p，q，代表pxq的棋盘)
 * p q //1<=p*q<=26，p表示棋盘垂直方向用数字1，2，……，p表示；q表示水平方向用前q个大写字母A，B，……表示
 * 
 * OUTPUT:
 * Scenario #i: //i表示第几个用例，从1开始，每个测试用例之间还有一个空行
 * 给出访问路径  //若有多个解，则输出字母表排序最小的解
 * //每一个格子都是由一个字母和一个数字组成，例如A1
 * //若无法访问所有格子，则输出impossible
 * 
 * TIPS:
 * 默认往编号偏小的且尚未访问过的格子走，直到八个方向都已经被访问过或step==p*q
 * 若此时step==p*q，则输出访问路径
 * 否则impossible
 * 
 * 
 * DFS深度优先搜索，一般不用来求解最优解，而是用来判断问题是否有解
 * 举个栗子：
 * 一个二叉树
 *     1
 *   2   3
 *  4 5 6 7
 * DFS:
 * 1-> 12 -> 124 -> 125 
 *  -> 12 -> 1 -> 13 -> 136 
 *  -> 137 -> 13 -> 1 -> nop
 * 向下搜索直到该节点的左右节点均被访问才弹出该节点
 **/ 
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int p,q;

int directions[8][2] = {
    //x,y 分别对应 q,p 访问顺序按q递增
    {-2,-1},{-2,1},{-1,-2},{-1,2},
    {1,-2},{1,2},{2,-1},{2,1}
};

bool DFS(int x, int y, int step, string ans, vector<vector<bool>> &visit){
    if (step == p*q)
    {
        cout << ans << endl;
        return true;
    }else{
        for (int i = 0; i < 8; ++i)
        {
            //依次访问邻居节点
            int nx=x+directions[i][0];
            int ny=y+directions[i][1];
            char col = nx+'A';
            char row = ny+'1';
            if (nx < 0 || nx >= q || ny < 0 || ny >= p || visit[nx][ny])
                continue;
            visit[nx][ny] = true;
            if (DFS(nx, ny, step+1, ans+col+row, visit)) //深度优先搜索
                return true;
            
            visit[nx][ny] = false;
        }
    }
    return false;
}

int main(){
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Scenario #" << i+1 << ":" << endl;
            cin >> p >> q;
            vector<vector<bool>> visit(q,vector<bool>(p));
            visit[0][0] = true; //从A1开始
            if (!DFS(0,0,1,"A1", visit))
                cout << "impossible" << endl;
            cout << endl;
        }
        
        /**
         * 若p = 4， q = 3
         * 则棋盘为
         *   A B C x:q:col
         * 1
         * 2
         * 3
         * 4
         * y:p:row
         * 规定范围顺序是【最左】最上到【最右】最下，按列访问
         * 记横坐标为x(字母递增),纵坐标为y(数字递增)
         * 每次可选格子依次为
         * x-2,y-1
         * x-2,y+1
         * x-1,y-2
         * x-1,y+2
         * x+1,y-2
         * x+1,y+2
         * x+2,y-1
         * x+2,y+1
         **/ 
    }
    return 0;
}