#include "usual.h"

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<vector<int>> v;
        vector<int> curr{ratings[0]};
        int n = ratings.size();
        for (int i = 1; i != n; ++i) {
            if (ratings[i] == curr.back()) {
                v.push_back(curr);
                curr.clear();
            }
            curr.push_back(ratings[i]);
        }
        v.push_back(curr);
        int ans = 0;
        for (const auto& rs : v) {
            if (rs.size() == 1)
                ++ans;
            else {
                vector<pair<int, int>> bottom;
                bool down = true;
                int level = 0;
                for (int i = 1; i != rs.size(); ++i) {
                    if (down) {
                        if (rs[i] > rs[i - 1]) {
                            bottom.emplace_back(level, i - 1);
                            down = false;
                        }
                        --level;
                    } else if (!down) {
                        if (rs[i] < rs[i - 1]) {
                            down = true;
                        }
                        ++level;
                    }
                }
                if (down)
                    bottom.emplace_back(level, rs.size() - 1);
                sort(bottom.begin(), bottom.end());
                vector<bool> has(rs.size(), false);
                for (const auto&[l, i] : bottom) {
                    ++ans;
                    for (int j = i + 1; j != rs.size() && rs[j] > rs[j - 1]; ++j) {
                        if (!has[j]) {
                            ans += j - i + 1;
                            has[j] = true;
                        }
                    }
                    for (int j = i - 1; j >= 0 && rs[j] > rs[j + 1]; --j) {
                        if (!has[j]) {
                            ans += i - j + 1;
                            has[j] = true;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{1, 0, 2};
    Solution().candy(v);
    return 0;
}
