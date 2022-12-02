#include "usual.h"

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        long long max_sum = 0;
        unordered_map<string, long long> sum_views;
        unordered_map<string, unordered_map<string, long long>> vs;
        int n = creators.size();
        for (int i = 0; i < n; ++i) {
            sum_views[creators[i]] += views[i];
            vs[creators[i]][ids[i]] += views[i];
            max_sum = max(max_sum, sum_views[creators[i]]);
        }
        vector<string> candidates;
        for (const auto& [name, view] : sum_views) {
            if (view == max_sum) {
                candidates.push_back(name);
            }
        }
        vector<vector<string>> ans;
        for (const auto& name : candidates) {
            long long max_v = -1;
            string max_id;
            for (const auto& [id, view] : vs[name]) {
                if (view > max_v || (view == max_v && id < max_id)) {
                    max_v = view;
                    max_id = id;
                }
            }
            ans.push_back(vector<string>{name, max_id});
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
