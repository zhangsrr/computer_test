/**
 * 堆栈的使用
 * 
 * INPUT:
 * 正整数n (0<n<=10000)，n=0结束
 * n行
 * 每行第一个字符可能是'P','O','A'
 * 若为P，后面还会跟一个整数，表示把这个数据压入堆栈
 * 若为O，表示将栈顶的值pop出来；若堆栈中没有元素则忽略此次操作
 * 若为A，表示询问当前栈顶的值；若当时栈为空，则输出'E'
 * 
 * 每行单独输出结果
 **/
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main(){
    int n=0;
    while (cin>>n)
    {
        if (n == 0)
            break;
        
        stack<int> Stack;
        char ch;
        int num=0;
        for (int i = 0; i < n; i++)
        {
            cin >> ch;
            switch (ch)
            {
            case 'P':
                cin >> num;
                Stack.push(num);
                break;
            case 'O':
                if (!Stack.empty())
                    Stack.pop();
                break;
            case 'A':
                if (!Stack.empty())
                    cout << Stack.top() << endl;
                else
                    cout << 'E' << endl;
                break;
            }
        }
        cout << endl;
    }
    return 0;
}