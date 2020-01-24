#include <iostream>
using std::endl;
using std::cin;
using std::cout;

#include <string>
using std::string;

#include <stack>
using std::stack;

int set_op_level(char op){
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else if (op == '(')
        return 0;
    else
        return -1;
}

int compare_op(char op_curr, char op_prev){
    int cur_level, prev_level;
    cur_level = set_op_level(op_curr);
    prev_level = set_op_level(op_prev);
    return cur_level - prev_level;
}

int calc(stack<int>& nums, stack<char>& ops){
    int num1, num2, res;
    char opr;
    num2 = nums.top();
    nums.pop();
    num1 = nums.top();
    nums.pop();
    opr = ops.top();
    ops.pop();
    switch (opr)
    {
    case '+':
        res = num1 + num2;
        break;
    case '-':
        res = num1 - num2;
        break;
    case '*':
        res = num1 * num2;
        break;
    case '/':
        res = num1 / num2;
        break;
    default:
        res = 0;
        break;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    // 9.52
    stack<char> op;
    stack<int> num;
    string s;
    while (cin >> s){
        // 读取每个字符
        for (auto &c : s){
            // 数字
            if (isdigit(c))
                num.push(c-'0');
            // 运算符
            else{
                // 运算符栈空
                if (op.empty())
                    op.push(c);  // 压入
                // 运算符栈非空，且为'('
                else if (c=='(')
                    op.push(c);
                // 运算符栈非空，且为')'
                else if (c == ')'){
                    while (op.top() != '(')
                        num.push(calc(num, op));
                    op.pop();
                }
                // 运算符栈非空，且为其他运算符 
                else {
                    // 当前运算符优先级不高于栈顶运算符
                    while (compare_op(c, op.top()) <= 0){
                        num.push(calc(num, op));
                    }
                    op.push(c);
                }
            }
        }
        while (!op.empty())
            num.push(calc(num, op));
        cout << "=" << num.top() << endl;
        num.pop();
    }

    return 0;
}
