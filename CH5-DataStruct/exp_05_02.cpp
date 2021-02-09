/**
 * 计算表达式
 * 表达式只含数字和+-/*，且不含空格
 * 
 * 设置运算数和运算符两个栈，
 * 运算符栈初始化为$,优先级最低
 * 表达式末尾追加一个#运算符，优先级最低
 * 
 * 对于运算数直接压入栈
 * 对于运算符，
 * 若其优先级比栈顶运算符的低，则弹出运算数用栈顶运算符做运算后压栈，新运算符压栈
 * 若其优先级比栈顶运算符的高，则直接压栈
 * 
 * 终止条件：
 * num栈size==1
 * op栈size == 2 且 top为'#'
 * 
 * INPUT:
 * 表达式
 * 
 * OUTPUT:
 * 计算结果
 **/
#include <iostream>
#include <stack>
using namespace std;

float calculate(float a, float b, char op){
    switch (op)
    {
    case '+':
        return a+b;
    case '-':
        return b-a;
    case '*':
        return a*b;
    case '/':
        return b/a;
    default:
        return 0;
    }
}

int GetPriority(char op){
    if (op == '$')
        return 0;
    else if (op == '#')
        return 1;    
    else if (op == '+' || op == '-')
        return 2;
    else
        return 3;
}

int main(){
    stack<float> num;
    stack<char> op;
    op.push('$');
    string expr;
    while (cin >> expr)
    {
        expr+='#';
        float number=0;
        float a=0,b=0; //弹出两个运算数
        int i = 0;
        while (i < expr.size())
        {
            if (isdigit(expr[i])) //操作数
            {
                number=0;
                while (isdigit(expr[i]))
                {
                    number *= 10;
                    number += expr[i] - '0';   
                    i++;
                }
                num.push(number);
            }else
            {
                if (GetPriority(expr[i]) > GetPriority(op.top()))
                    op.push(expr[i++]);
                else//优先级更低 则栈内要做运算再压栈
                {
                    a = num.top();
                    num.pop();
                    b = num.top();
                    num.pop();
                    num.push(calculate(a, b, op.top()));
                    op.pop();
                }
            }
        }
        cout << num.top() << endl;
    }
    return 0;
} 