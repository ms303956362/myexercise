#include "usual.h"

class Solution {
    int ans;
    int cnt;

public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        ans = 0;
        cnt = 0;
        vector<int> in(n, 0), out(n, 0);
        backtrack(0, m, n, in, out, requests);
        return ans;
    }

    void backtrack(int i, int m, int n, vector<int>& in, vector<int>& out, vector<vector<int>>& requests) {
        if (i == m) {
            for (int j = 0; j != n; ++j)
                if (in[j] != out[j])
                    return;
            ans = max(ans, cnt);
            return;
        }
        const auto &r = requests[i];
        ++out[r[0]];
        ++in[r[1]];
        ++cnt;
        backtrack(i + 1, m, n, in, out, requests);
        --out[r[0]];
        --in[r[1]];
        --cnt;
        backtrack(i + 1, m, n, in, out, requests);
    }
};
int main(int argc, char const *argv[])
{
    int n = 3;
    vector<vector<int>> r{{1,2},{1,2},{2,2},{0,2},{2,1},{1,1},{1,2}};
    cout << Solution().maximumRequests(n, r) << endl;
    return 0;
}
