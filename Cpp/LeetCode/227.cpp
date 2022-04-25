#include "usual.h"

class Solution {
public:
    int calculate(string s) {
        bool ispos = true;
        stack<int> sn;
        stack<char> sc;
        sn.push(0);
        auto check = [](char c, char op) {
            return c == '+' || c == '-' || op == '*' || op == '/';
        };
        for (const auto& c : s) {
            if ('0' <= c && c <= '9') {
                sn.top() = sn.top() * 10 + (c - '0');
            } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                while (!sc.empty() && check(c, sc.top())) {
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
                }
                sc.push(c);
                sn.push(0);
            }
        }
        while (!sc.empty()) {
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
        }
        return sn.top();
    }
};

int main(int argc, char const *argv[])
{
    Solution().calculate("1*2-3/4+5*6-7*8+9/10");
    return 0;
}
