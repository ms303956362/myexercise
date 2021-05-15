#include "usual.h"

class Solution {
public:
    int clumsy(int N) {
        vector<char> op{'*', '/', '+', '-'};
        stack<char> sc;
        stack<int> sn;
        sn.push(N--);
        int i = 0;
        for (; N > 0; --N, i = (i + 1) % 4) {
            if (op[i] == '+' || op[i] == '-') {
                if (!sc.empty() && (sc.top() == '+' || sc.top() == '-')) {
                    int n1 = sn.top();
                    sn.pop();
                    if (sc.top() == '+')
                        sn.top() += n1;
                    else
                        sn.top() -= n1;
                    sc.pop();
                }
                sc.push(op[i]);
                sn.push(N);
            } else if (op[i] == '*') 
                sn.top() *= N;
            else
                sn.top() /= N;       
        }
        while (!sc.empty()) {
            int n1 = sn.top();
            sn.pop();
            if (sc.top() == '+')
                sn.top() += n1;
            else
                sn.top() -= n1;
        }
        return sn.top();
    }
};

int main(int argc, char const *argv[])
{
    Solution().clumsy(10);
    return 0;
}
