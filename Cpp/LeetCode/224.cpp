#include "usual.h"

class Solution {
public:
    int calculate(string s) {
        stack<int> s1;
        stack<char> s2;
        s.push_back('#');
        int n = s.size(), num = -1;
        for (int i = 0; i != n; ++i) {
            if (s[i] == ' ') {
                continue;
            } else if ('0' <= s[i] && s[i] <= '9') {
                if (num == -1) {
                    num = s[i] - '0';
                } else {
                    num = num * 10 + s[i] - '0';
                }
            } else {
                if (num != -1) {
                    s1.push(num);
                    num = -1;
                }
                if (s[i] != '(' && !s2.empty() && s2.top() != '(') {
                    int num2 = s1.top();
                    s1.pop();
                    if (s2.top() == '+')
                        s1.top() += num2;
                    else
                        s1.top() -= num2;
                    s2.pop();
                }
                if (s[i] == ')')
                    s2.pop();
                else
                    s2.push(s[i]);
            }
        }
        return s1.top();
    }
};

int main(int argc, char const *argv[])
{
    string s1("(1+(4+5+2)-3)+(6+8)"), s2("2147483647");
    Solution().calculate(s2);
    return 0;
}
