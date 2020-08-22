#include "usual.h"

class Solution {
public:
    int minDays(int n) {
        queue<int> q;
        unordered_set<int> s;
        q.push(n);
        s.insert(n);
        int ans = 0;
        int u, len;
        bool ok = false;
        while (!q.empty()) {
            len = q.size();
            for (int i = 0; i != len; ++i) {
                u = q.front();
                if (u == 0) {
                    ok = true;
                    break;
                }
                q.pop();
                if (s.find(u - 1) == s.end()) {
                    q.push(u - 1);
                    s.insert(u - 1);
                }
                if (u % 2 == 0 && s.find(u / 2) == s.end()) {
                    q.push(u / 2);
                    s.insert(u / 2);
                }
                if (u % 3 == 0 && s.find(u / 3) == s.end()) {
                    q.push(u / 3);
                    s.insert(u / 3);
                }
            }
            if (ok)
                break;
            ++ans;
        }
        return ans;
    }
};


class Solution {
    unordered_map<int, int> ans;

public:
    int minDays(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (ans.count(n))
            return ans[n];
        int res = min(minDays(n / 2) + n % 2 + 1, minDays(n / 3) + n % 3 + 1);
        ans[n] = res;
        return res;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
