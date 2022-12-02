#include "usual.h"

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        // int n = nums.size();
        // vector<set<pair<int, int>>> first(n);
        // stack<int> st;
        // for (int i = n - 1; i >= 0; --i) {
        //     while (!st.empty() && nums[st.top()] <= nums[i]) {
        //         st.pop();
        //     }
        //     if (!st.empty()) {
        //         first[st.top()].emplace(nums[i], i);
        //     }
        //     st.push(i);
        // }
        // while (!st.empty()) {
        //     st.pop();
        // }
        // vector<int> ans(n, -1);
        // for (int i = n - 1; i >= 0; --i) {
        //     while (!st.empty() && nums[st.top()] <= nums[i]) {
        //         while (!first[i].empty() && nums[st.top()] > nums[first[i].begin()->second]) {
        //             auto [_, j] = *first[i].begin();
        //             first[i].erase(first[i].begin());
        //             ans[j] = nums[st.top()];
        //         }
        //         st.pop();
        //     }
        //     if (!st.empty()) {
        //         while (!first[i].empty()) {
        //             auto [_, j] = *first[i].begin();
        //             first[i].erase(first[i].begin());
        //             ans[j] = nums[st.top()];
        //         }
        //     }
        //     st.push(i);
        // }
        // return ans;
        // int n = nums.size();
        // vector<pair<int, int>> v;
        // for (int i = 0; i < n; ++i) {
        //     v.emplace_back(nums[i], -i);
        // }
        // sort(v.begin(), v.end());
        // set<int> st;
        // vector<int> ans(n);
        // for (int i = n - 1; i >= 0; --i) {
        //     auto [num, idx] = v[i];
        //     idx = -idx;
        //     auto p = st.upper_bound(idx);
        //     if (p != st.end()) {
        //         auto q = next(p);
        //         if (q != st.end()) {
        //             ans[idx] = nums[*q];
        //         }
        //     }
        //     st.insert(idx);
        // }
        // return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
