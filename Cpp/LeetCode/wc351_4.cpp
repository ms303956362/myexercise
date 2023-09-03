#include "usual.h"

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<tuple<int, int, char>> v;
        unordered_map<int, int> idx;
        for (int i = 0; i < n; ++i) {
            idx[positions[i]] = i;
            v.emplace_back(positions[i], healths[i], directions[i]);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i) {
            healths[i] = get<1>(v[i]);
            directions[i] = get<2>(v[i]);
        }
        stack<pair<int, int>> st;
        for (int i = n - 1; i >= 0; --i) {
            if (directions[i] == 'L') {
                st.emplace(healths[i], i);
            } else {
                while (!st.empty()) {
                    if (st.top().first > healths[i]) {
                        healths[i] = 0;
                        --st.top().first;
                        --healths[st.top().second];
                        break;
                    } else if (st.top().first == healths[i]) {
                        healths[st.top().second] = 0;
                        st.pop();
                        healths[i] = 0;
                        break;
                    } else {
                        healths[st.top().second] = 0;
                        st.pop();
                        --healths[i];
                    }
                }
            }
        }
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                ans.emplace_back(healths[i], get<0>(v[i]));
            }
        }
        sort(ans.begin(), ans.end(), [&](const auto lp, const auto rp) {
            auto [_, pl] = lp;
            auto [_, pr] = rp;
            return idx[pl] < idx[pr];
        });
        vector<int> ret;
        for (const auto& [h, _] : ans) {
            ret.push_back(h);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
