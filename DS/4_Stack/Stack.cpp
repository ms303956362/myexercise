#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cstring>

#include "Stack.h"

void convert(Stack<char>& s, long long num, int base) {
    char digits[17] = "0123456789ABCDEF";
    while (num != 0) {
        s.push(digits[num % base]);
        num = num / base;
    }
}

bool paren(const char expr[], int lo, int hi) { // [lo, hi)
    Stack<char> s;
    for (int i = lo; i != hi;++i) {
        if (expr[i] == '(') // 左括号
            s.push(expr[i]);
        else if (!s.empty()) // 右括号且s非空
            s.pop();
        else // 右括号且s空，多出不匹配的右括号
            return false;
    }
    return s.empty(); // 判断是否有多出不匹配的左括号
}

void readNum(char* &s, Stack<float>& num) {
    num.push(static_cast<float>(*s - '0'));
    while (isdigit(*++s)) 
        num.push(num.pop() * 10 + (*s - '0'));
    if (*s != '.')
        return;
    float frac = 1;
    while (isdigit(*++s)) {
        num.push(num.pop() + (*s - '0') * frac / 10.0);
        frac /= 10;
    }
}

int op2rank(char op) {
    switch (op) {
        case '+': return 0;
        case '-': return 1;
        case '*': return 2;
        case '/': return 3;
        case '^': return 4;
        case '!': return 5;
        case '(': return 6;
        case ')': return 7;
        case '\0': return 8;
        default: exit(-1);
    }
}
char pri[9][9] = {
            /* +    -   *   /   ^   !   (   )   \0*/
    /* + */   '>', '>','<','<','<','<','<','>', '>',
    /* - */   '>', '>','<','<','<','<','<','>', '>',
    /* * */   '>', '>','>','>','<','<','<','>', '>',
    /* / */   '>', '>','>','>','<','<','<','>', '>',
    /* ^ */   '>', '>','>','>','>','<','<','>', '>',
    /* ! */   '>', '>','>','>','>','>',' ','>', '>',
    /* ( */   '<', '<','<','<','<','<','<','=', ' ',
    /* ) */   ' ', ' ',' ',' ',' ',' ',' ',' ', ' ',
    /* \0 */  '<', '<','<','<','<','<','<',' ', '='
};

char orderBetween(char op1, char op2) {
    return pri[op2rank(op1)][op2rank(op2)];
}

float calc(float num, char op) {
    float res = 1;
    switch (op) {
    case '!':
        while (num > 0)
            res *= num--;
        break;
    default:
        exit(-1);
    }
    return res;
}

float calc(float num1, char op, float num2) {
    float res;
    switch (op) {
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
    case '^':
        res = 1;
        while (num2 > 0) {
            res *= num1;
            --num2;
        }
        break;
    default:
        exit(-1);
    }
    return res;
}

void append(char* &rpn, char op) {
    int n = strlen(rpn);
    rpn[n] = op;
    // rpn[n + 1] = ' ';
    rpn[n + 1] = '\0';
}

void append(char *&rpn, float num) {
    char buf[64];
    if (num != static_cast<float>(static_cast<int>(num)))
        sprintf(buf, "%.2f", num);
    else 
        sprintf(buf, "%d", static_cast<int>(num));
    
    strcat(rpn, buf);
}

float calcExpr(char* s, char* &rpn) {
    Stack<char> op;
    Stack<float> num;
    op.push('\0');
    while (!op.empty()) {
        if (isdigit(*s)){
            readNum(s, num);
            append(rpn, num.top());
        } else {
            switch (orderBetween(op.top(), *s)) {
            case '=':
                op.pop();
                ++s;
                break;
            case '<':
                op.push(*s++);
                break;
            case '>':
                char opr = op.pop();
                append(rpn, opr);
                if (opr == '!')
                    num.push(calc(num.pop(), opr));
                else {
                    float num2 = num.pop(), num1 = num.pop(); // 注意运算数顺序，必须先pop
                    num.push(calc(num1, opr, num2));
                }
                break;
            }
        }
    }
    return num.pop();
}

int main(int argc, char const *argv[])
{
    // 测试基本功能
    cout << "test stack" << endl;
    Stack<int> s;
    s.push(1);
    s.push(2);
    cout << s.pop() << endl;
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.pop() << s.pop() << endl;
    cout << endl;

    // 进制转换
    cout << "convert: (2015)8 = ";
    Stack<char> s1;
    convert(s1, 2015, 8);
    while (!s1.empty()) {
        cout << s1.pop();
    }
    cout << endl;

    // 括号匹配
    char expr[11] = "((()())())";
    cout << paren(expr, 0, 10) << endl;

    // 中缀表达式求值
    char *calc_expr = new char[35], *calc_rpn = new char[70];
    calc_rpn[0] = '\0';
    float calc_res;
    while (cin >> calc_expr) {
        calc_res = calcExpr(calc_expr, calc_rpn);
        cout << calc_expr << " = " << calc_res << endl;
        cout << "rpn:" << calc_rpn << endl;
        calc_rpn[0] = '\0';
    }
    return 0;
}
