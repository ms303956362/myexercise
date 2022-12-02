#include "usual.h"

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<bool> vst(n, false);
        function<int(int)> dfs = [&](int u) {
            int cnt = 1;
            for (const auto& v : g[u]) {
                if (!vst[v]) {
                    vst[v] = true;
                    cnt += dfs(v);
                }
            }
            return cnt;
        };
        vector<long long> a;
        for (int i = 0; i < n; ++i) {
            if (!vst[i]) {
                vst[i] = true;
                long long tmp = dfs(i);
                cout << i << " " << tmp << endl;
                a.push_back(tmp);
            }
        }
        long long sum = 0, ans = 0;
        for (const auto& num : a) {
            ans += sum * num;
            sum += num;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
