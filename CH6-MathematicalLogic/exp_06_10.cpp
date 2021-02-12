/**
 * A+B for Matrices
 * 计算矩阵A+B，并统计结果中全为0的行和列的数目
 * INPUT:
 * M N (0<M,N<=10 正整数)代表矩阵的行和列数
 * 接下来2M行，每行包括N列，分别是A、B各个元素Pij，Pij∈[-100,100],用空格分隔
 * 
 * 前M行是A，后M行是B
 * 当M=0时表示终止，不做处理
 * 
 * OUTPUT:
 * 输出A+B中全为0的行和列的数目之和
 **/
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> ivec;


int main(){
    int M=0,N=0;
    while (cin >> M)
    {
        if (M==0)
            break;
        cin >> N;
        ivec A_Matrix(M, vec(N));
        ivec B_Matrix(M, vec(N));
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                cin >> A_Matrix[i][j];
                
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                cin >> B_Matrix[i][j];
                
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                A_Matrix[i][j] += B_Matrix[i][j];
        
        int rows=0,cols=0;
        //数全为0的行数
        for (int i = 0; i < M; ++i)
        {
            int times=0;
            for (int j = 0; j < N; ++j)
            {
                if (A_Matrix[i][j] == 0)
                    times++;
                else
                    break; //有一个元素不为零则不需要再计算
            }
            if (times==N)
                rows++;
        }
        for (int j = 0; j < N; ++j)
        {
            int times=0;
            for (int i = 0; i < M; ++i)
            {
                if (A_Matrix[i][j] == 0)
                    times++;
                else
                    break;                
            }
            if (times == M)
                cols++;
        }
        cout << rows+cols << endl;
        
    }
    return 0;
}