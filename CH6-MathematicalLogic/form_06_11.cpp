/**
 * 计算两个矩阵的乘积
 * 输入两个矩阵，一个为2*3的矩阵，另一个为3*2的矩阵
 * INPUT:
 * 两个矩阵元素
 * OUTPUT:
 * 一个2*2的矩阵，每一个数字后都跟一个空格
 * 
 * 矩阵乘法
 * A:
 * 00 01 02
 * 10 11 12
 * 
 * B:
 * 00 01
 * 10 11
 * 20 21
 * 
 **/
#include <iostream>
#include <vector>
using namespace std;
#define ROW 2
#define COL 3

typedef vector<int> vec;
typedef vector<vec> ivec;

void MatrixMulti(ivec A, ivec B, ivec& ans){
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < ROW; j++)
            for (int k = 0; k < COL; k++)
                ans[i][j] += A[i][k]*B[k][j];            
}

int main(){
    ivec A(ROW, vec(COL));
    ivec B(COL, vec(ROW));
    ivec ans(ROW, vec(ROW));
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            cin >> A[i][j];
    
    for (int i = 0; i < COL; i++)
        for (int j = 0; j < ROW; j++)
            cin >> B[i][j];
    MatrixMulti(A,B,ans);
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < ROW; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}