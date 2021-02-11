/**
 * 矩阵幂
 * 给定一个nxn的矩阵P，求该矩阵的k次幂
 * INPUT:
 * n k (2<=n<=10, 1<=k<=5)
 * n行 每行n个正整数，且0<=Pij<=10
 * 保证数据结果不超过10^8
 * 
 * OUTPUT:
 * 输出结果，用空格隔开，且每列最后一个数字后无空格
 **/
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> ivec;

ivec MatrixMulti(ivec x, ivec y){
    //将x*y的结果赋值给ans,因为这里如果使用引用的话，将会导致结果算出来是中间结果的多个矩阵累加，而不是幂，且会溢出
    ivec ans(x.size(), vec(x[0].size()));
    for (int i = 0; i < x.size(); i++)
        for (int j = 0; j < x[i].size(); j++){
            ans[i][j] = 0;
            for (int k = 0; k < x.size(); k++)
                ans[i][j] += x[i][k] * y[k][j];
        }
    return ans;
}

void PrintMatrix(ivec ans){
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            if (j != 0)
                cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }
    return;    
}
void FastMatrix(ivec A, ivec& ans, int k){
    //初始化为单位矩阵，为什么要初始化为单位矩阵，因为EA=A
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            if (i == j)
                ans[i][j] = 1;
            else
                ans[i][j] = 0;            
        }
    }

    while (k != 0)
    {
        if (k%2 == 1) //奇次幂则要多乘一次
            ans = MatrixMulti(ans, A);
        k/=2;
        A = MatrixMulti(A, A);
    }
    return;
}

int main(){
    int n=0,k=0;
    while (cin >> n >> k)
    {
        ivec ans(n, vec(n));
        ivec A(n, vec(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> A[i][j];
        
        FastMatrix(A, ans, k);
        PrintMatrix(ans);
    }
    return 0;
}