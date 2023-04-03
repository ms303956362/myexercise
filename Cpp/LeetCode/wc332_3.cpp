#include "usual.h"

class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<long long, pair<int, int>> mp;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (!mp.count(0)) {
                    mp[0] = make_pair(i, i);
                }
                continue;
            }
            long long num = 0;
            for (int l = 1; l <= 32 && i + l <= n; ++l) {
                num = num * 2 + s[i + l - 1] - '0';
                if (!mp.count(num)) {
                    mp[num] = make_pair(i, i + l - 1);
                }
            }
        }
        vector<vector<int>> ans;
        for (const auto& q : queries) {
            if (mp.count(q[0] ^ q[1])) {
                auto [l, r] = mp[q[0] ^ q[1]];
                ans.push_back(vector<int>{l, r});
            } else {
                ans.push_back(vector<int>{-1, -1});
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
