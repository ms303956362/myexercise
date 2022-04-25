#include "usual.h"

class Solution {
public:
    int calculate(string s) {
        stack<int> sn;
        stack<char> sc;
        // auto check = [](char curr_op, char prev_op) {
        //     return prev_op != '(' && (curr_op == '+' || curr_op == '-' || prev_op == '*' || prev_op == '/');
        // };
        unordered_map<char, int> order{
            {'(', 0},
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2},
        };
        auto calc = [](stack<int>& sn, stack<char>& sc) {
            char op = sc.top();
            sc.pop();
            int num = sn.top();
            sn.pop();
            if (op == '+') {
                sn.top() += num;
            } else if (op == '-') {
                sn.top() -= num;
            } else if (op == '*') {
                sn.top() *= num;
            } else {
                sn.top() /= num;
            }
        };
        sn.push(0);
        for (const auto& c : s) {
            if ('0' <= c && c <= '9') {
                sn.top() = sn.top() * 10 + (c - '0');
            } else if (c == '(') {
                sc.push('(');
            } else if (c == ')') {
                while (sc.top() != '(') {
                    calc(sn, sc);
                }
                sc.pop();
            } else {
                while (!sc.empty() && order[c] <= order[sc.top()]) {
                    calc(sn, sc);
                }
                sc.push(c);
                sn.push(0);
            }
        }
        while (!sc.empty()) {
            calc(sn, sc);
        }
        return sn.top();
    }
};

int main(int argc, char const *argv[])
{
    Solution().calculate("2*(5+5*2)/3+(6/2+8)");
    return 0;
}
