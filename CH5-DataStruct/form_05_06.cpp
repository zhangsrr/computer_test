/**
 * 简单计算器
 * 读入一个只包含'+'、'-'、'*'、'/'的非负整数计算表达式
 * 计算该表达式的值
 * 
 * 在运算符栈中放置一个特殊运算符$，优先级最低
 * 在表达式末尾添加一个特殊运算符#，优先级最低
 * 
 * 用两个栈分别存储 运算数和运算符
 * 若扫描到运算数则直接入栈
 * 若扫描到运算符，则与栈顶元素进行比较，
 * 若优先级大于栈顶元素，则将运算符压栈
 * 否则弹出两个运算数进行运算
 * 
 * INPUT:
 * 若干测试用例，每个测试用例一行
 * 每个测试用例不超过100个字符，整数和运算符之间用一个【空格分隔】
 * 当一行中只有0时输入结束
 * 
 * 不考虑非法表达式
 * 
 * OUTPUT:
 * 输出表达式的值，精确到小数点后2位
 * 
 **/
#include <iostream>
#include <stack>
#include <iomanip>
#include <string>
using namespace std;

int GetPriority(char op){
    switch (op)
    {
    case '#':
        return 0;
        break;
    case '$':
        return 1;
        break;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;    
    default:
        return 0;
    }
}

float Calculate(float a, float b, char op){
    if (op == '+')
        return a+b;
    else if (op == '-')
        return b-a;
    else if (op == '*')
        return a*b;
    else
        return b/a;
}

int main(){
    string expr;
    cout << fixed << setprecision(2);
    while (getline(cin, expr))
    {
        stack<float> num;
        stack<char> op;
        op.push('#');
    
        expr+='$';
        if (expr.size() == 2 && expr[0] == '0')
            return 0;
        
        int i=0;
        while (i < expr.size())
        {
            if (expr[i] == ' ')
                i++;            
            else if (isdigit(expr[i]))
            {
                int number=0;
                while (isdigit(expr[i]))
                {
                    number = number*10 + expr[i] - '0';
                    i++;
                }
                num.push(number);
            }else
            {
                if (GetPriority(expr[i]) > GetPriority(op.top()))
                    op.push(expr[i++]);
                else
                {
                    float a = num.top();
                    num.pop();
                    float b = num.top();
                    num.pop();
                    num.push(Calculate(a, b, op.top()));
                    op.pop();
                }
            }
        }  
        cout << num.top() << endl;      
    }
    return 0;
}