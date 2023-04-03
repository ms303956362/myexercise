#include "usual.h"

class Solution {
public:
    int minOperations(int n) {
        vector<long long> pow;
        long long p = 1;
        while (p < 10 * n + 5) {
            pow.push_back(p);
            p *= 2;
        }
        queue<long long> q;
        vector<bool> vst(10 * n + 5);
        int step = 0;
        q.push(n);
        vst[n] = true;
        while (!q.empty()) {
            int l = q.size();
            for (int i = 0; i < l; ++i) {
                auto u = q.front();
                q.pop();
                if (u == 0) {
                    return step;
                }
                for (const auto& v : pow) {
                    if (u + v < 10 * n + 5 && !vst[u + v]) {
                        vst[u + v] = true;
                        q.push(u + v);
                    }
                    if (u - v >= 0 && !vst[u - v]) {
                        vst[u - v] = true;
                        q.push(u - v);
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution().minOperations(54);
    return 0;
}
