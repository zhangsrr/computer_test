/**
 * 二叉树
 * 一棵二叉树，自顶向下，从左到右，每个节点升序编号，根节点为1，其左子树的根节点为2，右子树的根节点为3
 * 是一棵完全二叉树，总的结点数为n，问编号为m的节点所在的子树包含多少个节点
 * 
 * INPUT:
 * m n (1<=m<=n<=1000 000 000)
 * OUTPUT:
 * 节点m所在的子树(包括m本身)中包含的结点的数目
 * 
 * ret = m所在节点左子树的节点个数 + m所在节点右子树的节点个数 + 1(本身)
 * 
 * 根据编号特征
 * 任何一个节点m的左右子树的根节点编号分别为 2m与2m+1，即若其满足<=n, 则其在子树中
 **/ 
#include <iostream>
using namespace std;

int nodesum(int id, int n){
    if (id > n)
        return 0;
    else
        return nodesum(2*id, n)+ nodesum(2*id+1, n) + 1; //左子树，右子树，自身
}

int main(){
    int m,n;
    while (cin >> m >> n)
    {
        if (m == 0 || n == 0)
            break;
        cout << nodesum(m, n) << endl;
    }
    return 0;
}